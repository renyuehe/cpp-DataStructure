#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include "Array.h"

template <class T>
class MaxHeap{
public:
	int size(){
		return arr.size();
	}
	bool isEmpty(){
		return arr.isEmpty();
	}
	void add(T num){
		arr.addLast(num);
		siftUp(arr.size() - 1);
	}
	T findMax(){
		if (arr.size() == 0){
			cout << "¶þ²æ¶ÑÎª¿Õ£¡" << endl;
			return NULL;
		}
		return arr.get(0);
	}
	T extractMax(){
		T res = findMax();
		swap(0, arr.size() - 1);
		arr.removeLast();
		siftDown(0);
		return res;
	}
private:
	int parent(int index){
		if (index <= 0 || index >= arr.size()){
			return NULL;
		}
		return (index - 1) / 2;
	}
	int leftChild(int index){
		return index * 2 + 1;
	}
	int rightChild(int index){
		return (index + 1) * 2;
	}
	void swap(int i, int j){
		if (i < 0 || i >= arr.size() || j < 0 || j >= arr.size()){
			return;
		}
		T t = arr.get(i);
		arr.set(i, arr.get(j));
		arr.set(j, t);
	}
	void siftUp(int index){
		while (index && arr.get(index) > arr.get(parent(index))){
			swap(index, parent(index));
			index = parent(index);
		}
	}
	void siftDown(int index){
		while (leftChild(index) < arr.size()){
			int left = leftChild(index);
			if (left + 1 < arr.size() && arr.get(left + 1) > arr.get(left)){
				left++;
			}
			if (arr.get(index) >= arr.get(left)){
				break;
			}
			swap(index, left);
			index = left;
		}
	}
private:
	Array<T> arr;
};

#endif