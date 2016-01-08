/******************************************************************************
* COMPANY       : APS ENGINEERING
* PROJECT       : LINUX DRIVER
*******************************************************************************
* NAME          : sample1.c
* DESCRIPTION   : Basic sample of libaps use
* CVS           : $Id: sample1.c,v 1.5 2007/12/10 15:14:36 nicolas Exp $
*******************************************************************************
* HISTORY       :
*   08mar2006   nico    Initial revision
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <aps/aps.h>
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
		unsigned char reset[2];
		
		char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";


		// ESC @
// Description: Resets printer
// Format: <1Bh> <40h>
	
		// reset[0]=0x1B;
		// reset[1]=0x40;
		// errnum = aps_write(port,reset,sizeof(reset));
	   // errnum = aps_flush(port);
		port = aps_create_port(puerto);
		errnum = aps_open(port);
		
		reset[0]=0x1B;
		reset[1]=0x40;
		errnum = aps_write(port,reset,sizeof(reset));
	    errnum = aps_flush(port);


       
		/* close communication port */
        errnum = aps_close(port);

        /* destroy communication port */
        errnum = aps_destroy_port(port);

        return 0;
}

