#ifndef __MAP_H__
#define __MAP_H__

template <class K, class V>
class Map{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	//增加操作
	virtual void add(K key, V value) = 0;
	//删除操作
	virtual V remove(K key) = 0;
	//修改操作
	virtual void set(K key, V value) = 0;
	//查找操作
	virtual bool contains(K key) = 0;
	virtual V get(K key) = 0;
};

#endif