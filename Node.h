#pragma once

#include <memory>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;

    Node(const T& d) : data(d), next(nullptr), prev() {}
};