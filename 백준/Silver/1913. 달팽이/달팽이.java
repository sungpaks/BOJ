
import java.io.*;
import java.math.BigInteger;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	int[][] snailArray;
	int[] di = {0, -1, 0, 1};
	int[] dj = {-1, 0, 1, 0};
	private void snail(int n, int i, int j, int k, int cur) {
		if (cur > n*n) return;
		snailArray[i][j] = cur;
		if (snailArray[i+di[(k+1)%4]][j+dj[(k+1)%4]] == 0) k = (k+1)%4;
		i += di[k];
		j += dj[k];
		snail(n, i, j, k, cur+1);
	}
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = in.nextInt();
		int m = in.nextInt();
		snailArray = new int[n][n];
		snail(n, n/2, n/2, 0, 1);
		int mi = 0, mj = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if (snailArray[i][j] == m) {
					mi = i+1;
					mj = j+1;
				}
				bw.write(Integer.toString(snailArray[i][j]) + " ");
			}
			bw.write("\n");
		}
		bw.write(Integer.toString(mi) + " " + Integer.toString(mj));
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}