#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(ReverseListTest, one_element) {
  const int val = 1;

  ListNode head(val);
  Solution solution;
  auto output = solution.reverseList(&head);

  EXPECT_EQ(val, output->val);
  EXPECT_EQ(nullptr, output->next);
}

TEST(ReverseListTest, empty_list) {
  Solution solution;
  auto output = solution.reverseList(nullptr);
  EXPECT_EQ(nullptr, output);
}

TEST(ReverseListTest, multi_elements) {
  ListNode nodes[5] = {
    ListNode(1),
    ListNode(2),
    ListNode(3),
    ListNode(4),
    ListNode(5)
  };

  for (int i = 0; i < 4; ++i) {
    nodes[i].next = &nodes[i+1];
  }

  Solution solution;
  auto output = solution.reverseList(&nodes[0]);

  ListNode* current = output;
  for (int i = 5; i > 0; --i) {
    EXPECT_NE(nullptr, current);
    EXPECT_EQ(i, current->val);
    current = current->next;
  }
  EXPECT_EQ(nullptr, current);
}

TEST(DeleteNodeTest, two_elements) {
  ListNode nodes[2] = {
    ListNode(1),
    ListNode(2),
  };

  nodes[0].next = &nodes[1];

  Solution solution;
  solution.deleteNode(&nodes[0]);

  EXPECT_EQ(2, nodes[0].val);
  EXPECT_EQ(nullptr, nodes[0].next);
}

TEST(DeleteNodeTest, three_elements) {
  ListNode nodes[3] = {
    ListNode(1),
    ListNode(2),
    ListNode(3),
  };

  for (int i = 0; i < 2; ++i) {
    nodes[i].next = &nodes[i+1];
  }

  Solution solution;
  solution.deleteNode(&nodes[1]);

  int expected_vals[2] = {
    1, 3
  };
  ListNode* current = &nodes[0];
  for (int i = 0; i < 2; ++i) {
    EXPECT_NE(nullptr, current);
    EXPECT_EQ(expected_vals[i], current->val);
    current = current->next;
  }
  EXPECT_EQ(nullptr, current);
}

TEST(DeleteNodeTest, multi_elements) {
  ListNode nodes[5] = {
    ListNode(1),
    ListNode(2),
    ListNode(3),
    ListNode(4),
    ListNode(5)
  };

  for (int i = 0; i < 4; ++i) {
    nodes[i].next = &nodes[i+1];
  }

  Solution solution;
  solution.deleteNode(&nodes[1]);

  int expected_vals[4] = {
    1, 3, 4, 5
  };
  ListNode* current = &nodes[0];
  for (int i = 0; i < 4; ++i) {
    EXPECT_NE(nullptr, current);
    EXPECT_EQ(expected_vals[i], current->val);
    current = current->next;
  }
  EXPECT_EQ(nullptr, current);
}
}
