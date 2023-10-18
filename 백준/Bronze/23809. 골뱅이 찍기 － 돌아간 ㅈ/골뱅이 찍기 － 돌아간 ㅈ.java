
import java.io.*;
import java.math.BigInteger;
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
		int n = in.nextInt();
		arr = new char[1000][1000];
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if (j==0 || (i==0 && j==4) || (i==1&&j==3) ||
						(i==2&&j==1) || (i==2&&j==2) || (i==3&&j==3) || (i==4&&j==4)) fillShells(i*n, j*n, n, '@');
				else if ((i==0&&(j==1||j==2||j==3)) || (i==1&&(j==1||j==2)) || (i==3&&(j==1||j==2) || (i==4&&(j==1||j==2||j==3))))
					fillShells(i*n, j*n, n, ' ');
			}
		}
		for(int i=0;i<5*n;i++) {
			for(int j=0;j<5*n;j++) {
				if (arr[i][j] == '@' || arr[i][j] == ' ') System.out.print(arr[i][j]);
			}
			if (i < 5*n-1)System.out.print("\n");
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}