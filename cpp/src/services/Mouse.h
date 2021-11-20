#ifndef __MOUSE_H__
#define __MOUSE_H__

#include <ApplicationServices/ApplicationServices.h>

class Mouse {
public:
  void move(int x, int y);

  CGPoint getLocation();

private:
  void executeEvent(CGMouseButton button, CGEventType type, CGPoint location);
};

#endif
