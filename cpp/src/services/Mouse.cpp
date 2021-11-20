#include "Mouse.h"
#include "../common/delay.h"

CGPoint Mouse::getLocation() {
  CGEventRef event = CGEventCreate(nullptr);
  CGPoint cursor = CGEventGetLocation(event);
  CFRelease(event);

  return CGPointMake(cursor.x, cursor.y);
}

void Mouse::click(int button, bool shouldPress) {
  CGPoint location = getLocation();
  CGEventType typePress;
  CGEventType typeRelease;

  switch (button) {
    case kCGMouseButtonLeft:
      typePress = shouldPress ? kCGEventLeftMouseDown : kCGEventLeftMouseUp;
      typeRelease = shouldPress ? kCGEventLeftMouseUp : kCGEventLeftMouseDown;
      break;

    case kCGMouseButtonRight:
      typePress = shouldPress ? kCGEventRightMouseDown : kCGEventRightMouseUp;
      typeRelease = shouldPress ? kCGEventRightMouseUp : kCGEventRightMouseDown;
      break;
  };

  CGMouseButton type = CGMouseButton(button);

  executeEvent(type, typePress, location);
  executeEvent(type, typeRelease, location);
}

void Mouse::move(int x, int y) {
  CGPoint location = CGPointMake(x, y);
  executeEvent(kCGMouseButtonLeft, kCGEventMouseMoved, location);
}

void Mouse::executeEvent(CGMouseButton button, CGEventType type, CGPoint location) {
  CGEventRef event = CGEventCreateMouseEvent(NULL, type, location, button);
  CGEventPost(kCGHIDEventTap, event);
  CFRelease(event);

  delay(delayMs);
}

void Mouse::setDelay(int ms) {
  delayMs = ms;
}
