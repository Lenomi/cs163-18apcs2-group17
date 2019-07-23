#include"Trie.h"

void Insersion(struct TrieNode *root, string key)
{

	struct TrieNode* pCrawl = root;
	for (int level = 0; level < key.length(); level++)
	{
		int index;
		if (find_slot(index,level,key)) {
			if (pCrawl->children[index] == NULL)
				pCrawl->children[index] = createNode();
			pCrawl = pCrawl->children[index];
		}
	}
	pCrawl->isEnd = true;
	pCrawl->key = key;
}
TrieNode* createNode() //problem ?
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isEnd = NULL;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;
	return pNode;
}

// serching a word 

bool search(struct TrieNode *root, const string key)
{
	int lenght = key.length();
	struct TrieNode *pCrawl = root;
	for (int level = 0; level < lenght; level++)
	{
		int index;
		if (find_slot(index, level, key)) {
			if (pCrawl->children[index] == NULL)
				return false;
			pCrawl = pCrawl->children[index];
		}
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
		if (find_slot(index, level, query) && !pCrawl->children[index])//problem ?
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

bool find_slot(int &index,int level, string key) {
	if (key[level] >= 97 && key[level] <= 122) {
		index = key[level] - 'a';
		return true;
	}
	else if (key[level] >= 65 && key[level] <= 90) {
		index = key[level] - 'A';
		return true;
	}
	else if (key[level] <= 57 && key[level] >= 48) {
		index = key[level] - 22;
		return true;
	}
	return false;
}

void save_result(string file_name, string keyword) {
	ofstream fout;
	fout.open(keyword + ".txt",ios::app);
	fout << file_name + ".txt\n";
	fout.close();
}

