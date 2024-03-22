import java.io.*;
import java.util.*;

public class Main {
	private int nameToIndex(String name) {
		if (name.equals("kor") || name.equals("apple") || name.equals("red")) return 0;
		else if (name.equals("eng") || name.equals("pear") || name.equals("blue")) return 1;
		else return 2;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		/*
		subject : kor, eng, math, -
		fruit : apple, pear, orange, -
		color : red, blue, green, -
		 */
		int[][][] favorCount = new int[3][3][3];

		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());

			String subject = st.nextToken();
			String fruit = st.nextToken();
			String color = st.nextToken();

			favorCount[nameToIndex(subject)][nameToIndex(fruit)][nameToIndex(color)]++;
		}
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int[] index = new int[3];
			for(int j=0;j<3;j++) {
				String name = st.nextToken();
				if(name.equals("-")) index[j] = -1;
				else index[j] = nameToIndex(name);
			}
			int cnt = 0;
			for(int a = 0;a<3;a++) {
				if(!(index[0]==-1 || index[0]==a)) continue;
				for(int b=0;b<3;b++) {
					if(!(index[1]==-1 || index[1]==b)) continue;
					for(int c=0;c<3;c++) {
						if(!(index[2]==-1 || index[2]==c)) continue;
						cnt += favorCount[a][b][c];
					}
				}
			}
			bw.write(Integer.toString(cnt) + "\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}