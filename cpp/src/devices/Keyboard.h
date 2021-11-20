#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <ApplicationServices/ApplicationServices.h>
#include <string>

class Keyboard {
public:
  void type(std::string query);

  void click(char key);

  void clickEnter();

private:
  int mapASCIIToVirtualKey(char key);

  void press(int key);

  void release(int key);
};

#endif
