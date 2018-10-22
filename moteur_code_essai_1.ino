#define pinEnable 13 // Activation du driver/pilote
#define pinStep    9 // Signal de PAS (avancement)
#define pinDir     8 // Direction 

enum{PUSH,PULL}; //syringe movement direction
 
void setup(){
  Serial.begin(9600);
  Serial.println("Test DRV8825");
 
  pinMode( pinEnable, OUTPUT );
  pinMode( pinDir   , OUTPUT );
  pinMode( pinStep  , OUTPUT );
}


void loop(){
  int i = 0;
 
  digitalWrite( pinDir   , HIGH); // Direction avant
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
 
  // Avance de 200 pas

  if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'||key == '/' || key == '*' || key == '-' || key == '+' )){
    if (valOnePresent != true){
      numop = numop + key;
      if (temp_press==(numop'+')){
       Serial.println("clockwise");
      myStepper.step(stepsPerRevolution);
       for( i=0; i<numop; i++){
        Serial.println( i );
         digitalWrite( pinStep, HIGH );
         delay( 10 );
        digitalWrite( pinStep, LOW );
        delay( 10 );}
       }
      if (temp_press==(numop'-')){
         Serial.println("counterclockwise");
         myStepper.step(-stepsPerRevolution);
        for( i=0; i<200; i++){   // Changer de direction
          Serial.println( i );
           digitalWrite( pinStep, HIGH );
           delay( 1 );
          digitalWrite( pinStep, LOW );
          delay( 1 );}
        }   
    }
  }
 
  
