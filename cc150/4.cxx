#include <iostream>
using namespace std;

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

   cout << node->data << endl;
   preorder(node->left);
   preorder(node->right);

}

void BTree::print()
{
   if (!_root) {
      cout << "NULL" << endl;
      return;
   } 

   preorder(_root);
}


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

   tree.print();
   return 0;
}
