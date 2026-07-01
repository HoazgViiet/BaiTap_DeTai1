#pragma once
#include <string>
#include <queue>

using namespace std;

// Cấu trúc Độc giả (Linked List)
struct Reader {
    string readerId;
    string name;
    int borrowCount;
    Reader* next;

    Reader(string id, string n) : readerId(id), name(n), borrowCount(0), next(nullptr) {}
};

// Cấu trúc Sách (BST)
struct Book {
    string bookId;
    string title;
    bool isAvailable;
    int timesBorrowed;
    queue<string> waitlist; // Queue: Hàng đợi mượn sách

    Book* left;
    Book* right;

    Book(string id, string t) : bookId(id), title(t), isAvailable(true), timesBorrowed(0), left(nullptr), right(nullptr) {}
};

// Cấu trúc Lịch sử thao tác (Stack)
struct Action {
    string actionType; // "BORROW" hoặc "RETURN"
    string bookId;
    string readerId;

    Action(string type, string bId, string rId) : actionType(type), bookId(bId), readerId(rId) {}
};