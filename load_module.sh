sudo rmmod -f pteditor
pushd modules
sudo insmod pteditor.ko
popd
