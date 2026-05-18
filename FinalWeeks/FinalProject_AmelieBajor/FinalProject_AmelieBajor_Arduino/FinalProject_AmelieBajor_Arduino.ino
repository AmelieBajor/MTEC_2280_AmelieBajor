const int greenLED = 5;
const int redLED = 6;
const int whiteLED = 9;

const int vertPOT = 1;
const int horiPOT = 2;
const int button = 41;

const int buzzer = 36;


bool GREENbuzzerPlayed = 0;
bool REDbuzzerPlayed = 0;
bool CLOSEbuzzerPlayed = 0;
bool CLOSERbuzzerPlayed = 0;
bool FOUNDbuzzerPlayed = 0;
bool RESETbuzzerPlayed = 0;

bool buttonState = 0;
int horiAdcVAL = 0;
int vertAdcVAL = 0;

int lastTime = 0;
int currentTime = 0;
int timerInterval = 5;



int inByte = 0;
byte val;



void setup() {

  analogReadResolution(7);
  pinMode(button, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
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

  if (Serial.available()){
    inByte = Serial.read();
    if(inByte == 'A'){
      //GREEN LIGHT
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      analogWrite(whiteLED, 0);

      REDbuzzerPlayed = 0;
      CLOSEbuzzerPlayed = 0;
      CLOSERbuzzerPlayed = 0;
      FOUNDbuzzerPlayed = 0;
      RESETbuzzerPlayed = 0;

    if (GREENbuzzerPlayed == 0){

      GREENbuzzerPlayed = 1;
      tone(buzzer, 1000, 10);
    }

    delay(500);
    digitalWrite(greenLED, LOW);

    }

    else if (inByte == 'B'){
    //RED LIGHT
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    analogWrite(whiteLED, 0);

      GREENbuzzerPlayed = 0;
      CLOSEbuzzerPlayed = 0;
      CLOSERbuzzerPlayed = 0;
      FOUNDbuzzerPlayed = 0;
      RESETbuzzerPlayed = 0;

    if (REDbuzzerPlayed == 0){
        REDbuzzerPlayed = 1;
        tone(buzzer, 500, 10);

    }

    delay(50);
    digitalWrite(redLED, LOW);


    }


    else if (inByte == 'C'){
    //WHITE LIGHT FAR
    analogWrite(whiteLED, 0);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);

      GREENbuzzerPlayed = 0;
      REDbuzzerPlayed = 0;
      CLOSEbuzzerPlayed = 0;
      CLOSERbuzzerPlayed = 0;
      FOUNDbuzzerPlayed = 0;
      RESETbuzzerPlayed = 0;
      tone(buzzer, 0, 1);

    }

    else if (inByte == 'D'){
    //WHITE LIGHT CLOSE
    analogWrite(whiteLED, 25);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);

      GREENbuzzerPlayed = 0;
      REDbuzzerPlayed = 0;
      CLOSERbuzzerPlayed = 0;
      FOUNDbuzzerPlayed = 0;
      RESETbuzzerPlayed = 0;

    if(CLOSEbuzzerPlayed == 0){
      CLOSEbuzzerPlayed = 1;
      tone(buzzer, 100, 10);

    }

    }

    else if (inByte == 'E'){
    //WHITE LIGHT CLOSER
    analogWrite(whiteLED, 100);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);

    GREENbuzzerPlayed = 0;
    REDbuzzerPlayed = 0;
    CLOSEbuzzerPlayed = 0;
    CLOSERbuzzerPlayed = 0;
    FOUNDbuzzerPlayed = 0;
    RESETbuzzerPlayed = 0;

    }

    else if (inByte == 'F'){
    //WHITE LIGHT FOUND
    analogWrite(whiteLED, 255);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);

      GREENbuzzerPlayed = 0;
      REDbuzzerPlayed = 0;
      CLOSEbuzzerPlayed = 0;
      CLOSERbuzzerPlayed = 0;
      RESETbuzzerPlayed = 0;
      FOUNDbuzzerPlayed = 0;


    }


    else if (inByte == 'G'){
    //RESET
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    analogWrite(whiteLED, 0);

      GREENbuzzerPlayed = 0;
      REDbuzzerPlayed = 0;
      CLOSEbuzzerPlayed = 0;
      CLOSERbuzzerPlayed = 0;
      FOUNDbuzzerPlayed = 0;

    if(RESETbuzzerPlayed == 0){
    RESETbuzzerPlayed = 1;
    tone(buzzer, 500, 100);
    tone(buzzer, 0, 20);
    tone(buzzer, 500, 100);
    tone(buzzer, 0, 20);
    tone(buzzer, 500, 100);
    tone(buzzer, 0, 20);

    }

    }

    else{

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    analogWrite(whiteLED, 0);
      GREENbuzzerPlayed = 0;
      REDbuzzerPlayed = 0;
      CLOSEbuzzerPlayed = 0;
      CLOSERbuzzerPlayed = 0;
      FOUNDbuzzerPlayed = 0;
      RESETbuzzerPlayed = 0;
      tone(buzzer, 0, 10);


    }



  }



}
