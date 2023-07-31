
import java.io.*;
import java.util.*;

public class Main {
	public static int getSum (int n) {
		int result = 0;
		while (n>0) {
			result += n%10;
			n /= 10;
		}
		return result;
	}
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for(int i=1;i<n;i++) {
			if (i + getSum(i) == n) {
				System.out.println(i);
				return;
			}
		}
		System.out.println(0);
	}
}