/*Кнопка подтянута резистором 10k к GND*/
#define RESISTOR_TO_GND 0
/*Кнопка подтянута резистором 10k к VCC*/
#define RESISTOR_TO_VCC 1
/*Описываем объект класса "Кнопка"*/
#ifndef   Button_h
#define   Button_h
#include  <Arduino.h>

class Button
{
    /*Хранение состояния кнопки*/
    bool State = false;
    /*Номер пина подключения*/
    int pinButton;
    /*Время фильтрации сигнала*/
    int tFiltered; 
    /*Флаг определяющий схематическое подключение кнопки*/
    bool PulledUp_to;
    /*Состояния кнопки*/
    bool ButtonCurrent  = false;
    bool ButtonPrevious = false;
    /*Подавление дребезга контакта*/
    bool Debounce(int _Pin, bool _Last);
  public:
    /*Конструктор класса*/
    Button(uint8_t _b, uint8_t _t, boolean _p);
    /*Получаем состояние кнопки нажата/отпущена*/
    bool Pressed();
};

#endif
