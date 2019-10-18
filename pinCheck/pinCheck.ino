const int ledPin = 13;
int outPin, inPin;
int incomingByte;
int stage = 0;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  while (!Serial);
}

void loop() {
  incomingByte = Serial.read();
  //Serial.println(incomingByte);
  switch (stage) {
    case 0:
      Serial.println("---------");
      Serial.println("Select the test you want to run (Send 0 to come back to this menu)");
      Serial.println("1. Pin13 Led test");
      Serial.println("2. Pin to pin test");
      Serial.println("------------");
      while (!Serial.available());
      stage = 1;
      break;
    case 1:
      if (incomingByte == 49) {
        Serial.println("Send a H or a L");
        stage = 2;
      } else if (incomingByte == 50) {
        Serial.println("Now, please select the output and input pins.");
        stage = 3;
      }
      break;
    case 2:
      while (!Serial.available());
      if (incomingByte == 72) {
        digitalWrite(ledPin, HIGH);
      }
      if (incomingByte == 76) {
        digitalWrite(ledPin, LOW);
      }
      break;
    case 3:
      Serial.println("Select the OUTPUT pin");
      Serial.read();
      while (Serial.available()== 0x00);
      outPin = Serial.parseInt();
      Serial.print("Selected pin: ");
      Serial.println(outPin);
      stage = 4;
      break;
    case 4:
      Serial.println("Select the INPUT pin");
      while (!Serial.available());
      inPin = Serial.parseInt();
      Serial.print("Selected pin: ");
      Serial.println(inPin);
      stage = 5;
      break;
    case 5:
      Serial.print("Please connect a jumper between pin ");
      Serial.print(outPin);
      Serial.print(" and ");
      Serial.println(inPin);
      pinMode(outPin, OUTPUT);
      pinMode(inPin, INPUT);
      Serial.println("Send H or L from the output pin. If you want to read the input pin send an R");
      while (!Serial.available());
      stage = 6;
      break;
    case 6:
      if (incomingByte == 72) {
        digitalWrite(outPin, HIGH);
      }
      if (incomingByte == 76) {
        digitalWrite(outPin, LOW);
      }
      if (incomingByte == 82) {
        Serial.print("Input pin is: ");
        Serial.println(digitalRead(inPin));
        Serial.println("Send H or L from the output pin. If you want to read the input pin send an R");
      }
      while (!Serial.available());
      break;
  }
  if (incomingByte == 48) {
    stage = 0;
  }
}
