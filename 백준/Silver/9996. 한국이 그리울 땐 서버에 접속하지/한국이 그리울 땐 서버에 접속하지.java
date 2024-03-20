import java.io.*;
import java.util.*;

public class Main {
	private boolean check(String name, String pattern) {
		String left = pattern.substring(0, pattern.indexOf('*'));
		String right = pattern.substring(pattern.indexOf('*')+1);

		if (name.length() < pattern.length()-1) return false;
		try {
			return (name.substring(0, left.length()).equals(left)
					&& name.substring(name.length()-right.length()).equals(right));
		} catch(Exception e) {
			return false;
		}
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		String pattern = br.readLine();
		String[] names = new String[n+1];
		for(int i=0;i<n;i++) {
			names[i] = br.readLine();
		}
		for(int i=0;i<n;i++) {
			if(check(names[i], pattern)) bw.write("DA\n");
			else bw.write("NE\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}