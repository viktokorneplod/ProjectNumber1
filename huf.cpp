#include "header.h"
#include <unordered_map>
huffman_Node* create_Node(char symbol, int freq, huffman_Node* left, huffman_Node* right) {
    huffman_Node* node = new huffman_Node();
    node->symbol = symbol;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

void inCode(huffman_Node* root, std::string code, std::unordered_map<char, std::string>& huffman_Codes) {
    if (root == nullptr) return;
    if (!root->left && !root->right) {
        huffman_Codes[root->symbol] = code;
    }

    inCode(root->left, code + "0", huffman_Codes);
    inCode(root->right, code + "1", huffman_Codes);
}

void deCode(huffman_Node* root, int& index, const std::string& inCode_string) {
    if (root == nullptr) return;

    if (!root->left && !root->right) {
        std::cout << root->symbol;
        return;
    }
    index++;
    if (inCode_string[index] == '0') {
        deCode(root->left, index, inCode_string);
    }
    else {
        deCode(root->right, index, inCode_string);
    }
}
