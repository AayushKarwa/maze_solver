const int lefttrigPin = 2;
const int leftechoPin = 3;
const int fronttrigPin = 4;
const int frontechoPin = 5;
const int righttrigPin = 6;
const int rightechoPin = 7;

const leftmotorPinA = 9;
const leftmotorPinB = 10;
const rightmotorPinA = 11;
const rightmotorPinB = 12;

const int thresholdDistance = 20; //20 centimeters





void setup(){
  pinMode(lefttrigPin,OUTPUT);
  pinMode(leftechoPin,INPUT);
  pinMode(fronttrigPin,OUTPUT);
  pinMode(frontechoPin,INPUT);
  pinMode(righttrigPin,OUTPUT);
  pinMode(rightechoPin,INPUT);
  pinMode(leftmotorPinA,OUTPUT);
  pinMode(leftmotorPinB,OUTPUT);
  pinMode(rightmotorPinA,OUTPUT);
  pinMode(rightmotorPinB,OUTPUT);

  Serial.print(9600);

  stopMotors();
  
}

void loop(){

  int leftdistance = getDistance(lefttrigPin,leftechoPin);
  int frontdistance = getDistance(fronttrigPin,frontechoPin);
  int rightdistance = getDistance(righttrigPin.rightechoPin);

  Serial.print("leftdistance:");
  Serial.println(leftdistance);
  Serial.print("frontdistance:");
  Serial.println(frontdistance);
  Serial.print("rightdistance");
  Serial.println(rightdistance);

  if(frontdstance <= thresholdDistance){
  
  if(rightdistance <= thresholdDistance && leftdistance <= thresholdDistance){
  stopMotors();
  delay(2000);
  turn180Degree();
  }
  
  
  else if(rightdistance <= thresholdDistance && leftdistance >= thresholdDistance){
  stopMotors();
  delay(500);
  moveLeft();
  }

  else if(leftdistance <= thresholdDistance && rightdistance >= thresholdDistance){
  stopMotors();
  delay(500);
  moveRight();
  }

  else if(leftdistance >= 100 && rightdistance >=100 && frontdistance >= 100){
    stopMotors();
    delay(100);
    }
}

else 
{
moveForward();
}

  void stopMotors(){
    digitalWrite(leftmotorPinA,LOW);
    digitalWrite(leftmotorPinB,LOW);
    digitalWrite(rightmotorPinA,LOW);
    digitalWrite(righttmotorPinB,LOW);
    }

  void moveForward(){
    digitalWrite(leftmotorPinA,HIGH);
    digitalWrite(leftmotorPinB,LOW);
    digitalWrite(rightmotorPinA,HIGH);
    digitalWrite(righttmotorPinB,LOW);
  }

  void moveLeft(){

    digitalWrite(leftmotorPinA,LOW);
    digitalWrite(leftmotorPinB,HIGH);
    digitalWrite(rightmotorPinA,HIGH);
    digitalWrite(rightmotorPinB,LOW);
    delay(500);
    stopMotors();
    }

    void moveRight(){

      digitalWrite(leftmotorPinA,HIGH);
      digitalWrite(leftmotorPinB,LOW);
      digitalWrite(righttmotorPinA,LOW);
      digitalWrite(rightmotorPinB,HIGH);
      delay(500);
      stopMotors();

      
      }

      void turn180Degree(){

        digitalWrite(leftmotorPinA,HIGH);
      digitalWrite(leftmotorPinB,LOW);
      digitalWrite(righttmotorPinA,LOW);
      digitalWrite(rightmotorPinB,HIGH);
      delay(2000);
      stopMotors();
        }
  }
  
}
