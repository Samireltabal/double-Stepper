# double-Stepper
Control Two Stepper Motors using serial inputs to arduino 
[CODE] 

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
    char* separator = strchr(command, ':');
    if (separator != 0)
    {
        // Actually split the string in 2: replace ':' with 0
        *separator = 0;
        int servoId = atoi(command);
        ++separator;
        int position = atoi(separator);
         small_stepper.setSpeed(600);   
         small_stepper2.setSpeed(600);   
         small_stepper.step(servoId);
         small_stepper2.step(position);
  delay(10);
  
    }
    command = strtok(0, "&");
} /* end while */
 
} /* end serial check */  
   
}/* --(end main loop )-- */



/* ( THE END ) */
[ HOW TO TEST ] 
1. Upload sketch to your arduino , 

2. Attach 2 28byj-48 5V Stepper Motors by The pin configuration in the code .. 

3. open serial monitor

4. send steps like (  StepsForMotor1:StepsForMotor2 )

5. Multiple orders  ( StepsForMotor1:StepsForMotor2&StepsForMotor1:StepsForMotor2 ) 

This Sketch is created by Me Samir eltabal ( fb.com/xsolyx ) 
