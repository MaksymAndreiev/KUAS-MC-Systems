#include <Charliplexing.h>  // LoLShield library
void setup(void) {
  LedSign::Init(0);  // initialize the library
}
void loop(void) {
  int y = 0;
  int x = 0;
  int dy = -1;
  int dx = -1;
  while (y < 9) {
    while (x < 14) {
      LedSign::Set(x, y, 7);
      delay(50);  // 20 ms
      // turn off LED at (x,y)
      LedSign::Set(x, y, 0);
      if(y == 0| y == 8){
        dy *= -1;
      }
      if(x == 0| x == 13){
        dx *= -1;
      }
      y += dy;
      x += dx;
    }
  }
  // for (int y = 0; y < 9; ++y) {
  //   for (int x = 0; x < 14; ++x) {
  //     if (x == 8 & y == 8) {
  //     }
  //     // turn on LED at (x,y) full brightness
  //     LedSign::Set(x, y, 7);
  //     delay(50);  // 20 ms
  //     // turn off LED at (x,y)
  //     LedSign::Set(x, y, 0);
  //   }
  // }
}
