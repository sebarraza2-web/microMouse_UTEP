#include "micromouse.h"
#include <Encoder.h>

Encoder right_encoder(ENCODER_0_CHA, ENCODER_0_CHB);
Encoder left_encoder(ENCODER_1_CHA, ENCODER_1_CHB);

void backward();
void forward();
void stop_motors();
void enableMotors();

void setup() {    
  //Pin Setup
  enableMotors();
  ir_init;
  ir0_read;
  ir1_read;
  ir2_read;
  ir3_read;
  
  /*Setup button pin*/
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  Serial.println("El Raton Mas Vergon: Que rollo crabon");
  Serial.println("---------------------------------------");
}

 void loop() {
 /*Wait for user input*/
 while(digitalRead(BUTTON) != HIGH);
  {
    Serial.println("Button Has Been Pressed");
    /*read infared LED values*/
    
    long int right_encoder_count;
    long int left_encoder_count;
    long int average_encoder_count = 0;
         int ir0_value;
         int ir3_value;
    long int average_ir_value = 0;
    
    delay(1000); 
    forward(1000);

    while(average_encoder_count < 1090)
    {
      ir0_value = ir0_read();
      ir3_value = ir3_read(); 
      average_ir_value = (ir0_value+ir3_value)/2;
      if(average_ir_value >= 250)
        exit;
      else
      { 
        right_encoder_count = right_encoder.read();
        left_encoder_count = left_encoder.read();
        Serial.print(right_encoder_count);
        Serial.print(",");
        Serial.print(left_encoder_count);
        Serial.print(",");
        average_encoder_count = (right_encoder_count - left_encoder_count)/2;
        Serial.println(average_encoder_count);
        delay(20);
      }
    } 
    stop_motors();
    right_encoder.write(0);
    left_encoder.write(0);
    backward(1000);
    average_encoder_count = 0;
    while(average_encoder_count < 1090)
    {
      ir0_value = ir0_read();
      ir3_value = ir3_read(); 
      average_ir_value = (ir0_value+ir3_value)/2;
      if(average_ir_value >= 250){
        exit;
      }
      else
      { 
      right_encoder_count = right_encoder.read();
      left_encoder_count = left_encoder.read();
      Serial.print(right_encoder_count);
      Serial.print(",");
      Serial.print(left_encoder_count);
      Serial.print(",");
      average_encoder_count = (-right_encoder_count + left_encoder_count)/2;
      Serial.println(average_encoder_count);
      Serial.println(average_ir_value);
      delay(20);
      }
    }
    Serial.print(right_encoder_count);
    Serial.print(",");
    Serial.print(left_encoder_count);
    Serial.print(",");
    Serial.println(average_encoder_count);
    
    stop_motors();
    right_encoder.write(0);
    left_encoder.write(0);
  }
 }
 //NEED TO DO: 
 //Cannot use wirelessly. FIX IT.
 //Integrate IR code and write averaging code and collision detection code
 /*Serial.println(ir0);
  Serial.println(ir1);
  Serial.println(ir2);
  Serial.println(ir3);*/
