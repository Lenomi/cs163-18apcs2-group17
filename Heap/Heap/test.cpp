#include "header.h"

int main()
{
	vector<string> fileNames;
	
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	
	
	for (int i = 0; i < 2; i++) {
		vector<int> ID;
		string l;	
		do {
			getline(cin, l);
		} while (l == "");
		vector<string> query;
		string word = "";
		for (auto x : l)
		{
			if (x == ' ')
			{
				query.push_back(word);
				word = "";
			}
			else
			{
				word = word + x;
			}
		}
		query.push_back(word);
		hi.ranking(fileNames, query, ID);
		for (int i = 0; i < 5 && i<ID.size(); i++)
		{
			hi.Cout_name_file(fileNames, ID[i]);
			//hi.Cout_file(ID[i]);
			cout << endl;
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}
