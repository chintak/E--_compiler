declare -a arr=("01" "01a" "01b" "02" "02a" "02b" "03" "03a" "04a" "04b" "05" "05a" "05b" "06a" "06b" "06c" "07" "08")

cd typecheck/test

mkdir -p runs
rm runs/tout*

for i in "${arr[@]}"
do
    echo "#######################################################"
    echo "typecheck/test/in$i:"
    echo ""
    ../../demo \
        in$i &> runs/tout$i && \
        diff -w --text runs/tout$i out$i \
        | head -30;
done

cd ../..
