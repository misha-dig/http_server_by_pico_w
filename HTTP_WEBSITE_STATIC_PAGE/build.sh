#/bin/bash
# Set enviroment PICO_SDK_PATH for this project to avoid stupid error
export PICO_SDK_PATH=/home/linuxpc/pico/pico-sdk
# Checking folder existing path
[ -d "build" ] && echo "folder build exists." || echo "Directory build does not exists. It will create automatically" && mkdir build  
# Go to build directory after your source of code 
cd build
# Prepare and configure cmake building your c code
cmake -DPICO_BOARD=pico_w -DWIFI_SSID="WIFI_EXAMPLE" -DWIFI_PASSWORD="PASSWORD_EXAMPLE" ..
# Build your source of code !
make
# Checking files in build directory
ls -lh
# Inform that the building of source of code 
echo "Ready to upload binaries into your Raspberry PI PICO W"
