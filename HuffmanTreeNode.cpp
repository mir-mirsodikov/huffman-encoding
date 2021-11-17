#include "HuffmanTreeNode.h"

/**
 * For initialization when reading from the map of characters and frequencies
 */ 
HuffmanTreeNode::HuffmanTreeNode(wchar_t character, int frequency) :
  character{ character }, frequency{frequency}, left{ nullptr }, right{ nullptr } {}

/**
 * Used for internal vertices that hold the frequency sums
 */ 
HuffmanTreeNode::HuffmanTreeNode(int frequency, HuffmanTreeNode* left, HuffmanTreeNode* right) : 
  frequency{ frequency }, left { left }, right { right } {
}

/**
 * @return If the node is a leaf or not
 */ 
bool HuffmanTreeNode::isLeaf() {
  return !(this->left || this->right);
}