#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__

#include "Queue.h"

using namespace std;

template <class T>
class LoopQueue : public Queue<T>{
public:
	LoopQueue(int len = initialLen){
		T *p = new T[len];
		m_data = p;
		m_capacity = len;
		m_size = m_front = m_rear = 0;
	}
	int size(){
		return m_size;
	}
	void resize(int len){
		T *p = new T[len];
		if (m_size == 0){}
		else{
			for (int i = 0; i < m_size; ++i){
				p[i] = m_data[(i + m_front) % m_capacity];
			}
		}
		delete[] m_data;
		m_data = p;
		m_capacity = len;
		m_front = 0;
		m_rear = m_size;
	}
	bool isEmpty(){
		return m_size == 0;
	}
	void print(){
		cout << "LoopQueue: ";
		cout << "Size = " << m_size << endl;
		cout << "front[";
		if (m_size == 0){}
		else{
			for (int i = 0; i < m_size; ++i){
				cout << m_data[(i + m_front) % m_capacity];
				if (i != m_size - 1){
					cout << ',';
				}
			}
		}
		cout << "]rear" << endl;
	}
	//入队操作
	void enqueue(T num){
		if (m_size >= m_capacity){
			resize(2 * m_capacity);
		}
		m_data[m_rear] = num;
		m_size++;
		m_rear = (m_rear + 1) % m_capacity;
	}
	//出队操作
	void dequeue(){
		if (m_size <= 0){
			cout << "队列为空，出队操作失败！" << endl;
			return;
		}
		if (m_size <= m_capacity / 4){
			resize(m_capacity / 2);
		}
		m_size--;
		m_front = (m_front + 1) % m_capacity;
	}
	//获得队首元素
	T front(){
		if (m_size <= 0){
			cout << "队列为空，操作失败！" << endl;
			return NULL;
		}
		return m_data[m_front];
	}
private:
	T *m_data;
	int m_capacity;
	int m_size;
	int m_front;
	int m_rear;
};

#endif