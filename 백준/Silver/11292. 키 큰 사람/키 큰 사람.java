
import java.io.*;
import java.math.BigInteger;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	private void solution() throws IOException {
		Scanner in = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		while (true) {
			Map<Double, String>student = new TreeMap<>();
			double max = 0;
			int n = in.nextInt();
			if (n == 0) break;
			for(int i=0;i<n;i++) {
				String name = in.next();
				Double h = in.nextDouble();
				if (max < h) max = h;
				if (student.containsKey(h)) {
					String oldString = student.get(h);
					student.replace(h, oldString + " " + name);
				}
				else student.put(h, name);
			}
			bw.write(student.get(max) + "\n");
			bw.flush();
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}