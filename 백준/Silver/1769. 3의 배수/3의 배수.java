
import java.io.*;
import java.math.BigInteger;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		String bigInteger = in.next();
		int X = 0;
		int cnt = bigInteger.length() > 1 ? 1 : 0;
		int Y = 0;
		for(int i=0;i<bigInteger.length();i++) {
			X += bigInteger.charAt(i) - '0';
		}
		while (!(0<=X && X<=9)) {
			cnt++;
			Y = 0;
			while(X > 0) {
				Y += X%10;
				X /= 10;
			}
			X = Y;
		}
		System.out.println(cnt);
		System.out.println(X%3 == 0 ? "YES" : "NO");
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}