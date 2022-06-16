
#ifndef CMAP_H_
#define CMAP_H_

//����vector��ģ�壬����ĺ���breadthFirstTraverseImpl(vector<int> preVec)���õ�

#include <vector>

#include "Node.h"

using namespace std;
class CMap
{
public:
	CMap(int capacity);           //���캯��������ͼ
	~CMap();                      //��������������ͼ
	bool addNode(Node* pNode);    //���ӽڵ�
	void resetNode();             //���ýڵ�ķ���״̬Ϊδ����
	   //������ͼ���ڽӾ����Ԫ������ֵ
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
	//������ͼ���ڽӾ����Ԫ������ֵ
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);

	void printMartrix();          //��ӡ�ڽӾ���

	void depthFirstTraverse(int nodeIndex);              //������ȱ���
	void breadthFirstTraverse(int nodeIndex);            //������ȱ���

private:
	bool getValueFromMatrix(int row, int col, int& val);   //��ȡ�ڽӾ�����Ԫ�ص�ֵ
	   //������ȱ����Ĺ��ߺ����������洢ĳһ���Ԫ��
	void breadthFirstTraverseImpl(vector<int> preVec);

private:
	int m_iCapacity;               //ͼ�Ľڵ������                                
	int m_iNodeCount;              //ͼ��ǰ�Ľڵ������
	Node* m_pNodeArray;            //ָ��ͼ���׽ڵ��ָ��
	int* m_pMatrix;                //ָ���ڽӾ�����Ԫ�ص�ָ��
};

#endif
