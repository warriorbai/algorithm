//use unordered_map to solve top k 

#include<iostream>
#include<fstream>
#include<tr1/unordered_map>

using namespace std;
using namespace std::tr1;



int main() {
    string s;
    ifstream fin("data.txt");
    while(std::getline(fin, s) ) {

        cout<<s<<endl;

    }

    return 0;
}
