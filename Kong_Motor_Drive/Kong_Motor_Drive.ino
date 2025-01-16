#include <Conceptinetics.h>

#define DMX_SLAVE_CHANNELS  1
DMX_Slave dmx_slave(DMX_SLAVE_CHANNELS);

#define DRIVER_PUL 2  // Pulse pin
#define DRIVER_DIR 5  // Direction pin
#define ENABLE_PIN 10

void setup() {
  dmx_slave.enable();
  pinMode(DRIVER_PUL, OUTPUT);
  pinMode(DRIVER_DIR, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(DRIVER_DIR, LOW);  // Set direction to low initially
  digitalWrite(ENABLE_PIN, HIGH);  // Set enable high initially (triggers LOW)
}

void loop() {
  int speeddmxValue = dmx_slave.getChannelValue(1);
  int enabledmxValue = dmx_slave.getChannelValue(2);
  
  if (enabledmxValue == 255) {
    digitalWrite(ENABLE_PIN, LOW);
  }
  else {
    digitalWrite(ENABLE_PIN, HIGH);
  }

  int speed = map(speeddmxValue, 0, 255, 2000, 400);
  digitalWrite(DRIVER_PUL, HIGH);
  delayMicroseconds(speed);
  digitalWrite(DRIVER_PUL, LOW);
  delayMicroseconds(speed);

}
