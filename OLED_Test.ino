#include "U8glib.h"
/*
OLED    ARDUINO

GND      GND
VCC       5v
SCL       SCK (15 on Leonardo/Micro )
SDA       MOSI (16 on Leonardo/Micro)
RES        6
DC         7
CS         10 (SS)
*/

int check = 1;
//OLED SSD1309 128x64 constructor
//U8GLIB_SSD1309_128X64 u8g( SCK, MOSI, SS, DC, RES );
U8GLIB_SSD1309_128X64 u8g( 15, 16, 10, 7, 6 );

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  //u8g.setFont(u8g_font_unifont);
  u8g.setFont(u8g_font_5x8);
  //u8g.setFont(u8g_font_helvR10); 
  u8g.drawStr( 0, 10, "RPM: 900");
  u8g.drawStr( 0, 22, "Oil: 87 C");
  u8g.drawStr( 0, 34, "Coolant: 94 C");
}

void setup(void) {
  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  
  pinMode(8, OUTPUT);
}

void loop(void) {
  // picture loop
 
  u8g.firstPage();
   draw();  
  do {
    draw();
  } while( u8g.nextPage() );
 //} while( check == 1 );
  
  Serial.println("OKAY");
  
  // rebuild the picture after some delay
  delay(1000);
}
