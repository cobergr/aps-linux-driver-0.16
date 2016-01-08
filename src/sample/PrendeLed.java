import java.io.*;  // importar
  public class PrendeLed{ // clase
   static int led; // variable led
public static native void  Estado(int led);
public static void main(String[] args){

PrendeLed prendeled= new PrendeLed();

BufferedReader entrada= new BufferedReader(new InputStreamReader(System.in)); // lectura

try{
System.out.println ("MENU: Elige Opcion"); // Menú 
System.out.println ("1) Prender Led Uno");
System.out.println ("2) Prender Led Dos");

led=Integer.parseInt(entrada.readLine()); // leer entrada
 }catch(IOException e){}
 prendeled.Estado(led);
System.out.println ("Encendiste el led" + led);             
}
static{
 System.loadLibrary("PrendeLed");
  }
}