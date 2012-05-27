
#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char HS[] = "Hackerspace Lausanne : https://fixme.ch";
char PAD[16] = "               ";

void setup(){
  lcd.begin(8, 2);
  //lcd.write(HS);
}

void loop()
{
  show(HS);
  //delay(500);
  //lcd.scrollDisplayLeft();
}

void show(char* txt_orig){
  int len = strlen(txt_orig);
  char txt[len+16];
  strncpy(txt, PAD, 16);
  strncat(txt, txt_orig, len);
  len += 16;
  if(len>8){
    for (int j=0; j<len; j++) {
      lcd.setCursor(0, 0);
      for (int i=0+j; i<8+j; i++){
        if(i<len-1){
          lcd.write(txt[i]);
        } 
        else {
          lcd.write(" ");
        }
      }
      lcd.setCursor(0, 1);
      for (int i=8+j; i<16+j; i++){
        if(i<len-1){
          lcd.write(txt[i]);
        } 
        else {
          lcd.write(" ");
        }
      }
      delay(250);
    }
  }
  else {
    lcd.setCursor(0, 0);
    lcd.write(txt);
  }
}



