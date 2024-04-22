#!/bin/bash
make
gnuplot -p -e "plot '< ./sorting 1 200 2' using 1:3 with lines title 'iSort', '' using 1:2 with lines title 'mSort'"

