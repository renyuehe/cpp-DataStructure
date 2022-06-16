
#include <iostream>
#include "CMap.h"

using namespace std;

void test01() {
    /*
        ͼ�Ĵ洢 �� ͼ�ı���
    */
    /*
          A
        /   \
       B      D
      / \    / \
     C   F  G �� H
     \  /
      E

    */

    /*

    ������ȱ�����A B C E F D G H
    ������ȱ�����A B D C F G F E


    �ڽӾ���
      A  B  C  D  E  F  G  H
    A     1     1
    B  1     1        1
    C     1        1  1
    D  1                 1  1
    E        1
    F     1  1
    G           1           1
    H           1        1

    */

    CMap* pMap = new CMap(8);

    Node* pNodeA = new Node('A');
    Node* pNodeB = new Node('B');
    Node* pNodeC = new Node('C');
    Node* pNodeD = new Node('D');
    Node* pNodeE = new Node('E');
    Node* pNodeF = new Node('F');
    Node* pNodeG = new Node('G');
    Node* pNodeH = new Node('H');

    pMap->addNode(pNodeA);
    pMap->addNode(pNodeB);
    pMap->addNode(pNodeC);
    pMap->addNode(pNodeD);
    pMap->addNode(pNodeE);
    pMap->addNode(pNodeF);
    pMap->addNode(pNodeG);
    pMap->addNode(pNodeH);

    pMap->setValueToMatrixForUndirectedGraph(0, 1);
    pMap->setValueToMatrixForUndirectedGraph(0, 3);
    pMap->setValueToMatrixForUndirectedGraph(1, 2);
    pMap->setValueToMatrixForUndirectedGraph(1, 5);
    pMap->setValueToMatrixForUndirectedGraph(3, 6);
    pMap->setValueToMatrixForUndirectedGraph(3, 7);
    pMap->setValueToMatrixForUndirectedGraph(6, 7);
    pMap->setValueToMatrixForUndirectedGraph(2, 4);
    pMap->setValueToMatrixForUndirectedGraph(4, 5);


    pMap->printMartrix();

    cout << endl;

    pMap->depthFirstTraverse(0);

    cout << endl;

    pMap->resetNode();

    pMap->breadthFirstTraverse(0);
    cin.get();
}

int main(void)
{
    test01();

    return 0;
}