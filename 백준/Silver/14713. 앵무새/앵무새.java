import java.io.*;
import java.util.*;

public class Main {

	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		Queue<String>[]q = new Queue[n];
		for(int i=0;i<n;i++) {
			q[i] = new LinkedList<>();
			st = new StringTokenizer(br.readLine());
			while(st.hasMoreTokens()) {
				q[i].add(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		boolean isPossible;
		while(st.hasMoreTokens()) {
			String current = st.nextToken();
			isPossible = false;
			for(int i=0;i<n;i++) {
				if (current.equals(q[i].peek())) {
					isPossible = true;
					q[i].poll();
					break;
				}
			}
			if (!isPossible) {
				System.out.println("Impossible");
				return;
			}
		}
		isPossible = true;
		for(int i=0;i<n;i++) {
			if (!q[i].isEmpty()) {
				isPossible = false;
				break;
			}
		}
		if (isPossible) System.out.println("Possible");
		else System.out.println("Impossible");
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
