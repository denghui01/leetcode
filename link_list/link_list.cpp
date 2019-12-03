#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "link_list.h"

using namespace std;

ptr_node list_tail(ptr_node head)
{
    if(head == NULL) return NULL; // Empty
    ptr_node node = head;
    while(node->next)
    {
        node = node->next;
    }
    return node;
}

ptr_node make_node(data_t x)
{
    ptr_node node = (ptr_node)malloc(sizeof(ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

ptr_node append_node(ptr_node node, ptr_node head)
{
    if(!head) // Empty
    {
        return node;
    }    
    else
    {
        ptr_node tail = list_tail(head);
        if(tail)
        {
            tail->next = node;
        }
        return head;
    }    
}

int list_len(ptr_node head)
{
    int length = 0;
    while(head)
    {
        ++length;
        head = head->next;
    }
    return length;
}

