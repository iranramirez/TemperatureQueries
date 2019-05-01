# TemperatureQueries

This program allows you to input a data file as the first argument in your CLI. The data file should look like the following:

411048 2015 1 9.58
411048 2015 3 14.82
411048 2016 4 20.51
411048 2016 1 10.99
411000 1973 1 0.54
411048 2016 3 18.40
411048 2016 5 -99.99

The data represents City ID, year, month, and temperature respectively. The program creates a linked list that orders the data by City ID, year, month, and temperature. We then can input a query file as the second CLI argument that should look like the following:

411048 AVG 2015 2016
411138 AVG 1995 1995
411048 MODE 2015 2016

The query file represents city ID, calculation (Average or Mode), and year range (yearOne and yearTwo). The example of the query file will cause the program to create an output file named "result.dat" which should return something like the following:

411048 2015 2016 AVG 14.86
411138 1995 1995 AVG unknown
411048 2015 2016 MODE 21

The output file represents city ID, year range (yearOne and yearTwo), calculation (Average or Mode), and result.
