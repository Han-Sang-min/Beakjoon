import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedWriter br = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		
		int x = Integer.valueOf(bw.readLine());
		int y = Integer.valueOf(bw.readLine());
		
		if(x > 0 && y > 0)
			br.write("1");
		else if (x < 0 && y > 0)
			br.write("2");
		else if (x < 0 && y < 0)
			br.write("3");
		else if (x > 0 && y < 0)
			br.write("4");
		
		br.flush();
		br.close();
	}
}