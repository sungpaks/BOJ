import java.io.*;
import java.util.*;

public class Main {
	Map<Integer, Integer>clockNumberOrder = new HashMap<>();
	int makeClockNumber(int[] cn) {
		int result = 10000;
		for(int i=0;i<4;i++) {
			int cur = cn[i%4]*1000 + cn[(i+1)%4]*100 + cn[(i+2)%4]*10 + cn[(i+3)%4];
			if (cur < result) result = cur;
		}
		return result;
	}
	void setClockNumberOrder() {
		int o = 1;
		for(int thousand = 1;thousand <= 9; thousand++) {
			for(int hundred = 1; hundred <= 9; hundred++) {
				//if (thousand > hundred) continue;
				for(int ten = 1; ten<=9; ten++) {
					//if(hundred > ten) continue;
					for(int one=1; one<=9;one++) {
						//if (ten > one) continue;
						int currentNumber = thousand*1000+hundred*100+ten*10+one;
						int[] cd = {thousand, hundred, ten, one};
						if (currentNumber == makeClockNumber(cd)) clockNumberOrder.put(currentNumber, o++);
					}
				}
			}
		}
		//for(var n : clockNumberOrder.entrySet()) System.out.println(n);
	}

	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int[] cardNumber = new int[4];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<4;i++) {
			cardNumber[i] = Integer.parseInt(st.nextToken());
		}
		setClockNumberOrder();
		System.out.println(clockNumberOrder.get(makeClockNumber(cardNumber)));
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}
//4999 = 425?
