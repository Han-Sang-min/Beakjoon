import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader bw = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(bw.readLine(), " ");
		
		int h = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken()) - 45;
		
		if(m < 0) {
			if(h == 0)
				h = 23;
			else
				h -= 1;
			m += 60;
		}
		System.out.println(h + " " + m);
	}
}