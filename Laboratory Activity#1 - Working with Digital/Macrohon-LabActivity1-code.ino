int ledArray[] = {12, 11, 10, 9, 8};

void setup(){
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop(){ //not the most clean code for me, but necessary to not be similar to others
  for(int i = 0; i < sizeof(ledArray)/sizeof(int); i++){ //loops ledArray for turning led ON, condition is set to the length of ledArray
    digitalWrite(ledArray[i], HIGH); //turning led ON
    delay(1000); //1 second delay
    
    if(i == sizeof(ledArray)/sizeof(int) -1){ //catches when i == 4(all led are set to ON) to prepare for turning leds OFF 
      for(i = 0; i < sizeof(ledArray)/sizeof(int); i++){ //looping through ledArray
        digitalWrite(ledArray[i], LOW); //turning led OFF
    	delay(1000);
      }
    }
  }
}
