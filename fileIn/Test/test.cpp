#include "header.h"

int main()
{
	vector<string> fileNames;
	File hi;
	hi.loadFileNames(fileNames);
	hi.openFiles(fileNames);
	return 0;
}
