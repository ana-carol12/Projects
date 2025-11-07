// ------------------------ BLUETOOTH SLAVE COM BOTÃO ------------------------
#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;

const int ledPin = 2;    // LED interno do ESP32
const int buttonPin = 4; // Botão no GPIO 4
bool ledState = false;
bool blinking = false;

unsigned long buttonPressTime = 0;
unsigned long buttonReleaseTime = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Botão com pull-up interno

  if (BT.begin("ESP32_SLAVE_BUTTON")) {
    Serial.println("Bluetooth iniciado com sucesso (modo SLAVE)");
    Serial.print("Endereço Bluetooth: ");
    Serial.println(BT.getBtAddressString());
  } else {
    Serial.println("Erro ao iniciar o Bluetooth!");
    while (true);
  }

  Serial.println("\nAguardando comandos via Bluetooth ou botão...");
  Serial.println("Comandos: liga / desliga / pisca");
}

void loop() {
  // ------------------------ COMANDOS VIA BLUETOOTH ------------------------
  if (BT.available()) {
    String cmd = BT.readStringUntil('\n');
    cmd.trim();
    cmd.toLowerCase();

    Serial.printf("Comando recebido: %s\n", cmd.c_str());

    if (cmd == "liga") {
      ledState = true;
      blinking = false;
      digitalWrite(ledPin, HIGH);
      BT.println("LED ligado!");
    }
    else if (cmd == "desliga") {
      ledState = false;
      blinking = false;
      digitalWrite(ledPin, LOW);
      BT.println("LED desligado!");
    }
    else if (cmd == "pisca") {
      blinking = true;
      Serial.println("Iniciando piscar...");
      BT.println("LED piscando...");
    }
    else {
      BT.println("Comando inválido!");
    }
  }

  // ------------------------ CONTROLE PELO BOTÃO ------------------------
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !buttonPressed) {
    // Botão pressionado
    buttonPressed = true;
    buttonPressTime = millis();
  }

  if (buttonState == HIGH && buttonPressed) {
    // Botão solto
    buttonPressed = false;
    buttonReleaseTime = millis();

    unsigned long pressDuration = buttonReleaseTime - buttonPressTime;

    if (pressDuration < 2000) {
      // Clique curto → alterna LED
      if (blinking) {
        blinking = false;
        digitalWrite(ledPin, LOW);
        ledState = false;
        Serial.println("Parando piscar, LED desligado.");
      } else {
        ledState = !ledState;
        digitalWrite(ledPin, ledState ? HIGH : LOW);
        Serial.printf("Clique curto -> LED %s\n", ledState ? "ligado" : "desligado");
      }
    } else {
      // Pressionado por mais de 2 segundos → piscar
      if (!blinking) {
        blinking = true;
        Serial.println("Long press -> iniciando piscar");
      } else {
        blinking = false;
        digitalWrite(ledPin, LOW);
        Serial.println("Parando piscar, LED desligado.");
      }
    }
  }

  // ------------------------ PISCAR O LED ------------------------
  static unsigned long lastBlink = 0;
  if (blinking && millis() - lastBlink > 300) {
    lastBlink = millis();
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
