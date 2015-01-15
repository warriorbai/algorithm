#include "1_2.h"
#include<set>
#include<vector>
//This file is used for store solutions for 1.2 - 1.8
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

//1.3
//Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
//FOLLOW UP
//Write the test cases for this method.
void rm_duplicate_c(string& str) {
    if(str.length() <= 1) return;
    int end = 0;
    for(int i = 1; i != str.length(); ++i) {
        int j;
        bool found = false;
        for(j=0;j<=end;j++) {
            if(str[j] == str[i]) {
                found = true;
                break;
            }
        }
        if(!found) {
            str[j] = str[i];
            end = j;
        }
    }
    end++;
    str.resize(end);
}
void test_1_3() {
    string str = "abcsafadsfde";
    cout<<str<<endl;
    rm_duplicate_c(str);
    cout<<str<<endl;
}


//1.4
// Check if two strings are anagrams
bool isAnagrams(string& s1, string& s2) {
    vector<int> v_ct(256,0);
    for(int i = 0; i != s1.length(); ++i) {
        int num = (int)s1[i];
        v_ct[num]++;
    }
    for(int j = 0; j != s2.length(); j++) {
        int num = (int)s2[j];
        if(v_ct[num] == 0)    return false;
        else    v_ct[num]--;
    }
    return true;
}

void test_1_4() {
    string str1 = "tobias";
    string str2 = "saibot";
    cin >> str1 >> str2;
    string buf = isAnagrams(str1, str2)? " are ":" are not ";
    cout << str1 <<" and "<< str2 << buf <<" anagrams."<<endl;
}
