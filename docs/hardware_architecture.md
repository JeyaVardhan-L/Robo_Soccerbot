# Hardware Architecture

## Drive System
- 4 DC motors (300 RPM)
- 2 BTS7960 motor drivers
- Left motors connected in parallel
- Right motors connected in parallel

## Controller
- Arduino UNO

## Receiver
- FlySky receiver
- Channel 1: Steering
- Channel 2: Throttle

## Power System
- 3S LiPo battery (11.1V nominal)
- Buck converter for 5V rail
- 5V powers:
  - Arduino
  - BTS logic
  - Receiver

## Wiring Principles
- All grounds common
- Thick wire for motor power
- Separate signal and power routing
- Active braking used at zero input

This design evolved through multiple debugging stages.