#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    try {
        SinglyLinkedList<int> s;
        s.push_back(1);
        s.push_back(2);
        s.push_front(0);
        s.insert(2, 5);
        std::cout << "Singly: " << s << " size=" << s.size() << "\n";
        std::cout << "Find 5 -> " << s.find(5) << "\n";
        s.remove(2);
        std::cout << "After remove: " << s << "\n";

        DoublyLinkedList<std::string> d;
        d.push_back("one");
        d.push_front("zero");
        d.push_back("two");
        d.insert(1, "half");
        std::cout << "Doubly: " << d << " size=" << d.size() << "\n";
        std::cout << "At(2) -> " << d.at(2) << "\n";
        d.remove(1);
        std::cout << "After remove: " << d << "\n";

    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}