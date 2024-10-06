#include "defines.h"
#include "variables.h"
#include "Button.h"

#include <WiFi.h>
#include <WebServer.h>
#include <LiquidCrystal_I2C.h>

/*Инициализация web сервера*/
WebServer server(80);

/*Создание объекта класса для работы с дисплеем*/
LiquidCrystal_I2C LocalDisplay(DISPLAY_I2C_ADDR,COLS,ROWS);

Button KeySelect(SELECT,DEBOUNCE_TIME_FILTER,RESISTOR_TO_GND);
Button KeyRigth(RIGTH,DEBOUNCE_TIME_FILTER,RESISTOR_TO_GND);
Button KeyUp(UP,DEBOUNCE_TIME_FILTER,RESISTOR_TO_GND);
Button KeyDown(DOWN,DEBOUNCE_TIME_FILTER,RESISTOR_TO_VCC);
Button KeyLeft(LEFT,DEBOUNCE_TIME_FILTER,RESISTOR_TO_VCC);

void setup(){
  /*Только для отладки*/
  Serial.begin(115200);
  /*Подключение к указанной wi-fi сети*/ 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi... подключено.");
  Serial.print("IP адрес: ");
  Serial.println(WiFi.localIP());
  
  /*Инициализация дисплея*/
  LocalDisplay.init();                      
  /*Включение подсветки*/
  LocalDisplay.backlight();
  /**/
  LocalDisplay.clear();
  LocalDisplay.setCursor(3,0);
  LocalDisplay.print("Hello, world!");
  LocalDisplay.setCursor(0,1);
  LocalDisplay.print("Ywrobot Arduino!");
  LocalDisplay.setCursor(0,2);
  LocalDisplay.print("Arduino LCM IIC 2");
  LocalDisplay.setCursor(0,3);
  LocalDisplay.print("Power By Ec-yuan!");

  /*Старт веб сервера*/
  server.begin();
  Serial.println("Сервер запущен.");
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
