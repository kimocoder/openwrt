PART_NAME=firmware
REQUIRE_IMAGE_METADATA=1

RAMFS_COPY_BIN='fw_printenv fw_setenv head'
RAMFS_COPY_DATA='/etc/fw_env.config /var/lock/fw_printenv.lock'

platform_check_image() {
    # Validate image for supported boards
    case "$(board_name)" in
    linksys,mx2000|\
    linksys,mx5500|\
    wally,dr5018)
        return 0
        ;;
    *)
        echo "Unsupported board: $(board_name)"
        return 1
        ;;
    esac
}

platform_do_upgrade() {
    CI_UBIPART="rootfs"
    CI_ROOTPART="ubi_rootfs"
    CI_IPQ807X=1

    case "$(board_name)" in
    linksys,mx2000|\
    linksys,mx5500)
        platform_do_upgrade_linksys "$1"
        ;;
    wally,dr5018)
        if [ -f /proc/boot_info/rootfs/upgradepartition ]; then
            CI_UBIPART="$(cat /proc/boot_info/rootfs/upgradepartition)"
            CI_BOOTCFG=1
        else
            echo "Error: Upgrade partition file not found!"
            return 1
        fi
        nand_upgrade_tar "$1"
        ;;
    *)
        echo "Warning: Falling back to default upgrade method."
        default_do_upgrade "$1"
        ;;
    esac
	return 0;
}
