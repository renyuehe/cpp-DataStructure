#ifndef __SET_H__
#define __SET_H__

template <class T>
class Set{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	//���Ӳ���
	virtual void add(T num) = 0;
	//ɾ������
	virtual void remove(T num) = 0;
	//���Ҳ���
	virtual bool contains(T num) = 0;
};

#endif