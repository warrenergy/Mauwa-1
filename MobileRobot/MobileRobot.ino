const int IN1 = 8;

const int IN2 = 9;

const int IN3 = 10;

const int IN4 = 11;

const int trigPin = 7;

const int echoPin = 6;

const float DISTANCE_MIN = 20.0;

float mesurerDistance() {

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duree = pulseIn(echoPin, HIGH, 30000);

  if (duree == 0) {

    return 999.0;

  }

  return duree * 0.0343 / 2.0;

}

void avancer() {

  digitalWrite(IN1, LOW);

  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);

  digitalWrite(IN4, LOW);

}

void reculer() {

  digitalWrite(IN1, HIGH);

  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);

  digitalWrite(IN4, HIGH);

}

void tournerDroite() {

  digitalWrite(IN1, LOW);

  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);

  digitalWrite(IN4, HIGH);

}

void arreter() {

  digitalWrite(IN1, LOW);

  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);

  digitalWrite(IN4, LOW);

}

void setup() {

  pinMode(IN1, OUTPUT);

  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);

  pinMode(IN4, OUTPUT);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  arreter();

  delay(1000);

}

void loop() {

  float distance = mesurerDistance();

  Serial.print("Distance : ");

  Serial.print(distance);

  Serial.println(" cm");

 if (distance > 20) {
   avancer();
 } else {
   arreter();
   delay(300);
   reculer();
   delay(600);
   arreter();
   delay(200);
   tournerDroite();
   delay(600);
   arreter();
   delay(200);
 }
 delay(50);
}
 