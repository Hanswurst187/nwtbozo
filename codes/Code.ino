#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensor1Pin = 2;
const int sensor2Pin = 3;
const int sensor3Pin = 4;
const int sensor4Pin = 5;
const int sensor5Pin = 6;
const int sensor6Pin = 7;
const int sensor7Pin = 8;
const int sensor8Pin = 9;

int sensor1Count = 0;
int sensor2Count = 0;
int sensor3Count = 0;
int sensor4Count = 0;
int sensor5Count = 0;
int sensor6Count = 0;
int sensor7Count = 0;
int sensor8Count = 0;

int sensor1State = LOW;
int sensor2State = LOW;
int sensor3State = LOW;
int sensor4State = LOW;
int sensor5State = LOW;
int sensor6State = LOW;
int sensor7State = LOW;
int sensor8State = LOW;

unsigned long lastSampleTime = 0;
const unsigned long sampleInterval = 10; // Abtastfrequenz in Millisekunden

void setup() {
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  pinMode(sensor4Pin, INPUT);
  pinMode(sensor5Pin, INPUT);
  pinMode(sensor6Pin, INPUT);
  pinMode(sensor7Pin, INPUT);
  pinMode(sensor8Pin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Total Count: ");
}

void loop() {
  if (millis() - lastSampleTime >= sampleInterval) {
    int sensor1Reading = digitalRead(sensor1Pin);
    if (sensor1Reading != sensor1State) {
      if (sensor1Reading == HIGH) {
        sensor1Count++;
      }
      sensor1State = sensor1Reading;
    }
    int sensor2Reading = digitalRead(sensor2Pin);
    if (sensor2Reading != sensor2State) {
      if (sensor2Reading == HIGH) {
        sensor2Count++;
      }
      sensor2State = sensor2Reading;
    }
    int sensor3Reading = digitalRead(sensor3Pin);
    if (sensor3Reading != sensor3State) {
      if (sensor3Reading == HIGH) {
        sensor3Count++;
      }
      sensor3State = sensor3Reading;
    }
    int sensor4Reading = digitalRead(sensor4Pin);
    if (sensor4Reading != sensor4State) {
      if (sensor4Reading == HIGH) {
        sensor4Count++;
      }
      sensor4State = sensor4Reading;
    }
    int sensor5Reading = digitalRead(sensor5Pin);
    if (sensor5Reading != sensor5State) {
      if (sensor5Reading == HIGH) {
        sensor5Count++;
      }
      sensor5State = sensor5Reading;
    }
    int sensor6Reading = digitalRead(sensor6Pin);
    if (sensor6Reading != sensor6State) {
      if (sensor6Reading == HIGH) {
        sensor6Count++;
      }
      sensor6State = sensor6Reading;
    }
    int sensor7Reading = digitalRead(sensor7Pin);
    if (sensor7Reading != sensor7State) {
      if (sensor7Reading == HIGH) {
        sensor7Count++;
      }
      sensor7State = sensor7Reading;
    }
    int sensor8Reading = digitalRead(sensor8Pin);
    if (sensor8Reading != sensor8State) {
      if (sensor8Reading == HIGH) {
        sensor8Count++;
      }
      sensor8State = sensor8Reading;
    }
    lastSampleTime = millis();
  }
  int totalCount = sensor1Count + sensor2Count + sensor3Count + sensor4Count + sensor5Count + sensor6Count + sensor7Count + sensor8Count ;
  lcd.setCursor(0, 1);
  lcd.print(totalCount);
}

