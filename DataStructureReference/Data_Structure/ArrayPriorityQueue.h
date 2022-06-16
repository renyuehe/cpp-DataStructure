#ifndef __ARRAYPRIORITYQUEUE_H__
#define __ARRAYPRIORITYQUEUE_H__

#include "Queue.h"
#include "Array.h"

template <class T>
class ArrayPriorityQueue{
public:
	int size(){
		return arr.size();
	}
	bool isEmpty(){
		return arr.isEmpty();
	}
	void print(){
		if (arr.isEmpty()){
			return;
		}
		cout << "ArrayPriorityQueue: ";
		cout << "Size = " << arr.size() << endl;
		cout << "front [";
		cout << arr.get(findMax()) << "...";
		cout << "] rear" << endl;
	}
	//��Ӳ���
	void enqueue(T num){
		arr.addLast(num);
	}
	//���Ӳ���
	void dequeue(){
		if (arr.isEmpty()){
			cout << "����ʧ�ܣ�" << endl;
			return;
		}
		arr.remove(findMax());
	}
	//��ö���Ԫ��
	T front(){
		return arr.get(findMax());
	}
private:
	int findMax(){
		int index = 0;
		for (int i = 0; i < arr.size(); ++i){
			if (arr.get(i) > arr.get(index)){
				index = i;
			}
		}
		return index;
	}
private:
	Array<T> arr;
};

#endif