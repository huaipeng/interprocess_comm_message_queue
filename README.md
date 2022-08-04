# message queue example

first compile the application:

1. cmake .
2. make

after the compilation, an executable file 'test_boost_message_queue' will be generated. then start to test the communication via message queues

type the following command in a terminal :

./test_boost_message_queue

output :

parent simulator creates 3 children <br />
parent simulator sends 10 to each child <br />
child simulator 1 picks a message {task:0, content: job 0}<br />
child simulator 2 picks a message {task:0, content: job 0}<br />
child simulator 2 picks a message {task:1, content: job 1}<br />
child simulator 0 picks a message {task:0, content: job 0}<br />
child simulator 0 picks a message {task:1, content: job 1}<br />
child simulator 0 picks a message {task:2, content: job 2}<br />
child simulator 1 picks a message {task:1, content: job 1}<br />
child simulator 1 picks a message {task:2, content: job 2}<br />
child simulator 1 picks a message {task:3, content: job 3}<br />
child simulator 0 picks a message {task:3, content: job 3}<br />
child simulator 1 picks a message {task:4, content: job 4}<br />
child simulator 2 picks a message {task:2, content: job 2}<br />
child simulator 2 picks a message {task:3, content: job 3}<br />
child simulator 2 picks a message {task:4, content: job 4}<br />
child simulator 0 picks a message {task:4, content: job 4}<br />
child simulator 0 picks a message {task:5, content: job 5}<br />
child simulator 0 picks a message {task:6, content: job 6}<br />
child simulator 2 picks a message {task:5, content: job 5}<br />
child simulator 1 picks a message {task:5, content: job 5}<br />
child simulator 1 picks a message {task:6, content: job 6}<br />
child simulator 1 picks a message {task:7, content: job 7}<br />
child simulator 0 picks a message {task:7, content: job 7}<br />
child simulator 1 picks a message {task:8, content: job 8}<br />
child simulator 2 picks a message {task:6, content: job 6}<br />
child simulator 2 picks a message {task:7, content: job 7}<br />
child simulator 2 picks a message {task:8, content: job 8}<br />
child simulator 0 picks a message {task:8, content: job 8}<br />
child simulator 0 picks a message {task:9, content: job 9}<br />
child simulator 0 picks a message {task:-1, content: ending}<br />
child simulator 0 exits<br />
remove message queue message_queue_0<br />
child simulator 1 picks a message {task:9, content: job 9}<br />
child simulator 1 picks a message {task:-1, content: ending}<br />
child simulator 1 exits<br />
remove message queue message_queue_1<br />
child simulator 2 picks a message {task:9, content: job 9}<br />
child simulator 2 picks a message {task:-1, content: ending}<br />
child simulator 2 exits<br />
remove message queue message_queue_2<br />
parent simulator exits<br />

