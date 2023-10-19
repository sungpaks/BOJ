
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
		int T = in.nextInt();
		while(T-- > 0) {
			int n = in.nextInt();
			HashMap<String, Integer>publicKey1 = new HashMap<String, Integer>();
			int[] order = new int[n];
			for(int i=0;i<n;i++) {
				String word = in.next();
				publicKey1.put(word,i);
			}
			for(int i=0;i<n;i++) {
				String word = in.next();
				order[i] = publicKey1.get(word);
			}
			String[] encryptedKey = new String[n];
			for(int i=0;i<n;i++) {
				String word = in.next();
				encryptedKey[order[i]] = word;
			}
			for(int i=0;i<n;i++) {
				bw.write(encryptedKey[i] + " ");
			}
			bw.write("\n");
		}
		bw.flush();
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}