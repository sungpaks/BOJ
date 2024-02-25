import java.io.*;
import java.util.*;

public class Main {
	private void checkCycle(int[] arr, boolean[] visited, int i) {
		int j = i;
		visited[i] = true;
		while(arr[j] != i) {
			j = arr[j];
			visited[j] = true;
		}
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());

		while(t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			int[] arr = new int[n+1];
			boolean[] visited = new boolean[n+1];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=1;i<=n;i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			int result=0;
			for(int i=1;i<=n;i++) {
				if(!visited[i]) {
					checkCycle(arr, visited, i);
					result++;
				}
			}
			bw.write(Integer.toString(result) + "\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();

	}
}