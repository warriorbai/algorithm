#include <iostream>
#include <vector>
#include <list>
#include "binarytree.h"
using namespace std;

// 4.1  check tree balance
// DFS
bool
is_balanced(BTree *tree)
{
   if(tree == NULL) {
      return true;
   }

   return tree->is_balanced();
}
// 4.2 graph 
// pending


//4.3 sorted array to tree with least height
void
build_tree(int from,
           int to,
           vector<int> &vec,
           BTree* tree)
{
   int mid;

   if (from > to) {
      return;
   }

   mid = from + (to - from) / 2;

   std::cout << "mid is " << mid << std::endl; 
   
   tree->insert(vec[mid]);
 
   build_tree(from, mid-1, vec, tree); 
   build_tree(mid+1, to, vec, tree); 
}


BTree*
array_to_tree(vector<int> &vec)
{
   BTree *tree = new BTree();

   build_tree(0, vec.size()-1, vec, tree);

   return tree;
}

//4.4 get a list of nodes at each depth for binary search tree
void
get_list_of_binary_tree(BTree* tree,
                        list<list<TreeNode*>* > &llist)
{
   if (tree == NULL || tree->is_empty()) {
      return;
   }

   tree->get_level_list(llist);

   std::cout << "Output result. " << std::endl;

   int i = 1;
   for(auto l: llist) {
      std::cout << "Level " << i << std::endl;
      for (auto &i: *l) {
         std::cout << " " << i->data;
      }
      std::cout << std::endl;
      i++;
   }

}

void
gen_tree(BTree *tree)
{
   if (!tree) {
      return;
   }


   tree->insert(101);
   tree->insert(102);
   tree->insert(103);
   tree->insert(105);
   tree->insert(50);
   tree->insert(59);
   tree->insert(30);
   tree->insert(1);
   tree->insert(200);
   tree->insert(207);

}


int main()
{
   // 4.1
   cout << "\n4.1 run." << endl;
   BTree *tree = new BTree();
   gen_tree(tree); 
   std::cout << ((tree->is_balanced())? "true" : "false") << endl;

   // 4.3
   cout << "\n4.3 run." << endl;
   vector<int> vec1 = {1,2,3,4,5,6,7,8,9, 100, 101,102,104,105,106};
   BTree *tree43;
   tree43 = array_to_tree(vec1);
   tree43->print(PRE);

   // 4.4 
   cout << "\n4.4 run." << endl;
   list<list<TreeNode*>*> llist; 
   get_list_of_binary_tree(tree, llist); 

   return 0;
}
