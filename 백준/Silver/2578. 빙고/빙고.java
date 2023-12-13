
import java.io.IOException;
import java.util.*;

public class Main {
	public int isBingo(int[][] cheolsu) {
		int cnt = 0;
		
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if (cheolsu[i][j] != 0) break;
				if (j == 4) cnt++;
			}
			for(int j=0;j<5;j++) {
				if (cheolsu[j][i] != 0) break;
				if (j == 4) cnt++;
			}
		}
		for(int i=0;i<5;i++) {
			if (cheolsu[i][i] != 0) break;
			if (i==4) cnt++;
		}
		for(int i=0;i<5;i++) {
			if (cheolsu[i][4-i] != 0) break;
			if (i==4) cnt++;
		}
		
		return cnt;
	}
	public void solve() throws IOException{
		Scanner in = new Scanner(System.in);
		int[][] cheolsu = new int[5][5];
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				cheolsu[i][j] = in.nextInt();
			}
		}
		for(int k=0;k<25;k++) {
			int n = in.nextInt();
			for(int i=0;i<5;i++) {
				for(int j=0;j<5;j++) {
					if (n == cheolsu[i][j]) {
						cheolsu[i][j] = 0;
						if (isBingo(cheolsu) >= 3) {
							System.out.println(k+1);
							return;
						}
						break;
					}
				}
			}
		}
	}

	public static void main(String[] args) throws IOException{
		new Main().solve();
	}

}
