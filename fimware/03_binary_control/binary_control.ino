// ===============================
// PURE DIGITAL CONTROL
// Arduino UNO + 2 BTS7960
// ===============================

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

  if (ch2 > 1550) {
    forward();
  }
  else if (ch2 < 1450) {
    backward();
  }
  else if (ch1 > 1550) {
    rotateRight();
  }
  else if (ch1 < 1450) {
    rotateLeft();
  }
  else {
    brakeAll();
  }
}

void forward() {
  digitalWrite(L_RPWM, HIGH);
  digitalWrite(L_LPWM, LOW);
  digitalWrite(R_RPWM, HIGH);
  digitalWrite(R_LPWM, LOW);
}

void backward() {
  digitalWrite(L_RPWM, LOW);
  digitalWrite(L_LPWM, HIGH);
  digitalWrite(R_RPWM, LOW);
  digitalWrite(R_LPWM, HIGH);
}

void rotateRight() {
  digitalWrite(L_RPWM, HIGH);
  digitalWrite(L_LPWM, LOW);
  digitalWrite(R_RPWM, LOW);
  digitalWrite(R_LPWM, HIGH);
}

void rotateLeft() {
  digitalWrite(L_RPWM, LOW);
  digitalWrite(L_LPWM, HIGH);
  digitalWrite(R_RPWM, HIGH);
  digitalWrite(R_LPWM, LOW);
}

void brakeAll() {
  digitalWrite(L_RPWM, HIGH);
  digitalWrite(L_LPWM, HIGH);
  digitalWrite(R_RPWM, HIGH);
  digitalWrite(R_LPWM, HIGH);
}