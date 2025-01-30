#!/usr/env/bash

cat << EOF > .config
CONFIG_TARGET_qualcommax=y
CONFIG_TARGET_qualcommax_ipq50xx=y
CONFIG_TARGET_MULTI_PROFILE=y

# Device specific target.
# Replace my_device_name with the correct one from 'make info'
CONFIG_TARGET_DEVICE_qualcommax_ipq50xx_DEVICE_wallys_dr5018=y
#CONFIG_BUSYBOX_CUSTOM=y
# Select UBI support for busybox, might not be needed
#CONFIG_BUSYBOX_CONFIG_UBIATTACH=y
#CONFIG_BUSYBOX_CONFIG_UBIDETACH=y
#CONFIG_BUSYBOX_CONFIG_UBIFS_FS=y
#CONFIG_BUSYBOX_CONFIG_UBIMCVOL=y
#CONFIG_BUSYBOX_CONFIG_UBINFO=y
#CONFIG_BUSYBOX_CONFIG_UBINIZE=y
#CONFIG_BUSYBOX_CONFIG_UBIRENAME=y
#CONFIG_BUSYBOX_CONFIG_UBIRSVOL=y
#CONFIG_BUSYBOX_CONFIG_UBIRMVOL=y
#CONFIG_BUSYBOX_CONFIG_UBIUPDATEVOL=y

# Include UBI tools
CONFIG_PACKAGE_ubi-utils=y

# Other packages you may need
CONFIG_PACKAGE_kmod-usb-core=y
CONFIG_PACKAGE_kmod-usb2=y
CONFIG_PACKAGE_kmod-usb3=y
CONFIG_PACKAGE_kmod-usb-ehci=y
CONFIG_PACKAGE_kmod-usb-ohci=y
CONFIG_PACKAGE_kmod-usb-xhci-hcd=y
CONFIG_PACKAGE_kmod-usb-xhci-mtk=y
CONFIG_PACKAGE_kmod-nls-cp437=y
CONFIG_PACKAGE_kmod-nls-iso8859-1=y
CONFIG_PACKAGE_kmod-fs-vfat=y
CONFIG_PACKAGE_kmod-fs-ext4=y
CONFIG_PACKAGE_block-mount=y
CONFIG_PACKAGE_kmod-mtd-rw=y # Allow read-write for MTD partitions (be careful)
CONFIG_PACKAGE_kmod-mtd-self-test=y # Might be needed for development
CONFIG_PACKAGE_kmod-hwmon-core=y
CONFIG_PACKAGE_kmod-thermal=y
CONFIG_PACKAGE_kmod-thermal-qcom-tsens=y
#Optional: Add luci for web interface
CONFIG_PACKAGE_luci=y
CONFIG_PACKAGE_luci-app-firewall=y

EOF
# Prepare the build
make .config -j4 V=sc
