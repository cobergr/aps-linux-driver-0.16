/******************************************************************************
* COMPANY       : APS ENGINEERING
* PROJECT       : LINUX DRIVER
*******************************************************************************
* NAME          : sample5.c
* DESCRIPTION   : Demonstrates custom high-speed baudrates for HSP printer
* CVS           : $Id: sample5.c,v 1.1 2007/12/10 15:14:36 nicolas Exp $
*******************************************************************************
* HISTORY       :
*   06apr2007   nico    Initial revision
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <aps/aps.h>

/* PRIVATE DEFINITIONS ------------------------------------------------------*/

#define ESC     27
#define GS      29

/* PRIVATE FUNCTIONS --------------------------------------------------------*/

/*-----------------------------------------------------------------------------
Name      :  print_ticket
Purpose   :  Print test ticket (100 lines)
Inputs    :  port : port structure
Outputs   :  <>
Return    :  APS_OK or negative error code
-----------------------------------------------------------------------------*/

/* PUBLIC FUNCTIONS ---------------------------------------------------------*/

/*-----------------------------------------------------------------------------
Name      :  main
Purpose   :  Program main function
Inputs    :  argc : number of command-line arguments (including program name)
             argv : array of command-line arguments
Outputs   :  <>
Return    :  0 if successful, 1 if program failed
-----------------------------------------------------------------------------*/
int main(int argc,char** argv)
{		
		unsigned char buf[9];
		unsigned char bufe[3];
		int errnum;
        char line[100];
		//ABRE PUERTOS
		
		char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";
		char *str;
		str = (char *) malloc(706);
		str ="<TED version=\"1.0\"><DD><RE>76431892-7</RE><TD>39</TD><F>1</F><FE>2015-05-01</FE><RR>77157050-K</RR><RSR>DALEALBO</RSR><MNT>60000</MNT><IT1>Detalle</IT1><CAF version=1.0><DA><RE>76431892-7</RE><RS>GIVINN SPA</RS><TD>39</TD><RNG><D>1</D><H>10</H></RNG><FA>2015-04-04</FA><RSAPK><M>5TNd7jr+NHGNk1Q83MQYylgSt9ygtIDyvmFyah84RSSSxr/UrS3rb10H/MVv+eIMi976XmNpwG+Mq9W2HoWl9w==</M><E>Aw==</E></RSAPK><IDK>100</IDK></DA><FRMA algoritmo=SHA1withRSA>p7Y+O35toGIXg2f78CcKSZCe7Vv6JkSL6qlJy7wKMqHS4f8+sKpCcLg/SVEiw7gcX8uCIIazj23xcjyjpOhlXw==</FRMA></CAF><TSTED>2015-07-07T13:14:43</TSTED></DD><FRMT algoritmo=SHA1withRSA>y1GxPVo3k83So+zpfOngKwAPEfgQr1mDPZkShZhIm1Gv+dIFRsH7AMpRIMDN7gReKSME9SpWDzyoiCGPh5qNxQ==</FRMT></TED>";
		void *port;
		// CALCULO BUFERS LARGO
		
		int largoCa;
		int lengthOfString;
		largoCa=706;
		lengthOfString=706;
		printf(" lengthOfString %d",lengthOfString); 
		printf(" lengthOfString %s",str); 
		int i=0;
		char largo[4] ;
		snprintf( largo, 4, "%x", largoCa );
		printf( "largo string %s ", largo);
		int primero;
		int segundo;
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
		primero=2;
		segundo = 196;//strtol(segundoC,&fin,16);
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
		for(sec =0; sec<400000 ;sec++)
			if(sec>399990)
				printf(" %d ",sec);
		
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
        buf[5] = 10;//of columns (1 to 30),

		//buf[6] = uno;
		buf[6]=2;
		buf[7] = 194;
		buf[8] = NULL;
		
		
		int largoTotal=lengthOfString+lengthOfString+8+1;
		char *timbre;
		timbre = (char *) malloc(largoTotal);
		stpcpy(stpcpy(stpcpy(timbre,buf),str),str);
		int cont;
		for(cont =0;cont<largoTotal;cont++)
			printf("Car%d,%c,%x ",timbre[cont],timbre[cont],timbre[cont]);
		printf("\n\n timbre largo %s \n",timbre);
		errnum = aps_write(port,timbre,largoTotal);
		errnum = aps_flush(port);
		
		free(timbre);
		
		snprintf(line,sizeof(line),"                        \n\n\n\n\n\n\n\n\n");
		errnum =  aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		printf("antes de cerrar los puertos\n");
		errnum = aps_close(port);
		errnum = aps_destroy_port(port);
		printf("antes del release\n");
		
	
		printf("saliendo ...\n");


        return 0;
}

