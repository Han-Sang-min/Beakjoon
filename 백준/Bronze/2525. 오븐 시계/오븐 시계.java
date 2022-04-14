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
		
		StringTokenizer st = new StringTokenizer(bw.readLine(), " ");
		int h = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(bw.readLine());
		int tot = m + p;
		
		if(tot >= 60) {
			h += tot / 60;
			tot %= 60;
		}
		if(h >= 24)
			h %= 24;
		
		br.write(String.valueOf(h) + " " + String.valueOf(tot));
		
		br.flush();
		br.close();
	}
}