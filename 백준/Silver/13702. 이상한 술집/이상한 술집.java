import java.io.*;
import java.util.*;

public class Main {
	int[] mak;
	int n, k;
	private long devideMak(long amount) {
		long result = 0;
		for(int i=0;i<n;i++) {
			result += (amount == 0 ? 0 : mak[i]/amount);
		}
		return result;
	}
	private long binSearch(long left, long right) {
		if (right == 0 || left > right) return right;
		long mid = ((long)left + (long)right)/2;
		long d = devideMak(mid);
		if (d >= k) return binSearch(mid+1, right);
		else return binSearch(left, mid-1);
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		mak = new int[n+1];
		for(int i=0;i<n;i++) {
			mak[i] = Integer.parseInt(br.readLine());
		}
		System.out.println(binSearch(0, Integer.MAX_VALUE));

		//bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}