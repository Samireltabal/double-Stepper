#include <Stepper.h>
#define INPUT_SIZE 30


#define STEPS_PER_MOTOR_REVOLUTION 32   
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  
 

Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);
Stepper small_stepper2(STEPS_PER_MOTOR_REVOLUTION, 4, 6, 5, 7);


int  Steps2Take;

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
Serial.begin(9600);
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if ( Serial.available () > 0 ) 
{ 
char input[INPUT_SIZE + 1];
byte size = Serial.readBytes(input, INPUT_SIZE);

input[size] = 0;


char* command = strtok(input, "&");
while (command != 0)
{
    // Split the command in two values
    char* separator = strchr(command, '-');
    if (separator != 0)
    {
        // Actually split the string in 2: replace ':' with 0
        *separator = 0;
        int motor1Degres = atoi(command);
        ++separator;
        int motor2Degres = atoi(separator);

        int steps1 = stepCalc(motor1Degres);
        int steps2 = stepCalc(motor2Degres);
         small_stepper.setSpeed(600);   
         small_stepper2.setSpeed(600);       
         small_stepper.step(steps1);
         small_stepper2.step(steps2);
         Serial.print("Motor 1 : ");
         Serial.println(steps1);
         Serial.print("Motor 2 : ");
         Serial.println(steps2);
  delay(10);
  
    }
    command = strtok(0, "&");
} /* end while */
 
} /* end serial check */  
   
}/* --(end main loop )-- */

int stepCalc(int degres) {
 int result;
 double mathVal = 2048.00 / 360.00 ; 
 double FLSteps2Take = degres * mathVal ;
 Steps2Take = (int) FLSteps2Take;
result = Steps2Take; 
return result;
}

/* ( THE END ) */
