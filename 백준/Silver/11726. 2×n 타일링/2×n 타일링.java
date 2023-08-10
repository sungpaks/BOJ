
import java.io.*;
import java.util.*;

public class Main {
	/*private int getCombination(int n, int r) {
		if (r == 0 || n == r) return 1;
		if (r == 1) return n;
		return getCombination(n-1, r-1) + getCombination(n-1, r);
	}*/
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int [] dp = new int[1001];
		dp[1] = 1;
		dp[2] = 2;
		for(int i=3;i<=n;i++) {
			dp[i] = (dp[i-1] + dp[i-2])%10007;
		}
		bw.write(Integer.toString(dp[n]));
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
/*
ㅣ모양 2개마다
n-1C1 + n-2C2 + n-3C3 + ...
n-iCi?
9인 경우
9C0 + 8C1 + 7C2 + 6C3 + 5C4 = 1 + 8 + 21 + 20 + 5 = 55.
8은
8C0 + 7C1 + 6C2 + 5C3 + 4C4 = 1 + 7 + 15 + 10 + 1 = 34.
7은
7C0 + 6C1 + 5C2 + 4C3  = 	  1 + 6 + 10 + 4 = 21.
6은
6C0 + 5C1 + 4C2 + 3C3 = 	  1 + 5 + 6 + 1 = 13.
5는
5C0 + 4C1 + 3C2 = 			  1 + 4 + 3 = 8.

 */