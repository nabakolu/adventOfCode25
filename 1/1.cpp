#include <iostream>
#include <string>

int main() {
  int left;
  int num;
  int cur = 50;
  int pass = 0;

  std::string line;
  while (std::getline(std::cin, line)) {
    if (line[0] == 'L') {
      left = 1;
    } else if (line[0] == 'R') {
      left = 0;
    } else {
      exit(-1);
    }
    num = std::stoi(line.substr(1));
    if (left == 1) {
      cur -= num;
    } else {
      cur += num;
    }
    cur = cur % 100;
    if (cur == 0) {
      pass++;
    }
  }
  printf("%d\n", pass);
}
