/*
 *  A binary search tree implmentation.
 */

#ifndef  _BINARY_TREE_H 
#define  _BINARY_TREE_H
#include "stddef.h"
#include <iostream>

typedef enum {
   PRE,
   POST,
   IN
} TraverseType;

class TreeNode
{
public:
   TreeNode()
   {
   //   std::cout << "Build a binary tree node." << std::endl;
      left = NULL;
      right = NULL;
   }
   
   virtual void print()
   {
      std::cout << data << " ";
   }

   int data;
   TreeNode *left;
   TreeNode *right;
};


class AVLTreeNode: public TreeNode
{
public:
   AVLTreeNode()
   {
      std::cout << "Build a AVL tree node." << std::endl;
      parent = NULL;
      depth = 1;
   }
   
   void print()
   {
      std::cout << data << "__" << depth << " ";
   }

   int depth;  //Max depth of the tree the node as a root.
   TreeNode *parent;
};


class BTree
{
public:
   BTree();
   ~BTree();
   virtual void insert(int d);
   void remove(int d);
   void print(TraverseType type);
protected:
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

class AVLTree : public BTree
{
public:
   AVLTree();
   ~AVLTree();
   void insert(int d);
private:
   AVLTreeNode* insert_imp(AVLTreeNode* node, int d);
   void update_depth(AVLTreeNode *node);
   AVLTreeNode* find_non_balance_node(AVLTreeNode *node);
   void avl_balancing(AVLTreeNode *node);
   int left_depth(AVLTreeNode *node); 
   int right_depth(AVLTreeNode *node); 
   AVLTreeNode* single_rotate(AVLTreeNode *node, bool insert_l); 
   AVLTreeNode* double_rotate(AVLTreeNode *node, bool insert_l);
};

#endif
