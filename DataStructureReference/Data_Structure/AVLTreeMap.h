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
	//增加操作
	void add(K key, V value){
		avl.add(key, value);
	}
	//删除操作
	V remove(K key){
		V res = avl.get(key);
		avl.remove(key);
		return res;
	}
	//修改操作
	void set(K key, V value){
		avl.add(key, value);
	}
	//查找操作
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