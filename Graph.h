#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <deque>
#include <list>
#include <map>
#include "GraphNode.h"
template <class T>
class Graph {
protected:
  std::deque<GraphNode<T>> nodes;
public:
  Graph();
  Graph(std::deque<GraphNode<T>>& nNodes);
  ~Graph();
  std::deque<GraphNode<T>>& getNodes();
  void setNodes(std::deque<GraphNode<T>>& nNodes);

  GraphNode<T>* findVertex(T vertex);
  bool findEdge(T& origin, T& destination);
  bool addVertex(T& nVertex);
  bool addEdge(T& origin, T& destination);
  bool addEdge(T& origin, T& destination, unsigned int nWeight);
  bool addUndirectedEdge(T& origin, T& destination);
  bool addUndirectedEdge(T& origin, T& destination, unsigned int nWeight);
  void removeVertex(T& vertex);
  void removeEdge(T& origin, T& destination);
  unsigned int allWeights();

  void flatCourse();
  std::deque<T> depthFirst(T begin);
  std::deque<T> breadthFirst(T begin);
  std::list<std::deque<T>> connectedComponents();
  std::deque<T> strongConnection(T begin);
  Graph<T> invertedGraph();
  std::list<std::deque<T>> allStrongConnections();
  bool evenAdyacentNodes();
  bool EulerCircuit();
  bool EulerPath();
  bool EulerCircuitUndirected();
  bool EulerPathUndirected();

  std::map<T,AdyacentNode<T>>* Dijkstra(T begin);
  std::map<T,AdyacentNode<T>*>* Prim(T begin);
};
#include "Graph.hxx"
#endif
