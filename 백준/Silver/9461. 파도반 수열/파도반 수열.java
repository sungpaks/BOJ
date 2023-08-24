

import java.io.*;
import java.net.Inet4Address;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		long [] dp = new long[101];
		dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
		dp[6] = 3; dp[7] = 4; dp[8] = 5; dp[9] = 7;
		for(int i = 10;i<=100;i++) dp[i] = dp[i-1] + dp[i-5];
		for(int i=0;i<t;i++) {
			int cur = Integer.parseInt(br.readLine());
			bw.write(Long.toString(dp[cur]) + "\n");
		}
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}