#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <aps/aps.h>
#include "PrendeLed.h"

static const char ticket[] = "Hello world! GIVINN\n";
static const char** argv;

static void error(const char *s)
{
        fprintf(stderr,"error: %s\n",s);
        exit(1);
}



JNIEXPORT void JNICALL
Java_PrendeLed_Estado(JNIEnv *env, jobject obj, jint led) {
printf("Comenzando Impresión\n");
        
return;
}







