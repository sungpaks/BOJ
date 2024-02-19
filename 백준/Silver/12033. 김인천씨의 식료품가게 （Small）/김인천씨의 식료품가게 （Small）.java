import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());
		ArrayList<Integer>p = new ArrayList<>();
		for(int k=1;k<=t;k++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0;i<2*n;i++) {
				p.add(Integer.parseInt(st.nextToken()));
			}
			String result = "Case #" + k + ":";
			while(!p.isEmpty()) {
				for(int i=1;i<p.size();i++) {
					if((p.get(i)/4)*3 == p.get(0)) {
						result = result + " " + p.get(0);
						p.remove(i);
						p.remove(0);
						break;
					}
				}
			}
			bw.write(result + "\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();

	}
}