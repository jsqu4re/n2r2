#ifndef _RGBLED_H_
#define _RGBLED_H_

#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <navio_vendor/Common/Led.h>
#include <navio_vendor/Common/gpio.h>

class RGBled {
public:
  RGBled();

  bool initialize();
  void setColor(Colors color);

private:
  Navio::Pin *pinR;
  Navio::Pin *pinG;
  Navio::Pin *pinB;
};

#endif //_RGBLED_H_
