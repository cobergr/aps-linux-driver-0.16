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
      		const char *str = 
		
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
		int primero;
		int segundo;
		char *segundoC, *fin;
		for(i=0;i<4;i++){
			 printf("largo i %d %c \n" , i,largo[i]);
			 if(i<1){
				if(i==0){
					primero = largo[i]-'0';
				
				}else{
					
			 		primero = largo[i]-'0';
				}
				
			 }
			 else{
				if(i==1){
					segundoC[0] = largo[i];
				}else{
					if(i==2){
						segundoC[1] = largo[i];
					}
				}
				
			 }
			  
		}
		
		
		printf(" largo primero %d", primero);
		segundo = strtol(segundoC,&fin,16);
		printf(" largo segundo %d", segundo);
		// CALCULO BUFERS LARGO
		
		
				

		int errnum;
        char line[100];

		//ABRE PUERTOS
		
		char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";
		port = aps_create_port(puerto);
		errnum = aps_open(port);

		//CIERRE PUERTOS
		
		bufe[0]=ESC;
		bufe[1]=0x20;
		bufe[3]=20;
		errnum = aps_write(port,bufe,sizeof(bufe));
		errnum = aps_flush(port);
		
		bufe[0]=ESC;
		bufe[1]='C';
		bufe[3]=0x02;
		errnum = aps_write(port,bufe,sizeof(bufe));
		errnum = aps_flush(port);


		
	
		snprintf(line,sizeof(line),"\n");
		errnum = aps_write(port,line,strlen(line));
		snprintf(line,sizeof(line),"GIVINN SPA \n");
		errnum = aps_write(port,line,strlen(line));
		snprintf(line,sizeof(line),"                        \n\n\n\n\n\n\n\n\n");
		errnum = aps_write(port,line,strlen(line));
		
		errnum = aps_flush(port);

		
		
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
        buf[4] = 2;//error level (0 to 8) (maximum of 5 for the moment),
        buf[5] = 9;//of columns (1 to 30),

		//buf[6] = uno;
		buf[6]=2;
		buf[7] = 194;
		
		int largoTotal=lengthOfString+lengthOfString+8;
		char timbre[largoTotal];
		stpcpy(timbre,buf);
		strcat(timbre,str);
		strcat(timbre,str);
		
		errnum = aps_write(port,timbre,largoTotal);
		errnum = aps_flush(port);
		
		errnum =  aps_write(port,line,strlen(line));
		errnum = aps_flush(port);
		
		printf("antes de cerrar los puertos\n");
		errnum = aps_close(port);
		errnum = aps_destroy_port(port);
		printf("antes del release\n");
		
		(*env)->ReleaseStringUTFChars(env, string, str);
		printf("saliendo ...\n");


        return 0;
}

