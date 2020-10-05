#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);	

// This one-wire object let’s us communicate with any one-wire device, not just DS18B20. 
// In order to communicate with DS18B20 sensor, we need to create object of 
// DallasTemperature library and pass reference of one-wire object as a parameter.
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();	// Start up the library
  Serial.begin(9600);
}

void loop(void)
{ 
  // Send the command to get temperatures
  sensors.requestTemperatures(); 

  //print the temperature in Celsius
  Serial.print("Temperature: ");
  // function reads and returns temperature reading from the sensor.
  // index is the location of the sensor on the bus. 
  // If you are using only one DS18B20 on the bus, set it to 0.
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);//shows degrees character
  Serial.print("C  |  ");
  
  //print the temperature in Fahrenheit
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F");
  
  delay(500);
}
