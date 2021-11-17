/**
  1. Define a struct for Huffman tree node. This struct contains links to left/right child nodes, a character,
      and its frequency.
 */

#pragma once

struct HuffmanTreeNode {
  wchar_t character;
  int frequency;
  HuffmanTreeNode* left;
  HuffmanTreeNode* right;

  HuffmanTreeNode(wchar_t character, int frequency);
  HuffmanTreeNode(int frequency, HuffmanTreeNode* left, HuffmanTreeNode* right);
  
  bool isLeaf();
};