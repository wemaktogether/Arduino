#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int Vo = A0;
int V_LED = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);

float Vo_value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(V_LED, OUTPUT);
  pinMode(Vo, INPUT);

  // initialize LCD
  lcd.begin();
  lcd.backlight();
  lcd.home();
  lcd.print("Dust Meter(PM25)");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(V_LED, LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_LED, HIGH);
  delayMicroseconds(9680);

  lcd.setCursor(0,1);
  lcd.print(Vo_value);
  //Serial.println(Vo_value);
  delay(500);
}
