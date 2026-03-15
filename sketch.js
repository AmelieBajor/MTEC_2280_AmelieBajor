let serial; // declare variable for an instance of the serialport library
let portName = '/dev/tty.usbserial-110';  // fill in your serial port name here
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code

let inData; // declare variable for storing incoming serial data
let diamondColorR = 255;
let diamondColorG = 20;
let diamondColorB = 100;
let diamondStrokeReduce = 50;


function setup() //setup function runs once at beginning
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
  textSize(72); // set text size
  textAlign(CENTER, CENTER);  // set text alignment



}

function draw() //  draw function loops forever at frame rate
{
  background(0);  // clear frame with background color each draw loop

  fill(diamondColorR, diamondColorG, diamondColorB);
  let eye = map(inData, 0, 255, width, 0);
  
  

 /* vertex(0, displayHeight/2);
  vertex(displayWidth/2, mouseY);
  vertex(displayWidth, displayHeight/2);
  vertex(displayWidth/2, mouseY * -1)
  endShape(CLOSE);
*/
 stroke(diamondColorR - diamondStrokeReduce ,diamondColorG - diamondStrokeReduce, diamondColorB - diamondStrokeReduce);
  strokeWeight(10);
line(width/2, 0, width/2, height);

line(0, 0, 0, height);
line(0, height, width, height);
line(width, height, width, 0);
line(width, 0, 0, 0);

strokeWeight(5);

beginShape();



vertex(0, height/2);
vertex(width/2,eye);
vertex(width, height/2);
vertex(width/2, height/1.2 - eye);


 

endShape(CLOSE);
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
  inData = Number(serial.read()); //Store incoming data as a number
  //print(inData);
}
 
function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}
 
function portClose() //gets called when the serial port closes
{
  print("*____SERIAL PORT CLOSED");
}


