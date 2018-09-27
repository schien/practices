#include <iostream>
#include <vector>

#include "solution.cpp"

std::vector<ListNode> next_list() {
  uint32_t n;
  std::cin >> n;

  std::vector<ListNode> nodes;
  for (uint32_t i = 0; i < n; ++i) {
    int val;
    std::cin >> val;

    nodes.emplace_back(val);
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      nodes[i-1].next = &nodes[i];
    }
  }

  return nodes;
}

std::vector<RandomListNode> next_random_list() {
  uint32_t n;
  std::cin >> n;

  std::vector<RandomListNode> nodes;
  for (uint32_t i = 0; i < n; ++i) {
    int val;
    std::cin >> val;

    nodes.emplace_back(val);
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      nodes[i-1].next = &nodes[i];
    }
    int random;
    std::cin >> random;

    nodes[i].random = (random>=0&&random<n)?&nodes[random]:nullptr;
  }

  return nodes;
}

void printList(ListNode* head) {
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << std::endl;
}

void printRandomList(RandomListNode* head) {
  while (head) {
    std::cout << '@' << '[' << std::hex << head << ']'
              << head->label
              << '(' << std::hex << head->random << ')'
              << '\n';
    head = head->next;
  }
  std::cout << std::endl;
}

void runReverseList() {
  std::vector<ListNode> nodes = next_list();
  Solution solution;
  auto output = solution.reverseList(&nodes[0]);

  printList(output);
}

void runDeleteNode() {
  std::vector<ListNode> nodes = next_list();
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

void runSortList() {
  std::vector<ListNode> nodes = next_list();
  Solution solution;
  auto output = solution.sortList(&nodes[0]);

  printList(output);
}

void runPalindrome() {
  std::vector<ListNode> nodes = next_list();
  Solution solution;
  auto output = solution.isPalindrome(&nodes[0]);

  std::cout << output << std::endl;
}

void runOddEvenList() {
  std::vector<ListNode> nodes = next_list();
  Solution solution;
  auto output = solution.oddEvenList(&nodes[0]);
  printList(output);
}

void runCopyRandomList() {
  std::vector<RandomListNode> nodes = next_random_list();
  Solution solution;
  auto output = solution.copyRandomList(&nodes[0]);
  printRandomList(output);
}

void runMyLinkedList() {
  MyLinkedList list;
  while (true) {
    char op;
    std::cin >> op;
    if (std::cin.eof()) {
      break;
    }

    switch (op) {
      case 'h':
      {
        int val;
        std::cin >> val;
        list.addAtHead(val);
        break;
      }
      case 't':
      {
        int val;
        std::cin >> val;
        list.addAtTail(val);
        break;
      }
      case 'i':
      {
        int idx, val;
        std::cin >> idx >> val;
        list.addAtIndex(idx, val);
        break;
      }
      case 'd':
      {
        int idx;
        std::cin >> idx;
        list.deleteAtIndex(idx);
        break;
      }
      case 'p':
        list.print(std::cout);
        break;
      default:
        break;
    }
  }
}

void runRemoveElements() {
  std::vector<ListNode> nodes = next_list();
  int val;
  std::cin >> val;
  Solution solution;

  auto output = solution.removeElements(&nodes[0], val);
  printList(output);
}

void usage() {
  std::cerr << "usage: r N v[1] ... v[N]\n"
            << "       d N v[1] ... v[N] v[x] (where x < N)\n"
            << "       p N v[1] ... v[N]\n"
            << "       s N v[1] ... v[N]\n"
            << "       o N v[1] ... v[N]\n"
            << "       c N v[1] ... v[N] r[1] ... r[N] (where -1 == nullptr)\n"
            << "       l (h v)|(t v)|(i idx v)|(d idx v)|(p)\n"
            << "       R N v[1] ... v[N] k\n"
            << std::flush;
}

int main() {
  char op;
  std::cin >> op;

  switch (op) {
    case 'r':
      runReverseList();
      break;
    case 'd':
      runDeleteNode();
      break;
    case 'p':
      runPalindrome();
      break;
    case 's':
      runSortList();
      break;
    case 'o':
      runOddEvenList();
      break;
    case 'c':
      runCopyRandomList();
      break;
    case 'l':
      runMyLinkedList();
      break;
    case 'R':
      runRemoveElements();
      break;
    default:
      usage();
  }

  return 0;
}
