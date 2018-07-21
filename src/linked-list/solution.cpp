// https://leetcode.com/problems/reverse-linked-list/
// https://leetcode.com/problems/delete-node-in-a-linked-list/
// https://leetcode.com/problems/palindrome-linked-list/
// https://leetcode.com/problems/sort-list/
// https://leetcode.com/problems/odd-even-linked-list/

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

ListNode* insertion_sort(ListNode* head) {
  if (!head) {
    return nullptr;
  }

  ListNode* result = head;
  head = head->next;
  result->next = nullptr;

  while (head) {
    const int h_v = head->val;
    ListNode** prev = &result;
    ListNode* curr = result;
    while (curr && h_v > curr->val) {
      prev = &curr->next;
      curr = curr->next;
    }
    auto tmp = head->next;
    head->next = curr;
    *prev = head;
    head = tmp;
  }
  return result;
}

ListNode* quick_sort(ListNode* head) {
  if (!head) {
    return nullptr;
  }
  ListNode* pivot = head;
  ListNode* l = nullptr;
  ListNode* h = nullptr;

  ListNode* curr = head->next;
  const int p_v = pivot->val;
  while (curr) {
    ListNode** n = (p_v>curr->val) ? &l : &h;
    auto tmp = curr->next;
    curr->next = *n;
    *n = curr;
    curr = tmp;
  }

  pivot->next = quick_sort(h);
  if (!l) {
    return pivot;
  }

  l = quick_sort(l);
  curr = l;
  while(curr->next) {
    curr = curr->next;
  }
  curr->next = pivot;
  return l;
}

ListNode* merge_sort(ListNode* head) {
  if (!head) {
    return nullptr;
  }
  // split
  ListNode* split = head->next;
  ListNode* curr = head;
  while (curr) {
    auto next = curr->next;
    if (next) {
      curr->next = next->next;
    }
    curr = next;
  }

  if (!split) {
    return head;
  }

  ListNode* a = merge_sort(head);
  ListNode* b = merge_sort(split);

  // merge
  static auto merge = [](ListNode* a, ListNode* b) {
    ListNode head(0);
    ListNode* tail = &head;
    while (a && b) {
      if (a->val < b->val) {
        tail->next = a;
        a = a->next;
      } else {
        tail->next = b;
        b = b->next;
      }
      tail = tail->next;
    }
    if (a) {
      tail->next = a;
    }
    if (b) {
      tail->next = b;
    }
    return head.next;
  };
  return merge(a, b);
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
  ListNode* sortList(ListNode* head) {
    return merge_sort(head);
    //return insertion_sort(head);
    //return quick_sort(head);
  }
  ListNode* oddEvenList(ListNode* head) {
    if (!head) {
      return nullptr;
    }

    auto curr = head;
    auto odd = head->next;
    bool is_even = true;
    ListNode* even_tail = nullptr;
    while (curr) {
      auto next = curr->next;
      if (next) {
        curr->next = next->next;
      }
      if (is_even && !curr->next) {
        even_tail = curr;
      }
      curr = next;
      is_even = !is_even;
    }

    even_tail->next = odd;

    return head;
  }
};
