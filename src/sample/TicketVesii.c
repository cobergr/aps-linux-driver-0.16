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
static int print_ticket(void *port, int numero, char* monto)
{
        int errnum;
        int i;
        char line[100];
		char buf[3];

				
                	// }
				
				buf[0]=ESC;
				buf[1]=0x20;
				buf[3]=20;
				errnum = aps_write(port,buf,sizeof(buf));
				printf("buf  %s" , buf );
				errnum = aps_flush(port);
				
				buf[0]=ESC;
				buf[1]='C';
				buf[3]=0x02;
				errnum = aps_write(port,buf,sizeof(buf));
				printf("buf  %s" , buf );
				errnum = aps_flush(port);
				
				snprintf(line,sizeof(line),"                        \n");
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"GIVINN SPA\n");
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"Proyecto VESII\n");
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"Giro: SERVICIOS INTEGRALES DE TECNOLOGIA\n");
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"Los Jesuitas 786, Providencia, Santiago\n");
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"                               \n");
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"                               \n");
				errnum = aps_write(port,line,strlen(line));
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"Boleta Electrónica N: %d", i);
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"\n\n\n");
				errnum = aps_write(port,line,strlen(line));
				errnum = aps_flush(port);


				
				
				buf[0]=ESC;
				buf[1]='C';
				buf[3]=0x02;
				errnum = aps_write(port,buf,sizeof(buf));
				errnum = aps_flush(port);
				
				
				snprintf(line,sizeof(line),"Venta :            %c %s\n",36, monto);
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"              Total %c %s\n",36, monto);
				errnum = aps_write(port,line,strlen(line));
				snprintf(line,sizeof(line),"\n\n\n");
				errnum = aps_write(port,line,strlen(line));
				errnum = aps_flush(port);
				
				
				
				//errnum = impresor(port,line,strlen(line));
                
}



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
        void *port;
        int errnum;
        unsigned char buf[3];
		if (argc<2) {
                printf("Usage: sample5 URI\n");
                exit(0);
        }
        
		char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";
        /*port = aps_create_port(argv[1]);*/
		port = aps_create_port(puerto);

        /* open communication port */
        errnum = aps_open(port);

		printf( "%s", argv[1]  );
	
	// Maxima Velcidad
	    buf[0] = GS;
        buf[1] = 0x2F;
        buf[2] = 0x1D;
        errnum = aps_write(port,buf,sizeof(buf));
		errnum = aps_flush(port);

		
		// GS D n
		// Description: Set print Intensity
		// Format: <1Dh> <44h> <n>
		// n=80h (128d) : (Default). Nominal print intensity
		// n>80h (128d) : Printout becomes darker
		// n<80h (128d) : Printout becomes lighter
		
	     // buf[0] = GS;
         // buf[1] = 0x44;
         // buf[2] = 0x80;
         // errnum = aps_write(port,buf,sizeof(buf));
	     // errnum = aps_flush(port);


        errnum = print_ticket(port, 9, argv[1]);

        
        /* close communication port */
        errnum = aps_close(port);

        /* destroy communication port */
        errnum = aps_destroy_port(port);

        return 0;
}

