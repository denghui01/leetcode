#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "solution.h"

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
    ptr_node node2 = head;

    while(node2->next != NULL)
    {
        node1 = node1->next;
        node2 = node2->next->next;
        if(node1 == node2)
        {
            return true;
        }
    }
    return false;  
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

// 25. Reverse Nodes in k-Group
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(!head || k < 2) return head;

    ptr_node origin_head = head;
    int progress = 0;
    for(;;)
    {
        if(head)
        {
            head = head->next;
        } 
        else
        {
            return origin_head;
        }
        ++progress;
        if(progress % k == 0)
        {
            origin_head = reverseBetween(origin_head, progress - k + 1, progress);                    
        }
    }    
}

// 160. Intersection of Two Linked Lists
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB) return NULL;

    ptr_node tailB = list_tail(headB);
    tailB->next = headB;  // Loop listB

    ptr_node node1 = headA;
    ptr_node node2 = headA;

    while(node2 && node2->next)
    {
        node1 = node1->next;
        node2 = node2->next->next;
        if(node1 == node2)
        {
            break;
        }
    }

    if(!node2 || !node2->next)
    {
        return NULL;
    }

    node1 = headA;
    while(node1 != node2)
    {
        node1 = node1->next;
        node2 = node2->next; 
    }
    return node1;
}

// 1019. Next Greater Node In Linked List
typedef struct IndexNode
{
    int val;
    int index;
}IndexNode, *ptr_index;
stack<ptr_index> s;
void push_index(ptr_node node, int index, int *a)
{
    ptr_index index_node = (ptr_index)malloc(sizeof(IndexNode));
    a[index] = 0;
    index_node->val = node->val;
    index_node->index = index;
    s.push(index_node);
}

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    *returnSize = list_len(head);
    if(!(*returnSize)) return NULL;

    int i = 0;
    int *ra = (int*)malloc(sizeof(int) * (*returnSize)); // result array
    push_index(head, i++, ra);
    head = head->next;
    while(head)
    {
        while(!s.empty() && s.top()->val < head->val)
        {
            ra[s.top()->index] = head->val;
            s.pop();
        }
        push_index(head, i++, ra);
        head = head->next;
    }
    return ra;
}

// 1266. Minimum Time Visiting All Points
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int result = 0;
    for(int i = 1; i < points.size(); ++i)
    {
        result += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
    }
    return result;
}

// 1252. Cells with Odd Values in a Matrix
int oddCells(int n, int m, vector<vector<int>>& indices) {
    uint64_t nbits = 0;
    uint64_t mbits = 0;

    for(int i = 0; i < indices.size(); ++i)
    {
        nbits ^= (uint64_t)1 << indices[i][0];
        mbits ^= (uint64_t)1 << indices[i][1];
    }
    int dn = 0;
    int dm = 0;
    for(int i = 0; i < 64; ++i)
    {
        if(nbits & ((uint64_t)1 << i)) dn++;
        if(mbits & ((uint64_t)1 << i)) dm++;
    }
    return dm * n + dn * m - dn * dm * 2;           
}

// 905. Sort Array By Parity
 vector<int> sortArrayByParity(vector<int>& A)
 {
     vector<int> r(A.size());
     int even_end = 0;
     int odd_end = A.size() - 1;
     for(int i = 0; i < A.size(); ++i)
     {
         if(A[i] % 2 == 0)
         {
             r[even_end++] = A[i];
         }
         else
         {
             r[odd_end--] = A[i];
         }         
     }
     return r;
 }

 // 977. Squares of a Sorted Array
 vector<int> sortedSquares(vector<int>& A)
 {
     vector<int> r;
     return r;        
 }

 // 1. Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> r(2);
    for(int i = 0; i < nums.size() - 1; ++i)
    {
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                r[0] = i;
                r[1] = j;
                return r;
            }
        }
    }
    return r;
}

// 728. Self Dividing Numbers
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> digis(4, 0);
    vector<int> r;
    for(int i = left; i <= right; ++i)
    {

    }
    return r;
}

// 942. DI String Match 
vector<int> diStringMatch(string S) 
{
    int i_head = 0;
    int d_head = S.size();
    vector<int> r(d_head + 1);
    for(int i = 0; i < S.size(); ++i)
    {
        if(S[i] == 'I')
        {
            r[i] = i_head++;
        }
        else
        {
            r[i] = d_head--;
        }        
    }
    r[S.size()] = i_head; 
    return r;   
}

// 1237. Find Positive Integer Solution for a Given
class CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
  int f(int x, int y){return x + y;}
};

vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
{
    int i = 1;
    int j = 1;
    vector<vector<int>> r;
    for(int i = 1;;++i)
    {
        for(int j = 1;;++j)
        {
            if(customfunction.f(i, j) == z)
            {
                r.push_back(vector<int>{i, j});
                break;
            }
        }
    }
}