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
	SOC := ipq5018
	DEVICE_MODEL := Wallys
	DEVICE_VARIANT := DR5018
	BLOCKSIZE := 128k
	PAGESIZE := 2048
	IMAGE_SIZE := 129408k
	UBINIZE_OPTS := -E 5
	IMAGES := factory.bin
	IMAGE/factory.bin := append-ubi | check-size | ubinize-image -s 2048
	DEVICE_PACKAGES := kmod-qca-nss-dp kmod-usb3 kmod-usb-dwc3 kmod-usb-dwc3-qcom kmod-usb-phy ath11k-firmware-qcn6122
endef
TARGET_DEVICES += wallys_dr5018
