
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define buttonPin1 3
#define buttonPin2 4

int buttonState1 = 0;
int buttonState2 = 0;
RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00002";

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == 1)
  {
    buttonState1 = 1;
  }
  else  if (buttonState1 == 0)
  {
    buttonState1 = 0;
  }
  if (buttonState2 == 1)
  {
    buttonState2 = 3;
  }
  else  if (buttonState2 == 0)
  {
    buttonState2 = 2;
  }
  Serial.println(buttonState1);
  Serial.print("\t");
  Serial.println(buttonState2);
  radio.write(&buttonState1, sizeof(buttonState1));
  radio.write(&buttonState2, sizeof(buttonState2));
}
