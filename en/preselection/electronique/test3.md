# Test 3: 7-Segment Display

This test concerns the use of 7-segment displays.

## Objectives

- Control a 7-segment display
- Display numbers and letters
- Use shift registers

## Hardware

- 7-segment display
- 74HC595 (shift register)

## Example Code

```python
import RPi.GPIO as GPIO

# Pin configuration
data_pin = 17
clock_pin = 18
latch_pin = 19

def display_digit(digit):
    # Display the digit
    pass
```

## References

- [7-Segment Display](https://en.wikipedia.org/wiki/Seven-segment_display)