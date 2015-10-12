#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>

class graph {
public:
  graph(int V);
  ~graph();

  void add_edge(int v, int u);
  void print_graph();

private:
  int V;
  std::list<int> *adj;
};

#endif // GRAPH_H_