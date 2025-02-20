#define HUFFMAN_H
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

struct huffman_Node {
    char symbol;
    int freq;
    huffman_Node *left, *right;
}
huffman_Node* create_Node(char symbol, int freq, huffman_Node* left, huffman_Node* right);
struct compareNode {
    bool operator()(huffman_Node* left, huffman_Node* right);
};
void build_Huffman_Tree(const std::string& inputFile, const std::string& outputFile);
