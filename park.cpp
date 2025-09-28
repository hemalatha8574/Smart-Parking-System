/*
  Smart Parking System
  Detects car presence in slot using ultrasonic sensor
*/

#define trigPin 2
#define echoPin 3
#define redLed 8
#define greenLed 9

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Smart Parking System Ready...");
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 10) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    Serial.println("Slot: Occupied ❌");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    Serial.println("Slot: Available ✅");
  }

  delay(1000);
}
