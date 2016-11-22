#ifndef __ADYACENTNODE_H__
#define __ADYACENTNODE_H__

template <class T>
class AdyacentNode {
protected:
  T data;
  unsigned int weight;
public:
    AdyacentNode();
    AdyacentNode(T& nData);
    AdyacentNode(T& nData, unsigned int nWeight);
    ~AdyacentNode();
    T& getData();
    unsigned int getWeight();
    void setData(T& nData);
    void setWeight(unsigned int nWeight);
};
#include "AdyacentNode.hxx"
#endif
