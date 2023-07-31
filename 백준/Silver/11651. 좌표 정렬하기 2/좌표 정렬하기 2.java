
import java.io.*;
import java.util.*;

public class Main {
	public static class pair {
		public int x, y;
		pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	public static class comp implements Comparator<pair> {

		@Override
		public int compare(pair o1, pair o2) {
			if (o1.y == o2.y) return o1.x > o2.x ? 1 : -1;
			else return o1.y > o2.y ? 1 : -1;
		}
	}
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		ArrayList<pair>arr = new ArrayList<pair>();
		for(int i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			arr.add(new pair(x, y));
		}
		arr.sort(new comp());
		for(int i=0;i<n;i++) {
			System.out.println(arr.get(i).x + " " + arr.get(i).y);
		}
	}
}