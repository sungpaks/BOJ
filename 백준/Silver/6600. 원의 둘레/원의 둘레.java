
import java.io.*;
import java.nio.file.NoSuchFileException;
import java.util.*;

public class Main {
	private double getCircumRadius(double[] x, double[] y) {
		double[] vectorX = new double[3];
		double[] vectorY = new double[3];
		double r = 1;
		for(int i=0;i<3;i++) {
			vectorX[i] = x[(i+1)%3] - x[(i+2)%3];
			vectorY[i] = y[(i+1)%3] - y[(i+2)%3];
			r *= Math.sqrt(Math.pow(x[(i+1)%3]-x[(i+2)%3], 2) + Math.pow(y[(i+1)%3]-y[(i+2)%3],2));
		}
		r /= (2*Math.abs(vectorX[0]*vectorY[1]-vectorY[0]*vectorX[1]));
		return r;
	}
	private void solution() throws IOException {
		final double PIE = 3.141592653589793;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			try{
				StringTokenizer st = new StringTokenizer(br.readLine());
				double[] x = new double[3];
				double[] y = new double[3];
				for (int i = 0; i < 3; i++) {
					x[i] = Double.parseDouble(st.nextToken());
					y[i] = Double.parseDouble(st.nextToken());
				}
				double r = getCircumRadius(x, y);
				System.out.printf("%.2f%n", 2 * PIE * r);
			}catch(EOFException e) {
				break;
			} catch(NullPointerException e) {
				break;
			} catch(NoSuchElementException e) {
				break;
			}
		}
 	}
    public static void main(String[] args) throws IOException {
		new Main().solution();
	}
}