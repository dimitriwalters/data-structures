#include <iostream>
#include "graph.h"

using namespace std;

graph::graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

graph::~graph() {
  delete[] adj;
}

void graph::add_edge(int v, int u) {
  adj[v].push_back(u);
}

void graph::print_graph() {
  cout << "[";
  for (int i=0; i<V; i++) {
    list<int> neighbours = adj[i];
    if (i != 0) {
      cout << ",";
    }
    cout << " " << i << ": [ ";
    for (list<int>::iterator it=neighbours.begin(); it != neighbours.end(); ++it) {
      if (it != neighbours.begin()) {
        cout << ", ";
      }
      cout << *it;
    }
    cout << " ]";
  }
  cout << " ]" << endl;
}