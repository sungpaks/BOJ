
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public void solve() throws IOException{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine();
		while(T-- > 0) {
			String rec = in.nextLine();
			String[] words = new String[101];
			words = rec.split(" ");
			HashMap<String, Boolean>otherAnimals = new HashMap<>();
			while (true) {
				String s = in.nextLine();
				if (s.equals("what does the fox say?")) break;
				else otherAnimals.put(s.split(" ")[2], true);
			}
			for(int i=0;i<words.length;i++) {
				if (otherAnimals.containsKey(words[i])) continue;
				System.out.print(words[i] + " ");
			}
		}
	}

	public static void main(String[] args) throws IOException{
		new Main().solve();
	}

}
