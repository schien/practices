// https://leetcode.com/problems/reverse-linked-list/
// https://leetcode.com/problems/delete-node-in-a-linked-list/
// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// time: O(n) + O(n)
// space: O(n)
static bool palindrome_reverse_all(ListNode* head) {
  ListNode* rvHead = nullptr;
  ListNode* current = head;
  // create a new list in reverse order
  while(current){
    ListNode* n = new ListNode(current->val);
    n->next = rvHead;
    rvHead = n;
    current = current->next;
  }

  // list comparison
  bool result = true;
  while(head) {
    result = result && (head->val == rvHead->val);

    head = head->next;

    // progressively clean up the reversed list
    auto tmp = rvHead;
    rvHead = rvHead->next;
    delete tmp;
  }
  return result;
}

// time: O(n) + O(n/2) + O(n/2)
// space: O(1)
static bool palindrome_reverse_half(ListNode* head) {
  ListNode* current = head;
  ListNode* half = head;

  // find middle node in the list
  while (current) {
    current = current->next;
    if (!current) {
      break;
    }
    current = current->next;
    half = half->next;
  }

  // reverse the second half of the list
  current = half;
  ListNode* rvHead = nullptr;
  while (current) {
    auto tmp = current->next;
    current->next = rvHead;
    rvHead = current;
    current = tmp;
  }

  // compare the first half and the second half
  bool result = true;
  while (rvHead) {
    result = result && (head->val == rvHead->val);

    head = head->next;

    // progressively restore the order of the second half
    auto tmp = rvHead->next;
    rvHead->next = current;
    current = rvHead;
    rvHead = tmp;
  }

  return result;
}

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
  bool isPalindrome(ListNode* head) {
    //return palindrome_reverse_all(head);
    return palindrome_reverse_half(head);
  }
};
