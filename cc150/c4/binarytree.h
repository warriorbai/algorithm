#ifndef  _BINARY_TREE_H 
#define  _BINARY_TREE_H
#include "stddef.h"
class TreeNode
{
public:
   TreeNode()
   {
      left = NULL;
      right = NULL;
   }
   int data;
   TreeNode *left;
   TreeNode *right;
};

class BTree
{
public:
   BTree();
   ~BTree();
   void insert(int d);
   void print();
   
private:
   void insert_imp(TreeNode* node, int d);
   void preorder(TreeNode* node);
   TreeNode* _root;
};
#endif
