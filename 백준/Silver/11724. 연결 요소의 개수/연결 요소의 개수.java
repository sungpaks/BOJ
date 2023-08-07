
import java.io.*;
import java.util.*;

public class Main {
	private static boolean [] visited;
	private static List<Integer>[] graph;
	private void dfs(int current) {
		if (visited[current]) return;
		visited[current] = true;
		for(int i=0;i<graph[current].size();i++) {
			dfs(graph[current].get(i));
		}
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		visited = new boolean[n+1];
		graph = new ArrayList[n+1];
		for(int i=1;i<=n;i++) graph[i] = new ArrayList<Integer>();
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			graph[u].add(v);
			graph[v].add(u);
		}
		int cnt = 0;
		if (m == 0) cnt++;
		else {
			for(int i=1;i<=n;i++) {
				if (!visited[i]) {
					dfs(i);
					cnt++;
				}
			}
		}
		bw.write(Integer.toString(cnt));
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}