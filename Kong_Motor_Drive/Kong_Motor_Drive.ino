#include <Conceptinetics.h>

#define DMX_SLAVE_CHANNELS  1
DMX_Slave dmx_slave(DMX_SLAVE_CHANNELS);

#define DRIVER_PUL 2  // Pulse pin
#define DRIVER_DIR 5  // Direction pin

void setup() {
  dmx_slave.enable();
  pinMode(DRIVER_PUL, OUTPUT);
  pinMode(DRIVER_DIR, OUTPUT);
  digitalWrite(DRIVER_DIR, LOW);  // Set direction to low initially
}

void loop() {
  int dmxValue = dmx_slave.getChannelValue(1);
  int speed = map(dmxValue, 0, 255, 2000, 400);
  digitalWrite(DRIVER_PUL, HIGH);
  delayMicroseconds(speed);
  digitalWrite(DRIVER_PUL, LOW);
  delayMicroseconds(speed);
}
