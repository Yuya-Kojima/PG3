#include <Novice.h>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <string>
#include <thread>

const char kWindowTitle[] = "学籍番号";

std::mutex gMutex;
std::condition_variable gCv;
int gTurn = 1;

std::string gLine[3];

std::atomic<bool> gStarted{false};

void ThreadFunc(int id) {
  std::unique_lock<std::mutex> lock(gMutex);

  gCv.wait(lock, [id]() { return gTurn == id; });

  gLine[id - 1] = "thread " + std::to_string(id);

  ++gTurn;
  lock.unlock();
  gCv.notify_all();
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

  // ライブラリの初期化
  Novice::Initialize(kWindowTitle, 1280, 720);

  // キー入力結果を受け取る箱
  char keys[256] = {0};
  char preKeys[256] = {0};

  std::thread t1;
  std::thread t2;
  std::thread t3;

  // ウィンドウの×ボタンが押されるまでループ
  while (Novice::ProcessMessage() == 0) {
    // フレームの開始
    Novice::BeginFrame();

    // キー入力を受け取る
    memcpy(preKeys, keys, 256);
    Novice::GetHitKeyStateAll(keys);

    ///
    /// ↓更新処理ここから
    ///
    if (!gStarted.load()) {
      gStarted = true;

      {
        std::lock_guard<std::mutex> lock(gMutex);
        gTurn = 1;
        gLine[0].clear();
        gLine[1].clear();
        gLine[2].clear();
      }

      t1 = std::thread(ThreadFunc, 1);
      t2 = std::thread(ThreadFunc, 2);
      t3 = std::thread(ThreadFunc, 3);
    }

    ///
    /// ↑更新処理ここまで
    ///

    ///
    /// ↓描画処理ここから
    ///

    if (!gLine[0].empty()) {
      Novice::ScreenPrintf(20, 20, gLine[0].c_str());
    }
    if (!gLine[1].empty()) {
      Novice::ScreenPrintf(20, 40, gLine[1].c_str());
    }
    if (!gLine[2].empty()) {
      Novice::ScreenPrintf(20, 60, gLine[2].c_str());
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

  if (gStarted.load()) {
    if (t1.joinable())
      t1.join();
    if (t2.joinable())
      t2.join();
    if (t3.joinable())
      t3.join();
  }

  // ライブラリの終了
  Novice::Finalize();
  return 0;
}
