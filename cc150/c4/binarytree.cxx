#include "binarytree.h"
#include <iostream>
#include "stddef.h"

BTree::BTree()
{
   _root = NULL;
}

BTree::~BTree()
{


}

void BTree::insert_imp(TreeNode *node, int d)
{
   TreeNode *insert_node;
   bool left;

   if (d >= node->data) {
      insert_node = node->right;
      left = false;
   } else {
      insert_node = node->left;
      left = true;
   }

   if (insert_node != NULL) {
      insert_imp(insert_node, d);
   } else {
      insert_node = new TreeNode;
      insert_node->data = d;
      if (left) {
         node->left = insert_node;
      } else {
         node->right = insert_node;
      }
   }
}

void BTree::insert(int d)
{
   if (_root == NULL) {
      _root = new TreeNode;
      _root->data = d;
   } else {
      insert_imp(_root, d);
   }
}

void BTree::preorder(TreeNode *node)
{
   if (!node) {
      return;
   }

   std::cout << node->data << std::endl;
   preorder(node->left);
   preorder(node->right);

}

void BTree::print()
{
   if (!_root) {
      std::cout << "NULL" << std::endl;
      return;
   } 

   preorder(_root);
}
