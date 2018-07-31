#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(PokerHandsTest, example) {
  Solution solution;

  vector<vector<string>> hands {
    {"KH", "JH", "9H", "7H", "5C"}, //high card
    {"KH", "JH", "9H", "7H", "6C"}, //high card
    {"KH", "JH", "9H", "8H", "5C"}, //high card
    {"KH", "JH", "TH", "7H", "5C"}, //high card
    {"KH", "QH", "9H", "7H", "5C"}, //high card

    {"KH", "KC", "9H", "7H", "5C"}, //pair
    {"KH", "KC", "9H", "7H", "6C"}, //pair
    {"KH", "KC", "9H", "8H", "5C"}, //pair
    {"KH", "KC", "TH", "7H", "5C"}, //pair
    {"AH", "AC", "9H", "7H", "5C"}, //pair

    {"KH", "KC", "9H", "9C", "5C"}, //two pairs
    {"KH", "KC", "9H", "9C", "6C"}, //two pairs
    {"KH", "KC", "TH", "TC", "5C"}, //two pairs
    {"AH", "AC", "9H", "9C", "5C"}, //two pairs

    {"KH", "KC", "KD", "7H", "5C"}, //three
    {"AH", "AC", "AD", "7H", "5C"}, //three

    {"KH", "QC", "JC", "TC", "9C"}, //straight
    {"AC", "KH", "QC", "JC", "TC"}, //straight

    {"KH", "JH", "9H", "7H", "5H"}, //flush
    {"KH", "JH", "9H", "7H", "6H"}, //flush
    {"KH", "JH", "9H", "8H", "5H"}, //flush
    {"KH", "JH", "TH", "7H", "5H"}, //flush
    {"KH", "QH", "9H", "7H", "5H"}, //flush

    {"KH", "KC", "KD", "7H", "7C"}, //full house
    {"AH", "AC", "AD", "5H", "5C"}, //full house

    {"KH", "KC", "KD", "KS", "5C"}, //four
    {"AH", "AC", "AD", "AS", "5C"}, //four

    {"KC", "QC", "JC", "TC", "9C"}, //flush straight
    {"AC", "KC", "QC", "JC", "TC"}, //flush straight

  };

  for (int i = 0; i < hands.size(); ++i) {
    EXPECT_EQ(0, solution.compare(hands[i], hands[i]));
    for (int j = i+1; j < hands.size(); ++j) {
      EXPECT_GT(0, solution.compare(hands[i], hands[j]));
    }
  }
}

}
