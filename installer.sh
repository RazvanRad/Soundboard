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

################
##### MAIN #####
################

MY_PATH=${0}
EXTERN=$(dirname ${MY_PATH})/external
mkdir $(dirname ${MY_PATH})/tmp
TMP=$(dirname ${MY_PATH})/tmp

copy_music
unzip_sdl
install_sdl_mixer
install_sdl2
bluetooth_config

rm -r tmp