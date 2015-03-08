#include<vector>
#include<iostream>
#include<string>
#include<map>
#include"common.h"
using namespace std;
typedef void (*pFunc)();
map<string, pFunc> funcMap;
void init_func_map() {
    funcMap.insert(pair<string, pFunc>("1.1", test_1_1));
    funcMap.insert(pair<string, pFunc>("1.2", test_1_2));
    funcMap.insert(pair<string, pFunc>("1.3", test_1_3));
    funcMap.insert(pair<string, pFunc>("1.4", test_1_4));
    funcMap.insert(pair<string, pFunc>("1.6", test_1_6));
    funcMap.insert(pair<string, pFunc>("1.7", test_1_7));
    funcMap.insert(pair<string, pFunc>("1.8", test_1_8));
    funcMap.insert(pair<string, pFunc>("2.1", test_2_1));
    funcMap.insert(pair<string, pFunc>("2.2", test_2_2));
    funcMap.insert(pair<string, pFunc>("2.3", test_2_3));
}

int main() {
    string option;
    init_func_map();
    cout<<"Input case num:";
    cin>>option;
    map<string, pFunc>::iterator it = funcMap.find(option);
    if(it != funcMap.end()) {
        (it->second)();
    } else {
        cerr<<"Wrong option. No matching case."<<endl;    
    }
    cout<<endl;
    return 0;
}
