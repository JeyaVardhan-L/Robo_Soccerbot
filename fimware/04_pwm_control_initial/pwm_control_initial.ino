// ============================================
// INITIAL PWM CONTROL (Assumed 1000-2000)
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

#define DEADZONE 40
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

  int steer = map(ch1, 1000, 2000, -MAX_PWM, MAX_PWM);
  int throttle = map(ch2, 1000, 2000, -MAX_PWM, MAX_PWM);

  if (abs(steer) < DEADZONE) steer = 0;
  if (abs(throttle) < DEADZONE) throttle = 0;

  int left = throttle + steer;
  int right = throttle - steer;

  left = constrain(left, -MAX_PWM, MAX_PWM);
  right = constrain(right, -MAX_PWM, MAX_PWM);

  driveMotor(left, L_RPWM, L_LPWM);
  driveMotor(right, R_RPWM, R_LPWM);
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