#!/bin/bash
for timestep in {320..2880..320}
do
    g++ LINADV_v1.cpp
    ./a.out $timestep
    mv LINADV_data.txt LINADV_data_$timestep.txt
done
mv LINADV_data_* 2.3_Data
