let serial;
let portName = '/dev/tty.usbserial-110';
let options = {baudRate: 9600};
let outByte = 0;




function setup() {
  createCanvas(400, 720);
  textAlign(CENTER,CENTER);
  textSize(36);

  serial = new p5.SerialPort();
  serial.on('list', printList);
  serial.on('connected', serverConnected);
  serial.on('open', portOpen);
  serial.on('data', serialEvent);
  serial.on('error', serialError);
  serial.on('close', portClose);
  serial.list();
  serial.open(portName, options);

  

}

function draw() {
  //____GFX_START____//
  //draw gradient background with for loop
  
  background(0);




   for (let i = 0; i < height; i++)
  {
    let c = map(i, 0, height, 0, 255);  //map i to 0-255 range for color
    stroke(2/c, 2*c, outByte);    //change stroke color for each x position, red is scaled to 2x
    line(0, i, width, i);  //draw vertical line for each x position
  }


  //mouse position indicator
  stroke(255-mouseY)
  fill(mouseY);
  circle(width/2, mouseY, 20);

  stroke(mouseY);
  fill(255-mouseY);
  circle(width/2,mouseY, 10);

  //____GFX_END____//

  if(mouseY < height && mouseY > 0) //if mouseY is within canvas...
  {
    let posX = constrain(mouseY, 0, height); // constrain mouseX to canvas width, store as posX
    outByte = map(posX, 0, height, 0, 255); //remap posX to 0-255 range
    outByte = floor(outByte); // convert to integer, cut off decimal values
    serial.write(outByte);   //send byte across serial port
  }

  fill(255);
  text("DIM + SLOW", width/2, 50);
  fill(0);
  text("LIGHT + FAST", width/2, height-150);
  text("BOTH LIGHTS ON", width/2, height - 50);

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
  //only sending data to microcontroller in this sketch, so not being used
}

function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}
