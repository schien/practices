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

TEST(KthSmallestTest, invalid) {
  Solution solution;
  vector<vector<int>> input{};
  EXPECT_EQ(-1, solution.kthSmallest(input, 1));

  input = {{0}};
  EXPECT_EQ(-1, solution.kthSmallest(input, 0));
  EXPECT_EQ(-1, solution.kthSmallest(input, 2));
}

TEST(KthSmallestTest, one) {
  Solution solution;
  vector<vector<int>> input{{0}};
  EXPECT_EQ(0, solution.kthSmallest(input, 1));
}

TEST(KthSmallestTest, example) {
  Solution solution;
  vector<vector<int>> input{10, vector<int>(10)};
  int v = 1;
  for (int i = 0; i < 10; ++i) {
    for (int j = i; j >= 0; --j) {
      input[i-j][j] = v++;
    }
  }
  for (int i = 1; i < 10; ++i) {
    for (int j = 0; j < 10-i; ++j) {
      input[i+j][9-j] = v++;
    }
  }

  for (int i = 1; i <= 100; ++i) {
    EXPECT_EQ(i, solution.kthSmallest(input, i));
  }

  v = 1;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      input[i][j] = v++;
    }
  }

  for (int i = 1; i <= 100; ++i) {
    EXPECT_EQ(i, solution.kthSmallest(input, i));
  }

  v = 1;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      input[j][i] = v++;
    }
  }

  for (int i = 1; i <= 100; ++i) {
    EXPECT_EQ(i, solution.kthSmallest(input, i));
  }

}

TEST(SpiralMatrixTest, empty) {
  Solution solution;

  vector<vector<int>> input{};
  EXPECT_EQ(vector<int>{}, solution.spiralOrder(input));

  input = {vector<int>{}};
  EXPECT_EQ(vector<int>{}, solution.spiralOrder(input));
}

TEST(SpiralMatrixTest, square) {
  Solution solution;

  vector<vector<int>> input{{1}};
  EXPECT_EQ(vector<int>{1}, solution.spiralOrder(input));

  input = {
    {1, 2},
    {4, 3},
  };
  EXPECT_EQ((vector<int>{1,2,3,4}), solution.spiralOrder(input));

  input = {
    {1, 2, 3},
    {8, 9, 4},
    {7, 6, 5},
  };
  EXPECT_EQ((vector<int>{1,2,3,4,5,6,7,8,9}), solution.spiralOrder(input));

  input = {
    {1, 2, 3, 4},
    {12, 13, 14, 5},
    {11, 16, 15, 6},
    {10, 9, 8, 7},
  };
  EXPECT_EQ((vector<int>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}), solution.spiralOrder(input));
}

TEST(SpiralMatrixTest, not_square) {
  Solution solution;

  vector<vector<int>> input = {
    {1, 2},
    {6, 3},
    {5, 4},
  };
  EXPECT_EQ((vector<int>{1,2,3,4,5,6}), solution.spiralOrder(input));

  input = {
    {1, 2, 3},
    {6, 5, 4},
  };
  EXPECT_EQ((vector<int>{1,2,3,4,5,6}), solution.spiralOrder(input));

  input = {
    {1, 2, 3, 4},
    {10, 11, 12, 5},
    {9, 8, 7, 6},
  };
  EXPECT_EQ((vector<int>{1,2,3,4,5,6,7,8,9,10,11,12}), solution.spiralOrder(input));

  input = {
    {1, 2, 3},
    {10, 11, 4},
    {9, 12, 5},
    {8, 7, 6},
  };
  EXPECT_EQ((vector<int>{1,2,3,4,5,6,7,8,9,10,11,12}), solution.spiralOrder(input));
}

TEST(NumIslandsTest, empty) {
  Solution solution;

  vector<vector<char>> input{};
  EXPECT_EQ(0, solution.numIslands(input));
  input = {{}};
  EXPECT_EQ(0, solution.numIslands(input));
}

TEST(NumIslandsTest, one_dimension) {
  Solution solution;

  vector<vector<char>> input{ {'0', '0', '0'} };
  for (int i = 0; i < 8; ++i) {
    input[0][0] = '0' + (i&1?1:0);
    input[0][1] = '0' + (i&2?1:0);
    input[0][2] = '0' + (i&4?1:0);

    int expected = (i&2) ? 1 : ((i&1) + (i>>2));
    EXPECT_EQ(expected, solution.numIslands(input));
  }

  input = {
    {'0'},
    {'0'},
    {'0'},
  };
  for (int i = 0; i < 8; ++i) {
    input[0][0] = '0' + (i&1?1:0);
    input[1][0] = '0' + (i&2?1:0);
    input[2][0] = '0' + (i&4?1:0);

    int expected = (i&2) ? 1 : ((i&1) + (i>>2));
    EXPECT_EQ(expected, solution.numIslands(input));
  }
}

TEST(NumIslandsTest, two_dimension) {
  Solution solution;

  vector<vector<char>> input{
    {'1', '0', '1'},
    {'0', '1', '0'},
    {'1', '0', '1'},
  };
  EXPECT_EQ(5, solution.numIslands(input));

  input = {
    {'0', '1', '0'},
    {'1', '0', '1'},
    {'0', '1', '0'},
  };
  EXPECT_EQ(4, solution.numIslands(input));

  input = {
    {'1', '1', '1'},
    {'1', '0', '1'},
    {'1', '1', '1'},
  };

  for (int i = 0; i < 8; ++i) {
    input[i/3][i%3] = '0';
    EXPECT_EQ(1, solution.numIslands(input));
    if (i != 4) {
      input[i/3][i%3] = '1';
    }
  }

  input = {
    {'1', '1', '1'},
    {'1', '0', '0'},
    {'1', '0', '0'},
  };
  EXPECT_EQ(1, solution.numIslands(input));

  swap(input[0][0], input[1][1]);
  EXPECT_EQ(1, solution.numIslands(input));

  swap(input[0][1], input[1][2]);
  EXPECT_EQ(1, solution.numIslands(input));

  swap(input[1][0], input[2][1]);
  EXPECT_EQ(1, solution.numIslands(input));

  swap(input[1][1], input[2][2]);
  EXPECT_EQ(1, solution.numIslands(input));

  swap(input[0][1], input[1][2]);
  swap(input[1][1], input[2][2]);
  EXPECT_EQ(1, solution.numIslands(input));
}

TEST(MaxAreaOfIslandTest, empty) {
  Solution solution;

  vector<vector<int>> input{};
  EXPECT_EQ(0, solution.maxAreaOfIsland(input));
  input = {{}};
  EXPECT_EQ(0, solution.maxAreaOfIsland(input));
}

TEST(MaxAreaOfIslandTest, one_dimension) {
  Solution solution;

  vector<vector<int>> input{ {0, 0, 0} };
  for (int i = 0; i < 8; ++i) {
    input[0][0] = (i&1?1:0);
    input[0][1] = (i&2?1:0);
    input[0][2] = (i&4?1:0);

    int expected = (i&2) ? (1+(i&1) + (i>>2)) : ((i&1)|(i>>2));
    EXPECT_EQ(expected, solution.maxAreaOfIsland(input));
  }

  input = {
    {0},
    {0},
    {0},
  };
  for (int i = 0; i < 8; ++i) {
    input[0][0] = (i&1?1:0);
    input[1][0] = (i&2?1:0);
    input[2][0] = (i&4?1:0);

    int expected = (i&2) ? (1+(i&1) + (i>>2)) : ((i&1)|(i>>2));
    EXPECT_EQ(expected, solution.maxAreaOfIsland(input));
  }
}

TEST(MaxAreaOfIslandTest, two_dimension) {
  Solution solution;

  vector<vector<int>> input{
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1},
  };
  EXPECT_EQ(1, solution.maxAreaOfIsland(input));
  for (int i = 1; i < 9; i+=2) {
    for (int j = 0; j < 9; ++j) {
      if (!(j&1)) {
        input[j/3][j%3] = 1;
      }
    }
    input[i/3][i%3] = 1;
    EXPECT_EQ(4, solution.maxAreaOfIsland(input));
  }

  input = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0},
  };
  EXPECT_EQ(1, solution.maxAreaOfIsland(input));
  for (int i = 0; i < 9; i+=2) {
    for (int j = 0; j < 9; ++j) {
      if (j&1) {
        input[j/3][j%3] = 1;
      }
    }
    input[i/3][i%3] = 1;
    EXPECT_EQ((i==4?5:3), solution.maxAreaOfIsland(input));
  }


  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (j!=4) {
        input[j/3][j%3] = 1;
      }
    }
    input[i/3][i%3] = 0;
    EXPECT_EQ((i==4?8:7), solution.maxAreaOfIsland(input));
  }

  input = {
    {1, 1, 1},
    {1, 0, 0},
    {1, 0, 0},
  };
  EXPECT_EQ(5, solution.maxAreaOfIsland(input));

  input = {
    {0, 1, 1},
    {1, 1, 0},
    {1, 0, 0},
  };
  EXPECT_EQ(5, solution.maxAreaOfIsland(input));

  input = {
    {0, 0, 1},
    {1, 1, 1},
    {1, 0, 0},
  };
  EXPECT_EQ(5, solution.maxAreaOfIsland(input));

  input = {
    {0, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
  };
  EXPECT_EQ(5, solution.maxAreaOfIsland(input));

  input = {
    {0, 0, 1},
    {0, 0, 1},
    {1, 1, 1},
  };
  EXPECT_EQ(5, solution.maxAreaOfIsland(input));

  input = {
    {0, 1, 1},
    {0, 1, 0},
    {1, 1, 0},
  };
  EXPECT_EQ(5, solution.maxAreaOfIsland(input));
}

TEST(WordSearchTest, invalid) {
  Solution solution;
  vector<vector<char>> input{};
  EXPECT_FALSE(solution.exist(input, "test"));

  input = {{}};
  EXPECT_FALSE(solution.exist(input, "test"));

  input = {{'a'}};
  EXPECT_FALSE(solution.exist(input, ""));
  EXPECT_FALSE(solution.exist(input, "aa"));

  input = {
    {'a', 'a'},
    {'a', 'a'},
  };
  EXPECT_FALSE(solution.exist(input, "aaaaa"));
}

TEST(WordSearchTest, one_dimension) {
  Solution solution;
  vector<vector<char>> input{{}};
  for (int i = 0; i < 10; ++i) {
    for (int j = i; j > 0; --j) {
      input[0].push_back('A');
    }
    input[0].push_back('B');
  }

  for (int i = 0; i < 10; ++i) {
    string word(i+1, 'A');
    if (i != 9) {
      EXPECT_TRUE(solution.exist(input, word));
    } else {
      EXPECT_FALSE(solution.exist(input, word));
    }
  }

  input = {};
  for (int i = 0; i < 10; ++i) {
    for (int j = i; j > 0; --j) {
      input.push_back({'A'});
    }
    input.push_back({'B'});
  }

  for (int i = 0; i < 10; ++i) {
    string word(i+1, 'A');
    if (i != 9) {
      EXPECT_TRUE(solution.exist(input, word));
    } else {
      EXPECT_FALSE(solution.exist(input, word));
    }
  }
}

TEST(WordSearchTest, two_dimension) {
  Solution solution;
  vector<vector<char>> input;

  input = {
    {'A', 'A', 'A'},
    {'A', 'A', 'A'},
    {'A', 'A', 'A'},
  };

  for (int t = 0; t < 9; ++t) {
    input[t/3][t%3] = 'B';
    for (int i = 1; i <= 9; ++i) {
      string word(i, 'A');
      if (i < 9 && !(i==8 && (t&1))) {
        EXPECT_TRUE(solution.exist(input, word));
      } else {
        EXPECT_FALSE(solution.exist(input, word));
      }
    }
    input[t/3][t%3] = 'A';
  }

  input = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
  };

  vector<string> words {
    "ABCFEDGHI",
    "CBADEFIHG",
    "ABCFIHGDE",
    "CBADGHIFE",
    "ABCFIHEDG",
    "CBADGHEFI",
  };

  for (auto& word:words) {
    EXPECT_TRUE(solution.exist(input, word));
  }

  reverse(input.begin(), input.end());
  for (auto& word:words) {
    EXPECT_TRUE(solution.exist(input, word));
  }

  for (auto& row:input) {
    reverse(row.begin(), row.end());
  }
  for (auto& word:words) {
    EXPECT_TRUE(solution.exist(input, word));
  }

  reverse(input.begin(), input.end());
  for (auto& word:words) {
    EXPECT_TRUE(solution.exist(input, word));
  }

}

TEST(SetZerosTest, empty) {
  Solution solution;
  vector<vector<int>> input{};
  EXPECT_NO_THROW(solution.setZeroes(input));
  input = {{}};
  EXPECT_NO_THROW(solution.setZeroes(input));
}

TEST(SetZerosTest, one_dimension) {
  Solution solution;
  vector<vector<int>> input{
    vector<int>(10, 1)
  };
  solution.setZeroes(input);
  EXPECT_EQ(vector<vector<int>>{vector<int>(10, 1)}, input);

  for (int i = 0; i < (1<<10)-1; ++i) {
    for (int j = 0; j < 10; ++j) {
      input[0][j] = (i>>j)&1;
    }
    solution.setZeroes(input);
    EXPECT_EQ(vector<vector<int>>{vector<int>(10, 0)}, input);
  }

  input = vector<vector<int>>(10, {1});
  solution.setZeroes(input);
  EXPECT_EQ(vector<vector<int>>(10, {1}), input);

  for (int i = 0; i < (1<<10)-1; ++i) {
    for (int j = 0; j < 10; ++j) {
      input[j][0] = (i>>j)&1;
    }
    solution.setZeroes(input);
    EXPECT_EQ(vector<vector<int>>(10, {0}), input);
  }
}

TEST(SetZerosTest, two_dimension) {
  Solution solution;
  vector<vector<int>> input(10, vector<int>(10, 1));
  solution.setZeroes(input);
  EXPECT_EQ(vector<vector<int>>(10, vector<int>(10, 1)), input);

  for (int i = 0; i < 100; ++i) {
    for (int j = i+1; j < 100; ++j) {
      input[i/10][i%10] = 0;
      input[j/10][j%10] = 0;

      solution.setZeroes(input);
      for (int x = 0; x < 100; ++x) {
        if (x/10 == i/10 || x/10 == j/10 || x%10 == i%10 || x%10 == j%10) {
          EXPECT_EQ(0, input[x/10][x%10]);
        } else {
          EXPECT_EQ(1, input[x/10][x%10]);
        }
      }
      for (auto& vec:input) {
        fill(vec.begin(), vec.end(), 1);
      }
    }
  }
}

TEST(SurroundingRegionsTest, empty) {
  Solution solution;
  vector<vector<char>> input{};
  EXPECT_NO_THROW(solution.solve(input));
  input = {{}};
  EXPECT_NO_THROW(solution.solve(input));
}

TEST(SurroundingRegionsTest, one_dimension) {
  Solution solution;
  vector<vector<char>> input{{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};

  for (int i = 0; i < (1<<10); ++i) {
    vector<char> expected;
    for (int j = 0; j < 10; ++j) {
      input[0][j] = (j&(1<<j))?'O':'X';
      expected.push_back(input[0][j]);
    }
    solution.solve(input);
    EXPECT_EQ(expected, input[0]);
  }

  input = {
    {'X'},
    {'X'},
    {'X'},
    {'X'},
    {'X'},
    {'X'},
    {'X'},
    {'X'},
    {'X'},
    {'X'},
  };

  for (int i = 0; i < (1<<10); ++i) {
    vector<vector<char>> expected;
    for (int j = 0; j < 10; ++j) {
      input[j][0] = (j&(1<<j))?'O':'X';
      expected.push_back(input[j]);
    }
    solution.solve(input);
    EXPECT_EQ(expected, input);
  }
}

TEST(SurroundingRegionsTest, two_dimension) {
  Solution solution;
  vector<vector<char>> input = {
    {'X','X','X'},
    {'X','X','X'},
    {'X','X','X'},
  };

  for (int i = 0; i < 9; ++i) {
    input[i/3][i%3] = 'O';
    solution.solve(input);

    vector<vector<char>> expected = {
      {'X','X','X'},
      {'X','X','X'},
      {'X','X','X'},
    };
    if (i != 4) {
      expected[i/3][i%3] = 'O';
    }
    EXPECT_EQ(expected, input);
    input[i/3][i%3] = 'X';
  }

  input = {
    {'X','X','X'},
    {'X','O','X'},
    {'X','X','X'},
  };

  for (int i = 0; i < 9; ++i) {
    if (i == 4) { continue; }
    input[i/3][i%3] = 'O';
    solution.solve(input);

    vector<vector<char>> expected = {
      {'X','X','X'},
      {'X','X','X'},
      {'X','X','X'},
    };
    expected[i/3][i%3] = 'O';
    expected[1][1] = (i&1)?'O':'X';

    EXPECT_EQ(expected, input);
    input[i/3][i%3] = 'X';
    input[1][1] = 'O';
  }

  input = {
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
  };

  solution.solve(input);

  vector<vector<char>> expected = {
    {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
    {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
    {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
    {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
  };
  EXPECT_EQ(expected, input);
}

}
