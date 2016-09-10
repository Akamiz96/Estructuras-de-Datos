
BinaryTreeAVL::BinaryTreeAVL(){
	root = nullptr;
}
BinaryTreeAVL::BinaryTreeAVL(NodoVocabulario& val){
	BinaryNodeAVL* node = new BinaryNodeAVL(val);
	root = node;
}
BinaryTreeAVL::~BinaryTreeAVL(){

}
bool BinaryTreeAVL::isEmpty(){
	return (this->root == nullptr) ? true : false;
}
BinaryNodeAVL* BinaryTreeAVL::getRoot(){
	return this->root;
}
void BinaryTreeAVL::setRoot(BinaryNodeAVL* nroot){
	this->root = nroot;
}
T& BinaryTreeAVL::max(){
	return (this->root->max());
}
T& BinaryTreeAVL::min(){
	return (this->root->min());
}
bool BinaryTreeAVL::insert(NodoVocabulario& n){
	if(this->isEmpty()){
		BinaryNodeAVL* nroot = new BinaryNodeAVL(n);
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
bool BinaryTreeAVL::erase(NodoVocabulario& n){
	if(this->isEmpty())
		return false;
	BinaryNodeAVL* node = nullptr;
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
bool BinaryTreeAVL::eraseRoot(){
	if(this->isEmpty())
		return false;
	BinaryNodeAVL* node = this->root;
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
		NodoVocabulario max = this->root->getLeft()->max()->getData();
		this->root->searchFather(max)->erase(max);
		this->root->setData(max);
	}
	return true;
}
bool BinaryTreeAVL::search(NodoVocabulario& n){
	return (this->root->search(n) == nullptr) ? false : true;
}
bool BinaryTreeAVL::searchFather(NodoVocabulario& n){
	return (this->root->searchFather(n) == nullptr) ? false : true;
}
int BinaryTreeAVL::treeHeight(){
	if(this->isEmpty())
		return -1;
	return this->root->nodeHeight();
}
void BinaryTreeAVL::updateHeight(){
	this->root->updateHeight();
}
void BinaryTreeAVL::inOrder(){
	if(this->root->getLeft() != nullptr)
	this->root->getLeft()->inOrder();
	std::cout << this->root->getData() << std::endl;
	if(this->root->getRight() != nullptr)
		this->root->getRight()->inOrder();
}
void BinaryTreeAVL::preOrder(){
	std::cout << this->root->getData() << std::endl;
	if(this->root->getLeft() != nullptr)
		this->root->getLeft()->preOrder();
	if(this->root->getRight() != nullptr)
		this->root->getRight()->preOrder();
}
void BinaryTreeAVL::posOrder(){
	if(this->root->getLeft() != nullptr)
		this->root->getLeft()->posOrder();
	if(this->root->getRight() != nullptr)
		this->root->getRight()->posOrder();
	std::cout << this->root->getData() << std::endl;
}
void BinaryTreeAVL::levelOrder(){
	std::list<BinaryNodeAVL*> List;
	List.push_back(this->root);
	for(typename std::list<BinaryNodeAVL*>::iterator iterador = List.begin(); iterador != List.end(); iterador++){
		(*iterador)->levelOrder(List);
	}
	for(typename std::list<BinaryNodeAVL*>::iterator iterador = List.begin(); iterador != List.end(); iterador++){
		std::cout << (*iterador)->getData() << std::endl;
	}
	List.clear();
}
void BinaryTreeAVL::balanceCheck(BinaryNodeAVL* father){
	BinaryNodeAVL* fathersFather;
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
