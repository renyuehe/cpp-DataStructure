#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"
#include "LinkedList.h"
#include "LinkedListStack.h"
#include "LinkedListQueue.h"
#include "BST.h"
#include "BSTSet.h"
#include "LinkedListSet.h"
#include "LinkedListMap.h"
#include "BSTMap.h"
#include "MaxHeap.h"
#include "PriorityQueue.h"
#include "ArrayPriorityQueue.h"
#include "LinkedListPriorityQueue.h"
#include "SegmentTree.h"
#include "Trie.h"
#include "QuickFind.h"
#include "QuickUnion.h"
#include "AVLTree.h"
#include "AVLTreeMap.h"
#include "RBTree.h"

using namespace std;

void test01(){
	Array<int> arr;
	for (int i = 0; i < 10; ++i){
		arr.addLast(i);
	}
	arr.print();
	arr.set(2, 8);
	arr.print();
	arr.addFirst(10);
	arr.add(3, 4);
	arr.add(-1, 4);
	arr.print();
	for (int i = 0; i < 8; ++i){
		arr.remove(2);
	}
	arr.remove(11);
	arr.print();
	cout << arr.get(2) << endl;
	cout << arr.get(8) << endl;
	cout << arr.find(8) << '\t' << arr.contains(8) << endl;
	cout << arr.find(2) << '\t' << arr.contains(2) << endl;
}
void test02(){
	ArrayStack<int> s;
	for (int i = 0; i < 10; ++i){
		s.push(i);
	}
	s.print();
	for (int i = 0; i < 8; ++i){
		s.pop();
	}
	s.print();
	cout << s.peek() << endl;
}
void test03(){
	ArrayQueue<int> q;
	for (int i = 0; i < 10; ++i){
		q.enqueue(i);
	}
	q.print();
	for (int i = 0; i < 8; ++i){
		q.dequeue();
	}
	q.print();
	cout << q.front() << endl;
}
void test04(){
	LoopQueue<int> q;
	for (int i = 0; i < 12; ++i){
		q.enqueue(i);
	}
	q.print();
	for (int i = 0; i < 8; ++i){
		q.dequeue();
	}
	q.print();
	for (int i = 0; i < 5; ++i){
		q.enqueue(i);
	}
	q.print();
	cout << q.front() << endl;
}
void test05(){
	LinkedList<int> list;
	for (int i = 0; i < 10; ++i){
		list.add(i, i);
	}
	list.add(12, 10);
	list.print();
	list.addFirst(9);
	list.addLast(10);
	list.print();
	for (int i = 0; i < 5; ++i){
		list.remove(0);
	}
	list.removeFirst();
	list.removeLast();
	list.print();
	list.removeElement(7);
	list.print();
	list.set(0, 9);
	list.print();
	cout << list.get(1) << '\t' << list.contains(6) << endl;
}
void test06(){
	LinkedListStack<int> s;
	for (int i = 0; i < 10; ++i){
		s.push(i);
	}
	s.print();
	for (int i = 0; i < 5; ++i){
		s.pop();
	}
	s.print();
	cout << s.peek() << endl;
}
void test07(){
	LinkedListQueue<int> q;
	for (int i = 0; i < 10; ++i){
		q.enqueue(i);
	}
	q.print();
	for (int i = 0; i < 5; ++i){
		q.dequeue();
	}
	q.print();
	cout << q.front() << endl;
}
void test08(){
	BST<int> bst;
	int a[] = { 5, 2, 7, 1, 4, 6, 8, 7, 1, 4, 1, 4, 6, 8, 7, 7 };
	for (int i = 0; i < 16; ++i){
		bst.add(a[i]);
	}
	bst.add(3);
	bst.add(9);
	bst.preOrder();
	bst.preOrderNR();
	bst.inOrder();
	bst.inOrderNR();
	bst.postOrder();
	bst.postOrderNR();
	bst.levelOrder();
	bst.remove(4);
	bst.remove(8);
	bst.remove(8);
	bst.preOrder();
	bst.remove(2);
	bst.preOrder();
	cout << bst.contains(7) << endl;
}
void test09(){
	BSTSet<char> s;
	string str = "aajhfiouwoernfjdahfuafj";
	for (int i = 0; i < str.size(); ++i){
		s.add(str[i]);
	}
	cout << s.size() << endl;
	for (int i = 0; i < str.size() / 2; ++i){
		s.remove(str[i]);
	}
	cout << s.size() << endl;
}
void test10(){
	LinkedListSet<char> s;
	string str = "aajhfiouwoernfjdahfuafj";
	for (int i = 0; i < str.size(); ++i){
		s.add(str[i]);
	}
	cout << s.size() << endl;
	for (int i = 0; i < str.size() / 2; ++i){
		s.remove(str[i]);
	}
	cout << s.size() << endl;
}
void test11(){
	LinkedListMap<int, char> m;
	m.add(1, 'a');
	m.add(2, 'b');
	m.add(3, 'c');
	m.add(4, 'd');
	m.add(5, 'e');
	cout << m.contains(2) << '\t' << m.get(2) << endl;
	m.set(2, 'g');
	cout << m.size() << '\t' << m.get(2) << endl;
}
void test12(){
	BSTMap<int, int> m;
	m.add(1, 1);
	cout << m.contains(1) << m.get(1) << m.isEmpty() << m.size() << endl;
	m.set(1, 2);
	cout << m.get(1) << endl;
	cout << m.remove(1);
}
void test13(){
	MaxHeap<int> h;
	srand(time(0));
	for (int i = 0; i < 100; ++i){
		h.add(rand() % 100);
	}
	for (int i = 0; i < 100; ++i){
		cout << h.extractMax() << endl;
	}
}
void test14(){
	PriorityQueue<int> q;
	srand(time(0));
	for (int i = 0; i < 100; ++i){
		q.enqueue(rand() % 100);
	}
	for (int i = 0; i < 100; ++i){
		q.print(); 
		q.dequeue();
	}
}
void test15(){
	ArrayPriorityQueue<int> q;
	srand(time(0));
	for (int i = 0; i < 100; ++i){
		q.enqueue(rand() % 100);
	}
	for (int i = 0; i < 100; ++i){
		q.print();
		q.dequeue();
	}
}
void test16(){
	LinkedListPriorityQueue<int> q;
	srand(time(0));
	for (int i = 0; i < 100; ++i){
		q.enqueue(rand() % 100);
	}
	for (int i = 0; i < 100; ++i){
		q.print();
		q.dequeue();
	}
}
void test17(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
	SegmentTree<int> seg(a, 9);
	seg.print();
	cout << seg.query(1, 5) << endl;
}
void test18(){
	Trie trie;
	trie.add("chinese");
	trie.add("china");
	trie.add("hello");
	trie.add("English");
	trie.add("chinese");
	cout << trie.size() << endl;
	cout << trie.contains("chinaf") << endl;
	cout << trie.contains("china") << endl;
	cout << trie.isPrefix("ch") << endl;
	cout << trie.isPrefix("Eng") << endl;
}
void test19(){
	QuickFind qf(10);
	QuickUnion qu(10);
	qf.print();
	cout << qf.isConnected(6, 9) << endl;
	qf.unionElements(1, 2);
	qf.unionElements(2, 6);
	qf.unionElements(2, 9);
	cout << qf.isConnected(6, 9) << endl;
	qf.print();
	qu.print();
	cout << qu.isConnected(6, 9) << endl;
	qu.unionElements(1, 2);
	qu.unionElements(2, 6);
	qu.unionElements(2, 9);
	cout << qu.isConnected(6, 9) << endl;
	qu.print();
}
void test20(){
	AVLTree<int, int> avl;
	BST<int> tree;
	const int n = 50;
	int a[n];
	srand(time(0));
	for (int i = 0; i < n; ++i){
		a[i] = rand() % 100;
		avl.add(a[i], 0);
	}
	avl.inOrder();
	for (int i = 0; i < 10; ++i){
		avl.remove(i);
	}
	avl.inOrder();
	cout << avl.get(13) << endl;
	cout << avl.get(101) << endl;
	AVLTreeMap<int, int> m;
	for (int i = 0; i < n; ++i){
		a[i] = rand() % 100;
		m.add(i, a[i]);
	}
	cout << m.remove(6) << endl;
	cout << m.remove(6) << endl;
}

void TestRBTree()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t;
	int n = 1000000;
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		int e = rand();
		t.Insert(make_pair(e, e));
	}

	//t.InOrder();
	cout << t.IsRBTree() << endl;
}
void TestRBTree2()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));

	}
	cout << t.IsRBTree() << endl;
}
int main(){


	TestRBTree();
	
	
	return 0;
}