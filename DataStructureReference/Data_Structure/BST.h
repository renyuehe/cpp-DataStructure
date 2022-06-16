#ifndef __BST_H__
#define __BST_H__

#include "ArrayStack.h"
#include "LoopQueue.h"

template <class T>
class BTNode{
public:
	BTNode(T num, BTNode<T> *left = NULL, BTNode<T> *right = NULL){
		m_data = num;
		this->left = left;
		this->right = right;
	}
public:
	T m_data;
	BTNode<T> *left;
	BTNode<T> *right;
};
template <class T>
class BST{
public:
	BST(){
		root = NULL;
	}
	int size(){
		return m_size;
	}
	bool isEmpty(){
		return root == NULL;
	}
	//增加操作
	void add(T num);
	//删除操作
	void remove(T num);
	//查找操作
	bool contains(T num);
	//遍历操作
	void preOrder();
	void inOrder();
	void postOrder();
	void preOrderNR();
	void inOrderNR();
	void postOrderNR();
	void levelOrder();
private:
	BTNode<T>* add(BTNode<T> *node, T num);
	BTNode<T>* remove(BTNode<T> *node, T num);
	bool contains(BTNode<T> *node, T num);
	void preOrder(BTNode<T> *node);
	void inOrder(BTNode<T> *node);
	void postOrder(BTNode<T> *node);
private:
	BTNode<T> *root;
	int m_size;
};

template <class T>
void BST<T>::add(T num){
	root = add(root, num);
}
template <class T>
BTNode<T>* BST<T>::add(BTNode<T> *node, T num){
	if (node == NULL){
		m_size++;
		return new BTNode<T>(num);
	}
	else if (num < node->m_data){
		node->left = add(node->left, num);
	}
	else if(num > node->m_data){
		node->right = add(node->right, num);
	}
	return node;
}

template <class T>
void BST<T>::remove(T num){
	root = remove(root, num);
}
template <class T>
BTNode<T>* BST<T>::remove(BTNode<T> *node, T num){
	if (node == NULL){
		return node;
	}
	if (num < node->m_data){
		node->left = remove(node->left, num);
	}
	else if (num > node->m_data){
		node->right = remove(node->right, num);
	}
	else if (num == node->m_data){
		if (node->left == NULL){
			BTNode<T> *rightNode = node->right;
			delete node;
			m_size--;
			return rightNode;
		}
		else if (node->right == NULL){
			BTNode<T> *leftNode = node->left;
			delete node;
			m_size--;
			return leftNode;
		}
		else{
			BTNode<T> *minNode = node->right;
			for (; minNode->left; minNode = minNode->left);
			node->m_data = minNode->m_data;
			node->right = remove(node->right, minNode->m_data);
			return node;
		}
	}
	return node;
}

template <class T>
bool BST<T>::contains(T num){
	return contains(root, num);
}
template <class T>
bool BST<T>::contains(BTNode<T> *node, T num){
	if (node == NULL){
		return false;
	}
	if (num == node->m_data){
		return true;
	}
	else if (num < node->m_data){
		return contains(node->left, num);
	}
	else{
		return contains(node->right, num);
	}
}

template <class T>
void BST<T>::preOrder(){
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "先序遍历：";
	preOrder(root);
	cout << endl;
}
template <class T>
void BST<T>::preOrder(BTNode<T> *node){
	if (node == NULL){
		return;
	}
	cout << node->m_data << "  ";
	preOrder(node->left);
	preOrder(node->right);
}
template <class T>
void BST<T>::inOrder(){
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "中序遍历：";
	inOrder(root);
	cout << endl;
}
template <class T>
void BST<T>::inOrder(BTNode<T> *node){
	if (node == NULL){
		return;
	}
	inOrder(node->left);
	cout << node->m_data << "  ";
	inOrder(node->right);
}
template <class T>
void BST<T>::postOrder(){
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "后序遍历：";
	postOrder(root);
	cout << endl;
}
template <class T>
void BST<T>::postOrder(BTNode<T> *node){
	if (node == NULL){
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	cout << node->m_data << "  ";
}
template <class T>
void BST<T>::preOrderNR(){
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "先序遍历（非递归）：";
	ArrayStack<BTNode<T>*> s;
	s.push(root);
	while (!s.isEmpty()){
		BTNode<T> *node = s.peek();
		cout << node->m_data << "  ";
		s.pop();
		if (node->right != NULL){
			s.push(node->right);
		}
		if (node->left != NULL){
			s.push(node->left);
		}
	}
	cout << endl;
}
template <class T>
void BST<T>::inOrderNR(){
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "中序遍历（非递归）：";
	ArrayStack<BTNode<T>*> s;
	BTNode<T> *node = root;
	while (node != NULL || !s.isEmpty()){
		while (node != NULL){
			s.push(node);
			node = node->left;
		}
		node = s.peek();
		cout << node->m_data << "  ";
		s.pop();
		if (node->right != NULL){
			node = node->right;  
		}
		else{
			node = NULL;
		}
	}
	cout << endl;
}
template <class T>
void BST<T>::postOrderNR(){
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "后序遍历（非递归）：";
	ArrayStack<BTNode<T>*> s;
	BTNode<T> *node = root;
	BTNode<T> *lastVisited = root;
	while (node != NULL || !s.isEmpty()){
		while (node != NULL){
			s.push(node);
			node = node->left;
		}
		node = s.peek();
		if (node->right != NULL && lastVisited != node->right){
			node = node->right;
		}
		else{
			lastVisited = node;
			cout << node->m_data << "  ";
			s.pop();
			node = NULL;
		}
	}
	cout << endl;
}
template <class T>
void BST<T>::levelOrder(){
	cout << "Binary Search Tree: " << "Size = " << m_size << endl;
	cout << "层序遍历：";
	LoopQueue<BTNode<T>*> q;
	q.enqueue(root);
	while (!q.isEmpty()){
		BTNode<T> *node = q.front();
		cout << node->m_data << "  ";
		q.dequeue();
		if (node->left != NULL){
			q.enqueue(node->left);
		}
		if (node->right != NULL){
			q.enqueue(node->right);
		}
	}
	cout << endl;
}

#endif