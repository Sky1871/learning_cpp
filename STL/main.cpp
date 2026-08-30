#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> numbers = {12, 55, 68, 90, 3, 42, 88, 19, 104, 50};

  int count = std::count_if(numbers.begin(), numbers.end(), 
    [](int n) {
      return (n % 2 == 0) && (n > 50);
    }
  );

  std::cout << "Found " << count << " numbers that match the criteria\n";

  return 0;
}
