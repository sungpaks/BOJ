
import java.io.IOException;
import java.util.*;

public class Main {
	private class student {
		int nationNumber, studentNumber, score;
		student(int nationNumber, int studentNumber, int score) {
			this.nationNumber = nationNumber;
			this.studentNumber = studentNumber;
			this.score = score;
		}
	}
	public void solve() throws IOException{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		ArrayList<student>list = new ArrayList<>();
		for(int i=0;i<n;i++) {
			int nationNumber = in.nextInt();
			int studentNumber = in.nextInt();
			int score = in.nextInt();
			list.add(new student(nationNumber, studentNumber, score));
		}
		list.sort((student o1, student o2)->(-(o1.score - o2.score)));
		System.out.println(list.get(0).nationNumber + " " + list.get(0).studentNumber);
		System.out.println(list.get(1).nationNumber + " " + list.get(1).studentNumber);
		int i = 2;
		while (list.get(i).nationNumber == list.get(1).nationNumber && list.get(1).nationNumber == list.get(0).nationNumber) i++;
		System.out.println(list.get(i).nationNumber + " " + list.get(i).studentNumber);
	}

	public static void main(String[] args) throws IOException{
		new Main().solve();
	}

}
