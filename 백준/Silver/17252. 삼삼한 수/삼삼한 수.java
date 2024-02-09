import java.io.*;
import java.util.*;

public class Main {
	boolean result = false;
	int n;
	private void samsam(int cur, int exp) {
		if (exp >= 20 || cur >= n) {
			if (cur == n) result = true;
			return;
		}
		samsam(cur, exp+1);
		samsam(cur+(int)Math.pow(3, exp), exp+1);
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		samsam(0, 0);
		System.out.println(n != 0 && result ? "YES" : "NO");
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();

	}
}