#include"Trie.h"

void insert_Node(struct TrieNode *root, string key)
{

	struct TrieNode* pCrawl = root;
	for (int level = 0; level < key.length(); level++)
	{
		int index;
		if (key[level] >= 97) index = key[level] - 'a';
		else if (key[level] <= 57 && key[level] >= 48) index = key[level] - 22;
		if (pCrawl->children[index] == NULL)
			pCrawl->children[index] = createNode();
		pCrawl = pCrawl->children[index];
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
		int index;
		if (key[level] >= 97) index = key[level] - 'a';
		else if (key[level] <= 57 && key[level] >= 48) index = key[level] - 22;
		else
		{

		}
		if (pCrawl->children[index] == NULL)
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isEnd);
}

bool isLastNode(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i] != NULL)
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
		int index;
		if (query[level] >= 97)
			index = query[level] - 'a';
		else if (query[level] <= 57 && query[level] >= 48) 
			index = query[level] - 22;
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
