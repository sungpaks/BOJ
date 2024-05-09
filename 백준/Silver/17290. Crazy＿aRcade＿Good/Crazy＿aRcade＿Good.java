import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int y = Integer.parseInt(st.nextToken()) - 1;
		int x = Integer.parseInt(st.nextToken()) - 1;
		boolean[][] arcade = new boolean[10][10];
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				char c = (char)br.read();
				if (c == 'o') {
					for(int k=0;k<10;k++) {
						arcade[i][k]=true;
						arcade[k][j]=true;
					}
				}
			}
			br.read();
		}
		int min = 10000;
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				if (!arcade[i][j]) {
					min = Math.min(Math.abs(i-y)+Math.abs(j-x), min);
				}
			}
		}
		System.out.println(min);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}