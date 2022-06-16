#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

using namespace std;

template <class T>
class Node{
public:
	Node(T num = NULL, Node *next = NULL){
		m_data = num;
		this->next = next;
	}
public:
	T m_data;
	Node *next;
};
template <class T>
class LinkedList{
public:
	LinkedList(){
		head.m_data = NULL;
		head.next = NULL;
		m_size = 0;
	}
	int size(){
		return m_size;
	}
	bool isEmpty(){
		return m_size == 0;
	}
	void print(){
		cout << "LinkedList: ";
		cout << "Size = " << m_size << endl;
		Node<T> *node = head.next;
		while(node){
			cout << node->m_data << "->";
			node = node->next;
		}
		cout << "NULL" << endl;
	}
	//增加操作
	void add(int index, T num);
	void addFirst(T num);
	void addLast(T num);
	//删除操作
	T remove(int index);
	T removeFirst();
	T removeLast();
	void removeElement(T num);
	//修改操作
	void set(int index, T num);
	//查找操作
	T get(int index);
	T getFirst();
	T getLast();
	bool contains(T num);
private:
	Node<T> head;
	int m_size;
};

template <class T>
void LinkedList<T>::add(int index, T num){
	if (index < 0 || index > m_size){
		cout << "添加位置非法！" << endl;
		return;
	}
	Node<T> *node = &head;
	for (int i = 0; i < index; ++i, node = node->next);
	node->next = new Node<T>(num, node->next);
	m_size++;
}
template <class T>
void LinkedList<T>::addFirst(T num){
	add(0, num);
}
template <class T>
void LinkedList<T>::addLast(T num){
	add(m_size, num);
}

template <class T>
T LinkedList<T>::remove(int index){
	if (index < 0 || index >= m_size){
		cout << "删除位置非法！" << endl;
		return NULL;
	}
	Node<T> *node = &head;
	for (int i = 0; i < index; ++i, node = node->next);
	Node<T> *p = node->next;
	T res = p->m_data;
	node->next = p->next;
	delete p;
	m_size--;
	return res;
}
template <class T>
T LinkedList<T>::removeFirst(){
	return remove(0);
}
template <class T>
T LinkedList<T>::removeLast(){
	return remove(m_size - 1);
}
template <class T>
void LinkedList<T>::removeElement(T num){
	if (!head.next){
		return;
	}
	Node<T> *node = &head;
	Node<T> *p;
	while(node){
		p = node->next;
		if (p->m_data == num){
			node->next = p->next;
			delete p;
			m_size--;
			return;
		}
		node = p;
	}
}

template <class T>
void LinkedList<T>::set(int index, T num){
	Node<T> *node = head.next;
	for (int i = 0; i < index; ++i, node = node->next);
	node->m_data = num;
}

template <class T>
T LinkedList<T>::get(int index){
	if (index < 0 || index >= m_size){
		cout << "访问位置非法！" << endl;
		return NULL;
	}
	Node<T> *node = head.next;
	for (int i = 0; i < index; ++i, node = node->next);
	return node->m_data;
}

template <class T>
T LinkedList<T>::getFirst(){
	return get(0);
}
template <class T>
T LinkedList<T>::getLast(){
	return get(m_size - 1);
}
template <class T>
bool LinkedList<T>::contains(T num){
	Node<T> *node = head.next;
	while(node){
		if (node->m_data == num){
			return true;
		}
		node = node->next;
	}
	return false;
}

#endif