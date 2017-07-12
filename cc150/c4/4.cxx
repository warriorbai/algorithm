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
   tree.insert(21);
   tree.insert(17);

   tree.print(PRE);
   //tree.print(POST);
   //tree.print(IN);
/*
   tree.remove(1);
   tree.print(PRE);
   tree.remove(28);
   tree.print(PRE);
   tree.remove(20);
   tree.print(PRE);
*/

   AVLTree avl;
   
   avl.insert(20);
   avl.insert(28);
   avl.insert(22);
   avl.insert(100);
   avl.insert(10);
   avl.insert(1);
   avl.insert(15);
   avl.insert(21);
   avl.insert(17);

   avl.print(PRE);

   return 0;
}
