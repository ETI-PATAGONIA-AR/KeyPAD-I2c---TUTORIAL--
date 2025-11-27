//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//Ejemplo: tECLADO 4X4 I2c con PCF8574 - prof.martintorres@educ.ar - ETI Patagonia
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const byte ROWS = 4;
const byte COLS = 4;
 
char keys[ROWS][COLS] = {
{'D','#','0','*'},
{'C','3','2','1'},
{'B','6','5','4'},
{'A','9','8','7'}
};


 
byte rowPins[ROWS] = {0,1,2,3};
byte colPins[COLS] = {4,5,6,7};
 
int i2caddress = 0x20; // set direccion I2c del teclado 4x4
 
Keypad_I2C kpd = Keypad_I2C( makeKeymap(keys), rowPins, colPins, ROWS, COLS, i2caddress );
LiquidCrystal_I2C lcd(0x27,20,4);  // set direccion I2c del display LCD
 
void setup(){
  Serial.begin(9600); // Inicializamos la comunicacion serial
  lcd.init();     // Inicializamos el display LCD I2c
  lcd.backlight();
  lcd.setCursor(0,0);
  // Imprimimos mensaje de INICIO en display LCD I2c
  lcd.print(" TECLADO  I2c  v1.1 ");
  lcd.setCursor(0,1);
  lcd.print("                    ");
  lcd.setCursor(0,2);
  lcd.print(" Desarrollado por:  ");
  lcd.setCursor(0,3);
  lcd.print(" - ETI  Patagonia - ");
   delay(1500);
  lcd.clear();
  kpd.begin(); // Inicializamos el teclado I2c
 
}
 
void loop()
 {
   lcd.setCursor(0,0);
  lcd.print("  KEYPAD i2C  V1.1  ");
  lcd.setCursor(0,1);
  lcd.print("--------------------");
  lcd.setCursor(0,2);
  lcd.print("Tecla:");
  char key = kpd.getKey();  //"kpd.getKey" es el subprograma que se encarga de leer el teclado.Cuando hay una lectura,lo guarda en la variable key que es del tipo "char"(caracter)
  if (key)                  // si hay una tecla presionada, entonces...
     {
       // Imprimir los datos en el display LCD I2c
       lcd.setCursor(0,3);
       lcd.print(key);     //imprimimos el caracter de la tecla presionada
       Serial.println(key);
     // delay(1500);
     //lcd.clear();
     }
}