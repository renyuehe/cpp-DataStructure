#ifndef __STACK_H__
#define __STACK_H__

template <class T>
class Stack{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	//��ջ����
	virtual void push(T num) = 0;
	//��ջ����
	virtual void pop() = 0;
	//���ջ��Ԫ��
	virtual T peek() = 0;
};

#endif