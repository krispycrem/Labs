#pragma once

#include <cstddef>
#include <iostream>
#include <math.h>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

class HashTable {

    private:
        LinkedList** table;
        int table_size;
        int maxChainLen = 0;

        int hash(const int& key) {
            return key % table_size;
        }

    public:
        HashTable(int table_size) {
            this->table_size = table_size;
            table = new LinkedList*[table_size]();

            for (int i = 0; i < table_size; i++) {
                table[i] = new LinkedList();
            }
        }

        void put_value(const int& key) {
            int hashValue = hash(key);
            LinkedList* linkedList = table[hashValue];
            Node* entry = linkedList->getNode();
            Node* prev = entry;

            while (entry != NULL && entry->getKey() != key) {
                entry = entry->getNext();
            }

            if (entry == NULL) {
                entry = new Node(key);
                linkedList->setNode(entry);
                entry->setNext(prev);

                int nodeCount = linkedList->getNodeCount();
                linkedList->setNodeCount(nodeCount + 1);

                if (nodeCount == maxChainLen) {
                    maxChainLen++;
                }
            }
        }

        void get_max_min_length_hashtable() {
            int min = maxChainLen;

            for (int i = 0; i < table_size; i++) {
                int nodeCount = table[i]->getNodeCount();

                if (nodeCount < min) {
                    min = nodeCount;
                }
            }

            cout << "Maximum chain length: " << maxChainLen << endl;
            cout << "Minimum chain length: " << min << endl;
        }
};
