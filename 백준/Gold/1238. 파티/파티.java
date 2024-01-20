import java.io.*;
import java.util.*;

public class Main {
	public static final int INF = 10000000;
	private class Pair implements Comparable<Pair> {
		int to, weight;
		public Pair(int t, int w) {
			to = t;
			weight = w;
		}

		@Override
		public int compareTo(Pair o) {
			return this.weight - o.weight;
		}
	}
	ArrayList<Pair>[]graph;
	int[]d = new int[1001];
	int n, m, x;
	private void dijkstra(int from) {
		PriorityQueue<Pair>pq = new PriorityQueue<>();
		for(int i=1;i<=n;i++) d[i] = INF;
		pq.add(new Pair(from, 0));
		d[from] = 0;
		while(!pq.isEmpty()) {
			int cur = pq.peek().to;
			int cost = pq.peek().weight;
			pq.poll();
			for(int i=0;i<graph[cur].size();i++) {
				int next = graph[cur].get(i).to;
				int nCost = cost + graph[cur].get(i).weight;
				if (d[next] > nCost) {
					d[next] = nCost;
					pq.add(new Pair(next, nCost));
				}
			}
		}
	}
	private void BellmanFord() {

	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		graph = new ArrayList[n+1];
		for(int i=1;i<=n;i++) graph[i] = new ArrayList<>();
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int weight = Integer.parseInt(st.nextToken());
			graph[from].add(new Pair(to,weight));
		}
		int[] goBackCost = new int[n+1];
		for(int i=1;i<=n;i++) {
			dijkstra(i);
			if(i == x) {
				for(int j=1;j<=n;j++) goBackCost[j] += d[j];
			}
			else goBackCost[i] += d[x];
		}
		int max = 0;
		for(int i=1;i<=n;i++) {
			//System.out.println(i + " : " + goBackCost[i]);
			max = Math.max(max, goBackCost[i]);
		}
		System.out.println(max);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
