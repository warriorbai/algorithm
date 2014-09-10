#include"llc.h"
#include"stdio.h"
//C-style linked list basic function implmentation
//head is a pointer to head node's address.
bool insertNode(slist *head, int key) {
    if(!head)    return false;
    slist new_node = new sl_node; 
    if(!new_node)    return false;
    new_node->data = key;
    new_node->next = *head;
    *head = new_node;
    return true;
}

slist searchNode(slist *head, int key) {


}

void deleteNode(slist *head, int key) {

}

void dumpList(slist *head) {
    if(!head) return;
    slist pnode = *head;
    while(pnode != NULL) {
        printf("%d ", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");
}

