#include <stdbool.h>
typedef int data_t;
typedef struct ListNode
{
    data_t val;
    struct ListNode *next;
}ListNode, *ptr_node;

void print_list(ptr_node head);
ptr_node append_node(ptr_node node, ptr_node head);
ptr_node list_tail(ptr_node head);
ptr_node make_node(data_t x);

// Leetcode
ptr_node reverse(ptr_node head);
ptr_node middle_node(ptr_node head);
ptr_node reverseBetween(ptr_node head, int m, int n);
ptr_node mergeTwoLists(ptr_node l1, ptr_node l2);
ptr_node deleteDuplicates(ptr_node head);
ptr_node deleteDuplicates2(ptr_node head);
bool hasCycle(ptr_node head);
bool isPalindrome(struct ListNode* head);
ptr_node removeElements(ptr_node head, int val);
ptr_node reverseKGroup(ptr_node head, int k);