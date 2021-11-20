#include <napi.h>
#include "Mouse.h"

class MouseWrapped : public Napi::ObjectWrap<MouseWrapped> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  MouseWrapped(const Napi::CallbackInfo& info);
  Mouse* GetInternalInstance();

 private:
  static Napi::FunctionReference constructor;
  Napi::Value GetValue(const Napi::CallbackInfo& info);
  Napi::Value Add(const Napi::CallbackInfo& info);
  Mouse *actualClass_;
};
