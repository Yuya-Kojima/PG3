#include <Novice.h>
#include <atomic>
#include <condition_variable>
#include <fstream>
#include <mutex>
#include <queue>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

const char kWindowTitle[] = "学籍番号";

static std::vector<std::vector<int>> LoadCsv01(const std::string &path) {
  std::ifstream ifs(path);
  if (!ifs.is_open())
    return {};

  std::vector<std::vector<int>> grid;
  std::string line;

  while (std::getline(ifs, line)) {
    if (line.empty())
      continue;

    std::vector<int> row;
    std::stringstream ss(line);
    std::string cell;

    while (std::getline(ss, cell, ',')) {
      row.push_back((cell.find('1') != std::string::npos) ? 1 : 0);
    }

    if (!row.empty())
      grid.push_back(std::move(row));
  }

  size_t maxW = 0;
  for (auto &r : grid)
    maxW = (std::max)(maxW, r.size());
  for (auto &r : grid)
    r.resize(maxW, 0);

  return grid;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

  // ライブラリの初期化
  Novice::Initialize(kWindowTitle, 1280, 720);

  // キー入力結果を受け取る箱
  char keys[256] = {0};
  char preKeys[256] = {0};

  const std::string csvPath = "stage.csv";

  std::mutex mutex;
  std::condition_variable condition;
  std::queue<int> q;
  bool exit = false;

  std::vector<std::vector<int>> sharedMap;
  bool mapReady = false;

  std::thread th([&]() {
    while (!exit) {

      {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        condition.wait(uniqueLock, [&]() { return exit || !q.empty(); });

        if (exit) {
          break;
        }

        q.pop();
      }

      auto loaded = LoadCsv01(csvPath);

      {
        std::lock_guard<std::mutex> lock(mutex);
        sharedMap = std::move(loaded);
        mapReady = true;
      }
    }
  });

  {
    std::lock_guard<std::mutex> lock(mutex);
    q.push(1);
  }
  condition.notify_all();

  const int tile = 32;
  const int ox = 32;
  const int oy = 64;

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

    ///
    /// ↑更新処理ここまで
    ///

    ///
    /// ↓描画処理ここから
    ///

    std::vector<std::vector<int>> current;

    {
      std::lock_guard<std::mutex> lock(mutex);
      if (mapReady) {
        current = sharedMap;
      }
    }

    if (!current.empty()) {
      const int h = (int)current.size();
      const int w = (int)current[0].size();

      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          if (current[y][x] == 1) {
            Novice::DrawBox(ox + x * tile, oy + y * tile, tile - 1, tile - 1,
                            0.0f, 0xFFFFFFFF, kFillModeSolid);
          }
        }
      }
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

  {
    std::lock_guard<std::mutex> lock(mutex);
    exit = true;
  }
  condition.notify_all();

  th.join();

  // ライブラリの終了
  Novice::Finalize();
  return 0;
}
