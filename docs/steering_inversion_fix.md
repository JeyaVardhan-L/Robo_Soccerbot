# Steering Inversion Fix

After calibration, steering direction was reversed.

Symptoms:
- Moving joystick right caused robot to turn left.
- Moving joystick left caused robot to turn right.

Root Cause:
Motor polarity and mixing logic sign mismatch.

Solution:
Invert steering variable in firmware:

    steer = -mapChannel(ch1);

Why firmware fix instead of rewiring?
- Cleaner
- Easier to adjust
- Avoid physical rewiring mistakes

Lesson:
Fix minimal layer necessary.
Prefer logical correction over hardware rewiring when appropriate.