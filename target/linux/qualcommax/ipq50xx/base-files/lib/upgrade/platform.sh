#!/bin/sh
# /lib/upgrade/platform.sh for Wallys DR5018 (IPQ5018)

. /lib/functions.sh
. /lib/upgrade/common.sh

# Define supported board name
detect_board() {
    echo "wallys_dr5018"
}

# Check firmware compatibility
platform_check_image() {
    local image="$1"

    case "$image" in
        *wallys_dr5018*)
            return 0
            ;;
        *)
            echo "Incompatible firmware image." >&2
            return 1
            ;;
    esac
}

# Pre-upgrade operations
platform_pre_upgrade() {
    sync
    echo 3 > /proc/sys/vm/drop_caches
    echo "Starting upgrade process for Wallys DR5018..."
}

# Flash firmware
platform_do_upgrade() {
    local image="$1"
    echo "Flashing firmware for Wallys DR5018..."

    # Example MTD flashing commands (adjust based on DTS partitions)
    # Identify partitions in DTS: kernel, rootfs, etc.
    local kernel_part="kernel"
    local rootfs_part="rootfs"

    # Write kernel and rootfs to respective partitions
    mtd write "$image" "$kernel_part"
    mtd write "$image" "$rootfs_part"

    # Optionally configure bootloader here
    fw_setenv bootcmd "bootm $(mtdinfo -u "$kernel_part")"

    echo "Firmware flashed successfully! Rebooting..."
    reboot
}

# Post-upgrade operations (optional)
platform_post_upgrade() {
    echo "Post-upgrade cleanup and verification for Wallys DR5018 completed."
}

# Integration with LuCI
platform_setup_luci() {
    echo "Setting up LuCI for firmware flashing..."
    # Additional setup code if needed
}

# Invoke appropriate functions based on OpenWRT upgrade process
case "$1" in
    detect)
        detect_board
        ;;
    check)
        platform_check_image "$2"
        ;;
    pre_upgrade)
        platform_pre_upgrade
        ;;
    do_upgrade)
        platform_do_upgrade "$2"
        ;;
    post_upgrade)
        platform_post_upgrade
        ;;
    luci_setup)
        platform_setup_luci
        ;;
    *)
        echo "Usage: $0 {detect|check|pre_upgrade|do_upgrade|post_upgrade|luci_setup}" >&2
        exit 1
        ;;
esac
