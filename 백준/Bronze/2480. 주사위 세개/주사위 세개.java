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
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int z = Integer.parseInt(st.nextToken());
		
		if(x == y && y == z)
			br.write(String.valueOf(10000 + x * 1000));
		else if(x == y || x == z)
			br.write(String.valueOf(1000 + x * 100));
		else if(y == z)
			br.write(String.valueOf(1000 + y * 100));
		else
			br.write(String.valueOf(Math.max(Math.max(x,y), z) * 100));
		
		br.flush();
		br.close();
	}
}