import java.io.*;  // importar
public class Prueba{ // clase



	public static void main(String[] args) throws IOException{
	Prueba pr = new Prueba();	
	pr.callingSheel();
	}


	public static void callingSheel() throws IOException{

	char[] buf = new char[24];

	buf[0] = 29;
	buf[1] = 'k';
	buf[2] = 8;
	  buf[3] = 2;
	buf[4] = 5;
	buf[5] = 1;
	buf[6] = 0x00;
	buf[7] = 0x08;
	buf[8] = 'H';
	buf[9] = 'O';
	buf[10] = 'L';
	  buf[11] = 'A';
	buf[12] = 'H';
	buf[13] = 'O';
	buf[14] = 'L';
	buf[15] = 'A';
	buf[16] = 'H';
	buf[17] = 'O';
	  buf[18] = 'L';
	buf[19] = 'A';
	buf[20] = 'H';
	buf[21] = 'O';
	buf[22] = 'L';
	buf[23] = 'A';

	String line;

	System.out.println("Java Antes");
	Process p = Runtime.getRuntime().exec(new String[]{"bash","-c","./impresor "+buf});
		BufferedReader input = new BufferedReader(new InputStreamReader(p.getInputStream()));
	  while ((line = input.readLine()) != null) {
		System.out.println(line);
	  }
	  input.close();
		System.out.println("Java ejecutado");

	
		

}

}
