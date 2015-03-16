#ifndef _2_HEADER
#define _2_HEADER
#include<iostream>
using namespace std;

//linked list
template <class T> class Node {
public:
    T data;
    Node<T>* next;
};
template <class T> class LList {
public:
    typedef Node<T>* pNode;
    LList() {
        head = NULL;
        tail = NULL;
    }
    LList(T* array, int size);
    void dump();
    bool isEmpty() {
        return head == NULL;
    }
    pNode get_head() { return head; }
    pNode get_tail() { return tail; }
    pNode find(T a); 
    void  remove_duplicate();
    pNode get_nth_to_last(int n);
    bool  delete_item(pNode it);
    bool  push_back(T item) {
        pNode node = new Node<T>;
        if(node) {
            node->data = item;
        } else {
            return false;
        }
        if(tail != NULL) {
            tail->next = node;
            tail = tail->next;
        } else {
            head = node;
            tail = head;
        }
        tail->next = NULL;
        return true;
    }
    void clear() {
        head = tail = NULL;
    }           
private:
    pNode head;
    pNode tail;
};


void test_2_1();
void test_2_2();
void test_2_3();
void test_2_4();




#endif
