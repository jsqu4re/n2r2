#ifndef LED_NAVIO2_H
#define LED_NAVIO2_H

#include <navio_vendor/Common/Led.h>
#include <navio_vendor/Navio2/RGBled.h>

class Led_Navio2 : public Led {
public:
  Led_Navio2();
  bool initialize() override;
  void setColor(Colors color) override;

private:
  RGBled led;
};

#endif // LED_NAVIO2_H
