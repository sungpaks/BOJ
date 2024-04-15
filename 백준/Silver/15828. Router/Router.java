import java.io.*;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		Queue<Integer>q = new LinkedList<>();
		while(true) {
			int packet = Integer.parseInt(br.readLine());
			if (packet == -1) break;
			else if (packet == 0) q.poll();
			else if (q.size() < n) q.add(packet);
		}
		if (q.isEmpty()) System.out.println("empty");
		while(!q.isEmpty()) {
			System.out.print(q.poll() + " ");
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}