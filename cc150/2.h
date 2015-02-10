#ifndef _2_HEADER
#define _2_HEADER
#include<iostream>
using namespace std;

//linked list
class Node {
    int data;
    Node* next;
};
typedef Node* pNode;
class LList {
public:
    LList() {
        head = NULL;
    }
private:
    pNode head;
};


void test_2_1();




#endif
