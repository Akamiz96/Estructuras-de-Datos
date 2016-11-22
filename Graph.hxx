#include <stack>
#include <queue>
#include <algorithm>
#include "Graph.h"

struct Compare {
	template <class T>
  bool operator() (GraphNode<T> i,GraphNode<T> j) { return (i.getData()<j.getData());}
} compare;

template <class T>
Graph<T>::Graph(){

}
template <class T>
Graph<T>::Graph(std::deque<GraphNode<T>>& nNodes){
  this->nodes = nNodes;
}
template <class T>
Graph<T>::~Graph(){

}
template <class T>
std::deque<GraphNode<T>>& Graph<T>::getNodes(){
  return this->nodes;
}
template <class T>
void Graph<T>::setNodes(std::deque<GraphNode<T>>& nNodes){
  this->nodes = nNodes;
}
template <class T>
GraphNode<T>* Graph<T>::findVertex(T vertex){
  for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
    if(iterador->getData() == vertex)
    return &(*iterador);
  }
  return nullptr;
}
template <class T>
bool Graph<T>::findEdge(T& origin, T& destination){
  GraphNode<T>* nodeOrigin = this->findVertex(origin);
  GraphNode<T>* nodeDestination = this->findVertex(destination);
  if(nodeOrigin != nullptr && nodeDestination != nullptr){
    return nodeOrigin->findAdyacent(destination);
  }
  return false;
}
template <class T>
bool Graph<T>::addVertex(T& nVertex){
  for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
    if(iterador->getData() == nVertex)
      return false;
  }
  GraphNode<T>* node = new GraphNode<T>(nVertex);
  this->nodes.push_back(*node);
  std::sort(this->nodes.begin(),this->nodes.end(), compare);
  return true;
}
template <class T>
bool Graph<T>::addEdge(T& origin, T& destination){
  GraphNode<T>* nodeOrigin = this->findVertex(origin);
  GraphNode<T>* nodeDestination = this->findVertex(destination);
  if(nodeOrigin != nullptr && nodeDestination != nullptr){
    return nodeOrigin->addVertex(destination);
  }
  return false;
}
template <class T>
bool Graph<T>::addEdge(T& origin, T& destination, unsigned int nWeight){
	GraphNode<T>* nodeOrigin = this->findVertex(origin);
  GraphNode<T>* nodeDestination = this->findVertex(destination);
  if(nodeOrigin != nullptr && nodeDestination != nullptr){
    return nodeOrigin->addVertex(destination, nWeight);
  }
  return false;
}
template <class T>
bool Graph<T>::addUndirectedEdge(T& origin, T& destination){
	GraphNode<T>* nodeOrigin = this->findVertex(origin);
  GraphNode<T>* nodeDestination = this->findVertex(destination);
	if(nodeOrigin != nullptr && nodeDestination != nullptr){
		nodeOrigin->addVertex(destination);
		nodeDestination->addVertex(origin);
		return true;
	}
	return false;
}
template <class T>
bool Graph<T>::addUndirectedEdge(T& origin, T& destination, unsigned int nWeight){
	GraphNode<T>* nodeOrigin = this->findVertex(origin);
  GraphNode<T>* nodeDestination = this->findVertex(destination);
	if(nodeOrigin != nullptr && nodeDestination != nullptr){
		nodeOrigin->addVertex(destination, nWeight);
		nodeDestination->addVertex(origin, nWeight);
		return true;
	}
	return false;
}
template <class T>
void Graph<T>::removeVertex(T& vertex){
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		if(iterador->getData() == vertex){
				for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
					iterador->removeEdge(vertex);
				}
				this->nodes.erase(iterador);
				break;
			}
	}
}
template <class T>
void Graph<T>::removeEdge(T& origin, T& destination){
  GraphNode<T>* nodeOrigin = this->findVertex(origin);
  GraphNode<T>* nodeDestination = this->findVertex(destination);
  if(nodeOrigin != nullptr && nodeDestination != nullptr){
    nodeOrigin->removeEdge(destination);
  }
}
template <class T>
unsigned int Graph<T>::allWeights(){
	unsigned int sum = 0;
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		for(typename std::deque<AdyacentNode<T>>::iterator it2 = iterador->getAdyacentNodes().begin(); it2 != iterador->getAdyacentNodes().end(); it2++){
			sum += it2->getWeight();
		}
	}
	return sum;
}
template <class T>
void Graph<T>::flatCourse(){
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		std::cout << iterador->getData() << " " << std::endl;
	}
}
template <class T>
std::deque<T> Graph<T>::depthFirst(T begin){
	bool found, found_2;
	std::deque<T> nodesVisited;
	std::stack<T> nodes;
	GraphNode<T>* nodeOrigin = this->findVertex(begin);
	if(nodeOrigin != nullptr){
		nodes.push(nodeOrigin->getData());
		while(!nodes.empty()){
			found = false;
			T data = nodes.top();
			nodes.pop();
			for(typename std::deque<T>::iterator iterador = nodesVisited.begin(); iterador != nodesVisited.end(); iterador++){
				if(*iterador == data){
					found = true;
				}
			}
			if(!found){
				nodesVisited.push_back(data);
				for(typename std::deque<AdyacentNode<T>>::reverse_iterator iterador = this->findVertex(data)->getAdyacentNodes().rbegin(); iterador != this->findVertex(data)->getAdyacentNodes().rend(); iterador++){
					found_2 = false;
					for(typename std::deque<T>::iterator it2 = nodesVisited.begin(); it2 != nodesVisited.end(); it2++){
						if((*it2) == (iterador->getData())){
							found_2 = true;
						}
					}
					if(!found_2){
						nodes.push(iterador->getData());
					}
				}
			}
		}
	}
	return nodesVisited;
}
template <class T>
std::deque<T> Graph<T>::breadthFirst(T begin){
	bool found, found_2;
	std::deque<T> nodesVisited;
	std::queue<T> nodes;
	GraphNode<T>* nodeOrigin = this->findVertex(begin);
	if(nodeOrigin != nullptr){
		nodes.push(nodeOrigin->getData());
	}
	while(!nodes.empty()){
		found = false;
		T data = nodes.front();
		nodes.pop();
		for(typename std::deque<T>::iterator iterador = nodesVisited.begin(); iterador != nodesVisited.end(); iterador++){
			if(*iterador == data){
				found = true;
			}
		}
		if(!found){
			nodesVisited.push_back(data);
			for(typename std::deque<AdyacentNode<T>>::iterator iterador = this->findVertex(data)->getAdyacentNodes().begin(); iterador != this->findVertex(data)->getAdyacentNodes().end(); iterador++){
				found_2 = false;
				for(typename std::deque<T>::iterator it2 = nodesVisited.begin(); it2 != nodesVisited.end(); it2++){
					if((*it2) == (iterador->getData())){
						found_2 = true;
					}
				}
				if(!found_2){
					nodes.push(iterador->getData());
				}
			}
		}
	}
	return nodesVisited;
}
template <class T>
std::list<std::deque<T>> Graph<T>::connectedComponents(){
	std::list<std::deque<T>> connected;
	bool allready;
	typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin();
	do{
		allready = false;
		for(typename std::list<std::deque<T>>::iterator iteradorLista = connected.begin(); iteradorLista != connected.end() && !allready; iteradorLista++){
			for(typename std::deque<T>::iterator iteradorDeque = iteradorLista->begin(); iteradorDeque != iteradorLista->end() && !allready; iteradorDeque++){
				if(*iteradorDeque == iterador->getData())
					allready = true;
			}
		}
		if(!allready)
			connected.push_back(this->breadthFirst(iterador->getData()));
			//connected.push_back(this->depthFirst(iterador->getData()));
		iterador++;
	}while(iterador != this->nodes.end());
	return connected;
}
template <class T>
std::deque<T> Graph<T>::strongConnection(T begin){
	GraphNode<T>* nodeOrigin = this->findVertex(begin);
	std::deque<T>* strongConnected = new std::deque<T>();
	if(nodeOrigin != nullptr){
		std::deque<T> descendents = this->depthFirst(nodeOrigin->getData());
		Graph<T> inverted = this->invertedGraph();
		std::deque<T> ascendents = inverted.depthFirst(nodeOrigin->getData());
		for(typename std::deque<T>::iterator itDesc = descendents.begin(); itDesc != descendents.end(); itDesc++){
			for(typename std::deque<T>::iterator itAsc = ascendents.begin(); itAsc != ascendents.end(); itAsc++){
				if(*itDesc == *itAsc){
					strongConnected->push_back(*itDesc);
				}
			}
		}
	}
	return *strongConnected;
}
template <class T>
Graph<T> Graph<T>::invertedGraph(){
	Graph<T>* inverted = new Graph<T>();
	for(typename std::deque<GraphNode<T>>::iterator iteradorNodes = this->nodes.begin(); iteradorNodes != this->nodes.end(); iteradorNodes++){
		inverted->addVertex(iteradorNodes->getData());
	}
	for(typename std::deque<GraphNode<T>>::iterator iteradorNodes = this->nodes.begin(); iteradorNodes != this->nodes.end(); iteradorNodes++){
		for(typename std::deque<AdyacentNode<T>>::iterator iteradorData = iteradorNodes->getAdyacentNodes().begin(); iteradorData != iteradorNodes->getAdyacentNodes().end(); iteradorData++){
			inverted->addEdge(iteradorData->getData(), iteradorNodes->getData());
		}
	}
	return *inverted;
}
template <class T>
std::list<std::deque<T>> Graph<T>::allStrongConnections(){
	std::list<std::deque<T>> strongConnections;
	bool allready;
	typename std::deque<GraphNode<T>>::iterator iteradorData = this->nodes.begin();
	do{
		allready = false;
		for(typename std::list<std::deque<T>>::iterator iteradorLista = strongConnections.begin(); iteradorLista != strongConnections.end(); iteradorLista++){
			for(typename std::deque<T>::iterator iteradorDeque = iteradorLista->begin(); iteradorDeque != iteradorLista->end(); iteradorDeque++){
				if(iteradorData->getData() == *iteradorDeque)
					allready = true;
			}
		}
		if(!allready){
			strongConnections.push_back(this->strongConnection(iteradorData->getData()));
		}
		iteradorData++;
	}while(iteradorData != this->nodes.end());
	return strongConnections;
}
template <class T>
bool Graph<T>::evenAdyacentNodes(){
		for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
			if(iterador->getAdyacentNodes().size() % 2 != 0)
				return false;
		}
		return true;
}
template <class T>
bool Graph<T>::EulerCircuit(){
	Graph<T> inverted = this->invertedGraph();
	std::deque<T>* differentZero = new std::deque<T>();
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		GraphNode<T>* invertedNode = inverted.findVertex(iterador->getData());
		if(iterador->getAdyacentNodes().size() != invertedNode->getAdyacentNodes().size())
			return false;
		if(iterador->getAdyacentNodes().size() != 0){
			differentZero->push_back(iterador->getData());
		}
	}
	typename std::deque<T>::iterator itDiffZero = differentZero->begin();
	std::deque<T> strongConnected = this->strongConnection(*itDiffZero);
	bool found;
	itDiffZero++;
	for(; itDiffZero != differentZero->end(); itDiffZero++){
		std::deque<T> possible = this->strongConnection(*itDiffZero);
		if(strongConnected.size() < possible.size()){
			strongConnected = possible;
		}
	}
	for(itDiffZero = differentZero->begin(); itDiffZero != differentZero->end(); itDiffZero++){
		found = false;
		for(typename std::deque<T>::iterator itStrong = strongConnected.begin(); itStrong != strongConnected.end() && !found; itStrong++){
			if(*itStrong == *itDiffZero)
				found = true;
		}
		if(!found)
			return false;
	}
	return true;
}
template <class T>
bool Graph<T>::EulerPath(){
	Graph<T> inverted = this->invertedGraph();
	std::deque<T>* differentZero = new std::deque<T>();
	GraphNode<T>* onePlusEntrance = nullptr;
	GraphNode<T>* onePlusExit = nullptr;
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		GraphNode<T>* invertedNode = inverted.findVertex(iterador->getData());
		if(iterador->getAdyacentNodes().size() != invertedNode->getAdyacentNodes().size()){
			if(iterador->getAdyacentNodes().size() - invertedNode->getAdyacentNodes().size() == 1){
				if(onePlusEntrance == nullptr)
					onePlusEntrance = &(*iterador);
				else
					return false;
			}
			if(invertedNode->getAdyacentNodes().size() - iterador->getAdyacentNodes().size() == 1){
				if(onePlusExit == nullptr)
					onePlusExit = &(*iterador);
				else
					return false;
			}
		}
		if(iterador->getAdyacentNodes().size() != 0){
			differentZero->push_back(iterador->getData());
		}
	}
	if((onePlusEntrance != nullptr && onePlusExit == nullptr) || (onePlusEntrance == nullptr && onePlusExit != nullptr))
		return false;
	typename std::deque<T>::iterator itDiffZero = differentZero->begin();
	std::deque<T> connected = this->breadthFirst(*itDiffZero);
	bool found;
	itDiffZero++;
	for(; itDiffZero != differentZero->end(); itDiffZero++){
		std::deque<T> possible = this->breadthFirst(*itDiffZero);
		if(connected.size() < possible.size()){
			connected = possible;
		}
	}
	for(itDiffZero = differentZero->begin(); itDiffZero != differentZero->end(); itDiffZero++){
		found = false;
		for(typename std::deque<T>::iterator itStrong = connected.begin(); itStrong != connected.end() && !found; itStrong++){
			if(*itStrong == *itDiffZero)
				found = true;
		}
		if(!found)
			return false;
	}
	return true;
}
template <class T>
bool Graph<T>::EulerCircuitUndirected(){
	std::deque<T>* differentZero = new std::deque<T>();
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		if(iterador->getAdyacentNodes().size() % 2 != 0)
			return false;
		if(iterador->getAdyacentNodes().size() != 0)
			differentZero->push_back(iterador->getData());
	}
	typename std::deque<T>::iterator itDiffZero = differentZero->begin();
	std::deque<T> connected = this->breadthFirst(*itDiffZero);
	itDiffZero++;
	bool found;
	for(;itDiffZero != differentZero->end(); itDiffZero++){
		std::deque<T> possible = this->breadthFirst(*itDiffZero);
		if(connected.size() < possible.size()){
			connected = possible;
		}
	}
	for(itDiffZero = differentZero->begin(); itDiffZero != differentZero->end(); itDiffZero++){
		found = false;
		for(typename std::deque<T>::iterator itStrong = connected.begin(); itStrong != connected.end() && !found; itStrong++){
			if(*itStrong == *itDiffZero)
				found = true;
		}
		if(!found)
			return false;
	}
	return true;
}
template <class T>
bool Graph<T>::EulerPathUndirected(){
	std::deque<T>* differentZero = new std::deque<T>();
	GraphNode<T>* oddOne = nullptr;
	GraphNode<T>* oddTwo = nullptr;
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		if(iterador->getAdyacentNodes().size() % 2 != 0){
			if(oddOne == nullptr)
				oddOne = &(*iterador);
			else{
				if(oddTwo == nullptr)
					oddTwo = &(*iterador);
				else
					return false;
			}
		}
		if(iterador->getAdyacentNodes().size() != 0)
			differentZero->push_back(iterador->getData());
	}
	typename std::deque<T>::iterator itDiffZero = differentZero->begin();
	std::deque<T> connected = this->breadthFirst(*itDiffZero);
	bool found;
	itDiffZero++;
	for(; itDiffZero != differentZero->end(); itDiffZero++){
		std::deque<T> possible = this->breadthFirst(*itDiffZero);
		if(connected.size() < possible.size()){
			connected = possible;
		}
	}
	for(itDiffZero = differentZero->begin(); itDiffZero != differentZero->end(); itDiffZero++){
		found = false;
		for(typename std::deque<T>::iterator itStrong = connected.begin(); itStrong != connected.end() && !found; itStrong++){
			if(*itStrong == *itDiffZero)
				found = true;
		}
		if(!found)
			return false;
	}
	return true;
}
template <class T>
std::map<T, AdyacentNode<T>>* Graph<T>::Dijkstra(T begin){
	GraphNode<T>* nodeOrigin = this->findVertex(begin);
	if(nodeOrigin == nullptr)
		return nullptr;
	std::map<T, AdyacentNode<T>>* result = new std::map<T, AdyacentNode<T>>;
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		if(iterador->getData() == nodeOrigin->getData()){
			AdyacentNode<T>* node1 = new AdyacentNode<T>(iterador->getData(),0);
			result->insert(std::pair<T,AdyacentNode<T>>(iterador->getData(),*node1));
		}
		else{
			AdyacentNode<T>* node1 = new AdyacentNode<T>(iterador->getData());
			node1->setWeight(this->allWeights()+1);
			result->insert(std::pair<T,AdyacentNode<T>>(iterador->getData(),*node1));
		}
	}
	std::deque<T>* visitedNodes = new std::deque<T>();
	std::deque<T> nodesUnvisited;
	for(typename std::deque<GraphNode<T>>::iterator iterador = this->nodes.begin(); iterador != this->nodes.end(); iterador++){
		nodesUnvisited.push_back(iterador->getData());
	}
	T minimun = nodeOrigin->getData();
	while(!nodesUnvisited.empty()){
		visitedNodes->push_back(minimun);
		GraphNode<T>* node = this->findVertex(minimun);
		for(typename std::deque<T>::iterator it = nodesUnvisited.begin(); it != nodesUnvisited.end(); it++){
			if(*it == minimun){
				nodesUnvisited.erase(it);
				break;
			}
		}
		for(typename std::deque<AdyacentNode<T>>::iterator it = node->getAdyacentNodes().begin(); it != node->getAdyacentNodes().end(); it++){
			if((*result)[it->getData()].getWeight() > ((*result)[node->getData()].getWeight() + it->getWeight())){
					(*result)[it->getData()].setWeight(((*result)[node->getData()].getWeight() + it->getWeight()));
					(*result)[it->getData()].setData(node->getData());
				}
		}
		if(nodesUnvisited.size() > 0){
			typename std::deque<T>::iterator it = nodesUnvisited.begin();
			minimun = *it;
			it++;
			for(; it != nodesUnvisited.end(); it++){
				if((*result)[*it].getWeight() < (*result)[minimun].getWeight())
					minimun = *it;
			}
		}
	}
	return result;
}
template <class T>
std::map<T, AdyacentNode<T>*>* Graph<T>::Prim(T begin){
	bool finish = false, change = false;
	GraphNode<T>* nodeOrigin = this->findVertex(begin);
	if(nodeOrigin == nullptr)
		return nullptr;
	std::map<T, AdyacentNode<T>*>* result = new std::map<T, AdyacentNode<T>*>;
	result->insert(std::pair<T, AdyacentNode<T>*>(nodeOrigin->getData(),new AdyacentNode<T>(nodeOrigin->getData(),0)));
	while(!finish){
		change = false;
		finish = true;
		AdyacentNode<T>* adyacente = new AdyacentNode<T>(nodeOrigin->getData(),this->allWeights()+1);
		T* nodo = new T(0);
		for(typename std::map<T, AdyacentNode<T>*>::iterator it = result->begin(); it != result->end(); it++){
			GraphNode<T>* node = this->findVertex(it->first);
			if(node != nullptr){
				for(typename std::deque<AdyacentNode<T>>::iterator it2 = node->getAdyacentNodes().begin(); it2 != node->getAdyacentNodes().end(); it2++){
					typename std::map<T, AdyacentNode<T>*>::iterator found = result->find(it2->getData());
					if(found == result->end()){
						if(it2->getWeight() < adyacente->getWeight()){
							*nodo = it2->getData();
							adyacente->setData(node->getData());
							adyacente->setWeight(it2->getWeight());
							change = true;
						}
					}
				}
			}
		}
		if(change){
			result->insert(std::pair<T, AdyacentNode<T>*>(*nodo,adyacente));
			for(typename std::deque<GraphNode<T>>::iterator it = this->nodes.begin(); it != this->nodes.end(); it ++){
				typename std::map<T, AdyacentNode<T>*>::iterator found = result->find(it->getData());
				if(found == result->end()){
					finish = false;
				}
			}
		}
		else{
			break;
		}
	}
	for(typename std::deque<GraphNode<T>>::iterator it = this->nodes.begin(); it != this->nodes.end(); it ++){
		typename std::map<T, AdyacentNode<T>*>::iterator found = result->find(it->getData());
		if(found == result->end()){
			AdyacentNode<T>* nodeExtra = new AdyacentNode<T>(it->getData(),this->allWeights()+1);
			result->insert(std::pair<T, AdyacentNode<T>*>(it->getData(), nodeExtra));
		}
	}
	return result;
}
