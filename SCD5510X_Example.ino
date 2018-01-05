//This is example code for load data bit to SCD5510X 10 digits 5x5 display from osram (or siemens).

#include <SPI.h> //init. library for spi device .I will communicate with SCD5510X via SPI bus interface .
int Load= 10; //set pin SS or device enable(data input control)

void setup(){
pinMode(Load, OUTPUT);//set pin10 to output for switching "send bit" or "display data out"
SPI.begin(); //init. SPI Library .
SPI.setBitOrder(LSBFIRST);//Swap bit from MSB to LSB as first .arcoding to scd5510X datasheet .Thy start at d0 but arduino start bit at d7(8 bit SPI)
sendCommand(0xC0); // clear display
sendCommand(0xF8); // test lamp
delay(1000); // just wait for 1 sec ;D
sendCommand(0xC0); // clear display after test lamp
sendCommand(0xF6); // test lamp
}

void sendCommand(byte cmd) {
  digitalWrite(Load, LOW);
  SPI.transfer(cmd);
  digitalWrite(Load, HIGH);
}

void loop(){

sendCommand(0xB0);// select digit 0 for'T'
sendCommand(0x1F);//11111
sendCommand(0x24);//00100
sendCommand(0x44);//00100   T
sendCommand(0x64);//00100
sendCommand(0x84);//00100
sendCommand(0xB1);// select digit 1 for 'i'
sendCommand(0x04);//00100
sendCommand(0x20);//00000
sendCommand(0x4C);//01100   i
sendCommand(0x64);//00100
sendCommand(0x8E);//01110
sendCommand(0xB2);// select digit 2 for'n'
sendCommand(0x00);//00000
sendCommand(0x36);//10110
sendCommand(0x59);//11001   n
sendCommand(0x71);//10001
sendCommand(0x91);//10001
sendCommand(0xB3);// select digit 3 for 'L'
sendCommand(0x10);//10000
sendCommand(0x30);//10000
sendCommand(0x50);//10000   L
sendCommand(0x70);//10000
sendCommand(0x9F);//11111
sendCommand(0xB4);// select digit 4 for'e'
sendCommand(0x00);//00000
sendCommand(0x2E);//01110
sendCommand(0x5F);//11111   e
sendCommand(0x70);//10000
sendCommand(0x8E);//01110
sendCommand(0xB5);// select digit 5 for't'
sendCommand(0x08);//11111
sendCommand(0x3C);//00100
sendCommand(0x48);//00100   t
sendCommand(0x6A);//00100
sendCommand(0x84);//00100
sendCommand(0xB6);// select digit 6 for'H'
sendCommand(0x11);//10001
sendCommand(0x31);//10001
sendCommand(0x5F);//11111   H
sendCommand(0x71);//10001
sendCommand(0x91);//10001
sendCommand(0xB7);// select digit 7 for 'a'
sendCommand(0x00);//00000
sendCommand(0x2E);//01110
sendCommand(0x52);//10010   a
sendCommand(0x72);//10010
sendCommand(0x8D);//01101
sendCommand(0xB8);// select digit 8 for'x'
sendCommand(0x00);//00000
sendCommand(0x32);//10010
sendCommand(0x4C);//01100   x
sendCommand(0x6C);//01100
sendCommand(0x92);//10001
sendCommand(0xB9);// select digit 9 for '!'
sendCommand(0x04);//00100
sendCommand(0x24);//00100
sendCommand(0x44);//00100   !
sendCommand(0x60);//00000
sendCommand(0x84);//00100
}
