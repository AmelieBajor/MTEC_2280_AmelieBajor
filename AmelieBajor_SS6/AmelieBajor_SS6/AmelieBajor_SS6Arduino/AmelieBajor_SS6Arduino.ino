
const int adcPin = 1;
const int buttonPin = 41;
const int ledPin = 4;

bool buttonState = 0;

int adcRead = 0;
int inByte = 0;
byte val;

void setup() 
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  analogReadResolution(10); //set ADC from 0 to 1023 range
  Serial.begin(9600); //open serial port at 9600bps
}

void loop()
{
  if(Serial.available()) //if serial buffer is greater than zero...
  {
    inByte = Serial.read(); //store incoming byte
    if(inByte == 'A') //if incoming byte is 'A'...
    {
      digitalWrite(ledPin, 1);  //turn LED ON
      adcRead = analogRead(adcPin); //read pot 1
      buttonState = !digitalRead(buttonPin);  //read button 1
      Serial.print(buttonState);  
      Serial.print(',');          
      Serial.print(adcRead);     
      Serial.print('\n');           
    }
    else if (inByte == 'B') //if incoming byte is 'B'...
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
      Serial.println("Sensor Update Paused...");  //send paused status message
      //using Serial.println adds a newline after each print, so no need for Serial.print('/n')
    }
    else //if incoming byte is neither 'A' nor 'B'...
    {
      digitalWrite(ledPin, 0);  //turn LED OFF
      Serial.println("Rx Byte is neither 'A' nor 'B'"); //send status message
    }
  }
}