#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Arduino_Modulino.h>
ModulinoPixels leds;
ModulinoButtons buttons;
Adafruit_BNO055 sensor55 = Adafruit_BNO055();
float standingPitch = 999;
float depthPitch = 999;
bool ledA = false;
bool ledB = false;
//variable name setup for IMU
void setup() {
  Serial.begin(9600);
  sensor55.begin();
  //starts up the IMU
  Modulino.begin();
  buttons.begin();
  leds.begin();
  //starts up the buttons
}

void loop() {
  sensors_event_t event;
  //holds sensor data
  //orientation.x = heading
  //orientation.y = pitch
  //orientation.z = roll
  sensor55.getEvent(&event);
  if (buttons.update()) {
    if (buttons.isPressed('A')) {
      standingPitch = event.orientation.z;
      //if button A is pressed then standing position is set
      ledA = true;
      buttons.setLeds(ledA, ledB, false);
      // turns button led on while keeping others untouched
      } 
    else if (buttons.isPressed('B')) {
      depthPitch = event.orientation.z;
      //if button A is pressed then users depth is set
      ledB = true;
      buttons.setLeds(ledA, ledB, false);
      // turns button led on while keeping others untouched
      }
    else if (buttons.isPressed('C')){
      depthPitch = 999;
      standingPitch = 999;
      ledA = false;
      ledB = false;
      buttons.setLeds(ledA,ledB,false);
      // resets calibration
    }
  }
  Serial.print(event.orientation.z);
  Serial.print(" | depthPitch = ");
  Serial.print(depthPitch);
  Serial.print(" | ");
  if (event.orientation.z <= depthPitch) {
    Serial.println("DEPTH");
    for (int i = 0; i < 8; i++) {
      leds.set(i, GREEN, 25); 
    }
    //turns LEDs to green if squat is valid
    leds.show();
  } else {
    Serial.println("NOT DEPTH");
    for (int i = 0; i < 8; i++) {
      leds.set(i, RED, 25);   
    }
    //turns LEDs to red if squat is invalid
    leds.show();
  }
  // readable format for serial monitor
  delay(50);
}
