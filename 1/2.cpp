#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

int getModulus(int dividend, int divisor);

int main() {
  int left;
  int num;
  int cur = 50;
  int pass = 0;
  int old;

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
    old = cur;
    if (left == 1) {
      cur -= num;
    } else {
      cur += num;
    }
    if (cur < 0) {
      pass += (cur)/-100;
      if (old != 0) {
        pass++;
      }
    } else if (cur == 0) {
      pass++;
    } else {
      pass += cur/100;
    }
    cur = getModulus(cur, 100);
  }
  printf("%d\n", pass);
}


int getModulus(int dividend, int divisor) {
  int t = (int)floor((double)dividend / divisor);
  return dividend - divisor * t;
}
