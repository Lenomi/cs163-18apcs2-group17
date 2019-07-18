#ifndef __TRIE_H__
#define __TRIE_H__

#include<iostream>
#include<string>
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
void insert_Node(struct TrieNode *root, string key)
{

	struct TrieNode* pCrawl = root;
	for (int level = 0; level < key.length(); level++)
	{
		int index = key[level] - 'a';
		if (pCrawl->children[index] == NULL)
			pCrawl->children[index] = createNode();
			pCrawl=pCrawl->children[index];
	}
	pCrawl->isEnd = true;
}

// serching a word 

bool search(struct TrieNode *root, const string key)
{
	int lenght = key.length();
	struct TrieNode *pCrawl = root;
	for (int level = 0; level < lenght; level++)
	{
		int index = key[level] - 'a';
		if (pCrawl->children[index] == NULL)
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isEnd);
}

bool isLastNode(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i]!=NULL)
			return 0;
	return 1;
}

void suggestionsRec(struct TrieNode * root, string currPrefix) {
	if (root->isEnd)
	{
		cout << currPrefix << endl;
		cout << endl;
	}
	if (isLastNode(root))
	{
		return;
	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			currPrefix.push_back(97 + i);
			suggestionsRec(root->children[i], currPrefix);
		}
	}
}

int AutoSuggestions(struct TrieNode *root, string query)
{
	struct TrieNode *pCrawl = root;
	int lenght = query.length();
	for (int level = 0; level < lenght; level++)
	{
		int index = query[level] - 'a';
		if (!pCrawl->children[index])
		{
			return 0;

		}
		pCrawl = pCrawl->children[index];
	}
	


	bool isWord = (pCrawl->isEnd == true);
	bool isEnd = isLastNode(pCrawl);

	if (isWord && isEnd)
	{
		cout << query << endl;
		return -1;
	}
	if (!isEnd)
	{

		suggestionsRec(pCrawl, query);
			return 1;
	}


}
#endif // !TRIE_H

