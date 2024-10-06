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
  //Serial.begin(115200);
  /*Прежде всего инициализация дисплея*/
  LocalDisplay.init();                      
  /*Включение подсветки*/
  LocalDisplay.backlight();
  /**/
  LocalDisplay.clear();
  /**/
  LocalDisplay.setCursor(0,0);
  LocalDisplay.print(F("Search network"));
  /*Подключение к указанной wi-fi сети*/ 
  uint8_t i=0;
  WiFi.begin(ssid, password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    LocalDisplay.setCursor(i,1);
    LocalDisplay.print(".");
    i++;
  }
  LocalDisplay.clear();
  LocalDisplay.setCursor(0,0);
  LocalDisplay.print(F("WiFi status:"));
  LocalDisplay.setCursor(10,1);
  LocalDisplay.print(F("Connected."));
  LocalDisplay.setCursor(0,2);
  LocalDisplay.print(F("IP address:"));
  LocalDisplay.setCursor(5,3);
  LocalDisplay.print(WiFi.localIP());

  /*Руты (обработчики запросов веб сервера)*/
  /*Обработчик основной страницы*/
  server.on("/", handleRoot);
  /**/
  server.onNotFound(handleNotFound);
  
  /*Старт веб сервера*/
  server.begin();
  /**/
  delay(5000);
  LocalDisplay.clear();
  LocalDisplay.setCursor(0,0);
  LocalDisplay.print(F("Server is running."));
}

void loop(){
  /*Обработка запросов - обязательный вызов метода handleClient()*/
  server.handleClient();

  /*Обработка нажатий кнопок
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
  */
  /*Задержка*/
  delay(5000);
}
