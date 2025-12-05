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

  for (int cur = 0; cur < ranges.size(); cur++) {
    for (int other = 0; other < cur; other++) {
      if (ranges[cur].first <= ranges[other].first &&
          ranges[cur].second >= ranges[other].second) {
        ranges.erase(ranges.begin() + other);
        other--;
        continue;
      }
      if (ranges[cur].first >= ranges[other].first &&
          ranges[cur].second <= ranges[other].second) {
        ranges.erase(ranges.begin() + cur);
        other = -1;
        cur--;
        continue;
      }
      if (ranges[cur].first <= ranges[other].first &&
          ranges[cur].second >= ranges[other].first &&
          ranges[cur].second <= ranges[other].second) {
        ranges[cur].second = ranges[other].first - 1;
        continue;
      }
      if (ranges[cur].first <= ranges[other].second &&
          ranges[cur].second >= ranges[other].second &&
          ranges[cur].first >= ranges[other].first) {
        ranges[cur].first = ranges[other].second + 1;
        other = -1;
        cur = -1;
        continue;
      }
      if (ranges[cur].first > ranges[cur].second) {
        ranges.erase(ranges.begin() + cur);
        other = -1;
        cur--;
        continue;
      }
    }
  }

  total = 0;
  for (int i = 0; i < ranges.size(); i++) {
    total += ranges[i].second - ranges[i].first + 1;
  }

  std::cout << total << std::endl;
}
