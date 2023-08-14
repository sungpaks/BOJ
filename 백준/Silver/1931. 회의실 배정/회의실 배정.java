
import java.io.*;
import java.util.*;

public class Main {
	private static class myPair {
		public int start, end;
		public myPair (int start, int end) {
			this.start = start;
			this.end = end;
		}
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		myPair [] timeTable = new myPair[n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			timeTable[i] = new myPair(start, end);
		}
		Arrays.sort(timeTable, new Comparator<myPair>() {
			@Override
			public int compare(myPair p1, myPair p2) {
				int tmp = p1.end - p2.end;
				if (tmp == 0) {
					return (p1.start - p2.start);
				}
				return tmp;
			}
		});
		int cnt = 1;
		//int curStart = timeTable[0].start;
		int curEnd = timeTable[0].end;
		for(int i=1;i<n;i++) {
			if (curEnd <= timeTable[i].start) {
				cnt++;
				curEnd = timeTable[i].end;
			}
		}
		System.out.println(cnt);
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}