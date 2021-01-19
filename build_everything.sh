pushd modules
make clean
make
popd

pushd pagedump
make clean
make
popd

pushd test
make clean
. compile_cmd
popd
