#include "queue.h"

Node::Node() : value(0), next(nullptr) {
}

Node::Node(int32_t value, Node* next) : value(value), next(next) {
}

Queue::Queue() {
    front_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

Queue::~Queue() {
    Clear();
}

void Queue::Push(int32_t value) {
    if (tail_ == nullptr) {
        tail_ = new Node{value, nullptr};
        front_ = tail_;
    } else {
        Node* new_tail = new Node{value, nullptr};
        tail_->next = new_tail;
        tail_ = new_tail;
    }
    size_++;
}

void Queue::Pop() {
    if (Empty()) {
        return;
    }
    Node* new_front = front_->next;
    delete front_;
    front_ = new_front;
    size_--;
}

int32_t Queue::Front() const {
    return front_->value;
}

int32_t Queue::Size() const {
    return size_;
}

void Queue::Clear() {
    while (!Empty()) {
        Pop();
    }
}

bool Queue::Empty() const {
    return front_ == nullptr;
}