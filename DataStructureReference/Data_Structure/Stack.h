#ifndef __STACK_H__
#define __STACK_H__

template <class T>
class Stack{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	//入栈操作
	virtual void push(T num) = 0;
	//出栈操作
	virtual void pop() = 0;
	//获得栈顶元素
	virtual T peek() = 0;
};

#endif