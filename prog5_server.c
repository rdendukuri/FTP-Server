
//NAME:           RAHUL KRISHNA DENDUKURI
//ZID:              Z1749863
//Assignment 5
//Due Date :04/28/2015
//CSCI 631 section -1
#include "wrapper.h"
#include "serv.h"
/**
* static void usage(char *msg)
*
* The is the usage function for server
*
* @param char* msg       error message to printed
* @return void
*
*
*****************************************************************************/

static void usage(char *msg){
        if(msg)
                w_fputs(msg,stderr);
        fprintf(stderr,"\nusage:prog2_server [port number]\n");
        exit(1);

}

/**
* int main(int argc,char **argv)
*
* The is the main function of the server
*
* @param int argc       number of arguments
* @param char **argv    array of pointers for command line arguments
* @return integer
*
*
*****************************************************************************/

int main(int argc,char **argv)
{
	if (argc!=2)
{

    usage("Invalid number of arguments");

}
	doServ(atoi(argv[1]));//calling the server funcions
	return 0;

}
