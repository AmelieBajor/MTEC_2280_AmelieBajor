//"AmelieB_SS2"

const int buttonPin = 9;

const int ledPinWhite = 4;
const int ledPinGreen = 5;
const int ledPinRed = 6;
const int ledPinBlue = 7;

int ms = 100;
int buttonCount;

bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool fallToggle = 0;




void setup(){

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPinWhite, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  Serial.begin(115200);

}

void loop(){

buttonState = !digitalRead(buttonPin); //flip logic due to input pullup
  Serial.println(buttonState);

//RISING EDGE DETECT
  if (buttonState && !lastButtonState) //button went from 
  {
    toggle = !toggle;
  }

  if (!buttonState && lastButtonState)
  {
    fallToggle = !fallToggle;
  }

  lastButtonState = buttonState;
  Serial.printf("Button = %i _ Toggle = %i _ Falling = %i /n", buttonState, toggle, fallToggle);


  if(buttonState && !lastButtonState){
    toggle = !toggle;
    
  }

  if (!buttonState && lastButtonState){
    fallToggle = !fallToggle;
    
  }



if (toggle)
{
  pattern1();
  delay(ms);
  pattern2();
  delay(ms);
  pattern3();
  delay(ms);
  pattern4();
  delay(ms);
  pattern5();
  delay(ms);
  pattern6();
  delay(ms);
}

else if (buttonCount = 0){
}
  digitalWrite(ledPinWhite, LOW);
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinBlue, LOW);
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

}




