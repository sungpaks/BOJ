
import java.io.IOException;
import java.util.*;

public class Main {
	char[][]matrix = new char[101][101];
	public void solve() throws IOException{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while (t-->0) {
			String s = in.next();
			int l = (int)Math.sqrt(s.length());
			int index = 0;
			for(int i=0;i<l;i++) {
				for(int j=0;j<l;j++) {
					matrix[i][j] = s.charAt(index++);
				}
			}
			for(int i=l-1;i>=0;i--) {
				for(int j=0;j<l;j++) {
					System.out.print(matrix[j][i]);
				}
			}
			System.out.println();
		}
	}

	public static void main(String[] args) throws IOException{
		new Main().solve();
	}

}
