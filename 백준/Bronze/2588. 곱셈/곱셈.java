import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedWriter br = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		
		int a = Integer.parseInt(bw.readLine());
		int b = Integer.parseInt(bw.readLine());
		
		br.write(String.valueOf(a * (b % 10)));
		br.newLine();
		br.write(String.valueOf(a * ((b / 10)% 10)));
		br.newLine();
		br.write(String.valueOf(a * (b / 100)));
		br.newLine();
		br.write(String.valueOf(a * b));
		br.newLine();
		
		br.flush();
		br.close();
	}
}