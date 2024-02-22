#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 0 //3 für uno
TM1637Display display(CLK, DIO);
const int button = 4; //1 für uno
int buttonstate,counter,test;

void setup()
  {
    pinMode(button, INPUT_PULLUP);
    buttonstate = 1;
    display.setBrightness(0x0f);
  }

void loop()
  { display.showNumberDec(0, false);
    buttonstate = digitalRead(button);
  
  if (buttonstate == 0) //if the button is pressed
    { 
    test=1;
    delay(1000);
    counter=0; // initialize the timer to 0
  while(test==1) 
    {
    counter++;// increment the counter
    display.showNumberDec(counter, false);
    delay(1000);
    buttonstate = digitalRead(button);
  if (buttonstate == 1) //if the button is released
    {
    test=0;// stop the clock
    buttonstate = digitalRead(button);
    delay(6000);
    counter=0;
    display.showNumberDec(counter, false);
}
}
}
}