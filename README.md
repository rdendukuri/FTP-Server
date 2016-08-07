# FTP-Server

A concurrent server to handle multiple FTP clients simultaneously. 

FTP client program will enter its command interpreter and wait for instructions from the user.

The commands are as follows.

bye
Terminate the FTP session with the remote server and exit FTP. An
EOF will also terminate the session and exit.

 cd [remote directory]
Change the working directory on the remote machine to .
 cdup
Change the remote machine working directory to the parent of the current
remote machine working directory.

 close
Terminate the FTP session with the remote server, and return to the
command interpreter.

 disconnect
A synonym for close

 help [command]
Print an informative message about the meaning of . If no
argument is given, FTP prints a list of the known commands.

 lcd [directry]
Change the working directory on the local machine. If no is
specified, the user’s home directory is used.

 Open [Ip address} [port]
Establish a connection to the specified FTP server.

pwd
Print the name of the current working directory on the remote machine.

The Usage:

 Server-side:
    $ ./prog5_server 1234
    
 client-side:
 
    $ ./prog5_client
    $ >FTP: Open 127.0.0.1 1234 
    $ >FTP:lcd
      Changed the current directory to "HOME".
