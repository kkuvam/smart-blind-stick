int ledPIN = 7;
int speakerPIN = 9;
int trigPIN = 13;
int echoPIN = 11;
boolean buttonOn = false;

void setup() {
  pinMode(ledPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  pinMode(trigPIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPIN,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPIN,LOW);
  duration = pulseIn(echoPIN,HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
 
  if (distance < 40) {
    digitalWrite(ledPIN, HIGH);
    tone(speakerPIN,1000);
  }
  else {
    digitalWrite(ledPIN, LOW);
    noTone(speakerPIN);
  }
}

