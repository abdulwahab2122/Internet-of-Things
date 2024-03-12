Link to the Project + Code

https://www.tinkercad.com/things/iVHwMUeKbFZ-intruder-detector/editel?returnTo=%2Fdashboard%3Fcollection%3Ddesigns&sharecode=QLqD48mVV55H2QZpbTZsAWWASJPJOUZ2vDeB1GfO7eI

// C++ code
//
int distance = 0;

int force = 0;

int switchPin = 2;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  bool isArmed = digitalRead(switchPin);
  if (isArmed) {
    distance = 0.01723 * readUltrasonicDistance(6, 5);
    force = analogRead(A0);
    Serial.println(distance);
    Serial.println(force);
    if (distance <= 250) {
      digitalWrite(10, HIGH);
      delay(5000);
    } else {
      digitalWrite(10, LOW);
    }
    if (force > 700) {
      tone(9, 523, 500); // play tone 60 (C5 = 523 Hz)
    } else {
      noTone(9);
    }
   } 
  else { // If the switch is off (not armed)
    digitalWrite(10, LOW); // Turn off the lamp
    noTone(9); // Turn off the buzzer
  }
  delay(10); // Delay a little bit to improve simulation performance
}
