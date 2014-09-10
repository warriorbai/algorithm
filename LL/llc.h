typedef struct sl_node {
    struct sl_node* next;
    int data;
} sl_node, *slist;



bool insertNode(slist *head, int key);
slist searchNode(slist *head, int key); 
void deleteNode(slist *head, int key); 
void dumpList(slist *head); 

