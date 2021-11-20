#include "KeyboardWrapped.h"

Napi::FunctionReference KeyboardWrapped::constructor;

Napi::Object KeyboardWrapped::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Keyboard", {
      InstanceMethod("type", &KeyboardWrapped::type),
      InstanceMethod("click", &KeyboardWrapped::click),
      InstanceMethod("clickEnter", &KeyboardWrapped::clickEnter),
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

void KeyboardWrapped::type(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "Expected string.").ThrowAsJavaScriptException();
  }

  Napi::String query = info[0].As<Napi::String>();

  this->_actualClass_->type(query);
}

void KeyboardWrapped::click(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "Expected string.").ThrowAsJavaScriptException();
  }

  Napi::String keyCode = info[0].As<Napi::String>();
  std::string keyCodeString = keyCode.Utf8Value();

  const char *keyCodeStringCharPointer = keyCodeString.c_str();
  char keyCodeStringChar = *keyCodeStringCharPointer;

  this->_actualClass_->click(keyCodeStringChar);
}

void KeyboardWrapped::clickEnter(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_actualClass_->clickEnter();
}
