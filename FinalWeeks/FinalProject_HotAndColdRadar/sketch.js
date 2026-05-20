

let serial; // declare variable for an instance of the serialport library
let portName = '/dev/tty.usbserial-110';  // fill in your serial port name here
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code

let inData = 0; // variable for storing incoming serial data
let sensors = [0, 0, 0]; // array to hold sensor values: [horiPOT, vertPOT, button]

let lineThickness = 1;
let lineColor;
let backgroundColor;

let lineX = 0;
let lineY = 0;

let targetX = 540;
let targetY = 360;
let score = 0;



function setup() 
{
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

  //TYPICAL P5.JS SETUP
  createCanvas(1080, 720);
  textSize(64);
  textAlign(CENTER, CENTER);
  strokeWeight(10);
  stroke(1);




}

function draw() //  draw function loops forever at frame rate
{




  lineX = map(sensors[0], 0, 127, 0, displayWidth);
  lineY = map(sensors[1], 0, 127, 0, displayHeight);



    if (targetX - 175 < lineX && lineX < targetX + 175 && targetY - 175 < lineY && lineY < targetY + 175){
    serial.write('D');

    if (targetX - 75 < lineX && lineX < targetX + 75 && targetY - 75 < lineY && lineY < targetY + 75){
        serial.write('E');

        if (targetX - 25 < lineX && lineX < targetX + 25 && targetY - 25 < lineY && lineY < targetY + 25){
    serial.write('F');

    }
    }
    }

    else{
      serial.write('C');
    }

  if(sensors[2]){
    if (targetX - 25 < lineX && lineX < targetX + 25 && targetY - 25 < lineY && lineY < targetY + 25){
    serial.write('A');
    targetX = random(0, 1080);
    targetY = random(0, 720);
    }

    else{
      serial.write('B');
    }
  }

  else{
    backgroundColor = 0;
    lineThickness = 5;
    lineColor = 255;
  }

  background(0, 50, 0);

  for(i=0; i<width; i += 20){
  stroke(0, 60, 0);
  strokeWeight(2);
  line(0, i, width, i);
  }


  strokeWeight(4);
  noFill();

  stroke(150, 255, 150);
  circle(targetX, targetY, 350);

  strokeWeight(4);
  stroke(100, 255, 100);
  fill(0, 70, 0);
  circle(targetX, targetY, 150);

  noStroke();
  fill(0, 255, 0);
  circle(targetX, targetY, 50);

  
    if (0 < targetX && targetX < width && 0 < targetY && targetY < height){
      if(keyIsPressed === true){
    if (keyCode === UP_ARROW){
      targetY -= 1;
    }
    if (keyCode === DOWN_ARROW){
      targetY += 1;
    }
    if (keyCode === LEFT_ARROW){
      targetX -= 1;
    }
    if (keyCode === RIGHT_ARROW){
      targetX += 1;
    }
  }
    }
    else{
        targetX = random(0, 1080);
        targetY = random(0, 720);
        serial.write('G');
    }



  stroke(0, 255, 0);
  strokeWeight(lineThickness);
  line(lineX, 0, lineX, displayHeight);
  line(0, lineY, displayWidth, lineY);
  fill(255);
  circle(lineX, lineY, lineThickness*2);

  fill(0, 50, 0);
  circle(lineX, lineY, lineThickness * 4);

  fill(255);
  noStroke();
  circle(lineX, lineY, lineThickness);

strokeWeight(25);
  stroke(0, 100, 0);
  line(0, 0, width, 0);
  line(width, 0, width, height);
  line(width, height, 0, height);
  line(0, height, 0, 0);


fill(0,255,0);
noStroke();
rect(lineX - 15, 0, 30, 30);
rect(lineX - 15, height-30, 30, 30);

rect(0, lineY - 15, 30, 30);
rect(width -30, lineY - 15, 30, 30);


}










function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}
 
function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}
 
function serialEvent() //gets called when new data arrives
{
  let inString = serial.readStringUntil('\n'); // read until newline character
  if (inString.length > 0) //if there's data in the string
  {
    sensors = split(inString, ','); // split the string at commas and store in array
    
    for (let i = 0; i < sensors.length; i++) 
    {
      // Number() function converts string to number
      sensors[i] = Number(sensors[i]); // convert every element in array to numbers

      // You can also use parseInt() function, which takes a second argument for the base (radix).
      // A base of 10 is for decimal numbers, base of 16 is for hexadecimal, base of 2 is for binary.
      // sensors[i] = parseInt(sensors[i], 10); // converts every element in array to decimal number
    }
    //print(sensors);
  } 
}
 
function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}
 
function portClose() //gets called when the serial port closes
{
  print("*____SERIAL PORT CLOSED");
}