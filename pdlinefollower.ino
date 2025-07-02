#define Kp 0 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd 0 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define rightMaxSpeed 220 // max speed of the robot
#define leftMaxSpeed 220 // max speed of the robot
#define rightBaseSpeed 160 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 160  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  5     // number of sensors used
//only if your dong calibration here
//#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
//#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

#define rightMotor1 4
#define rightMotor2 5
#define rightMotorPWM 9
#define leftMotor1 2
#define leftMotor2 3
#define leftMotorPWM 10

//ir sensor connections
#define l2 A0
#define l1 A2
#define c A3
#define r1 A4
#define r2 A5


//if you are using the polulu sensor that jagath is getting
//QTRSensorsRC qtrrc((unsigned char[]) {  14, 15, 16, 17, 18, 19} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19
//unsigned int sensorValues[NUM_SENSORS];

void setup()
{
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  Serial.begin(9600);
    
 } 

int lastError = 0;

void loop()
{
 int x0= digitalRead(l2);
 int x1= digitalRead(l1);
 int x2= digitalRead(c);
 int x3= digitalRead(r1);
 int x4= digitalRead(r2);
 // do the thresholdig here
 
 
  int position = x0*0+x1*1000+x2*2000+x3*3000+x4*4000;
  int error = position - 2500;

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
  if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive

  Serial.println(x0);
  Serial.println(x1);
  Serial.println(x2);
  Serial.println(x3);
  Serial.println(x4);

   {
// move forward with appropriate speeds
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
 analogWrite(rightMotorPWM, rightMotorSpeed);

  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftMotorPWM, leftMotorSpeed);
  Serial.println("forward");
  
}
}
  
void wait(){

     digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
   digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  Serial.println("stop");
}
