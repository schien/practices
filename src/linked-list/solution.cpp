// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* newHead = nullptr;
    while (head != nullptr) {
      ListNode* next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
    }
    return newHead;
  }
};
