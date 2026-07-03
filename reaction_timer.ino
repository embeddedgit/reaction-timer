
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int buttonPin = 6;
const int greenLED = 8;
const int redLED = 9;
const int buzzerPin = 10;

unsigned long startTime;
unsigned long reactionTime;
bool waitingForClick = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(A0));
  showStartScreen();
}

void showStartScreen() {
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("   Press to Start");
}

void playStartTune() {
  tone(buzzerPin, 523, 150);
  delay(200);
  tone(buzzerPin, 659, 150);
  delay(200);
  tone(buzzerPin, 784, 300);
  delay(350);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(50);
    while (digitalRead(buttonPin) == LOW);

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("    Be Ready...");
    digitalWrite(greenLED, HIGH);

    playStartTune();

    long randomDelay = random(2000, 6000);
    unsigned long delayStart = millis();
    bool falseStart = false;

    while (millis() - delayStart < randomDelay) {
      if (digitalRead(buttonPin) == LOW) {
        falseStart = true;
        break;
      }
    }

    if (falseStart) {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("     Too Soon!");
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      tone(buzzerPin, 200, 500);

      delay(300);
      while (digitalRead(buttonPin) == HIGH);
      delay(50);
      while (digitalRead(buttonPin) == LOW);

      digitalWrite(redLED, LOW);
      showStartScreen();
      return;
    }

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("      Click!");
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(buzzerPin, 1000, 100);

    startTime = millis();
    waitingForClick = true;

    while (waitingForClick) {
      if (digitalRead(buttonPin) == LOW) {
        reactionTime = millis() - startTime;
        waitingForClick = false;
      }
    }

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(reactionTime);
    lcd.print(" ms");
    lcd.setCursor(0, 2);
    lcd.print("  Press to Start");

    digitalWrite(redLED, LOW);

    delay(300);
    while (digitalRead(buttonPin) == HIGH);
    delay(50);
    while (digitalRead(buttonPin) == LOW);

    showStartScreen();
  }
}