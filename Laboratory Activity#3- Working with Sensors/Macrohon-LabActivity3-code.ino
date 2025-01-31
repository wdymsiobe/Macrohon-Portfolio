// The temperature sensor used in this schematic is tmp36, the model requires to use the left pin or otherwise it would not work.
// Despite the instruction to not use the left pin, it would not be possible in this diagram.

#define TEMP_SENSOR_PIN A0
#define LDR_PIN A2
#define LED_PIN 12

// Set thresholds for temperature and brightness
const float TEMP_THRESHOLD = 50.0;
const int BRIGHTNESS_THRESHOLD = 220;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

// Read and convert the temperature from the sensor
float readTemperature() {
  int sensorValue = analogRead(TEMP_SENSOR_PIN);
  
  // Map the analog value (0-1023) to voltage (0-5000 mV) to avoid floating point multiplication
  int voltage_mV = map(sensorValue, 0, 1023, 0, 5000); 
  float temperatureC = (voltage_mV - 550.8) / 10.0; // Convert mV to Celsius
  
  return temperatureC;
}

// Get the brightness from the photoresistor
int readBrightness() {
  return analogRead(LDR_PIN);
}

void loop() {
  float temperature = readTemperature();
  int brightness = readBrightness();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Brightness: ");
  Serial.println(brightness);

  // If both readings are above the thresholds, blink the LED
  if (temperature >= TEMP_THRESHOLD && brightness >= BRIGHTNESS_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
