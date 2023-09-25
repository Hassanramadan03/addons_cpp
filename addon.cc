#include <node.h>

using namespace v8;

void HelloWorld(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  int sum = 0;
  Local<Array> arr = Local<Array>::Cast(args[0]); // Assuming the array is the first argument

  TryCatch try_catch(isolate);

  for (uint32_t i = 0; i < arr->Length();  i++) {
    Local<Value> element;
    if (!arr->Get(i).ToLocal(&element)) {
      // If there is an exception, skip this element and move on to the next one
      continue;
    }
    if (element->IsNumber()) {
      int value = element->Int32Value(); // Use Int32Value instead of NumberValue
      sum += value;
    }
  }

  if (try_catch.HasCaught()) {
    // If there is an exception, rethrow it to propagate the error to Node.js
    try_catch.ReThrow();
    return;
  }

  // Return the sum as a result
  args.GetReturnValue().Set(sum);
}
void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "helloWorld", HelloWorld);
}

 

NODE_MODULE(addon, Initialize)
