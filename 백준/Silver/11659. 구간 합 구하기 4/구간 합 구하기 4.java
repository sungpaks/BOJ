
import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int [] cumSum = new int[100001];
		st = new StringTokenizer(br.readLine());
		cumSum[0] = Integer.parseInt(st.nextToken());
		for(int i=1;i<n;i++) {
			cumSum[i] = Integer.parseInt(st.nextToken()) + cumSum[i-1];
		}
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int result = cumSum[end-1];
			if (start-2 >= 0) result -= cumSum[start-2];
			bw.write(Integer.toString(result)+'\n');
		}
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}