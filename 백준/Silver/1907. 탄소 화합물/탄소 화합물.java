import java.io.*;
import java.util.*;

public class Main {
	private int howManyAtoms(String s, char a) {
		//특정 원소 개수
		int result = 0;
		for(int i=0;i<s.length();i++) {
			if (s.charAt(i) != a) continue;
			if (i+1 < s.length() && s.charAt(i+1) >= '2' && s.charAt(i+1) <= '9') {
				result+= s.charAt(i+1) - '0';
				i++;
			}
			else result++;
		}
		return result;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String s = br.readLine();
		String[] M = s.split("[/+=]");
		//C,H,O 순서
		int[][] m = new int[3][3];
		for(int i=0;i<3;i++) {
			m[i][0] = howManyAtoms(M[i],'C');
			m[i][1] = howManyAtoms(M[i],'H');
			m[i][2] = howManyAtoms(M[i],'O');
		}
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++) {
				for(int k=1;k<=10;k++) {
					if (i*m[0][0] + j*m[1][0] == k*m[2][0] &&
							i*m[0][1] + j*m[1][1] == k*m[2][1] &&
							i*m[0][2] + j*m[1][2] == k*m[2][2]) {
						System.out.println(i + " " + j + " " + k);
						return;
					}
				}
			}
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
//6 + 1 = 6