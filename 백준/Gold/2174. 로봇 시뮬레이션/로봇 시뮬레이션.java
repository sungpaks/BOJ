
import java.io.*;
import java.util.*;

public class Main {
	private static class robot {
		int x, y;
		int dir; //0:북 , 1:서, 2:남, 3:동
		robot(int x, int y, char dir) {
			this.x = x;
			this.y = y;
			if (dir == 'N') this.dir = 0;
			if (dir == 'W') this.dir = 1;
			if (dir == 'S') this.dir = 2;
			if (dir == 'E') this.dir = 3;
		}
		void turnLeft() {
			this.dir = (this.dir + 1) % 4;
		}
		void turnRight() {
			if (this.dir > 0) this.dir--;
			else this.dir = 3;
		}
		void goForward() {
			int []dx = {0, -1, 0, 1};
			int []dy = {1, 0, -1, 0};
			this.x += dx[dir];
			this.y += dy[dir];
		}
	}
	private boolean isCrashedInToTheWall(int x, int y, int a, int b) {
		return !((1 <= x && x <= a) && (1 <= y && y <= b));
	}
	private void solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		//가로 A, 세로 B 크기의 땅
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		//로봇이 n개, m개의 명령
		List<robot>robots = new ArrayList<robot>();
		int [][]visited = new int[102][102];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int newX = Integer.parseInt(st.nextToken());
			int newY = Integer.parseInt(st.nextToken());
			char newDir = st.nextToken().charAt(0);
			robots.add(new robot(newX, newY, newDir));
			visited[newX][newY] = i+1;
		}

		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int robotIndex = Integer.parseInt(st.nextToken()) - 1;
			char command = st.nextToken().charAt(0);
			int t = Integer.parseInt(st.nextToken());
			robot curRobot = robots.get(robotIndex);
			while(t-- > 0) {
				if (command == 'L') curRobot.turnLeft();
				if (command == 'R') curRobot.turnRight();
				if (command == 'F') {
					visited[curRobot.x][curRobot.y] = 0;
					curRobot.goForward();
					if (visited[curRobot.x][curRobot.y] != 0) {
						System.out.println("Robot " + (robotIndex+1) + " crashes into robot " + visited[curRobot.x][curRobot.y]);
						return;
					}
					visited[curRobot.x][curRobot.y] = robotIndex+1;
				}
				//벽 충돌 확인
				if (isCrashedInToTheWall(curRobot.x, curRobot.y, a, b)) {
					System.out.println("Robot " + (robotIndex+1) + " crashes into the wall");
					return;
				}
			}
		}
		System.out.println("OK");
	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}