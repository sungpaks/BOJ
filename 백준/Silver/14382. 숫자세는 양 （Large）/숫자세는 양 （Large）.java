import java.io.*;
import java.util.*;

public class Main {
	private boolean isAllVisited(boolean[] visited) {
		for(int i=0;i<10;i++) if(!visited[i]) return false;
		return true;
	}
	private int check(boolean[] visited, int n) {
		if(n == 0) return 0;
		int i = 0;
		while(++i > 0) {
			int cur = i * n;
			while (cur > 0) {
				visited[cur % 10] = true;
				cur /= 10;
			}
			if (isAllVisited(visited)) break;
		}
		return i*n;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());
		for(int i=1;i<=t;i++) {
			int n = Integer.parseInt(br.readLine());
			boolean[] visited = new boolean[10];
			int y = check(visited, n);
			String yString;
			if(y == 0) yString = "INSOMNIA";
			else yString = Integer.toString(y);
			bw.write("Case #"+ Integer.toString(i) + ": " + yString + "\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}