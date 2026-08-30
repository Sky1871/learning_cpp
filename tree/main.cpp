#include <iostream>
#include <memory>

struct Node {
  int data;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

  Node(int val) {
    data = val;
    std::cout << "Created node: " << data << "\n";
  }
  ~Node() {
    std::cout << "Destroy node: " << data << "\n";
  }
};

int main() {
  std::cout << "--- Entering scope ---\n";

  {
    std::unique_ptr<Node> root = std::make_unique<Node>(10);
    root->left = std::make_unique<Node>(5);
    root->right = std::make_unique<Node>(15);
    root->left->left = std::make_unique<Node>(2);

    std::cout << "Tree built\nExiting scope...\n";
  }
  std::cout << "---Exited scope---\n";
  return 0;
}
