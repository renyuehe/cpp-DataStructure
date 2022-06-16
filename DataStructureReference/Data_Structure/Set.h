#ifndef __SET_H__
#define __SET_H__

template <class T>
class Set{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	//增加操作
	virtual void add(T num) = 0;
	//删除操作
	virtual void remove(T num) = 0;
	//查找操作
	virtual bool contains(T num) = 0;
};

#endif