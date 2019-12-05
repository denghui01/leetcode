#ifndef ARRAY_H
#define ARRAY_H
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include "link_list.h"
using namespace std;
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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);
int* nextLargerNodes(struct ListNode* head, int* returnSize);

int minTimeToVisitAllPoints(vector<vector<int>>& points);
int oddCells(int n, int m, vector<vector<int>>& indices);
vector<int> sortArrayByParity(vector<int>& A);
vector<int> sortedSquares(vector<int>& A);
vector<int> twoSum(vector<int>& nums, int target);
vector<int> diStringMatch(string S);
class CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
  int f(int x, int y){return x + y;}
};
vector<vector<int>> findSolution(CustomFunction& customfunction, int z);
int reverse(int x);
string convertToTitle(int n);
int countPrimes(int n);
int mySqrt(int x);
bool judgeSquareSum(int c);
bool hasGroupsSizeX(vector<int>& deck);
vector<int> pathInZigZagTree(int label);
string complexNumberMultiply(string a, string b);
#endif


