/**
 * Mirmukhammad Mirsodikov
 * CS400
 * Homework 7
  1. Define a struct for Huffman tree node. This struct contains links to left/right child nodes, a character,
      and its frequency.
  2. Define a function for file reading operation. This function should take in a filename (string type) as
      parameter and return a proper data structure object that contains characters and their frequencies
      that will be used to generate Huffman tree nodes.
  3. The construction of Huffman tree requires taking two nodes with smallest frequencies. Select a
      proper data structure to support this operation. Note this data structure object could be different to
      the object from Step (2).
  4. Design a function that takes in the root of Huffman coding tree, prints, and returns the encoding
      scheme in a data structure object.
  5. Design a function that takes in the encoding scheme and filename (string type), output encoded
      content (bit-string) to a file named pride.huff 
 * November 6
 */

#include "HuffmanTree.h"

int main() {
  HuffmanTree tree;
  tree.compress("Pride_and_Prejudice.txt");
}