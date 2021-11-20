#include <napi.h>
#include "_wrapped/MouseWrapped.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  MouseWrapped::Init(env, exports);

  return exports;
}

NODE_API_MODULE(macoskeyboardmouse, InitAll);
