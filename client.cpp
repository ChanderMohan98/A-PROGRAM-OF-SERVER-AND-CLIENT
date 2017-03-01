/* tcpclient.c */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include<fstream>
#include<iostream>

using namespace std;


int main()

{
       
        int sock, bytes_recieved;  
        char send_data[10],recv_data[10];
        struct hostent *host;
        struct sockaddr_in server_addr;  

        host = gethostbyname("127.0.0.1");

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }

        server_addr.sin_family = AF_INET;     
        server_addr.sin_port = htons(5004);   
        server_addr.sin_addr = *((struct in_addr *)host->h_addr);
        bzero(&(server_addr.sin_zero),8); 

        if (connect(sock, (struct sockaddr *)&server_addr,
                    sizeof(struct sockaddr)) == -1) 
        {
            perror("Connect");
            exit(1);
        }
         // reading the file
      
   ifstream fi("data.txt");
   int c=0;
   if(!fi)
    { cout<<"Failed to open file \n";
    }
   
   while(fi)
   { fi.getline(send_data,10);
     cout<<"Data from file "<<send_data <<"\n";
     send(sock,send_data,10, 0); 
   }
   fi.close();

       
        {
         for(int i=0;i<15;i++)
         {
          bytes_recieved=recv(sock,recv_data,10,0);
          recv_data[bytes_recieved] = '\0';
           printf("Recieved data in ascending order= %s \n" , recv_data);
 
          }
          
           close(sock);
           
        
        }   
return 0;
}
