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
    pNode get_head() { return head; }
    pNode find(T a); 
    void  remove_duplicate();
    pNode get_nth_to_last(int n);
    bool  delete_item(pNode it);
private:
    pNode head;
};


void test_2_1();
void test_2_2();
void test_2_3();




#endif
