#include"Trie.h"

int main()
{
	TrieNode *Root = createNode();
	Insersion(Root, "minh");
	Insersion(Root, "minhoca");
	
	

	int comp = AutoSuggestions(Root, "mi");

	if (comp == -1)
		cout << "No other strings found with this prefix\n";

	else if (comp == 0)
		cout << "No string found with this prefix\n";
	
	system("pause");
	return 0;

}