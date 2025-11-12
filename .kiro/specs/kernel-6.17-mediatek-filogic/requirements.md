# Requirements Document

## Introduction

This document outlines the requirements for adding Linux kernel 6.17 support to the MediaTek Filogic subtarget in OpenWrt. The MediaTek Filogic platform (MT798x series) currently supports kernel 6.12, and this feature will enable building OpenWrt firmware images with the newer 6.17 kernel version. This upgrade will provide access to newer kernel features, hardware support improvements, and security updates for MediaTek Filogic-based devices.

## Glossary

- **OpenWrt**: A Linux operating system targeting embedded devices, particularly routers and access points
- **Kernel**: The Linux kernel, the core component of the operating system
- **MediaTek Filogic**: A family of ARM-based SoCs (MT7981, MT7986, MT7987, MT7988) used in networking equipment
- **Subtarget**: A specific hardware platform variant within OpenWrt's build system
- **Build System**: OpenWrt's compilation framework that generates firmware images
- **Patch**: A file containing modifications to kernel source code
- **Config File**: Kernel configuration file that defines which features are enabled
- **Generic Platform**: The base kernel configuration shared across all OpenWrt targets
- **DTS/Device Tree**: Hardware description files that define device-specific configurations

## Requirements

### Requirement 1

**User Story:** As an OpenWrt developer, I want to build firmware images with kernel 6.17 for MediaTek Filogic devices, so that I can test and deploy newer kernel features on my hardware.

#### Acceptance Criteria

1. WHEN THE Build_System compiles the mediatek target, THE Build_System SHALL support kernel version 6.17 as a configuration option
2. WHEN kernel 6.17 is selected, THE Build_System SHALL download the correct kernel source tarball with valid hash verification
3. WHEN THE Build_System applies patches, THE Build_System SHALL successfully apply all generic kernel patches to version 6.17
4. WHEN THE Build_System configures the kernel, THE Build_System SHALL use a valid kernel configuration file for version 6.17
5. WHERE kernel 6.17 is selected, THE Build_System SHALL produce bootable firmware images for MediaTek Filogic devices

### Requirement 2

**User Story:** As an OpenWrt maintainer, I want kernel 6.17 patches to be properly organized and documented, so that I can maintain and update them efficiently.

#### Acceptance Criteria

1. THE Build_System SHALL store kernel 6.17 generic patches in the directory "target/linux/generic/backport-6.17", "target/linux/generic/hack-6.17", and "target/linux/generic/pending-6.17"
2. THE Build_System SHALL store MediaTek-specific kernel 6.17 patches in the directory "target/linux/mediatek/patches-6.17"
3. WHEN patches are copied from kernel 6.12, THE Build_System SHALL maintain the original patch numbering and naming convention
4. THE Build_System SHALL include patch files with descriptive names that indicate their purpose and upstream status

### Requirement 3

**User Story:** As an OpenWrt developer, I want kernel configuration files to be properly maintained for kernel 6.17, so that the kernel builds with the correct features enabled.

#### Acceptance Criteria

1. THE Build_System SHALL provide a generic kernel configuration file at "target/linux/generic/config-6.17"
2. THE Build_System SHALL provide a Filogic-specific kernel configuration file at "target/linux/mediatek/filogic/config-6.17"
3. THE Build_System SHALL provide kernel configuration files for all MediaTek subtargets (mt7622, mt7623, mt7629) at their respective paths
4. WHEN configuration options change between kernel versions, THE Build_System SHALL update config files to reflect new or removed options
5. THE Build_System SHALL validate that all required kernel features for MediaTek Filogic hardware are enabled in the configuration

### Requirement 4

**User Story:** As an OpenWrt developer, I want to be able to switch between kernel 6.12 and 6.17 for testing, so that I can compare stability and performance.

#### Acceptance Criteria

1. THE Build_System SHALL allow selection of kernel 6.17 as a testing kernel option in the configuration menu
2. WHEN kernel 6.17 is selected as testing kernel, THE Build_System SHALL use the KERNEL_TESTING_PATCHVER variable with value "6.17"
3. THE Build_System SHALL maintain both kernel 6.12 and 6.17 configurations simultaneously without conflicts
4. WHEN switching between kernel versions, THE Build_System SHALL use the appropriate patch directories and configuration files

### Requirement 5

**User Story:** As an OpenWrt developer, I want kernel 6.17 to support all MediaTek Filogic device tree files, so that all supported devices can boot with the new kernel.

#### Acceptance Criteria

1. WHEN THE Build_System compiles device trees, THE Build_System SHALL successfully compile all DTS files in "target/linux/mediatek/dts/" with kernel 6.17
2. THE Build_System SHALL apply any necessary device tree patches for kernel 6.17 compatibility
3. WHERE device tree syntax changes between kernel versions, THE Build_System SHALL include patches to update device tree files
4. THE Build_System SHALL maintain compatibility with existing device-specific configurations and overlays

### Requirement 6

**User Story:** As an OpenWrt developer, I want kernel 6.17 to include MediaTek-specific drivers and features, so that hardware functionality is preserved.

#### Acceptance Criteria

1. THE Build_System SHALL include MediaTek-specific driver files from "target/linux/mediatek/files-6.17" directory when building kernel 6.17
2. WHEN MediaTek drivers require updates for kernel 6.17, THE Build_System SHALL apply compatibility patches
3. THE Build_System SHALL enable support for MediaTek Ethernet, WiFi, PCIe, USB, and other hardware subsystems
4. THE Build_System SHALL maintain support for MediaTek-specific features including hardware crypto, thermal management, and clock control

### Requirement 7

**User Story:** As an OpenWrt developer, I want the kernel version metadata to be properly configured, so that the build system can download and verify the correct kernel source.

#### Acceptance Criteria

1. THE Build_System SHALL define kernel 6.17 version information in "target/linux/generic/kernel-6.17" file
2. THE Build_System SHALL include the exact kernel version number (e.g., 6.17.x) in the version file
3. THE Build_System SHALL include a valid SHA256 hash for the kernel source tarball
4. WHEN THE Build_System downloads kernel source, THE Build_System SHALL verify the tarball hash matches the configured value
5. THE Build_System SHALL fail the build with a clear error message if hash verification fails
