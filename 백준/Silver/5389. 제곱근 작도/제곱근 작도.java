import java.io.*;
import java.util.*;

public class Main {

	private int construction(int n) {
		// n = r*r - l*l = (r+l)(r-l)
		//i = r+l, n/i = r-l => i+n/i = 2r, i-n/i = 2l
		// ((i+n/i)^2 - (i-n/i)^2)/4 = n?
		int result = -1;
		for(int i=1;i*i<=n;i++) {
			if (n%i != 0) continue;
			int r = (i+n/i)/2;
			int l = (i-n/i)/2;
			if (l < 0) l = (n/i - i)/2;
			if (r*r-l*l == n) result = l;
		}
		return result;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());
		while(t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			long result = construction(n);
			bw.write(result == -1 ? "IMPOSSIBLE" : Long.toString(result) + " " + Long.toString((long)Math.sqrt(n+result*result)));
			bw.write("\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}