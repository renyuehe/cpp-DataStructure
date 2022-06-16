#ifndef __BSTMAP_H__
#define __BSTMAP_H__

#include "Map.h"
#include "MapBST.h"

template <class K, class V>
class BSTMap : public Map<K, V>{
public:
	int size(){
		return bst.size();
	}
	bool isEmpty(){
		return bst.isEmpty();
	}
	//增加操作
	void add(K key, V value){
		bst.add(key, value);
	}
	//删除操作
	V remove(K key){
		return bst.remove(key);
	}
	//修改操作
	void set(K key, V value){
		bst.set(key, value);
	}
	//查找操作
	bool contains(K key){
		return bst.contains(key);
	}
	V get(K key){
		return bst.get(key);
	}
private:
	MapBST<K, V> bst;
};

#endif