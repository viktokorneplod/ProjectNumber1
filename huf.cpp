#include "header.h"
#include <unordered_map>
void inCode(huffman_Node* root, std::string code, std::unordered_map<char, std::string>& huffman_Codes) {
    if (root == nullptr) return;
    if (!root->left && !root->right) {
        huffman_Codes[root->symbol] = code;
    }

    inCode(root->left, code + "0", huffman_Codes);
    inCode(root->right, code + "1", huffman_Codes);
}


