#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4);


const int pinReceiver_1 = 1; //digital pins where each of the reviever plugs into on the arduino 
const int pinReceiver_2 = 2; 
const int pinReceiver_3 = 3;
const int pinReceiver_4 = 4;
const int pinReceiver_5 = 5;
int a=0;    //defining the count for each of the counters to define the height of each column
int b=0;
int c=0;
int d=0;
int e=0;

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //defining the display !!!Make sure the arduino has the adafruit library installed otherwise this won't work!!!
    pinMode(pinReceiver_1, INPUT);
    pinMode(pinReceiver_2, INPUT);
    pinMode(pinReceiver_3, INPUT);
    pinMode(pinReceiver_4, INPUT);
    pinMode(pinReceiver_5, INPUT);// set the reciever pin to input mode
    Serial.begin(9600); // Setup serial connection for print out to console

    
    display.clearDisplay();
    display.display();
    
}

void loop() {
  
    //note that this display is 128 pixels by 32
  int value_1 = digitalRead(pinReceiver_1); //reading the digital values from each reciever
  int value_2 = digitalRead(pinReceiver_2);
  int value_3 = digitalRead(pinReceiver_3);
  int value_4 = digitalRead(pinReceiver_4);
  int value_5 = digitalRead(pinReceiver_5);

  
  display.setCursor(0,0);
  display.println("Filled Rectangle");
  

  
  //fillRect(x_cord of starting point, y_cord of starting point, width of rect, height of rect, color) 
  display.fillRect(0, 0, 6, a, WHITE);

  display.println("Filled Rectangle");
  display.fillRect(29, 0, 6, b, WHITE);

  display.println("Filled Rectangle");
  display.fillRect(61, 0, 6, c, WHITE);

  display.println("Filled Rectangle");
  display.fillRect(90, 0, 6, d, WHITE);

  display.println("Filled Rectangle");
  display.fillRect(122, 0, 6, e, WHITE);
  
  //printing each column with a height x
  
  display.display();

  
  
  Serial.print("Has a marble been detected?:   ");

  if  (value_1 == 0){ //working out whether a marble has been detected 0 break in the signal - print to console
    Serial.println( " Marble detected pin 1 " );
    a++; //increasing the height by 1 
    if (a==32) { //reseting once we reach the limit of the screen
      a=0;
    }
     
  }

  if  (value_2 == 1){
    Serial.println( " Marble detected pin 2  " );
    b++;
    delay(30);

    if (b==32) {
      b=0;
    }
     
  }

  if  (value_3 == 1){
    Serial.println( " Marble detected pin 3  " );
    c++;
    delay(40);
    if (c==32) {
      c=0;
    }
     
  }

  if  (value_4 == 1){
    Serial.println( " Marble detected pin 4  " );
    d++;
    delay(20);

    if (d==32) {
      d=0;
    }
     
  }

  if  (value_5 == 0){
    Serial.println( " Marble detected pin 5  " );
    e++;
    if (e==32) {
      e=0;
    }
     
  }
  delay(10); //delaying every 0.3s to avoid mal detection 
}
