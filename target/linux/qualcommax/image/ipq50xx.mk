define Device/qcom_mpxx
        $(call Device/MultiDTBFitImage)
        DEVICE_VENDOR := Qualcomm Technologies, Inc.
        DEVICE_MODEL := AP-MPXX
        DEVICE_VARIANT :=
        BOARD_NAME := ap-mpxx
        SOC := ipq5018
        KERNEL_INSTALL := 1
        KERNEL_SIZE := $(if $(CONFIG_DEBUG),8680k,6500k)
        IMAGE_SIZE := 25344k
        IMAGE/sysupgrade.bin := append-kernel | pad-to $$$$(KERNEL_SIZE) | append-rootfs | pad-rootfs | append-metadata
endef
TARGET_DEVICES += qcom_mpxx

define Device/linksys_ipq50xx_mx_base
	$(call Device/FitImageLzma)
	DEVICE_VENDOR := Linksys
	BLOCKSIZE := 128k
	PAGESIZE := 2048
	KERNEL_SIZE := 8192k
	IMAGE_SIZE := 83968k
	NAND_SIZE := 256m
	SOC := ipq5018
	UBINIZE_OPTS := -E 5	# EOD marks to "hide" factory sig at EOF
	IMAGES += factory.bin
	IMAGE/factory.bin := append-kernel | pad-to $$$$(KERNEL_SIZE) | append-ubi | linksys-image type=$$$$(DEVICE_MODEL)
endef

define Device/linksys_mr5500
	$(call Device/linksys_ipq50xx_mx_base)
	DEVICE_MODEL := MR5500
	DEVICE_DTS_CONFIG := config@mp03.1
	DEVICE_PACKAGES := kmod-ath11k-pci \
					ath11k-firmware-qcn9704 \
					ipq-wifi-linksys_mr5500
endef
TARGET_DEVICES += linksys_mr5500

define Device/linksys_mx2000
	$(call Device/linksys_ipq50xx_mx_base)
	DEVICE_MODEL := MX2000
	DEVICE_DTS_CONFIG := config@mp03.5-c1
	DEVICE_PACKAGES := ath11k-firmware-qcn6122 \
					ipq-wifi-linksys_mx2000
endef
TARGET_DEVICES += linksys_mx2000

define Device/linksys_mx5500
	$(call Device/linksys_ipq50xx_mx_base)
	DEVICE_MODEL := MX5500
	DEVICE_DTS_CONFIG := config@mp03.1
	DEVICE_PACKAGES := kmod-ath11k-pci \
					ath11k-firmware-qcn9074 \
					ipq-wifi-linksys_mx5500
endef
TARGET_DEVICES += linksys_mx5500

define Device/linksys_spnmx56
	$(call Device/linksys_ipq50xx_mx_base)
	DEVICE_MODEL := SPNMX56
	DEVICE_DTS_CONFIG := config@mp03.1
	DEVICE_PACKAGES := kmod-ath11k-pci \
					ath11k-firmware-qcn9074 \
					ipq-wifi-linksys_spnmx56
endef
TARGET_DEVICES += linksys_spnmx56

define Device/wallys_dr5018
        $(call Device/FitImageLzma)
        DEVICE_VENDOR := Wallys
        DEVICE_MODEL := DR5018
        DEVICE_VARIANT := C1
        BOARD_NAME := ap-mp03.5-c1
        BUILD_DTS_ipq5018-mp03.5-c1 := 1
        SOC := ipq5018
        KERNEL_INSTALL := 1
        KERNEL_SIZE := 6096k
        IMAGE_SIZE := 25344k
        IMAGE/sysupgrade.bin := append-kernel | pad-to $$$$(KERNEL_SIZE) | append-rootfs | pad-rootfs | append-metadata
endef
TARGET_DEVICES += $(wallys_dr5018)

#define Device/wallys_dr5018
#	#$(call Image/Build/Rootfs)
#	$(call Device/FitImageLzma)
#	SOC := ipq5018
#	DEVICE_MODEL := Wallys
#	DEVICE_VARIANT := DR5018
#	BLOCKSIZE := 128k
#	PAGESIZE := 2048
#        KERNEL_PART := kernel
#        KERNEL_SIZE := 8192k
#	IMAGE_SIZE := 129408k
#	UBINIZE_OPTS := -E 5
#	IMAGES := factory.bin
#	IMAGE/factory.bin := append-kernel | pad-to $$$$(KERNEL_SIZE) | append-ubi | check-size | ubinize-image -s 2048
#	DEVICE_PACKAGES := kmod-qca-nss-dp kmod-usb3 kmod-usb-dwc3 kmod-usb-dwc3-qcom kmod-usb-phy ath11k-firmware-qcn6122
#endef
#TARGET_DEVICES += wallys_dr5018

#define Device/wallys_dr5018
#	$(call Image/Build/Rootfs)
#	$(call Device/FitImageLzma)
 #       SOC := ipq5018
  #      DEVICE_MODEL := Wallys
   #     DEVICE_VARIANT := DR5018
#	BLOCKSIZE := 128k
#	PAGESIZE := 2048
	#$(call Image/Build/$(1),$(1))
        #IMAGE_SIZE := 83968k
        #NAND_SIZE := 256m
#	KERNEL_PART := kernel
#	KERNEL_SIZE := 8192k
#	IMAGE_SIZE := 129408k # Adjust based on your UBI partition size
#	UBINIZE_OPTS := -E 5 # Adjust based on your NAND's erase block size and ECC requirements
	#IMAGES += factory.bin sysupgrade.bin
	#IMAGE/factory.bin := append-kernel | pad-to 128k | \
	#                    	append-ubi | \
	#			nand-image-ipq50xx-128k-ecc
	#IMAGE/sysupgrade.bin := append-kernel | pad-to 128k | \
	#                        append-ubi | \
	#			nand-image-ipq50xx-128k-ecc | \
	#			append-metadata
	#IMAGES := factory.bin sysupgrade.bin
	#IMAGE/factory.bin := \
	#	wallys-dr5018 | append-metadata
	#IMAGE/sysupgrade.bin := \
	#	wallys-dr5018 | append-metadata
#        IMAGES += factory.bin
#        IMAGE/factory.bin := append-kernel | pad-to $$$$(KERNEL_SIZE) | append-ubi | type=$$$$(DEVICE_MODEL)
#endef
#TARGET_DEVICES += wallys_dr5018

#define Build/nand-image-ipq50xx-128k-ecc
	# Commands to generate the NAND image, likely using mkits.sh
#	$(call Image/Build/$(1),$(1))
	#$(call Image/Build/Rootfs)
#endef

#define Image/Build/Rootfs
#	$(STAGING_DIR_HOST)/bin/mksquashfs $(call Build/dir,root-$(1)) \
#	$(BIN_DIR)/$(IMG_PREFIX)-$(1).squashfs $(SquashfsOpts) -e /dev
#endef
