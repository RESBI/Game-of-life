import java.util.Random;

public class goi2d {
    public static void main(String[] args) {       
        System.out.print("\033[99m");
	int H = 40;
	int W = 40;
	int Count = 0;
	int AX, AY, POINT;
	int[][] Gird = new int[H][W];
	int[][] Temp = new int[H][W];
  
	int i, j, k, l, a, b; //Set values for "for".

	for (a = 0; a < H; a++) {
	    for (b = 0; b < W; b++) {
		Gird[a][b] = new Random().nextInt(2); //Generate random point.
	    }
	}
	/*
	  Frame Window = new Frame();
	  Window.setLocation(200, 100);
	  Window.setSize(W, H);
	  Window.setTitle("Game of life!");
	  Window.setVisible(true);
	*/
	while (1 == 1) {
            System.out.print("\033[0;0H");
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
		    if ((POINT == 1) && (Count < 2 || Count > 3)) {
			Temp[a][b] = 0;
		    } else if ((POINT == 0) && (Count == 3)){
			Temp[a][b] = 1;
		    } else {
			Temp[a][b] = POINT;
		    }
		}
	    }
	    //Flush the map then draw to screen and empty the temp.
	    for (a = 0; a < H; a++) {
		for (b = 0; b < W; b++) {
		    Gird[a][b] = Temp[a][b];
		    Temp[a][b] = 0;
		    if (Gird[a][b] == 1) {
			System.out.print("# ");
		    } else {
			System.out.print("  ");
		    }
		}
		System.out.print("\n");
	    }
	}
    }
}
