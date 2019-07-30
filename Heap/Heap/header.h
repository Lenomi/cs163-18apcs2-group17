#include<iostream>
#include < conio.h>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<cctype>
const int ALPHABET_SIZE = 38;

using namespace std;
struct Node
{
	int id, height;
	string data;
	Node* left, *right;
};
struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];
	bool isEnd;
	vector<int> file_ID;
	string synonyms;
	TrieNode() {
		isEnd = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = nullptr;
	}
};
class File
{
private:
	Node* root;
	TrieNode* root2;
	TrieNode* root3;

public:
	//AVL
	File() { root = nullptr; root2 = nullptr; root3 = nullptr; }
	void Insert(int k, string a, Node*& root);
	int height(Node* a);
	int Balance(Node *a);
	void leftRotate(Node *&x);
	void rightRotate(Node *&x);
	Node* search(Node* root, int k);
	void Cout_file(int k);
	void Cout_name_file(vector<string>& vec_fileNames, int k);
	void openFiles(vector<string>& vec_fileNames);
	void loadFileNames(vector<string>& vec_fileNames);
	//trie
	void insert_Node(string key,int ID);
	bool search(const string key, vector<int>& ID, vector<int>& occu, int mode);
	bool isLastNode(TrieNode* root2);
	bool suggestionsRec(TrieNode * root2, string currPrefix,string &ans);
	string AutoSuggestions(string query);
	bool find_slot(int &index, int level, string key);
	string convert_word(string key);
	void ranking(vector<string>& vec_fileNames, string query1, vector<int>& ID);
	void heapSort(vector<int> &occu, vector<int> &ID, int n);
	void heapify(vector<int> &occu, vector<int> &ID, int n, int i);


	// synosysms
	void insert_synonyms();
	bool search_synonyms(const string key, string &l);
};

