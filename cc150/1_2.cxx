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


//1.6
//rotate NxN image represented by 4 byte number
//mode 1 - clockwire 90   2 - counter clockwise 90
void rotate(int a[][6], int size, bool mode) {
for(int layer = 0; layer < size/2 ;layer++) {
    int i = layer;
    int start_j = layer;
    int end_j = size - layer - 1;
    for(int j = start_j; j < end_j;j++) {
        int target  = a[i][j];
        int m = j;
        int n = -i+size-1;
        do {
            int temp = a[m][n];
            a[m][n] = target;
            target = temp;
            int tm = m;
            m = n;
            n = -tm+size-1;
        } while (m != j || n != -i+size-1); 
    }
}
}

void dump(int a[][6], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void test_1_6() {
    int a[6][6] = {{1,2,3,4,5,6}, {4,5,6,7,8,9}, {7,8,9,10,11,12}, {1,3,5,7,9,11},{2,4,6,8,10,12},{333,333,333,111,111,111}};
    dump(a,6);
    rotate(a, 6, 1);
    dump(a,6);
    rotate(a, 6, 2);
    dump(a,6);
}
