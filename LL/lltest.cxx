#include<vector>
#include<iostream>
#include<iostream>
#include<fstream>
#include<string>
#include"llcpp.h"
#include"llc.h"

using namespace std;

//implement a C++ style single linked list
//data type: string





int main() {
//import data from data.txt
    vector<int> test;
    string s;
    ifstream fin("data.txt");
    while(std::getline(fin, s) ) {
        test.push_back(atoi(s.c_str()));
    }

    slist list1 = NULL; 

    int key;
    for(size_t i=0; i < test.size(); ++i) {
        key = test[i];
        insertNode(&list1, key);
    }
    dumpList(&list1);
    return 0;
}
