#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

template <typename T>
class Stack {
private:
  std::vector<T> m_elements;

public:
  void push(const T& item) {
    m_elements.push_back(item);
  }

  T pop() {
    if (m_elements.empty()) {
      throw std::out_of_range("Cannot pop from empty stack");
    }

    T topElement = m_elements.back();
    m_elements.pop_back();
    return topElement;
  }

  bool isEmpty() const {
    return m_elements.empty();
  }
};

int main() {
  Stack<int> intStack;
  intStack.push(10);
  intStack.push(20);

  std::cout << "Popped int: " << intStack.pop() << "\n";
  std::cout << "Popped int: " << intStack.pop() << "\n";

  std::cout << "---------------\n";

  Stack<std::string> stringStack;
  stringStack.push("Hello");
  stringStack.push("Balls");

  std::cout << "Popped string: " << stringStack.pop() << "\n";
  std::cout << "Popped string: " << stringStack.pop() << "\n";

  return 0;
}
