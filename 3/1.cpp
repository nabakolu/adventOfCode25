#include <iostream>
#include <string>

int main() {
  std::string line;
  int cur, right, left, total;
  total = 0;

  while (std::cin) {
    std::getline(std::cin, line);
    right = 0;
    left = 0;
    for (int i = 0; i < line.length(); i++) {
      cur = line[i] - '0';
      if (i < line.length() - 1 && cur > left) {
        left = cur;
        right = line[i + 1] - '0';
      } else if (cur > right) {
        right = cur;
      }
    }
    std::cout << right << " " << left << std::endl;
    total += 10 * left + right;
  }
  std::cout << total << std::endl;
}
