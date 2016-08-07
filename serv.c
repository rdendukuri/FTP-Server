//serv.c
//NAME:           RAHUL KRISHNA DENDUKURI
//ZID:              Z1749863
//Assignment 5
//Due Date :04/28/2015
//CSCI 631 section -1
#include "wrapper.h"
#include "serv.h"
#include "in_out.h"
#include "math.h"
static void exponent(int sock);
typedef void Sigfunc(int);
void sig_chld(int);
/**
* int doServ(uint16_t port)
*
* The is function is for server side socket connection 
* @param uint16_t port       port number for server connection
* @return integer
*
*
*****************************************************************************/
int doServ(uint16_t port){
	int listenfd,connfd;/*for socket file descriptor and connection descriptor*/
//	struct linger s;
//	 s.l_onoff = 1;
  //       s.l_linger = 10;
	
	pid_t childpid;//child process ID
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;//to store server details
	listenfd=socket(AF_INET,SOCK_STREAM,0);//connect to a socket
	bzero(&servaddr,sizeof(servaddr)); //set server address structure to 0
	servaddr.sin_family=AF_INET;//uses IPV4
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//ready for listening for connections
	servaddr.sin_port=htons(port);/*set port to Book SERVER*/
	w_bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)); //bind the port to the socket
	w_listen(listenfd,LISTENQ);//listen for connections
        Sigfunc *old=w_Sigaction(SIGCHLD ,sig_chld);
	while(1)
	{
		clilen=sizeof(cliaddr);
		if((connfd=accept(listenfd,(struct sockaddr *)&cliaddr,&clilen))<0){//if connect problem
		     if(errno == EINTR || errno == ECONNABORTED )//check for interrupts and aborts
			continue;
		 else
                	fprintf(stderr,"accept error:%s",strerror(errno));
			}	
	if((childpid= fork())==0){
		w_Sigaction(SIGCHLD ,old);
		w_close(listenfd);
		exponent(connfd);//matching of the title entered with the records in the database
		
//		setsockopt(connfd,SOL_SOCKET,SO_LINGER, &s, sizeof(s));
 		w_close(connfd);
		exit(0);
		}
	 w_close(connfd);
		}				
	}
/**
* int exponentint sock)
*	
* This function shall contain a loop that will perform the service operation for a single connected client. 
* It will read a plurality of text lines one at-a-time from the client socket. Each text line shall represent a number in the series. 
* @param int sock       file descriptor
* @return void
*
*
*****************************************************************************/
void exponent(int sock){

//	double  i=0.00;
//	double k=0.0;
	char a[MAXLINE];
//	int n=0;
//	fprintf(stderr,"heyy baby\n");
        while(readline(sock,a,MAXLINE+1)>0)
	{
		trim(a);
		if(!strcmp(a,"pwd"))
		{
			char st[MAXLINE]; 
			//getcwd(st,MAXLINE);
			writen(sock,getcwd(st,MAXLINE),strlen(getcwd(st,MAXLINE)));
			writen(sock,"\n",1);
		}
		else if(!strncmp(a,"cd ",3))
		{
		//	fprintf(stderr,"Fgfh");
			 char cmd[100];
                         char arg1[100];
			char arg2[100];
                         get_args(&a[0],&cmd[0],&arg1[0],&arg2[0]);
			
//			fprintf(stderr,"the arg1 is '%s'",arg1);
		//	arg1=check_home(arg1);
		//	fprintf(stderr,"the arg1 is '%s'",check_home(&arg1[0]));
			char* str=getenv("HOME");
			char* s=arg1;
			if(*arg1=='~')
				strcat(str+strlen(str),arg1+1);s=str;
			 //fprintf(stderr,"the arg1 is '%s'",check_home(str));
                         if(chdir(s)<0)
                         {	
				writen(sock,"unknown directory",17);
				writen(sock,"\n",1);
                          }      
                          else
                          {
                                writen(sock,arg1,strlen(arg1));
                                writen(sock,"\n",1);

                          }
	
		}
		else if(!strcmp(a,"cdup"))
		{
			char* t=getcwd(NULL,MAXLINE);
			get_parent(t);
			 if(chdir(t)<0)
                         {
                                writen(sock,"unknown directory",17);
                                writen(sock,"\n",1);
                          }
                          else
                          {
                                writen(sock,t,strlen(t));
                                writen(sock,"\n",1);

                          }
	
			
		}
	//	else
			

		

	}
//	sprintf(a,"%f",i);
//	writen(sock,a,strlen(a));
//	writen(sock,"\n",1);//send a new line

}


/**
* void sig_chld(int signo)
*
* The is function is for signal handlinf when a SIGHLD signal recieved
* @param int signo       Signal number corresponding to SIGCHLD
* @return void
*
*
*****************************************************************************/
void sig_chld(int signo){
	pid_t pid;
	int stat;
	while((pid=waitpid(-1,&stat,WNOHANG))>0);
//		printf("child %d terminated",pid);//waiting for all the child processes to be reaped
	return;
}
