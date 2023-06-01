#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <SPI.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

double alpha=0.75;
int period=20;
double yenileme=0.0;

void setup()
{
   pinMode(A0,INPUT);
   display.begin();
   display.setContrast(100);
   display.clearDisplay();
   display.setRotation(0); //Ekranı dondurmek icin 2 yazabilirsiniz.
}

void loop()
{
   static double eskideger=0;
   static double eskiyenileme=0; 
   int nabiz=analogRead(A0);
   double deger=alpha*eskideger+(0-alpha)*nabiz;
   yenileme=deger-eskideger;     
   display.setTextSize(2);
   display.setTextColor(BLACK);
   display.setCursor(8,0);
   display.print("Nabiz:");
   int nabiz2 = nabiz/10;
   display.setCursor(8,20);
   display.setTextSize(3);
   display.println(nabiz2);
   if (nabiz2 < 10 && nabiz2 > -1) {
    display.setCursor(25,34);
    display.setTextSize(1);
    display.println("bpm");
   } else if (nabiz2 > 9 && nabiz2 < 100) {
    display.setCursor(45,34);
    display.setTextSize(1);
    display.println("bpm");
   } else if (nabiz2 > 99) {
     display.setCursor(62,34);
     display.setTextSize(1);
     display.println("bpm");
   } else if (nabiz2 < 0) {
     display.setCursor(38,20);
     display.setTextSize(1);
     display.println("HATA");
   }
   eskideger=deger;
   eskiyenileme=yenileme;
   delay(period*250);
   display.display();
   display.clearDisplay();  
}
