#include"llc.h"
#include"stdio.h"
#include"stdlib.h"
//C-style linked list basic function implmentation
//head is a pointer to head node's address.
bool insertNode(slist *head, int key) {
    if(!head)    return false;
    slist new_node = (slist)malloc(sizeof(sl_node)); 
    if(!new_node)    return false;
    new_node->data = key;
    new_node->next = *head;
    *head = new_node;
    return true;
}

slist searchNode(slist *head, int key) {
    if(!head || !(*head))    return 0;
    slist pnode = *head;
    while(pnode) {
        if(pnode->data == key) {
            return pnode;
        }
        pnode = pnode->next;
    }
}

void deleteNode(slist *head, int key, bool delete_all) {
    if(!head || !*head)    return;
    slist pnode = *head;
    slist plast = NULL;
    slist pnext = NULL;
    while(pnode) {
        pnext = pnode->next;
        if(pnode->data == key) {
            if(!plast) {
                *head = pnode->next;
            } else {
                plast->next = pnode->next;    
            }
            free(pnode);
            if(!delete_all) {
                return;
            } else {
                pnode = pnext;
                continue;
            } 
        }
        plast = pnode;
        pnode = pnext;
    }
}

void dumpList(slist *head) {
    if(!head) return;
    slist pnode = *head;
    while(pnode) {
        printf("%d ", pnode->data);
        pnode = pnode->next;
    }
    printf("\n");
}

