import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		int result = 0;
		String str = br.readLine();
		int SKable = 0;
		int LRable = 0;
		for(int i=0;i<n;i++) {
			char c = str.charAt(i);
			if ('1' <= c && c <= '9') result++;
			else if (c == 'S') SKable++;
			else if (c == 'L') LRable++;
			else if (c == 'K') {
				if (SKable==0) break;
				result++;
				SKable--;
			}
			else if (c == 'R') {
				if (LRable==0) break;
				result++;
				LRable--;
			}
		}
		System.out.println(result);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}