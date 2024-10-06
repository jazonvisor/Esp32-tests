/*Конструктор класса для объекта "Кнопка"*/
Button::Button(uint8_t _b, uint8_t _t, boolean _p)
{
  pinButton = _b;
  tFiltered = _t;
  PulledUp_to = _p;
  pinMode(pinButton, INPUT);
}
