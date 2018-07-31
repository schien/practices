#include "gtest/gtest.h"

#include "solution.cpp"

namespace {

TEST(RotateTest, one) {
  Solution solution;

  vector<vector<int>> input {
    {1}
  };

  solution.rotate(input);
  EXPECT_EQ(vector<vector<int>>{{1}}, input);
}

TEST(RotateTest, small) {
  Solution solution;

  vector<vector<int>> input {
    {1, 2},
    {3, 4},
  }, expected {
    {3, 1},
    {4, 2}
  };

  solution.rotate(input);
  EXPECT_EQ(expected, input);

  input = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  expected  = {
    {7, 4, 1},
    {8, 5, 2},
    {9, 6, 3}
  };

  solution.rotate(input);
  EXPECT_EQ(expected, input);
}

TEST(RotateTest, large) {
  Solution solution;

  vector<vector<int>> input(1000, vector<int>(1000)), expected(1000, vector<int>(1000));
  for (int i = 0; i < 1000; ++i) {
    fill_n(input[i].begin(), 1000, i);
    expected[0][i] = 999 - i ;
  }
  for (int i = 1; i < 1000; ++i) {
    copy_n(expected[0].begin(), 1000, expected[i].begin());
  }
  solution.rotate(input);
  EXPECT_EQ(expected, input);
}

TEST(SearchMatrixTest, one) {
  Solution solution;

  vector<vector<int>> input {
    {1}
  };

  EXPECT_TRUE(solution.searchMatrix(input, 1));
  EXPECT_FALSE(solution.searchMatrix(input, 0));
  EXPECT_FALSE(solution.searchMatrix(input, 2));
}

TEST(SearchMatrixTest, one_dimension) {
  Solution solution;

  vector<vector<int>> input {
    {1, 3, 5, 7, 9}
  };

  for (int i = 0; i <= 10; ++i) {
    if (i&1) {
      EXPECT_TRUE(solution.searchMatrix(input, i));
    } else {
      EXPECT_FALSE(solution.searchMatrix(input, i));
    }
  }

  input = {
    {1},
    {3},
    {5},
    {7},
    {9}
  };

  for (int i = 0; i <= 10; ++i) {
    if (i&1) {
      EXPECT_TRUE(solution.searchMatrix(input, i));
    } else {
      EXPECT_FALSE(solution.searchMatrix(input, i));
    }
  }
}

TEST(SearchMatrixTest, large) {
  Solution solution;

  vector<vector<int>> input(500, vector<int>(500));
  int n = 1;
  for (int i = 0; i < 500; ++i) {
    for (int j = 0; j < 500; ++j) {
      input[i][j] = n;
      n += 2;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i&1) {
      EXPECT_TRUE(solution.searchMatrix(input, i));
    } else {
      EXPECT_FALSE(solution.searchMatrix(input, i));
    }
  }

  for (int i = 0; i < 500; ++i) {
    for (int j = i+1; j < 500; ++j) {
      swap(input[i][j], input[j][i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i&1) {
      EXPECT_TRUE(solution.searchMatrix(input, i));
    } else {
      EXPECT_FALSE(solution.searchMatrix(input, i));
    }
  }

}

TEST(GameOfLifeTest, under_population) {
  Solution solution;

  for (int i = 0; i < 2; ++i) {
    vector<vector<int>> input = {
      {i}
    };

    solution.gameOfLife(input);
    EXPECT_EQ(0, input[0][0]);
  }

  for (int i = 0; i < 4; ++i) {
    vector<vector<int>> input = {
      {i==0, i==1},
      {i==2, i==3},
    };

    solution.gameOfLife(input);
    EXPECT_EQ(0, input[i>>1][i&1]);
  }

  for (int i = 0; i < 9; ++i) {
    vector<vector<int>> input = {
      {i==0, i==1, i==2},
      {i==3, 1, i==4},
      {i==5, i==6, i==7},
    };

    solution.gameOfLife(input);
    EXPECT_EQ(0, input[1][1]);
  }

  for (int i = 0; i < 2; ++i) {
    vector<vector<int>> input = {
      {i==0, i==1, i==0},
      {i==1, 1, i==1},
      {i==0, i==1, i==0},
    };

    solution.gameOfLife(input);
    EXPECT_EQ(0, input[1][1]);
  }
}

TEST(GameOfLifeTest, over_population) {
  Solution solution;

  for (int i = 0; i < 9; ++i) {
    vector<vector<int>> input = {
      {i!=0, i!=1, i!=2},
      {i!=3, 1, i!=4},
      {i!=5, i!=6, i!=7},
    };

    solution.gameOfLife(input);
    EXPECT_EQ(0, input[1][1]);
  }
}

TEST(GameOfLifeTest, stable) {
  Solution solution;

  vector<vector<int>> input = {
    {1, 1},
    {1, 1},
  };

  solution.gameOfLife(input);

  for (int i = 0; i < 4; ++i) {
    EXPECT_EQ(1, input[i>>1][i&1]);
  }

  input = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0},
  };

  solution.gameOfLife(input);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ((i+j)&1, input[i][j]);
    }
  }
}

TEST(GameOfLifeTest, grow) {
  Solution solution;

  for (int i = 0; i < 4; ++i) {
    vector<vector<int>> input = {
      {i!=0, i!=1},
      {i!=2, i!=3},
    };

    solution.gameOfLife(input);
    EXPECT_EQ(1, input[i>>1][i&1]);
  }

}

}
