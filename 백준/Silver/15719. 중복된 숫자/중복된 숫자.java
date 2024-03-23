import java.io.*;
import java.util.*;

public class Main {
	private int nameToIndex(String name) {
		if (name.equals("kor") || name.equals("apple") || name.equals("red")) return 0;
		else if (name.equals("eng") || name.equals("pear") || name.equals("blue")) return 1;
		else return 2;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		int[] numbers = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int cur = Integer.parseInt(st.nextToken());
			if (numbers[cur] != 0) {
				System.out.println(cur);
				return;
			}
			numbers[cur] = 1;
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}