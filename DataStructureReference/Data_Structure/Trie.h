#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
#include "BSTMap.h"

class TrieNode{
public:
	TrieNode(bool isWord = false){
		this->isWord = isWord;
		BSTMap<char, TrieNode*> *p = new BSTMap<char, TrieNode*>; 
		next = p;
	}
	TrieNode operator= (TrieNode& node){
		this->isWord = node.isWord;
		this->next = node.next;
		return *this;
	}
public:
	bool isWord;
	BSTMap<char, TrieNode*> *next;
};

class Trie{
public:
	Trie(){
		m_size = 0;
	}
	int size()const{
		return m_size;
	}
	bool isEmpty()const{
		return m_size == 0;
	}
	void add(std::string word){
		TrieNode* cur = &root;
		for (int i = 0; i < word.size(); ++i){
			char c = word[i];
			if (!cur->next->contains(c)){
				TrieNode* node = new TrieNode;
				cur->next->add(c, node);
			}
			cur = cur->next->get(c);
		}
		if (!cur->isWord){
			cur->isWord = true;
			m_size++;
		}
	}
	bool contains(std::string word){
		TrieNode* cur = &root;
		for (int i = 0; i < word.size(); ++i){
			char c = word[i];
			if (!cur->next->contains(c)){
				return false;
			}
			cur = cur->next->get(c);
		}
		return cur->isWord;
	}
	bool isPrefix(string prefix){
		TrieNode *cur = &root;
		for (int i = 0; i < prefix.size(); ++i){
			char c = prefix[i];
			if (!cur->next->contains(c)){
				return false;
			}
			cur = cur->next->get(c);
		}
		return true;
	}
private:
	TrieNode root;
	int m_size;
};
#endif