#include "IStageSceneCommand.h"
#include "Selector.h"
#include "StageSceneInputHandler.h"
#include "Unit.h"
#include <Novice.h>

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

  // ライブラリの初期化
  Novice::Initialize(kWindowTitle, 1280, 720);

  // キー入力結果を受け取る箱
  char keys[256] = {0};
  char preKeys[256] = {0};

  Unit units[2];
  units[0].Init(0);
  units[1].Init(1);

  units[1].Move(+3, +2);

  Selector selector;
  selector.Init(units, 2);

  StageSceneInputHandler input;

  // ウィンドウの×ボタンが押されるまでループ
  while (Novice::ProcessMessage() == 0) {
    // フレームの開始
    Novice::BeginFrame();

    ///
    /// ↓更新処理ここから
    ///

    input.UpdateKeyState();

    IStageSceneCommand *cmd = nullptr;
    if (selector.GetSelectMode() == SelectMode::Selector) {
      cmd = input.SelectorHandleInput(&selector);
    } else {
      cmd = input.UnitHandleInput(selector.GetSelectedUnitAddress(), &selector);
    }

    if (cmd) {
      cmd->Exec();
      delete cmd;
    }

    ///
    /// ↑更新処理ここまで
    ///

    ///
    /// ↓描画処理ここから
    ///

    for (int y = 0; y < 25; ++y) {
      for (int x = 0; x < 40; ++x) {
        Novice::DrawBox(x * 32, y * 32, 32, 32, 0.0f, WHITE,
                        kFillModeWireFrame);
      }
    }


    selector.Draw();
    for (auto &u : units) {
      u.Draw();
    }
    ///
    /// ↑描画処理ここまで
    ///

    // フレームの終了
    Novice::EndFrame();

    // ESCキーが押されたらループを抜ける
    if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
      break;
    }
  }

  // ライブラリの終了
  Novice::Finalize();
  return 0;
}
