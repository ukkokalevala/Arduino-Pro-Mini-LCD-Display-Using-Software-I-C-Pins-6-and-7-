#ifndef LiquidCrystal_I2C_soft_h
#define LiquidCrystal_I2C_soft_h

#include <Arduino.h>
#include <SoftwareWire.h>

class LiquidCrystal_I2C {
  private:
    SoftwareWire* _wire;
    uint8_t _addr;

    void expanderWrite(uint8_t data) {
      _wire->beginTransmission(_addr);
      _wire->write(data | 0x08);
      _wire->endTransmission();
    }

    void pulseEnable(uint8_t data) {
      expanderWrite(data | 0x04);
      delayMicroseconds(1);
      expanderWrite(data & ~0x04);
      delayMicroseconds(50);
    }

    void write4bits(uint8_t value) {
      expanderWrite(value);
      pulseEnable(value);
    }

    void send(uint8_t value, uint8_t mode) {
      uint8_t highnib = value & 0xF0;
      uint8_t lownib  = (value << 4) & 0xF0;
      write4bits(highnib | mode);
      write4bits(lownib | mode);
    }

  public:
    LiquidCrystal_I2C(SoftwareWire* wire, uint8_t addr) {
      _wire = wire;
      _addr = addr;
    }

    void init() {
      _wire->begin();
      delay(50);

      write4bits(0x30);
      delay(5);
      write4bits(0x30);
      delayMicroseconds(150);
      write4bits(0x30);
      write4bits(0x20);

      command(0x28);
      command(0x0C);
      command(0x06);
      command(0x01);
      delay(2);
    }

    void command(uint8_t value) {
      send(value, 0);
    }

    void print(const char* str) {
      while (*str) {
        send(*str++, 1);
      }
    }

    void setCursor(uint8_t col, uint8_t row) {
      uint8_t row_offsets[] = {0x00, 0x40};
      command(0x80 | (col + row_offsets[row]));
    }

    void backlight() {
      expanderWrite(0x08);
    }
};

#endif
