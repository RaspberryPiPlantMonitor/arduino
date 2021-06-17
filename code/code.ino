#define lightPin 4
#define humidityPin A0

float humidityValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(humidityPin, INPUT);
  pinMode(lightPin, OUTPUT);

  digitalWrite(lightPin, LOW); 
}

void loop() {
  String data = Serial.readString(); 

  humidityValue = analogRead(humidityPin);
  Serial.print("{\"humidityValue\":"+String(humidityValue)+",\"lightValue\":"+data[0]+","+"\"pumpValue\":"+data[1]+"}\n");
  
  // Control IoT Relay
  if (data[0] == '1'){
    digitalWrite(lightPin, HIGH);  
  } else {
    digitalWrite(lightPin, LOW);
  }
  
  // Control Pump - TODO
  if (data[1] == '1'){
    //digitalWrite(powerPin, HIGH);  
  } else {
    //digitalWrite(powerPin, LOW);
  }  
}
