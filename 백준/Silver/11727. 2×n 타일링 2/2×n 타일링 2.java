
import java.io.*;
import java.net.Inet4Address;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int [] dp = new int[1001];
		dp[1] = 1;
		dp[2] = 3;
		for(int i=3;i<=1000;i++) {
			dp[i] = (dp[i-2]*2 + dp[i-1])%10007;
		}
		bw.write(Integer.toString(dp[n]));
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
/*
n=1 -> 1
n=2 -> 3
n=3 -> 3*2 - 1 = 2*2 + 1 = 5.
n=4 -> 3*3-1 + 2 = 10/ 6 + 1 + 4 = 11?
n=5 -> 10 + 11 = 21?
n=6 -> 22 + 21 = 43?
n=7 -> 42 + 43 = 85?
n=8 -> 86 + 85 = 171.... shit
dp[n-2]*2 + dp[n-1]임
 */