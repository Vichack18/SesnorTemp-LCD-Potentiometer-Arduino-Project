#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

const int rs=12, e=11, d4=5, d5=4, d6=3, d7=2;

OneWire ourWire(9);
DallasTemperature sensors(&ourWire);
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);


void setup() {
  // put your setup code here, to run once:
    lcd.begin(16, 2);
    sensors.begin(); // no require de parametros para inicializarlo //

}

void loop() {
  // put your main code here, to run repeatedly:
    sensors.requestTemperatures();
    float temp=sensors.getTempCByIndex(0);
    lcd.setCursor(0,0);
    lcd.print("Temperatura: ");
    lcd.setCursor(0,1);
    lcd.print(temp);
    lcd.setCursor(6,1);
    lcd.print("C"); // para indicar que son grados centigrados //
    dalay (1000);
}
