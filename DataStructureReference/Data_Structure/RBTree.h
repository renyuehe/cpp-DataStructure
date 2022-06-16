#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

//颜色
enum Colour
{
	RED,
	BLACK,
};
template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{
	}

	void _Destory(Node*& root)
	{
		if (root == nullptr)
			return;

		_Destory(root->_left);
		_Destory(root->_right);

		delete root;
		root = nullptr;
	}
	~RBTree()
	{
		_Destory(_root);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		//空树的情况
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		//查找位置插入节点
		Node* cur = _root, * parent = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		//创建链接节点
		cur = new Node(kv);
		Node* newnode = cur;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		//父节点存在且为红，则需要调整（不能存在连续的红色节点）
		while (parent && parent->_col == RED)
		{
			//此时当前节点一定有祖父节点
			Node* granparent = parent->_parent;
			//具体调整情况主要看叔叔节点
			//分左右讨论
			if (parent == granparent->_left)
			{
				Node* uncle = granparent->_right;
				//情况1：叔叔节点存在且为红
				if (uncle && uncle->_col == RED)
				{
					//修改颜色，继续向上检查
					granparent->_col = RED;
					parent->_col = uncle->_col = BLACK;

					cur = granparent;
					parent = cur->_parent;
				}
				else//情况2和3：叔叔节点不存在 或者存在且为黑
				{
					//单旋(三代节点为斜线)+变色
					if (cur == parent->_left)
					{
						RotateR(granparent);

						granparent->_col = RED;
						parent->_col = BLACK;
					}
					else//双旋(三代节点为折线)+变色
					{
						RotateL(parent);
						RotateR(granparent);

						cur->_col = BLACK;
						granparent->_col = RED;
					}
					//旋转后不需再向上调整了
					break;
				}
			}
			else//parent=grandparent->right
			{
				Node* uncle = granparent->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					granparent->_col = RED;

					cur = granparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(granparent);

						parent->_col = BLACK;
						granparent->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(granparent);

						cur->_col = BLACK;
						granparent->_col = RED;
					}
					break;
				}
			}
		}

		//确保根节点为黑
		_root->_col = BLACK;
		return make_pair(newnode, true);
	}

	bool IsRBTree()
	{
		if (_root == nullptr)
		{
			return true;
		}

		if (_root->_col == RED)
		{
			cout << "根节点为红色" << endl;
			return false;
		}

		int Blacknum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				Blacknum++;
			cur = cur->_left;
		}

		int i = 0;
		return _IsRBTree(_root, Blacknum, i);
	}

private:
	bool _IsRBTree(Node* root, int blacknum, int count)
	{
		if (root == nullptr)
		{
			if (blacknum == count)
				return true;
			cout << "各路径上黑色节点个数不同" << endl;
			return false;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "存在连续红色节点" << endl;
			return false;
		}

		if (root->_col == BLACK)
			count++;

		return _IsRBTree(root->_left, blacknum, count) && _IsRBTree(root->_right, blacknum, count);
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* parentP = parent->_parent;


		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			subR->_parent = parentP;
			if (parentP->_left == parent)
			{
				parentP->_left = subR;
			}
			else
			{
				parentP->_right = subR;
			}
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* parentP = parent->_parent;


		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			subL->_parent = parentP;
			if (parentP->_left == parent)
			{
				parentP->_left = subL;
			}
			else
			{
				parentP->_right = subL;
			}
		}
	}

private:
	Node* _root;
};
