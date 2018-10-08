#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

void usage() {
  std::cout << "usage: graph b n k e1_s e1_e ... ek_s ek_e\n"
            << std::flush;
}

static vector<vector<int>> read_undirected_graph() {
  int n = next<int>();
  vector<vector<int>> graph(n);

  int k = next<int>();
  for (int i = 0; i < k; ++i) {
    int s = next<int>();
    int e = next<int>();
    graph[s].emplace_back(e);
    graph[e].emplace_back(s);
  }
  return graph;
}

void runIsBipartiteGraph() {
  auto graph = read_undirected_graph();

  Solution solution;
  std::cout << std::boolalpha << solution.isBipartite(graph) << std::endl;
}

int main() {
  char op;
  cin >> op;
  switch (op) {
    case 'b':
      runIsBipartiteGraph();
      break;
    default:
      usage();
      break;
  }
  return 0;
}
