#include <iostream>
#include <vector>

#include "solution.cpp"

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

  Solution solution;
  auto output = solution.reverseList(&nodes[0]);

  ListNode* current = output;
  while (current) {
    std::cout << current->val << ' ';
    current = current->next;
  }
  std::cout << std::endl;

  return 0;
}
