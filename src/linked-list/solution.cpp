// https://leetcode.com/problems/reverse-linked-list/
// https://leetcode.com/problems/delete-node-in-a-linked-list/

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
  void deleteNode(ListNode* node) {
    if (!node) {
      return;
    }
    ListNode* next = node->next;
    if (!next) {
      return;
    }
    swap(node->val, next->val);
    node->next = next->next;
    next->next = nullptr;
  }
  static inline void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
};
