#include "HuffmanTree.h"
using namespace std;
class Compare {
public:
  bool operator() (HuffmanTreeNode* node1, HuffmanTreeNode* node2) {
    return node1->frequency > node2->frequency; 
  }
};


void HuffmanTree::compress(const std::string fileName) {
  HuffmanTreeNode* root = buildHuffmanTree(fileName);

  std::map<wchar_t, std::string> output;
  std::map<wchar_t, std::string> huffmanCodes = getHuffmanCodes(root, "", output);

  ofstream fileWrite;
  wifstream fileRead;
  fileRead.imbue(locale("zh_CN.UTF-8"));
  fileWrite.imbue(locale("zh_CN.UTF-8"));
  fileRead.open(fileName);

  if (fileRead.is_open()) {
    wchar_t fileCharacter;
    fileWrite.open("pride.huff");
    while (!fileRead.eof()) {
      fileRead.get(fileCharacter);
      if (fileRead.gcount() < 1) break;
      fileWrite << huffmanCodes[fileCharacter];
    }
  }
}

map<wchar_t, int> HuffmanTree::readFile(const string fileName) {
  wifstream fileRead;
  fileRead.imbue(locale("zh_CN.UTF-8"));
  map<wchar_t, int> characterFrequencyCounter;

  wchar_t fileCharacter;

  fileRead.open(fileName);
  if (fileRead.is_open()) {
    while (!fileRead.eof()) {
      fileRead.get(fileCharacter);
      if (fileRead.gcount() < 1) break;
      if (characterFrequencyCounter.count(fileCharacter) != 0) {
        characterFrequencyCounter.at(fileCharacter) += 1;
      }
      else {
        characterFrequencyCounter.insert(pair<wchar_t, int>(fileCharacter, 1));
      }
    }
  }
  return characterFrequencyCounter;
}

HuffmanTreeNode* HuffmanTree::buildHuffmanTree(const std::string fileName) {
  map<wchar_t, int> characterFrequencyCounter = readFile(fileName);
  priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> characterQueue;
        
  for (auto const &pair : characterFrequencyCounter) {
    characterQueue.push(new HuffmanTreeNode(pair.first, pair.second));
  }

  while (characterQueue.size() > 1) {
    HuffmanTreeNode* left = characterQueue.top();
    characterQueue.pop();
    HuffmanTreeNode* right = characterQueue.top();
    characterQueue.pop();

    int frequencySum = left->frequency + right->frequency;
    characterQueue.push(new HuffmanTreeNode(frequencySum, left, right));
  }
  return characterQueue.top();
}

std::map<wchar_t, std::string> HuffmanTree::getHuffmanCodes(HuffmanTreeNode* node, std::string prefix, std::map<wchar_t, std::string>& output) {
  if (node->isLeaf()) {
    output[node->character] = prefix;
  }
  else {
    getHuffmanCodes(node->left, prefix + "0", output);
    getHuffmanCodes(node->right, prefix + "1", output);
  }
  return output;
}