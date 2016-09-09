template <class T>
BinaryNodeAVL<T>::BinaryNodeAVL(){
	right = nullptr;
    left = nullptr;
}
template <class T>
BinaryNodeAVL<T>::BinaryNodeAVL(T& val){
    data = val;
    right = nullptr;
    left = nullptr;
}
template <class T>
BinaryNodeAVL<T>::BinaryNodeAVL(T& val, BinaryNodeAVL<T>* rightSon, BinaryNodeAVL<T>* leftSon){
    data = val;
    right = rightSon;
    left = leftSon;
}
template <class T>
BinaryNodeAVL<T>::~BinaryNodeAVL(){

}
template <class T>
T& BinaryNodeAVL<T>::getData(){
	return this->data;
}
template <class T>
BinaryNodeAVL<T>*& BinaryNodeAVL<T>::getRight(){
	return this->right;
}
template <class T>
BinaryNodeAVL<T>*& BinaryNodeAVL<T>::getLeft(){
	return this->left;
}
template <class T>
unsigned int BinaryNodeAVL<T>::getHeight(){
	return this->height;
}
template <class T>
void BinaryNodeAVL<T>::setData (T& val){
	this->data = val;
}
template <class T>
void BinaryNodeAVL<T>::setRight (BinaryNodeAVL<T>* val){
	this->right = val;
}
template <class T>
void BinaryNodeAVL<T>::setLeft (BinaryNodeAVL<T>* val){
	this->left = val;
}
template <class T>
void BinaryNodeAVL<T>::setHeight (unsigned int val){
	this->height = val;
}
template <class T>
BinaryNodeAVL<T>*  BinaryNodeAVL<T>::max(){
	return (this->right == nullptr) ? this : this->right->max();
}
template <class T>
BinaryNodeAVL<T>*  BinaryNodeAVL<T>::min(){
	return (this->left == nullptr) ? this : this->left->min();
}
template <class T>
bool BinaryNodeAVL<T>::insert (T& nval){
	BinaryNodeAVL<T>* node = new BinaryNodeAVL<T>(nval);
	if(nval > this->data){
		if(this->right == nullptr)
			this->right = node;
		else
			this->right->insert(nval);
	}
	if(nval < this->data){
		if(this->left == nullptr)
			this->left = node;
		else
			this->left->insert(nval);
	}
	if(this->data == nval)
		return false;

	return true;
}
template <class T>
void BinaryNodeAVL<T>::erase(T& val){
	BinaryNodeAVL<T>* node;
	if(val > this->data)
		node = this->right;
	if(val < this->data)
		node = this->left;
	if(node->getRight() == nullptr && node->getLeft() == nullptr){
		if(val > this->data)
			this->right = nullptr;
		if(val < this->data)
			this->left = nullptr;
		delete node;
	}
	if(node->getRight() != nullptr && node->getLeft() == nullptr){
		if(val > this->data)
			this->right = node->getRight();
		if(val < this->data)
			this->left = node->getRight();
		delete node;
	}
	if(node->getRight() == nullptr && node->getLeft() != nullptr){
		if(val > this->data)
			this->right = node->getLeft();
		if(val < this->data)
			this->left = node->getLeft();
		delete node;
	}
	if(node->getRight() != nullptr && node->getLeft() != nullptr){
		if(val > this->data){
			T max = node->getLeft()->max()->getData();
			this->searchFather(max)->erase(max);	
			this->right->setData(max);
		}
		if(val < this->data){
			T max = node->getLeft()->max()->getData();
			this->searchFather(max)->erase(max);
			this->left->setData(max);
		}
	}
}
template <class T>
BinaryNodeAVL<T>* BinaryNodeAVL<T>::search(T& val){
	if(this->data == val)
		return this;
	if(this->right != nullptr && val > this->data)
		return this->right->search(val);
	if(this->left != nullptr && val < this->data)
		return this->left->search(val);
	return nullptr;
}
template <class T>
BinaryNodeAVL<T>* BinaryNodeAVL<T>::searchFather(T& val){
	if(this->right != nullptr && this->right->getData() == val)
		return this;
	if(this->right != nullptr && val > this->data)
		return this->right->searchFather(val);
	if(this->left != nullptr && this->left->getData() == val)
		return this;
	if(this->left != nullptr && val < this->data)
		return this->left->searchFather(val);
	if(this->data == val)
		return nullptr;
	return nullptr;
}
template <class T>
int BinaryNodeAVL<T>::nodeHeight(){
	if(this->right == nullptr && this->left == nullptr)
		return 0;
	int rightH, leftH;
	if(this->right != nullptr)
		rightH = this->right->nodeHeight();
	else
		rightH = -1;
	if(this->left != nullptr)
		leftH = this->left->nodeHeight();
	else
		leftH = -1;
	return (leftH > rightH) ? (1 + leftH) : (1 + rightH);
}
template <class T>
void BinaryNodeAVL<T>::updateHeight(){
	if(this->right != nullptr){
		this->right->updateHeight();
	}
	if(this->left != nullptr){
		this->left->updateHeight();
	}
	this->setHeight(this->nodeHeight());
}
template <class T>
int BinaryNodeAVL<T>::size(){

}
template <class T>
void BinaryNodeAVL<T>::inOrder(){
	if(this->left != nullptr)
		this->left->inOrder();
	std::cout << this->getData() << std::endl;
	if(this->right != nullptr)
		this->right->inOrder();
}
template <class T>
void BinaryNodeAVL<T>::preOrder(){
	std::cout << this->getData() << std::endl;
	if(this->left != nullptr)
		this->left->preOrder();
	if(this->right != nullptr)
		this->right->preOrder();
}
template <class T>
void BinaryNodeAVL<T>::posOrder(){
	if(this->left != nullptr)
		this->left->posOrder();
	if(this->right != nullptr)
		this->right->posOrder();
	std::cout << this->getData() << std::endl;
}
template <class T>
void BinaryNodeAVL<T>::levelOrder(std::list<BinaryNodeAVL<T>*> & List){
	if(this->eft != nullptr)
		List.push_back(this->left);
	if(this->right != nullptr)
		List.push_back(this->right);
}
template <class T>
void BinaryNodeAVL<T>::descendants(){
	std::cout << "Father: " << this->data << std::endl;
	if(this->right != nullptr)
		std::cout << "Right son: " << this->right->getData() << std::endl;
	if(this->left != nullptr)
		std::cout << "Left son: " << this->left->getData() << std::endl;
}
template <class T>
BinaryNodeAVL<T>* BinaryNodeAVL<T>::rightRotation(){
	BinaryNodeAVL<T>* newFather = this->left;
	this->left = newFather->getRight();
	newFather->setRight(this);
	return newFather;
}
template <class T>
BinaryNodeAVL<T>* BinaryNodeAVL<T>::leftRotation(){
	BinaryNodeAVL<T>* newFather = this->right;
	this->right = newFather->getLeft();
	newFather->setLeft(this);
	return newFather;
}
template <class T>
BinaryNodeAVL<T>* BinaryNodeAVL<T>::rightLeftRotation(){
	BinaryNodeAVL<T>* aux = this->right->rightRotation();
	std::cout<< this->data << std::endl;
	this->right = aux;
	return this->leftRotation();

}
template <class T>
BinaryNodeAVL<T>* BinaryNodeAVL<T>::leftRightRotation(){
	BinaryNodeAVL<T>* aux = this->left->leftRotation();
	this->left = aux;
	return this->rightRotation();
}
template <class T>
bool BinaryNodeAVL<T>::balanceCheck(BinaryNodeAVL<T>* father, BinaryNodeAVL<T>*& root){
	BinaryNodeAVL<T>* change;
	int dif;
	if(this->left != nullptr && this->right != nullptr){
		dif = this->left->getHeight() - this->right->getHeight();
	}
	if(this->left == nullptr && this->right != nullptr){
		dif = -1 - this->right->getHeight();
	}
	if(this->left != nullptr && this->right == nullptr){
		dif = this->left->getHeight() + 1;
	}
	if(this->left == nullptr && this->right == nullptr){
		dif = 0;
	}
	if(dif >= 2){
		int leftH, rightH;
		if(this->left->getLeft() == nullptr)
			leftH = -1;
		else
			leftH = this->left->getLeft()->getHeight();
		if(this->left->getRight() == nullptr)
			rightH = -1;
		else
			rightH = this->left->getRight()->getHeight();
		if(leftH > rightH){
			if(this == root)
					root = this->balance(1);
			else{
				if(father != nullptr){
					change = this->balance(1);
					if(change->getData() > father->getData())
						father->setRight(change);
					else
						father->setLeft(change);
				}
			}
		}
		if(leftH < rightH){
			if(this == root)
					root = this->balance(3);
			else{
				if(father != nullptr){
					change = this->balance(3);
					if(change->getData() > father->getData())
						father->setRight(change);
					else
						father->setLeft(change);
				}
			}
		}
	}
	if(dif <= -2){
		std::cout << "-2: -> " << this->data << "-->"<<father->getData() << "-->" << root->getData()<< std::endl;
		int leftH, rightH;
		if(this->right->getLeft() == nullptr)
			leftH = -1;
		else{
			leftH = this->right->getLeft()->getHeight();

		}
		if(this->right->getRight() == nullptr)
			rightH = -1;
		else
			rightH = this->right->getRight()->getHeight();
		if(leftH < rightH){
			if(this == root){
				root = this->balance(2);
			}
			else{
				if(father != nullptr){
					change = this->balance(2);
					if(change->getData() > father->getData())
						father->setRight(change);
					else
						father->setLeft(change);
				}
			}
			return true;
		}
		if(leftH > rightH){
			if(this->data == root->getData()){
					root = this->balance(4);
			}
			else{
				if(father != nullptr){
					change = this->balance(4);
					if(change->getData() > father->getData())
						father->setRight(change);
					else
						father->setLeft(change);
				}
			}
			return true;
		}
	}
	return false;
}
template <class T>
BinaryNodeAVL<T>* BinaryNodeAVL<T>::balance(short int type){
	switch(type){
		case 1:
		return this->rightRotation();
		case 2:
		return this->leftRotation();
		case 3:
		return this->leftRightRotation();
		case 4:
		return this->rightLeftRotation();
		default:
		return nullptr;
	}
}
