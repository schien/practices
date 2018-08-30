#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: r n [n v_1_1 ... v_1_n] ... [n v_n_1 ... v_n_n]\n"
            << "       s n [m v_1_1 ... v_1_m] ... [m v_n_1 ... v_n_m]\n"
            << "       g n [m v_1_1 ... v_1_m] ... [m v_n_1 ... v_n_m]\n"
            << "       k n [n v_1_1 ... v_1_n] ... [n v_n_1 ... v_n_n] k\n"
            << "       p n [m v_1_1 ... v_1_m] ... [m v_n_1 ... v_n_m]\n"
            << "       i n [m c_1_1 ... c_1_m] ... [m c_n_1 ... c_n_m]\n"
            << "       a n [m c_1_1 ... c_1_m] ... [m c_n_1 ... c_n_m]\n"
            << "       w n [m c_1_1 ... c_1_m] ... [m c_n_1 ... c_n_m] str\n"
            << "       z n [m v_1_1 ... v_1_m] ... [m v_n_1 ... v_n_m]\n"
            << "       d n [m c_1_1 ... c_1_m] ... [m c_n_1 ... c_n_m]\n"
            << "       f n [m c_1_1 ... c_1_m] ... [m c_n_1 ... c_n_m]\n"
            << "       t n [m c_1_1 ... c_1_m] ... [m c_n_1 ... c_n_m]\n"
            << std::flush;
}

void runRotate() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    row.resize(n);
    matrix.push_back(row);
  }

  Solution solution;
  solution.rotate(matrix);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void runSearch() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    matrix.push_back(row);
  }

  Solution solution;
  const int target = next<int>();

  std::cout << std::boolalpha << solution.searchMatrix(matrix, target) << std::endl;
}

void runGameOfLife() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    row.resize(n);
    matrix.push_back(row);
  }

  Solution solution;
  solution.gameOfLife(matrix);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void runKthSmallest() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    row.resize(n);
    matrix.push_back(row);
  }

  const int k = next<int>();

  Solution solution;
  auto output = solution.kthSmallest(matrix, k);

  std::cout << output << std::endl;
}

void runSpiralMatrix() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    matrix.push_back(row);
  }

  Solution solution;
  auto output = solution.spiralOrder(matrix);

  for (auto n:output) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;
}

void runNumIslands() {
  const int n = next<int>();
  vector<vector<char>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<char> row = next_vector<char>();
    matrix.push_back(row);
  }

  Solution solution;
  auto output = solution.numIslands(matrix);

  std::cout << output << std::endl;
}

void runMaxAreaOfIsland() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    matrix.push_back(row);
  }

  Solution solution;
  auto output = solution.maxAreaOfIsland(matrix);

  std::cout << output << std::endl;
}

void runWordSearch() {
  const int n = next<int>();
  vector<vector<char>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<char> row = next_vector<char>();
    matrix.push_back(row);
  }
  string word = next<string>();

  Solution solution;
  auto output = solution.exist(matrix, word);

  std::cout << output << std::endl;
}

void runSetZero() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    matrix.push_back(row);
  }

  Solution solution;
  solution.setZeroes(matrix);

  for (auto& vec:matrix) {
    for (auto n:vec) {
      std::cout << n << ' ';
    }
    std::cout << std::endl;
  }
}

void runSurroundedRegions() {
  const int n = next<int>();
  vector<vector<char>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<char> row = next_vector<char>();
    matrix.push_back(row);
  }

  Solution solution;
  solution.solve(matrix);

  for (auto& vec:matrix) {
    for (auto c:vec) {
      std::cout << c << ' ';
    }
    std::cout << std::endl;
  }
}

void runFlipAndInvert() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    matrix.push_back(row);
  }

  Solution solution;
  solution.flipAndInvertImage(matrix);

  for (auto& vec:matrix) {
    for (auto i:vec) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
}

void runTranspose() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next_vector<int>();
    matrix.push_back(row);
  }

  Solution solution;
  auto output = solution.transpose(matrix);

  for (auto& vec:output) {
    for (auto i:vec) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
}

int main() {
  char op;
  std::cin >> op;
  switch(op) {
    case 'r':
      runRotate();
      break;
    case 's':
      runSearch();
      break;
    case 'g':
      runGameOfLife();
      break;
    case 'k':
      runKthSmallest();
      break;
    case 'p':
      runSpiralMatrix();
      break;
    case 'i':
      runNumIslands();
      break;
    case 'a':
      runMaxAreaOfIsland();
      break;
    case 'w':
      runWordSearch();
      break;
    case 'z':
      runSetZero();
      break;
    case 'd':
      runSurroundedRegions();
      break;
    case 'f':
      runFlipAndInvert();
      break;
    case 't':
      runTranspose();
      break;
    default:
      usage();
      break;
  }
  return 0;
}
