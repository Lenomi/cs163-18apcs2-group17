#include "header.h"

int main()
{
	vector<string> fileNames;
	vector<int> ID;
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	string l;
	getline(cin, l);
	hi.ranking(l, ID);
	for (int i = 0; i < ID.size(); i++)
	{
		hi.Cout_file(ID[i]);
		cout << endl;
	}
	system("pause");
	return 0;
}
