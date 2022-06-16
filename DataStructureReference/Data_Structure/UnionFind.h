#ifndef __UNIONFIND_H__
#define __UNIONFIND_H__

class UnionFind{
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	//�Ƿ�����
	virtual bool isConnected(int p, int q) = 0;
	//����Ԫ��
	virtual void unionElements(int p, int q) = 0;
};

#endif