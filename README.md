#double-Stepper

Control Two Stepper Motors using serial inputs to arduino 
you can send serial data using any method like ( i2c , uart , or via serial monitor on arduino ide ) 

#HOW TO TEST
1. Upload sketch to your arduino , 

2. Attach 2 28byj-48 5V Stepper Motors by The pin configuration in the code .. 

3. open serial monitor on your arduino IDE

4. send steps like (  DegreesForMotor1-DegreesForMotor2 )

5. Multiple orders  ( DegreesForMotor1-DegreesForMotor2&DegreesForMotor1-DegreesForMotor2 ) 

This Sketch is created by Me Samir eltabal ( fb.com/xsolyx ) 

#Change Log

v 0.0.2
 Order Motors by Degrees instead of steeps ( 0 - 360 ) ;
 Seperators has changed Orders Single Order ( 200-100 ) , Multiple Orders ( 360-0&230-120 ) ;
v 0.0.1 
 Initial setup
