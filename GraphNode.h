#ifndef __GRAPHNODE_H__
#define __GRAPHNODE_H__
#include "AdyacentNode.h"
#include <deque>
template <class T>
class GraphNode {
protected:
  T data;
  std::deque<AdyacentNode<T>> adyacentNodes;
public:
    GraphNode();
    GraphNode(T nData);
    GraphNode(T nData, std::deque<AdyacentNode<T>> NAdyacentNodes);
    ~GraphNode();
    T& getData();
    std::deque<AdyacentNode<T>>& getAdyacentNodes();
    void setData(T nData);
    void setAdyacentNodes(std::deque<AdyacentNode<T>> nNodes);

    bool findAdyacent(T destination);
    bool addVertex(T destination);
    bool addVertex(T destination, unsigned int nWeight);
    void removeEdge(T destination);
};
#include "GraphNode.hxx"
#endif
