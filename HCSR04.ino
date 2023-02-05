int trig_pin =7;
int echo_pin =6;
int buzzer_pin =5;

int maxRange= 30;
int minRange=0;


void setup() {
 pinMode(7,OUTPUT);
 pinMode(6, INPUT);
 pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 long olcum = mesafe(maxRange, minRange);
 melodi(olcum*10);
 Serial.println(olcum);
}

int mesafe(int maxRange, int minRange)
{
  long duration, distance;
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);

  duration = pulseIn(echo_pin, HIGH);
  distance = duration / 58.2;
  delay(50);

  if(distance>= maxRange || distance <= minRange)
  return 0;
  return distance;

}

int melodi(int dly)
{
  tone(5, 440);
  delay(dly);
  noTone(5);
  delay(dly);
}
