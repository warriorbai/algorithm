#include "2.h"
#include<set>
#include<vector>
#include<iomanip>
//This file is used for store solutions for 2.1 - 2.5   linked list
//
//constructor by a array
template <class T> LList<T>::LList(T* array, int size) {
    if(size > 0) {
        pNode tail = NULL;
        for(int i = 0; i < size; ++i) {
           pNode node_new = new Node<T>;
           node_new->data = array[i]; 
           if(tail == NULL) {
               head = node_new;
               tail = head;
           } else {
               tail->next = node_new;
               tail = tail->next;
           }
        }
        tail->next = NULL;
    }
}

template <class T> void LList<T>::dump() {
    pNode p = head;
    while(p != NULL) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
//2.1 
void test_2_1() {
    int array[6] = { 1, 3, 5, 7, 33, 2}; 
    LList<int> list_int(array, 6);
    list_int.dump();
}

