import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int k = Integer.parseInt(br.readLine());
		for(int i=1;i<=k;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int[] scores = new int[n];
			for(int j=0;j<n;j++) {
				scores[j] = Integer.parseInt(st.nextToken());
			}
			Arrays.sort(scores);
			bw.write("Class " + Integer.toString(i) + "\n");
			bw.write("Max " + Integer.toString(scores[n-1]) + ", Min " + Integer.toString(scores[0]) + ", Largest gap ");
			int max = 0;
			for(int j=1;j<n;j++) {
				if (max < scores[j] - scores[j-1]) max = scores[j] - scores[j-1];
			}
			bw.write(Integer.toString(max) + "\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}