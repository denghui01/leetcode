#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "link_list.h"
#include "solution.h"

#define LEETCODE_206    1
#define LEETCODE_876    1
#define LEETCODE_92     1
#define LEETCODE_21     1
#define LEETCODE_83     1
#define LEETCODE_141    1
#define LEETCODE_234    1
#define LEETCODE_203    1
#define LEETCODE_25     1
#define LEETCODE_160    1
#define LEETCODE_1019   1
#define LEETCODE_1252   1
#define LEETCODE_905    1
#define LEETCODE_1      1
#define LEETCODE_942    1

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

void print_vector(vector<int> v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int input[] = {9998,9997,9996,9996};
int main()
{
    // leetcode questions
#if (LEETCODE_206)
    // 206. Reverse Linked List
    ptr_node list1 = NULL;
    for(int i = 1; i < 9; ++i)
    {
        list1 = append_node(make_node(i), list1);
    }
    // [1,2,3,4,5,6,7,8]
    print_list(list1);
    list1 = reverse(list1);
    print_list(list1);
#endif

#if (LEETCODE_876)
    // 876. Middle of the Linked List
    ptr_node list2 = NULL;
    for(int i = 1; i < 9; ++i)
    {
        list2 = append_node(make_node(i), list2);
    }
    print_list(middle_node(list2)); // [5,6,7,8]

    list2 = append_node(make_node(9), list2);  // [1,2,3,4,5,6,7,8,9]
    print_list(middle_node(list2)); //[5,6,7,8,9]
#endif

#if (LEETCODE_92)
    // 92. Reverse Linked List II
    ptr_node list3 = NULL;
    for(int i = 1; i < 9; ++i)
    {
        list3 = append_node(make_node(i), list3);
    }
    print_list(reverseBetween(list3, 3, 4));
#endif

#if (LEETCODE_21)
    // 21. Merge Two Sorted Lists
    ptr_node list5 = NULL;
    ptr_node list6 = NULL;
    list5 = append_node(make_node(1), list5);
    list5 = append_node(make_node(2), list5);
    list5 = append_node(make_node(4), list5);

    list6 = append_node(make_node(1), list6);
    list6 = append_node(make_node(3), list6);
    list6 = append_node(make_node(4), list6);    
    print_list(mergeTwoLists(list5, list6));
#endif

#if (LEETCODE_83)
    //83. Remove Duplicates from Sorted List#include <stdbool.h>
    ptr_node list7 = NULL;
    list7 = append_node(make_node(1), list7);
    list7 = append_node(make_node(2), list7);
    list7 = append_node(make_node(2), list7);
    list7 = append_node(make_node(2), list7);
    list7 = append_node(make_node(3), list7);
    print_list(deleteDuplicates(list7));
#endif

#if (LEETCODE_141)
    //141. Linked List Cycle
    ptr_node list8 = NULL;
    list8 = append_node(make_node(1), list8);
    list8 = append_node(make_node(2), list8);
    list8 = append_node(make_node(2), list8);
    list8 = append_node(make_node(3), list8);
    list8 = append_node(make_node(1), list8);
    ptr_node tail = list_tail(list8);
    tail->next = list8->next->next;
    printf("Has Cycle? %s\n", hasCycle(list8)?"Yes":"No");
#endif    

#if (LEETCODE_234)
    // 234. Palindrome Linked List
    ptr_node list9 = NULL;
    list9 = append_node(make_node(1), list9);
    list9 = append_node(make_node(2), list9);
    list9 = append_node(make_node(6), list9);
    list9 = append_node(make_node(2), list9);
    list9 = append_node(make_node(1), list9);
    printf("Palindrome? %s\n", isPalindrome(list9)?"Yes":"No");
#endif

#if (LEETCODE_203)
    // 203. Remove Linked List Elements
    ptr_node lista = NULL;
    lista = append_node(make_node(1), lista);
    lista = append_node(make_node(2), lista);
    lista = append_node(make_node(2), lista);
    lista = append_node(make_node(2), lista);
    lista = append_node(make_node(1), lista);
    print_list(removeElements(lista, 1));
    print_list(removeElements(lista, 2));
    print_list(removeElements(lista, 3));
#endif

#if (LEETCODE_25)
    //25. Reverse Nodes in k-Group
    ptr_node list15 = NULL;
    list15 = append_node(make_node(1), list15);
    list15 = append_node(make_node(2), list15);
    list15 = append_node(make_node(3), list15);
    list15 = append_node(make_node(4), list15);
    list15 = append_node(make_node(5), list15);    
    print_list(reverseKGroup(list15, 2));
#endif

#if (LEETCODE_160)
    // 160. Intersection of Two Linked Lists
    ptr_node list16 = NULL;
    list16 = append_node(make_node(1), list16);
    list16 = append_node(make_node(2), list16);
    list16 = append_node(make_node(3), list16);
    list16 = append_node(make_node(4), list16);
    list16 = append_node(make_node(5), list16);    

    ptr_node list17 = NULL;
    list17 = append_node(make_node(7), list17);
    list17 = append_node(make_node(8), list17);
    list17 = append_node(make_node(9), list17);

    tail = list_tail(list17);
    tail->next = list16->next->next->next;
    ptr_node rlist = getIntersectionNode(list16, list17);
    if(rlist == NULL)
    {
        printf("No intersection\n");
    }
    else
    {
        printf("Intersected on %d\n", rlist->val);
    }
#endif

#if (LEETCODE_1019)
    // 1019. Next Greater Node In Linked List
    ptr_node list18 = NULL;
    list18 = append_node(make_node(9), list18);
    list18 = append_node(make_node(7), list18);
    list18 = append_node(make_node(6), list18);
    list18 = append_node(make_node(7), list18);
    list18 = append_node(make_node(6), list18);
    list18 = append_node(make_node(9), list18);
    list18 = append_node(make_node(2), list18);
    list18 = append_node(make_node(1), list18);
    list18 = append_node(make_node(5), list18);
    // for(int i = 0; i < sizeof(input)/sizeof(input[0]); ++i)
    // {
    //     list18 = append_node(make_node(input[i]), list18);
    // }
    int rsize;
    int *result = nextLargerNodes(list18, &rsize);
    for(int i = 0; i < rsize; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
#endif

#if (LEETCODE_1252)
    // 1252. Cells with Odd Values in a Matrix
    vector<vector<int>> v1 = {{1,1},{0,0}};
    printf("%d\n", oddCells(2, 2, v1));
#endif

#if (LEETCODE_905)
    // 905. Sort Array By Parity
    vector<int> v2 = {1,2,3,4};
    vector<int> r2 = sortArrayByParity(v2);
    print_vector(r2);
#endif

#if (LEETCODE_1)
    //1. Two Sum
    vector<int> v3 = {1,2,3,4};
    vector<int> r3 = twoSum(v3, 7);
    print_vector(r3);
#endif

#if (LEETCODE_942)
    // 942. DI String Match 
    string s4("IDID");
    vector<int> r4 = diStringMatch(s4);
    print_vector(r4);
#endif
    return EXIT_SUCCESS;
}