int ledArray[] = {12, 11,10,9, 8}; //led pins put into array
int i = 0; //initialized i to use later
int fade = 0; //initialized variable fade to use later
int reading = 1023; //variable for analog reading
int brightness = map(reading, 0, 1023, 0, 255); //convert analog reading 


void setup(){
  Serial.begin(9600); 
}

void loop(){
  while(i < (sizeof(ledArray)/sizeof(int))){ //loop of array led pin according to array length
    while(fade <= brightness){ //fade effect, max value is brightness
    	analogWrite(ledArray[i], fade); //turning led on
    	fade += 5; //increment for led turning ON fade effect
      	delay(30);
    }
    fade = 0; //resets fade to 0 so next led starts from 0
   	i++; //increment to next led
    delay(1000);
  }
  i = 0; //resets led back to index 0
  		// current value of fade is set on value of brightness  
  
  while(i < (sizeof(ledArray)/sizeof(int))){
    while(fade >= 0){ //fade is decreasing to 0, turning OFF
    	analogWrite(ledArray[i], fade);
    	fade -= 5; //decrement to turning OFF fade effect
      	delay(30);
    }
    fade = brightness; //resets fade value back to maximum ON value which is birghtness value
   	i++; //increment to next led
    delay(1000);
  }
  i = 0; //resets led back to index 0 for another loop
  fade = 0; //resets fade to 0 to prepapre for next turning ON loop
}
