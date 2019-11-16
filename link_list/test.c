#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

int main()
{
    // leetcode questions
    // 206. Reverse Linked List
    ptr_node head = NULL;
    ptr_node node;
    for(int i = 1; i < 9; ++i)
    {
        head = append_node(make_node(i), head);
    }
    // [1,2,3,4,5,6,7,8]
    print_list(head);

    // 206. Reverse Linked List
    head = reverse(head);
    print_list(head);

    // [1,2,3,4,5,6,7,8]
    head = reverse(head);
    print_list(head);

    // 876. Middle of the Linked List
    print_list(middle_node(head)); // [5,6,7,8]

    head = append_node(make_node(9), head);
    // [1,2,3,4,5,6,7,8,9]
    print_list(head);
    print_list(middle_node(head)); //[5,6,7,8,9]
    
    // 92. Reverse Linked List II
    print_list(reverseBetween(head, 3, 4));

    // 21. Merge Two Sorted Lists
    ptr_node list1 = NULL;
    ptr_node list2 = NULL;
    list1 = append_node(make_node(1), list1);
    list1 = append_node(make_node(2), list1);
    list1 = append_node(make_node(4), list1);

    list2 = append_node(make_node(1), list2);
    list2 = append_node(make_node(3), list2);
    list2 = append_node(make_node(4), list2);    
    print_list(mergeTwoLists(list1, list2));

    //83. Remove Duplicates from Sorted List#include <stdbool.h>
    ptr_node list3 = NULL;
    list3 = append_node(make_node(1), list3);
    list3 = append_node(make_node(2), list3);
    list3 = append_node(make_node(2), list3);
    list3 = append_node(make_node(2), list3);
    list3 = append_node(make_node(3), list3);

    print_list(deleteDuplicates(list3));

    //141. Linked List Cycle
    ptr_node list4 = NULL;
    list4 = append_node(make_node(1), list4);
    list4 = append_node(make_node(2), list4);
    list4 = append_node(make_node(2), list4);
    list4 = append_node(make_node(3), list4);
    list4 = append_node(make_node(1), list4);
    ptr_node tail = list_tail(list4);
    //tail->next = list4->next->next;
    printf("Has Cycle? %s\n", hasCycle(list4)?"Yes":"No");

    // 234. Palindrome Linked List
    printf("Palindrome? %s\n", isPalindrome(list4)?"Yes":"No");

    // 203. Remove Linked List Elements
    print_list(removeElements(list4, 1));
    print_list(removeElements(list4, 2));
    print_list(removeElements(list4, 3));

    //25. Reverse Nodes in k-Group
    ptr_node list5 = NULL;
    list5 = append_node(make_node(1), list5);
    list5 = append_node(make_node(2), list5);
    list5 = append_node(make_node(3), list5);
    list5 = append_node(make_node(4), list5);
    //list5 = append_node(make_node(5), list5);    
    print_list(reverseKGroup(list5, 4));


    return EXIT_SUCCESS;
}