g++ checker.cpp -o checker
g++ a.cpp -o a
g++ b.cpp -o b
while :
do
    i=$(($i + 1))
    echo $i 
    ./checker $i 5  > test.inp
    ./a < test.inp > test.out
    ./b < test.inp > test.ans

    diff test.out test.ans || break
done