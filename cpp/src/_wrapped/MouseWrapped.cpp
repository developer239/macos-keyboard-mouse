#include "MouseWrapped.h"

Napi::FunctionReference MouseWrapped::constructor;

Napi::Object MouseWrapped::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Mouse", {
      InstanceMethod("getLocation", &MouseWrapped::getLocation),
      InstanceMethod("move", &MouseWrapped::move),
      InstanceMethod("press", &MouseWrapped::press),
      InstanceMethod("setDelay", &MouseWrapped::setDelay),
      InstanceMethod("pressLeft", &MouseWrapped::pressLeft),
      InstanceMethod("pressRight", &MouseWrapped::pressRight),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Mouse", func);
  return exports;
}

MouseWrapped::MouseWrapped(const Napi::CallbackInfo &info) : Napi::ObjectWrap<MouseWrapped>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_actualClass_ = new Mouse();
}

void MouseWrapped::move(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Expected 2 arguments.").ThrowAsJavaScriptException();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "x is not a number.").ThrowAsJavaScriptException();
  }

  if (!info[1].IsNumber()) {
    Napi::TypeError::New(env, "y is not a number.").ThrowAsJavaScriptException();
  }

  Napi::Number x = info[0].As<Napi::Number>();
  Napi::Number y = info[1].As<Napi::Number>();

  this->_actualClass_->move(x, y);
}

Napi::Value MouseWrapped::getLocation(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  CGPoint point = this->_actualClass_->getLocation();

  Napi::Object result = Napi::Object::New(env);
  result.Set("x", point.x);
  result.Set("y", point.y);

  return result;
}

void MouseWrapped::setDelay(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Argument expected.").ThrowAsJavaScriptException();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Argument is not a number.").ThrowAsJavaScriptException();
  }

  Napi::Number ms = info[0].As<Napi::Number>();

  this->_actualClass_->setDelay(ms);
}

void MouseWrapped::press(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Expected 2 arguments.").ThrowAsJavaScriptException();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Button type is not a number.").ThrowAsJavaScriptException();
  }

  if (!info[1].IsBoolean()) {
    Napi::TypeError::New(env, "isDown is not a boolean.").ThrowAsJavaScriptException();
  }

  // TODO: is the type conversion correct?
  int buttonType = info[0].As<Napi::Number>();
  Napi::Boolean shouldPress = info[1].As<Napi::Boolean>();

  CGMouseButton button = CGMouseButton(buttonType);

  this->_actualClass_->press(button, shouldPress);
}

void MouseWrapped::pressLeft(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_actualClass_->pressLeft();
}

void MouseWrapped::pressRight(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_actualClass_->pressRight();
}
