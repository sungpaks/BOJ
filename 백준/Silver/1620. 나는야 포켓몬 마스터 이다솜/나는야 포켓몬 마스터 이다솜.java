
import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		Map<Integer, String>dogamByInteger = new HashMap<Integer, String>();
		Map<String, Integer>dogamByString = new HashMap<String, Integer>();
		for(int i=1;i<=n;i++) {
			String in = br.readLine();
			dogamByInteger.put(i, in);
			dogamByString.put(in, i);
		}
		for(int j=0;j<m;j++) {
			String current = br.readLine();
			try {
				int index = Integer.parseInt(current);
				bw.write(dogamByInteger.get(index)+'\n');
			} catch (NumberFormatException nfe) {
				int index = dogamByString.get(current);
				bw.write(Integer.toString(index)+'\n');
			}
		}
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}