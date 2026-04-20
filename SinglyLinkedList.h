#pragma once

#include "Node.h"
#include <memory>
#include <stdexcept>
#include <iostream>

template<typename T>
class SinglyLinkedList {
    using NodeT = Node<T>;
    std::shared_ptr<NodeT> head_;
    size_t size_ = 0;
public:
    SinglyLinkedList() = default;

    // Додавання в початок
    void push_front(const T& value) {
        auto node = std::make_shared<NodeT>(value);
        node->next = head_;
        head_ = node;
        ++size_;
    }

    // Додавання в кінець 
    void push_back(const T& value) {
        auto node = std::make_shared<NodeT>(value);
        if (!head_) { head_ = node; ++size_; return; }
        auto cur = head_;
        while (cur->next) cur = cur->next;
        cur->next = node;
        ++size_;
    }

    // Видалення з початку
    void pop_front() {
        if (!head_) throw std::out_of_range("Pop_front from empty list");
        head_ = head_->next;
        --size_;
    }

    // Видалення з кінця 
    void pop_back() {
        if (!head_) throw std::out_of_range("Pop_back from empty list");
        if (!head_->next) { head_.reset(); size_ = 0; return; }
        auto cur = head_;
        while (cur->next && cur->next->next) cur = cur->next;
        cur->next.reset();
        --size_;
    }

    // Доступ за індексом
    T& at(size_t idx) {
        if (idx >= size_) throw std::out_of_range("Index out of range");
        auto cur = head_;
        for (size_t i = 0; i < idx; ++i) cur = cur->next;
        return cur->data;
    }

    // Вставка на позицію 
    void insert(size_t idx, const T& value) {
        if (idx > size_) throw std::out_of_range("Index out of range");
        if (idx == 0) { push_front(value); return; }
        auto cur = head_;
        for (size_t i = 0; i + 1 < idx; ++i) cur = cur->next;
        auto node = std::make_shared<NodeT>(value);
        node->next = cur->next;
        cur->next = node;
        ++size_;
    }

    // Видалення за індексом
    void remove(size_t idx) {
        if (idx >= size_) throw std::out_of_range("Index out of range");
        if (idx == 0) { pop_front(); return; }
        auto cur = head_;
        for (size_t i = 0; i + 1 < idx; ++i) cur = cur->next;
        cur->next = cur->next->next;
        --size_;
    }

    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    // Пошук елементу
    int find(const T& value) const {
        auto cur = head_;
        int idx = 0;
        while (cur) {
            if (cur->data == value) return idx;
            cur = cur->next;
            ++idx;
        }
        return -1;
    }

    // Виведення списку
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& l) {
        os << "[";
        auto cur = l.head_;
        bool first = true;
        while (cur) {
            if (!first) os << ", ";
            os << cur->data;
            first = false;
            cur = cur->next;
        }
        os << "]";
        return os;
    }
};