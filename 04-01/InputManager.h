#pragma once
class InputManager {

private:
  char keys_[256] = {};
  char preKeys_[256] = {};

public:
  void Update();

  const char *GetKeys() const { return keys_; }
  const char *GetPreKeys() const { return preKeys_; }

  bool isTrigger(int key) const { return preKeys_[key] == 0 && keys_[key]; }
  bool isPress(int key) const { return preKeys_[key] && keys_[key]; }
};
