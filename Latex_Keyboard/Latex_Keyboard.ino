//Latex keypad
//Connect 4x4 keypad to pins 4 through 11 of arduino leonardo or micro
//Code is subject to Creative Commons Sharealike 4.0 lisence
//Author: Amitabh Shrivastava (tinkrmind@gmail.com)

#include <Keyboard.h>

int rows[] = {11, 10, 9, 8};
int cols[] = {7, 6, 5, 4};
int i, j, button;
const int delay_time = 300;
String s;

String keycode[]={
  "\\pi",    "\\theta", "\\lamda",  "\\phi",
  "\\alpha", "\\beta",  "\\gamma",  "\\delta",
  "\\Gamma", "\\Delta", "\\Pi",     "\\Sigma",
  "\\sim",   "\\ge",    "\\leq",    "\\equiv"
};

void setup()
{
  for (i = 0; i < 4; i++)
  {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH);
    pinMode(cols[i], INPUT);
    digitalWrite(cols[i], HIGH);
  }
  Keyboard.begin();
}

void loop()
{
  if(button = detectKey()){
    Keyboard.print(keycode[button-1]);
    delay(delay_time);
  }
}

int detectKey()
{
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      digitalWrite(rows[j], HIGH);
    }
    digitalWrite(rows[i], LOW);
    for (j = 0; j < 4; j++)
    {
      if (!digitalRead(cols[j]))
      {
        delay(5);
        if (!digitalRead(cols[j]))
          return (i * 4 + j + 1);
      }
    }
  }
  return 0;
}
