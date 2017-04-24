#include <iostream>
#include "binarytree.h"
using namespace std;

int main()
{
   BTree tree;
   tree.insert(20);
   tree.insert(28);
   tree.insert(22);
   tree.insert(100);
   tree.insert(10);
   tree.insert(1);
   tree.insert(15);

   tree.print();
   return 0;
}
