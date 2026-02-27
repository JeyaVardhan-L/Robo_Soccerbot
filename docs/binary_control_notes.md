# Binary Control Phase Notes

After verifying receiver signals, PWM control was temporarily removed.

Motivation:
- Ensure BTS wiring was correct
- Verify EN pins were properly driven
- Remove complexity from ramping and mapping

Results:
- Motors responded correctly to HIGH/LOW logic
- Forward, backward, and rotation confirmed
- Hardware and wiring validated

Lesson:
When debugging motor drivers, simplify control first.
Binary testing isolates hardware from software issues.