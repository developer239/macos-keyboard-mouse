#include <napi.h>
#include "services/classexample.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  ClassExample::Init(env, exports);

  return exports;
}

NODE_API_MODULE(macoskeyboardmouse, InitAll);
