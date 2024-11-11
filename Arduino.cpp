int buttonstate = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonstate = digitalRead(2);
  
  if (buttonstate == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250); // Wait for 250 milliseconds
    digitalWrite(LED_BUILTIN, LOW);
    delay(250); // Wait for 250 milliseconds
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250); // Wait for 250 milliseconds
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000); // Wait for 1000 milliseconds
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
