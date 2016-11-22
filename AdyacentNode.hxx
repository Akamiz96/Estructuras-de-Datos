template <class T>
AdyacentNode<T>::AdyacentNode(){

}
template <class T>
AdyacentNode<T>::AdyacentNode(T& nData){
  this->data = nData;
  this->weight = 0;
}
template <class T>
AdyacentNode<T>::AdyacentNode(T& nData, unsigned int nWeight){
  this->data = nData;
  this->weight = nWeight;
}
template <class T>
AdyacentNode<T>::~AdyacentNode(){

}
template <class T>
T& AdyacentNode<T>::getData(){
  return this->data;
}
template <class T>
unsigned int AdyacentNode<T>::getWeight(){
  return this->weight;
}
template <class T>
void AdyacentNode<T>::setData(T& nData){
  this->data = nData;
}
template <class T>
void AdyacentNode<T>::setWeight(unsigned int nWeight){
  this->weight = nWeight;
}
