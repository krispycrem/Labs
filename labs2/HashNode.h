#pragma once

#include <string>

using namespace std;
class HashNode {

private:
    string key;
    HashNode* next;
    HashNode* prev;

public:
    HashNode(const string& key): key(key), next(nullptr), prev(nullptr) {}

    string getKey() const {
        return key;
    }

    HashNode* getNext() const {
        return next;
    }

    HashNode* getPrev() const {
        return prev;
    }

    void setNext(HashNode* next) {
        this->next = next;
    }
    void setPrev(HashNode* prev) {
        this->next = prev;
    }

};

