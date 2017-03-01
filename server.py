# TCP server example
import socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(("", 5004))
server_socket.listen(5)

print "TCPServer Waiting for client on port 5004"

while 1:
	client_socket, address = server_socket.accept()
	print "I got a connection from ", address
	
        
        i=0
        l=[]
        while (i<15):
		data = client_socket.recv(10)
		
		list.append(l,data)

		i=i+1
        print "Sorting the given data "        
	l.sort()
	print "Sort complete "
	j=0
	print "Sending the data to client "
	while (j<15):
		data=l[j]
		
		
		client_socket.send(data)
		j=j+1
	print "TRANSFER COMPLETE :" 

		


		

      
                

              
	client_socket.close()
	

                
	
