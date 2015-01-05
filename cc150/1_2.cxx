#include "1_2.h"
#include<set>

void reverse_str(char* str) {
    if(!str) return;
    char* head = str;
    char* tail = str;
    while(*tail != '\0') {
        tail++;
    }
    tail--;
    while(tail > head) {
        char temp = *tail;
        *tail = *head;
        *head = temp;
        tail--;
        head++;
    }
}

void test_1_2() {
    char c_str[] = "1234567";
    reverse_str(c_str);
    cout<<"Reversed string is:"<<c_str<<endl;
    cout<<"Reversing again..."<<endl;
    reverse_str(c_str);
    cout<<"Reversed string is:"<<c_str<<endl;
}
