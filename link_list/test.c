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

    //83. Remove Duplicates from Sorted List
    ptr_node list3 = NULL;
    list3 = append_node(make_node(1), list3);
    list3 = append_node(make_node(2), list3);
    list3 = append_node(make_node(2), list3);
    list3 = append_node(make_node(2), list3);
    list3 = append_node(make_node(3), list3);

    print_list(deleteDuplicates(list3));

    return EXIT_SUCCESS;
}