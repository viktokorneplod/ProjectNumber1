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

bool compareNode::operator()(huffman_Node* left, huffman_Node* right) {
    return left->freq > right->freq;
}
