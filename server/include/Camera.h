
/**
 * @fileoverview Grab screenshots from window handles and convert them
 *     into 2D arrays of pixels.
 */
#ifndef Camera_H
#define Camera_H

#include "Finkel.h"
#include <vector>
#include <windows.h>

class Camera {
public:
  Camera();

  /**
   * Take a screenshot.
   * @param windowHandle Take a picture of the window on the handle.
   *     Cannot be null.
   * @param _return The 2D pixel array to write into.
   */
  void TakeScreenshot(
    HWND windowHandle,
    std::vector<std::vector<int8_t>> & _return
  );

private:
  /**
   * Convert a BITMAP to a 2D pixel array.
   * @param bitmap Some bitmap.
   * @param _return The 2D pixel array to write into.
   */
  void _Serialize(
    BITMAP bitmap,
    std::vector<std::vector<int8_t>> & _return
  );
};

#endif
