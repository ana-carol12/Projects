#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

const int pinoLed = 15;
const int buttonPinUp = 19;
const int buttonPinDown = 23;

int brightnessIntensity = 0; // 0–100%

Bounce debouncer_1 = Bounce();
Bounce debouncer_2 = Bounce();

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(pinoLed, OUTPUT);
  digitalWrite(pinoLed, LOW);

  debouncer_2.attach(buttonPinDown, INPUT_PULLUP);
  debouncer_2.interval(25);
  debouncer_1.attach(buttonPinUp, INPUT_PULLUP);
  debouncer_1.interval(25);

  lcd.init();     
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LED Brightness:");

  Serial.println("Ready to control brightness");
}

void loop() {
  debouncer_1.update();
  debouncer_2.update();

  if (debouncer_1.fell()) {
    if (brightnessIntensity < 100) {
      brightnessIntensity += 10;
    }
  }

  if (debouncer_2.fell()) {
    if (brightnessIntensity > 0) {
      brightnessIntensity -= 10;
    }
  }

  int pwmValue = map(brightnessIntensity, 0, 100, 0, 255);
  analogWrite(pinoLed, pwmValue);

  // Atualiza LCD
  lcd.setCursor(0, 1);
  lcd.print("Intensity: ");
  lcd.print(brightnessIntensity);
  lcd.print("%   "); 

  // Debug Serial
  Serial.print("Intensity: ");
  Serial.print(brightnessIntensity);
  Serial.print("% -> PWM: ");
  Serial.println(pwmValue);

  delay(20);
}
