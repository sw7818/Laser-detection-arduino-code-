#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4);


const int pinReceiver_1 = 1;
const int pinReceiver_2 = 2;
const int pinReceiver_3 = 3;
const int pinReceiver_4 = 4;
const int pinReceiver_5 = 5;
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
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
  int value_1 = digitalRead(pinReceiver_1);
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
  
  display.display();
  
  Serial.print("Has a marble been detected?:   ");

  if  (value_1 == 0){
    Serial.println( " Marble detected pin 1 " );
    a++;
     
  }

  if  (value_2 == 0){
    Serial.println( " Marble detected pin 2  " );
    b++;
     
  }

  if  (value_3 == 0){
    Serial.println( " Marble detected pin 3  " );
    c++;
     
  }

  if  (value_4 == 0){
    Serial.println( " Marble detected pin 4  " );
    d++;
     
  }

  if  (value_5 == 0){
    Serial.println( " Marble detected pin 5  " );
    e++;
     
  }
  delay(300);
}
