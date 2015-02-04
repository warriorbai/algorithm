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
    unordered_map<int, int> map1;
    int i = 0;
    //map1.rehash(101);
    map1.max_load_factor(100);
    while(i++ != 100) {
        map1.insert(make_pair(i,3));
        cout<<map1.bucket_count()<<" "<<map1.max_bucket_count()<<endl;
    }
    for(int i = 0; i < map1.bucket_count();i++) {
        cout<<map1.bucket_size(i)<<" ";
    }
    cout<<endl;
    cout<<"load factor:"<<map1.load_factor()<<endl;
    cout<<"max load factor:"<<map1.max_load_factor()<<endl;
    return 0;

}
