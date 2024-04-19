import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		String a = st.nextToken();
		String b = st.nextToken();
		int o = 0;
		String result = "";
		for(int i=0;i<Math.max(a.length(),b.length());i++) {
			int curA = a.length()-i-1 < 0 ? 0 : a.charAt(a.length()-i-1)-'0';
			int curB = b.length()-i-1 < 0 ? 0 : b.charAt(b.length()-i-1)-'0';
			if ((curA + curB + o)%2 == 1) result = "1" + result;
			else result = "0" + result;
			o = (curA + curB + o)/2;
		}
		if (o == 1) result  = "1" + result;
		int indexOf1 = result.indexOf('1');
		if (indexOf1 >= 0) result = result.substring(indexOf1);
		else result = "0";
		System.out.println(result);
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}