#include "KeyboardWrapped.h"

Napi::FunctionReference KeyboardWrapped::constructor;

Napi::Object KeyboardWrapped::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Keyboard", {

  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Keyboard", func);
  return exports;
}

KeyboardWrapped::KeyboardWrapped(const Napi::CallbackInfo &info) : Napi::ObjectWrap<KeyboardWrapped>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_actualClass_ = new Keyboard();
}
