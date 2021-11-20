#ifndef __KEYBOARDWRAPPED_H__
#define __KEYBOARDWRAPPED_H__

#include <napi.h>
#include "../devices/Keyboard.h"

class KeyboardWrapped : public Napi::ObjectWrap<KeyboardWrapped> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit KeyboardWrapped(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  Keyboard *_actualClass_;
};

#endif
