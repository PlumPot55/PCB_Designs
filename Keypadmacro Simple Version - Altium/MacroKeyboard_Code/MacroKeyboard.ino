/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/

///Libraries for the sceen/////

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306_STM32.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


////////


#include <Keypad.h>
#include <USBComposite.h>

USBHID HID;
HIDKeyboard Keyboard(HID);
const byte ROWS = 3; //four rows
const byte COLS = 3; //four columns
int mode = 1;
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
byte rowPins[ROWS] = {PB0, PB1, PB2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {PA4,PA5,PA6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
//Set up the displau///
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

 display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();


///Set up the keyboard///////  
  Serial.begin(9600);
  HID.begin(HID_KEYBOARD);
  while (!USBComposite);
  Keyboard.begin(); // useful to detect host capslock state and LEDs
}
  
void loop(){

   char customKey = customKeypad.getKey();
   if (customKey == '7'){
  mode = mode + 1;
 
  }

  if (mode > 4)
  {
    mode = 1;
  }


  switch (mode) {
 
  ////////Altium Schematic Mode/////////////
  case 1:
  
  display.clearDisplay();
    // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Altium SCH");
 display.display();
 
    //Place Net Label///
    if (customKey == '1'){
  Keyboard.press('p');  
  Keyboard.press('n');  
  Keyboard.releaseAll();
  }
    //Place Wire///
  if (customKey == '2'){
  Keyboard.press('p');  
  Keyboard.press('w');  
  Keyboard.releaseAll();
  }
    //Place Part///
    if (customKey == '3'){
  Keyboard.press('p');  
  Keyboard.releaseAll();
  Keyboard.press('p');  
  Keyboard.releaseAll();
  }
//Escape///
     if (customKey == '6'){
  Keyboard.press(KEY_ESC);  
  Keyboard.releaseAll();
  }
//Update to the PCB///
  if (customKey == '5'){
  Keyboard.press('d');  
  Keyboard.press('u');  
  Keyboard.releaseAll();
  }
//Place Power//
 if (customKey == '4'){
  Keyboard.press('p');  
  Keyboard.press('o');  
  Keyboard.releaseAll();
  }

//Place Port//
   if (customKey == '8'){
  Keyboard.press('p');  
  Keyboard.press('r');  
  Keyboard.releaseAll();
  }
//Rotate Part///
    if (customKey == '9'){
 Keyboard.write(0x20);
  Keyboard.releaseAll();
  }
    break;
  case 2:

  display.clearDisplay();
    // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Altium PCB");
 display.display();
  //Place Text///
     if (customKey == '1'){
  Keyboard.press('p');  
  Keyboard.press('s');  
  Keyboard.releaseAll();
  }

  if (customKey == '2'){
  Keyboard.press('p');  
  Keyboard.press('t');  
  Keyboard.releaseAll();
  }
    if (customKey == '3'){
  Keyboard.press('+');  
  Keyboard.releaseAll();
  }

     if (customKey == '6'){
  Keyboard.press(KEY_ESC);  
  Keyboard.releaseAll();
  }
    break;

    case 3:
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("KiCad SCH");
 display.display();
  //Place Net Label////
  if (customKey == '1'){
  Keyboard.press('l');  
  Keyboard.releaseAll();
  }
//Place Wire////
  if (customKey == '2'){ 
  Keyboard.press('w');  
  Keyboard.releaseAll();
  
  }
  //Place Component////
    if (customKey == '3'){
  Keyboard.press('a');  
  Keyboard.releaseAll();
  }
//Escape////
     if (customKey == '6'){
  Keyboard.press(KEY_ESC);  
  Keyboard.releaseAll();
  }
//update PCB////
  if (customKey == '5'){
  Keyboard.press(KEY_F8);  
  Keyboard.releaseAll();
  }
//Place Power////
 if (customKey == '4'){
  Keyboard.press('p');   
  Keyboard.releaseAll();
  }
//Place Port////
   if (customKey == '8'){
  Keyboard.press(KEY_LEFT_CTRL); 
   delay(200);
    Keyboard.press('h'); 
  Keyboard.releaseAll();
  }
    if (customKey == '9'){
 Keyboard.write('r');
  Keyboard.releaseAll();
  }

    break;
//KiCad Buttons///
    case 4:
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("KiCad PCB");
 display.display();

  //Place Net Label////
  if (customKey == '1'){
  Keyboard.press('l');  
  Keyboard.releaseAll();
  }
//Place Wire////
  if (customKey == '2'){ 
  Keyboard.press('w');  
  Keyboard.releaseAll();
  
  }
  //Place Component////
    if (customKey == '3'){
  Keyboard.press('a');  
  Keyboard.releaseAll();
  }
//Escape////
     if (customKey == '6'){
  Keyboard.press(KEY_ESC);  
  Keyboard.releaseAll();
  }
//update PCB////
  if (customKey == '5'){
  Keyboard.press(KEY_F8);  
  Keyboard.releaseAll();
  }
//Place Power////
 if (customKey == '4'){
  Keyboard.press('p');   
  Keyboard.releaseAll();
  }
//Place Port////
   if (customKey == '8'){
  Keyboard.press(KEY_LEFT_CTRL); 
   delay(200);
    Keyboard.press('h'); 
  Keyboard.releaseAll();
  }
    if (customKey == '9'){
 Keyboard.write('r');
  Keyboard.releaseAll();
  }

    break;
    
  default:
    // statements
    break;
}
 
  
  

  
}
