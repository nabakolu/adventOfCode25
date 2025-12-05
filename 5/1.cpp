#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::string line;
  long left, right, num, total;
  std::vector<std::pair<long, long>> ranges;
  while (std::cin) {
    std::getline(std::cin, line);
    if (line.empty()) {
      break;
    }
    long del = line.find("-");
    left = std::stol(line.substr(0, del));
    right = std::stol(line.substr(del + 1));
    ranges.push_back(std::make_pair(left, right));
  }
  total = 0;
  while (std::cin) {
    std::getline(std::cin, line);
    if (line.empty()) {
      break;
    }
    num = std::stol(line);
    for (int i = 0; i < ranges.size(); i++) {
      if (num >= ranges[i].first && num <= ranges[i].second) {
        total++;
        break;
      }
    }
  }
  std::cout << total << std::endl;
}
