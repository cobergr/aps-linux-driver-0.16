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
static int imprime(int argc,char** argv)
{
        void *port;
        int errnum;
        char buf[8];
		char bufe[3];
		//char* lchar =argv[1];
		char* lchar="1414";
		int l= 0;
		sscanf(lchar, "%d", &l);
		
		printf("largo  %d/n", l );
		char timbre[600];
		char timbre2[600];
		char timbre3[l-1200];
		
		memset(&timbre[0], 0, sizeof(timbre));
        memset(&buf[0], 0, sizeof(buf));
		memset(&timbre2[0], 0, sizeof(timbre2));
		memset(&timbre2[0], 0, sizeof(timbre2));
		memset(&timbre3[0], 0, sizeof(timbre3));

 
 
        // int n4;
		// sscanf(argv[3], "%d", &n4);
		// int n5;
		// sscanf(argv[4], "%d", &n5);
		
        /* create communication port from URI */
        /* this must point to a HSP printer on a RS232 port */
		char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";
        /*port = aps_create_port(argv[1]);*/
		port = aps_create_port(puerto);
		char* ted =  "<TED version=1.0><DD><RE>76431892-7</RE><TD>39</TD><F>3</F><FE>2015-07-22</FE><RR>66666666-6</RR><RSR>DALEALBO</RSR><MNT>5000</MNT><IT1>Detalle</IT1><CAF version=1.0><DA><RE>76431892-7</RE><RS>GIVINN SPA</RS><TD>39</TD><RNG><D>1</D><H>10</H></RNG><FA>2015-04-04</FA><RSAPK><M>5TNd7jr+NHGNk1Q83MQYylgSt9ygtIDyvmFyah84RSSSxr/UrS3rb10H/MVv+eIMi976XmNpwG+Mq9W2HoWl9w==</M><E>Aw==</E></RSAPK><IDK>100</IDK></DA><FRMA algoritmo=SHA1withRSA>p7Y+O35toGIXg2f78CcKSZCe7Vv6JkSL6qlJy7wKMqHS4f8+sKpCcLg/SVEiw7gcX8uCIIazj23xcjyjpOhlXw==</FRMA></CAF><TSTED>2015-07-22T11:19:51</TSTED></DD><FRMT algoritmo=SHA1withRSA>qeROQkY3bwt9EEP4yB+UVkTxfNkVkwoQRn8QP6ictQPlpIzmwZte3xK3e2g/nXAloHS/Xj0YdJG12y5QER4PeA==</FRMT></TED><TED version=1.0><DD><RE>76431892-7</RE><TD>39</TD><F>3</F><FE>2015-07-22</FE><RR>66666666-6</RR><RSR>DALEALBO</RSR><MNT>5000</MNT><IT1>Detalle</IT1><CAF version=1.0><DA><RE>76431892-7</RE><RS>GIVINN SPA</RS><TD>39</TD><RNG><D>1</D><H>10</H></RNG><FA>2015-04-04</FA><RSAPK><M>5TNd7jr+NHGNk1Q83MQYylgSt9ygtIDyvmFyah84RSSSxr/UrS3rb10H/MVv+eIMi976XmNpwG+Mq9W2HoWl9w==</M><E>Aw==</E></RSAPK><IDK>100</IDK></DA><FRMA algoritmo=SHA1withRSA>p7Y+O35toGIXg2f78CcKSZCe7Vv6JkSL6qlJy7wKMqHS4f8+sKpCcLg/SVEiw7gcX8uCIIazj23xcjyjpOhlXw==</FRMA></CAF><TSTED>2015-07-22T11:19:51</TSTED></DD><FRMT algoritmo=SHA1withRSA>qeROQkY3bwt9EEP4yB+UVkTxfNkVkwoQRn8QP6ictQPlpIzmwZte3xK3e2g/nXAloHS/Xj0YdJG12y5QER4PeA==</FRMT></TED>";
        //char ted[] ="HOLAHOLAHOLAHOLA";
		//char* ted =argv[2];
		/* open communication port */
        errnum = aps_open(port);

        bufe[0] = GS;
        bufe[1] = 'h';
        bufe[2] = 0x04;


        errnum = aps_write(port,bufe,sizeof(bufe));
	   errnum = aps_flush(port);
		//buf = argv[1];
        buf[0] = GS;
        buf[1] = 'k';
        buf[2] = 8;
  	    buf[3] = 2;
        buf[4] = 5;
        buf[5] = 1;
		// buf[6] = n4;
        // buf[7] = n5;
		buf[6] = 0x02;
        buf[7] = 0xBF;

			
		printf("entrada!\n %s",argv[1] );
		printf("buf  %s" , buf );
		strcpy(timbre, buf);
		 
		int j=8;
		int mitad = l-600;
		for ( j = 8; j < 600; j++ )
              {
                timbre[j]=ted[j-8];
              }

		int h;		
		for ( h = 0; h < 600; h++ )
              {
                timbre2[h]=ted[h + 600-8];
				
              }

		for ( h = 0; h < l-1200; h++ )
              {
                timbre3[h]=ted[h + 1200-8];
				
              }
	  
			  
		timbre[6]=0x02;
		int y;
		for ( y = 0; y < 600; y++ )
              {
                printf( "%c", timbre[y]  );
				if(y<8){
				printf( "%d", timbre[y]  );
				}
                
              } 
			  
		int q;	  
		for ( q = 0; q < l-600; q++ )
              {
                printf( "%c", timbre2[q]  );
	
				}
        for ( q = 0; q < l-1200; q++ )
              {
                printf( "%c", timbre3[q]  );
	
				}
                
              
	  
		
		printf("sizeof %d",sizeof(timbre) );
		printf("sizeof %d",sizeof(timbre2) );
		printf("sizeof %d",sizeof(timbre3) );
        
		
        //errnum = aps_write(port,buf,sizeof(buf));
		
		errnum = aps_write(port,timbre,sizeof(timbre));
		  errnum = aps_flush(port);   
		errnum = aps_write(port,timbre2,sizeof(timbre2));
		  errnum = aps_flush(port);   
        errnum = aps_write(port,timbre3,sizeof(timbre3));
        errnum = aps_flush(port);         
		char line[100];
        snprintf(line,sizeof(line),"                  ");

        aps_write(port,line,strlen(line));
		errnum = aps_flush(port);       
		 
        /* close communication port */
        errnum = aps_close(port);

        /* destroy communication port */
        errnum = aps_destroy_port(port);
		
		printf("por abierto!\n %d",errnum );

        return 0;
}

