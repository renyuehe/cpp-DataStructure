#ifndef __UNIONFIND_H__
#define __UNIONFIND_H__

class UnionFind{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	//是否连接
	virtual bool isConnected(int p, int q) = 0;
	//联合元素
	virtual void unionElements(int p, int q) = 0;
};

#endif