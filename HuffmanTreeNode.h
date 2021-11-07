/**
  1. Define a struct for Huffman tree node. This struct contains links to left/right child nodes, a character,
      and its frequency.
 */

#pragma once

class HuffmanTreeNode {
private:
  char _character;
  int _frequency;
  HuffmanTreeNode* _left;
  HuffmanTreeNode* _right;

public:
  HuffmanTreeNode(char character);
};