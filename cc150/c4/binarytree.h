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
   typedef enum {
      PRE, POST, IN
   } TraverseType
   
private:
   void insert_imp(TreeNode* node, int d);
   void preorder(TreeNode* node);
   void postorder(TreeNode* node);
   void inorder(TreeNode* node);
   TreeNode* _root;
};
#endif
