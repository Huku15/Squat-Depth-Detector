# Squat-Depth-Detector
Wearable squat depth detector utilizing IMU sensor that detects parallel depth and signals with an LED.

## What it does
You strap the sensor to the front of your thigh, calibrate your standing and parallel positions with correlating buttons, and the device tells you when you've reached proper squat depth.

## Why I built this
I'm a competitive powerlifter, and squat depth is one of the most common things that separates a good rep from a failed lift. Judging your own depth mid rep is hard, and a spotter or camera isn't always around. What I wanted was instant, objective feedback whether or not I'm hitting competition depth. As a result I built a wearable that tells me that in real time.

## Why measure the femur
Squat depth is defined by the thigh reaching parallel to the floor, which is the same moment the hip and knee are level. Because the femur rotates 90 degrees from standing to parallel regardless of a person's leg proportions, measuring the thigh's angle works for anyone without hardcoding a fixed number.

## Hardware
- Arduino UNO Q
- Adafruit BNO055 9-DOF IMU
- Arduino Modulino Buttons (I2C)
- Arduino Modulino Pixels (I2C)

## What I learned
- Sensor orientation matters: Mounting orientation changes everything. The IMU reports three orientation axes, but which one tracks the squat depends entirely on how the sensor is physically mounted. When I remounted from side of femur to the front thigh, the axis that had been working went flat.
- Calibrate to the user, don't hardcode:  Because leg proportions differ so I don't rely on set coordinates to determine a valid squat since it may work for one individual but not another.

## Controls
- Button A: set standing position
- Button B: set depth (parallel) position
- Button C: reset calibration
