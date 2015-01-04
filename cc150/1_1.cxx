#include "1_1.h"
#include<set>
bool hasUniqueChar1(string str) {
    set<char> temp;
    for(int i = 0; i < str.length(); ++i) {
        if((temp.insert(str[i])).second == false) return false;
    }
    return true;
}

//better method, use bool table, a simple hash table 
bool hasUniqueChar3(string str) {
    bool* p;
    p = new bool[256];
    for(int i = 0; i < str.length(); ++i) {
        if(p[str[i]] == true) return false;
        else {
            p[str[i]] = true;
        }
    }
    return true;
}

void test_1_1() {
    cout<<"call case 1.1"<<endl;
    cout<<"Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?"<<endl; 
    string str;
    cout<<"String is:";
    cin>>str;
    if(hasUniqueChar1(str)) {
        cout<<"has unique character."<<endl;
    } else {
        cout<<"String has no unique character."<<endl;
    }
}
