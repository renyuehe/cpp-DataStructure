#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class Queue{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	//��Ӳ���
	virtual void enqueue(T num) = 0;
	//���Ӳ���
	virtual void dequeue() = 0;
	//��ö���Ԫ��
	virtual T front() = 0;
};

#endif