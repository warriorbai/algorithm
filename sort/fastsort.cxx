#include<vector>
#include<iostream>
#include<iostream>
#include<fstream>

using namespace std;

void fast_sort(vector<int>& src, int begin, int end)
{
    if(end - begin < 1) return;
    int x = src[end];
    int i,j;
    for(j = begin, i = begin; j < end; ++j) {
        if(src[i] < x) {
            i++;
        } else if(src[j] < x && src[i] >=x) {
            int temp = src[j];
            src[j] = src[i];
            src[i] = temp;
            i++;
        }
    }
    int temp = src[i];
    src[i] = src[end];
    src[end] = temp;

    fast_sort(src, begin, i-1);
    fast_sort(src, i+1, end);

}

void dump(vector<int>& src)
{
    for(int i=0;i<src.size();++i) {
        cout<<src[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> test;
    string s;
    ifstream fin("data.txt");
    while(std::getline(fin, s) ) {
        test.push_back(atoi(s.c_str()));
    }

    fast_sort(test,0,test.size()-1);
    dump(test);
    return 0;
}
