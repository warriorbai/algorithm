#include "2.h"
#include<set>
#include<vector>
#include<iomanip>
//This file is used for store solutions for 2.1 - 2.5   linked list
//
//constructor by a array
template <class T> LList<T>::LList(T* array, int size) {
    tail = NULL;
    if(size > 0) {
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

template <class T> Node<T>* LList<T>::find(T a) {
    pNode it = head;
    while(it != NULL) {
        if(it->data == a) {
            return it;
        }
        it = it->next;
    }
    return NULL;
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



//2.3 Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
//EXAMPLE
//Input: the node ‘c’ from the linked list a->b->c->d->e
//Result: nothing is returned, but the new linked list looks like a->b->d->e
template <class T>  bool LList<T>::delete_item(pNode it) {
    if(it == NULL || it->next == NULL)  return false;
    pNode next = it->next;
    it->data = next->data;
    it->next = next->next;
    delete next;
    return true;
}

void test_2_3() {
    int array[10] = { 1, 1, 5, 7, 7, 2, 4, 5, 11, 21};
    LList<int> list_int(array, 10);
    list_int.dump();
    Node<int>* to_del = list_int.get_head();
    to_del = list_int.find(2);
    if(to_del != NULL) {
        list_int.delete_item(to_del);
    }
    list_int.dump();
}


//2.4
//You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
//EXAMPLE
//Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
//Output: 8 -> 0 -> 8

void add(LList<int>& num1, LList<int>& num2, LList<int>& result) {
    result.clear();
    Node<int>* p1 = num1.get_head(); 
    Node<int>* p2 = num2.get_head(); 
    int carry = 0;
    while(p1 != NULL || p2 != NULL) {
        int num1 = (p1 == NULL) ? 0:p1->data; 
        int num2 = (p2 == NULL) ? 0:p2->data; 
        int sum = (num1 + num2 + carry); 
        int val = sum % 10;
cout<<num1<< " "<<num2<<" "<< sum<<endl;
        result.push_back(val);
        carry = sum/10;
        if(p1) p1 = p1->next;
        if(p2) p2 = p2->next;
    }
    if(carry != 0) {
        result.push_back(carry);
    }
}

void test_2_4() {
    int array1[4] = { 7, 1, 5, 7};
    int array2[2] = { 5, 8};
    LList<int> num1(array1, 4);
    LList<int> num2(array2, 2);
    LList<int> result;
    num1.dump();
    num2.dump();
    add(num1,num2,result);
    result.dump();
}
