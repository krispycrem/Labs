#pragma once

class Node {

    private:
        int key;
        Node * next;

    public:
        Node(const int& value): key(key), next(nullptr) {}

        int getKey() const {
            return key;
        }

        Node* getNext() const {
            return next;
        }

        void setNext(Node* next) {
            this->next = next;
    }
};
