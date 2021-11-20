#include "MouseWrapped.h"

Napi::FunctionReference MouseWrapped::constructor;

Napi::Object MouseWrapped::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Mouse", {
    InstanceMethod("add", &MouseWrapped::Add),
    InstanceMethod("getValue", &MouseWrapped::GetValue),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Mouse", func);
  return exports;
}

MouseWrapped::MouseWrapped(const Napi::CallbackInfo& info) : Napi::ObjectWrap<MouseWrapped>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();
  
  if (length != 1) {
    Napi::TypeError::New(env, "Only one argument expected").ThrowAsJavaScriptException();
  }

  if(!info[0].IsNumber()){
    Napi::Object object_parent = info[0].As<Napi::Object>();
    MouseWrapped* example_parent = Napi::ObjectWrap<MouseWrapped>::Unwrap(object_parent);
    Mouse* parent_actual_class_instance = example_parent->GetInternalInstance();
    this->actualClass_ = new Mouse(parent_actual_class_instance->getValue());
    return;
  }

  Napi::Number value = info[0].As<Napi::Number>();
  this->actualClass_ = new Mouse(value.DoubleValue());
}

Napi::Value MouseWrapped::GetValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  double num = this->actualClass_->getValue();
  return Napi::Number::New(env, num);
}


Napi::Value MouseWrapped::Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1 || !info[0].IsNumber()) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }

  Napi::Number toAdd = info[0].As<Napi::Number>();
  double answer = this->actualClass_->add(toAdd.DoubleValue());

  return Napi::Number::New(info.Env(), answer);
}

Mouse* MouseWrapped::GetInternalInstance() {
  return this->actualClass_;
}