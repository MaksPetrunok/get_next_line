./a.out inp1 > out1
./a.out inp2 > out2
./a.out inp3 > out3
./a.out inp4 > out4
./a.out inp5 > out5
./a.out inp6 > out6
./a.out inp7 > out7
./a.out inp8 > out8
./a.out one_big_fat_line.txt > fat_out

diff inp1 out1
diff inp2 out2
diff inp3 out3
diff inp4 out4
diff inp5 out5
diff inp6 out6
diff inp7 out7
diff inp8 out8
diff one_big_fat_line.txt fat_out

