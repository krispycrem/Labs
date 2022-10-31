#pragma once

#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>

#include "Bucket.h"
#include "HashNode.h"

using namespace std;

class HashMap {

private:
    Bucket** table;
    int tableSize;
    const int p = 124;
    const int m = 997;

    int hash(string s){
        int h = 0;
        for (int i = 0; i < s.length(); i++){
            h+=((s[i]%m)*powmod(p, i, m))%m;
            h%=m;
        }
        return h;
    }

    int powmod(int a, int b, int m){
        if(b==0){
            return 1;
        }
        if(b == 1 || a == 0)
        {
            return a%m;
        }

        int res = 1;
        while(b>0){
            if (b%2 == 1){
                res = (res*a)%m;
            }
            a = (a * a) % m;
            b /= 2;
        }
        return res;
    }

public:
    HashMap(int tableSize) {
        this->tableSize = tableSize;
        table = new Bucket*[tableSize]();

        for (int i = 0; i < tableSize; i++) {
            table[i] = new Bucket();
        }
    }
    void insert_value(string s) {
        int h = hash(s);
        Bucket *bucket = table[h];
        HashNode *entry = bucket->getPNode();
        HashNode* prev = entry;

        while (entry != NULL && entry->getKey() != s) {
            entry = entry->getNext();
        }

        if (entry == NULL) {
            entry = new HashNode(s);
            bucket->setPNode(entry);
            entry->setNext(prev);

            if(prev!=NULL){
                prev->setPrev(entry);
            }
        }
    }

    void delete_value(string s){
        int h = hash(s);

        Bucket *bucket = table[h];
        HashNode *entry = bucket->getPNode();
        HashNode* head = entry;
        bool exists = false;

        while(entry != NULL) {
            if (entry->getKey() == s) {

                HashNode *prev = entry->getPrev();
                HashNode *next = entry->getNext();
                if (head->getKey() == s) {
                    bucket->delPnode(head);
                    exists = true;
                }
                if (prev != NULL) {
                    prev->setNext(entry->getNext());
                    bucket->delPnode(entry);
                    exists = true;
                }
                if (next != NULL) {
                    next->setPrev(entry->getPrev());
                    bucket->delPnode(entry);
                    exists = true;
                }
                entry = entry->getNext();
            }
        }
        /*if(!exists){
            cout<<"This value (" <<s<< ") does not exist "<<endl;
        }*/
        return;
    }

    void search_value(string s){
        int h = hash(s);
        Bucket *bucket = table[h];
        HashNode *entry = bucket->getPNode();

        while (entry != NULL){
            if(entry->getKey() == s){
                //cout<< "yes" << endl;
                return;
            }
            else{
                entry = entry->getNext();
            }
        }
        //cout << "no" << endl;
        return;
    }

    void print(){
        for(int i = 0; i <1000; i++)
        {
            Bucket *bucket = table[i];
            HashNode *entry = bucket->getPNode();
            while (entry != NULL) {
                cout<< entry->getKey() << endl;
                entry = entry->getNext();

            }
        }
    }
};
