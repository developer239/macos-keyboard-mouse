#include <ApplicationServices/ApplicationServices.h>
#include "delay.h"

void delay(unsigned int ms)
{
  usleep(ms * 1000);
}
