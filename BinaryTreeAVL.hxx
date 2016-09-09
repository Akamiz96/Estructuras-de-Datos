template <class T>
BinaryTreeAVL<T>::BinaryTreeAVL(){
	root = nullptr;
}
template <class T>
BinaryTreeAVL<T>::BinaryTreeAVL(T& val){
	BinaryNodeAVL<T>* node = new BinaryNodeAVL<T>(val);
	root = node;
}
template <class T>
BinaryTreeAVL<T>::~BinaryTreeAVL(){

}
template <class T>
bool BinaryTreeAVL<T>::isEmpty(){
	return (this->root == nullptr) ? true : false;
}
template <class T>
BinaryNodeAVL<T>* BinaryTreeAVL<T>::getRoot(){
	return this->root;
}
template <class T>
void BinaryTreeAVL<T>::setRoot(BinaryNodeAVL<T>* nroot){
	this->root = nroot;
}
template <class T>
T& BinaryTreeAVL<T>::max(){
	return (this->root->max());
}
template <class T>
T& BinaryTreeAVL<T>::min(){
	return (this->root->min());
}
template <class T>
bool BinaryTreeAVL<T>::insert(T& n){
	if(this->isEmpty()){
		BinaryNodeAVL<T>* nroot = new BinaryNodeAVL<T>(n);
		this->setRoot(nroot);
		this->updateHeight();
		return true;
	}
	if(this->root->insert(n)){
		this->updateHeight();
		this->balanceCheck(this->root->searchFather(n));
		return true;
	}
	return false;
}
template <class T>
bool BinaryTreeAVL<T>::erase(T& n){
	if(this->isEmpty())
		return false;
	BinaryNodeAVL<T>* node = nullptr;
	if(this->root->getData() == n){
		if(this->eraseRoot()){
			this->updateHeight();
			this->balanceCheck(this->root);
		}
		else
			return false;
	}
	else
		node = this->root->searchFather(n);
	if(node == nullptr)
		return false;
	node->erase(n);
	this->updateHeight();
	this->balanceCheck(node);
	return true;
}
template <class T>
bool BinaryTreeAVL<T>::eraseRoot(){
	if(this->isEmpty())
		return false;
	BinaryNodeAVL<T>* node = this->root;
	if(this->root->getRight() == nullptr && this->root->getLeft() == nullptr){
		this->setRoot(nullptr);
		delete node;
	}
	if(this->root->getRight() != nullptr && this->root->getLeft() == nullptr){
		this->setRoot(this->root->getRight());
		delete node;
	}
	if(this->root->getRight() == nullptr && this->root->getLeft() != nullptr){
		this->setRoot(this->root->getLeft());	
		delete node;
	}
	if(this->root->getRight() != nullptr && this->root->getLeft() != nullptr){
		T max = this->root->getLeft()->max()->getData();
		this->root->searchFather(max)->erase(max);	
		this->root->setData(max);
	}
	return true;
}
template <class T>
bool BinaryTreeAVL<T>::search(T& n){
	return (this->root->search(n) == nullptr) ? false : true;
}
template <class T>
bool BinaryTreeAVL<T>::searchFather(T& n){
	return (this->root->searchFather(n) == nullptr) ? false : true;
}
template <class T>
int BinaryTreeAVL<T>::treeHeight(){
	if(this->isEmpty())
		return -1;
	return this->root->nodeHeight();
}
template <class T>
void BinaryTreeAVL<T>::updateHeight(){
	this->root->updateHeight();
}
template <class T>
int BinaryTreeAVL<T>::size(){
	if(this->isEmpty())
		return 0;
}
template <class T>
void BinaryTreeAVL<T>::inOrder(){
	if(this->root->getLeft() != nullptr)
	this->root->getLeft()->inOrder();
	std::cout << this->root->getData() << std::endl;
	if(this->root->getRight() != nullptr)
		this->root->getRight()->inOrder();
}
template <class T>
void BinaryTreeAVL<T>::preOrder(){
	std::cout << this->root->getData() << std::endl;
	if(this->root->getLeft() != nullptr)
		this->root->getLeft()->preOrder();
	if(this->root->getRight() != nullptr)
		this->root->getRight()->preOrder();
}
template <class T>
void BinaryTreeAVL<T>::posOrder(){
	if(this->root->getLeft() != nullptr)
		this->root->getLeft()->posOrder();
	if(this->root->getRight() != nullptr)
		this->root->getRight()->posOrder();
	std::cout << this->root->getData() << std::endl;
}
template <class T>
void BinaryTreeAVL<T>::levelOrder(){
	std::list<BinaryNodeAVL<T>*> List; 
	List.push_back(this->root);
	for(typename std::list<BinaryNodeAVL<T>*>::iterator iterador = List.begin(); iterador != List.end(); iterador++){
		(*iterador)->levelOrder(List);
	}
	for(typename std::list<BinaryNodeAVL<T>*>::iterator iterador = List.begin(); iterador != List.end(); iterador++){
		std::cout << (*iterador)->getData() << std::endl;
	}
	List.clear();
}
template <class T>
void BinaryTreeAVL<T>::balanceCheck(BinaryNodeAVL<T>* father){
	BinaryNodeAVL<T>* fathersFather;
	while(father != this->root || father == nullptr){
		fathersFather = this->root->searchFather(father->getData());
		if(father->balanceCheck(fathersFather,this->root)){
			this->updateHeight();
		}
		father = fathersFather;
	}
	if(father == this->root){
		if(father->balanceCheck(father, this->root)){
			this->updateHeight();
		}
	}
	this->updateHeight();
}