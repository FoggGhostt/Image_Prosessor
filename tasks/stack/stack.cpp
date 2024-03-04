#include "stack.h"

Node::Node(int32_t value, Node* previous) : value(value), previous(previous) {
}

Stack::Stack() {
    size_ = 0;
    head_ = nullptr;
}

Stack::~Stack() {
    while (!Empty()) {
        Pop();
    }
}

Stack::Push(int32_t value) {
    Node* new_top = new Node{value, head_};
    head_ = new_top;
    size_ += 1;
}


