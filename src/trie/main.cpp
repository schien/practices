#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  Trie trie;

  char op;
  while (true) {
    std::cin >> op;
    if (std::cin.eof()) {
      break;
    }

    switch (op) {
      case 'i':
        trie.insert(next<string>());
        break;
      case 's':
        std::cout << std::boolalpha << trie.search(next<string>()) << '\n';
        break;
      case 'p':
        std::cout << std::boolalpha << trie.startsWith(next<string>()) << '\n';
        break;
    }
  }
  return 0;
}
