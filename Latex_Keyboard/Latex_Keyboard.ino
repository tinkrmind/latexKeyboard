//Latex keypad
//Connect 4x4 keypad to pins 4 through 11 of arduino leonardo.
//Code is subject to Creative Commons Sharealike 4.0 lisence
//Author: Amitabh Shrivastava (tinkrmind@gmail.com)

int rows[]={11, 10, 9, 8};
int cols[]={7, 6, 5, 4};
int i, j, button;
const int delay_time=300;
String s;

void setup()
{
  for(i=0; i<4; i++)
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
  button=detectKey();
//  if(button)
//  {
//    s=String(button);
//    Keyboard.print(s);
//    delay(50);
//  }
  switch(button)
  {
    case 1:
      Keyboard.print("\\pi");
    delay(delay_time); break;  
    case 2:
      Keyboard.print("\\theta");
    delay(delay_time); break;  
    case 3:
      Keyboard.print("\\lambda");
    delay(delay_time); break;  
    case 4:
      Keyboard.print("\\phi");
    delay(delay_time); break;  
    case 5:
      Keyboard.print("\\alpha");
    delay(delay_time); break;  
    case 6:
      Keyboard.print("\\beta");
    delay(delay_time); break;  
    case 7:
      Keyboard.print("\\gamma");
    delay(delay_time); break;  
    case 8:
      Keyboard.print("\\delta");
    delay(delay_time); break;  
    case 9:
      Keyboard.print("\\Gamma");
    delay(delay_time); break;  
    case 10:
      Keyboard.print("\\Delta");
    delay(delay_time); break;  
    case 11:
      Keyboard.print("\\Pi");
    delay(delay_time); break;  
    case 12:
      Keyboard.print("\\Sigma");
    delay(delay_time); break;  
    case 13:
      Keyboard.print("\\sim");
    delay(delay_time); break;  
    case 14:
      Keyboard.print("\\ge");
    delay(delay_time); break;  
    case 15:
      Keyboard.print("\\leq");
    delay(delay_time); break;  
    case 16:
      Keyboard.print("\\equiv");
    delay(delay_time); break;  
  }
}

int detectKey()
{
  for(i=0; i<4; i++)
  {
    for(j=0; j<4; j++)
    {
      digitalWrite(rows[j], HIGH);
    }
    digitalWrite(rows[i], LOW);
    for(j=0; j<4; j++)
    {
      if(!digitalRead(cols[j]))
      {
        delay(5);
        if(!digitalRead(cols[j]))
          return(i*4+j+1);
      } 
    }
  }
  return 0;
}
