**Arduino Pro Mini LCD Display Using Software I²C (Pins 6 and 7)**

This project demonstrates how to connect and operate a 16x2 I²C LCD display with an Arduino Pro Mini 
using software-based I²C communication on digital pins 6 (SDA) and 7 (SCL). The standard hardware I²C pins (A4 and A5) were unavailable, 
so a custom SoftwareWire solution was implemented to create a virtual I²C bus.

A modified LCD library was used to communicate with the LCD's I²C backpack through the software I²C interface. 
The display successfully shows text messages such as "Hello World" without requiring the Arduino's dedicated I²C pins.

This approach provides a flexible solution when the hardware I²C pins are already in use, 
allowing the LCD to operate on alternative digital pins while maintaining the simplicity of an I²C connection. 
The project demonstrates software-based communication, LCD interfacing, 
and efficient use of limited microcontroller resources on the ATmega168-based Arduino Pro Mini.

the temporary library LiquidCrystal_I2C_soft.h help to make the text visible.
