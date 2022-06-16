#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include "Array.h"
#include "Stack.h"

template <class T>
class ArrayStack : public Stack<T>{
public:
	ArrayStack(int len = initialLen){
		Array<T> *p= new Array<T>(len);
		arr = p;
	}
	int size(){
		return arr->size();
	}
	bool isEmpty(){
		return arr->size() == 0;
	}
	void print(){
		cout << "ArrayStack: ";
		cout << "Size = " << arr->size() << endl;
		cout << '[';
		for (int i = 0; i < arr->size(); ++i){
			cout << arr->get(i);
			if (i != arr->size() - 1){
				cout << ',';
			}
		}
		cout << "]top" << endl;
	}
	//��ջ����
	void push(T num){
		arr->addLast(num);
	}
	//��ջ����
	void pop(){
		arr->removeLast();
	}
	//���ջ��Ԫ��
	T peek(){
		return arr->get(arr->size() - 1);
	}
private:
	Array<T> *arr;
};

#endif