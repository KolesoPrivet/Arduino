#include <math.h>
#include <LiquidCrystal.h>

int RED_LED_PIN = 7;
int GREEN_LED_PIN = 6;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int minute = 1;
char data = 'S';
float voltage, temperature;

void setup() {
  
  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Temperature: ");
  redLedOn();
}

void loop() {
  voltage = analogRead(A0) * 5.0 / 1023;
  temperature = 1.0 / (log(voltage / 2.5) / 4300.0 + 1.0 / 298.0) - 273;

    lcd.setCursor(1, 1);
    lcd.print(temperature);
    lcd.print("   *C");
    
  data = Serial.read();
  
  switch(data){
    case 'G': greenLedOn(); break;
    case 'S': redLedOn(); break;
  }

  delay(1000);
}

void redLedOn(){
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, HIGH);
}
void greenLedOn(){
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    
    delay(500);
    Serial.println(temperature);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
  }
