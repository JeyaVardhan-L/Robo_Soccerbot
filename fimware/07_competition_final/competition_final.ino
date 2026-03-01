// ============================================
// FINAL STABLE COMPETITION CODE
// Arduino UNO + 2 BTS7960
// TX Range: 1200 - 1800
// Steering inverted only
// ============================================

// Receiver pins
#define CH1_PIN 2   // Steering
#define CH2_PIN 3   // Throttle

// LEFT BTS
#define L_RPWM 5
#define L_LPWM 6
#define L_REN  7
#define L_LEN  8

// RIGHT BTS
#define R_RPWM 9
#define R_LPWM 10
#define R_REN  11
#define R_LEN  12

// Transmitter calibration
#define TX_MIN 1200
#define TX_MID 1500
#define TX_MAX 1800

// Control tuning
#define DEADZONE 30
#define MAX_PWM 200
#define RAMP_STEP 5
#define SIGNAL_TIMEOUT 100

unsigned long lastSignalTime = 0;

int leftOut = 0;
int rightOut = 0;
int targetLeft = 0;
int targetRight = 0;

void setup() {

  pinMode(CH1_PIN, INPUT);
  pinMode(CH2_PIN, INPUT);

  pinMode(L_RPWM, OUTPUT);
  pinMode(L_LPWM, OUTPUT);
  pinMode(L_REN, OUTPUT);
  pinMode(L_LEN, OUTPUT);

  pinMode(R_RPWM, OUTPUT);
  pinMode(R_LPWM, OUTPUT);
  pinMode(R_REN, OUTPUT);
  pinMode(R_LEN, OUTPUT);

  digitalWrite(L_REN, HIGH);
  digitalWrite(L_LEN, HIGH);
  digitalWrite(R_REN, HIGH);
  digitalWrite(R_LEN, HIGH);
}

void loop() {

  int ch1 = pulseIn(CH1_PIN, HIGH, 25000);
  int ch2 = pulseIn(CH2_PIN, HIGH, 25000);

  if (ch1 > 1000 && ch2 > 1000) {
    lastSignalTime = millis();

    int steer = -mapChannel(ch1);   // Steering inverted only
    int throttle = mapChannel(ch2);

    targetLeft  = throttle + steer;
    targetRight = throttle - steer;

    targetLeft  = constrain(targetLeft,  -MAX_PWM, MAX_PWM);
    targetRight = constrain(targetRight, -MAX_PWM, MAX_PWM);
  }

  // Failsafe
  if (millis() - lastSignalTime > SIGNAL_TIMEOUT) {
    targetLeft = 0;
    targetRight = 0;
  }

  leftOut  = ramp(leftOut,  targetLeft);
  rightOut = ramp(rightOut, targetRight);

  driveMotor(leftOut,  L_RPWM, L_LPWM);
  driveMotor(rightOut, R_RPWM, R_LPWM);
}

int mapChannel(int value) {

  if (value > TX_MID - DEADZONE && value < TX_MID + DEADZONE)
    return 0;

  if (value >= TX_MID)
    return map(value, TX_MID, TX_MAX, 0, MAX_PWM);
  else
    return map(value, TX_MIN, TX_MID, -MAX_PWM, 0);
}

int ramp(int current, int target) {
  if (current < target) {
    current += RAMP_STEP;
    if (current > target) current = target;
  }
  else if (current > target) {
    current -= RAMP_STEP;
    if (current < target) current = target;
  }
  return current;
}

void driveMotor(int value, int rpwm, int lpwm) {

  if (value > 0) {
    analogWrite(rpwm, value);
    analogWrite(lpwm, 0);
  }
  else if (value < 0) {
    analogWrite(rpwm, 0);
    analogWrite(lpwm, -value);
  }
  else {
    // Active brake
    digitalWrite(rpwm, HIGH);
    digitalWrite(lpwm, HIGH);
  }
}