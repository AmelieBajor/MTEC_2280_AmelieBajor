//"YourName_SS1"

const int ledPinWhite = 4;
const int ledPinGreen = 5;
const int ledPinRed = 6;
const int ledPinBlue = 7;

int ms = 100;

int patternCount1 = 0;
int patternCount2 = 0;
int patternCount3 = 0;
int patternCount4 = 0;
int patternCount5 = 0;
int patternCount6 = 0;



void setup(){

  pinMode(ledPinWhite, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  Serial.begin(115200);

}

void loop(){

  if (patternCount1 <= 10){
    pattern1();
  }
  else if (patternCount1 > 10){
    if (patternCount2 <= 10){
      pattern2();
    }
    else if (patternCount2 > 10){
      if (patternCount3 <= 10){
        pattern3();
      }
      else if (patternCount3 > 10){
        if (patternCount4 <= 10){
          pattern4();
        }
        else if (patternCount4 > 10){
          if (patternCount5 <= 10){
            pattern5();
          }
          else if (patternCount5 > 10){
            if (patternCount6 <= 10){
              pattern6();
            }
            else if (patternCount6 > 10){
              patternCount1 = 0;
              patternCount2 = 0;
              patternCount3 = 0;
              patternCount4 = 0;
              patternCount5 = 0;
              patternCount6 = 0;
            }
          }
        }
      }
    }
  }





}

void pattern1(){

  digitalWrite(ledPinWhite, HIGH);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinBlue, LOW);

  delay(ms);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);

  delay(ms);
  patternCount1 ++;

}



void pattern2(){

  digitalWrite(ledPinWhite, HIGH);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);

  delay(ms);
  patternCount2 ++;


  
}

void pattern3(){
  digitalWrite(ledPinWhite, HIGH);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, HIGH);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

    digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

    digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 2);

  patternCount3 ++;



}

void pattern4(){

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms * 3);

  digitalWrite(ledPinWhite, HIGH);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms * 3);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinBlue, LOW);

  delay(ms * 3);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);

  delay(ms * 3);

  patternCount4 ++;

}


void pattern5(){

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);

  delay(ms / 3);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 3);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 3);

  digitalWrite(ledPinWhite, HIGH);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms / 3);

  patternCount5 ++;

}

void pattern6(){

  digitalWrite(ledPinWhite, HIGH);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms * 4);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);

  delay(ms * 4);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinBlue, LOW);

  delay(ms * 4);

  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, HIGH);

  delay(ms * 4);

  patternCount6 ++;

}




