
import java.io.*;
import java.util.*;

public class Main {
	static boolean []visited = new boolean[8];
	static int[]member = new int[8];
	static int[]team = new int[8];
	static float result = 0;
	private static void getSatisfaction(int cur) {
		if (cur == 8) {
			float s1 = 1 - (((float)Math.abs(member[team[0]]+member[team[1]]-member[team[2]]-member[team[3]]))/20);
			float s2 = 1 - (((float)Math.abs(member[team[4]]+member[team[5]]-member[team[6]]-member[team[7]]))/20);
			float sMin = Float.min(s1, s2);
//			for(int i=0;i<8;i++) System.out.print(team[i]);
//			System.out.println(":" + s1 + "," + s2);
			result = Float.max(result, sMin);
		}
		for(int i=0;i<8;i++) {
			if (!visited[i]) {
				visited[i] = true;
				team[cur] = i;
				getSatisfaction(cur+1);
				visited[i] = false;
			}
		}
	}
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		for(int i=0;i<8;i++) member[i] = in.nextInt();

		getSatisfaction(0);
		System.out.println(result);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}