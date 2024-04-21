import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] a = new int[n];
		for(int i=0;i<n;i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		int[] diff = new int[n];
		for(int i=0;i<n-1;i++) {
			diff[i] = a[i+1] - a[i];
		}
		int[] dp = new int[n];
		dp[0] = 0;
		int max = 0;
		for(int i=1;i<n;i++) {
			dp[i] = Math.max(diff[i-1], dp[i-1] + diff[i-1]);
			max = Math.max(max, dp[i]);
		}
		System.out.println(max);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}