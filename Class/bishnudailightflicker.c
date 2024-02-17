int led = 9; // Pin connected to LED 1
int led1 = 10; // Pin connected to LED 2

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  // Fading LED 1 up
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(led, brightness);
    digitalWrite(led1, HIGH); // Turn on LED 2
    delay(3);
    digitalWrite(led1, LOW); // Turn off LED 2
  }
  
  // Fading LED 1 down
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(led, brightness);
    digitalWrite(led1, HIGH); // Turn on LED 2
    delay(3);
    digitalWrite(led1, LOW); // Turn off LED 2
  }
}

