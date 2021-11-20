#ifndef __MOUSEWRAPPED_H__
#define __MOUSEWRAPPED_H__

#include <napi.h>
#include "../services/Mouse.h"

class MouseWrapped : public Napi::ObjectWrap<MouseWrapped> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  MouseWrapped(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  Mouse *_actualClass_;

  Napi::Value getLocation(const Napi::CallbackInfo &info);
  void move(const Napi::CallbackInfo &info);
};

#endif
