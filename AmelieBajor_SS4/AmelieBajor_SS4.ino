const int potPin1 = 1;
const int potPin2 = 2;
const int butPin1 = 41;
const int butPin2 = 42;


bool butState1 = 0;
bool butState2 = 0;
int potRead1 = 0;
int potRead2 = 0;


int lastTime = 0;
int currentTime = 0;
int timerInterval = 5;


void setup() {
  analogReadResolution(10);
  pinMode(butPin1, INPUT_PULLUP);
  pinMode(butPin2, INPUT_PULLUP);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  potRead1 = analogRead(potPin1);
  potRead2 = analogRead(potPin2);


  butState1 = !digitalRead(butPin1);
  butState2 = !digitalRead(butPin2);


  currentTime = millis();
  if(currentTime - lastTime >= timerInterval){
    lastTime = currentTime;
    Serial.print(butState1);
    Serial.print(',');
    Serial.print(butState2);
    Serial.print(',');
    Serial.print(potRead1);
    Serial.print(',');
    Serial.print(potRead2);
    Serial.print('\n');
  }

}
