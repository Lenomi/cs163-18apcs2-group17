#include "header.h"

int main()
{
	vector<string> fileNames;
	vector<int> ID;
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	
	string l;
	/*while (l != "0")
	{*/
		cout << "Enter something " << endl;
		getline(cin, l);
		hi.ranking(fileNames, l, ID);

		for (int i = 0; i < ID.size(); i++)
		{
			hi.Cout_name_file(fileNames, ID[i]);

			//hi.Cout_file(ID[i]);
			cout << endl;
		}
		_getch();
	//}

	//cout << "Enter something " << endl;
	//getline(cin, l);
	//hi.ranking(fileNames,l, ID);
	//
	//for (int i = 0; i < ID.size(); i++)
	//{
	//	hi.Cout_name_file(fileNames, ID[i]);
	//	
	//	//hi.Cout_file(ID[i]);
	//	cout << endl;
	//}
	//_getch();

	//system("pause");
	return 0;
}
