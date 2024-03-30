import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private boolean check(String str) {
		if (str.charAt(0) != '1' || str.charAt(str.length()-1) != '2') return false;

		for(int i=1;i<str.length()-1;i++) {
			char cur = str.charAt(i);
			char prev = str.charAt(i-1);
			char next = str.charAt(i+1);
			if (cur == '1' || cur == '2') return false;
			else if (cur == '3') {
				if (!(prev == '4' || prev == '6') ||
					!(next == '4' || next == '5')) return false;
			}
			else if (cur == '4') {
				if (!(prev == '1' || prev == '3') ||
					!(next == '2' || next == '3')) return false;
			}
			else if (cur == '5') {
				if (!(prev == '1' || prev == '3') ||
					!(next == '8')) return false;
			}
			else if (cur == '6') {
				if (!(next == '2' || next == '3') ||
						!(prev == '8')) return false;
			}
			else if (cur == '7') {
				if (next != '8' || prev != '8') return false;
			}
			else if (cur == '8') {
				if (!(prev == '5' || prev == '7') ||
					!(next == '6' || next == '7')) return false;
			}
		}
		return true;
	}
	/*
	142, 15862, 14342
	 */
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int i = 0;
		while(++i > 0) {
			String str = br.readLine();
			if (str.equals("0")) break;
			bw.write(Integer.toString(i) + ". ");
			if (check(str)) bw.write("VALID");
			else bw.write("NOT");
			bw.write("\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}