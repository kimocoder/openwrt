define Device/linksys_mx_atlas6
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

define Device/linksys_mx2000
	$(call Device/linksys_mx_atlas6)
	DEVICE_MODEL := MX2000
	DEVICE_DTS_CONFIG := config@mp03.5-c1
	DEVICE_PACKAGES := ath11k-firmware-qcn6122 \
					ipq-wifi-linksys_mx2000
endef
TARGET_DEVICES += linksys_mx2000

define Device/linksys_mx5500
	$(call Device/linksys_mx_atlas6)
	DEVICE_MODEL := MX5500
	DEVICE_DTS_CONFIG := config@mp03.1
	DEVICE_PACKAGES := kmod-ath11k-pci \
					ath11k-firmware-qcn9074 \
					ipq-wifi-linksys_mx5500
endef
TARGET_DEVICES += linksys_mx5500

define Device/wallys_dr5018
	DEVICE_TITLE := Wallys DR5018
	DEVICE_DTS := ipq5018-dr5018
	SUPPORTED_DEVICES := wallys,dr5018
	DEVICE_PACKAGES := ath11k-wifi-wallys-dr5018 uboot-envtools ath11k-firmware-qcn6122
	DEVICE_DTS_CONFIG := config@mp03.5-c1
	KERNEL = kernel-bin | libdeflate-gzip | fit gzip $(KDIR)/image-ipq5018-dr5018.dtb
	IMAGE/sysupgrade.bin := sysupgrade-tar | append-metadata
	IMAGE/sysupgrade.bin/squashfs := append-rootfs | sysupgrade-tar rootfs=$$$$@ | append-metadata
endef
TARGET_DEVICES += wallys_dr5018
