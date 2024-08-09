#include <IRremote.hpp>
#define LED1 A0
#define LED2 A1
#define LED3 A2
#define LED4 A3

unsigned long timer = 0;

bool state1 = false;
bool state2 = false;
bool state3 = false;
bool state4 = false;

void setup() {
  IrReceiver.begin(4, ENABLE_LED_FEEDBACK);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, LOW);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED3, LOW);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED4, LOW);
}

void loop() {
  if ((millis() - timer) > 300) {
    int x = GetData();
    LedAction(x);
    timer = millis();
  }



}


void LedAction(int data) {
  if (data == 22) {
    state1 = !state1;
    digitalWrite(LED1, state1);
  } else if (data == 12) {
    state2 = !state2;
    digitalWrite(LED2, state2);
  } else if (data == 24) {
    state3 = !state3;
    digitalWrite(LED3, state3);
  } else if (data == 94) {
    state4 = !state4;
    digitalWrite(LED4, state4);
  }
}

int GetData() {
  int y = 0;
  if (IrReceiver.decode()) {
    y = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
  }
  return y;
}
