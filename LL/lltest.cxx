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
void test1() {
    vector<int> test;
    string s;
    ifstream fin("data2.txt");
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
    slist pl = searchNode(&list1, 23);
    if(pl) {
        cout<<"search data is:"<<pl->data<<endl;
    } 
    deleteNode(&list1, 12);
    cout<<"delete one matching item in list."<<endl;
    dumpList(&list1);
    deleteNode(&list1, 12, true);
    cout<<"delete all matching item in list."<<endl;
    dumpList(&list1);

}

void test2() {
    vector<string> test;
    string s;
    ifstream fin("data.txt");
    while(std::getline(fin, s) ) {
        test.push_back(s);
    }

    double_ll list1;
    string key;
    for(size_t i=0; i < test.size(); ++i) {
        key = test[i];
        list1.push_back(key);
    }
    cout<<"dump list1"<<endl;
    list1.dump();
    double_ll list2;
    list2.insert(list1.front(), "12345"); 
    list1.dump();
    list2.dump();

}


int main() {
    test2();

    return 0;
}
