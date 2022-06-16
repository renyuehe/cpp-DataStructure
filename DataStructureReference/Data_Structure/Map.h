#ifndef __MAP_H__
#define __MAP_H__

template <class K, class V>
class Map{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	//���Ӳ���
	virtual void add(K key, V value) = 0;
	//ɾ������
	virtual V remove(K key) = 0;
	//�޸Ĳ���
	virtual void set(K key, V value) = 0;
	//���Ҳ���
	virtual bool contains(K key) = 0;
	virtual V get(K key) = 0;
};

#endif