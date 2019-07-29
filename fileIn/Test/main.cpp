#include"Trie.h"

int main()
{
	struct TrieNode *root = createNode();
	insert_Node(root, "minh");
	insert_Node(root, "minhoca");
	
	

	int comp = AutoSuggestions(root, "mi");

	if (comp == -1)
		cout << "No other strings found with this prefix\n";

	else if (comp == 0)
		cout << "No string found with this prefix\n";
	
	system("pause");
	return 0;

}