const int greenLED = 5;
const int redLED = 6;
const int whiteLED = 9;

const int vertPOT = 1;
const int horiPOT = 2;
const int button = 41;

bool buttonState = 0;
int horiAdcVAL = 0;
int vertAdcVAL = 0;

int lastTime = 0;
int currentTime = 0;
int timerInterval = 5;



void setup() {

  analogReadResolution(10);
  pinMode(button, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:


  horiAdcVAL = analogRead(horiPOT);
  vertAdcVAL = analogRead(vertPOT);
  buttonState = !digitalRead(button);

  currentTime = millis();
  if (currentTime - lastTime >= timerInterval){
    lastTime = currentTime;
    Serial.print(horiAdcVAL);
    Serial.print(',');
    Serial.print(vertAdcVAL);
    Serial.print(',');
    Serial.print(buttonState);
    Serial.print('\n');

  }


}
