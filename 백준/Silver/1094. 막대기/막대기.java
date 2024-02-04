import java.io.*;
import java.util.*;

public class Main {

	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int x = Integer.parseInt(br.readLine());
		String b = Integer.toBinaryString(x);
		int cnt = 0;
		for(int i=0;i<b.length();i++) {
			if (b.charAt(i) == '1') cnt++;
		}
		System.out.println(cnt);
		//23 = 16+4+2+1
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();

	}
}