 

 //in_out.c
//NAME: RAHUL KRISHNA DENDUKURI
//ZID:              Z1749863
//Assignment 5
//Due Date :04/28/2015
//CSCI 631 section -1

 #include "wrapper.h"
 #include "in_out.h" 
static ssize_t my_read(int fd,char *ptr);
 
 /**
* ssize_t writen(int fd, const void *vptr, size_t n)
*
* The is writen function writes chunks of data to the socket
*
* @param fd        file descriptor
* @param void *vptr    character array for input buffer 
* @param size_t n   number of bytes
* @return number of bytes written to the socket.
*
*
*****************************************************************************/
 ssize_t writen(int fd, const void *vptr, size_t n)/* Write "n" bytes to a descriptor. */
 {

 	 size_t nleft;
 	 ssize_t nwritten;
 	 const char *ptr;
 	 ptr = vptr;
  	 nleft = n;
         while (nleft > 0) {
 		if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
 			if (nwritten < 0 && errno == EINTR)
 				nwritten = 0; /* and call write() again */
 			else
 				return (-1); /* error */
                 }		
  	nleft -= nwritten;
 	ptr += nwritten;
   	 }	
 	return (n);
 }


  /*
* ssize_t readline(int fd, const void *vptr, size_t maxlen)
*
* The is a function that  reads chunks of data from the socket
*
* @param fd        file descriptor
* @param void *vptr    character array for output buffer
* @param size_t maxlen denotes the maximum number of bytes that can be read
* @return number of bytes written to the socket.
*
*
*****************************************************************************/



static int read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];

ssize_t my_read(int fd,char *ptr){

	if(read_cnt<=0){
		again:
		if((read_cnt=read(fd,read_buf,sizeof(read_buf)))<0){

			if(errno==EINTR)
				goto again;
			return (-1);


		}
	else if(read_cnt==0)
		return 0;
	read_ptr=read_buf;



	}
	read_cnt--;
	*ptr=*read_ptr++;
	return 1;



}


ssize_t readline(int fd,void *vptr,size_t maxlen){

	ssize_t n,rc;
	char c,*ptr;
	ptr=vptr;

	for(n=1;n<maxlen;n++){
		if((rc=my_read(fd,&c))==1){
			*ptr++=c;
			if(c=='\n')
				break;


		}
	else if(rc==0){

		*ptr=0;
		return (n-1);

	}
	else
		return -1;

	}
	*ptr=0;
	return n;


	}
void get_args(char* buf,char* cmd,char*arg1,char* arg2)
{
 //             int i=0;
//		fprintf(stderr,"%s",buf);
                strcat(cmd,strtok(buf," "));
                char* t;
               // while((t=strtok(NULL," "))!=NULL)
               // {
                   //     argv[++i]=t;
//		fprintf(stderr,"%s %s %s",cmd,arg1,arg2);
//		fprintf(stderr,"inside strtok");
		t=strtok(NULL," ");
//		fprintf(stderr,"'%s'",t);
                strcpy(arg1,t);
		if((t=strtok(NULL," "))!=NULL)
	                strcpy(arg2,t);
//		fprintf(stderr,"'%s' '%s' '%s'",cmd,arg1,arg2);
                //}

}

void  get_parent(char* cdir)
{
//	char c='';
	int n=strlen(cdir);
	int i=n-1;
	while(cdir[i]!='/' && i>=0)
		cdir[i--]='\0';
	cdir[i]='\0';
}

char* check_home(char* t)
{
        int i=1;
        char* sh="";
        strcat(sh,getenv("HOME"));
         //strcat(st+strlen(st),s+1);
//      fprintf(stderr,"%s\n",sh);
        if(*t=='~')
        {
         //     t++;
            //    strcat(sh+strlen(sh),t+1);
              //  strcat(t,sh);
                int j=0;
//              while(sh[j++]='\0');
                j=j+strlen(sh);
                while(i<strlen(t))
                {
                        sh[j++]=t[i++];
                }
                sh[j]='\0';
//              free(t);
//              t=0;
//              t=NULL;

//              strcat(t,sh);
  //      fprintf(stderr,"%s\n",sh);
//      i=0;
//      while(sh[i]!='\0')
//              t[i]=sh[i];i++;
//      t[i]='\0';
        return sh;
        }
        else
                return t;
}



