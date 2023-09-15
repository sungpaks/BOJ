
import java.io.*;
import java.util.*;

public class Main {

	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = br.readLine();
		int curNum = 0;
		int curSign = 1;
		int result = 0;
		for(int i=0;i<in.length();i++) {
			if ('0' <= in.charAt(i) && in.charAt(i) <= '9') {
				curNum *= 10;
				curNum += in.charAt(i) - '0';
			}
			else if (in.charAt(i) == '+' || in.charAt(i) == '-') {
				result += curSign * curNum;
				curNum = 0;
				if (in.charAt(i) == '-') curSign = -1;
			}
		}
		result += curSign * curNum;
		System.out.println(result);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}