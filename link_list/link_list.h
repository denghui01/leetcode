#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <stdbool.h>
typedef int data_t;
typedef struct ListNode
{
    data_t val;
    struct ListNode *next;
}ListNode, *ptr_node;

ptr_node append_node(ptr_node node, ptr_node head);
ptr_node list_tail(ptr_node head);
ptr_node make_node(data_t x);
int list_len(ptr_node head);
#endif
