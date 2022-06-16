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
	//入栈操作
	void push(T num){
		list.addFirst(num);
	}
	//出栈操作
	void pop(){
		list.removeFirst();
	}
	//获得栈顶元素
	T peek(){
		return list.get(0);
	}
private:
	LinkedList<T> list;
};

#endif