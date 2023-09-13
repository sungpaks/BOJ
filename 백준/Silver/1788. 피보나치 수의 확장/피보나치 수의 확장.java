
import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int million = 1_000_000;
		long [] dp = new long[2_000_004];
		dp[million] = 0; dp[million+1] = 1;
		for(int i=million+2;i<=million*2;i++) {
			dp[i] = dp[i-1] + dp[i-2];
			dp[i] = dp[i] % (million * 1000);
		}
		for(int i=million-1;i>=0;i--) {
			dp[i] = dp[i+2] - dp[i+1];
			dp[i] = dp[i] % (million * 1000);
		}
		if (dp[million+n] < 0) bw.write("-1\n");
		else if (dp[million+n] > 0) bw.write("1\n");
		else bw.write("0\n");
		bw.write(Long.toString(Math.abs(dp[million+n])));
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}