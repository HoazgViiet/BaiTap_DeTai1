#pragma once
#include "DataStructures.h"
#include <stack>

class LibraryManager {
private:
    Book* bookRoot;
    Reader* readerHead;
    stack<Action> history; // Stack: Lịch sử hoàn tác

    // Hàm đệ quy hỗ trợ BST
    Book* insertBookRec(Book* root, string id, string title);
    Book* searchBookRec(Book* root, string id);
    void findMostBorrowedRec(Book* root, Book*& maxBook);

public:
    LibraryManager();

    // Quản lý độc giả (Linked List)
    void addReader(string id, string name);
    Reader* searchReader(string id);

    // Quản lý sách (BST)
    void insertBook(string id, string title);
    Book* searchBookById(string id);

    // Logic cốt lõi
    void borrowBook(string readerId, string bookId);
    void returnBook(string readerId, string bookId);
    void undoLastAction();

    // Thống kê
    void statMostBorrowedBook();
    void statMostActiveReader();
};