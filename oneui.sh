#!/bin/bash
#
# Cronos Build Script
# For Exynos9610
# Coded by BlackMesa/AnanJaser1211/Prashantp01 @2020
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software

# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Directory Contol
CR_DIR=$(pwd)
CR_TC=/home/top/Desktop/aarch64-linux-android-4.9/bin/aarch64-linux-android-
CR_DTS=arch/arm64/boot/dts
CR_DTB=$CR_DIR/boot.img-dtb
# Kernel Variables
CR_VERSION=ONEUI
CR_NAME=hypersonic
CR_JOBS=5
CR_ANDROID=q
CR_PLATFORM=10
CR_ARCH=arm64
CR_DATE=$(date +%Y%m%d)
# Init build
export CROSS_COMPILE=$CR_TC
export ANDROID_MAJOR_VERSION=$CR_ANDROID
export PLATFORM_VERSION=$CR_PLATFORM
export $CR_ARCH
##########################################
# Device specific Variables [SM-A307FN]
CR_CONFG_A307FN=exynos7885-a30s_Q_defconfig
CR_VARIANT_A307FN=A307FN
##########################################

# Script functions
CLEAN_SOURCE()
{
echo "----------------------------------------------"
echo " "
echo "cleaning..."	
# rm -r -f $CR_OUT/*
rm -r -f $CR_DTB
rm -rf $CR_DTS/.*.tmp
rm -rf $CR_DTS/.*.cmd
rm -rf $CR_DTS/*.dtb 
echo " "
echo "----------------------------------------------"	
}
BUILD_ZIMAGE()
{
	echo "----------------------------------------------"
	echo " "
	echo "Building zImage for $CR_VARIANT"	
	export LOCALVERSION=-$CR_NAME-$CR_VERSION-$CR_VARIANT
	make  $CR_CONFG
	make -j$CR_JOBS
	echo " "
	echo "----------------------------------------------"	
}

# Main Menu
clear
echo "----------------------------------------------"
echo "$CR_NAME $CR_VERSION Build Script"
echo "----------------------------------------------"
PS3='Please select your option : '
menuvar=("SM-A307FN" "Exit")
select menuvar in "${menuvar[@]}"
do
    case $menuvar in
        "SM-A307FN")
            clear
            CLEAN_SOURCE
            echo "Starting $CR_VARIANT_A307FN kernel build..."
	    CR_VARIANT=$CR_VARIANT_A307FN
	    CR_CONFG=$CR_CONFG_A307FN
	    BUILD_ZIMAGE
            echo " "
            echo "----------------------------------------------"
            echo "$CR_VARIANT kernel build finished."
	    echo "Press any key to end the script"
            echo "----------------------------------------------"
            read -n1 -r key
            break
            ;;
        "Exit")
            break
            ;;
        *) echo Invalid option.;;
    esac
done

