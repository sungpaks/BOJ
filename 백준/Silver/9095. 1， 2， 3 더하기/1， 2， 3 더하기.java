
import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());
		int [] dp = new int[11];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i=4;i<=10;i++){
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}
		while (T-- > 0) {
			bw.write(dp[Integer.parseInt(br.readLine())] + "\n");
		}
		bw.flush();
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
/*
			1 => 1
			2 => 2
			3 => 4
			4 => 7
			5 => 1+1+1+1+1
				1+1+1+2  4qjs
				2+2+1 3qjs
				3+1+1 3qjs
				3+2 2qjs
				total => 13
			와..씨!!!
			6을 만드는 경우는
			3의 경우에다가 모두 3을 더함 + 4의 경우에다가 모두 2를 더함 + 5의 경우에다가 모두 1을 더함
			=> 4 + 7 + 13 = 24
			7을 만드는 경우는 그럼 7 + 13 + 24 = 44 딱맞죠??

*/