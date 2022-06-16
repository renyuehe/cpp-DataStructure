#ifndef __LINKEDLISTQUEUE_H__
#define __LINKEDLISTQUEUE_H__

#include "Queue.h"

using namespace std;

template <class T>
class LinkedListQueue : public Queue<T>{
public:
	LinkedListQueue(){
		head = NULL;
		tail = NULL;
		m_size = 0;
	}
	int size(){
		return m_size;
	}
	bool isEmpty(){
		return m_size == 0;
	}
	void print(){
		Node<T> *node = head;
		cout << "LinkedListQueue: ";
		cout << "Size = " << m_size << endl;
		cout << "front ";
		while (node){
			cout << node->m_data << "->";
			node = node->next;
		}
		cout << "NULL rear" << endl;
	}
	//入队操作
	void enqueue(T num){
		if (head == NULL){
			head = new Node<T>(num, NULL);
			tail = head;
		}
		else{
			tail->next = new Node<T>(num, NULL);
			tail = tail->next;
		}
		m_size++;
	}
	//出队操作
	void dequeue(){
		if (m_size <= 0){
			cout << "出队失败！" << endl;
			return;
		}
		Node<T> *node = head->next;
		delete head;
		head = node;
		m_size--;
	}
	//获得队首元素
	T front(){
		if (m_size <= 0){
			cout << "队列为空！" << endl;
			return NULL;
		}
		return head->m_data;
	}
private:
	Node<T> *head;
	Node<T> *tail;
	int m_size;
};

#endif