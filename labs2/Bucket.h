#pragma once

#include "HashNode.h"

class Bucket {
public:
    Bucket(): Node(nullptr) {}

    HashNode* getPNode() const {
        return Node;
    }

    void setPNode(HashNode* pNode) {
        this->Node = pNode;
    }

    void delPnode(HashNode* pNode){
        this->Node = nullptr;
        delete(this->Node);
    }

private:
    HashNode* Node;
};
