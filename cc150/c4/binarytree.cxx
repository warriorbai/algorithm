#include "binarytree.h"
#include <iostream>
#include "stddef.h"
#include <stack>
#include <list>
#include <stdlib.h>
#include <algorithm>

BTree::BTree()
{
   _root = NULL;
}


BTree::~BTree()
{


}


bool
BTree::is_empty()
{
   return (_root == NULL);
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

   node->print();
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
      p->print();
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
   node->print();
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
            cur->print();
            pre = cur;
            cur = NULL;
         } else {
            if (pre == cur->right || pre == cur->left) {
               cur->print();
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
   node->print();
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
            p->print();
            p = p->right;
         }
      } else {
         p = snode.top();
         snode.pop();
         p->print();
         p = p->right;
      }
   }
}


void
BTree::print(TraverseType type,
             bool verbose)
{
   if (!this->_root) {
      std::cout << "NULL" << std::endl;
      return;
   } 

   switch(type) {
   case PRE:
      preorder_nr(this->_root);
      std::cout << std::endl;
      preorder(this->_root);
      break;
   case POST:
      postorder(this->_root);
      std::cout << std::endl;
      postorder_nr(this->_root);
      break;
   case IN:
      inorder(this->_root);
      std::cout << std::endl;
      inorder_nr(this->_root);
      break;
   default:
      std::cout << "Invalid traverse type." << std::endl;
   }
   std::cout << std::endl;
  
}


int
max_depth(TreeNode *node)
{
   if (node == NULL) {
      return 0;
   }
   return 1 + std::max(max_depth(node->left), max_depth(node->right));
}


int
min_depth(TreeNode *node)
{
   if (node == NULL) {
      return 0;
   }
   return 1 + std::min(min_depth(node->left), min_depth(node->right));
}


bool
BTree::is_balanced()
{
   if (_root == NULL) {
      return true;
   }

   return (max_depth(_root)-min_depth(_root) > 1)? false:true;
}


void
BTree::get_level_list(std::list<std::list<TreeNode*>*> &llist)
{
   if (_root == NULL) {
      return;
   }

   std::list<TreeNode*> *cur_list;
   std::list<TreeNode*> *new_list;
   new_list = new std::list<TreeNode*>;
   new_list->push_back(_root);
   cur_list = new_list;
   llist.push_back(new_list);
 
   while(cur_list) {
      new_list = new std::list<TreeNode*>;
      for(auto &item: *cur_list) {
         if (item->left) {
            new_list->push_back(item->left); 
         }
         if (item->right) {
            new_list->push_back(item->right);
         }
      }

      if (!new_list->empty()) {
         llist.push_back(new_list);
      } else {
         delete new_list;
         new_list = NULL;
      }
      cur_list = new_list;
   }
}


AVLTree::AVLTree()
{
   _root = NULL;
}


AVLTree::~AVLTree()
{
}


void
AVLTree::update_depth(AVLTreeNode *node)
{
   std::cout << "Update depth for node " << node->data << std::endl;
   AVLTreeNode  *p = node;
   if (p == NULL) {
      return;
   }

   while(p->parent) {
      AVLTreeNode *parent = dynamic_cast<AVLTreeNode*>(p->parent);
      if(p->depth + 1 > parent->depth) {
         parent->depth++;
      }
      p = dynamic_cast<AVLTreeNode*>(p->parent);
   }
}


AVLTreeNode*
AVLTree::find_non_balance_node(AVLTreeNode *node)
{
   AVLTreeNode *p = node;
   while(p) {
     AVLTreeNode *l = dynamic_cast<AVLTreeNode*>(p->left);
     AVLTreeNode *r = dynamic_cast<AVLTreeNode*>(p->right);
     int ldepth = l ? l->depth:0;
     int rdepth = r ? r->depth:0;
     if (abs(ldepth - rdepth) > 1) {
        break;
     }
     p = dynamic_cast<AVLTreeNode*>(p->parent); 
   }

   if (p) {
      std::cout << "Non balance node is "<< p->data << std::endl;
   } else {
      std::cout << "No violent node." << std::endl;
   }
   return p;
}

int
AVLTree::left_depth(AVLTreeNode *node)
{
   AVLTreeNode *l = dynamic_cast<AVLTreeNode*>(node->left);
   return l?l->depth:0;
}


int
AVLTree::right_depth(AVLTreeNode *node)
{
   AVLTreeNode *r = dynamic_cast<AVLTreeNode*>(node->right);
   return r?r->depth:0;
}


AVLTreeNode*
AVLTree::single_rotate(AVLTreeNode *node,
                       bool left)  // Non balance is at left/right
{
   std::cout << "single rotate. " << std::endl;

   AVLTreeNode *new_root = left? dynamic_cast<AVLTreeNode*>(node->left):
                                 dynamic_cast<AVLTreeNode*>(node->right);

   std::cout << " node " << node->data << std::endl;

   AVLTreeNode *tmp = NULL;
   if (left) {
      tmp = dynamic_cast<AVLTreeNode*>(new_root->right);
      new_root->right = node;
      node->left = tmp;
   } else {
      tmp = dynamic_cast<AVLTreeNode*>(new_root->left);
      new_root->left = node;
      node->right = tmp;
   }

   if (tmp) {
      tmp->parent = node;
   }

   TreeNode *parent = node->parent;  
   node->parent = new_root;

   if (parent) {
      if (parent->left == node) {
         parent->left = new_root;
      } else {
         parent->right = new_root;
      }
   } else {
      _root = new_root;
   }
   
   new_root->parent = parent;

   node->depth = std::max(left_depth(node), right_depth(node)) + 1;
   new_root->depth = std::max(left_depth(new_root), right_depth(new_root)) + 1;

   return new_root;
}


AVLTreeNode*
AVLTree::double_rotate(AVLTreeNode *node,
                       bool left)  // Non balance is at left/right
{
   std::cout << "double rotate. ";
   if (left) {
      std::cout << "left" << std::endl;
   } else {
      std::cout << "right" << std::endl;
   }

   AVLTreeNode *r1_node = left? dynamic_cast<AVLTreeNode*>(node->left):
                                dynamic_cast<AVLTreeNode*>(node->right);

   AVLTreeNode *new_root;
   new_root = single_rotate(r1_node, !left);

   return single_rotate(node, left);
}


void
AVLTree::avl_balancing(AVLTreeNode *node)
{
   AVLTreeNode *target = find_non_balance_node(node);

   if (target == NULL) {
      return;
   }

   AVLTreeNode *l = dynamic_cast<AVLTreeNode*>(target->left);
   AVLTreeNode *r = dynamic_cast<AVLTreeNode*>(target->right);
   int ldepth = l ? l->depth:0;
   int rdepth = r ? r->depth:0;

   bool insert_l = (ldepth > rdepth);

   AVLTreeNode *nd;
  
   nd = insert_l?l:r;
   

   bool s_rotate = false;
   if (insert_l) {
      if (left_depth(nd) > right_depth(nd)) {
         s_rotate = true; 
      } 
   } else {
      if (left_depth(nd) < right_depth(nd)) {
         s_rotate = true;
      }
   }
   
   if (s_rotate) {
      single_rotate(target, insert_l); 
   } else {
      double_rotate(target, insert_l);
   }

}


void
AVLTree::insert(int d)
{
   std::cout << "insert " << d << std::endl;
   if (_root == NULL) {
      _root = new AVLTreeNode;
      _root->data = d;
   } else {
      AVLTreeNode* new_node;
      new_node = insert_imp(dynamic_cast<AVLTreeNode*>(_root), d);
      avl_balancing(new_node);
   }
}


AVLTreeNode*
AVLTree::insert_imp(AVLTreeNode *node,
                    int d)
{
   AVLTreeNode *insert_node;
   AVLTreeNode *new_node;
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
      new_node = insert_imp(insert_node, d);
   } else {
      insert_node = new AVLTreeNode;
      insert_node->data = d;
      if (left) {
         node->left = insert_node;
      } else {
         node->right = insert_node;
      }
      insert_node->parent = node;
      new_node = insert_node;
      update_depth(new_node);
   }

   return new_node;
}

