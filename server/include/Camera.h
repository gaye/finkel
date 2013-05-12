
/**
 * @fileoverview Grab screenshots from window handles.
 */
#ifndef Camera_H
#define Camera_H

#include <windows.h>

class Camera {
public:
  Camera();

  /**
   * Take a screenshot.
   * @param {HWND} windowHandle Take a picture of the window on the handle.
   *     Cannot be null.
   * @return {BITMAPH} Bitmap handle.
   */
  BITMAP TakeScreenshot(HWND windowHandle);
};

#endif
