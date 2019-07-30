#include "header.h"
#include"graphics.h"

void File::Insert(int k, string a, Node*& root)
{
	if (root == nullptr)
	{
		root = new Node;
		root->id = k;
		root->data = a;
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
	int k = 1;
	int gdriver = IBM8514, gmode = IBM8514HI;
	initgraph(&gdriver, &gmode, "");
	for (int i = 0; i < vec_fileNames.size(); i++)
	{
		string fileName = vec_fileNames[i];
		string path("database\\" + fileName);
		//string path("test\\" + fileName);
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
			cout << i << endl;
		}
		fin.close();
		int midx = getmaxx() / 2;
		int midy = getmaxy() / 2;
		cleardevice();
		setbkcolor(COLOR(0, 0, 0));
		//delay(100);
		circle(midx, midy, 185);



		setcolor(15);
		circle(midx, midy, 185);
		//delay(10);

		setcolor(13);
		circle(midx, midy - 92, 46);
		setfillstyle(i % 12, RED);
		floodfill(midx, midy - 92, 13);

		setcolor(13);
		circle(midx + 92, midy, 46);
		setfillstyle(i % 12, BLUE);
		floodfill(midx + 92, midy, 13);

		setcolor(13);
		circle(midx, midy + 92, 46);
		setfillstyle(i % 12, YELLOW);
		floodfill(midx, midy + 92, 13);

		setcolor(13);
		circle(midx - 92, midy, 46);
		setfillstyle(i % 12, GREEN);
		floodfill(midx - 92, midy, 13);
		//delay(40);
	}

	

}
void File::Cout_file(int k)
{
	cout << search(root, k)->data;
}

string File::GetFile(int k) {
	return search(root, k)->data;
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

