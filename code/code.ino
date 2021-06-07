int Pin1 = A0;
float value1 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(Pin1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("ML:");
  value1 = analogRead(Pin1);
  Serial.println(value1);
}
