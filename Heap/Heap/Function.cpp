#include "header.h"


void File::Insert(int k, string a, Node*& root)
{
	if (root == nullptr)
	{
		root = new Node;
		root->id = k;
		root->data=a;
		root->height = 1;
		root->left = root->right = nullptr;
	}
	if (k < root->id) Insert(k, a, root->left);
	else if (k > root->id) Insert(k, a, root->right);
	if (height(root->left) > height(root->right)) root->height = height(root->left) + 1;
	else root->height = height(root->right) + 1;
	int balance = Balance(root);
	if (balance > 1 && k < root->left->id)
		return rightRotate(root);
	if (balance < -1 && k > root->right->id)
		return leftRotate(root);
	if (balance > 1 && k > root->left->id)
	{
		leftRotate(root->left);
		return rightRotate(root);
	}
	if (balance < -1 && k < root->right->id)
	{
		rightRotate(root->right);
		return leftRotate(root);
	}
}
int File::height(Node* a)
{
	if (a == nullptr)
		return 0;
	return a->height;
}
int File::Balance(Node *a)
{
	if (a == nullptr)
		return 0;
	return height(a->left) - height(a->right);
}
void File::leftRotate(Node *&x)
{
	Node *y = x->right;
	Node *temp = y->left;
	y->left = x;
	x->right = temp;
	if (height(x->left) > height(x->right)) x->height = height(x->left) + 1;
	else x->height = height(x->right) + 1;
	if (height(y->left) > height(y->right)) y->height = height(y->left) + 1;
	else y->height = height(y->right) + 1;
	x = y;
}
void File::rightRotate(Node *&x)
{
	Node *y = x->left;
	Node *temp = y->right;
	y->right = x;
	x->left = temp;
	if (height(x->left) > height(x->right)) x->height = height(x->left) + 1;
	else x->height = height(x->right) + 1;
	if (height(y->left) > height(y->right)) y->height = height(y->left) + 1;
	else y->height = height(y->right) + 1;
	x = y;
}
Node* File::search(Node* root, int k)
{
	if (!root || root->id == k)
		return root;
	if (k < root->id)
		return search(root->left, k);
	else
		return search(root->right, k);
}
void File::openFiles(vector<string>& vec_fileNames)
{
	int k = 1;//ID bat dau bang 1
	for (int i = 0; i < vec_fileNames.size(); i++)
	{
		string fileName = vec_fileNames[i];
		string path("database\\" + fileName );
	//	string path("test\\" + fileName);
		ifstream fin;
		fin.open(path.c_str());
		if (!fin.is_open())
		{
			cout << "File " << vec_fileNames[i] << " Not Found! 2 " << endl;
		}
		else
		{
			string a, b;
			while (!fin.eof())
			{
				getline(fin, a);
				b = b + "\n" + a;
			}
			Insert(k, b, root);

			ifstream fin1;
			fin1.open(path.c_str());
			if (!fin1.is_open())
			{
				cout << "File " << vec_fileNames[i] << " Not Found! 2 " << endl;
			}
			else
			{
				string c;
				while (!fin1.eof())
				{
					fin1 >> c;
					insert_Node(c, k);
				}
			}
			fin1.close();
			k++;
		}	
		fin.close();
	}
	cout << 1 <<endl;
}
void File::Cout_file(int k)
{
	cout << search(root, k)->data;
}
void File::Cout_name_file(vector<string>& vec_fileNames, int k)
{
	cout << vec_fileNames[k - 1];
}
void File::loadFileNames(vector<string>& vec_fileNames)
{
	ifstream inFile("dataName.txt");
	//ifstream inFile("___index.txt");

	if (!inFile.is_open())

	{
		cout << "File Not Found! 1\n";
		return;
	}
	else
	{
		string line;
		while (getline(inFile, line))
		{
			vec_fileNames.push_back(line);
		}
	}
}
void File::insert_synonyms()
{
	ifstream insert("synonysms.txt");
	if (!insert.is_open())

	{
		cout << "File Not Found! 3\n";
		return;
	}
	string key;
	while (!insert.eof())
	{
		string l;
		getline(insert, l);
		vector<string> key;
		string word = "";
		for (auto x : l)
		{
			if (x == ' ')
			{
				key.push_back(word);
				word = "";
			}
			else
			{
				word = word + x;
			}
		}
		key.push_back(word);
		int query_size = key.size(), a = 0;
		bool *searched = new bool[query_size];
		for (int i = 0; i < query_size; i++) {
			searched[i] = false;
		}
		for (int i = 0; i < query_size; i++)
		{
			if (key[i] != " ")
			{
				if (root3 == nullptr)
				{
					root3 = new TrieNode;
					root3->isEnd = false;
					for (int i = 0; i < ALPHABET_SIZE; i++)
						root3->children[i] = nullptr;
				}
				TrieNode* pCrawl = root3;
				for (int level = 0; level < key[i].length(); level++)
				{
					int index;
					if (find_slot(index, level, key[i])) {
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
				pCrawl->synonyms = l;
			}
		}
	}
}
bool File::search_synonyms(const string key, string &l)
{
	int lenght = key.length();
	TrieNode *pCrawl = root3;
	for (int level = 0; level < lenght; level++)
	{
		int index;
		if (find_slot(index, level, key)) {
			if (pCrawl->children[index] == nullptr)
				return false;
			pCrawl = pCrawl->children[index];
		}
	}
	if (pCrawl != nullptr && pCrawl->isEnd) {
		l = pCrawl->synonyms;
		return true;
	}
}

