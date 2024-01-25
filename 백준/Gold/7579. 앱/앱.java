import java.io.*;
import java.util.*;

public class Main {
	final static int INF = 1000000000;
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] memory = new int[n];
		int[] cost = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			memory[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			cost[i] = Integer.parseInt(st.nextToken());
		}

		//0-1배낭인 듯
		long[][] dp = new long[n][n*100 + 1];
		//[i][j] : i번째 앱에 대해.. j는 비활성화 cost
		//100개 전부 확인한, 비활성화비용(j)에 따른 최대 memory를 dp에 저장
		int result = 100*m;
		for(int j=cost[0];j<=n*100;j++) {
			dp[0][j] = memory[0];
			if (m <= dp[0][j] && result > j) result = j;
		}
		for(int i=1;i<n;i++) {
			for(int j=0;j<=n*100;j++) {
				dp[i][j] = dp[i-1][j];
				if (j >= cost[i] && dp[i][j] < dp[i-1][j-cost[i]] + memory[i]) dp[i][j] = dp[i-1][j-cost[i]] + memory[i];
				if (m <= dp[i][j] && result > j) result = j;
			}
		}
		System.out.println(result);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
// 2,147,483,647
// 1,000,000,000