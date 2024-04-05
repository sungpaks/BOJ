import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		HashMap<String, Integer>poketmon = new HashMap<>();
		int total = 0;
		int max = 0;
		String maxPoketmon = "";
		for(int i=0;i<n;i++) {
			String name;
			int k, m;
			name = br.readLine();
			StringTokenizer st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			int cnt = 0;
			while(m >= k) {
				m = m - k + 2;
				cnt++;
			}
			poketmon.put(name, cnt);
			total += cnt;
			if (cnt > max) {
				max = cnt;
				maxPoketmon = name;
			}
		}
		System.out.println(total);
		System.out.println(maxPoketmon);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}