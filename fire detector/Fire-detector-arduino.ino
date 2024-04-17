#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2 // Define the pin for DHT11 sensor
#define DHTTYPE DHT11 // Define the type of DHT sensor

const int flamepin = 11;

int flame;

const int buzzerpin = 12;

const int redled = 5;
const int greenled = 6;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    // Initialize the LCD
    lcd.begin();

    // Turn on the backlight and print a message
    lcd.backlight();
 
    // Initialize the DHT sensor
    dht.begin();

    pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(buzzerpin, OUTPUT);
    pinMode(flamepin, INPUT);

    // Set up serial communication for debugging
    Serial.begin(9600);
}

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  flame = digitalRead(flamepin);

  if (flame == LOW)
  {
        digitalWrite(greenled, LOW);
        digitalWrite(buzzerpin, HIGH);
        digitalWrite(redled, LOW);
        delay(200);
        digitalWrite(redled, HIGH);
        lcd.clear();
        lcd.print("   Emergency");// Print emergency message on LCD when flame is low
        lcd.setCursor(0,1);
        lcd.print("  Temp: ");
        lcd.print(temperature);
        lcd.print("C");
        
  }
  else
  {
        digitalWrite(buzzerpin, LOW);
        digitalWrite(redled, LOW);
        digitalWrite(greenled, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperature);
        lcd.print("C");
        lcd.setCursor(0, 1);
        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.print("%");
  }
    

    // Read temperature and humidity from DHT sensor


    // Print temperature and humidity to serial monitor for debugging
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("C  Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(1000); // Delay for 2 seconds before updating readings again
}
