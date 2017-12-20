#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};

#define _0 {'1','2','3','A'}
#define _1 {'4','5','6','B'}
#define _2 {'7','8','9','C'}
#define _3 {'*','0','#','D'}


char keymap[ROWS][COLS]= {_0,_1,_2,_3};

Keypad myKeypad = Keypad(makeKeymap(keymap),rowPins,colPins,ROWS,COLS);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char keypressed = myKeypad.getKey();
  if(keypressed != NO_KEY)
  Serial.print(keypressed);
}
