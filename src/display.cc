#include <nan.h>

DEVMODE dm;

NAN_METHOD(rotate) {
  if (0 == EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm)) {
    return Nan::ThrowError("Can not read display settings.");
  }

  if (!info[0]->IsUndefined()) {
    dm.dmDisplayOrientation = Nan::To<uint32_t>(info[0]).FromJust();
    if (DISP_CHANGE_SUCCESSFUL != ChangeDisplaySettings(&dm, 0)) {
      return Nan::ThrowError("Can not change display settings.");
    }
  }

  info.GetReturnValue().Set(
    Nan::New<v8::Uint32>((uint32_t)dm.dmDisplayOrientation)
  );
}

NAN_MODULE_INIT(Init) {
  ZeroMemory(&dm, sizeof(dm));
  dm.dmSize = sizeof(dm);

  v8::Local<v8::FunctionTemplate> displayRotateTpl = Nan::New<v8::FunctionTemplate>(rotate);
  Nan::Set(
  	target,
  	Nan::New("rotate").ToLocalChecked(),
  	Nan::GetFunction(displayRotateTpl).ToLocalChecked()
	);
}

NODE_MODULE(DisplayAddon, Init)
