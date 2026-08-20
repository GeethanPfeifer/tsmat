Instructions:

READ    REG     DEVICE
SEND    REG     DEVICE
ADD     REG     INT
IF      REG     LABEL

EMPTY   0       0
PUSH    REG     0
READ    REG     0

LABEL   NAME    0
HALT    0       0



How it accomplishes stuff:
    - creates a bunch of threads
    - each thread runs an interpreter (or compiled? might be easier)
    - runs until all the threads have sent halt signals
