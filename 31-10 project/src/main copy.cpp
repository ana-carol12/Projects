#include <Arduino.h>
#include <string.h>

void handleSerialCommand();
void parseTemperatureMessage();
void detectArduinoKeyword();
void textFormattingDemo();

bool ledOn = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Boot complete. System initialized.");
  Serial.println("=================================");

  parseTemperatureMessage();
  Serial.println("=================================");

  detectArduinoKeyword();
  Serial.println("=================================");

  textFormattingDemo();
  Serial.println("=================================");
  
  Serial.println("Ready for input (try: LED ON / LED OFF)");
}

void loop() {
  handleSerialCommand();
}

void handleSerialCommand() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command.length() == 0) return;

    command.toUpperCase(); // make input case-insensitive

    if (command.indexOf("ON") >= 0) {
      Serial.println("→ Turning LED ON");
      ledOn = true;
    } 
    else if (command.indexOf("OFF") >= 0) {
      Serial.println("→ Turning LED OFF");
      ledOn = false;
    } 
    else {
      Serial.println("⚠ Unknown command");
    }

    Serial.printf("Received: %s\n", command.c_str());
    Serial.printf("LED status: %s\n\n", ledOn ? "ON" : "OFF");
  }
}

void parseTemperatureMessage() {
  Serial.println("Running temperature parser...");

  String data = "Temp: 25C recorded";
  int start = data.indexOf(':') + 1;
  int end = data.indexOf('C');
  String tempText = data.substring(start, end);
  tempText.trim();

  int celsius = tempText.toInt();
  float fahrenheit = celsius * 1.8 + 32;

  Serial.printf("Raw message: %s\n", data.c_str());
  Serial.printf("Extracted temperature: %d°C (%.1f°F)\n", celsius, fahrenheit);
}

void detectArduinoKeyword() {
  Serial.println("Checking for keyword...");

  char text[] = "Learning ESP32 programming today";
  const char* keyword = "ARDUINO";

  Serial.printf("Text: %s\n", text);

  if (strstr(text, keyword) != NULL) {
    Serial.println("Found keyword related to Arduino!");
  } else {
    Serial.println("No Arduino reference detected.");
  }
}

void textFormattingDemo() {
  Serial.println("Text formatting demonstration...");

  String phrase = "hElLo eSp32 wOrLd";
  Serial.print("Original: ");
  Serial.println(phrase);

  String upper = phrase;
  upper.toUpperCase();
  Serial.print("Uppercase: ");
  Serial.println(upper);

  String lower = phrase;
  lower.toLowerCase();
  Serial.print("Lowercase: ");
  Serial.println(lower);

  // Capitalize first character properly
  lower[0] = toupper(lower[0]);
  Serial.print("Capitalized: ");
  Serial.println(lower);
}
