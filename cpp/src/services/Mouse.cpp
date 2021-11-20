#include "Mouse.h"
#include "../common/delay.h"

CGPoint Mouse::getLocation() {
  CGEventRef event = CGEventCreate(nullptr);
  CGPoint cursor = CGEventGetLocation(event);
  CFRelease(event);

  return CGPointMake(cursor.x, cursor.y);
}

void Mouse::press(CGMouseButton button, bool isButtonDown) {
  CGPoint location = getLocation();
  CGEventType typePress;
  CGEventType typeRelease;

  switch (button) {
    case kCGMouseButtonLeft:
      typePress = isButtonDown ? kCGEventLeftMouseDown : kCGEventLeftMouseUp;
      typeRelease = isButtonDown ? kCGEventLeftMouseUp : kCGEventLeftMouseDown;
      break;

    case kCGMouseButtonRight:
      typePress = isButtonDown ? kCGEventRightMouseDown : kCGEventRightMouseUp;
      typeRelease = isButtonDown ? kCGEventRightMouseUp : kCGEventRightMouseDown;
      break;
  };

  executeEvent(button, typePress, location);
  executeEvent(button, typeRelease, location);
}

void Mouse::move(int x, int y) {
  CGPoint location = CGPointMake(x, y);
  executeEvent(kCGMouseButtonLeft, kCGEventMouseMoved, location);
}

void Mouse::executeEvent(CGMouseButton button, CGEventType type, CGPoint location) {
  CGEventRef event = CGEventCreateMouseEvent(nullptr, type, location, button);
  CGEventPost(kCGHIDEventTap, event);
  CFRelease(event);

  delay(delayMs);
}

void Mouse::setDelay(int ms) {
  delayMs = ms;
}
