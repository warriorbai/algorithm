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

//2.1 Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?
//2.1 
template <class T> void LList<T>::remove_duplicate() {
    if(isEmpty())    return;
    pNode current = head->next; 
    pNode prev = head;
    pNode it;
    while(current) {
        it = head;
        while(it != current) {
            if(it->data == current->data) {
                prev->next = current->next;
                delete current;
                current = prev;
                break;
            } 
            it = it->next;
        }
        prev = current;
        current = current->next;
    }
    dump();
}

void test_2_1() {
    int array[6] = { 1, 1, 5, 7, 7, 2}; 
    int array1[5] = { 7, 7, 7, 7, 7}; 
    LList<int> list_int(array1, 5);
    list_int.dump();
    list_int.remove_duplicate();
}


//2.2 Implement an algorithm to find the nth to last element of a singly linked list.
template <class T>  Node<T>* LList<T>::get_nth_to_last(int n) {
    dump();
    if (head == NULL || n < 1) {
        return NULL;
    }
    pNode p1 = head;
    pNode p2 = head;
    for (int j = 0; j < n - 1; ++j) { // skip n-1 steps ahead
        if (p2 == NULL) {
            return NULL; // not found since list size < n
        }
        p2 = p2->next;
    }
    while (p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

void test_2_2() {
    int array[10] = { 1, 1, 5, 7, 7, 2, 4, 5, 11, 21};
    LList<int> list_int(array, 10);
    list_int.dump();
    cout<<list_int.get_nth_to_last(2)->data<<endl;
}




