#ifndef __SEGMENTTREE_H__
#define __SEGMENTTREE_H__

#include "Merger.h"

template <class T>
class MergerNew : Merger<T>{
public:
	T merger(T a, T b){
		return a + b;
	}
};
template <class T>
class SegmentTree{
public:
	SegmentTree(T *arr, int len){
		m_data = new T[len];
		for (int i = 0; i < len; ++i){
			m_data[i] = arr[i];
		}
		m_size = len;
		m_tree = new T[4 * len];
		m_treeSize = 0;
		buildSegmentTree(0, 0, m_size - 1);
	}
	int size() const {
		return m_treeSize;
	}
	bool isEmpty()const{
		return m_treeSize == 0;
	}
	void print() const {
		cout << "SegmentTree: " << "Size = " << m_treeSize << endl;
		cout << '[';
		for (int i = 0; i < m_treeSize; ++i){
			cout << m_tree[i];
			if (i != m_treeSize - 1){
				cout << ',';
			}
		}
		cout << ']' << endl;
	}
	T get(const int index) const{
		if (index < 0 || index >= m_size){
			cout << "访问越界！"
			throw 0;
		}
		return m_data[index];
	}
	T query(const int queryL, const int queryR) {
		if (queryL < 0 || queryL >= m_size || queryR < 0 || queryR >= m_size){
			cout << "访问越界！" << endl;
			throw 0;
		}
		return query(0, 0, m_size - 1, queryL, queryR);
	}
private:
	//返回完全二叉树中，一个结点左子结点的索引
	int leftChild(const int index) const {
		return 2 * index + 1;
	}
	//返回完全二叉树中，一个结点右子结点的索引
	int rightChild(const int index) const {
		return 2 * (index + 1);
	}
	//在treeIndex位置创建表示区间[left...right]的线段树
	void buildSegmentTree(const int treeIndex,const int left,const int right){
		m_treeSize++;
		if (left == right){
			m_tree[treeIndex] = m_data[left];
			return;
		}
		int leftTreeIndex = leftChild(treeIndex);
		int rightTreeIndex = rightChild(treeIndex);
		int mid = (left + right) / 2;
		buildSegmentTree(leftTreeIndex, left, mid);
		buildSegmentTree(rightTreeIndex, mid + 1, right);
		//以求和为例
		m_tree[treeIndex] = m.merger(m_tree[leftTreeIndex], m_tree[rightTreeIndex]);
	}
	T query(const int treeIndex,const int left,const int right,const int queryL,const int queryR) {
		if (left == queryL && right == queryR){
			return m_tree[treeIndex];
		}
		int leftTreeIndex = leftChild(treeIndex);
		int rightTreeIndex = rightChild(treeIndex);
		int mid = (left + right) / 2;
		if (queryL >= mid + 1){
			return query(rightTreeIndex, mid + 1, right, queryL, queryR);
		}
		else if (queryR <= mid){
			return query(leftTreeIndex, left, mid, queryL, queryR);
		}
		T leftRes = query(leftTreeIndex, left, mid, queryL, mid);
		T rightRes = query(rightTreeIndex, mid + 1, right, mid + 1, queryR);
		return m.merger(leftRes, rightRes);
	}
private:
	T *m_data;
	int m_size;
	T *m_tree;
	int m_treeSize;
	MergerNew<T> m;
};

#endif