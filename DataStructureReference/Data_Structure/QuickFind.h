#ifndef __QUICKFIND_H__
#define __QUICKFIND_H__

#include "UnionFind.h"

class QuickFind : public UnionFind{
public:
	QuickFind(int size){
		m_data = new int[size];
		for (int i = 0; i < size; ++i){
			m_data[i] = i;
		}
		m_size = size;
	}
	int size(){
		return m_size;
	}
	bool isEmpty(){
		return m_size == 0;
	}
	void print(){
		cout << "QuickFind: " << "Size = " << m_size << endl;
		cout << '[';
		for (int i = 0; i < m_size; ++i){
			cout << m_data[i];
			if (i != m_size - 1){
				cout << ',';
			}
		}
		cout << ']' << endl;
	}
	//是否连接
	bool isConnected(int p, int q){
		return find(p) == find(q);
	}
	//联合元素
	void unionElements(int p, int q){
		if (p == q){
			return;
		}
		for (int i = 0; i < m_size; ++i){
			if (m_data[i] == m_data[q]){
				m_data[i] = m_data[p];
			}
		}
	}
private:
	int find(int index){
		if (index < 0 || index >= m_size){
			cout << "访问越界！" << endl;
			throw 0;
		}
		return m_data[index];
	}
private:
	int *m_data;
	int m_size;
};

#endif