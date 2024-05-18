import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] dishes = new int[n];
		for(int i=0;i<n;i++) {
			dishes[i] = Integer.parseInt(st.nextToken());
		}
		int prev = dishes[n-1];
		int oneTak = 0;
		for(int i=0;i<n;i++) {
			if (prev >= dishes[i]) oneTak++;
			prev = dishes[i];
		}
		System.out.println(oneTak);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}