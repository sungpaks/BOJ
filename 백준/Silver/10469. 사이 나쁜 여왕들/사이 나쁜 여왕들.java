import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	int[] di = {1,-1,1,-1};
	int[] dj = {1,1,-1,-1};
	boolean check(String[] board) throws IOException {
		boolean[][] chess = new boolean[8][8];
		int queenCount = 0;
		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				char c = (char)board[i].charAt(j);
				if (c == '*') {
					queenCount++;
					if (chess[i][j]) return false;
					for(int k=0;k<8;k++) {
						for(int t=0;t<4;t++) {
							int ni = i+di[t]*k;
							int nj = j+dj[t]*k;
							if (0 <= ni && ni < 8 && 0 <= nj && nj < 8) {
								chess[ni][nj] = true;
							}
						}
						chess[i][k]=true;
						chess[k][j]=true;
					}
					/*System.out.println();
					for(int a=0;a<8;a++) {
						for(int b=0;b<8;b++) {
							System.out.print(chess[a][b] ? 'X' : 'O');
						}
						System.out.println();
					}
					System.out.println();*/
				}
			}
		}
		return queenCount == 8;
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String[] board = new String[8];
		for(int i=0;i<8;i++) board[i]=br.readLine();
		if (check(board)) System.out.println("valid");
		else System.out.println("invalid");
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}