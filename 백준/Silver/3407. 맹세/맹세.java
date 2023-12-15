import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public boolean isInPeriodicTable(char c1) {
		if (c1 == 'h' || c1 == 'b' || c1 == 'c' || c1 == 'n' ||
				c1 == 'o' || c1 == 'f' || c1 == 'p' || c1 == 's' ||
				c1 == 'k' || c1 == 'v' || c1 == 'y' || c1 == 'i' ||
				c1 == 'w' || c1 == 'u') return true;
		return false;
	}
	public boolean isInPeriodicTable(char c1, char c2) {
		String combined = Character.toString(c1) + Character.toString(c2);

	    if (combined.equals("he") ||
	        combined.equals("li") ||
	        combined.equals("be") ||
	        combined.equals("ne") ||
	        combined.equals("na") ||
	        combined.equals("mg") ||
	        combined.equals("al") ||
	        combined.equals("si") ||
	        combined.equals("cl") ||
	        combined.equals("ar") ||
	        combined.equals("ca") ||
	        combined.equals("sc") ||
	        combined.equals("ti") ||
	        combined.equals("cr") ||
	        combined.equals("mn") ||
	        combined.equals("fe") ||
	        combined.equals("co") ||
	        combined.equals("ni") ||
	        combined.equals("cu") ||
	        combined.equals("zn") ||
	        combined.equals("ga") ||
	        combined.equals("ge") ||
	        combined.equals("as") ||
	        combined.equals("se") ||
	        combined.equals("br") ||
	        combined.equals("kr") ||
	        combined.equals("rb") ||
	        combined.equals("sr") ||
	        combined.equals("zr") ||
	        combined.equals("nb") ||
	        combined.equals("mo") ||
	        combined.equals("tc") ||
	        combined.equals("ru") ||
	        combined.equals("rh") ||
	        combined.equals("pd") ||
	        combined.equals("ag") ||
	        combined.equals("cd") ||
	        combined.equals("in") ||
	        combined.equals("sn") ||
	        combined.equals("sb") ||
	        combined.equals("te") ||
	        combined.equals("xe") ||
	        combined.equals("cs") ||
	        combined.equals("ba") ||
	        combined.equals("hf") ||
	        combined.equals("ta") ||
	        combined.equals("re") ||
	        combined.equals("os") ||
	        combined.equals("ir") ||
	        combined.equals("pt") ||
	        combined.equals("au") ||
	        combined.equals("hg") ||
	        combined.equals("tl") ||
	        combined.equals("pb") ||
	        combined.equals("bi") ||
	        combined.equals("po") ||
	        combined.equals("at") ||
	        combined.equals("rn") ||
	        combined.equals("fr") ||
	        combined.equals("ra") ||
	        combined.equals("rf") ||
	        combined.equals("db") ||
	        combined.equals("sg") ||
	        combined.equals("bh") ||
	        combined.equals("hs") ||
	        combined.equals("mt") ||
	        combined.equals("ds") ||
	        combined.equals("rg") ||
	        combined.equals("cn") ||
	        combined.equals("fl") ||
	        combined.equals("lv") ||
	        combined.equals("la") ||
	        combined.equals("ce") ||
	        combined.equals("pr") ||
	        combined.equals("nd") ||
	        combined.equals("pm") ||
	        combined.equals("sm") ||
	        combined.equals("eu") ||
	        combined.equals("gd") ||
	        combined.equals("tb") ||
	        combined.equals("dy") ||
	        combined.equals("ho") ||
	        combined.equals("er") ||
	        combined.equals("tm") ||
	        combined.equals("yb") ||
	        combined.equals("lu") ||
	        combined.equals("ac") ||
	        combined.equals("th") ||
	        combined.equals("pa") ||
	        combined.equals("np") ||
	        combined.equals("pu") ||
	        combined.equals("am") ||
	        combined.equals("cm") ||
	        combined.equals("bk") ||
	        combined.equals("cf") ||
	        combined.equals("es") ||
	        combined.equals("fm") ||
	        combined.equals("md") ||
	        combined.equals("no") ||
	        combined.equals("lr")) {
	        return true;
	    }
	    return false;
	}
	boolean isOk;
	boolean[] visited;
	void check(String s, int i) {
		if (visited[i]) return;
		if (i >= s.length()) {
			isOk = true;
			//System.out.println("true");
			return;
		}
		visited[i] = true;
		if (i < s.length() - 1 && isInPeriodicTable(s.charAt(i), s.charAt(i+1))) {
			check(s, i+2);
			//System.out.print(Character.toString(s.charAt(i)) + Character.toString(s.charAt(i+1)) + " ");
		}
		if (isInPeriodicTable(s.charAt(i))) {
			check(s, i+1);
			//System.out.print(Character.toString(s.charAt(i)) + " ");
		}
	}
	public void solve() throws IOException{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-- > 0) {
			String s = in.next();
			isOk = false;
			visited = new boolean[s.length()+1];
			check(s, 0);
			if (isOk) System.out.println("YES");
			else System.out.println("NO");
		}
	}

	public static void main(String[] args) throws IOException{
		new Main().solve();
	}

}
