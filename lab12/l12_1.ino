#include <Charliplexing.h>  // LoLShield library
void setup(void) {
  LedSign::Init(0);  // initialize the library
}
void loop(void) {
  for (int y = 0; y < 9; ++y) {
    for (int x = 0; x < 14; ++x) {
      // turn on LED at (x,y) full brightness
      LedSign::Set(x, y, 7);
      delay(50);  // 20 ms
      // turn off LED at (x,y)
      LedSign::Set(x, y, 0);
    }
  }
}
