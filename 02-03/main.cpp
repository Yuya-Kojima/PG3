#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

/// <summary>
/// 結果を表示する
/// </summary>
/// <param name="roll">出目</param>
/// <param name="userGuess">入力値</param>
void ShowResult(int roll, int userGuess) {

  int rollParity = (roll % 2 == 0) ? 0 : 1;

  printf("出目は%dでした\n", roll);

  if (rollParity == userGuess) {
    printf("正解\n");
  } else {
    printf("不正解\n");
  }
}

/// <summary>
/// 指定された時間待ってから関数を実行する
/// </summary>
/// <param name="fn">実行する関数へのポインタ</param>
/// <param name="delayMs">待機時間(ミリ秒)</param>
/// <param name="roll">出目</param>
/// <param name="userGuess">入力値</param>
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll,
                 int userGuess) {

  // 3秒止める
  Sleep(delayMs);

  // 結果を表示
  fn(roll, userGuess);
}

int main(void) {

  // 乱数の初期化
  srand((unsigned int)time(NULL));

  int userGuess;

  printf("0(丁)か1(半)を入力");
  scanf_s("%d", &userGuess);

  int roll = rand() % 6 + 1;

  DelayReveal(ShowResult, 3000, roll, userGuess);

  return 0;
}
