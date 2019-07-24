#include "header.h"

int main()
{
	vector<string> fileNames;
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	string l;
	hi.Cout_file(11000);
	hi.Cout_name_file(fileNames, 11000);
	/*do
	{
		cin >> l;
		bool file = hi.search(l);
		if (file) cout << "yes" << endl;
		else cout << "no" << endl;
	} while (l != "deo");*/
	system("pause");
	return 0;
}
