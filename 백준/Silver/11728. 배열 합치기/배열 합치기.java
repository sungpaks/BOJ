import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		ArrayList<Integer>arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		arr.sort(null);
		for(int i=0;i<n+m;i++) {
			bw.write(Integer.toString(arr.get(i)) + " ");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}