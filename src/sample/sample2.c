#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <aps/aps.h>
static void error(const char *s)
{
        fprintf(stderr,"error: %s\n",s);
        exit(1);
}
#define gv_flush if((errnum = aps_write(port,"\x1b \x40",3))<0) {error(aps_strerror(errnum));};
#define gv_printf(...) gv_flush;tamano_buffer = sprintf(buffer, __VA_ARGS__);if ((errnum = aps_write(port,buffer,tamano_buffer-1))<0) {error(aps_strerror(errnum));};gv_flush;

int main(int argc,char** argv)
{
        void *port;
        int errnum;
	char puerto[]="aps:/proc/bus/usb?type=usb+vid=0+pid=0";

	if(argc!=2 ){
		printf("canridad de parametros incorrecto (%i)\n", argc);
		return -1;
	}

	printf("Numero de parametros %i\n", argc);
	int i=0;
	for(i=0;i<argc;i++){
		printf("arg %i: %s \n", i, argv[i]);
	}


	char buffer[5000];
	static const char ticket[] = "\x1b \x40 R.U.T. 76.431.892-7\n BOLETA ELECTRONICA";
	
	int tamano_buffer=0;
	//tamano_buffer = sprintf(buffer, "\x1b \x40 R.U.T. 76.431.892-7\n BOLETA ELECTRONICA\n  p1:%s\x1b \x40", argv[1]);

       /* if (argc<2) {
                printf("usage: sample2 uri\n");
                return 0;
        } */
	printf("abriendo port\n");
        /* create communication port from URI */
        port = aps_create_port(puerto);
	printf("por abierto!\n");

        if (port==NULL) {
                error("cannot create port");
        }
        else if ((errnum = aps_get_error(port))<0) {
                error(aps_strerror(errnum));
        }

        /* open communication port */
        if ((errnum = aps_open(port))<0) {
                error(aps_strerror(errnum));
	        printf("bufer\n");
		return -2;
        }

	//imprime
	tamano_buffer=	sprintf(buffer, "\x1b \x40 R.U.T. 76.431.892-7\nBOLETA ELECTRONICABOLETA ELECTRONICA\n p1:%s\x1b \x40", argv[1]);

	if ((errnum = aps_write(port,buffer,tamano_buffer-1))<0) {
                error(aps_strerror(errnum));
		printf("ERROR\n");
	}
	printf("pasado\n");

//	tamano_buffer=	sprintf(buffer, "\x1b \x40 \x1d\x6b\x8holamundo esto es una prueba, por favor. ponga atencion.\0\x1b \x40\niwegbiuwe\n\x1b \x40");
	/*if ((errnum = aps_write(port,buffer,tamano_buffer-1))<0) {
                error(aps_strerror(errnum));
		printf("ERROR\n");
	}*/



        /*if ((errnum = aps_write(port,ticket,sizeof(ticket)-1))<0) {
                error(aps_strerror(errnum));
	} */

        /* close communication port */
        if ((errnum = aps_close(port))<0) {
                error(aps_strerror(errnum));
        }

        /* destroy communication port */
        if ((errnum = aps_destroy_port(port))<0) {
                error(aps_strerror(errnum));
        }
        return 0;
}

