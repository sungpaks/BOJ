
import java.io.*;
import java.math.BigInteger;
import java.nio.Buffer;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	static char[][] arr;
	static boolean isLeft(char c) {
		return (c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='y'||
				c=='a'||c=='s'||c=='d'||c=='f'||c=='g'||
				c=='z'||c=='x'||c=='c'||c=='v'||c=='b');
	}
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String s = in.nextLine();
		int leftSum = 0;
		int rightSum = 0;
		int shiftAndSpace = 0;
		for(int i = 0; i<s.length();i++) {
			char c = s.charAt(i);
			if (c == ' ') shiftAndSpace++;
			else {
				if ('A' <= c && c <= 'Z') {
					shiftAndSpace++;
					c += 32;
				}
				if (isLeft(c)) leftSum++;
				else rightSum++;
			}
		}
		while (shiftAndSpace-- > 0) {
			if (leftSum > rightSum) rightSum++;
			else leftSum++;
		}
		System.out.println(leftSum + " " + rightSum);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}