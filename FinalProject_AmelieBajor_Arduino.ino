const int greenLED = 5;
const int redLED = 6;
const int whiteLED = 9;

const int vertPOT = 1;
const int horiPOT = 2;

const int button = 41;
bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool fallToggle = 0;


byte horiVal;
byte vertVal;
byte butVal;


void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);

  analogReadResolution(12);

  Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = !digitalRead(button);
  int vertAdcVAL = analogRead(vertPOT);
  int horiAdcVAL = analogRead(horiPOT);



  if(buttonState && !lastButtonState){
    toggle = !toggle;
  }

  if(!buttonState && lastButtonState){
    fallToggle = !fallToggle;
  }

  lastButtonState = buttonState;

  Serial.printf("Vertical Pot = %i _ Horizontal Pot = %i _ Button = %i \n", vertAdcVAL, horiAdcVAL, buttonState);




}
