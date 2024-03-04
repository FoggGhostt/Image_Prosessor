#pragma once

#include <cstddef>
#include <cstdint>

struct Node {
    int32_t value;
    Node* previous;
    Node(int32_t value, Node* previous);

    Node& operator=(Node* other) {
        value = other->value;
        previous = other->previous;
        delete other;
        return *this;
    }
};

class Stack {
private:
    Node* head_;
    int size_;

public:
    Stack() {
        size_ = 0;
        head_ = nullptr;
    };

    ~Stack() {
        while (!Empty()) {
            Pop();
        }
    }

    void Push(int32_t value) {
        Node* new_top = new Node{value, top_};
        top_ = new_top;
        size_ += 1;
    }

    void Clear() {
        while (!Empty()) {
            Pop();
        }
    }

    void Pop() {
        if (Empty()) {
            return;
        }
        Node* old_top = top_->previous;
        delete top_;
        top_ = old_top;
        size_ -= 1;
    }

    int32_t Top() const {
        if (Empty()) {
            return {};
        }
        int32_t value = top_->value;
        return value;
    }

    int32_t Size() const {
        return size_;
    }

    bool Empty() const {
        return top_ == nullptr;;
    }

private:
    Node* top_ = nullptr;
};
