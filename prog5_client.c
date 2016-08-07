

//prog5_client.c
//NAME:           RAHUL KRISHNA DENDUKURI
//ZID:              Z1749863
//Assignment 5
//Due Date :04/28/2015
//CSCI 631 section -1


#include "wrapper.h"
#include "in_out.h"
#include "query.h"

/**
* static void usage(char *msg)
*
* The is the usage function for client
*
* @param char* msg       error message to printed
* @return void
*
*
*****************************************************************************/


static void usage(char *msg){
        if(msg)
                w_fputs(msg,stderr);
        fprintf(stderr,"\nusage:prog5_client\n");
        exit(1);


}
/**
* int main(int argc,char **argv)
*
* The is the main function of the client
*
* @param int argc       number of arguments
* @param char **argv    array of pointers for command line arguments
* @return integer
*
*
*****************************************************************************/
int main(int argc, char **argv)
{
	int sockfd;
	char in_buf[MAXLINE];
	struct sockaddr_in servaddr;
//	struct hostent *hp;

	if (argc>1)
	{

   		 usage("Invalid arguments");
	}
	
/*	sockfd=w_socket(AF_INET,SOCK_STREAM,0);//create a socket
	memset(&servaddr,0,sizeof(servaddr));//zero-out 
	servaddr.sin_family=AF_INET;//set address family 
	const char* s1=argv[1];
	hp = w_gethostbyname(s1);
	bcopy( hp->h_addr, &(servaddr.sin_addr.s_addr), hp->h_length);
	servaddr.sin_port=htons(atoi(argv[2]));

	w_connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));//connect to the server*/

	fprintf(stderr,"Ftp>:");
	while(w_fgets(in_buf, sizeof(in_buf), stdin)!=NULL)
	{
		
		trim(in_buf);
		if(!(strcmp(in_buf,"bye"))||!(strcmp(in_buf,"close"))||!(strcmp(in_buf,"disconnect")))
			break;
		else if(!strncmp(in_buf,"open [] []",4) && strlen(in_buf)>4)
		{
//			fprintf(stderr,"inbufff '%s'",in_buf);
			char cmd[100];
			char arg1[100];
			char arg2[100];
			get_args(&in_buf[0],&cmd[0],&arg1[0],&arg2[0]);
//			 fprintf(stderr,"'%s' '%s' '%s'",cmd,arg1,arg2);
			  sockfd=w_socket(AF_INET,SOCK_STREAM,0);//create a socket
		        memset(&servaddr,0,sizeof(servaddr));//zero-out
		        servaddr.sin_family=AF_INET;//set address family
		        char* s1=arg1;
//		        hp = w_gethostbyname(s1);
//			fprintf(stderr,"The host is %s",s1);
			w_inet_pton(AF_INET,s1,&servaddr.sin_addr);//convert the IP address from ASCII to numeric format
//		        bcopy( hp->h_addr, &(servaddr.sin_addr.s_addr), hp->h_length);
		        servaddr.sin_port=htons(atoi(arg2));

		        w_connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));//connect to the server

		
			doQuery(sockfd);//client function call
			w_close(sockfd);
		}
		  else if(!strncmp(in_buf,"lcd ",4)||!strcmp(in_buf,"lcd"))
                        {
                                if(!strcmp(in_buf,"lcd"))
                                {
                                //      t=getenv("HOME");
                                        if(chdir(getenv("HOME"))<0)
                                                fprintf(stderr,"Could not change the directory\n");
                                        else
                                                fprintf(stderr,"Changed to 'HOME' directory on local machine\n");
                                }
                                else
                                {
                                        char cmd[100];
                                        char arg1[100];
                                        get_args(in_buf,cmd,arg1,(char*) NULL);
                                   char* str=getenv("HOME");
                                        char* s=arg1;
                                 if(*arg1=='~')
                                        strcat(str+strlen(str),arg1+1);s=str;

                                //      get_args(in_buf,cmd,arg1,(char*) NULL);

                                        if(chdir(s)<0)
                                                fprintf(stderr,"Could not change the directory\n");
                                }

                        }
		   else if(!strncmp(in_buf,"help ",5) || !(strncmp(in_buf,"? ",2)))
                        {
                                strtok(in_buf," ");
                                char* str=strtok(NULL," ");
                                if(!strcmp(str,"open"))
                                {
                                }
                                else if(!strcmp(str,"close"))
                                {
                                }



                                else
                                {
                                        fprintf(stderr,"Wrong command\n");
                                }



                        }

		else if(!strcmp(in_buf,"pwd") || !strcmp(in_buf,"cdup") || !strcmp(in_buf,"cd") || !strncmp(in_buf,"cd ",3))

		{
			fprintf(stderr,"Not connceted to server to execute : %s \n",in_buf);
	
		}
		else
		{
			fprintf(stderr,"wrong command\n");
		}
		 fprintf(stderr,"Ftp>:");		
		//strcpy(in_buf),"")
//		strcpy(in_buf,"'\0'");
		int i=0;
		while(i<strlen(in_buf))
			in_buf[i++]='\0';		
	//	free(in_buf);
		//in_buf=NULL;
	}

/*	w_shutdown(sockfd,SHUT_WR);//shutdown the write-side of the socket

	char st[MAXLINE];

	readline(sockfd,st,MAXLINE);

	trim(st);
	
	  printf("sum of exponents:%s\n",st);*/

	 // w_close(sockfd); //close sockeet

	exit(0);
}

                 

