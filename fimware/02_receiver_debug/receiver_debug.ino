// ==============================
// Receiver Signal Debug
// Arduino UNO
// ==============================

#define CH1_PIN 2   // Steering
#define CH2_PIN 3   // Throttle

void setup() {
  Serial.begin(115200);
  pinMode(CH1_PIN, INPUT);
  pinMode(CH2_PIN, INPUT);
}

void loop() {

  int ch1 = pulseIn(CH1_PIN, HIGH, 25000);
  int ch2 = pulseIn(CH2_PIN, HIGH, 25000);

  Serial.print("CH1: ");
  Serial.print(ch1);
  Serial.print("   CH2: ");
  Serial.println(ch2);

  delay(100);
}