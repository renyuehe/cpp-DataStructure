#ifndef __LINKEDLISTPRIORITYQUEUE_H__
#define __LINKEDLISTPRIORITYQUEUE_H__

#include "Queue.h"
#include "LinkedList.h"

template <class T>
class LinkedListPriorityQueue{
public:
	int size(){
		return list.size();
	}
	bool isEmpty(){
		return list.isEmpty();
	}
	void print(){
		if (list.isEmpty()){
			return;
		}
		cout << "LinkedListPriorityQueue: ";
		cout << "Size = " << list.size() << endl;
		cout << "front [";
		cout << list.get(findMax()) << "...";
		cout << "] rear" << endl;
	}
	//��Ӳ���
	void enqueue(T num){
		list.addFirst(num);
	}
	//���Ӳ���
	void dequeue(){
		if (list.isEmpty()){
			cout << "����ʧ�ܣ�" << endl;
			return;
		}
		list.remove(findMax());
	}
	//��ö���Ԫ��
	T front(){
		return list.getFirst();
	}
private:
	int findMax(){
		int index = 0;
		for (int i = 0; i < list.size(); ++i){
			if (list.get(i) > list.get(index)){
				index = i;
			}
		}
		return index;
	}
private:
	LinkedList<T> list;
};

#endif