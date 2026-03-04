const int potPin = 1; //potentiometer

const int buttonPin = 16; //button

const int ledPinPOT = 15; //potentiometer + LED
const int ledPinBUT = 7;



bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool fallToggle = 0;


void setup() {
  Serial.begin(115200);

  analogReadResolution(12); //potentiometer

  pinMode(buttonPin, INPUT_PULLUP); //button
  pinMode(ledPinPOT, OUTPUT); //Potentiometer + LED
  pinMode(ledPinBUT, OUTPUT); // Button + LED
  
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

  digitalWrite(ledPinBUT, toggle);
  analogWrite(ledPinPOT, adcVal);
  Serial.printf("Button = %i _ Toggle = %i _ Falling = %i /n", buttonState, toggle, fallToggle);


}
