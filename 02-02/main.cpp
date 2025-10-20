#include <cstdint>
#include <iostream>

/// <summary>
/// 再帰的な賃金の合計を算出する
/// </summary>
/// <param name="hour"></param>
/// <returns></returns>
uint32_t CalculateRecursiveTotalWage(uint32_t hour);

/// <summary>
/// 再帰的な賃金の時給を算出する
/// </summary>
/// <param name="hour"></param>
/// <returns></returns>
uint32_t CalculateRecursiveHourlyWage(uint32_t hour);

int main() {

  uint32_t workTime{};

  std::cout << "働いた時間を入力してください: ";
  std::cin >> workTime;

  uint32_t recursiveTotal{};
  uint32_t normalTotal{};

  recursiveTotal = CalculateRecursiveTotalWage(workTime);
  normalTotal = 1226 * workTime;

  std::cout << "再帰賃金:" << recursiveTotal << ",一般賃金:" << normalTotal
            << std::endl;

  if (recursiveTotal > normalTotal) {
    std::cout << " 再帰的な賃金体系のほうが儲かる" << std::endl;
  } else if (recursiveTotal < normalTotal) {
    std::cout << " 一般的な賃金体系のほうが儲かる" << std::endl;
  } else {
    std::cout << " どちらも同じ" << std::endl;
  }

  return 0;
}

uint32_t CalculateRecursiveTotalWage(uint32_t hour) {
  if (hour <= 0) {
    return 0;
  }

  // 一時間前までの合計に加算する
  return CalculateRecursiveTotalWage(hour - 1) +
         CalculateRecursiveHourlyWage(hour);
}

uint32_t CalculateRecursiveHourlyWage(uint32_t hour) {

  // 最初は100円から
  if (hour <= 1) {
    return 100;
  }

  // 一時間前の時給
  uint32_t preWage = CalculateRecursiveHourlyWage(hour - 1);

  return preWage * 2 - 50;
}
