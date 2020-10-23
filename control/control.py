import socket
port = 8080
ip = '192.168.1.90'
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
while True:
    command = str(input())
    if command == "forward":
        client.connect((ip, port))
        client.send("f")
    elif command == "backward":
        client.connect((ip, port))
        client.send("b")
    elif command == "stop":
        client.connect((ip, port))
        client.send("s")
    elif command == "right":
        client.connect((ip, port))
        client.send("r")
    elif command("left"):
        client.connect((ip, port))
        client.send("l")
    else:
        client.connect((ip, port))
        client.send("s")
    #from_server = client.recv(4096)
    client.close()
    print from_server
