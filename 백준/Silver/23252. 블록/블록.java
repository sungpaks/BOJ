

import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int a, b, c;
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			boolean result = false;
			if (c > 0) {
				if (a == c) result = true;
				else if (a > c && (a-c) % 2 == 0) result = true;
				else result = false;
			}
			else {
				if (b > 0) {
					if (b % 2 == 0) {
						if (a % 2 == 0) result = true;
					}
					else {
						if (a >= 2 && a % 2 == 0) result = true;
					}
				}
				else {
					if (a % 2 == 0) result = true;
				}
			}
			if (result == true) bw.write("Yes\n");
			else bw.write("No\n");
		}
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}