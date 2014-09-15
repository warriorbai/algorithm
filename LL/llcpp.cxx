#include"llcpp.h"
#include<iostream>
using namespace std;

double_ll::double_ll() {
    header = NULL;
    tail = NULL;
    numNode = 0;
}
    
bool double_ll::insert(ll_node* pos, string str) {
    if(!pos) return false;
    ll_node* tmp = new ll_node;
    if(!tmp) return false;
    tmp->next = pos->next;
    tmp->prev = pos;
    tmp->data = str;
    if(pos->next != NULL) {
        pos->next->prev = tmp;
    } else {
        tail = tmp;
    }
    pos->next = tmp;
    numNode++;
    return true;
}

ll_node* double_ll::search(string str) {

}

bool double_ll::push_front(string str) {
    ll_node* tmp = new ll_node;
    if(!tmp) return false;
    if(!header) {
        tail = tmp;
    } else {
        tmp->next = header;
        header->prev = tmp;
    } 
    header = tmp;
    numNode++;
    return true;
}

bool double_ll::push_back(string str) {
    ll_node* tmp = new ll_node;
    tmp->data = str;
    if(!tmp) return false;
    if(!header) {
        header = tmp;
    } else {
        tail->next = tmp;
        tmp->prev = tail;
    }
    tail = tmp;
    numNode++;
    return true;
}

bool double_ll::pop_front() {}
bool double_ll::pop_back() {}
size_t double_ll::size() { return numNode; }
  
ll_node* double_ll::front() { return header; }
ll_node* double_ll::back() { return tail; }
    
bool double_ll::remove(string str) {}
bool double_ll::erase(ll_node* item) {}
bool double_ll::clean() {}

void double_ll::dump() {
    ll_node* it = header;
    while(it) {
        cout<<it->data<<" ";
        it = it->next;
    }
    cout<<endl;
}
// complex functions
void double_ll::reverse_list() {}


