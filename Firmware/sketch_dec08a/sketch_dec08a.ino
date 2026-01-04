#include <SPI.h>

#define VERSION 0.1

// SPI
#define SPI_DIN 11
#define SPI_DOUT 12
#define SPI_SCLK 13
#define SPI_CS_BIAS A0
#define SPI_CS_QUENCH A1
#define SPI_CS_RESET A2

// LED
#define LED1 A3 // inside
#define LED2 A4
#define LED3 A5
#define LED4 A6
#define LED5 5  // panel
#define LED6 6
#define LED7 7
#define LED8 9

// TC
#define TEMPERATURE A7
#define PELT_PWM 3

#define CL_FLAG 2

void setup() { // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Booting OpenSPAD");
  pinMode(CL_FLAG, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  digitalWrite(LED5, 1);
  pinMode(SPI_CS_BIAS, OUTPUT);
  digitalWrite(SPI_CS_BIAS, 1);
  pinMode(SPI_CS_QUENCH, OUTPUT);
  digitalWrite(SPI_CS_QUENCH, 0);
  pinMode(SPI_CS_RESET, OUTPUT);
  digitalWrite(SPI_CS_RESET, 0);
  pinMode(PELT_PWM, OUTPUT);
  // analogWrite(PELT_PWM, 0);
  digitalWrite(PELT_PWM, 0);
  Serial.print("Firmware version: ");
  Serial.println(VERSION);
  delay(500);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16); // Clock = masterclock / 8 = 16 MHz / 8 = 2 MHz (DS1124 is max 10 MHz, MAX1932 is max 2 MHz)
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  digitalWrite(LED5, 0);
  digitalWrite(LED6, 1);

  digitalWrite(SPI_CS_BIAS, 0);
  SPI.transfer(00);
  digitalWrite(SPI_CS_BIAS, 1);
}

byte n = 0;

void loop() { // put your main code here, to run repeatedly:
//  digitalWrite(SPI_CS_RESET, 1);
//  SPI.transfer(n);
//  digitalWrite(SPI_CS_RESET, 0);
//  digitalWrite(SPI_CS_QUENCH, 1);
//  SPI.transfer(n);
//  digitalWrite(SPI_CS_QUENCH, 0);
  digitalWrite(SPI_CS_BIAS, 0);
  SPI.transfer(n);
  digitalWrite(SPI_CS_BIAS, 1);
  // Serial.print("Set value: ");
  // Serial.println(String(n));
  // delay(1); 
  n++;
  if(n>255){
    n = 0;
  }
}
