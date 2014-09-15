//c++ style linked list
#include<string>

using namespace std;


class ll_node {
public:
    ll_node() 
    { 
        prev = NULL;
        next = NULL;
    }
        
    string data;
    ll_node* prev;
    ll_node* next;
};


class double_ll {
public:
//functions
    double_ll();
    bool insert(ll_node* pos, string str);
    ll_node* search(string str);
    bool push_front(string str);
    bool push_back(string str);
    bool pop_front();
    bool pop_back();
    size_t size();
    ll_node* front();
    ll_node* back();
    bool remove(string str);
    bool erase(ll_node* item);
    bool clean();
    void dump();
// complex functions
    void reverse_list();

//data member
private:
    ll_node* header;
    ll_node* tail;
    size_t numNode;
}; 
