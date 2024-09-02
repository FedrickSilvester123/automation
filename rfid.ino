int count = 0;
char c;
String id;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("Please scan your RFID TAG");
 
}

void loop() {
  while(Serial.available()>0)
  {
    c = Serial.read();
   count++;
   id += c;
   if(count == 21)  
    {
      Serial.print(id);
      //break;
     
      if(id=="AB123456789SUPERVISOR")
      {
        Serial.println("Valid TAG");
        digitalWrite(13, HIGH);
      }
      else
      {
      digitalWrite(13, LOW);
      Serial.println("Invalid TAG");
      }
    }
  }
  count = 0;
  id="";
  delay(500);

}
