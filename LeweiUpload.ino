/*
  Lewei Upload And Control Demo
  Control LED through writeSerial method ( Write Helloworld to serial)
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int ledstatus = 0;
String comdata="";

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  randomSeed(analogRead(0));
  
  Serial.print("BH:");
  Serial.print(random(20,50));
  Serial.print(";pm1:");
  Serial.print(random(40,80));
  Serial.print(";t:");
  Serial.print(random(19,30));  
  Serial.print(";uv:"); 
  Serial.println(random(1200,1400)); //println not print
  
  while (Serial.available() > 0) {
      comdata += char(Serial.read());
      delay(2);
  }
  if (comdata.length() > 0) { 
       if (comdata[0] == 'H') {
         ledstatus = ~ledstatus;
       }
       comdata="";
  }
  if (0 == ledstatus) {
      digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
  } else {
      digitalWrite(led, HIGH);    // turn the LED off by making the voltage LOW
  }
  delay(1000);               // wait for a second
}

