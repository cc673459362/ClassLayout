# using clang output layout and vtable
echo "clang++ -m$1 -Xclang -fdump-vtable-layouts $2 > $2.vtable"
clang++ -c -m$1 -Xclang -fdump-vtable-layouts $2 > $2.vatble
echo "clang++ -m$1 -Xclang -fdump-record-layouts $2 > $2.record"
clang++ -c -m$1 -Xclang -fdump-record-layouts $2 > $2.record

# using fixfile.cc to get the useful infomation from clang layout resule
clang++ fixfile.cc -o fix
./fix $2.record $2.recordfix

# draw the picture


# delete middle file
rm fix
rm $2.record
rm *.o
mv $2.recordfix $2.record
