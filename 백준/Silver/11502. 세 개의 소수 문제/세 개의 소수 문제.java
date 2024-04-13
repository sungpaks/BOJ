import java.io.*;
import java.util.*;

public class Main {
	private boolean check(int n, ArrayList<Integer> prime) {
		for(int i : prime) {
			for(int j : prime) {
				for (int k : prime) {
					if (i+j+k == n) {
						System.out.println(i + " " + j + " " + k);
						return true;
					}
				}
			}
		}
		return false;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		ArrayList<Integer>prime = new ArrayList<>();
		for(int i=2;i<=1000;i++) {
			boolean isPrime = true;
			for(int j=0;j<prime.size();j++) {
				if (i % prime.get(j) == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) prime.add(i);
		}
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			if (!check(n, prime)) System.out.println(0);
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}