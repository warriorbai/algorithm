#include<iostream>
/* Given a circular linked list, implement an algorithm which returns node at the beginning of the loop
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an
earlier node, so as to make a loop in the linked list
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C
*/

using namespace std;

class Node
{
public:
   int data;
   Node *next;
};

typedef Node* pNode;

void build_list(pNode *list)
{
   pNode p = NULL;
   pNode head = NULL;
   pNode tail = NULL;
   pNode mid = NULL;
   for (int i = 0; i < 10; i++) { 
      p = new Node;
      p->data = i;
      if (tail) {
         tail->next = p; 
      } else {
         head = p;
      }
      tail = p;
      if (i == 5) {
         mid = p;
      }
   }

   tail->next = mid; 
   *list = head;
}

void dump(pNode list)
{
   if (list == NULL) {
      return;
   }

   pNode p = list;
   for (int i = 0; i < 20; i++) { 
      cout << p->data << endl;
      p = p->next;
   }

}

pNode find_loop(pNode list)
{
   if (list == NULL) {
      return NULL;
   }

   pNode n1 = list;
   pNode n2 = list;

   while (n2->next) {
      n1 = n1->next;
      n2 = n2->next->next;
      if (n1 == n2) {
         break;
      }
   }

   if (n1 == NULL) {
      return NULL;
   }

   n2 = list;
   
   while (n1 != n2) {
      n1 = n1->next;
      n2 = n2->next;
   }

   return n2;
}

int main()
{
   pNode list;
   build_list(&list);
   dump(list);
   pNode loop_node;
   loop_node = find_loop(list);
   if (loop_node) {
      cout << "loop node is " << loop_node->data << endl;
   } else {
      cout << "list has no loop." << endl;
   }
   return 0;
}
