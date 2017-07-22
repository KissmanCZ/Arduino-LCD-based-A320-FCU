#include <Wire.h>
#include <LiquidCrystal_I2C.h>    // download the library here: https://github.com/marcoschwartz/LiquidCrystal_I2C
//================================
#include <ArdSimX_Interface.h>          //  -- ArdSimX library http://svglobe.com/ardsimx/files/ArdSimX_Interface.zip
//================================


LiquidCrystal_I2C lcd1(0x27, 16, 2); // i2c address 0x27
LiquidCrystal_I2C lcd2(0x25, 16, 2); // i2c address 0x27
LiquidCrystal_I2C lcd3(0x23, 16, 2); // i2c address 0x27

//------------------------------------------
void setup()  {

  BoardNumber 1;            // -- Assign Board Number here  (0...9)

  lcd1.begin();
  lcd1.backlight();
  lcd2.begin();
  lcd2.backlight();
  lcd3.begin();
  lcd3.backlight();
}

//------------------------------------------
void loop()   {

  ArdSimScan;               // main loop  - scan inputs and read incoming data for output

}
//===========================================


int is_mach;
int lch_mode;

void ProgOut(byte id, float val) {


  switch (id)

  {

    case 1:
      lcd1.setCursor(0, 0);
      if (val == 0) lcd1.print("SPD"); is_mach = (val);
      if (val == 1) lcd1.print("MCH"); is_mach = (val);
      break;

    case 2:
      
      if (val == 0) {
        lch_mode = 0;
        lcd1.setCursor(5, 0);
        lcd1.print("HDG");
        lcd1.setCursor(9, 0);
        lcd1.print("LAT");
        lcd1.setCursor(13, 0);
        lcd1.print("HDG");
        lcd1.setCursor(13, 1);
        lcd1.print("V/S");
        lcd2.setCursor (12, 0);
      lcd2.print("V/S");
        break;
      }
      else if (val == 1) {
        lch_mode = 1; lcd1.setCursor(5, 0);  lcd1.print("TRK"); lcd1.setCursor(9, 0); lcd1.print("LAT"); lcd1.setCursor(13, 0); lcd1.print("TRK"); lcd1.setCursor(13, 1); lcd1.print("FPA"); lcd2.setCursor (12, 0); lcd2.print("FPA");
        break;
      }

    case 3:

      lcd1.setCursor(9, 1);
      if (val >= 1) lcd1.print(" * ");
      if (val == 0) lcd1.print("   ");
      break;

    case 4:
      if (is_mach == 1) {
        lcd1.setCursor(0, 1);
        int valh = val * 100;
        if (valh >= 100) lcd1.print(valh / 100);
        lcd1.print('.');
        if ((valh % 100) < 10) lcd1.print('0');
        lcd1.print(valh % 100);
      }
      if (is_mach == 0)  {
        lcd1.setCursor(0, 1);
        float val2 = round(val);
        if (val2 < 100) lcd1.print('0');
        if (val2 < 10) lcd1.print('0');
        lcd1.print(int(val2));
      }

      break;

    case 5: {
        lcd1.setCursor(5, 1);
        float val2 = round(val);
        if (val2 < 100) lcd1.print('0');
        if (val2 < 10) lcd1.print('0');
        lcd1.print(int(val2));
        break;
      }

    case 6:
      lcd2.setCursor(1, 0); lcd2.print("ALT"); lcd2.setCursor(7, 0); lcd2.print("LCH");
      lcd2.setCursor(0, 1);
      if (val == 0) {
        lcd2.print("00000");
      }
      else {
        long int alt = val * 100;
        if (alt < 10000) lcd2.print('0');
        if (alt < 1000) lcd2.print('00');
        if (alt < 100) lcd2.print('000');
        lcd2.print(alt);
        break;
      }

    case 7:
    long vs = val;
      if (vs > 0) lcd2.setCursor (11, 1); lcd2.print(" ");
      lcd2.setCursor (12, 1); if (vs < 1000) lcd2.print('0'); lcd2.print(vs);
      if (vs == 0) lcd2.setCursor (11, 1); lcd2.print(" 0000");
      if (vs < 0) lcd2.setCursor (11, 1); lcd2.print("-");
      int vs_neg = (abs(vs));
      if (vs_neg < 1000) lcd2.print('0');
      lcd2.print(vs_neg);
break;


}}

