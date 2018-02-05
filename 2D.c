#include <stdio.h>
#include <time.h>

void main(){
  system("clear");
  printf("\033[99m"); //Set color.
  int H = 30;
  int W = 30;
  int Count = 0;
  int AX, AY, POINT;
  int Gird[H][W];
  int Temp[H][W];
  int i, j, k, l, a, b; //Set values for "for".
  
  srand(time(NULL));
  for (a = 0; a < H; a++) {
    for (b = 0; b < W; b++) {
      Gird[a][b] = rand() % 2; //Generate random point.
    }
  }
  /*
  for(int k = 3; k < W; k=k+6){  //Generate many flight.
    for(int l = 2; l < H; l=l+5){
      Gird[l][k] = 1;
      Gird[l][k+1] = 1;
      Gird[l][k+2] = 1;
      Gird[l+1][k] = 1;
      Gird[l+2][k+1] = 1;
    }
  }
  */
  while (1) {
    printf("\x1b[0;0H");
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
	  printf("# ");
        } else {
	  printf("  ");
	}
      }
      printf("\n");
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
