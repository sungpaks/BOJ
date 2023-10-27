
import java.io.*;
import java.math.BigInteger;
import java.nio.Buffer;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		long n = in.nextInt();
		long k = in.nextInt();
		System.out.println(n*n*k);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}