const int pinArray[] = {1, 41, 15, 7, 6};

const int potPin = pinArray[0];

const int buttonPin = pinArray[1]; //button

const int ledPinRED = pinArray[2]; //potentiometer + LED
const int ledPinGREEN = pinArray[3];
const int ledPinBLUE = pinArray[4];


bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool fallToggle = 0;





int ms = 100;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12); //potentiometer

  pinMode(buttonPin, INPUT_PULLUP); //button
  pinMode(ledPinRED, OUTPUT); //Potentiometer + LED
  pinMode(ledPinGREEN, OUTPUT); // Button + LED

}

void loop() {
  int adcVal = analogRead(potPin); //potentiometer
  Serial.println(adcVal); //potentiometer

  buttonState = !digitalRead(buttonPin); //Button

  if (buttonState && !lastButtonState){
    toggle = !toggle;
  }


  if(!buttonState && lastButtonState){
    fallToggle = !fallToggle;
  }


  lastButtonState = buttonState;


  for (int i = 0; i <= 255; i++){
    analogWrite(ledPinBLUE, i);
    if (millis() > 100){


    }

  if (i > 255){
    i = 0;
  }

}



  digitalWrite(ledPinGREEN, toggle);
  analogWrite(ledPinRED, adcVal);
  Serial.printf("Button = %i _ Toggle = %i _ Falling = %i /n", buttonState, toggle, fallToggle);


}
