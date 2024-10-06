/*Фильтрация дребезга контакта*/
bool Button::Debounce(int _Pin, bool _Last)
{
  bool current = digitalRead(_Pin);
  if(current != _Last)
  {
    delay(tFiltered);
    current = digitalRead(_Pin); 
  }
  return current;
}
