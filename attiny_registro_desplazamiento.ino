int pindata = 2; 
int pinclock = 0;
int pinlatch = 1;

void setup()
{
  //Se establece que los pines data, clock, latch seran salidas del arduino 
  pinMode(pindata, OUTPUT);
  pinMode(pinclock, OUTPUT);  
  pinMode(pinlatch, OUTPUT);
}

void loop() {
  int index;
  int delayTime = 100;  
  
  
  for(index = 0; index <= 7; index++) {
    shiftWrite(index, HIGH);  
    delay(delayTime);   
    shiftWrite(index, LOW); 
  }
   
  for(index = 7; index >= 0; index--) {
    shiftWrite(index, HIGH);  
    delay(delayTime);   
    shiftWrite(index, LOW);
  }

}

void shiftWrite(int desiredPin, boolean desiredState) {

    bitWrite(data,desiredPin,desiredState);
    shiftOut(pindata, pinclock, MSBFIRST, data);

    digitalWrite(pinlatch, HIGH);
    digitalWrite(pinlatch, LOW);
}
