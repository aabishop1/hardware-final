#include <Arduino.h>
#include <U8g2lib.h> // U8g2 for text plus graphics

U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled{U8G2_R0};

const int box_width{4};
const int number_of_boxes = 128 / box_width;
const int box_max_height{64};

//each value in this array will dictate the pixel height of a box.
int display_array[number_of_boxes];

void setup(void) {

 oled.begin();
 oled.setFont(u8g2_font_ncenB08_tr);
 //draw box uses the x and y as the top left corner of the box and draws it from there.
 oled.drawBox(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h)

}

void fillArray(){

   for(int i = 0; i < number_of_boxes; i++) {

      display_array[i] = random(5, box_max_height);

   }

}


void drawArray() {

   oled.clearBuffer();

   for (int i = 0; i < number_of_boxes(); i++) {

      //top left corner:  x             y              w              h
      oled.drawBox(i * box_width, display_array[i], box_width, display_array[i])

   }

   oled.sendBuffer();

}

//functions should be on a seperate page to reduce clutter, then we can pass a pointer to the array.

void insertionSort() {

   for (int step = 1; step < number_of_boxes; step++) {
      int key = display_array[step];
      int j = step - 1;


      while (key < display_array[j] && j >= 0) {
         display_array[j + 1] = display_array[j];
         --j;
      }
      drawArray();

      display_array[j + 1] = key;
      delay(10);
  }

  //array sorted.

}



void loop(void) {

}


 





