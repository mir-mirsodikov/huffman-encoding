/**
  1. Define a struct for Huffman tree node. This struct contains links to left/right child nodes, a character,
      and its frequency.
 */

#pragma once

class HuffmanTreeNode {
public:
  char character;
  int frequency;
  HuffmanTreeNode* left;
  HuffmanTreeNode* right;

  HuffmanTreeNode(char character, int frequency);
};