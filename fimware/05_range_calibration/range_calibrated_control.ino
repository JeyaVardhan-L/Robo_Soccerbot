// ============================================
// PWM Control With Proper TX Calibration
// TX Range: 1200–1800
// ============================================

#define CH1_PIN 2
#define CH2_PIN 3

#define L_RPWM 5
#define L_LPWM 6
#define L_REN  7
#define L_LEN  8

#define R_RPWM 9
#define R_LPWM 10
#define R_REN  11
#define R_LEN  12

#define TX_MIN 1200
#define TX_MID 1500
#define TX_MAX 1800

#define DEADZONE 30
#define MAX_PWM 200

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

  int steer = mapChannel(ch1);
  int throttle = mapChannel(ch2);

  int left = throttle + steer;
  int right = throttle - steer;

  left = constrain(left, -MAX_PWM, MAX_PWM);
  right = constrain(right, -MAX_PWM, MAX_PWM);

  driveMotor(left, L_RPWM, L_LPWM);
  driveMotor(right, R_RPWM, R_LPWM);
}

int mapChannel(int value) {

  if (value > TX_MID - DEADZONE && value < TX_MID + DEADZONE)
    return 0;

  if (value >= TX_MID)
    return map(value, TX_MID, TX_MAX, 0, MAX_PWM);
  else
    return map(value, TX_MIN, TX_MID, -MAX_PWM, 0);
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
    digitalWrite(rpwm, HIGH);
    digitalWrite(lpwm, HIGH);
  }
}