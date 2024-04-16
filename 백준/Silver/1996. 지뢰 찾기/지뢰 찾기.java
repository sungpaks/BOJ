import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		char[][] map = new char[n+1][n+1];
		int[] di = {0,1,1,1,0,-1,-1,-1};
		int[] dj = {1,1,0,-1,-1,-1,0,1};
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				map[i][j] = (char)br.read();
			}
			br.read();
		}
		int[][] result = new int[n+1][n+1];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if (map[i][j] != '.') {
					int z = map[i][j]-'0';
					for(int k = 0; k < 8;k++) {
						int ni = i + di[k];
						int nj = j + dj[k];
						if (0 <= ni && ni < n && 0 <= nj && nj < n) {
							result[ni][nj] += z;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				int cur = result[i][j];
				if (map[i][j] != '.') bw.write("*");
				else if (cur >= 10) bw.write("M");
				else bw.write(Integer.toString(cur));
			}
			bw.write("\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}