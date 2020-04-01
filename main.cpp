
#include "mbed.h"

#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


PwmOut PWM1(D6);

DigitalIn  sense(D7);

Serial pc( USBTX, USBRX );

int main() {

    uLCD.background_color(WHITE);
    uLCD.textbackground_color(WHITE);
    uLCD.color(BLUE);
    uLCD.printf("\n106061216\n"); //Default Green on black text
    uLCD.line(40, 40, 40, 60, WHITE);
    uLCD.line(40, 60, 60, 60, WHITE);
    uLCD.line(60, 60, 60, 40, WHITE);
    uLCD.line(60, 40, 40, 40, WHITE);

    PWM1.period(0.001);
    float cycle=0;
    float inc = 0.1;
    int counter = 0;
    PWM1 = cycle;
    while(1){
        wait(0.1);
        PWM1 = cycle;
        cycle += inc;
        if(counter == 10){
            inc = -0.1;
        }
        if(counter == 20){
            inc = 0.1;
            counter = 0;
        }
        counter++;
        pc.printf("%1.3f\r\n", sense);
    }
    

    

}


/*
#include "mbed.h"


int main()

{

    // basic printf demo = 16 by 18 characters on screen
    uLCD.background_color(WHITE);
    uLCD.textbackground_color(WHITE);
    uLCD.color(BLUE);
    uLCD.printf("\n106061216\n"); //Default Green on black text
    uLCD.line(40, 40, 40, 60, WHITE);
    uLCD.line(40, 60, 60, 60, WHITE);
    uLCD.line(60, 60, 60, 40, WHITE);
    uLCD.line(60, 40, 40, 40, WHITE);
 

}

*/

/*
Serial pc( USBTX, USBRX );

AnalogIn Ain(A0);

float ADCdata;


int main(){

  while(1){

    ADCdata = Ain;

    wait(0.5);

    pc.printf("%1.3f\r\n", ADCdata);

  }

}

*/