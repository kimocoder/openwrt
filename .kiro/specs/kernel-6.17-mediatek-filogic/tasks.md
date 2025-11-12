# Implementation Plan

- [x] 1. Set up generic kernel 6.17 infrastructure
  - Create kernel version metadata file with version number and hash
  - Copy generic kernel configuration from 6.12 as baseline
  - Create directory structure for generic patches
  - _Requirements: 1.1, 1.2, 7.1, 7.2, 7.3, 7.4, 7.5_

- [x] 1.1 Create kernel version metadata file
  - Create `target/linux/generic/kernel-6.17` file
  - Add LINUX_VERSION-6.17 variable with patch version
  - Add LINUX_KERNEL_HASH-6.17.X variable with SHA256 hash of kernel tarball
  - Verify hash format matches existing kernel-6.12 file
  - _Requirements: 7.1, 7.2, 7.3, 7.4, 7.5_

- [x] 1.2 Create generic kernel configuration
  - Copy `target/linux/generic/config-6.12` to `target/linux/generic/config-6.17`
  - Review configuration for any obvious 6.17-specific changes needed
  - Document any configuration options that may need updating after kernel download
  - _Requirements: 1.2, 1.4, 3.1, 3.4_

- [x] 1.3 Create generic patch directories
  - Create `target/linux/generic/backport-6.17/` directory
  - Create `target/linux/generic/hack-6.17/` directory
  - Create `target/linux/generic/pending-6.17/` directory
  - Copy all patches from corresponding 6.12 directories to 6.17 directories
  - _Requirements: 1.3, 2.1, 2.3, 2.4_

- [x] 1.4 Clean up patches already in kernel 6.17
  - Review backport patches to identify those already included in 6.17 upstream
  - Remove patches that are already in kernel 6.17 (check patch headers for version tags like v6.13, v6.14, v6.15, v6.16)
  - Test build after removing each patch to ensure it's truly not needed
  - Document which patches were removed and why
  - **Completed**: Removed 168 patches total (163 v6.13-6.17 backports, 1 v6.18 DMA patch, 4 v6.18 KS8995 patches)
  - **Remaining**: 5 legitimate v6.18 patches (MTD NAND, MediaTek WED, Realtek PHY)
  - _Requirements: 1.3, 2.1, 2.4_

- [x] 2. Set up MediaTek target infrastructure for kernel 6.17
  - Create MediaTek-specific patch directory
  - Copy MediaTek patches from 6.12
  - Create MediaTek driver files directory if needed
  - Update MediaTek Makefile to support kernel 6.17 as testing kernel
  - _Requirements: 1.1, 2.1, 2.2, 2.3, 2.4, 4.1, 4.2, 4.3, 4.4, 6.1, 6.2_

- [x] 2.1 Create MediaTek patch directory
  - Create `target/linux/mediatek/patches-6.17/` directory
  - Copy all patches from `target/linux/mediatek/patches-6.12/` to `patches-6.17/`
  - Maintain original patch numbering and naming convention
  - _Requirements: 2.1, 2.2, 2.3, 2.4_

- [x] 2.2 Create MediaTek driver files directory
  - Check if `target/linux/mediatek/files-6.12/` exists
  - If it exists, copy to `target/linux/mediatek/files-6.17/`
  - If it doesn't exist, skip this step
  - _Requirements: 6.1, 6.2_

- [x] 2.3 Update MediaTek Makefile for testing kernel
  - Open `target/linux/mediatek/Makefile`
  - Add line `KERNEL_TESTING_PATCHVER:=6.17` after the existing `KERNEL_PATCHVER:=6.12` line
  - Verify Makefile syntax is correct
  - _Requirements: 4.1, 4.2, 4.3, 4.4_

- [ ] 3. Configure Filogic subtarget for kernel 6.17
  - Copy Filogic kernel configuration from 6.12
  - Create configurations for other MediaTek subtargets
  - Verify all subtarget configurations are present
  - _Requirements: 1.4, 3.1, 3.2, 3.3, 3.4, 3.5_

- [x] 3.1 Create Filogic kernel configuration
  - Copy `target/linux/mediatek/filogic/config-6.12` to `target/linux/mediatek/filogic/config-6.17`
  - Verify configuration file format is correct
  - _Requirements: 3.2, 3.4, 3.5_

- [ ] 3.2 Create MT7622 kernel configuration
  - Copy `target/linux/mediatek/mt7622/config-6.12` to `target/linux/mediatek/mt7622/config-6.17`
  - Verify configuration file format is correct
  - _Requirements: 3.3, 3.4_

- [ ] 3.3 Create MT7623 kernel configuration
  - Copy `target/linux/mediatek/mt7623/config-6.12` to `target/linux/mediatek/mt7623/config-6.17`
  - Verify configuration file format is correct
  - _Requirements: 3.3, 3.4_

- [ ] 3.4 Create MT7629 kernel configuration
  - Copy `target/linux/mediatek/mt7629/config-6.12` to `target/linux/mediatek/mt7629/config-6.17`
  - Verify configuration file format is correct
  - _Requirements: 3.3, 3.4_

- [-] 4. Verify initial build system integration
  - Test that kernel 6.17 option appears in configuration
  - Verify build system recognizes new kernel version
  - Check that patch directories are correctly referenced
  - _Requirements: 1.1, 1.2, 1.3, 4.1, 4.2, 4.3, 4.4_

- [ ] 4.1 Verify kernel version is recognized
  - Run `make menuconfig` and navigate to kernel options
  - Verify that kernel 6.17 appears as a testing kernel option
  - Document the configuration path for enabling 6.17
  - _Requirements: 4.1, 4.2_

- [ ] 4.2 Check patch directory detection
  - Verify build system will look for patches-6.17 when 6.17 is selected
  - Verify build system will look for files-6.17 when 6.17 is selected
  - Confirm config-6.17 files will be used when 6.17 is selected
  - _Requirements: 1.3, 4.3, 4.4_

- [ ] 5. Create documentation for kernel 6.17 support
  - Document the new kernel 6.17 support
  - Create notes about testing status
  - Document how to enable kernel 6.17
  - List known limitations or issues
  - _Requirements: 1.1, 4.1, 4.2_

- [ ] 5.1 Create README for kernel 6.17
  - Create `.kiro/specs/kernel-6.17-mediatek-filogic/README.md`
  - Document how to enable kernel 6.17 in menuconfig
  - Document build commands for testing
  - List supported devices and subtargets
  - Note that this is a testing kernel, not production-ready
  - _Requirements: 1.1, 4.1, 4.2_

- [ ] 5.2 Create testing checklist
  - Create `.kiro/specs/kernel-6.17-mediatek-filogic/TESTING.md`
  - List all hardware components to test
  - Provide test commands and expected results
  - Document how to report issues
  - _Requirements: 1.1_
