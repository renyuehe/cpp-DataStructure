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
	//��Ӳ���
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
	//���Ӳ���
	void dequeue(){
		if (m_size <= 0){
			cout << "����ʧ�ܣ�" << endl;
			return;
		}
		Node<T> *node = head->next;
		delete head;
		head = node;
		m_size--;
	}
	//��ö���Ԫ��
	T front(){
		if (m_size <= 0){
			cout << "����Ϊ�գ�" << endl;
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