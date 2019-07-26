#include "header.h"

int main()
{
	vector<string> fileNames;
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	string l;
	hi.Cout_file(5);
	cout << endl;
	hi.Cout_name_file(fileNames, 5);
	do
	{
		cin >> l;
		bool file = hi.search(l);
		if (file) cout << "yes" << endl;
		else cout << "no" << endl;
	} while (l != "deo");
	system("pause");
	return 0;
}
