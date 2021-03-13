#include <LiquidCrystal.h>
#include <Servo.h>
#define backlight A4
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo;
int times = 0;
int hours = 0;

boolean leftButton = LOW;
boolean debounceLeft;
boolean rightButton = LOW;
boolean debounceRight;
boolean midButton = LOW;
boolean debounceMid;
const int left = 8;
const int mid = 9;
const int right = 10;
int screen = 0;

boolean isTimes = false;
boolean isHours = false;
boolean positive = false;
long next = 0;

void setup() {
    pinMode(6, OUTPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);

    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print(String(times) + "x for " + String(hours) + " hours  ");
    lcd.setCursor(0,1);
    lcd.print("Times      Hours");
  
    servo.attach(7);
    servo.write(0);

    analogWrite(backlight, 255);
    randomSeed(analogRead(0));
}

void loop() {
    if (isHours && isTimes) {
        analogWrite(backlight, 10);
        while (!positive) {
            next = random(hours * 30 / times);
            if (next > 0) {
                positive = true;
            }
        }
        lcd.clear();
        lcd.print("Spin in " + String(next) + " sec");
        for (int i = 0; i < next; i++) {
            delay(1000);
        }
        digitalWrite(6, HIGH);
        servo.write(180);
        for (int i = 0; i < 3; i++) {
            delay(1000); 
        }
        digitalWrite(6, LOW);
        servo.write(0);
        positive = false;
    } else {
        debounceLeft = debounce(leftButton, left);
        debounceRight = debounce(rightButton, right);
        debounceMid = debounce(midButton, mid);
        toggleLCD();
    }
}

void toggleLCD() {
    if (screen == 0 && debounceLeft == HIGH && leftButton == LOW) {
        leftButton = HIGH;
        screen++;
    } else if (screen == 0 && debounceLeft == LOW && leftButton == HIGH) {
        leftButton = LOW;
    }
    if (screen == 0 && debounceRight == HIGH && rightButton == LOW) {
        rightButton = HIGH;
        screen += 2;
    } else if (screen == 0 && debounceRight == LOW && rightButton == HIGH) {
        rightButton = LOW;
    }
    
    if (screen == 1 && debounceLeft == HIGH && leftButton == LOW) {
        leftButton = HIGH;
        times++;
    } else if (screen == 1 && debounceLeft == LOW && leftButton == HIGH) {
        leftButton = LOW;
    }
    if (screen == 1 && debounceRight == HIGH && rightButton == LOW) {
        rightButton = HIGH;
        if (times > 0) {
            times--; 
        }
    } else if (screen == 1 && debounceRight == LOW && rightButton == HIGH) {
        rightButton = LOW;
    }
    if (screen == 1 && debounceMid == HIGH && midButton == LOW) {
        midButton = HIGH;
        screen--;
        if (times > 0) {
            isTimes = true;
        }
    } else if (screen == 1 && debounceMid == LOW && midButton == HIGH) {
        midButton = LOW;
    }
    
    if (screen == 2 && debounceLeft == HIGH && leftButton == LOW) {
        leftButton = HIGH;
        hours++;
    } else if (screen == 2 && debounceLeft == LOW && leftButton == HIGH) {
        leftButton = LOW;
    }
    if (screen == 2 && debounceRight == HIGH && rightButton == LOW) {
        rightButton = HIGH;
        if (hours > 0) {
          hours--; 
        }
    } else if (screen == 2 && debounceRight == LOW && rightButton == HIGH) {
        rightButton = LOW;
    }
    if (screen == 2 && debounceMid == HIGH && midButton == LOW) {
        midButton = HIGH;
        screen -= 2;
        if (hours > 0) {
            isHours = true;
        }
    } else if (screen == 2 && debounceMid == LOW && midButton == HIGH) {
        midButton = LOW;
    }

    switch (screen) {
        case 0:
            lcd.setCursor(0,0);
            lcd.print(String(times) + "x for " + String(hours) + " hours  ");
            lcd.setCursor(0,1);
            lcd.print("Times      Hours");
            break;
        case 1:
            lcd.setCursor(0,0);
            lcd.print("How many times?");
            lcd.setCursor(0,1);
            lcd.print("++     " + String(times) + "      --");
            break;
        case 2:
            lcd.setCursor(0,0);
            lcd.print("How many hours?");
            lcd.setCursor(0,1);
            lcd.print("++     " + String(hours) + "      --");
        default:
            break;
    }
}

boolean debounce(boolean state, int button) {
    boolean stateNow = digitalRead(button);
    if (state != stateNow) {
      delay(10);
      stateNow = digitalRead(button);
    }
    return stateNow;
}
