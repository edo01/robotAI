/*
Pin WeMos D1 mini 	Pin Arduino IDE
D0	                16
D1	                5
D2	                4
D3	                0
D4	                2
D5	                14
D6  	              12  
D7	                13
D8	                15
TX	                1
RX	                3
*/

//Motor Connections
//Change this if you wish to use another diagram
#define EnA 5 // d1 pwm
#define EnB 4 // d2 pwm
#define In1 15 //d8
#define In2 14 //d5
#define In3 12 //d6
#define In4 13 //d7
 
void setPins()
{
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void setPower(int power){
  analogWrite(EnA, power);
  analogWrite(EnB, power);
}

void stopMotors(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void forward() 
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void forward(int power) 
{
  setPower(power);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void backward()
{
  digitalWrite(In2, HIGH);
  digitalWrite(In1, LOW);
  digitalWrite(In4, HIGH);
  digitalWrite(In3, LOW); 
}

void backward(int power)
{
  setPower(power);
  digitalWrite(In2, HIGH);
  digitalWrite(In1, LOW);
  digitalWrite(In4, HIGH);
  digitalWrite(In3, LOW); 
}


void right(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void right(int power){
  setPower(power);
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}


void left(){
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void left(int power){
  setPower(power);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
