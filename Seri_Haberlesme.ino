#include <Servo.h>
#include <StepperMotor.h>

StepperMotor motor(7,6,5,4);
Servo servo1;
Servo servo2; 

void setup() {
  servo2.attach(3);
  servo1.attach(2);
  servo1.write(90);
  servo2.write(90);
  motor.setStepDuration(1);      
  Serial.begin(9600);  
  
}


void ledCircuit(){
  //start
  bool pressed = false;
  int x;
  int y;
  servo1.write(90);
  servo2.write(90);
  //setp1 goto home
  y = 60;
  servo2.write(y);
  // step2 write 
  servo1.write(20);
  x = 2000;
  motor.step(x);
  servo1.write(90);
  delay(100);
  //setp1 goto home
  y = 70;
  servo2.write(y);
  // step2 write 
  servo1.write(20);
  x = -2000;
  motor.step(x);
  servo1.write(90);
  delay(100);
  //step5 end
  servo1.write(90);
  servo2.write(90);
  }
void geA(){
    servo2.write(70);
    delay(50);
    servo1.write(0);
    delay(150);
    servo1.write(90);
    delay(50);
    servo2.write(65);
    delay(50);
    servo1.write(0);
    delay(20);
    motor.step(100);
    }
char msj;
int beforeX;
int beforeY;
int X1;
int X2;
int Y1;
int Y2; 
void loop() {
int queue =1;
delay(100);
servo1.write(90);
servo2.write(90);
char msg = Serial.read();
if(msg == 'l'){
  
  ledCircuit();
  }
if(msg == 'g'){
  geA();
  }/*
  servo1.write(0);
  servo2.write(45);
  motor.step(10000);
  delay(2000);
  servo2.write(30);
  motor.step(-10000);
*/
/*servo2.write(30);
while(queue < 20){
    motor.step((5000/20));
    servo2.write(queue+30);
    queue++;
  }
queue = 1;
while(queue < 20){
    motor.step(-(5000/20));
    servo2.write(queue+30);
    queue++;
  }*/

}
