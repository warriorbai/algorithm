/*
 *  A binary search tree implmentation.
 */

#ifndef  _BINARY_TREE_H 
#define  _BINARY_TREE_H
#include "stddef.h"
typedef enum {
   PRE, POST, IN
} TraverseType;

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
   void remove(int d);
   void print(TraverseType type);
private:
   TreeNode* find_min(TreeNode* node);
   void insert_imp(TreeNode* node, int d);
   TreeNode* remove_imp(TreeNode* node, int d);
   void preorder(TreeNode* node);
   void preorder_nr(TreeNode* node);
   void postorder(TreeNode* node);
   void postorder_nr(TreeNode* node);
   void inorder(TreeNode* node);
   void inorder_nr(TreeNode* node);
   TreeNode* _root;
};
#endif
