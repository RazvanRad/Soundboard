#!/bin/bash

copy_music(){
    cp $(dirname ${MY_PATH})/media/* ~/Music
}

unzip_sdl(){
    unzip ${EXTERN}/SDL2-2.0.16.zip -d ${TMP}
    unzip ${EXTERN}/SDL2_mixer-2.0.4.zip -d ${TMP}
}

install_sdl2(){
    cd SDL2-2.0.16
    mkdir build
    cd build
    ../configure
    make all
    sudo make install
    cd ../../..
}

install_sdl_mixer(){
    cd ${TMP}/SDL2_mixer-2.0.4
    mkdir build
    mkdir ceva
    cd build
    ../configure
    make all
    sudo make install
    cd ../..
}

bluetooth_config(){
    sudo apt-get install libbluetooth-dev python-dev libglib2.0-dev libboost-python-dev libboost-thread-dev
    sudo apt install bluez
    sudo pip3 install pybluez
}

bluetooth_config_rasp(){
    sshpass -p ${PASSWORD} ssh pi@192.168.249.30 'sudo apt-get install libbluetooth-dev python-dev libboost-python-dev libboost-thread-dev'
    sshpass -p ${PASSWORD} ssh pi@192.168.249.30 'sudo apt install bluez'
    sshpass -p ${PASSWORD} ssh pi@192.168.249.30 'pip3 install --trusted-host pypi.org --trusted-host files.pythonhosted.org pybluez'
}

dependencies(){
    sudo apt-get install sshpass
}

################
##### MAIN #####
################

MY_PATH=${0}
EXTERN=$(dirname ${MY_PATH})/external
rm -r tmp > /dev/null 2>&1
mkdir $(dirname ${MY_PATH})/tmp > /dev/null 2>&1
TMP=$(dirname ${MY_PATH})/tmp

echo "Please enter your password for rapsberry"
read -s PASSWORD

dependencies
copy_music
unzip_sdl
install_sdl_mixer
install_sdl2
bluetooth_config
bluetooth_config_rasp

rm -r tmp > /dev/null 2>&1