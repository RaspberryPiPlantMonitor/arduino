#define powerPin 4
#define humidityPin A0

float humidityValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(humidityPin, INPUT);
  pinMode(powerPin, OUTPUT);

  digitalWrite(powerPin, LOW); 
}

void loop() {
  // Check data comming from Raspberry Pi USB port
  String data = Serial.readStringUntil('\n');
  if (data.length() == 0) { return; }
  
  humidityValue = analogRead(humidityPin);
  Serial.print("{humidityValue:"+String(humidityValue)+",powerValue:"+data[0]+","+"pumpValue:"+data[1]+"}\n");

  // Control IoT Relay
  if (data[0] == '1'){
    digitalWrite(powerPin, HIGH);  
  } else {
    digitalWrite(powerPin, LOW);
  }

  // Control Pump - TODO
  if (data[1] == '1'){
    //digitalWrite(powerPin, HIGH);  
  } else {
    //digitalWrite(powerPin, LOW);
  }
}