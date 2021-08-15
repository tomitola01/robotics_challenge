double ir_value = 0;

//Rest of the code can be found at https://github.com/atctwo/sumo_robot/blob/master/bean_robot/bean_robot.ino
void loop() {
  //wait until robot senses line
    Serial.println("wait for line");
    while( ir_value < ir_threshold ) 
    {
      ir_value = analogRead(A0);
    }

    //reset ir value
    Serial.println("found line");
    ir_value = 0;

    //go backwards for 3s
    Serial.println("go backwards");
    driveLeftMotor(-motor_speed_drive);
    driveRightMotor(-motor_speed_drive);
    delay(time_backwards);

    //store encoder position at line
    long end_encoder = leftEncoderStore;

    //go backwards for the same distance as the robot went forwards
    
    while(0)
    {
      break;
      Serial.print("distance: ");
      Serial.print(end_encoder  - start_encoder);
      Serial.print("\t\t\telapsed: ");
      Serial.println(leftEncoderStore - end_encoder);
    }
}
