#include "stack.h"

Node::Node(int32_t value, Node* previous) : value(value), previous(previous) {
}

Stack::Stack() : head_(nullptr), size_(0) {
}

Stack::~Stack() {
    while (!Empty()) {
        Pop();
    }
}

void Stack::Push(int32_t value) {
    Node* new_top = new Node{value, head_};
    head_ = new_top;
    size_++;
}

void Stack::Clear() {
    while (!Empty()) {
        Pop();
    }
}

void Stack::Pop() {
    if (Empty()) {
        return;
    }
    Node* old_top = head_->previous;
    delete head_;
    head_ = old_top;
    size_--;
}

int32_t Stack::Top() const {
    if (Empty()) {
        return 0;
    }
    int32_t value = head_->value;
    return value;
}

int32_t Stack::Size() const {
    return size_;
}

bool Stack::Empty() const {
    return head_ == nullptr;
}
