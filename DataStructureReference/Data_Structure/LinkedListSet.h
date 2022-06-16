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
	//增加操作
	void add(T num){
		if (!list.contains(num)){
			list.addFirst(num);
		}
	}
	//删除操作
	void remove(T num){
		while (list.contains(num)){
			list.removeElement(num);
		}
	}
	//查找操作
	bool contains(T num){
		return list.contains(num);
	}
private:
	LinkedList<T> list;
};

#endif
