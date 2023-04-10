int analogpin = A0;
int val = 0;
long no_of_pulse=0;
long pulserate=0;
unsigned long time=0;

void setup() {
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  time=millis();  //get the current time
  val = analogRead(analogpin);  //get the detected pulse

  if(val>580){    //600 is the standard threshold
      digitalWrite(12, HIGH); 
      no_of_pulse++;
  }else{
    digitalWrite(12, LOW); 
  }

  pulserate=no_of_pulse*60000/time;   //get the pulserate
  
  //print the pulse
  Serial.print("SignalLevel: ");
  Serial.print(val);

  Serial.print(",");

  //print the pulserate
  Serial.print("Pulserate: ");
  Serial.print(pulserate);
  Serial.print("\n");

  delay(150);
}
