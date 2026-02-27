# Receiver Debug Findings

When testing the FlySky receiver output using pulseIn():

Observed values:

- Minimum ≈ 1200
- Center ≈ 1500
- Maximum ≈ 1800

Important discovery:
The transmitter does NOT output 1000–2000 range.

This required recalibrating mapping logic in firmware.

Without this calibration:
- Robot response felt compressed
- Steering felt incorrect
- Speed scaling was inconsistent

Lesson:
Always measure actual TX output range before mapping.
Never assume 1000–2000.