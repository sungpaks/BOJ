
import java.io.*;
import java.math.BigInteger;
import java.nio.Buffer;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	static char[][] arr;
	private static void fillShells(int iStart, int jStart, int n, char c) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				arr[iStart+i][jStart+j] = c;
			}
		}
	}
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int P = in.nextInt();
		while (P-- > 0) {
			int T = in.nextInt();
			int[] kids = new int[20];
			int curResult = 0;
			for(int i=0;i<20;i++) {
				kids[i] = in.nextInt();
				for(int j=0;j<i;j++) {
					if (kids[i] < kids[j]) curResult++;
				}
			}
			bw.write(Integer.toString(T) + " " + Integer.toString(curResult) + "\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}