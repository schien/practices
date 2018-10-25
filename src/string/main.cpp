#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: a str1 str2\n"
            << "       s str1 str2\n"
            << "       g n str_1 ... str_n\n"
            << "       r str1\n"
            << "       d str1\n"
            << "       b str n word_1 ... word_n\n"
            << "       w str1\n"
            << "       p str1\n"
            << "       e n str_1 ... str_n\n"
            << "       c str1\n"
            << "       l str1\n"
            << "       j str1 str2\n"
            << "       m str n word_1 ... word_n\n"
            << "       C str1\n"
            << "       R str1\n"
            << "       i str1\n"
            << "       P str1\n"
            << "       D str1 str2\n"
            << "       B str1 str2\n"
            << "       L str1\n"
            << "       k str n word_1 ... word_n\n"
            << std::flush;
}

void runAnagram() {
  string s = next<string>(), t = next<string>();

  Solution solution;
  std::cout << "isAnagram: " << solution.isAnagram(s, t) << std::endl;
}

void runStrStr() {
  string s = next<string>(), t = next<string>();

  Solution solution;
  std::cout << "strStr: " << solution.strStr(s, t) << std::endl;
}

void runGroupAnagram() {
  std::vector<string> strs = next_vector<string>();
  Solution solution;
  auto output = solution.groupAnagrams(strs);
  for (auto& vec: output) {
    for (auto& s:vec) {
      std::cout << s << ' ';
    }
    std::cout << '\n';
  }
}

void runRomanToInt() {
  string s = next<string>();

  Solution solution;
  std::cout << solution.romanToInt(s) << std::endl;
}

void runLetterCombinations() {
  string s = next<string>();

  Solution solution;
  auto output = solution.letterCombinations(s);

  for (auto s : output) {
    std::cout << s << std::endl;
  }
}

void runWordBreak() {
  string s = next<string>();
  vector<string> wordDict = next_vector<string>();

  Solution solution;
  auto output = solution.wordBreak(s, wordDict);
  std::cout << std::boolalpha << output << std::endl;
}

void runDecodeWays() {
  string s = next<string>();
  Solution solution;
  auto output = solution.numDecodings(s);
  std::cout << output << std::endl;
}

void runPalindromePartition() {
  string s = next<string>();
  Solution solution;
  auto output = solution.partition(s);
  for (auto& vec: output) {
    for (auto& s: vec) {
      std::cout << s << ' ';
    }
    std::cout << std::endl;
  }
}

void runEvaluateReversePolishNotation() {
  vector<string> input = next_vector<string>();
  Solution solution;
  auto output = solution.evalRPN(input);
  std::cout << output << std::endl;
}

void runCalculator() {
  string input = next<string>();
  Solution solution;
  auto output = solution.calculate(input);
  std::cout << output << std::endl;
}

void runToLowerCase() {
  string input = next<string>();
  Solution solution;
  auto output = solution.toLowerCase(input);
  std::cout << output << std::endl;
}

void runJewelsAndStones() {
  string jewels = next<string>();
  string stones = next<string>();
  Solution solution;
  auto output = solution.numJewelsInStones(jewels, stones);
  std::cout << output << std::endl;
}

void runUniqueMorseCodes() {
  std::vector<std::string> words = next_vector<std::string>();
  Solution solution;
  auto output = solution.uniqueMorseRepresentations(words);
  std::cout << output << std::endl;
}

void runLetterCasePermutation() {
  Solution solution;
  auto output = solution.letterCasePermutation(next<std::string>());
  for (auto& s : output) {
    std::cout << s << '\n';
  }
  std::cout << std::flush;
}

void runReturnToOrigin() {
  std::string moves = next<string>();
  Solution solution;
  std::cout << solution.judgeCircle(moves) << std::endl;
}

void runValidIPAddress() {
  Solution solution;
  std::cout << solution.validIPAddress(next<std::string>()) << std::endl;
}

void runValidPalindrome() {
  Solution solution;
  std::cout << std::boolalpha << solution.validPalindrome(next<std::string>()) << std::endl;
}

void runFindDifference() {
  Solution solution;
  std::cout << solution.findTheDifference(next<std::string>(), next<std::string>()) << std::endl;
}

void runBuddyString() {
  Solution solution;
  std::cout << std::boolalpha << solution.buddyStrings(next<std::string>(), next<std::string>()) << std::endl;
}

void runReverseOnlyLetters() {
  Solution solution;
  std::cout << solution.reverseOnlyLetters(next<std::string>()) << std::endl;
}

void runKeyboardRow() {
  std::vector<std::string> words = next_vector<std::string>();
  Solution solution;
  auto output = solution.findWords(words);
  for (auto& s : output) {
    std::cout << s << ' ';
  }
  std::cout << std::endl;
}

int main() {
  char op;
  std::cin >> op;

  switch(op) {
    case 'a':
      runAnagram();
      break;
    case 's':
      runStrStr();
      break;
    case 'g':
      runGroupAnagram();
      break;
    case 'r':
      runRomanToInt();
      break;
    case 'd':
      runLetterCombinations();
      break;
    case 'b':
      runWordBreak();
      break;
    case 'w':
      runDecodeWays();
      break;
    case 'p':
      runPalindromePartition();
      break;
    case 'e':
      runEvaluateReversePolishNotation();
      break;
    case 'c':
      runCalculator();
      break;
    case 'l':
      runToLowerCase();
      break;
    case 'j':
      runJewelsAndStones();
      break;
    case 'm':
      runUniqueMorseCodes();
      break;
    case 'C':
      runLetterCasePermutation();
      break;
    case 'R':
      runReturnToOrigin();
      break;
    case 'i':
      runValidIPAddress();
      break;
    case 'P':
      runValidPalindrome();
      break;
    case 'D':
      runFindDifference();
      break;
    case 'B':
      runBuddyString();
      break;
    case 'L':
      runReverseOnlyLetters();
      break;
    case 'k':
      runKeyboardRow();
      break;
    default:
      usage();
      break;
  }

  return 0;
}
