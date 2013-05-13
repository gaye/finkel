
#include "Camera.h"


Camera::Camera() {
}


void Camera::TakeScreenshot(HWND windowHandle,
  std::vector<std::vector<int8_t>> & _return) {
  // Get the dimensions of the window.
  RECT rect;
  GetClientRect(windowHandle, &rect);

  // Setup the in memory device and bitmap handles.
  HDC deviceHandle = GetDC(NULL);
  HDC memDeviceHandle = CreateCompatibleDC(deviceHandle);
  HBITMAP bitmapHandle = CreateCompatibleBitmap(
    deviceHandle,
    rect.right - rect.left /** nWidth */,
    rect.bottom - rect.top /** nHeight */
  );
  SelectObject(memDeviceHandle, bitmapHandle);

  // Print window into memory.
  PrintWindow(windowHandle, memDeviceHandle, PW_CLIENTONLY);

  BITMAP bitmap;
  GetObject(bitmapHandle, sizeof(BITMAP), &bitmap);

  // Release memory.
  DeleteDC(memDeviceHandle);
  DeleteObject(bitmapHandle);
  ReleaseDC(NULL, deviceHandle);

  this->_Serialize(bitmap, _return);
}


void Camera::_Serialize(BITMAP bitmap,
  std::vector<std::vector<int8_t>> & _return) {
  // TODO(gareth)
}
