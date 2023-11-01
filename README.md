# An example of interprocess communication using C++ Message queue

Here is an example showing how to create a message queue for inter-process communication using the boost library

## First compile the application in the following two steps. The project uses cmake to manage the C++ source code:

1. cmake .
2. make

After compilation, the executable file "message_queue_comm.exe" will be generated. Then start testing the communication through the message queue

## Run the executable file in the terminal:

./message_queue_comm.exe

Output :

The parent process creates 3 child processes with different IDs. <br />
The parent process sends 10 messages to each child process. <br />
Child process 2 receives a message: {Msg Id:0, Msg Content: Job 0}<br />
Child process 1 receives a message: {Msg Id:0, Msg Content: Job 0}<br />
Child process 1 receives a message: {Msg Id:1, Msg Content: Job 1}<br />
Child process 2 receives a message: {Msg Id:1, Msg Content: Job 1}<br />
Child process 2 receives a message: {Msg Id:2, Msg Content: Job 2}<br />
Child process 1 receives a message: {Msg Id:2, Msg Content: Job 2}<br />
Child process 2 receives a message: {Msg Id:3, Msg Content: Job 3}<br />
Child process 1 receives a message: {Msg Id:3, Msg Content: Job 3}<br />
Child process 0 receives a message: {Msg Id:0, Msg Content: Job 0}<br />
Child process 2 receives a message: {Msg Id:4, Msg Content: Job 4}<br />
Child process 1 receives a message: {Msg Id:4, Msg Content: Job 4}<br />
Child process 2 receives a message: {Msg Id:5, Msg Content: Job 5}<br />
Child process 0 receives a message: {Msg Id:1, Msg Content: Job 1}<br />
Child process 1 receives a message: {Msg Id:5, Msg Content: Job 5}<br />
Child process 2 receives a message: {Msg Id:6, Msg Content: Job 6}<br />
Child process 0 receives a message: {Msg Id:2, Msg Content: Job 2}<br />
Child process 2 receives a message: {Msg Id:7, Msg Content: Job 7}<br />
Child process 1 receives a message: {Msg Id:6, Msg Content: Job 6}<br />
Child process 0 receives a message: {Msg Id:3, Msg Content: Job 3}<br />
Child process 2 receives a message: {Msg Id:8, Msg Content: Job 8}<br />
Child process 1 receives a message: {Msg Id:7, Msg Content: Job 7}<br />
Child process 0 receives a message: {Msg Id:4, Msg Content: Job 4}<br />
Child process 2 receives a message: {Msg Id:9, Msg Content: Job 9}<br />
Child process 1 receives a message: {Msg Id:8, Msg Content: Job 8}<br />
Child process 0 receives a message: {Msg Id:5, Msg Content: Job 5}<br />
Child process 2 receives a message: {Msg Id:-1, Msg Content: Nil}<br />
Child process 2 exits<br />
Child process 1 receives a message: {Msg Id:9, Msg Content: Job 9}<br />
Child process 0 receives a message: {Msg Id:6, Msg Content: Job 6}<br />
Child process 1 receives a message: {Msg Id:-1, Msg Content: Nil}<br />
Child process 0 receives a message: {Msg Id:7, Msg Content: Job 7}<br />
Child process 1 exits<br />
Child process 0 receives a message: {Msg Id:8, Msg Content: Job 8}<br />
Child process 0 receives a message: {Msg Id:9, Msg Content: Job 9}<br />
Child process 0 receives a message: {Msg Id:-1, Msg Content: Nil}<br />
Child process 0 exits<br />
Destroy message queue: message_queue_2<br />
Destroy message queue: message_queue_1<br />
Destroy message queue: message_queue_0<br />
Parent process exits.<br />

