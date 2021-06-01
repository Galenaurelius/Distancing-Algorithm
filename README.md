# Distancing-Algorithm
A nlog^2(n) algorithm to find the largest distance possible between individuals for p people and n tables.


Given a straight line of tables or spaces at which one person may sit/stand, what is the maximum distance at which people can be spaced apart? This very simple divide-and-conquer algorithm seeks to solve this very problem by repeatedly dividing the possible range at which people may be spaced apart, checking it, and then adjusting accordingly.

The program will start by taking two inputs, n, representing the number of tables, and p, the number of people to be seated, where 2 <= n <= 10^6, and p <= n. The following n lines will list the distance from the start to each table/space. After all of the tables are input, the program will return the maximum distance in n(log^2(n)) time.
