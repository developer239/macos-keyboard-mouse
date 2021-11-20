#ifndef __MOUSE_H__
#define __MOUSE_H__

#include <ApplicationServices/ApplicationServices.h>

class Mouse {
public:
  void move(int x, int y);

  void press(CGMouseButton button, bool isButtonDown);

  void pressLeft();

  void pressRight();

  void setDelay(int ms);

  CGPoint getLocation();

private:
  int delayMs = 16;

  void executeEvent(CGMouseButton button, CGEventType type, CGPoint location);
};

#endif
