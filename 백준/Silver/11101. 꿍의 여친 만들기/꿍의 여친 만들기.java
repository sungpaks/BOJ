
import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			Map<String, Integer>ggoong = new HashMap<>();
			StringTokenizer st = new StringTokenizer(br.readLine(), ",");
			while (st.hasMoreTokens()) {
				String curToken = st.nextToken();
				String [] splited = curToken.split(":");
				ggoong.put(splited[0], Integer.parseInt(splited[1]));
			}
			st = new StringTokenizer(br.readLine(), "|");
			int minCost = 2147483647;
			while (st.hasMoreTokens()) {
				int curCostMax = 0;
				String curToken = st.nextToken();
				String [] splited = curToken.split("&");
				for(int j=0;j<splited.length;j++) {
					int curCost = ggoong.get(splited[j]);
					if (curCostMax < curCost) curCostMax = curCost;
				}
				if (curCostMax < minCost) minCost = curCostMax;
			}
			bw.write(Integer.toString(minCost) + "\n");
		}
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}