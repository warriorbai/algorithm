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

//4.6 find common ancestor
// See BTree::find_common_ancestor();


// 4.7 Check if a binrary tree is subtree of another.

bool
match(TreeNode *t1,
      TreeNode *t2)
{
   if (t1 == NULL && t2 == NULL) {
      return true;
   }

   if (t1 && t2 && (t1->data == t2->data) &&
       match(t1->left, t2->left) &&
       match(t1->right, t2->right)) {
      return true;
   } else {
      return false;
   } 
}


bool
is_subtree(TreeNode *n1,
           TreeNode *n2)
{
   if (n1 == NULL) {
      return false;
   }

   if (n1->data == n2->data) {
      if (match(n1, n2)) {
         return true;
      }
   } 
   
   return is_subtree(n1->left, n2) || is_subtree(n1->right, n2);
}


// Check if tr1 conmtains tr2.
bool
check_contain_tree(BTree *tr1,
                   BTree *tr2)
{
   if (tr2 == NULL || tr2->is_empty()) {
      return true;
   }

   if (tr1 == NULL || tr1->is_empty()) {
      return false;
   }

   TreeNode *r1 = tr1->get_root();
   TreeNode *r2 = tr2->get_root();

   return is_subtree(r1, r2);
}


// 4.8 Find path that sum to a value.
void
print_path(vector<TreeNode*> &vnodes,
           int idx)
{
   for (int i = idx; i < vnodes.size(); i++) {
      std::cout << vnodes[i]->data << " ";
   }
   std::cout << std::endl;
}


void
find_path(TreeNode *root,
          int val,
          vector<TreeNode*> &vnodes)
{
   if (root) {
      vnodes.push_back(root);
   } else {
      return;
   }
   
   int size = vnodes.size();
   int tmp = val;

   for(int i = size-1; i >= 0; i--) {
      tmp = tmp - vnodes[i]->data;
      if (tmp == 0) {
         print_path(vnodes, i);
      }
   }

   find_path(root->left, val, vnodes);
   find_path(root->right, val, vnodes);

   vnodes.pop_back();
}


void
find_paths_sum_to_value(BTree *tree,
                        int value)
{
   if (tree == NULL || tree->is_empty()) {
      return;
   }

   TreeNode *root = tree->get_root();
   vector<TreeNode*> vnodes;
   find_path(root, value, vnodes);
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
   tree->insert(199);
   tree->insert(55);
   tree->insert(67);
}


void
gen_tree(BTree *tree,
         vector<int> &vec)
{
   if (!tree) {
      return;
   }

   for (auto &i: vec) {
      tree->insert(i);
   }
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

   // 4.6
   cout << "\n4.6 run." << endl;
   TreeNode *n1 = tree->get_node(101); 
   TreeNode *n2 = tree->get_node(101); 
   cout << n1->data << " " << n2->data << endl;
   TreeNode *an = tree->find_common_ancestor(n1, n2);
   cout << "common ancestor is: " << an->data << endl;

   // 4.7
   cout << "\n4.7 run." << endl;
   vector<int> vec47 = {105, 207, 200, 199};
   BTree *tree47 = new BTree();
   gen_tree(tree47, vec47);
   bool yes = check_contain_tree(tree, tree47);
   cout << "Contains. " << (yes? "yes":"no") << endl;

   // 4.8
   cout << "\n4.8 run." << endl;
   int val = 105;
   cin >> val;
   vector<int> vec48 = {50, 25, 55, 100, 20, 30, 5, 45};
   BTree *tree48 = new BTree();
   gen_tree(tree48, vec48);
   find_paths_sum_to_value(tree48, val); 
   return 0;
}
