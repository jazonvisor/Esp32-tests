#include "defines.h"
#include "variables.h"
#include "Button.h"
//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27,16,4);

Button KeySelect(SELECT,DEBOUNCE_TIME_FILTER,RESISTOR_TO_GND);
Button KeyRigth(RIGTH,DEBOUNCE_TIME_FILTER,RESISTOR_TO_GND);
Button KeyUp(UP,DEBOUNCE_TIME_FILTER,RESISTOR_TO_GND);
Button KeyDown(DOWN,DEBOUNCE_TIME_FILTER,RESISTOR_TO_VCC);
Button KeyLeft(LEFT,DEBOUNCE_TIME_FILTER,RESISTOR_TO_VCC);

void setup(){
  Serial.begin(9600);
  //lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  //lcd.backlight();
  //lcd.setCursor(3,0);
  //lcd.print("Hello, world!");
  //lcd.setCursor(0,1);
  //lcd.print("Ywrobot Arduino!");
  // lcd.setCursor(0,2);
  //lcd.print("Arduino LCM IIC 2");
  // lcd.setCursor(0,3);
  //lcd.print("Power By Ec-yuan!");

}

void loop(){
  if(KeySelect.Pressed())
    Serial.println("Нажатие кнопки SELECT");
  if(KeyRigth.Pressed())
    Serial.println("Нажатие кнопки RIGTH");
  if(KeyUp.Pressed())
    Serial.println("Нажатие кнопки UP");
  if(KeyDown.Pressed())
    Serial.println("Нажатие кнопки DOWN");
  if(KeyLeft.Pressed())
    Serial.println("Нажатие кнопки LEFT");
}
