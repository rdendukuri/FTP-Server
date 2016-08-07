//query.c
//NAME:           RAHUL KRISHNA DENDUKURI
//ZID:              Z1749863
//Assignment 5
//Due Date :04/28/2015
//CSCI 631 section -1
#include "wrapper.h"
#include "in_out.h"
#include "query.h"
/**
* int doQuery(int sock, const char *in)
*
* The is a function that  reads chunks of data from the socket
*
* @param int sock        file descriptor
* @param char *in    character array for accepting input from client side
*
*
*****************************************************************************/
void doQuery(int sockfd)
{
	  
//	char** argv[];
	char st[MAXLINE];
	char in_buf[MAXLINE];
        
		
         //        usage("Invalid arguments");
	//	int i=0;
//		argv[i]=strtok(in," ");
//		char* t;
	fprintf(stderr,"Ftp>:");	
		while(w_fgets(in_buf, sizeof(in_buf), stdin)!=NULL)
        	{

                	trim(in_buf);
                	if(!(strcmp(in_buf,"bye"))||!(strcmp(in_buf,"close"))||!(strcmp(in_buf,"disconnect")))
                        	break;
//	                doQuery(sockfd,in_buf);//client function call
			else if(!strncmp(in_buf,"cd ",3))
			{
				writen(sockfd,in_buf,strlen(in_buf));
				writen(sockfd,"\n",1);
				readline(sockfd,st,MAXLINE);
				trim(st);
				if(strcmp(st,"unknown directory")!=0)
					fprintf(stderr,"Current directory at server changed to '%s'\n",st);	
				else
					fprintf(stderr,"The directory doesn't exist\n");
			}
			else if(!strcmp(in_buf,"cdup"))
			{
//				cdup(sockfd);
				writen(sockfd,in_buf,strlen(in_buf));
                                writen(sockfd,"\n",1);
//                                readline(sockfd,st,MAXLINE);
//				fprintf(stderr,"changed to parent directory\n");
				  readline(sockfd,st,MAXLINE);
                                trim(st);
                                if(strcmp(st,"unknown directory")!=0)
                                        fprintf(stderr,"changed to parent directory '%s'\n",st);
                                else
					 fprintf(stderr,"The directory doesn't exist\n");

				
				
			}
			else if(!strncmp(in_buf,"lcd ",4)||!strcmp(in_buf,"lcd"))
			{
				if(!strcmp(in_buf,"lcd"))
				{
				//	t=getenv("HOME");
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

				//	get_args(in_buf,cmd,arg1,(char*) NULL);
					
					if(chdir(s)<0)
						fprintf(stderr,"Could not change the directory\n");
				}
				
			}
			else if(!strcmp(in_buf,"pwd"))
			{
				fprintf(stderr,"pwds is '%s'",in_buf);
				writen(sockfd,in_buf,strlen(in_buf));
                                writen(sockfd,"\n",1);
				readline(sockfd,st,MAXLINE);
				trim(st);
				fprintf(stderr,"The current directory is '%s'\n",st);
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
					fprintf(stderr,"Wrong command");
				}
	
				
				
			}
			else
				fprintf(stderr,"The command %s doesnot exist",in_buf);

			
			 
			
        	        fprintf(stderr,"Ftp>:");
                }

	


//	if(strcmp
//	writen(sock, in, strlen(in));
//	writen(sock,"\n",1);

 }

