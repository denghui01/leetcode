#include <cmath>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
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
vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
{
    int i = 0;
    vector<vector<int>> r;
    while(1)
    {
        ++i;
        if(customfunction.f(i, 1) > z)
        {
            return r;
        }
        int j = 0;
        while(1)
        {
            ++j;
            int m = customfunction.f(i, j);
            if(m == z)
            {
                r.push_back(vector<int>{i, j});
                break;
            }
            else if(m > z)
            {
                break;
            }
        }
    }
}

// 7. Reverse Integer
int reverse(int x) {
    int64_t r = 0;
    int64_t t = x;
    int flag = (x >= 0 ? 1 : -1);
    t *= flag;
    while(t)
    {
        if((r = r * 10 + t % 10) > INT32_MAX) return 0;
        t /= 10;
    }
    return (int)r * flag;
}

// 168. Excel Sheet Column Title
string convertToTitle(int n) {
    string s;
    stack<int> d;
    
    while(--n > 0)
    {
        d.push(n % 26);
        n /= 26;        
    }
    if(n == 0) d.push(0);    
    while(d.size())
    {
        s.push_back('A' + d.top());
        d.pop();
    }
    return s;
}

// 204. Count Primes
int countPrimes(int n) {
    vector<int> v(n);
    for(int i = 0; i < n; ++i) 
    {
        v[i] = i;
    }

    for(int i = 2; i <= (n - 1) / 2; ++i)
    {
        if(v[i] == 0) continue;
        for(int j = 2; j <= (n - 1) / i; ++j)
        {
            v[i * j] = 0;
        }
    }

    int r = 0;
    for(int i = 2; i < n; ++i)
    {
        if(v[i] != 0) ++r;
    }
    return r;
}

// 69. Sqrt(x)
int mySqrt(int x) {
    uint64_t n = x;
    uint64_t m = 1;
    while (m < n)
    {
        uint64_t mid = ((uint64_t)m + n) / 2;
        if(mid * mid > x )
        {
            n = mid - 1;
        }
        else if(mid * mid < x)
        {
            m = mid + 1;
        }
        else
        {
            return (int)mid;
        }        
    }    
    if(n * n > x) --n;
    return (int)n; 
}

// 633. Sum of Square Numbers
bool judgeSquareSum(int c)
{
    for(int m = sqrt(c); m >= 0; --m)
    {
        int left = c - m * m;
        if((int)sqrt(left) * (int)sqrt(left) == left)
        {
            cout << m << " " << sqrt(left) << endl;
            return true;
        } 
    }
    return false;
}

// 914. X of a Kind in a Deck of Cards
int gcd(int x, int y)
{
    int r = y;
    if (x == y) return x;
    else if(x < y)
    {
        r = y;
        y = x;
        x = r;
    }
    // x is bigger
    while(r != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> map;
    for(int i = 0; i < deck.size(); ++i){
        auto search = map.find(deck[i]);
        if(search != map.end())
        {
            ++search->second;
        }
        else
        {
            map.insert({deck[i], 1});
        }        
    }

    int ref = map.begin()->second;
    if(ref == 1) return false;
    for(const auto& it : map)
    {
        if(gcd(it.second, ref) < 2) return false; 
    }
    return true;    
}


// 1104. Path In Zigzag Labelled Binary Tree
int reverseOrder(int n)
{
    int t = n;
    int i = 0;
    while(t >>= 1)
    {
        ++i;
    }
    return n ^ ((1 << i) - 1); 
}
vector<int> pathInZigZagTree(int label) {
    vector<int> r;
    int flag = 1;
    while(label)
    {
        r.insert(r.begin(), flag == 1? label : reverseOrder(label));
        label >>= 1;
        flag *= -1;
    }
    return r;
}

// 537. Complex Number Multiplication
string complexNumberMultiply(string a, string b) {
    string r;
    int x1 = stoi(a);
    int x2 = stoi(b);
    int y1 = stoi(a.substr(a.find('+') + 1));
    int y2 = stoi(b.substr(b.find('+') + 1));
    r += to_string(x1 * x2 - y1 * y2);
    r.push_back('+');
    r += to_string(x1 * y2 + x2 * y1);
    r.push_back('i');
    return r;
}