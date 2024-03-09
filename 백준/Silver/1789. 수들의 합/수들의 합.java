import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		long n = Long.parseLong(br.readLine());
		long i = 1;
		long cur = 0;
		int result = 0;
		while(cur + i <= n) {
			cur += i;
			i++;
			result++;
		}
		System.out.println(result);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}