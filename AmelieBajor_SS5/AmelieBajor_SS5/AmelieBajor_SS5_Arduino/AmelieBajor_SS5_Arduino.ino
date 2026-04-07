const int greenLED = 4;
const int redLED = 8;

bool switchLED;

byte val;

int currentTime = 0;
int lastTime = 0;
int timerInterval = 1000;

void setup() {
  // put your setup code here, to run once:

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
  analogReadResolution(10);
}

void loop() {

  if (Serial.available()){
    val = Serial.read();
  }

  currentTime = millis();
  timerInterval = 1000 - (val*2);

  if(currentTime - lastTime >= timerInterval){
    lastTime = currentTime;
    switchLED = !switchLED;
  }

  analogWrite(greenLED, val * switchLED);
  analogWrite(redLED, val * !switchLED);

  if (val >= 250){
    analogWrite(greenLED, 255);
    analogWrite(redLED, 255);
  }

  //Serial.println(switchLED);



  // put your main code here, to run repeatedly:

}
