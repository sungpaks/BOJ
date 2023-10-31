
import java.io.IOException;
import java.util.*;

public class Main {
	static int n, k;
	static int cnt=0;
	static int[] kit;
	static boolean[] used;
	public void backTracking(int cur, int curWeight) {
		if (cur >= n) {
			cnt++;
			return;
		}
		for(int i=0;i<n;i++) {
			if (!used[i] && curWeight+kit[i]-k >= 500) {
				used[i] = true;
				backTracking(cur+1, curWeight+kit[i]-k);
				used[i] = false;
			}
		}
	}
	public void solve() throws IOException{
		Scanner in = new Scanner (System.in);
		n = in.nextInt();
		k = in.nextInt();
		kit = new int[n];
		used = new boolean[n];
		for(int i=0;i<n;i++) kit[i] = in.nextInt();
		backTracking(0, 500);
		System.out.println(cnt);
	}

	public static void main(String[] args) throws IOException{
		new Main().solve();
	}

}
