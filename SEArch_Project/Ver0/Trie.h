#ifndef __TRIE_H__
#define __TRIE_H__

#include<iostream>
#include<string>
#include<queue>
#include<cctype>
#include<fstream>
using namespace std;

const int ALPHABET_SIZE = 36;

//trie node
struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];
	//isendofword is true if the node present the end a of word 
	bool isEnd;
	string key;
};

//creat new trie node
TrieNode* createNode();

// insert a key into trie tree
void Insersion(struct TrieNode *root, string key);
bool search(struct TrieNode *root, const string key);
bool isLastNode(struct TrieNode* root);
void suggestionsRec(struct TrieNode * root, string currPrefix);
int AutoSuggestions(struct TrieNode *root, string query);
bool find_slot(int &index, int level, string key);









#endif // !TRIE_H