#include <iostream>
#include <vector>

#include "solution.cpp"

void printList(ListNode* head) {
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << std::endl;
}

void runReverseList(std::vector<ListNode>& nodes) {
  Solution solution;
  auto output = solution.reverseList(&nodes[0]);

  printList(output);
}

void runDeleteNode(std::vector<ListNode>& nodes) {
  int deleteVal;
  std::cin >> deleteVal;

  ListNode* toBeDeleted = nullptr;
  for (int i = 0; i < nodes.size()-1; ++i) {
    if (nodes[i].val == deleteVal) {
      toBeDeleted = &nodes[i];
      break;
    }
  }

  Solution solution;
  if (toBeDeleted != nullptr) {
    solution.deleteNode(toBeDeleted);
  }

  printList(&nodes[0]);
}

void runSortList(std::vector<ListNode>& nodes) {
  Solution solution;
  auto output = solution.sortList(&nodes[0]);

  printList(output);
}

void runPalindrome(std::vector<ListNode>& nodes) {
  Solution solution;
  auto output = solution.isPalindrome(&nodes[0]);

  std::cout << output << std::endl;
}

void usage() {
  std::cerr << "N v[1] ... v[N]" << std::endl
            << "r" << std::endl
            << "d v[x] (where x < N)" << std::endl
            << "s v[1] ... v[N]" << std::endl;
}

int main() {
  uint32_t n;
  std::cin >> n;

  std::vector<ListNode> nodes;
  for (uint32_t i = 0; i < n; ++i) {
    int val;
    std::cin >> val;

    ListNode node(val);
    nodes.push_back(node);
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      nodes[i-1].next = &nodes[i];
    }
  }

  char op;
  std::cin >> op;

  switch (op) {
    case 'r':
      runReverseList(nodes);
      break;
    case 'd':
      runDeleteNode(nodes);
      break;
    case 'p':
      runPalindrome(nodes);
      break;
    case 's':
      runSortList(nodes);
      break;
    default:
      usage();
  }

  return 0;
}
