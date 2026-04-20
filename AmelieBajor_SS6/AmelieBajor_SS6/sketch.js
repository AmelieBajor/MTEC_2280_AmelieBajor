let serial; // variable for instance of the serialport library
let portName = '/dev/tty.usbserial-110'; // fill in your serial port name
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code

let rxFlag = false; // flag to indicate when new data has been received
let firstContact = false; // flag to indicate when the first contact has been made with the serial port
let sensors = [0, 0]; // declare array to hold incoming sensor data, and initialize with zeros
let pot = 0; // variable to hold potentiometer value
let button = 0; // variable to hold button value

let xPos = 540;


function setup() 
{
  //P5 Sketch Setup
  createCanvas(1080, 720);
  textAlign(CENTER, CENTER);
  textSize(24);
  strokeWeight(4);
  stroke(127);

  //P5 SerialPort Setup
  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port
}

function draw() 
{
  background(0);


  noStroke();
  fill(255);

  

  

  if (!firstContact)  //if we have not yet received any data...
  {
  // display "Waiting" page
    background(150, 0, 50);
    fill(255);
    noStroke();
    fill(255,0,50);
    circle(width/2, height/1.1, 140);
    fill(0);
    text("START", width/2, height/1.1);
  }
  else  //if we have established contact with the serial port, show main sketch...
  {
    circle(width/2, height/1.1, 140);
fill(0);
    if (rxFlag){
      

      background(0, 0, button-150);
    fill(pot, 0, button);
    rect(0, height/1.5, width, 10);

    if (keyIsPressed === true){
      if (keyCode === LEFT_ARROW){
         xPos -= 5;
      }

      else if (keyCode === RIGHT_ARROW){
          xPos += 5;
      }
    
      }

          fill(255);
          circle(xPos, height/1.4, 20);
          circle(width/2, height/1.1, 140);
}
else if (!rxFlag){
    background(255);
    fill(button, pot, 0);
    rect(0, height/1.5, width, 10);

    rect(xPos-7, (height/1.4) + 10, 15, -pot*2.5);
    
    fill(0);
    circle(xPos, (height/1.4)+5, 20);
    circle(width/2, height/1.1, 140);
}

  }
}



function mousePressed() //if mouse is pressed...
{
  if (dist(mouseX, mouseY, width/2, height/1.1) < 70) // if mouse postion is within the radius of the circle button...
  {
    
    rxFlag = !rxFlag; // toggle the rxFlag

    if (rxFlag) //if rxFlag is true, we want to receive data, so...
    {
      serial.write('A'); // send 'A' to the serial port to indicate that we want to receive data
    }
    else  //if rxFlag is false, we want to pause receiving data, so...
    {
      serial.write('B'); // send 'B' to the serial port to indicate that we want to pause receiving data
    }
  }
}

function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}

function portClose() //gets called when the serial port closes
{
  print("SERIAL PORT CLOSED");
}

function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serialEvent() // gets called when new serial data arrives
{
  if (!firstContact)  //if we have not yet received any data, this is our first contact with the serial port, so...
  {
    print("FIRST CONTACT"); //print "FIRST CONTACT" to the console
    firstContact = true;  //set firstContact flag to true
  }
  
  if(rxFlag)  //if rxFlag is true, we want to receive data, so...
  {
    let inString = serial.readStringUntil('\n'); // read the incoming string until you get a newline character
    if (inString.length > 0) 
    {
      print("Rx String: " + inString); // print the incoming string to the console
      sensors = split(inString, ','); // split the string into an array of sensor values
    
      if(sensors.length >= 2) // check if we have all 4 sensor values before trying to access them
      {
        print(sensors); // print the array of sensor values to the console

        button = Number(sensors[0]); // convert the first sensor value to an integer
        button = map(button, 0, 1, 0, 255); // map the button value from boolean true/false to 0-255

        
        pot = Number(sensors[1]); // convert the third sensor value to an integer
        pot = map(pot, 0, 1023, 0, 255); // map the potentiometer value from 0-1023 to 0-255
        pot = floor(pot); // round the potentiometer value to an integer

        print("Button: " + button + " Pot: " + pot);  //print mapped sensor values to the console

        //now that we're done processing the incoming data, we can "call out" to our microcontroller, which respond with latest sensor data.
        serial.write('A');  // send 'A' to the serial port to indicate that we want the latest sensor data
      }
    }
  }
  else
  {
    let inString = serial.readStringUntil('\n'); // read the incoming string until you get a newline character
    print(inString); // print the incoming string to the console
  }
}

function serialError(err) //gets called when there's an error
{
  print('SERIAL ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERIAL SERVER");
}