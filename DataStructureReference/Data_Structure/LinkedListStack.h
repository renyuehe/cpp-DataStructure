#ifndef __LINKEDLISTSTACK_H__
#define __LINKEDLISTSTACK_H__

#include "LinkedList.h"
#include "Stack.h"

template <class T>
class LinkedListStack : public Stack<T>{
public:
	LinkedListStack(){}
	int size(){
		return list.size();
	}
	bool isEmpty(){
		return list.isEmpty();
	}
	void print(){
		cout << "LinkedListStack: ";
		cout << "Size = " << list.size() << endl;
		cout << "top ";
		for (int i = 0; i < list.size(); ++i){
			cout << list.get(i) << "->";
		}
		cout << "NULL" << endl;
	}
	//��ջ����
	void push(T num){
		list.addFirst(num);
	}
	//��ջ����
	void pop(){
		list.removeFirst();
	}
	//���ջ��Ԫ��
	T peek(){
		return list.get(0);
	}
private:
	LinkedList<T> list;
};

#endif