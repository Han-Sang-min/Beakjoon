import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedWriter br = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		
		String str = bw.readLine();
		StringTokenizer st = new StringTokenizer(str, " ");
		
		double a = (double)Integer.parseInt(st.nextToken());
		double b = (double)Integer.parseInt(st.nextToken());
		
		br.write(String.format("%.9f", a / b));
		
		br.flush();
		br.close();
	}
}