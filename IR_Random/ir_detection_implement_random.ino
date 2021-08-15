#define IR_PIN A0

//Rest of the code can be found at https://github.com/atctwo/sumo_robot/blob/master/Sumo_Robot_Random/Sumo_Robot_Random.ino
void loop() 
{
  int distanceForward = frontSensor.read();
  double ir_val = analogRead(IR_PIN);
  delay(50);

# ifdef RANDOM_DIRECTION
  if (random(50) == 1)
  {
# else
  if (distanceForward < 80)
  {
# endif /*RANDOM_DIRECTION*/

    stopMotors();
    
    //sprintForward(normalSpeed, 1000);
    while(1)
    {
      driveLeftMotor(normalSpeed);
      driveRightMotor(normalSpeed);

      if (ir_val >= 900.0) 
      {
        driveLeftMotor(-normalSpeed);
        driveRightMotor(-normalSpeed);
        break;
      }
    }
  }
  
  //else rotate
  else
  {
    driveRightMotor(-slowSpeed);
    driveLeftMotor(slowSpeed); 
    delay(20);
    stopMotors();
  }
}
