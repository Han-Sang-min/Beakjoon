import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedWriter br = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		
		int score = Integer.valueOf(bw.readLine());
		
		if (score >= 90)
			br.write("A");
		else if (score >= 80)
			br.write("B");
		else if (score >= 70)
			br.write("C");
		else if (score >= 60)
			br.write("D");
		else
			br.write("F");
		br.flush();
		br.close();
	}
}