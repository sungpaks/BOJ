import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] A = new int[n];
		for(int i=0;i<n;i++) {
			A[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(A);
		int right = 0;
		int left = 0;
		int min = Integer.MAX_VALUE;
		while(true) {
			if (A[right]-A[left] >= m) min = Math.min(A[right]-A[left], min);
			if (A[right]-A[left] < m) {
				if (right+1 < n) right++;
			}
			else if (A[right]-A[left] > m) {
				if (left < right && A[right]-A[left+1] >= m) left++;
				else if (right+1 < n) right++;
				else break;
			}
			else break;
		}
		System.out.println(min);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
// 1 2 100 102 105