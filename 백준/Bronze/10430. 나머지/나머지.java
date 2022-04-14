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
		
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		
		br.write(String.valueOf((a + b) % c));
		br.newLine();
		br.write(String.valueOf((((a % c) + (b % c)) % c)));
		br.newLine();
		br.write(String.valueOf((a * b) % c));
		br.newLine();
		br.write(String.valueOf((((a % c) * (b % c)) % c)));
		br.newLine();
		
		br.flush();
		br.close();
	}
}