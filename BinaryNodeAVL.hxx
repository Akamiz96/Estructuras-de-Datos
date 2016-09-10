BinaryNodeAVL::BinaryNodeAVL(){
	right = nullptr;
  left = nullptr;
}
BinaryNodeAVL::BinaryNodeAVL(NodoVocabulario& val){
    data = val;
    right = nullptr;
    left = nullptr;
}
BinaryNodeAVL::BinaryNodeAVL(NodoVocabulario& val, BinaryNodeAVL* rightSon, BinaryNodeAVL* leftSon){
    data = val;
    right = rightSon;
    left = leftSon;
}
BinaryNodeAVL::~BinaryNodeAVL(){

}
NodoVocabulario& BinaryNodeAVL::getData(){
	return this->data;
}
BinaryNodeAVL*& BinaryNodeAVL::getRight(){
	return this->right;
}
BinaryNodeAVL*& BinaryNodeAVL::getLeft(){
	return this->left;
}
unsigned int BinaryNodeAVL::getHeight(){
	return this->height;
}
void BinaryNodeAVL::setData (NodoVocabulario& val){
	this->data = val;
}
void BinaryNodeAVL::setRight (BinaryNodeAVL* val){
	this->right = val;
}
void BinaryNodeAVL::setLeft (BinaryNodeAVL* val){
	this->left = val;
}
void BinaryNodeAVL::setHeight (unsigned int val){
	this->height = val;
}
BinaryNodeAVL*  BinaryNodeAVL::max(){
	return (this->right == nullptr) ? this : this->right->max();
}
BinaryNodeAVL*  BinaryNodeAVL::min(){
	return (this->left == nullptr) ? this : this->left->min();
}
bool BinaryNodeAVL::insert (NodoVocabulario& nval){
	BinaryNodeAVL* node = new BinaryNodeAVL(nval);
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
void BinaryNodeAVL::erase(NodoVocabulario& val){
	BinaryNodeAVL* node;
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
			NodoVocabulario max = node->getLeft()->max()->getData();
			this->searchFather(max)->erase(max);
			this->right->setData(max);
		}
		if(val < this->data){
			NodoVocabulario max = node->getLeft()->max()->getData();
			this->searchFather(max)->erase(max);
			this->left->setData(max);
		}
	}
}
BinaryNodeAVL* BinaryNodeAVL::search(NodoVocabulario& val){
	if(this->data == val)
		return this;
	if(this->right != nullptr && val > this->data)
		return this->right->search(val);
	if(this->left != nullptr && val < this->data)
		return this->left->search(val);
	return nullptr;
}
BinaryNodeAVL* BinaryNodeAVL::searchFather(NodoVocabulario& val){
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
int BinaryNodeAVL::nodeHeight(){
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
void BinaryNodeAVL::updateHeight(){
	if(this->right != nullptr){
		this->right->updateHeight();
	}
	if(this->left != nullptr){
		this->left->updateHeight();
	}
	this->setHeight(this->nodeHeight());
}
void BinaryNodeAVL::inOrder(){
	if(this->left != nullptr)
		this->left->inOrder();
	std::cout << this->getData() << std::endl;
	if(this->right != nullptr)
		this->right->inOrder();
}
void BinaryNodeAVL::preOrder(){
	std::cout << this->getData() << std::endl;
	if(this->left != nullptr)
		this->left->preOrder();
	if(this->right != nullptr)
		this->right->preOrder();
}
void BinaryNodeAVL::posOrder(){
	if(this->left != nullptr)
		this->left->posOrder();
	if(this->right != nullptr)
		this->right->posOrder();
	std::cout << this->getData() << std::endl;
}
void BinaryNodeAVL::levelOrder(std::list<BinaryNodeAVL*> & List){
	if(this->left != nullptr)
		List.push_back(this->left);
	if(this->right != nullptr)
		List.push_back(this->right);
}
void BinaryNodeAVL::descendants(){
	std::cout << "Father: " << this->data << std::endl;
	if(this->right != nullptr)
		std::cout << "Right son: " << this->right->getData() << std::endl;
	if(this->left != nullptr)
		std::cout << "Left son: " << this->left->getData() << std::endl;
}
BinaryNodeAVL* BinaryNodeAVL::rightRotation(){
	BinaryNodeAVL* newFather = this->left;
	this->left = newFather->getRight();
	newFather->setRight(this);
	return newFather;
}
BinaryNodeAVL* BinaryNodeAVL::leftRotation(){
	BinaryNodeAVL* newFather = this->right;
	this->right = newFather->getLeft();
	newFather->setLeft(this);
	return newFather;
}
BinaryNodeAVL* BinaryNodeAVL::rightLeftRotation(){
	BinaryNodeAVL* aux = this->right->rightRotation();
	std::cout<< this->data << std::endl;
	this->right = aux;
	return this->leftRotation();

}
BinaryNodeAVL* BinaryNodeAVL::leftRightRotation(){
	BinaryNodeAVL<T>* aux = this->left->leftRotation();
	this->left = aux;
	return this->rightRotation();
}
bool BinaryNodeAVL::balanceCheck(BinaryNodeAVL* father, BinaryNodeAVL*& root){
	BinaryNodeAVL* change;
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
BinaryNodeAVL* BinaryNodeAVL::balance(short int type){
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
