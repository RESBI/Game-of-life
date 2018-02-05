import java.util.Random;

public class goi2d {
    public static void main(String[] args) {       
        System.out.print("\033[99m");
	int H = 30;
	int W = 30;
	int Count = 0;
	int AX, AY, POINT;
	int[][] Gird = new int[H][W];
	int[][] Temp = new int[H][W];
        String Line;
	int i, j, k, l, a, b; //Set values for "for".

	for (a = 0; a < H; a++) {
	    for (b = 0; b < W; b++) {
		Gird[a][b] = new Random().nextInt(2); //Generate random point.
	    }
	}
	while (1 == 1) {
            System.out.print("\033[0;0H");
	    //Generate new map.
	    for (a = 0; a < H; a++) {
		Line = "";
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
		    //Draw to screen.
		    if (Gird[a][b] == 1) {
			Line += "# ";
		    } else {
			Line += "  ";
		    }
		}
		System.out.println(Line);
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
}
