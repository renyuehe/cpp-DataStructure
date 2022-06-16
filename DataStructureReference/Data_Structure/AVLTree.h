#ifndef __AVLTREE_H__
#define __AVLTREE_H__

template <typename K, typename V>
class AVLNode{
public:
	AVLNode(K key, V value){
		this->key = key;
		this->value = value;
		height = 1;
		left = NULL;
		right = NULL;
	}
public:
	K key;
	V value;
	int height;
	AVLNode<K, V> *left;
	AVLNode<K, V> *right;
};

template <typename K, typename V>
class AVLTree{
public:
	AVLTree(){
		root = NULL;
		m_size = 0;
	}
	int size(){
		return m_size;
	}
	bool isEmpty(){
		return m_size == 0;
	}
	//增加操作
	void add(K key, V value);
	//删除操作
	void remove(K key);
	//查找操作
	bool contains(K key);
	V get(K key);
	//遍历操作
	void inOrder();
private:
	AVLNode<K, V>* add(AVLNode<K, V>* node, K key, V value);
	AVLNode<K, V>* remove(AVLNode<K, V>* node, K key);
	bool contains(AVLNode<K, V>* node, K key);
	int getHeight(AVLNode<K, V>* node);
	int max(int a, int b){ return a > b ? a : b; }
	int getBalanceFactor(AVLNode<K, V>* node);
	AVLNode<K, V>* rightRotate(AVLNode<K, V>* node);
	AVLNode<K, V>* leftRotate(AVLNode<K, V>* node);
	void inOrder(AVLNode<K, V> *node);
private:
	AVLNode<K, V> *root;
	int m_size;
};

template <typename K, typename V>
void AVLTree<K, V>::add(K key, V value){
	root = add(root, key, value);
}
template <typename K, typename V>
AVLNode<K, V>* AVLTree<K, V>::add(AVLNode<K, V>* node, K key, V value){
	if (node == NULL){
		m_size++;
		return new AVLNode<K, V>(key, value);
	}
	else if (key < node->key){
		node->left = add(node->left, key, value);
	}
	else if (key > node->key){
		node->right = add(node->right, key, value);
	}
	else if (key == node->key){
		node->value = value;
		return node;
	}
	//计算平衡因子
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	int balanceFactor = getBalanceFactor(node);
	//平衡维护
	if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0){
		return rightRotate(node);
	}
	else if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0){
		return leftRotate(node);
	}
	else if (balanceFactor > 1 && getBalanceFactor(node->left) < 0){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	else if (balanceFactor < -1 && getBalanceFactor(node->right) > 0){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

template <typename K, typename V>
void AVLTree<K, V>::remove(K key){
	root = remove(root, key);
}
template <typename K, typename V>
AVLNode<K, V>* AVLTree<K, V>::remove(AVLNode<K, V> *node, K key){
	if (node == NULL){
		return node;
	}
	AVLNode<K, V> *resNode = node;
	if (key < node->key){
		node->left = remove(node->left, key);
	}
	else if (key > node->key){
		node->right = remove(node->right, key);
	}
	else if (key == node->key){
		if (node->left == NULL){
			AVLNode<K, V> *rightNode = node->right;
			delete node;
			m_size--;
			resNode = rightNode;
		}
		else if (node->right == NULL){
			AVLNode<K, V> *leftNode = node->left;
			delete node;
			m_size--;
			resNode = leftNode;
		}
		else{
			AVLNode<K, V> *minNode = node->right;
			for (; minNode->left; minNode = minNode->left);
			minNode->right = remove(node->right, minNode->key);
			minNode->left = node->left;
			node->left = node->right = NULL;
			resNode = minNode;
		}
	}
	if (resNode == NULL){
		return NULL;
	}
	//计算平衡因子
	resNode->height = max(getHeight(resNode->left), getHeight(resNode->right)) + 1;
	int balanceFactor = getBalanceFactor(resNode);
	//平衡维护
	if (balanceFactor > 1 && getBalanceFactor(resNode->left) >= 0){
		return rightRotate(resNode);
	}
	else if (balanceFactor < -1 && getBalanceFactor(resNode->right) <= 0){
		return leftRotate(resNode);
	}
	else if (balanceFactor  > 1 && getBalanceFactor(resNode->left) < 0){
		resNode->left = leftRotate(resNode->left);
		return rightRotate(resNode);
	}
	else if (balanceFactor < -1 && getBalanceFactor(resNode->right) > 0){
		resNode->right = rightRotate(resNode->right);
		return leftRotate(resNode);
	}
	return resNode;
}

template <typename K, typename V>
bool AVLTree<K, V>::contains(K key){
	return contains(root, key);
}
template <typename K, typename V>
bool AVLTree<K, V>::contains(AVLNode<K, V> *node, K key){
	if (node == NULL){
		return false;
	}
	if (key == node->key){
		return true;
	}
	else if (key < node->key){
		return contains(node->left, key);
	}
	else{
		return contains(node->right, key);
	}
}
template <typename K, typename V>
V AVLTree<K, V>::get(K key){
	AVLNode<K, V> *node = root;
	while (node != NULL){
		if (key == node->key){
			return node->value;
		}
		else if (key < node->key){
			node = node->left;
		}
		else if (key > node->key){
			node = node->right;
		}
	}
	cout << "查询失败！AVL树中不存在" << key << "！" << endl;
	return NULL;
}

template <typename K, typename V>
int AVLTree<K, V>::getHeight(AVLNode<K, V>* node){
	if (node == NULL){
		return 0;
	}
	return node->height;
}
template <typename K, typename V>
int AVLTree<K, V>::getBalanceFactor(AVLNode<K, V>* node){
	int lHeight = 0, rHeight = 0;
	if (node == NULL){
		return 0;
	}
	if (node->left != NULL){
		lHeight = node->left->height;
	}
	if (node->right != NULL){
		rHeight = node->right->height;
	}
	return lHeight - rHeight;
}
template <typename K, typename V>
AVLNode<K, V>* AVLTree<K, V>::rightRotate(AVLNode<K, V>* node){
	AVLNode<K, V>* res = node->left;
	AVLNode<K, V>* p = res->right;
	res->right = node;
	node->left = p;
	//维护平衡
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	res->height = max(getHeight(res->left), getHeight(res->right)) + 1;
	return res;
}
template <typename K, typename V>
AVLNode<K, V>* AVLTree<K, V>::leftRotate(AVLNode<K, V>* node){
	AVLNode<K, V>* res = node->right;
	AVLNode<K, V>* p = res->left;
	res->left = node;
	node->right = p;
	//维护平衡
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	res->height = max(getHeight(res->left), getHeight(res->right)) + 1;
	return res;
}

template <typename K, typename V>
void AVLTree<K, V>::inOrder(){
	cout << "AVL Tree: " << "Size = " << m_size << endl;
	cout << "中序遍历：";
	inOrder(root);
	cout << endl;
}
template <typename K, typename V>
void AVLTree<K, V>::inOrder(AVLNode<K, V> *node){
	if (node == NULL){
		return;
	}
	inOrder(node->left);
	cout << node->key << "  ";
	inOrder(node->right);
}

#endif