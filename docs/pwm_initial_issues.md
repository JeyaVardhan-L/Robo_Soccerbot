# Initial PWM Control Issues

The first PWM implementation assumed the transmitter output range was 1000–2000.

However, actual measured range was 1200–1800.

This caused:

- Reduced resolution
- Non-linear feel
- Compressed control response
- Steering felt inconsistent

Lesson:
Never assume transmitter output range.
Always measure using Serial before mapping.