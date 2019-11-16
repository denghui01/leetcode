#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
#include "link_list.h"

using namespace std;

void print_list(ptr_node head)
{
    ptr_node node = head;
    while(node)
    {
        printf("%d->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

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

// Leetcode questions
// 206. Reverse Linked List
ptr_node reverse(ptr_node head)
{
    ptr_node new_head = NULL;
    while(head)
    {
        ptr_node temp = head;
        head = head->next;
        temp->next = new_head;
        new_head = temp;
    }
    return new_head;
}

// Leetcode questions
// 876. Middle of the Linked List
ptr_node middle_node(ptr_node head)
{
    ptr_node one_step = head;
    if(one_step == NULL) return NULL; // Empty

    ptr_node two_step = one_step->next;
    while(two_step)
    {
        one_step = one_step->next;
        two_step = two_step->next;
        if(two_step == NULL) break;
        two_step = two_step->next;
    }
    return one_step; // Return only the real node, not the head of list
}

//92. Reverse Linked List II
// m, n should be 1-based
//typedef struct ListNode *ptr_node;
ptr_node reverseBetween(ptr_node head, int m, int n)
{    
    assert(m > 0 && n > 0); 
    assert(n >= m);
    if(m == n) return head; 

    ptr_node new_head = NULL;
    ptr_node tail1 = NULL;
    ptr_node tail2 = head;
    ptr_node old_head = head;
    while(head)
    {
        if(--m > 0)
        {
            tail1 = head;
            new_head = head;
            head = head->next;
            tail2 = head;
            --n;
        }
        else // start to reverse
        {
            if(--n >= 0)
            {
                ptr_node temp = head;
                head = head->next;
                temp->next = new_head;
                new_head = temp;
            }
            else // finished
            {
                break;
            }            
        }        
    }
    
    tail2->next = head;
    if(tail1)
    {
        tail1->next = new_head;
        return old_head;
    }
    else
    {
        return new_head;
    }
}

//21. Merge Two Sorted Lists
ptr_node mergeTwoLists(ptr_node l1, ptr_node l2)
{
    ptr_node head1, head2, head;
    if(!l1) return l2;
    if(!l2) return l1;    
    if(l2->val >= l1->val)
    {
        head1 = l1;
        head = l1;
        head2 = l2;        
    }
    else
    {
        head1 = l2;
        head = l2;
        head2 = l1;
    }
    ptr_node tail = head1;
    while(head1 && head2)
    {
        while(head1 && head2->val >= head1->val)
        {
            tail = head1;
            head1 = head1->next;
        }
        tail->next = head2;

        if(head1)
        {
            while(head2 && head2->val < head1->val)
            {
                tail = head2;
                head2 = head2->next;
            }
            tail->next = head1;
        }
    }
    return head;
}

//83. Remove Duplicates from Sorted List
ptr_node deleteDuplicates(ptr_node head)
{
    if(!head) return head;

    ptr_node node1, node2;
    node1 = head;
    node2 = head;
    while(node1)
    {
        while(node2 && node2->val == node1->val)
        {
            node2 = node2->next;
        }
        node1->next = node2;
        node1 = node2;        
    }
    return head;
}

//82. Remove Duplicates from Sorted List II
ptr_node deleteDuplicates2(ptr_node head)
{
    if(!head) return head;

    ptr_node new_head, node1, node2;
    new_head = NULL;
    node1 = head;
    node2 = head->next;
    while(node1)
    {
        while(node2 && node2->val == node1->val)
        {
            node2 = node2->next;
        }
        node1->next = node2;
        node1 = node2;        

    }
    return head;
}

//141. Linked List Cycle
bool hasCycle(ptr_node head) 
{
    if(!head) return false;
    ptr_node node1 = head;
    ptr_node node2 = head->next;

    while(node1 != node2)
    {
        node1 = node1->next;
        if(node2)
        {
            node2 = node2->next;
        }
        else
        {
            return false;
        }
        if(node2){
            node2 = node2->next;
        }
        else
        {
            return false;
        }        
    }  
    return true;  
}

// 234. Palindrome Linked List
bool isPalindrome(struct ListNode* head){
    if(!head) return true;

    stack<ptr_node> s;
    ptr_node origin = head;
    while(head)
    {
        s.push(head);
        head = head->next;
    }

    while(origin)
    {
        head = s.top();
        if(origin->val != head->val){
            return false;
        }
        s.pop();
        origin = origin->next;
    }
    return true;    
}

// 203. Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val) {
    if(!head) return NULL;
    ptr_node new_head = NULL;
    while(head && head->val == val)
    {
        head = head->next;
    }
    new_head = head;
    while(head && head->next)    
    {
        if(head->next->val == val)
        {
            head->next = head->next->next;
        }
        else
        {
            head = head->next;
        }        
    }
    return new_head;
}