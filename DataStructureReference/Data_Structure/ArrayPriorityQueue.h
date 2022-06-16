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
	//入队操作
	void enqueue(T num){
		arr.addLast(num);
	}
	//出队操作
	void dequeue(){
		if (arr.isEmpty()){
			cout << "出队失败！" << endl;
			return;
		}
		arr.remove(findMax());
	}
	//获得队首元素
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