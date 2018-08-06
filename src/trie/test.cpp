#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(TrieTest, empty) {
  Trie trie;
  EXPECT_FALSE(trie.search(""));
  EXPECT_TRUE(trie.startsWith(""));
  trie.insert("");
  EXPECT_TRUE(trie.search(""));
}

TEST(TrieTest, simple) {
  Trie trie;
  trie.insert("a");
  trie.insert("aa");
  trie.insert("bc");

  EXPECT_TRUE(trie.search("a"));
  EXPECT_TRUE(trie.search("aa"));
  EXPECT_TRUE(trie.search("bc"));
  EXPECT_FALSE(trie.search("b"));
  EXPECT_FALSE(trie.search("c"));
  EXPECT_FALSE(trie.search("ab"));
  EXPECT_FALSE(trie.search("bd"));
  EXPECT_FALSE(trie.search("aaa"));

  EXPECT_TRUE(trie.startsWith("a"));
  EXPECT_TRUE(trie.startsWith("aa"));
  EXPECT_TRUE(trie.startsWith("b"));
  EXPECT_TRUE(trie.startsWith("bc"));
  EXPECT_FALSE(trie.startsWith("c"));
  EXPECT_FALSE(trie.startsWith("d"));
  EXPECT_FALSE(trie.startsWith("ab"));
  EXPECT_FALSE(trie.startsWith("bd"));
  EXPECT_FALSE(trie.startsWith("aaa"));
}

}
