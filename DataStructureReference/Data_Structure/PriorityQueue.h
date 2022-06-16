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
	//��Ӳ���
	void enqueue(T num){
		heap.add(num);
	}
	//���Ӳ���
	void dequeue(){
		heap.extractMax();
	}
	//��ö���Ԫ��
	T front(){
		return heap.findMax();
	}
private:
	MaxHeap<T> heap;
};

#endif