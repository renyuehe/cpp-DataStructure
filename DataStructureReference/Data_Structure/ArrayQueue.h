#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include "Array.h"
#include "Queue.h"

template <class T>
class ArrayQueue : public Queue<T>{
public:
	ArrayQueue(int len = initialLen){
		Array<T> *p = new Array<T>(len);
		arr = p;
	}
	int size(){
		return arr->size();
	}
	bool isEmpty(){
		return arr->size() == 0;
	}
	void print(){
		cout << "ArrayQueue: ";
		cout << "Size = " << arr->size() << endl;
		cout << "front[";
		for (int i = 0; i < arr->size(); ++i){
			cout << arr->get(i);
			if (i != arr->size() - 1){
				cout << ',';
			}
		}
		cout << "]rear" << endl;
	}
	//��Ӳ���
	void enqueue(T num){
		arr->addLast(num);
	}
	//���Ӳ���
	void dequeue(){
		arr->removeFirst();
	}
	//��ö���Ԫ��
	T front(){
		return arr->get(0);
	}
private:
	Array<T> *arr;
};

#endif