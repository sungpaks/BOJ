import java.io.*;
import java.util.*;

public class Main {
	private static final int INF = 100000;
	private boolean isPrimeNumber(int n) {
		if (n <= 1) return false;
		if (n == 2) return true;
		for(int i=2; i*i <= n; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		ArrayList<Integer>PrimeNumbers = new ArrayList<>();
		for(int i=2;i<INF;i++) {
			if (isPrimeNumber(i)) PrimeNumbers.add(i);
		}
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			for(Integer i : PrimeNumbers) {
				int cnt = 0;
				while (n%i == 0) {
					n /= i;
					cnt++;
				}
				if (cnt > 0)
					bw.write(Integer.toString(i) + " " + Integer.toString(cnt) + "\n");
			}
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
//6 + 1 = 6