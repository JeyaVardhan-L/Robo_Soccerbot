// =============================
// BTS Motor Direct Test
// Arduino UNO
// =============================

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

  pinMode(L_RPWM, OUTPUT);
  pinMode(L_LPWM, OUTPUT);
  pinMode(L_REN, OUTPUT);
  pinMode(L_LEN, OUTPUT);

  pinMode(R_RPWM, OUTPUT);
  pinMode(R_LPWM, OUTPUT);
  pinMode(R_REN, OUTPUT);
  pinMode(R_LEN, OUTPUT);

  // Enable drivers
  digitalWrite(L_REN, HIGH);
  digitalWrite(L_LEN, HIGH);
  digitalWrite(R_REN, HIGH);
  digitalWrite(R_LEN, HIGH);
}

void loop() {

  // FORWARD
  analogWrite(L_RPWM, 150);
  analogWrite(L_LPWM, 0);

  analogWrite(R_RPWM, 150);
  analogWrite(R_LPWM, 0);

  delay(3000);

  // BRAKE
  digitalWrite(L_RPWM, HIGH);
  digitalWrite(L_LPWM, HIGH);

  digitalWrite(R_RPWM, HIGH);
  digitalWrite(R_LPWM, HIGH);

  delay(2000);

  // BACKWARD
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 150);

  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 150);

  delay(3000);

  // BRAKE
  digitalWrite(L_RPWM, HIGH);
  digitalWrite(L_LPWM, HIGH);

  digitalWrite(R_RPWM, HIGH);
  digitalWrite(R_LPWM, HIGH);

  delay(2000);
}



