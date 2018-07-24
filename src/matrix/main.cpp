#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: r n [n v_1_1 ... v_1_n] ... [n v_n_1 ... v_n_n]\n"
            << std::flush;
}

void runRotate() {
  const int n = next<int>();
  vector<vector<int>> matrix;
  for (int i = 0; i < n; ++i) {
    vector<int> row = next();
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

int main() {
  char op;
  std::cin >> op;
  switch(op) {
    case 'r':
      runRotate();
      break;
    default:
      usage();
      break;
  }
  return 0;
}
