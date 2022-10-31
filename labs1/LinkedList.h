#pragma once

#include "Node.h"

class LinkedList {

    private:
        Node* node;
        int nodeCount = 0;

    public:
        LinkedList(): node(nullptr) {}

        Node* getNode() const {
            return node;
        }

        void setNode(Node* node) {
            this->node = node;
        }

        int getNodeCount() const {
            return nodeCount;
        }

        void setNodeCount(int nodeCount) {
            this->nodeCount = nodeCount;
        }
};