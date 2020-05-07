#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal Skjar(6 , 7, 5, 4, 3, 2);
const int trigPin = 11;
const int echoPin = 10;
long duration;
int CM;

bool forward , backward , right , left =0;
void setup()
{
  Skjar.begin(16,2);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);


}

void loop()
{
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  CM = duration*0.034/2;
  
  Skjar.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  Skjar.print("Fjarlaegd:"); // Prints string "Distance" on the LCD
  Skjar.print(CM); // Prints the distance value from the sensor
  Skjar.print("cm");

  if (CM > 100){ //Ég skrifaði þessar if setningar alveg sjálfur svo að það sé á hreynu!
    Skjar.setCursor(0,1);
    Skjar.print("Metrar: ");
    Skjar.print(CM/100);
    Skjar.print("     ");
  	delay(2);
  }
 
  if (CM >51 and CM < 79){
  	Skjar.setCursor(0,1);
    Skjar.print("Passadu Tig!");
  }
  if (CM <= 50){
	Skjar.setCursor(0,0);
    Skjar.print("STOP!        ");
    Skjar.setCursor(0,1);
    Skjar.print("FAERDU BILINN!");
    delay(500);
  }
  if (CM < 100 and CM > 80){
  Skjar.setCursor(0,1);
  Skjar.print("Metrar: 0");
  Skjar.print("         ");
  }
  

}
