#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
const byte PWLONG = 4;
int password[PWLONG]= {0,0,0,0};
int maspw[PWLONG] = {1,2,3,4};
int inpw[PWLONG];


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
  Serial.println("Select Menu");
  // put your main code here, to run repeatedly:
  char keypressed = myKeypad.getKey();
  if(keypressed != NO_KEY){
    switch(keypressed){
      case A:
        enter(1); // Door Open
        break;
      case B:
        enter(2); //Gen OTP Password
        break;
      case C:
       enter(3);  //Change master password
       break;
    }
  }
}

void enter(int mode){
  int stack = 0;
  int awswer = 0;
  int newpassword;
  Serial.println("Enter Your Password");
  while(stack < 4){
    if(keypressed != NO_KEY)
      inpw[stack] = keypressed;
      stack++;
    }  
  }

  stack = 0;
  
  if (mode == 4){
     while(stack < 4){
      maspw[stack] = inpw[stack];
      stack++ 
      } 
      return 0;
  ]
  else{
    while(stack < 4){
    if(inpw[stack] == password[stack] || inpw[stack] == maspw[stack])
       answer++;
      `stack++;
      } 
    }

  if (stack == 4){

    switch(mode){
      case 1:
        if (stack == 4){
            Serial.println("Door Opened");
            delay(5000);
            Serial.println("Door Closed");
          }
        else{
          Serial.println("Password Wrong");
        }
        break;
      case 2:
        newpassword = random(0000,9999);
        Serial.println("New OTP Password is " + newpassword);
        password[0] = newpassword / 1000;
        newpassword = newpassword % 1000;
        password[1] = newpassword / 100;
        newpassword = newpassword % 100;
        password[2] = newpassword / 10;
        password[3] = newpassword % 10;
        break;
      case 3:
        enter (4);
        Serial.println("Master Password Changed");
        break;
  }
  
}

