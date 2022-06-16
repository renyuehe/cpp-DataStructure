#ifndef __QUICKUNION_H__
#define __QUICKUNION_H__

#include "UnionFind.h"

class QuickUnion : public UnionFind{
public:
	QuickUnion(int size){
		m_data = new int[size];
		//m_num = new int[size];
		m_rank = new int[size];
		for (int i = 0; i < size; ++i){
			//每个结点指向自己
			m_data[i] = i;
			//m_num[i] = 1;
			m_rank[i] = 1;
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
		cout << "QuickUnion: " << "Size = " << m_size << endl;
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
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot){
			return;
		}
		/*
		if (m_num[pRoot] > m_num[qRoot]){
			m_data[qRoot] = pRoot;
			m_num[pRoot] += m_num[qRoot];
		}
		else{
			m_data[pRoot] = qRoot;
			m_num[qRoot] += m_num[pRoot];
		}
		*/
		if (m_rank[pRoot] > m_rank[qRoot]){
			m_data[qRoot] = pRoot;
		}
		else if (m_rank[pRoot] > m_rank[qRoot]){
			m_data[pRoot] = qRoot;
		}
		else{
			m_data[qRoot] = pRoot;
			m_rank[pRoot] = m_rank[qRoot] + 1;
		}
	}
private:
	int find(int index){
		if (index < 0 || index >= m_size){
			cout << "访问越界！" << endl;
			throw 0;
		}
		while (index != m_data[index]){
			m_data[index] = m_data[m_data[index]];
			index = m_data[index];
		}
		return index;
	}
private:
	int *m_data;
	int m_size;
	//int *m_num;  //以i为根的树结点个数
	int *m_rank;  //结点的高度
};

#endif