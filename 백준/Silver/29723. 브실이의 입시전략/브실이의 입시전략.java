import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		HashMap<String, Integer>scores = new HashMap<>();
		String[] names = new String[n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			int score = Integer.parseInt(st.nextToken());
			scores.put(name, score);
			names[i] = name;
		}
		Arrays.sort(names, (o1, o2)->{
			return scores.get(o2) - scores.get(o1);
		});
		int sum = 0;
		for(int i=0;i<k;i++) {
			String name = br.readLine();
			sum += scores.get(name);
			scores.remove(name);
		}
		int minSum = sum;
		int maxSum = sum;
		int cnt = m - k;
		for(int i=0;i<cnt;i++) {
			try {
				maxSum += scores.get(names[i]);
			} catch(Exception e) {
				cnt++;
			}
		}
		cnt = m - k;
		for(int i=0;i<cnt;i++) {
			try {
				minSum += scores.get(names[n-i-1]);
			} catch(Exception e) {
				cnt++;
			}
		}
		System.out.println(minSum + " " + maxSum);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}