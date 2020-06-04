# Assignment PA1

## Michael Rivnak

A. Start by sending a single value around the ring (a single integer) and confirm that your program is working correctly. As shown below where N ranks exist, rank 0 would send the number 0 to rank 1 (rank 1 would increment the number by 1) and then send the number to rank 2 (which in turn increments the number by 1) and sends it to the next rank, etc. Finally, rank 0 receives the number, which should be N-1, and displays the number.

B) Try sending a larger structure, like an array, and time (use the MPI_Wtime() function) how long it takes to travel between nodes. The size of the array should be large, ~1GB. Use this information to compute the bandwidth of the network.



C) After you have the token ring working, write a similar code that ping pongs between each rank and rank 0. For example, send data from 0 to 1 then back to 0, then 0 to 2 and back to 0, etc. as shown in the figure below. 