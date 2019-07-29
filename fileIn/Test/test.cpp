#include "header.h"

int main()
{
	vector<string> fileNames;
	vector<int> ID;
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	string l;
	//getline(cin, l);
	vector<string> query;
	for (int i = 0; i < 30; i++) {
		cin >> l;
		query.push_back(l);
	}
	hi.ranking(fileNames,query, ID);
	for (int i = 0; i < ID.size(); i++)
	{
		hi.Cout_name_file(fileNames, ID[i]);
		hi.Cout_file(ID[i]);
		cout << endl;
	}
	system("pause");
	return 0;
}
