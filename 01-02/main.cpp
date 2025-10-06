#include <algorithm>
#include <fstream>
#include <iostream> //cout
#include <sstream>  //文字列
#include <stdio.h>
#include <string>
#include <vector>

int main() {

  // 読み込むファイル名
  std::ifstream file("PG3_2025_01_02.txt");
  std::vector<std::string> students;
  std::string line;

  // ファイルを1行ずつ読み込む
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string item;

    // カンマで区切られているので、1つずつ取り出す
    while (std::getline(ss, item, ',')) {
      if (!item.empty()) { // 空文字でなければ追加
        students.push_back(item);
      }
    }
  }

  // 学籍番号順に並び替え
  std::sort(students.begin(), students.end());

  // 結果表示
  for (const auto &s : students) {
    std::cout << s << std::endl;
  }

  return 0;
}