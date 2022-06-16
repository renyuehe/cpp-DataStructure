#ifndef __BSTSET_H__
#define __BSTSET_H__

#include "BST.h"
#include "Set.h"

template <class T>
class BSTSet : public Set<T>{
public:
	int size(){
		return bst.size();
	}
	bool isEmpty(){
		return bst.isEmpty();
	}
	//增加操作
	void add(T num){
		bst.add(num);
	}
	//删除操作
	void remove(T num){
		bst.remove(num);
	}
	//查找操作
	bool contains(T num){
		return bst.contains(num);
	}
private:
	BST<T> bst;
};

#endif