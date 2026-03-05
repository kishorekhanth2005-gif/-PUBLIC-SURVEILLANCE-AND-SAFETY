#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// LCD setup (address may be 0x27 or 0x3F, check your module)
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Buzzer pin
#define BUZZER_PIN D6 // You can change pin if needed
void setup() {
 Serial.begin(9600); // Start serial communication
 lcd.init(); // Initialize LCD
 lcd.backlight(); // Turn on backlight
 pinMode(BUZZER_PIN, OUTPUT); // Set buzzer pin as output
 digitalWrite(BUZZER_PIN, LOW);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Smart Surveillance");
 delay(2000);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("System Normal");
}
void loop() {
 if (Serial.available() > 0) {
 char inputChar = Serial.read(); // Read incoming character
 lcd.clear();
 if (inputChar == 'A') {
 // Display abnormal activity
 lcd.setCursor(0,0);
 lcd.print("Abnormal Activity");
 lcd.setCursor(0,1);
 lcd.print("Detected!");
 // Buzzer alert (beep 3 times)
 for (int i = 0; i < 3; i++) {
 digitalWrite(BUZZER_PIN, HIGH);
 delay(300);
 digitalWrite(BUZZER_PIN, LOW);
 delay(300);
 }
 } else {
 lcd.setCursor(0,0);
 lcd.print("System Normal");
 digitalWrite(BUZZER_PIN, LOW); // Ensure buzzer is OFF
}
}