#include "header.h"
#include <fstream>
#include <queue>
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

void build_Huffman_Tree(const std::string& inputFile, const std::string& outputFile) {

    std::ifstream infile(inputFile);
    if (!infile) {
        std::cerr << "file reading error " << inputFile << std::endl;
        return;
    }

    std::string text((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    std::unordered_map<char, int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }

    std::priority_queue<huffman_Node*, std::vector<huffman_Node*>, compareNode> queue_with_P;

    for (auto& pair : freqMap) {
        queue_with_P.push(create_Node(pair.first, pair.second, nullptr, nullptr));
    }

    while (queue_with_P.size() > 1) {
        huffman_Node* left = queue_with_P.top(); queue_with_P.pop();
        huffman_Node* right = queue_with_P.top(); queue_with_P.pop();
        int sum = left->freq + right->freq;
        queue_with_P.push(create_Node('\0', sum, left, right));
    }

    huffman_Node* root = queue_with_P.top();

    std::unordered_map<char, std::string> huffmanCodes;
    inCode(root, "", huffmanCodes);


    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "file reading error: " << outputFile << std::endl;
        return;
    }

    std::string encodedString;
    for (char ch : text) {
        encodedString += huffmanCodes[ch];
    }

    outFile << encodedString;
    outFile.close();
    std::cout << "output: ";
    int index = -1;
    while (index < (int)encodedString.size() - 2) {
        deCode(root, index, encodedString);
    }
    std::cout << std::endl;
}
