#ifndef __AVLTREEMAP_H__
#define __AVLTREEMAP_H__

#include "Map.h"
#include "AVLTree.h"

template <class K, class V>
class AVLTreeMap : public Map<K, V>{
public:
	int size(){
		return avl.size();
	}
	bool isEmpty(){
		return avl.isEmpty();
	}
	//���Ӳ���
	void add(K key, V value){
		avl.add(key, value);
	}
	//ɾ������
	V remove(K key){
		V res = avl.get(key);
		avl.remove(key);
		return res;
	}
	//�޸Ĳ���
	void set(K key, V value){
		avl.add(key, value);
	}
	//���Ҳ���
	bool contains(K key){
		return avl.contains(key);
	}
	V get(K key){
		return avl.get(key);
	}
private:
	AVLTree<K, V> avl;
};

#endif