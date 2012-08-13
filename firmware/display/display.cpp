#ifndef DISPLAY_H
#define DISPLAY_H

#include "oled.h"
#include "nfont.h"
#include "display.h"
#include "utils.h"

extern uint8_t _binary_image_1_data_start;
extern uint8_t _binary_image_1_data_size;

void display_initialise() {
  oled_platform_init();
  oled_init();
}

void display_clear() {
  CLS();
}

void display_draw_line(int start_x,int start_y,int end_x,int end_y,uint16_t color=65535) {
  Set_Column_Address(start_x, end_x+1);
  Set_Row_Address   (start_y, end_y+1);
  write_c(0x5c);
  for(uint32_t n=0;n<((end_x-start_x)*(end_y*start_y));n++) write_d(color);
}
  
void display_draw_point(int x,int y,uint16_t color=65535) {
  Set_Column_Address(x, x+1);
  Set_Row_Address(y, y+1);
  write_c(0x5c);
  write_d(color);
  write_d(color);
}

void display_draw_rectangle(int start_x,int start_y,int end_x,int end_y,uint16_t color) {
  Set_Column_Address(start_x, end_x);
  Set_Row_Address   (start_y, end_y);

  uint32_t size = (end_x-start_x)*(end_y-start_y+1);
   
  write_c(0x5C);    // Enable MCU to Read from RAM
  for (uint32_t i=1; i<=size;i++) {
    write_d(color);
    write_d(color >> 8);
  } 
}

void display_draw_text(int x,int y,char *text,int16_t background) {
  ::draw_text(x,y,text,background);
}


void display_draw_number(int x,int y,uint32_t number,int width,int16_t background) {
  char text[50];
  int_to_char(number,text,width);
  draw_text(x,y,text,background);
}

void display_dump_image() {
  oled_draw_rect(0,0,128,127,((uint8_t *) &_binary_image_1_data_start)+1);
}

void display_powerup() {
  oled_init();
}

void display_powerdown() {
  oled_deinit();
}

#endif