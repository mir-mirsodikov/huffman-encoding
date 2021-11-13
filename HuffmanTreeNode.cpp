#include "HuffmanTreeNode.h"

HuffmanTreeNode::HuffmanTreeNode(wchar_t character, int frequency) :
  character{ character }, frequency{frequency}, left{ nullptr }, right{ nullptr } {}
