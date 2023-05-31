# sh clean.sh
sh cmake.sh
cd ../build
rm -rf tests
make
./tests