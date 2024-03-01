import java.io.*;
import java.util.*;

public class Main {
	private boolean equation(int x, int y, int r) {
		return x+1+y+1 < r;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(br.readLine());

		int t = 0;
		int[][] garden = new int[1001][1001];
		int x = a;
		int y = b;
		while(++t > 0) {
			garden[x][y] = 1;
			if (equation(x, y, r)) {
				x++;
				y++;
			} else {
				x /= 2;
				y /= 2;
			}
			if (garden[x][y] == 1) {
				System.out.println(t);
				return;
			}
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();

	}
}