#ifndef MICROMOUSE_H_
#define MICROMOURE_H_
/*Motor definitions*/
#define ENABLE            A6
#define MOTOR_0_1A        11
#define MOTOR_0_2A        5
#define MOTOR_1_1A        6  
#define MOTOR_1_2A        9
#define ENCODER_0_CHA     2
#define ENCODER_0_CHB     13
#define ENCODER_1_CHA     3
#define ENCODER_1_CHB     8

/*Infrared sensors definitions*/
#define IR0_TX       A1
#define IR1_TX       12
#define IR2_TX       7
#define IR3_TX       4
#define IR0_RX       A0
#define IR1_RX       A7
#define IR2_RX       A2
#define IR3_RX       A3

/*Extras*/
#define BUTTON      10
#define USER_LED    13  //Do not use this and ENCODER_0_CHB pin at the same time!

const int speed = 30;
int ir_delay = 150;
void ir_init()
{
   pinMode(IR0_TX, OUTPUT);
   pinMode(IR1_TX, OUTPUT);
   pinMode(IR2_TX, OUTPUT);
   pinMode(IR3_TX, OUTPUT);
  
   digitalWrite(IR0_TX, LOW);
   digitalWrite(IR1_TX, LOW);
   digitalWrite(IR2_TX, LOW);
   digitalWrite(IR3_TX, LOW);
}

int ir0_read()
{
  digitalWrite(IR0_TX, HIGH);
  delayMicroseconds(ir_delay);
  int value = analogRead(IR0_RX);
  digitalWrite(IR0_TX, LOW);

  return value;
}

int ir1_read()
{
  digitalWrite(IR1_TX, HIGH);
  delayMicroseconds(ir_delay);
  int value = analogRead(IR1_RX);
  digitalWrite(IR1_TX, LOW);

  return value;
}

int ir2_read()
{
  digitalWrite(IR2_TX, HIGH);
  delayMicroseconds(ir_delay);
  int value = analogRead(IR2_RX);
  digitalWrite(IR2_TX, LOW);

  return value;
}

int ir3_read()
{
  digitalWrite(IR3_TX, HIGH);
  delayMicroseconds(ir_delay);
  int value = analogRead(IR3_RX);
  digitalWrite(IR3_TX, LOW);

  return value;
}
void enableMotors()
{
   pinMode(ENABLE, OUTPUT);
   pinMode(MOTOR_0_1A, OUTPUT);
   pinMode(MOTOR_0_2A, OUTPUT);
   pinMode(MOTOR_1_1A, OUTPUT);
   pinMode(MOTOR_1_2A, OUTPUT);
}


void forward(int t)
{
 analogWrite(MOTOR_0_1A, 0);
 analogWrite(MOTOR_0_2A, speed);
 analogWrite(MOTOR_1_1A, speed);
 analogWrite(MOTOR_1_2A, 0);
 delay(t);
}



void backward(int t)
{
 analogWrite(MOTOR_0_1A, speed);
 analogWrite(MOTOR_0_2A, 0);
 analogWrite(MOTOR_1_1A, 0);
 analogWrite(MOTOR_1_2A, speed);
 delay(t);
}

void stop_motors()
{
 analogWrite(MOTOR_0_1A, 0);
 analogWrite(MOTOR_0_2A, 0);
 analogWrite(MOTOR_1_1A, 0);
 analogWrite(MOTOR_1_2A, 0);
}

#endif
