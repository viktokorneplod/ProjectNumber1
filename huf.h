#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};
huffman_Node* create_Node(char symbol, int freq, huffman_Node* left, huffman_Node* right);
void build_Huffman_Tree(const std::string& inputFile, const std::string& outputFile);
