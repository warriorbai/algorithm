// implementation of hash table with C ( key type C-stype string, value type integer )
// hash chaining
// seperate chaining
#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
typedef const char* ElementType; 
struct ListNode {
    ElementType element;
    ListNode* next;
};
typedef ListNode* List; 
struct hash_table {
    int table_size;
    List* lists; 
};

typedef struct hash_table* Hash;
// functions for hash table
int hash_func(const char* str) {
    return strlen(str);
}

bool comp_func(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

List find(Hash hash_table, const char* str) {
    List L;
    L = hash_table->lists[hash_func(str) % hash_table->table_size];
    List s = L;
    while(s != NULL && comp_func(s->element, str)!=0) {
        s = s->next;
    }
    return s;
}

void insert(Hash hash_table, const char* str) {


}

Hash initialize_hash(int bucket_num) {
    if(bucket_num < 0) return 0;

    Hash hash = (Hash)malloc(sizeof(hash_table));

    if(hash == 0)    return 0;
    hash->lists = (List*)malloc(bucket_num * sizeof(List));
    hash->table_size = bucket_num;
}

void dump_hash(Hash hash) {


}

int main() {
    string s;
    Hash hash1; 
    hash1 = initialize_hash(31);
    ifstream fin("data.txt");
    while(std::getline(fin, s) ) {
        cout<<s<<endl;
    //    insert(hash1, s.c_str());
    }
    int* aaa;
    cout<< sizeof(List) <<endl;
    cout<< sizeof(aaa) <<endl;
    return 0;
}

