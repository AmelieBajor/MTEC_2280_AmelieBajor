const int adcPin = 1;
int adcRead = 0;

int lastTime = 0;
int currentTime = 0;
int timerInterval = 2;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    analogReadResolution(8); // range of 0 - 255
}

void loop() {
  // put your main code here, to run repeatedly:

  currentTime = millis();
  if (currentTime - lastTime >= timerInterval){
    lastTime = currentTime;
    adcRead = analogRead(adcPin);
    //code in this block will only run every 2 milliseconds, freeing up CPU for other tests

  //Serial.println(adcRead);
  Serial.write(adcRead);

  }

  //anything her ewill run more freuqnetly

}
