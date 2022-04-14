import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedWriter br = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		
		int year = Integer.valueOf(bw.readLine());
		
		if ((year%4 == 0 && year%100 != 0 )|| year%400 == 0)
			br.write("1");
		else
			br.write("0");
		br.flush();
		br.close();
	}
}