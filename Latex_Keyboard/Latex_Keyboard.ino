// Latex keypad
// Connect 4x4 keypad to pins 4 through 11 of arduino leonardo or micro
// Code is subject to Creative Commons Sharealike 4.0 lisence
// Author: Amitabh Shrivastava (tinkrmind@gmail.com)
//
// While I work on UTF-8 support, you can use modifier keys to hack your way into typing accented characters and whatnot
// To use key combinations, leave the keycode of the corresponding button blank and then add an if statement to handle the button as demonstrated below
//
// More info on Keyboard library at: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
// Info on supported key modifiers etc: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
//

#include <Keyboard.h>

int rows[] = {11, 10, 9, 8};
int cols[] = {7, 6, 5, 4};
int i, j, button;
const int delay_time = 300;
String s;

String keycode[]={                                  // Button numbers
  "\\pi",    "\\theta", "\\lamda",  "\\phi",        // 1   2   3   4
  "\\alpha", "\\beta",  "\\gamma",  "\\delta",      // 5   6   7   8
  "\\Gamma", "\\Delta", "\\Pi",     "\\Sigma",      // 9   10  11  12
  "\\sim",   "\\ge",    "\\leq",    ""              // 13  14  15  16
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
  button = detectKey();
  if(button != 0){
    Keyboard.print(keycode[button-1]);
    delay(delay_time);
  }
  // If button 16 is pressed execute the following key presses
  if(button == 16){
    // Press Ctrl+ALt+Delete
    Keyboard.press( KEY_LEFT_CTRL );
    Keyboard.press( KEY_LEFT_ALT );
    Keyboard.press( KEY_DELETE );
    // Now release all keys at once
    Keyboard.releaseAll(); // NOTE: Make sure you release keys after pressing them. Otherwise you can really mess you your day!
    
    // Now type "you are pwned" in caps
    Keyboard.write( KEY_CAPS_LOCK );
    Keyboard.print("you are pwned");

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
