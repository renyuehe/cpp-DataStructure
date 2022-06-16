#ifndef __LINKEDLISTSET_H__
#define __LINKEDLISTSET_H__

#include "LinkedList.h"
#include "Set.h"

template <class T>
class LinkedListSet : public Set<T>{
public:
	int size(){
		return list.size();
	}
	bool isEmpty(){
		return list.isEmpty();
	}
	//���Ӳ���
	void add(T num){
		if (!list.contains(num)){
			list.addFirst(num);
		}
	}
	//ɾ������
	void remove(T num){
		while (list.contains(num)){
			list.removeElement(num);
		}
	}
	//���Ҳ���
	bool contains(T num){
		return list.contains(num);
	}
private:
	LinkedList<T> list;
};

#endif
