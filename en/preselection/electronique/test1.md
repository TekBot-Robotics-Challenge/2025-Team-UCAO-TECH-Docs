# Test 1: Gyroscope and Accelerometer

This test introduces motion sensors: gyroscope and accelerometer.

## Objectives

- Understand IMU sensor operation
- Measure orientation and acceleration
- Process sensor data

## Hardware

- MPU-6050 module
- I2C connections

## Example Code

```python
import smbus

bus = smbus.SMBus(1)
address = 0x68

def read_word(adr):
    # Read data
    pass
```

## References

- [MPU-6050 Datasheet](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)