#include "Mouse.h"

Mouse::Mouse(double value){
    this->value_ = value;
}

double Mouse::getValue()
{
  return this->value_;
}

double Mouse::add(double toAdd)
{
  this->value_ += toAdd;
  return this->value_;
}