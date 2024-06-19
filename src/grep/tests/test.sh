#!/bin/bash

# make clean
# make

echo
echo ">>>>> TEST #1 | file: test1.txt <<<<<<"
echo 

#   just find 1
./s21_grep alone tests/test1.txt > res1
grep alone tests/test1.txt > res2
cmp -s res1 res2 && echo "       just find 1 - SUCCES"
rm res1 res2

#   just find 2
./s21_grep one tests/test1.txt > res1
grep one tests/test1.txt > res2
cmp -s res1 res2 && echo "       just find 2 - SUCCES"
rm res1 res2

#   just find 3
./s21_grep alone tests/test1.txt tests/test2.txt  > res1
grep alone tests/test1.txt tests/test2.txt > res2
cmp -s res1 res2 && echo "       just find 3 - SUCCES"
rm res1 res2



#   -n flag 1
./s21_grep -n alone tests/test1.txt > res1
grep -n alone tests/test1.txt > res2
cmp -s res1 res2 && echo "         -n flag 1 - SUCCES"
rm res1 res2

#   -n flag 2
./s21_grep -n xyz tests/test1.txt > res1
grep -n xyz tests/test1.txt > res2
cmp -s res1 res2 && echo "         -n flag 2 - SUCCES"
rm res1 res2

#   -n flag 3
./s21_grep -n alone tests/test1.txt tests/test2.txt  > res1
grep -n alone tests/test1.txt tests/test2.txt > res2
cmp -s res1 res2 && echo "         -n flag 3 - SUCCES"
rm res1 res2



#   -i flag 1
./s21_grep -i alone tests/test1.txt > res1
grep -i alone tests/test1.txt > res2
cmp -s res1 res2 && echo "         -i flag 1 - SUCCES"
rm res1 res2

#   -i flag 2
./s21_grep -i xyz tests/test1.txt > res1
grep -i xyz tests/test1.txt > res2
cmp -s res1 res2 && echo "         -i flag 2 - SUCCES"
rm res1 res2

#   -i flag 3
./s21_grep -i alone tests/test1.txt tests/test2.txt  > res1
grep -i alone tests/test1.txt tests/test2.txt > res2
cmp -s res1 res2 && echo "         -i flag 3 - SUCCES"
rm res1 res2


#   -v flag 1
./s21_grep -v alone tests/test1.txt > res1
grep -v alone tests/test1.txt > res2
cmp -s res1 res2 && echo "         -v flag 1 - SUCCES"
rm res1 res2

#   -v flag 2
./s21_grep -v xyz tests/test1.txt > res1
grep -v xyz tests/test1.txt > res2
cmp -s res1 res2 && echo "         -v flag 2 - SUCCES"
rm res1 res2

#   -v flag 3
./s21_grep -v alone tests/test1.txt tests/test2.txt  > res1
grep -v alone tests/test1.txt tests/test2.txt > res2
cmp -s res1 res2 && echo "         -v flag 3 - SUCCES"
rm res1 res2


#   -c flag 1
./s21_grep -c alone tests/test1.txt > res1
grep -c alone tests/test1.txt > res2
cmp -s res1 res2 && echo "         -c flag 1 - SUCCES"
rm res1 res2

#   -c flag 2
./s21_grep -c xyz tests/test1.txt > res1
grep -c xyz tests/test1.txt > res2
cmp -s res1 res2 && echo "         -c flag 2 - SUCCES"
rm res1 res2

#   -c flag 3
./s21_grep -c alone tests/test1.txt tests/test2.txt  > res1
grep -c alone tests/test1.txt tests/test2.txt > res2
cmp -s res1 res2 && echo "         -c flag 3 - SUCCES"
rm res1 res2


#   -l flag 1
./s21_grep -l alone tests/test1.txt > res1
grep -l alone tests/test1.txt > res2
cmp -s res1 res2 && echo "         -l flag 1 - SUCCES"
rm res1 res2

#   -l flag 2
./s21_grep -l xyz tests/test1.txt > res1
grep -l xyz tests/test1.txt > res2
cmp -s res1 res2 && echo "         -l flag 2 - SUCCES"
rm res1 res2

#   -l flag 3
./s21_grep -l alone tests/test1.txt tests/test2.txt  > res1
grep -l alone tests/test1.txt tests/test2.txt > res2
cmp -s res1 res2 && echo "         -l flag 3 - SUCCES"
rm res1 res2



#   -h flag 1
./s21_grep -h alone tests/test1.txt > res1
grep -h alone tests/test1.txt > res2
cmp -s res1 res2 && echo "         -h flag 1 - SUCCES"
rm res1 res2

#   -h flag 2
./s21_grep -h xyz tests/test1.txt > res1
grep -h xyz tests/test1.txt > res2
cmp -s res1 res2 && echo "         -h flag 2 - SUCCES"
rm res1 res2

#   -h flag 3
./s21_grep -h alone tests/test1.txt tests/test2.txt  > res1
grep -h alone tests/test1.txt tests/test2.txt > res2
cmp -s res1 res2 && echo "         -h flag 3 - SUCCES"
rm res1 res2



#   -s flag 1
./s21_grep -s alone testsdgsdgs/test1.txt > res1
grep -s alone tests/testsdgsd1.txt > res2
cmp -s res1 res2 && echo "         -s flag 1 - SUCCES"
rm res1 res2

#   -s flag 2
./s21_grep -s xyz tests/tsdgsest1.txt > res1
grep -s xyz tests/tdsggsest1.txt > res2
cmp -s res1 res2 && echo "         -s flag 2 - SUCCES"
rm res1 res2

#   -s flag 3
./s21_grep -s alone tests/testsdg1.txt tests/sdgtest2.txt  > res1
grep -s alone tests/test1.sdgtxt tests/test2.sdgtxt > res2
cmp -s res1 res2 && echo "         -s flag 3 - SUCCES"
rm res1 res2