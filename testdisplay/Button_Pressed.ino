/*Проверка состояния нажата/отпущена*/
bool Button::Pressed()
{
  ButtonCurrent = Debounce(pinButton, ButtonPrevious);
  if(PulledUp_to == RESISTOR_TO_VCC)
  {
    if(ButtonPrevious == true && ButtonCurrent == false)
      State = true;
    else
      State = false;
  }
  else
  {
    if(PulledUp_to == RESISTOR_TO_GND)
    {
      if(ButtonPrevious == false && ButtonCurrent == true)
        State = true;
      else
        State = false;
    }
  }
  ButtonPrevious = ButtonCurrent;
  return State;
}
