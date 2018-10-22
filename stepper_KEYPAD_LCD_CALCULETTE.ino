
/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
 

// DEBUT partie Klcd

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'X','0','=','/'},
};
byte rowPins[ROWS] = {53,51,49,47}; //connect to row pinouts 
byte colPins[COLS] = {45,43,41,39}; //connect to column pinouts
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
 
//variables declaration
boolean valOnePresent = false;
boolean next = false;
boolean final = false;
String num;
int ans;
char op;

// FIN partie KLCD




// DEBUT Moteur Definitions


#define pinEnable 13 // Activation du driver/pilote
#define pinStep    9 // Signal de PAS (avancement)
#define pinDir     8 // Direction 


// FIN Moteur



const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 5, 6);

int stepCount = 0;  // number of steps the motor has taken

void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Debit Volumique");
  delay(6000);
  lcd.clear(); //clears the LCD screen and positions the cursor in the upper-left corner. 



pinMode( pinEnable, OUTPUT );
  pinMode( pinDir   , OUTPUT );
  pinMode( pinStep  , OUTPUT );


  
}    ////



void loop(){
  char key = myKeypad.getKey();
 
  if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'|| key == '-')){
    if (valOnePresent != true){
      num = num + key;
      int numLength = num.length();
      lcd.setCursor(15 - numLength, 0); //to adjust one whitespace for operator
      lcd.print(num);
    }////




// DEBUT MOTEUR


int i = 0;
  
  digitalWrite( pinDir   , HIGH); // Direction avant
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step



//FIN MOTEUR



if (final == true && key != NO_KEY && key == '='){  

 int Reading = digitalRead(num.toInt());
  // map it to a range from 0 to 100:
  int motorSpeed = map(Reading, -10000, 10000, -100, 100);
  // set the motor speed:
  if (motorSpeed > -10000) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}








else if (key != NO_KEY && key == 'X'){
    lcd.clear();
    valOnePresent = false;
    final = false;
    num = "";
    ans = 0;
    op = ' ';
  }




  }
}





