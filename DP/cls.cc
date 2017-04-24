// Common longest sub seq
// 0  x- y- 
// 1  x-
// 2  y-
#include "gen.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

void print_vec(vector<int> &vec)
{
   for (int i = 0; i < vec.size(); i++) {
      cout << vec[i] << " ";
   }
   cout << endl;
}

void get_result(vector<int> &b, vector<int> &result, vector<int> &v2, int x, int y) 
{
   if (x < 0 || y < 0) {
      return;
   }

   if (b[x * v2.size() + y] == 0) {
      result.push_back(v2[y]);
      get_result(b, result, v2, x-1, y-1);
   } else if (b[x * v2.size() + y] == 1) {
      get_result(b, result, v2, x-1, y); 
   } else if (b[x * v2.size() + y] == 2) {
      get_result(b, result, v2, x, y-1);
   }
}

void find_cls(vector<int> &v1, vector<int> &v2, vector<int> &result)
{
   int x = v1.size();
   int y = v2.size();
   int vc_size = x * y;
   vector<int> vc (vc_size, 0);
   vector<int> b(vc_size, -1);
   
   for (int i = 0; i < v1.size(); i++) {
      for (int j = 0; j < v2.size(); j++) {
   //      cout << i << "," << j << " " << "x,y= " << x << " " << y << endl;
         if (v1[i] == v2[j]) {
            if (i == 0 || j == 0) {
               vc[i*y + j] = 1;
            } else {
               vc[i*y + j] = vc[(i-1)*y + (j-1)] + 1;
            }
            b[i*y + j] = 0;
         } else {
            if (i == 0 || j == 0) {
               continue;
            }
        
            if (vc[(i-1)*y + j] >= vc[i*y + (j-1)]) {
               vc[i*y + j] = vc[(i-1)*y + j];
               b[i*y + j] = 1;
            } else if (vc[(i-1)*y + j] < vc[i*y + (j-1)]) {
               vc[i*y + j] = vc[i*y + (j-1)];
               b[i*y + j] = 2;
            }
         }
      }
   } 

  
   cout << vc[x*y-1] << endl;

   //print_vec(b);
   // get resilt
   get_result(b, result, v2, x-1, y-1); 

   int rsz = result.size();
   for (int i = 0; i < rsz/2; i++) {
      int tmp = result[i];
      result[i] = result[rsz-1-i];
      result[rsz-1-i] = tmp;
   }
}


int main()
{
   //vector<int> v1 = {2, 3, 5, 7, 11, 13, 19};
   //vector<int> v2 = {1, 3, 5, 7, 9};
   vector<int> v1;
   vector<int> v2;
   srand(time(NULL));

   gen(0, 15, 15, v1);
   gen(0, 15, 12, v2);   

   vector<int> res;

   find_cls(v1, v2, res);
   print_vec(v1);
   print_vec(v2);
   print_vec(res);
   return 0;

}
