#include "HuffmanTree.h"
#include "iostream"

HuffmanTree::HuffmanTree() : _root{ nullptr } {}

void HuffmanTree::insert(char character, int frequency) {
  _root = insert(_root, character, frequency);
}

HuffmanTreeNode* HuffmanTree::insert(HuffmanTreeNode* node, char character, int frequency) {
  if (!node) {
    node = new HuffmanTreeNode(character, frequency);
    _root = node;
  }
  else if(frequency < node->frequency) {
    node->left = insert(node->left, character, frequency);
  }
  else if (frequency > node->frequency) {
    node->right = insert(node->right, character, frequency);
  }
  return node;
}

void HuffmanTree::preOrder() {
  preOrder(_root);
}


void HuffmanTree::preOrder(const HuffmanTreeNode* node) {
  if (node) {
		std::cout << node->character << " " << node->frequency << std::endl; 
		preOrder(node->left); 
		preOrder(node->right); 
	}
}