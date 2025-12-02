#include <iostream>
#include <ostream>
#include <string>

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
      if (number.length() % 2 == 1) {
        continue;
      }
      if (0 == number.substr(0, number.length() / 2)
                   .compare(number.substr(number.length() / 2))) {

        out += i;
      }
    }

    cur = next;
  }
  std::cout << out << std::endl;
}
