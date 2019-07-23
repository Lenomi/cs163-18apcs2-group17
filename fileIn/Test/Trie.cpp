#include "header.h"

void File::insert_Node(string key)
{
	if (root2 == nullptr)
	{
		root2 = new TrieNode;
		root2->isEnd = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			root2->children[i] = nullptr;
	}
	TrieNode* pCrawl = root2;
	for (int level = 0; level < key.length(); level++)
	{
		int index;
		if (find_slot(index, level, key)) {
			if (pCrawl->children[index] == nullptr)
			{
				pCrawl->children[index] = new TrieNode;
				pCrawl->children[index]->isEnd = false;
				for (int i = 0; i < ALPHABET_SIZE; i++)
					pCrawl->children[index]->children[i] = nullptr;
			}
			pCrawl = pCrawl->children[index];
		}
	}
	pCrawl->isEnd = true;
	pCrawl->key = key;
}
// serching a word 

bool File::search(const string key)
{
	int lenght = key.length();
	TrieNode *pCrawl = root2;
	for (int level = 0; level < lenght; level++)
	{
		int index;
		if (find_slot(index, level, key)) {
			if (pCrawl->children[index] == nullptr)
				return false;
			pCrawl = pCrawl->children[index];
		}
	}
	return (pCrawl != nullptr && pCrawl->isEnd);
}

bool File::isLastNode(TrieNode* root2)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root2->children[i] != nullptr)
			return 0;
	return 1;
}

void File::suggestionsRec(TrieNode * root2,string currPrefix) {
	if (root2->isEnd)
	{
		cout << currPrefix << endl;
		cout << endl;
	}
	if (isLastNode(root2))
	{
		return;
	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root2->children[i])
		{
			currPrefix.push_back(97 + i);
			suggestionsRec(root2->children[i], currPrefix);
		}
	}
}

int File::AutoSuggestions(string query)
{
	TrieNode *pCrawl = root2;
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

bool File::find_slot(int &index, int level, string key) {
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
	fout.open(keyword + ".txt", ios::app);
	fout << file_name + ".txt\n";
	fout.close();
}

