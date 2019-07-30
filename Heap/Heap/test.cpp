#include "header.h"

int main()
{
	vector<string> fileNames;
	
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	hi.insert_synonyms();
	
	for (int i = 0; i < 2; i++) {
		vector<int> ID;
		string query;
		getline(cin, query);
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
