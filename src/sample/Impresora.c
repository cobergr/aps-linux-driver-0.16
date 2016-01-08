#include "cl_givinn_remote_printer_Impresora.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include </home/pi/aps-linux-driver-016/src/aps/aps.h>

#define ESC     27
#define GS      29
 
// cc -shared -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/linux Impresora.c /home/pi/aps-linux-driver-016/src/aps/aps.c /home/pi/aps-linux-driver-016/src/aps/uri.c -I/home/pi/aps-linux-driver-016/src  -o libImpresora.so

	// cc -shared -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/linux Impresora.c /home/pi/aps-linux-driver-016/src/aps/aps.c /home/pi/aps-linux-driver-016/src/aps/uri.c /home/pi/aps-linux-driver-016/src/aps/usb.c /home/pi/aps-linux-driver-016/src/aps/aps-private.h -I/home/pi/aps-linux-driver-016/src  -o libImpresora.so -lusb-1.0


 
// cc -shared -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/linux Impresora.c -o libImpresora.so 

//aps-linux-driver-0.16/src/sample/ 
JNIEXPORT jint JNICALL Java_cl_givinn_remote_printer_Impresora_envioTimbre
  (JNIEnv *env, jobject obj, jstring string,  jint uno, jint dos ){
	
	unsigned char buf[9];
		unsigned char bufe[3];
		int errnum;
        char line[100];
		//ABRE PUERTOS
				
		int largoCa;
		

		char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";
		
		//str = (char *) malloc(largoCa);
		char *str = (*env)->GetStringUTFChars(env, string, 0);
		jsize lengthOfString =(*env)->GetStringLength(env,string);
		jint avalue = uno;
		jint bvalue = dos;

		// CALCULO BUFERS LARGO
		
		largoCa=lengthOfString;

		
		
		
		
		//str ="<TED version=\"1.0\"><DD><RE>76431892-7</RE><TD>39</TD><F>1</F><FE>2015-05-01</FE><RR>77157050-K</RR><RSR>DALEALBO</RSR><MNT>60000</MNT><IT1>Detalle</IT1><CAF version=1.0><DA><RE>76431892-7</RE><RS>GIVINN SPA</RS><TD>39</TD><RNG><D>1</D><H>10</H></RNG><FA>2015-04-04</FA><RSAPK><M>5TNd7jr+NHGNk1Q83MQYylgSt9ygtIDyvmFyah84RSSSxr/UrS3rb10H/MVv+eIMi976XmNpwG+Mq9W2HoWl9w==</M><E>Aw==</E></RSAPK><IDK>100</IDK></DA><FRMA algoritmo=SHA1withRSA>p7Y+O35toGIXg2f78CcKSZCe7Vv6JkSL6qlJy7wKMqHS4f8+sKpCcLg/SVEiw7gcX8uCIIazj23xcjyjpOhlXw==</FRMA></CAF><TSTED>2015-07-07T13:14:43</TSTED></DD><FRMT algoritmo=SHA1withRSA>y1GxPVo3k83So+zpfOngKwAPEfgQr1mDPZkShZhIm1Gv+dIFRsH7AMpRIMDN7gReKSME9SpWDzyoiCGPh5qNxQ==</FRMT></TED>";
		void *port;
		// CALCULO BUFERS LARGO
		printf(" lengthOfString %d",lengthOfString); 
		printf(" lengthOfString %s",str); 
		int i=0;
		char largo[4] ;
		snprintf( largo, 4, "%x", largoCa );
		printf( "largo string %s ", largo);
		int primero;
		int segundo;
		primero=uno;
		segundo=dos;
		//char *segundoC, *fin;
		// for(i=0;i<4;i++){
			 // printf("largo i %d %c \n" , i,largo[i]);
			 // if(i<1){
				// if(i==0){
					// primero = largo[i]-'0';
				
				// }else{
					
			 		// primero = largo[i]-'0';
				// }
				
			 // }
			 // else{
				// if(i==1){
					// segundoC[0] = largo[i];
				// }else{
					// if(i==2){
						// segundoC[1] = largo[i];
					// }
				// }
				
			 // }
			  
		// }
		
		
		printf(" largo primero %d", primero);
		printf(" largo segundo %d", segundo);
		// CALCULO BUFERS LARGO
		
		
				

		port = aps_create_port(puerto);
		errnum = aps_open(port);

		//CIERRE PUERTOS
		
		//Alto timbre
		bufe[0] = GS;
		bufe[1] = 'h';
		bufe[2] = 0x03;
    	errnum = aps_write(port,bufe,sizeof(bufe));
		errnum = aps_flush(port);

		//ancho timbre
        bufe[0] = GS;
        bufe[1] = 'w';
        bufe[2] = 0x02;
		errnum = aps_write(port,bufe,sizeof(bufe));
		errnum = aps_flush(port);
		
		errnum = aps_close(port);
		int sec;

		errnum = aps_open(port);
		//buf = argv[1];
        buf[0] = GS;
        buf[1] = 'k';
        buf[2] = 8;//pdf
  	    buf[3] = 2;
		
		
//compression mode (for the moment, “Automatic” is set automatically) EPM307-HRS - Technical Manual - Rev. C Page 28
// 0: Text,
//1: Numeric,
// 2: Byte,
// 3: Automatic
        buf[4] = 5;//error level (0 to 8) (maximum of 5 for the moment),
        buf[5] = 1;//of columns (1 to 30),

		//buf[6] = uno;
		buf[6]=primero;//2;
		buf[7] = segundo;//194;
		buf[8] = NULL;
		
		
		int largoTotal=lengthOfString+lengthOfString+8+1;
			char *timbre;
			timbre = (char *) malloc(largoTotal);
			stpcpy(stpcpy(stpcpy(timbre,buf),str),str);


		errnum = aps_write(port,timbre,largoTotal);
		errnum = aps_flush(port);
		
		free(timbre);
		
		snprintf(line,sizeof(line),"                        \n");
		
		errnum =  aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		
		bufe[0]=ESC;
		bufe[1]='C';
		bufe[2]=0;
		
		errnum = aps_write(port,bufe,3);
		errnum = aps_flush(port);

		
		
		snprintf(line,sizeof(line),"Timbre Electronico SII Res. 78 03/11/2015 \n\n\n\n\n\n");
		
		errnum =  aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		
		
		
		
		printf("antes de cerrar los puertos\n");
		errnum = aps_close(port);
		errnum = aps_destroy_port(port);
		printf("antes del release\n");
		
		
		(*env)->ReleaseStringUTFChars(env, string, str);
	
		printf("saliendo ...\n");
				

     return 1;
 }
 
 JNIEXPORT jint JNICALL Java_cl_givinn_remote_printer_Impresora_envioDatos
  (JNIEnv *env, jobject obj, jstring fecha, jstring monto, jstring folio ){
	
		unsigned char bufe[3];
		
		int errnum;
        char line[100];
		//ABRE PUERTOS
				
		int largoCa;
		
		void *port;

			
		//str = (char *) malloc(largoCa);
		char *strFecha = (*env)->GetStringUTFChars(env, fecha, 0);
		jsize lengthOfStringF =(*env)->GetStringLength(env,fecha);
		
		
		char *strMonto = (*env)->GetStringUTFChars(env, monto, 0);
		jsize lengthOfStringM =(*env)->GetStringLength(env,monto);
		
		
		char *strFolio = (*env)->GetStringUTFChars(env, folio, 0);
		jsize lengthOfStringFo =(*env)->GetStringLength(env,folio);
		
		
		
	
		
		
		
		
		
		
		char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";
		port = aps_create_port(puerto);
		errnum = aps_open(port);

		
		bufe[0]=ESC;
		bufe[1]='R';
		bufe[2]=12;
		
		errnum = aps_write(port,bufe,3);
		errnum = aps_flush(port);
		
		bufe[0]=GS;
		bufe[1]='/';
		bufe[2]=5;
		
		errnum = aps_write(port,bufe,3);
		errnum = aps_flush(port);
		
		
		bufe[0]=ESC;
		bufe[1]='C';
		bufe[2]=0;
		
		errnum = aps_write(port,bufe,3);
		errnum = aps_flush(port);
		
		
		bufe[0]=ESC;
		bufe[1]=0x20;
		bufe[2]=20;
		errnum = aps_write(port,bufe,3);
		errnum = aps_flush(port);
	
		

		
		
		
		
		snprintf(line,sizeof(line),"\n");
		errnum = aps_write(port,line,strlen(line));
		snprintf(line,sizeof(line),"GIVINN SPA3\n");
		errnum = aps_write(port,line,strlen(line));
		snprintf(line,sizeof(line),"79.431.892 - 7\n");
		errnum = aps_write(port,line,strlen(line));
		snprintf(line,sizeof(line),"GIRO: Servicios Integrales de Tecnologia e Informacion\n");
		errnum = aps_write(port,line,strlen(line));
		snprintf(line,sizeof(line),"Los Jesutitas 786, Providencia, Santiago \n");
		errnum = aps_write(port,line,strlen(line));
		snprintf(line,sizeof(line),"\n");
		errnum = aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		
		
		bufe[0]=ESC;
		bufe[1]='C';
		bufe[2]=2;
		
		errnum = aps_write(port,bufe,3);
		errnum = aps_flush(port);
		
		
		snprintf(line,sizeof(line),"   Boleta Numero : ");
		errnum = aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		errnum = aps_write(port,strFolio,lengthOfStringFo);
		errnum = aps_flush(port);
		
		
		snprintf(line,sizeof(line),"\n   Fecha:  ");
		errnum = aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		errnum = aps_write(port,strFecha,lengthOfStringF);
		errnum = aps_flush(port);
		
		
		
		snprintf(line,sizeof(line),"\n");
		errnum = aps_write(port,line,strlen(line));
		errnum = aps_flush(port);

		snprintf(line,sizeof(line),"   Venta             $ ");
		errnum = aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		
		errnum = aps_write(port,strMonto,lengthOfStringM);
		errnum = aps_flush(port);
		
		
		
		
		snprintf(line,sizeof(line),"\n\n\n");
		errnum = aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		
		
		

		
		errnum = aps_close(port);
		errnum = aps_destroy_port(port);
		
		(*env)->ReleaseStringUTFChars(env, fecha, strFecha);
		(*env)->ReleaseStringUTFChars(env, monto, strMonto);
		(*env)->ReleaseStringUTFChars(env, folio, strFolio);
		

     return 1;
 }
 
 
 
 
 
 
void main(){}