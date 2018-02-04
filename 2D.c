#include <stdio.h>

void main(){
  printf("\033[99m"); //Set color.
  int H = 150;
  int W = 300;
  int Count = 0;
  int AX;
  int AY;
  int POINT;
  int Gird[H][W];
  int Temp[H][W];
  for(int a = 0; a < H; a++){
    for(int b = 0; b < W; b++){
      Gird[a][b] = 0;
      Temp[a][b] = 0;
    }
  }
  for(int k = 3; k < W; k=k+6){  //Generate many flight.
    for(int l = 2; l < H; l=l+5){
      Gird[l][k] = 1;
      Gird[l][k+1] = 1;
      Gird[l][k+2] = 1;
      Gird[l+1][k] = 1;
      Gird[l+2][k+1] = 1;
    }
  }
  while(1){
    printf("\x1b[0;0H");
    //Draw
    for(int a = 0; a < H; a++){
      for(int b = 0; b < W; b++){
	if(Gird[a][b] == 1){
	  printf("# ");
        }else{
	  printf("  ");
	}
      }
      printf("\n");
    }    
    //Generate new map.
    for(int a = 0; a < H; a++){
      for(int b = 0; b < W; b++){
	//Get neighbour.
	Count = 0;
	for(int i = -1; i < 2; i++){
	  for(int j = -1; j < 2; j ++){
	    AX = (b + j + W) % W;
	    AY = (a + i + H) % H;
	    Count = Count + Gird[AY][AX];
	  }
	}
	Count = Count - Gird[a][b];
	//Get new point.
	POINT = Gird[a][b];
	if(POINT == 1 && (Count < 2 || Count > 3)){
	  Temp[a][b] = 0;
	}else if(POINT == 0 && Count == 3){
	  Temp[a][b] = 1;
	}else{
	  Temp[a][b] = POINT;
	}
      }
    }
    //Flush the map and empty the temp.
    for(int a = 0; a < H; a++){
      for(int b = 0; b < W; b++){
	Gird[a][b] = Temp[a][b];
	Temp[a][b] = 0;
      }
    } 
  }
}
