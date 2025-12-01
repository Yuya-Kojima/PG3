#include "GameManager.h"
#include "InputManager.h"
#include <Novice.h>

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

  // ライブラリの初期化
  Novice::Initialize(kWindowTitle, 1280, 720);

  InputManager input;

  GameManager *gameManager_ = nullptr;

  gameManager_ = new GameManager(&input);

  gameManager_->Run();

  delete gameManager_;
  gameManager_ = nullptr;

  // ライブラリの終了
  Novice::Finalize();
  return 0;
}
