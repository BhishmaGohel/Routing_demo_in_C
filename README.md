# Routing_demo_in_C
This repository is having one main.c code which basically giving the demo of static routing using C language.

Assumptions:
<br>
1.Here we are assuming that network is having 4 router connected with each other in ring topology.
<br>
2.the network is fixed.<br>
3.once the ip of nodes which connected to router than it will not change in future

abstract about code:

1.Functions:<br>
1.1 concat:To concatinate two string in C<br>
1.2 validate_number:To validate number for ip address<br>
1.3 validate_ip: To validate structure of ip address<br>

2.stuctures:<br>
2.1 a:1D array of structure node which is having 2D array of character to store ip addresses for each router.<br>
2.2 n:2D array of size 16 and type int is used to save structure of network<br>
2.3 num:1D array of size 4 and type int is used to save how many nodes is connected to one router<br>
2.4 sc:pointer of type char to store ip addresses for calculations.<br>
2.5 sd:To store data of inter mediate step.<br>
