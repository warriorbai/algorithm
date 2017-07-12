#include "binarytree.h"
#include <iostream>
#include "stddef.h"
#include <stack>

BTree::BTree()
{
   _root = NULL;
}


BTree::~BTree()
{


}


void
BTree::insert_imp(TreeNode *node,
                  int d)
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


void
BTree::insert(int d)
{
   if (_root == NULL) {
      _root = new TreeNode;
      _root->data = d;
   } else {
      insert_imp(_root, d);
   }
}


TreeNode*
BTree::find_min(TreeNode *node)
{
   TreeNode *n = node;
   while(n && n->left) {
      n = n->left;
   }
   return n;
}


TreeNode*
BTree::remove_imp(TreeNode *node,
                  int d)
{
   TreeNode *n = node;
   TreeNode *tmp = NULL;

   if (n == NULL) {
      return NULL;
   } else if (d > n->data) {
      n->right = remove_imp(n->right, d);   
   } else if (d < n->data) {
      n->left = remove_imp(n->left, d);
   } else {
   // Found node and remove it
      if (n->left && n->right) {
      // Two child, need choose a new one replace itself
         tmp = find_min(n->right);
         n->data = tmp->data;
         n->right = remove_imp(n->right, n->data);
      } else {
      // One or zero chiled, remove and child replace itseft.
         tmp = n;
         if (n->left == NULL) {
            n = n->right;
         } else if (n->right == NULL) {
            n = n->left;
         }
         delete tmp;
      }
   }
   return n;
}


void
BTree::remove(int d)
{
   if (_root == NULL) {
      return;
   } else {
      remove_imp(_root, d);
   }
}


void
BTree::preorder(TreeNode *node)
{
   if (!node) {
      return;
   }

   std::cout << node->data << " ";
   preorder(node->left);
   preorder(node->right);

}


//Non-recursive method
void
BTree::preorder_nr(TreeNode *node)
{
   if (!node) {
      return;
   }

   TreeNode *p;
   p = node;
   std::stack<TreeNode*> snode;

   while(p != NULL || !snode.empty()) {
      if (p == NULL) {
         p = snode.top();
         snode.pop();
      }
      std::cout << p->data << " "; 
      if (p->right) {
         snode.push(p->right);
      }
      p = p->left;
   }

}


void
BTree::postorder(TreeNode *node)
{
   if (!node) {
      return;
   }

   postorder(node->left);
   postorder(node->right);
   std::cout << node->data << " ";

}


// Non-recursive
void
BTree::postorder_nr(TreeNode *node)
{
   if (!node) {
      return;
   }

   TreeNode *cur;
   TreeNode *pre;
   cur = node;
   pre = NULL;
   std::stack<TreeNode*> snode;

   while(cur != NULL || !snode.empty()) {
      if (cur != NULL) {
         snode.push(cur);
         if (cur->right) {
            snode.push(cur->right);
         }
         cur = cur->left;
      } else {
         cur = snode.top();
         snode.pop(); 
         if (!cur->left && !cur->right) {
            std::cout << cur->data << " ";
            pre = cur;
            cur = NULL;
         } else {
            if (pre == cur->right || pre == cur->left) {
               std::cout << cur->data << " ";
               pre = cur;
               cur = NULL;
            }
         }
      }
   }
}


void
BTree::inorder(TreeNode *node)
{
   if (!node) {
      return;
   }

   inorder(node->left);
   std::cout << node->data << " ";
   inorder(node->right);

}


//Non-recursive method
void
BTree::inorder_nr(TreeNode *node)
{
   if (!node) {
      return;
   }

   TreeNode *p;
   p = node;
   std::stack<TreeNode*> snode;

   while(p != NULL || !snode.empty()) {
      if (p != NULL) {
         if (p->left) {
            snode.push(p);
            p = p->left;
         } else {
            std::cout << p->data << " ";
            p = p->right;
         }
      } else {
         p = snode.top();
         snode.pop();
         std::cout << p->data << " ";
         p = p->right;
      }
   }
}


void
BTree::print(TraverseType type)
{
   if (!_root) {
      std::cout << "NULL" << std::endl;
      return;
   } 

   switch(type) {
   case PRE:
      preorder_nr(_root);
      std::cout << std::endl;
      preorder(_root);
      break;
   case POST:
      postorder(_root);
      std::cout << std::endl;
      postorder_nr(_root);
      break;
   case IN:
      inorder(_root);
      std::cout << std::endl;
      inorder_nr(_root);
      break;
   default:
      std::cout << "Invalid traverse type." << std::endl;
   }
   std::cout << std::endl;
  
}


AVLTree::AVLTree()
{
   _root = NULL;
}


AVLTree::~AVLTree()
{
}


void
AVLTree::insert(int d)
{
   if (_root == NULL) {
      _root = new AVLTreeNode;
      _root->data = d;
      _root->depth = 1;
   } else {
      _root = insert_imp(_root, d);
   }
}


AVLTreeNode*
AVLTree::insert_imp(AVLTreeNode *node,
                    int d)
{
   AVLTreeNode *insert_node;
   bool left;

   if (node == NULL) {
      return 0;
   }

   if (d >= node->data) {
      insert_node = static_cast<AVLTreeNode*>(node->right);
      left = false;
   } else {
      insert_node = static_cast<AVLTreeNode*>(node->left);
      left = true;
   }

   if (insert_node != NULL) {
      insert_imp(insert_node, d);
   } else {
      insert_node = new AVLTreeNode;
      insert_node->data = d;
      if (left) {
         node->left = insert_node;
      } else {
         node->right = insert_node;
      }
      insert_node->parent = node;
   }
}

