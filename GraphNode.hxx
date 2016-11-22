#include <algorithm>
#include "GraphNode.h"

struct CompareNode {
	template <class T>
  bool operator() (AdyacentNode<T> i,AdyacentNode<T> j) { return (i.getData()<j.getData());}
} compareNode;

template <class T>
GraphNode<T>::GraphNode(){

}
template <class T>
GraphNode<T>::GraphNode(T& nData){
  this->data = nData;
}
template <class T>
GraphNode<T>::GraphNode(T& nData, std::deque<AdyacentNode<T>>& NAdyacentNodes){
  this->adyacentNodes = NAdyacentNodes;
}
template <class T>
GraphNode<T>::~GraphNode(){

}
template <class T>
T& GraphNode<T>::getData(){
  return this->data;
}
template <class T>
std::deque<AdyacentNode<T>>& GraphNode<T>::getAdyacentNodes(){
  return this->adyacentNodes;
}
template <class T>
void GraphNode<T>::setData(T& nData){
  this->data = nData;
}
template <class T>
void GraphNode<T>::setAdyacentNodes(std::deque<AdyacentNode<T>>& nNodes){
  this->adyacentNodes = nNodes;
}
template <class T>
bool GraphNode<T>::findAdyacent(T& destination){
  for(typename std::deque<AdyacentNode<T>>::iterator iterador = this->adyacentNodes.begin(); iterador != this->adyacentNodes.end(); iterador++){
    if(iterador->getData() == destination)
      return true;
  }
  return false;
}
template <class T>
bool GraphNode<T>::addVertex(T destination){
  if(this->findAdyacent(destination))
    return true;
	AdyacentNode<T>* node = new AdyacentNode<T>(destination);
  this->adyacentNodes.push_back(*node);
	std::sort(this->adyacentNodes.begin(),this->adyacentNodes.end(), compareNode);
  return true;
}
template <class T>
bool GraphNode<T>::addVertex(T destination, unsigned int nWeight){
	if(this->findAdyacent(destination))
    return true;
	AdyacentNode<T>* node = new AdyacentNode<T>(destination, nWeight);
  this->adyacentNodes.push_back(*node);
	std::sort(this->adyacentNodes.begin(),this->adyacentNodes.end(), compareNode);
  return true;
}
template <class T>
void GraphNode<T>::removeEdge(T destination){
  for(typename std::deque<AdyacentNode<T>>::iterator iterador = this->adyacentNodes.begin(); iterador != this->adyacentNodes.end(); iterador++){
    if(iterador->getData() == destination){
      this->adyacentNodes.erase(iterador);
      break;
    }
  }
}
