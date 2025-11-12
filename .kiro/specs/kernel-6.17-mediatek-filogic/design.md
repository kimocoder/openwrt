# Design Document: Kernel 6.17 Support for MediaTek Filogic

## Overview

This design document describes the implementation approach for adding Linux kernel 6.17 support to the MediaTek Filogic subtarget in OpenWrt. The implementation follows OpenWrt's established patterns for kernel version support, creating parallel infrastructure for kernel 6.17 alongside the existing 6.12 support.

The design leverages OpenWrt's build system architecture, which uses:
- Version-specific patch directories for kernel modifications
- Version-specific configuration files for kernel features
- A kernel version metadata system for source management
- A flexible target/subtarget hierarchy for platform-specific builds

## Architecture

### High-Level Component Structure

```
OpenWrt Build System
├── Generic Kernel Infrastructure (6.17)
│   ├── Kernel Version Metadata
│   ├── Generic Patches (backport/hack/pending)
│   └── Generic Configuration
├── MediaTek Target Infrastructure (6.17)
│   ├── MediaTek-Specific Patches
│   ├── MediaTek-Specific Driver Files
│   └── Subtarget Configurations
└── Build System Integration
    ├── Makefile Configuration
    ├── Patch Application Logic
    └── Kernel Compilation Process
```

### Directory Structure

The implementation will create the following directory structure:

```
target/linux/
├── generic/
│   ├── kernel-6.17                    # Kernel version metadata
│   ├── config-6.17                    # Generic kernel config
│   ├── backport-6.17/                 # Upstream backported patches
│   ├── hack-6.17/                     # OpenWrt-specific modifications
│   └── pending-6.17/                  # Patches pending upstream
├── mediatek/
│   ├── Makefile                       # Updated to support 6.17
│   ├── patches-6.17/                  # MediaTek-specific patches
│   ├── files-6.17/                    # MediaTek driver files (if needed)
│   ├── filogic/
│   │   └── config-6.17                # Filogic-specific config
│   ├── mt7622/
│   │   └── config-6.17                # MT7622-specific config
│   ├── mt7623/
│   │   └── config-6.17                # MT7623-specific config
│   └── mt7629/
│       └── config-6.17                # MT7629-specific config
```

## Components and Interfaces

### 1. Kernel Version Metadata Component

**Purpose**: Define kernel version information and source verification data

**Location**: `target/linux/generic/kernel-6.17`

**Interface**:
```makefile
LINUX_VERSION-6.17 = .X
LINUX_KERNEL_HASH-6.17.X = <sha256_hash>
```

**Responsibilities**:
- Specify the exact kernel version (e.g., 6.17.0, 6.17.1)
- Provide SHA256 hash for source tarball verification
- Enable build system to download correct kernel source

**Dependencies**:
- Kernel.org release schedule (6.17 must be released)
- `include/kernel-version.mk` for parsing

### 2. Generic Kernel Configuration Component

**Purpose**: Define base kernel configuration shared across all targets

**Location**: `target/linux/generic/config-6.17`

**Interface**: Standard Linux kernel .config format

**Responsibilities**:
- Enable core kernel features required by OpenWrt
- Configure generic subsystems (networking, filesystems, etc.)
- Set baseline security and performance options

**Creation Strategy**:
- Copy from `config-6.12` as baseline
- Run `make kernel_oldconfig` to update for 6.17 changes
- Review and adjust new configuration options
- Remove obsolete options that no longer exist in 6.17

### 3. Generic Patch Component

**Purpose**: Apply OpenWrt-specific modifications to vanilla kernel

**Locations**:
- `target/linux/generic/backport-6.17/` - Patches from upstream kernel
- `target/linux/generic/hack-6.17/` - OpenWrt-specific hacks
- `target/linux/generic/pending-6.17/` - Patches awaiting upstream acceptance

**Interface**: Standard unified diff format (.patch files)

**Patch Categories**:

1. **Backport Patches**: Features from newer kernels backported to 6.17
   - Naming: `XXX-vY.Z-subsystem-description.patch`
   - Example: `100-v6.18-net-add-feature.patch`

2. **Hack Patches**: OpenWrt-specific modifications
   - Naming: `XXX-subsystem-description.patch`
   - Example: `250-netfilter-add-fullconenat.patch`

3. **Pending Patches**: Submitted upstream but not yet merged
   - Naming: `XXX-subsystem-description.patch`
   - Example: `680-net-add-optimization.patch`

**Creation Strategy**:
- Copy all patches from 6.12 directories
- Test each patch for applicability to 6.17
- Refresh patches that have context conflicts
- Drop patches that are already in 6.17 upstream
- Update patches that need API changes for 6.17

### 4. MediaTek-Specific Patch Component

**Purpose**: Apply MediaTek hardware-specific modifications

**Location**: `target/linux/mediatek/patches-6.17/`

**Patch Categories**:
- Device tree updates for MediaTek SoCs
- MediaTek-specific driver enhancements
- Hardware initialization and configuration
- Platform-specific bug fixes

**Key Patch Areas**:
- Ethernet driver (mtk_eth_soc)
- WiFi integration (MT7915/MT7916/MT7981/MT7986/MT7988)
- PCIe controller
- USB controller
- Thermal management
- Clock and power management
- Pinctrl and GPIO

**Creation Strategy**:
- Copy from `patches-6.12/` as baseline
- Refresh patches for 6.17 kernel API changes
- Test compilation and runtime functionality
- Update device tree bindings if changed in 6.17

### 5. MediaTek Driver Files Component

**Purpose**: Provide out-of-tree driver code for MediaTek hardware

**Location**: `target/linux/mediatek/files-6.17/`

**Structure**:
```
files-6.17/
├── arch/arm64/boot/dts/mediatek/    # Additional device trees
├── drivers/                          # Out-of-tree drivers
└── include/                          # Driver headers
```

**Responsibilities**:
- Provide drivers not yet in mainline kernel
- Override mainline drivers with MediaTek-optimized versions
- Add device-specific configurations

**Creation Strategy**:
- Copy from `files-6.12/` if it exists
- Update driver code for 6.17 kernel API changes
- Test driver compilation and loading
- Verify hardware functionality

### 6. Subtarget Configuration Component

**Purpose**: Define kernel configuration specific to each MediaTek subtarget

**Locations**:
- `target/linux/mediatek/filogic/config-6.17`
- `target/linux/mediatek/mt7622/config-6.17`
- `target/linux/mediatek/mt7623/config-6.17`
- `target/linux/mediatek/mt7629/config-6.17`

**Responsibilities**:
- Enable subtarget-specific hardware support
- Configure SoC-specific drivers
- Set platform-specific options

**Key Configuration Areas for Filogic**:
- ARM64 architecture settings
- MediaTek Ethernet driver (CONFIG_NET_VENDOR_MEDIATEK)
- MediaTek WiFi drivers
- PCIe support (CONFIG_PCIE_MEDIATEK_GEN3)
- USB support
- Crypto hardware acceleration
- Thermal zones
- Device tree support

**Creation Strategy**:
- Copy from respective `config-6.12` files
- Run `make kernel_menuconfig` for each subtarget
- Update for new 6.17 options
- Test build for each subtarget

### 7. Build System Integration Component

**Purpose**: Integrate kernel 6.17 into OpenWrt build system

**Location**: `target/linux/mediatek/Makefile`

**Current State**:
```makefile
KERNEL_PATCHVER:=6.12
```

**Design Options**:

**Option A: Testing Kernel (Recommended for Initial Implementation)**
```makefile
KERNEL_PATCHVER:=6.12
KERNEL_TESTING_PATCHVER:=6.17
```

This approach:
- Keeps 6.12 as default stable kernel
- Makes 6.17 available via `CONFIG_TESTING_KERNEL` option
- Allows parallel testing without disrupting stable builds
- Follows OpenWrt's standard kernel upgrade path

**Option B: Default Kernel (For Production Release)**
```makefile
KERNEL_PATCHVER:=6.17
```

This approach:
- Makes 6.17 the default kernel
- Used after thorough testing and validation
- Requires all patches to be stable

**Implementation**: Start with Option A, migrate to Option B after validation

## Data Models

### Kernel Version Metadata

```makefile
# File: target/linux/generic/kernel-6.17
LINUX_VERSION-6.17 = .0              # Patch version (6.17.0)
LINUX_KERNEL_HASH-6.17.0 = <hash>    # SHA256 of linux-6.17.0.tar.xz
```

### Patch File Naming Convention

```
<number>-[v<version>-]<subsystem>-<description>.patch

Where:
- number: 3-digit ordering number (000-999)
- version: Optional upstream version (e.g., v6.18)
- subsystem: Kernel subsystem (net, arm64, dts, etc.)
- description: Brief description with hyphens
```

### Configuration File Format

Standard Linux kernel .config format:
```
CONFIG_OPTION=y          # Enabled
CONFIG_OPTION=m          # Module
# CONFIG_OPTION is not set  # Disabled
CONFIG_OPTION=value      # Value
```

## Error Handling

### Build-Time Error Handling

1. **Missing Kernel Source**
   - Detection: Hash verification fails or download fails
   - Handling: Build system reports error and stops
   - Recovery: Update kernel-6.17 file with correct version/hash

2. **Patch Application Failure**
   - Detection: `patch` command returns non-zero exit code
   - Handling: Build stops with patch file name
   - Recovery: Refresh or fix the failing patch

3. **Configuration Errors**
   - Detection: Kernel build fails due to missing/invalid config
   - Handling: Build stops with kernel error message
   - Recovery: Update config file with required options

4. **Compilation Errors**
   - Detection: Kernel compilation fails
   - Handling: Build stops with compiler error
   - Recovery: Fix driver code or patch causing the error

### Runtime Error Handling

1. **Boot Failure**
   - Detection: Device fails to boot or kernel panic
   - Handling: Device remains in bootloader or reboots
   - Recovery: Revert to working kernel, debug device tree or drivers

2. **Driver Loading Failure**
   - Detection: Hardware not detected or driver errors in dmesg
   - Handling: Hardware remains non-functional
   - Recovery: Fix driver compatibility issues

3. **Performance Degradation**
   - Detection: Benchmarking or user reports
   - Handling: System runs but slower than expected
   - Recovery: Review and optimize kernel configuration

## Testing Strategy

### Phase 1: Build Testing

**Objective**: Verify that kernel 6.17 builds successfully

**Tests**:
1. Clean build test
   ```bash
   make target/linux/clean
   make target/linux/compile
   ```

2. Patch application test
   - Verify all patches apply without conflicts
   - Check for fuzz or offset warnings

3. Configuration validation
   - Run `make kernel_oldconfig` to check for missing options
   - Verify no unset required options

4. Multi-subtarget build
   - Build all MediaTek subtargets (filogic, mt7622, mt7623, mt7629)
   - Verify each produces valid kernel images

**Success Criteria**:
- All patches apply cleanly
- Kernel compiles without errors
- All subtargets build successfully
- Kernel modules compile correctly

### Phase 2: Boot Testing

**Objective**: Verify that kernel 6.17 boots on real hardware

**Test Devices** (Filogic examples):
- BananaPi BPI-R3 (MT7986)
- BananaPi BPI-R4 (MT7988)
- OpenWrt One (MT7981)
- GL.iNet GL-MT6000 (MT7986)

**Tests**:
1. Basic boot test
   - Flash firmware with 6.17 kernel
   - Verify device boots to login prompt
   - Check kernel version: `uname -r`

2. Serial console test
   - Monitor boot process via serial
   - Check for kernel panics or errors
   - Verify all drivers load

3. Device tree validation
   - Check dmesg for device tree errors
   - Verify all hardware nodes are detected

**Success Criteria**:
- Device boots successfully
- No kernel panics or oops
- Serial console accessible
- System reaches multi-user target

### Phase 3: Hardware Functionality Testing

**Objective**: Verify all hardware components work correctly

**Test Areas**:

1. **Networking**
   - Ethernet ports (WAN/LAN)
   - Switch functionality
   - VLAN configuration
   - Link speed negotiation

2. **WiFi**
   - 2.4GHz radio
   - 5GHz radio
   - 6GHz radio (if supported)
   - Client and AP modes

3. **Storage**
   - eMMC/SD card
   - NAND flash
   - NOR flash
   - USB storage

4. **USB**
   - USB 2.0 ports
   - USB 3.0 ports
   - USB device detection

5. **PCIe**
   - PCIe device enumeration
   - WiFi cards on PCIe
   - NVMe drives (if supported)

6. **System**
   - LEDs
   - Buttons
   - Hardware watchdog
   - Thermal sensors
   - CPU frequency scaling

**Success Criteria**:
- All hardware components functional
- Performance comparable to 6.12
- No regressions in functionality

### Phase 4: Stability Testing

**Objective**: Verify long-term stability and performance

**Tests**:
1. Stress testing
   - Network throughput tests (iperf3)
   - CPU stress (stress-ng)
   - Memory stress
   - Thermal testing

2. Long-term operation
   - 24-hour uptime test
   - Monitor for memory leaks
   - Check for kernel warnings/errors

3. Power cycling
   - Multiple reboot cycles
   - Power loss recovery
   - Watchdog functionality

**Success Criteria**:
- No crashes or hangs during stress tests
- Stable operation for 24+ hours
- Clean recovery from power cycles
- No memory leaks detected

### Phase 5: Regression Testing

**Objective**: Ensure no regressions from kernel 6.12

**Tests**:
1. Feature parity check
   - Compare enabled features between 6.12 and 6.17
   - Verify no critical features disabled

2. Performance comparison
   - Network throughput (6.12 vs 6.17)
   - CPU performance
   - Memory usage

3. Compatibility testing
   - Existing configurations work
   - Package compatibility
   - User space tools function correctly

**Success Criteria**:
- No feature regressions
- Performance within 5% of 6.12
- All existing functionality preserved

## Implementation Phases

### Phase 1: Foundation (Generic Kernel Infrastructure)

**Goal**: Establish base kernel 6.17 support in generic platform

**Tasks**:
1. Create kernel version metadata file
2. Copy and update generic kernel configuration
3. Copy generic patches from 6.12
4. Test generic kernel build

**Deliverables**:
- `target/linux/generic/kernel-6.17`
- `target/linux/generic/config-6.17`
- `target/linux/generic/backport-6.17/`
- `target/linux/generic/hack-6.17/`
- `target/linux/generic/pending-6.17/`

### Phase 2: MediaTek Platform Support

**Goal**: Add MediaTek-specific kernel 6.17 support

**Tasks**:
1. Copy MediaTek patches from 6.12
2. Refresh patches for 6.17 compatibility
3. Copy MediaTek driver files (if needed)
4. Update MediaTek Makefile

**Deliverables**:
- `target/linux/mediatek/patches-6.17/`
- `target/linux/mediatek/files-6.17/` (if needed)
- Updated `target/linux/mediatek/Makefile`

### Phase 3: Filogic Subtarget Configuration

**Goal**: Configure kernel 6.17 for Filogic subtarget

**Tasks**:
1. Copy Filogic configuration from 6.12
2. Update configuration for 6.17
3. Test Filogic build
4. Validate on hardware

**Deliverables**:
- `target/linux/mediatek/filogic/config-6.17`
- Tested firmware images

### Phase 4: Additional Subtargets

**Goal**: Extend support to other MediaTek subtargets

**Tasks**:
1. Configure mt7622 subtarget
2. Configure mt7623 subtarget
3. Configure mt7629 subtarget
4. Test each subtarget

**Deliverables**:
- Configuration files for all subtargets
- Tested firmware for each platform

### Phase 5: Validation and Documentation

**Goal**: Comprehensive testing and documentation

**Tasks**:
1. Execute full test suite
2. Document known issues
3. Create upgrade guide
4. Submit for review

**Deliverables**:
- Test results
- Known issues list
- Documentation updates

## Dependencies

### External Dependencies

1. **Linux Kernel 6.17 Release**
   - Status: Must be released by kernel.org
   - Impact: Cannot proceed until 6.17 is available
   - Mitigation: Can prepare infrastructure using RC releases

2. **MediaTek Driver Support**
   - Status: MediaTek drivers must support 6.17 APIs
   - Impact: May require driver updates
   - Mitigation: Patch drivers for compatibility

3. **OpenWrt Build System**
   - Status: Must support kernel 6.17
   - Impact: Build system changes may be needed
   - Mitigation: Follow established patterns from 6.12

### Internal Dependencies

1. **Generic Kernel Infrastructure** → MediaTek Platform
   - MediaTek patches depend on generic patches
   - Must complete generic setup first

2. **MediaTek Platform** → Subtarget Configuration
   - Subtarget configs depend on MediaTek patches
   - Must have working MediaTek build first

3. **All Components** → Testing
   - Testing requires all components complete
   - Cannot validate until full build works

## Risk Assessment

### High Risk Items

1. **API Changes in Kernel 6.17**
   - Risk: Significant API changes break MediaTek drivers
   - Mitigation: Review kernel changelogs, test early
   - Contingency: Patch drivers or wait for upstream fixes

2. **Hardware Compatibility**
   - Risk: New kernel breaks hardware functionality
   - Mitigation: Thorough testing on multiple devices
   - Contingency: Keep 6.12 as fallback option

### Medium Risk Items

1. **Patch Conflicts**
   - Risk: Patches don't apply cleanly to 6.17
   - Mitigation: Systematic patch refresh process
   - Contingency: Rewrite or drop problematic patches

2. **Configuration Changes**
   - Risk: New kernel options cause build failures
   - Mitigation: Careful config review and testing
   - Contingency: Adjust configurations iteratively

### Low Risk Items

1. **Build System Integration**
   - Risk: Makefile changes cause issues
   - Mitigation: Follow established patterns
   - Contingency: Revert to known-good configuration

2. **Documentation**
   - Risk: Incomplete documentation
   - Mitigation: Document as we implement
   - Contingency: Update documentation post-implementation

## Performance Considerations

### Build Performance

- Parallel builds supported (make -j)
- Ccache recommended for faster rebuilds
- Patch application is serial (cannot parallelize)

### Runtime Performance

- Kernel 6.17 may have performance improvements
- New scheduler features may benefit multi-core SoCs
- Network stack improvements may increase throughput
- Monitor for any performance regressions

### Resource Usage

- Kernel size should be similar to 6.12
- Memory usage expected to be comparable
- Storage requirements unchanged

## Security Considerations

### Kernel Security Updates

- Kernel 6.17 includes latest security fixes
- Must track 6.17.x stable updates
- Update kernel-6.17 file as patches release

### Patch Security

- Review all patches for security implications
- Ensure backported patches include security fixes
- Validate patch sources and authenticity

### Build Security

- Verify kernel source tarball hash
- Use secure download sources (HTTPS)
- Maintain patch integrity

## Future Enhancements

### Short Term

1. Add support for newer MediaTek SoCs (MT7987)
2. Optimize kernel configuration for size/performance
3. Backport additional features from 6.18+

### Long Term

1. Transition 6.17 from testing to default kernel
2. Remove 6.12 support after 6.17 stabilization
3. Prepare for kernel 6.18 support

## Conclusion

This design provides a comprehensive approach to adding kernel 6.17 support for MediaTek Filogic in OpenWrt. The implementation follows OpenWrt's established patterns, minimizes risk through phased rollout, and includes thorough testing at each stage. The modular design allows for incremental development and easy rollback if issues arise.
