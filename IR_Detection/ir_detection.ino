#define sensor A0
#define DIR_R_A 8
#define DIR_R_B 7
#define END_R 5
#define DIR_L_A 11
#define DIR_L_B 9
#define END_L 6


int turnSpeed = 90;
int foundSpeed = 150;
int searchSpeed = 120;
int stopM = 0;


void setup() {
  pinMode(sensor, INPUT);
  pinMode(DIR_R_A, OUTPUT);
  pinMode(DIR_R_B, OUTPUT);
  pinMode(END_R, OUTPUT);
  pinMode(DIR_L_A, OUTPUT);
  pinMode(DIR_L_B, OUTPUT);
  pinMode(END_L, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  double detect = analogRead(sensor);
  //Serial.println(detect);
  int distanceForward = frontSensor.read();
  Serial.println(distanceForward);
  delay(50);
  if(distanceForward < 80){
    leftMotor(stopM);
    rightMotor(stopM);
    leftMotor(foundSpeed * 1.3);
    rightMotor(foundSpeed);
  }
  if(detect >= 900){
    leftMotor(stopM);
    rightMotor(stopM);
    delay(100);
    leftMotor(searchSpeed*1.3);
    rightMotor(-(searchSpeed));
    delay(1000);
    rightMotor(turnSpeed);
    leftMotor(turnSpeed);
    delay(1000);
    //Serial.println("Black");
  }else{
    leftMotor(-(searchSpeed)*1.3);
    rightMotor(searchSpeed);
    //Serial.println("White");
  }
}

void leftMotor(int left){
  analogWrite(END_L, abs(left));
  if(left>0){
    digitalWrite(DIR_L_A, LOW);
    digitalWrite(DIR_L_B, HIGH);
  }else if(left<0){
    digitalWrite(DIR_L_A, HIGH);
    digitalWrite(DIR_L_B, LOW);
  }else{
    digitalWrite(DIR_L_A, LOW);
    digitalWrite(DIR_L_B, LOW);
  }
}

void rightMotor(int right){
  analogWrite(END_R, abs(right));
  if(right>0){
    digitalWrite(DIR_R_A, LOW);
    digitalWrite(DIR_R_B, HIGH);
  }else if(right< 0){
    digitalWrite(DIR_R_A, HIGH);
    digitalWrite(DIR_R_B, LOW);
  }else{
    digitalWrite(DIR_R_A, LOW);
    digitalWrite(DIR_R_B, LOW);
  }
}
