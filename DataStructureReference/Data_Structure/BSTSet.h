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
	//���Ӳ���
	void add(T num){
		bst.add(num);
	}
	//ɾ������
	void remove(T num){
		bst.remove(num);
	}
	//���Ҳ���
	bool contains(T num){
		return bst.contains(num);
	}
private:
	BST<T> bst;
};

#endif