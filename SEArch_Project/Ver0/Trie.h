#ifndef __TRIE_H__
#define __TRIE_H__

#include<iostream>
#include<string>
#include <queue>
using namespace std;

const int ALPHABET_SIZE = 26;

//trie node
struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];
	//isendofword is true if the node present the end a of word 
	bool isEnd;
};

//creat new trie node
struct TrieNode *createNode()
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isEnd = NULL;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

// insert a key into trie tree

#endif // !TRIE_H