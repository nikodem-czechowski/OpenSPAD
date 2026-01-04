// DS1124 8-Bit Programmable Timing Element

#ifndef DS1124_h
#define DS1124_h

#include <SPI.h>

class DS1124
{
  public:
    DS1124(int pin);
    int set_timing(int timing); 
  private:
    int _CS_pin;
    
}

#endif // DS1124_h
