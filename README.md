Subject requirement for course COSC 111B - CS ELECTIVE 3 - Internet of Things

LabActivity 1 - objective is to create a running light from right to left using digitalWrite().

use pins 8 to 12 for the LED. turn LED ON starting from pin 12 to 8. after turning all the LED on, turn LED OFF starting from pins 12 to 8.

LabActivity 2 - objective is to add brightness control to the output of LabActivity1.

use the output of LabActivity1. use analogWrite() to create a fade effect. use while loop to repeatedly put increment to analogWrite(), which slowly increases or decreases the brightness of each LED when turning ON or OFF.

LabActivity 3- objective is to imitate a fire detector using photoresistor and thermistor. Since tinkercad doesn't have thermistor, a temperature sensor was used instead.

Temperature sensor on pin A0. Photoresistor on pin A2. LED on pin 12. using analogRead() to photoresistor and temperature sensor to get input from sensors. using map() function to transform the analog reading from sensors to digital values. when a certain threshold set in photoresistor and temperature sensor is met, the LED will blink ON and OFF.

LabActivity 4 - objective is to use photoresistor that will sense light. When a certain threshold is met, then a LED will blink ON and OFF, and when typed "stop" in serial monitor, then it will stop functioning.

Photoresistor on pin A2. LED on pin 13. using map() function to transform the analog reading from photoresistor to digital values. when a certain threshold is met, then the LED will blink. using Serial.available() function to read inputs from serial monitor. when typed "stop", regardless of casing, the code will halt functioning.

LabActivity 5 - objective is to create a circuit that will provide a connection through fastapi, and those who will connect can control the LED of the circuit to turn ON and OFF.

The arduino code functions that when it receive an input value of '1' then the LED will turn ON. When input received is '0' then LED will turn OFF. The python code enables controlling of the arduino and establishing connection using fastapi. In startup event, it attempts to connect to the arduino with time.sleep(2) to ensure that the connection is fully opened up. In shutdown event, it simply closes the connection to the arduino. In POST LED ON, when the fastapi receives a request to turn ON, then it will pass a byte string '1' to the arduino which will trigger the LED to turn on. In POST LED OFF, when the fastapi receives a request to turn OFF, then it will pass a byte string '0' to the arduino which will trigger the LED to turn off.

LabActivity 6 - objective is to create a circuit that will connect to the fastapi connection in LabActivity 6 and will send out the signals for input value which should trigger to turn the LED ON and OFF.

The arduino code functions to constantly print values, while the button is pressed then it will print '1', otherwise it will print '0'. The python code will be used to connect to the fastapi and send out signals from the button. The imported requests library is important that allows values to be forwarded in the fastapi connection. The api_url variable should be passed with the address created by the fastapi. This is important to establish connection. Then, the Python code will receive inputs from the Arduino and forward it to the FastAPI connection.
