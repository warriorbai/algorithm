#include<vector>
#include<iostream>
#include<iostream>
#include<fstream>
#include<string>
#include"llcpp.h"

using namespace std;

//implement a C++ style single linked list
//data type: string





int main() {
    vector<int> test;
    string s;
    ifstream fin("data.txt");
    while(std::getline(fin, s) ) {
        test.push_back(atoi(s.c_str()));
    }

    single_ll header;
    


    return 0;
}
