#include "Mouse.h"
#include "../common/delay.h"

CGPoint Mouse::getLocation() {
  CGEventRef event = CGEventCreate(nullptr);
  CGPoint cursor = CGEventGetLocation(event);
  CFRelease(event);

  return CGPointMake(cursor.x, cursor.y);
}

void Mouse::move(int x, int y) {
  CGPoint location = CGPointMake(x, y);
  executeEvent(kCGMouseButtonLeft, kCGEventMouseMoved, location);
}

void Mouse::executeEvent(CGMouseButton button, CGEventType type, CGPoint location) {
  CGEventRef event = CGEventCreateMouseEvent(NULL, type, location, button);
  CGEventPost(kCGHIDEventTap, event);
  CFRelease(event);

  delay(25);
}
