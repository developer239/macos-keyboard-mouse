#ifndef __MOUSEWRAPPED_H__
#define __MOUSEWRAPPED_H__

#include <napi.h>
#include "../devices/Mouse.h"

class MouseWrapped : public Napi::ObjectWrap<MouseWrapped> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit MouseWrapped(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  Mouse *_actualClass_;

  Napi::Value getLocation(const Napi::CallbackInfo &info);

  void move(const Napi::CallbackInfo &info);

  void press(const Napi::CallbackInfo &info);

  void pressLeft(const Napi::CallbackInfo &info);

  void pressRight(const Napi::CallbackInfo &info);

  void setDelay(const Napi::CallbackInfo &info);
};

#endif
