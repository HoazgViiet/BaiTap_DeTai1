#include "LibraryManager.h"
#include <iostream>

using namespace std;

LibraryManager::LibraryManager() {
    bookRoot = nullptr;
    readerHead = nullptr;
}

// ================= THÊM ĐỘC GIẢ (LINKED LIST) =================
void LibraryManager::addReader(string id, string name) {
    Reader* newReader = new Reader(id, name);
    newReader->next = readerHead;
    readerHead = newReader;
    cout << "Da them doc gia: " << name << endl;
}

Reader* LibraryManager::searchReader(string id) {
    Reader* curr = readerHead;
    while (curr != nullptr) {
        if (curr->readerId == id) return curr;
        curr = curr->next;
    }
    return nullptr;
}

// ================= THÊM VÀ TÌM KIẾM SÁCH (BST) =================
Book* LibraryManager::insertBookRec(Book* root, string id, string title) {
    if (root == nullptr) return new Book(id, title);
    if (id < root->bookId) root->left = insertBookRec(root->left, id, title);
    else if (id > root->bookId) root->right = insertBookRec(root->right, id, title);
    return root;
}

void LibraryManager::insertBook(string id, string title) {
    bookRoot = insertBookRec(bookRoot, id, title);
    cout << "Da them sach: " << title << endl;
}

Book* LibraryManager::searchBookRec(Book* root, string id) {
    if (root == nullptr || root->bookId == id) return root;
    if (id < root->bookId) return searchBookRec(root->left, id);
    return searchBookRec(root->right, id);
}

Book* LibraryManager::searchBookById(string id) {
    return searchBookRec(bookRoot, id);
}

// ================= LOGIC MƯỢN / TRẢ (QUEUE & STACK) =================
void LibraryManager::borrowBook(string readerId, string bookId) {
    Book* b = searchBookById(bookId);
    Reader* r = searchReader(readerId);

    if (!b || !r) {
        cout << "Khong tim thay sach hoac doc gia!" << endl;
        return;
    }

    if (b->isAvailable) {
        b->isAvailable = false;
        b->timesBorrowed++;
        r->borrowCount++;
        history.push(Action("BORROW", bookId, readerId));
        cout << r->name << " da muon sach " << b->title << " thanh cong." << endl;
    }
    else {
        b->waitlist.push(readerId);
        cout << "Sach dang duoc muon. " << r->name << " da duoc dua vao hang doi (Queue)." << endl;
    }
}

void LibraryManager::returnBook(string readerId, string bookId) {
    Book* b = searchBookById(bookId);
    if (!b) return;

    b->isAvailable = true;
    history.push(Action("RETURN", bookId, readerId));
    cout << "Da tra sach " << b->title << "." << endl;

    // Tự động mượn cho người tiếp theo trong Queue
    if (!b->waitlist.empty()) {
        string nextReaderId = b->waitlist.front();
        b->waitlist.pop();
        cout << "\n[Tu dong] Den luot nguoi trong hang doi..." << endl;
        borrowBook(nextReaderId, bookId);
    }
}

// ================= UNDO (STACK) =================
void LibraryManager::undoLastAction() {
    if (history.empty()) {
        cout << "Khong co thao tac nao de Undo!" << endl;
        return;
    }

    Action last = history.top();
    history.pop();
    Book* b = searchBookById(last.bookId);

    if (last.actionType == "BORROW") {
        b->isAvailable = true;
        cout << "Da Undo: Huy viec muon sach " << b->title << endl;
    }
    else if (last.actionType == "RETURN") {
        b->isAvailable = false;
        cout << "Da Undo: Huy viec tra sach " << b->title << endl;
    }
}

// ================= THỐNG KÊ =================
void LibraryManager::findMostBorrowedRec(Book* root, Book*& maxBook) {
    if (!root) return;
    if (!maxBook || root->timesBorrowed > maxBook->timesBorrowed) maxBook = root;
    findMostBorrowedRec(root->left, maxBook);
    findMostBorrowedRec(root->right, maxBook);
}

void LibraryManager::statMostBorrowedBook() {
    Book* maxBook = nullptr;
    findMostBorrowedRec(bookRoot, maxBook);
    if (maxBook) cout << "Sach muon nhieu nhat: " << maxBook->title << " (" << maxBook->timesBorrowed << " lan)\n";
    else cout << "Chua co du lieu mượn sách.\n";
}

void LibraryManager::statMostActiveReader() {
    Reader* curr = readerHead;
    Reader* maxReader = nullptr;
    while (curr != nullptr) {
        if (!maxReader || curr->borrowCount > maxReader->borrowCount) maxReader = curr;
        curr = curr->next;
    }
    if (maxReader) cout << "Doc gia tich cuc nhat: " << maxReader->name << " (" << maxReader->borrowCount << " lan)\n";
    else cout << "Chua co du lieu độc giả.\n";
}