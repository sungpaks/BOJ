
import java.io.IOException;
import java.util.*;

public class Main {
	public boolean[][] place = new boolean[501][501];
	public void solve() throws IOException{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int i=0;i<n;i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();
			for(int y = y1; y<y2;y++) {
				for(int x = x1; x<x2; x++) {
					place[y][x] = true;
				}
			}
		}
		int result = 0;
		for(int i=0;i<500;i++) {
			for(int j=0;j<500;j++) {
				if (place[i][j]) result++;
			}
		}
		System.out.println(result);
	}

	public static void main(String[] args) throws IOException{
		new Main().solve();
	}

}
