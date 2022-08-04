# message queue example

first compile the application:

1. cmake .
2. make

after the compilation, an executable file 'test_boost_message_queue' will be generated. then start to test the communication via message queues

type the following command in a terminal :

./test_boost_message_queue

output :

parent simulator creates 3 children
parent simulator sends 10 to each child
child simulator 1 picks a message {task:0, content: job 0}
child simulator 2 picks a message {task:0, content: job 0}
child simulator 2 picks a message {task:1, content: job 1}
child simulator 0 picks a message {task:0, content: job 0}
child simulator 0 picks a message {task:1, content: job 1}
child simulator 0 picks a message {task:2, content: job 2}
child simulator 1 picks a message {task:1, content: job 1}
child simulator 1 picks a message {task:2, content: job 2}
child simulator 1 picks a message {task:3, content: job 3}
child simulator 0 picks a message {task:3, content: job 3}
child simulator 1 picks a message {task:4, content: job 4}
child simulator 2 picks a message {task:2, content: job 2}
child simulator 2 picks a message {task:3, content: job 3}
child simulator 2 picks a message {task:4, content: job 4}
child simulator 0 picks a message {task:4, content: job 4}
child simulator 0 picks a message {task:5, content: job 5}
child simulator 0 picks a message {task:6, content: job 6}
child simulator 2 picks a message {task:5, content: job 5}
child simulator 1 picks a message {task:5, content: job 5}
child simulator 1 picks a message {task:6, content: job 6}
child simulator 1 picks a message {task:7, content: job 7}
child simulator 0 picks a message {task:7, content: job 7}
child simulator 1 picks a message {task:8, content: job 8}
child simulator 2 picks a message {task:6, content: job 6}
child simulator 2 picks a message {task:7, content: job 7}
child simulator 2 picks a message {task:8, content: job 8}
child simulator 0 picks a message {task:8, content: job 8}
child simulator 0 picks a message {task:9, content: job 9}
child simulator 0 picks a message {task:-1, content: ending}
child simulator 0 exits
remove message queue message_queue_0
child simulator 1 picks a message {task:9, content: job 9}
child simulator 1 picks a message {task:-1, content: ending}
child simulator 1 exits
remove message queue message_queue_1
child simulator 2 picks a message {task:9, content: job 9}
child simulator 2 picks a message {task:-1, content: ending}
child simulator 2 exits
remove message queue message_queue_2
parent simulator exits

