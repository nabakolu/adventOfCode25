#include <cmath>
#include <iostream>
#include <ostream>
#include <string>

int main() {
  std::string line;
  int cur, index;
  long long total;
  long nums[12];
  total = 0;

  while (std::cin) {
    std::getline(std::cin, line);
    if (line == "\0") {
      break;
    }
    index = 0;
    for (int i = 0; i < 12; i++) {
      nums[i] = -1;
    }

    for (int i = 0; i < 12; i++) {
      for (int j = index; j < line.length() - 11 + i; j++) {
        cur = line[j] - '0';
        if (cur > nums[i]) {
          nums[i] = cur;
          index = j+1;
        }
      }
      std::cout << nums[i];
    }
    std::cout << std::endl;

    for (int i = 0; i < 12; i++) {
      total += std::pow(10, 11 - i) * nums[i];
    }
  }
  std::cout << total << std::endl;
}
