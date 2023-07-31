
import java.io.*;
import java.util.*;

public class Main {
    public static int getCountOfFive(int n) {
        int result = 0;
        while (n > 0) {
            if (n%5 == 0) result++;
            else break;
			n/=5;
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        //2,5 쌍이 몇개고, 10배수가 몇개냐.. 근데 2는 충분히 많아서 5만 세줘도 될듯?
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = 0;
        for(int i=5;i<=n;i++) {
            cnt += getCountOfFive(i);
        }
        System.out.println(cnt);
    }
}