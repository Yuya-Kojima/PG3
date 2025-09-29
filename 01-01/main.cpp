#include <cstring>
#include <list>
#include <stdio.h>

int main() {

  // 1970
  std::list<const char *> station{
      "Tokyo",        "Kanda",     "Akihabara", "Okachimachi",  "Ueno",
      "Uguisudani",   "Nippori",   "Tabata",    "Komagome",     "Sugamo",
      "Otsuka",       "Ikebukuro", "Mejiro",    "Takadanobaba", "Shin-Okubo",
      "Shinjuku",     "Yoyogi",    "Harajuku",  "Shibuya",      "Ebisu",
      "Meguro",       "Gotanda",   "Osaki",     "Shinagawa",    "Tamachi",
      "Hamamatsucho", "Shimbashi", "Yurakucho"};

  // 2019
  std::list<const char *> ver2019 = station;

  // 2019  田端の前に西日暮里を追加
  for (auto itr = ver2019.begin(); itr != ver2019.end(); ++itr) {
    if (std::strcmp(*itr, "Tabata") == 0) {
      itr = ver2019.insert(itr, "Nishi-Nippori");
      ++itr;
    }
  }

  // 2022
  std::list<const char *> ver2022 = ver2019;

  // 2022  田町の前に高輪ゲートウェイを追加
  for (auto itr = ver2022.begin(); itr != ver2022.end(); ++itr) {
    if (std::strcmp(*itr, "Tamachi") == 0) {
      itr = ver2022.insert(itr, "Takanawa Gateway");
      ++itr;
    }
  }

  // 結果を表示
  printf("1970Ver\n");
  for (auto s : station) {
    printf("%s\n", s);
  }

  printf("\n2019Ver\n");

  for (auto s : ver2019) {
    printf("%s\n", s);
  }

  printf("\n2022Ver\n");

  for (auto s : ver2022) {
    printf("%s\n", s);
  }

  return 0;
}