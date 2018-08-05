#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  Solution solution;

  std::string beginWord = next<std::string>();
  std::string endWord = next<std::string>();

  std::vector<std::string> wordList = next_vector<std::string>();

  auto output = solution.ladderLength(beginWord, endWord, wordList);
  std::cout << output << std::endl;

  return 0;
}
