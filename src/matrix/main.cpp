#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: r n [n v_1_1 ... v_1_n] ... [n v_n_1 ... v_n_n]\n"
            << "       s n [m v_1_1 ... v_1_m] ... [m v_n_1 ... v_n_m]\n"
            << "       g n [m v_1_1 ... v_1_m] ... [m v_n_1 ... v_n_m]\n"
            << "       k n [n v_1_1 ... v_1_n] ... [n v_n_1 ... v_n_n] k\n"
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
    default:
      usage();
      break;
  }
  return 0;
}
