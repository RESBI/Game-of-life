#include <time.h>
#include <SSD1306ASCII.h>

// OLED
#define OLED_DATA 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RST 13
SSD1306ASCII oled(OLED_DATA, OLED_CLK, OLED_DC, OLED_RST, OLED_CS);

void setup(){
  oled.ssd1306_init(SSD1306_SWITCHCAPVCC);
  pinMode(A0, INPUT);
}

void loop(){
  int H = 8;
  int W = 21;
  int Count = 0;
  int AX, AY, POINT;
  int Gird[H][W];
  int Temp[H][W];
  int i, j, k, l, a, b; //Set values for "for".
  
  srand(time(NULL));
  for (a = 0; a < H; a++) {
    for (b = 0; b < W; b++) {
      Gird[a][b] = analogRead(A0) % 2; //Generate random point.
    }
  }
  while (1) {
    //delay(200);
    //Generate new map.
    for (a = 0; a < H; a++) {
      for (b = 0; b < W; b++) {
  POINT = Gird[a][b];
  //Get neighbour.
  Count = - POINT;
  for (i = -1; i < 2; i++) {
    AY = (a + i + H) % H;
    for (j = -1; j < 2; j ++) {
      AX = (b + j + W) % W;
      Count += Gird[AY][AX];
    }
  }
  //Get new point.
  if (POINT && (Count < 2 || Count > 3)) {
    Temp[a][b] = 0;
  } else if (!POINT && Count == 3){
    Temp[a][b] = 1;
  } else {
    Temp[a][b] = POINT;
  }
  //Draw to screen.
  if (Gird[a][b]) {
        oled.print("@");
        } else {
        oled.print(" ");
  } 
      }
    oled.setCursor(0, a);
    }
    //Flush the map and empty the temp.
    for (a = 0; a < H; a++) {
      for (b = 0; b < W; b++) {
  Gird[a][b] = Temp[a][b];
  Temp[a][b] = 0;
      }
    }
  }
}
