
import java.io.*;
import java.math.BigInteger;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		int cur = 0;
		int max = 0;
		for(int i=0;i<10;i++) {
			cur -= in.nextInt();
			cur += in.nextInt();
			if (cur > max) max = cur;
		}
		System.out.println(max);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}