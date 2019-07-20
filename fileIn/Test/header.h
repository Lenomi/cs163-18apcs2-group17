#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
struct Node
{
	int id, height;
	string data;
	Node* left, *right;
};
class File
{
private:
	Node* root;
public:
	File() { root = nullptr; }
	void Insert(int k, string a, Node*& root);
	int height(Node* a);
	int Balance(Node *a);
	void leftRotate(Node *&x);
	void rightRotate(Node *&x);
	Node* search(Node* root, int k);
	void openFiles(vector<string>& vec_fileNames);
	void loadFileNames(vector<string>& vec_fileNames);
};
