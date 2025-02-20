#include "header.h"

int main() {
    std::string inputFile = "input.txt";  
    std::string outputFile = "compressed.bin";  

    build_Huffman_Tree(inputFile, outputFile);

    return 0;
}