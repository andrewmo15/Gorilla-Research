#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int times = 0;
int switchState;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Times");
}
void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(8);
  if (switchState == HIGH) {
    lcd.setCursor(5, 0);
    times++;
    lcd.print(String(times));
  }
}
