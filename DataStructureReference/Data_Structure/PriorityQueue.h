#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include "Queue.h"
#include "MaxHeap.h"

template <class T>
class PriorityQueue{
public:
	int size(){
		return heap.size();
	}
	bool isEmpty(){
		return heap.isEmpty();
	}
	void print(){
		if (heap.isEmpty()){
			return;
		}
		cout << "PriorityQueue: ";
		cout << "Size = " << heap.size() << endl;
		cout << "front [";
		cout << heap.findMax() << "...";
		cout << "] rear" << endl;
	}
	//入队操作
	void enqueue(T num){
		heap.add(num);
	}
	//出队操作
	void dequeue(){
		heap.extractMax();
	}
	//获得队首元素
	T front(){
		return heap.findMax();
	}
private:
	MaxHeap<T> heap;
};

#endif