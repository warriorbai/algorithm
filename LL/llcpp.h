//c++ style linked list
#include<string>

using namespace std;


class single_ll {
public:
    single_ll() { next = NULL; }    
    string getValue() const { return data;}
    string setValue(string str) { data = str;}
    single_ll* getNext() const { return next; }

private:
    string data;
    single_ll* next;

}; 
