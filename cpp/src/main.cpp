#include <napi.h>
#include "_wrapped/MouseWrapped.h"
#include "_wrapped/KeyboardWrapped.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  MouseWrapped::Init(env, exports);
  KeyboardWrapped::Init(env, exports);

  return exports;
}

NODE_API_MODULE(macoskeyboardmouse, InitAll);
