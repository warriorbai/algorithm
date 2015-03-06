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
    }
    LList(T* array, int size);
    void dump();
    bool isEmpty() {
        return head == NULL;
    }
    void  remove_duplicate();
    pNode get_nth_to_last(int n);
private:
    pNode head;
};


void test_2_1();
void test_2_2();




#endif
