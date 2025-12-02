#include <iostream>
#include <ostream>
#include <string>

bool isInvalid(std::string number);

int main() {
  std::string line, range, number, left, right;
  std::getline(std::cin, line);
  line.append(",");
  long out, cur, next, minus, lower, upper;
  cur = 0;
  out = 0;

  while ((next = line.find(",", cur + 1)), next != -1) {
    range = line.substr(cur, next - cur);
    std::erase(range, ',');
    minus = range.find("-");
    lower = std::stol(range.substr(0, minus));
    upper = std::stol(range.substr(minus + 1));

    for (long i = lower; i <= upper; i++) {
      number = std::to_string(i);
      if (isInvalid(number)) {
        out += i;
      }
    }

    cur = next;
  }
  std::cout << out << std::endl;
}


bool isInvalid(std::string number) {
  std::string ss;
  bool correct;
  for (int i = 1; i <= number.length()/2; i++) {
    ss = number.substr(0, i);
    correct = true;
    for (int j = i; j < number.length(); j+=i) {
      if (number.substr(j,i).compare(ss)!=0) {
        correct = false;
        break;
      }
    }
    if (correct) {
      return true;
    }
  }
  return false;
}
