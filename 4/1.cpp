#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::vector<bool>> grid;
  std::string line;
  int out = 0;

  while (std::cin) {
    std::getline(std::cin, line);
    if (line.empty()) {
      break;
    }
    std::vector<bool> row(line.length());
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '@') {
        row[i] = true;
      } else {
        row[i] = false;
      }
    }
    grid.push_back(row);
  }

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (!grid[i][j]) {
        continue;
      }
      int adj = 0;
      if (i > 0) {
        adj += grid[i - 1][j];
      }
      if (i > 0 && j > 0) {
        adj += grid[i - 1][j - 1];
      }
      if (i > 0 && j + 1 < grid[i].size()) {
        adj += grid[i - 1][j + 1];
      }
      if (i + 1 < grid.size()) {
        adj += grid[i + 1][j];
      }
      if (i + 1 < grid.size() && j > 0) {
        adj += grid[i + 1][j - 1];
      }
      if (i + 1 < grid.size() && j + 1 < grid[i].size()) {
        adj += grid[i + 1][j + 1];
      }
      if (j > 0) {
        adj += grid[i][j - 1];
      }
      if (j + 1 < grid[i].size()) {
        adj += grid[i][j + 1];
      }

      if (adj < 4) {
        out++;
      }
    }
  }

  std::cout << out << std::endl;
}
