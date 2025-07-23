#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 9, 4, 5, 6, 7);
int trig = 12;
int echo = 3;
long pulse_length;
void setup() {
  //set display dimensions *16 columns, 2 rows
  lcd.begin(16, 2);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delay(10);

  //send pulse
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //calcuate length of pulse
  pulse_length = pulseIn(echo, HIGH);
  float distance = pulse_length * 0.017;
  Serial.println(distance);
  //print distance on lcd display
  lcd.print("Distance= ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print("cm");
  delay(500);
  lcd.clear();
}
