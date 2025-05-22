#define ENA 10
#define M1A 9
#define M1B 8
#define M2A 7
#define M2B 6
#define ENB 5
#define IRS_L A0
#define IRS_R A1
#define ECHO A2
#define TRIG A3
#define SERVO A5

int threshold = 15;
int distLeft, distFront, distRight;

void setup() {
  Serial.begin(9600);

  pinMode(IRS_R, INPUT);
  pinMode(IRS_L, INPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(SERVO, OUTPUT);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  for (int ang = 70; ang <= 140; ang += 5) moveServo(SERVO, ang);
  for (int ang = 140; ang >= 0; ang -= 5) moveServo(SERVO, ang);
  for (int ang = 0; ang <= 70; ang += 5) moveServo(SERVO, ang);

  distFront = readDistance();
  delay(500);
}

void loop() {
  distFront = readDistance();
  Serial.print("Front = "); Serial.println(distFront);

  if ((digitalRead(IRS_R) == 0) && (digitalRead(IRS_L) == 0)) {
    if (distFront > threshold) driveForward();
    else checkSides();
  } else if ((digitalRead(IRS_R) == 1) && (digitalRead(IRS_L) == 0)) {
    steerRight();
  } else if ((digitalRead(IRS_R) == 0) && (digitalRead(IRS_L) == 1)) {
    steerLeft();
  }

  delay(10);
}

void moveServo(int pin, int ang) {
  int pwm = (ang * 11) + 500;
  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(pin, LOW);
  delay(50);
}

long readDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  long t = pulseIn(ECHO, HIGH);
  return t / 29 / 2;
}

void comparePaths() {
  if (distLeft > distRight) {
    steerLeft(); delay(500);
    driveForward(); delay(600);
    steerRight(); delay(500);
    driveForward(); delay(600);
    steerRight(); delay(400);
  } else {
    steerRight(); delay(500);
    driveForward(); delay(600);
    steerLeft(); delay(500);
    driveForward(); delay(600);
    steerLeft(); delay(400);
  }
}

void checkSides() {
  halt(); delay(100);

  for (int ang = 70; ang <= 140; ang += 5) moveServo(SERVO, ang);
  delay(300);
  distRight = readDistance();
  Serial.print("Right = "); Serial.println(distRight);
  delay(100);

  for (int ang = 140; ang >= 0; ang -= 5) moveServo(SERVO, ang);
  delay(500);
  distLeft = readDistance();
  Serial.print("Left = "); Serial.println(distLeft);
  delay(100);

  for (int ang = 0; ang <= 70; ang += 5) moveServo(SERVO, ang);
  delay(300);

  comparePaths();
}

void driveForward() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);
}

void reverse() {
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}

void steerRight() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
}

void steerLeft() {
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);
}

void halt() {
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);
}
