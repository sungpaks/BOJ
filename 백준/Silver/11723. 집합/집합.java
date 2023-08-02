
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int s = 0; //공집합에서 시작.
		for(int i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String o = st.nextToken();
			if (o.equals("add")) {
				int x = Integer.parseInt(st.nextToken());
				s = s | (1 << x); //1을 x만큼 비트시프트해서 OR연산으로 적용
			}
			if (o.equals("remove")) {
				int x = Integer.parseInt(st.nextToken());
				s = s & ~(1 << x); //x자리에만 0이고 나머진 1임 => 1이었떤 x자리가 0이 됨. 나머지는 1인자리는 1로 유지
			}
			if (o.equals("check")) {
				int x = Integer.parseInt(st.nextToken());
				bw.write(Integer.toString((s & (1 << x)) >> x) + "\n");
			}
			if (o.equals("toggle")) {
				int x = Integer.parseInt((st.nextToken()));
				s = s ^ (1 << x);
			}
			if (o.equals("all")) {
				s = (1 << 21) - 1;
			}
			if (o.equals("empty")) {
				s = 0;
			}
		}
		br.close();
		bw.close();
	}
}