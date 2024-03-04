#pragma once

#include <cstddef>
#include <cstdint>

struct Node {
    int32_t value;
    Node* previous;
    Node(int32_t value, Node* previous);
};

class Stack {
private:
    Node* head_;
    int size_;

public:
    Stack();

    ~Stack();

    void Push(int32_t value);

    void Clear();

    void Pop();

    int32_t Top() const;

    int32_t Size() const;

    bool Empty() const;
};
