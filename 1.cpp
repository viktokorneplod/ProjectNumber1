#include <iostream>
#include <string>

using namespace std;
// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;
.......}

Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}
int main()
{
	

	return 0;
}
