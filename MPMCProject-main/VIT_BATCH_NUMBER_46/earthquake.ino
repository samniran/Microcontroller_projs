#include <LiquidCrystal.h>

LiquidCrystal lcd( 7, 6, 5, 4, 3, 2);
unsigned char Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };	
unsigned char Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };	

//Analog read pins
const int xPin = A2;
const int yPin = A1;
const int zPin = A0;

int minVal = 265;
int maxVal = 402;
//to hold the caculated values
double x;
double y;
double z;




void setup()
   {
    Serial.begin(9600);
  	lcd.begin(16,2);
   }//end setup()


void loop()
   {
  	
    speeder(); 
   }//end loop()


void speeder()
   {
  	delay(3000);
  	lcd.clear();
    //read the analog values from the accelerometer
    int xRead = analogRead(xPin);
    int yRead = analogRead(yPin);
    int zRead = analogRead(zPin);
    //convert read values to degrees -90 to 90 – Needed for atan2
    int xAng = map(xRead, minVal, maxVal, -90, 90);
    int yAng = map(yRead, minVal, maxVal, -90, 90);
    int zAng = map(zRead, minVal, maxVal, -90, 90);

    x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
    y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
    z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);
  	//lcd print
  	if(x<=90){
  		lcd.setCursor(2,0);
  		lcd.print("x");
  		lcd.setCursor(0,1);  
  		lcd.print(x);
  		lcd.setCursor(9,0);
  		lcd.print("y");
  		lcd.setCursor(8,1);  
    	lcd.print(y);}
  	else{
    	lcd.setCursor(0,0);
    	lcd.print("Earthquake Alert");
  		}
    
    
   }//end of speeder()


  