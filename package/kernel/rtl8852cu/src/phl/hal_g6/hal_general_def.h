/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#ifndef _HAL_GENERAL_DEF_H_
#define _HAL_GENERAL_DEF_H_

#define FL_COMP_VER BIT0
#define FL_COMP_INIT BIT1
#define FL_COMP_TASK BIT2
#define FL_COMP_CNS BIT3
#define FL_COMP_H2C BIT4
#define FL_COMP_C2H BIT5
#define FL_COMP_TX BIT6
#define FL_COMP_RX BIT7
#define FL_COMP_IPSEC BIT8
#define FL_COMP_TIMER BIT9
#define FL_COMP_DBGPKT BIT10
#define FL_COMP_PS BIT11
#define FL_COMP_BB BIT16
#define FL_COMP_MCC BIT20

#define RTW_MAC_TBTT_AGG_DEF 1

/* RXBUF should larger than RXBD, or it will cause RX RDU
   the minimum number of RXBUF - RXBD is 32 */
#define RTW_RX_BUF_BD_MIN_DIFF 32

enum rtw_chip_id {
	CHIP_WIFI6_8852A,
	CHIP_WIFI6_8834A,
	CHIP_WIFI6_8852B,
	CHIP_WIFI6_8852C,
	CHIP_WIFI6_8192XB,
	CHIP_WIFI6_8832BR,
	CHIP_WIFI6_8852BP,
	CHIP_WIFI7_8922A,
	CHIP_WIFI6_8851B,
	CHIP_WIFI6_MAX
};

enum rtw_efuse_info {
	/* MAC Part */
	EFUSE_INFO_MAC_ADDR,
	EFUSE_INFO_MAC_PID,
	EFUSE_INFO_MAC_DID,
	EFUSE_INFO_MAC_VID,
	EFUSE_INFO_MAC_SVID,
	EFUSE_INFO_MAC_SMID,
	EFUSE_INFO_MAC_MAX,
	/* BB Part */
	EFUSE_INFO_BB_ANTDIV,
	EFUSE_INFO_BB_MAX,
	/* RF Part */
	EFUSE_INFO_RF_PKG_TYPE,
	EFUSE_INFO_RF_PA,
	EFUSE_INFO_RF_VALID_PATH,
	EFUSE_INFO_RF_RFE,
	EFUSE_INFO_RF_TXPWR,
	EFUSE_INFO_RF_BOARD_OPTION,
	EFUSE_INFO_RF_CHAN_PLAN,
	EFUSE_INFO_RF_CHAN_PLAN_6GHZ,
	EFUSE_INFO_RF_CHAN_PLAN_FORCE_HW,
	EFUSE_INFO_RF_COUNTRY,
	EFUSE_INFO_RF_THERMAL,
	EFUSE_INFO_RF_2G_CCK_A_TSSI_DE_1,
	EFUSE_INFO_RF_2G_CCK_A_TSSI_DE_2,
	EFUSE_INFO_RF_2G_CCK_A_TSSI_DE_3,
	EFUSE_INFO_RF_2G_CCK_A_TSSI_DE_4,
	EFUSE_INFO_RF_2G_CCK_A_TSSI_DE_5,
	EFUSE_INFO_RF_2G_CCK_A_TSSI_DE_6,
	EFUSE_INFO_RF_2G_BW40M_A_TSSI_DE_1,
	EFUSE_INFO_RF_2G_BW40M_A_TSSI_DE_2,
	EFUSE_INFO_RF_2G_BW40M_A_TSSI_DE_3,
	EFUSE_INFO_RF_2G_BW40M_A_TSSI_DE_4,
	EFUSE_INFO_RF_2G_BW40M_A_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_1,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_2,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_3,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_4,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_6,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_7,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_8,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_9,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_10,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_11,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_12,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_13,
	EFUSE_INFO_RF_5G_BW40M_A_TSSI_DE_14,
	EFUSE_INFO_RF_5G_BW20M1S_BW40M1S_A_DIFF,
	EFUSE_INFO_RF_5G_OFDM1T_BW40M1S_A_DIFF,
	EFUSE_INFO_RF_5G_BW40M2S_BW40M1S_A_DIFF,
	EFUSE_INFO_RF_5G_BW20M2S_BW20M1S_A_DIFF,
	EFUSE_INFO_RF_5G_BW40M3S_BW40M2S_A_DIFF,
	EFUSE_INFO_RF_5G_BW20M3S_BW20M2S_A_DIFF,
	EFUSE_INFO_RF_5G_BW40M4S_BW40M3S_A_DIFF,
	EFUSE_INFO_RF_5G_BW20M4S_BW20M3S_A_DIFF,
	EFUSE_INFO_RF_5G_OFDM2T_OFDM1T_A_DIFF,
	EFUSE_INFO_RF_5G_OFDM3T_OFDM2T_A_DIFF,
	EFUSE_INFO_RF_5G_OFDM4T_OFDM3T_A_DIFF,
	EFUSE_INFO_RF_5G_BW80M1S_BW40M1S_A_DIFF,
	EFUSE_INFO_RF_5G_BW160M1S_BW80M1S_A_DIFF,
	EFUSE_INFO_RF_5G_BW80M2S_BW80M1S_A_DIFF,
	EFUSE_INFO_RF_5G_BW160M2S_BW160M1S_A_DIFF,
	EFUSE_INFO_RF_5G_BW80M3S_BW80M2S_A_DIFF,
	EFUSE_INFO_RF_5G_BW160M3S_BW160M2S_A_DIFF,
	EFUSE_INFO_RF_5G_BW80M4S_BW80M3S_A_DIFF,
	EFUSE_INFO_RF_5G_BW160M4S_BW160M3S_A_DIFF,
	EFUSE_INFO_RF_2G_CCK_B_TSSI_DE_1,
	EFUSE_INFO_RF_2G_CCK_B_TSSI_DE_2,
	EFUSE_INFO_RF_2G_CCK_B_TSSI_DE_3,
	EFUSE_INFO_RF_2G_CCK_B_TSSI_DE_4,
	EFUSE_INFO_RF_2G_CCK_B_TSSI_DE_5,
	EFUSE_INFO_RF_2G_CCK_B_TSSI_DE_6,
	EFUSE_INFO_RF_2G_BW40M_B_TSSI_DE_1,
	EFUSE_INFO_RF_2G_BW40M_B_TSSI_DE_2,
	EFUSE_INFO_RF_2G_BW40M_B_TSSI_DE_3,
	EFUSE_INFO_RF_2G_BW40M_B_TSSI_DE_4,
	EFUSE_INFO_RF_2G_BW40M_B_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_1,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_2,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_3,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_4,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_6,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_7,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_8,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_9,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_10,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_11,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_12,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_13,
	EFUSE_INFO_RF_5G_BW40M_B_TSSI_DE_14,
	EFUSE_INFO_RF_5G_BW20M1S_BW40M1S_B_DIFF,
	EFUSE_INFO_RF_5G_OFDM1T_BW40M1S_B_DIFF,
	EFUSE_INFO_RF_5G_BW40M2S_BW40M1S_B_DIFF,
	EFUSE_INFO_RF_5G_BW20M2S_BW20M1S_B_DIFF,
	EFUSE_INFO_RF_5G_BW40M3S_BW40M2S_B_DIFF,
	EFUSE_INFO_RF_5G_BW20M3S_BW20M2S_B_DIFF,
	EFUSE_INFO_RF_5G_BW40M4S_BW40M3S_B_DIFF,
	EFUSE_INFO_RF_5G_BW20M4S_BW20M3S_B_DIFF,
	EFUSE_INFO_RF_5G_OFDM2T_OFDM1T_B_DIFF,
	EFUSE_INFO_RF_5G_OFDM3T_OFDM2T_B_DIFF,
	EFUSE_INFO_RF_5G_OFDM4T_OFDM3T_B_DIFF,
	EFUSE_INFO_RF_5G_BW80M1S_BW40M1S_B_DIFF,
	EFUSE_INFO_RF_5G_BW160M1S_BW80M1S_B_DIFF,
	EFUSE_INFO_RF_5G_BW80M2S_BW80M1S_B_DIFF,
	EFUSE_INFO_RF_5G_BW160M2S_BW160M1S_B_DIFF,
	EFUSE_INFO_RF_5G_BW80M3S_BW80M2S_B_DIFF,
	EFUSE_INFO_RF_5G_BW160M3S_BW160M2S_B_DIFF,
	EFUSE_INFO_RF_5G_BW80M4S_BW80M3S_B_DIFF,
	EFUSE_INFO_RF_5G_BW160M4S_BW160M3S_B_DIFF,
	EFUSE_INFO_RF_2G_CCK_C_TSSI_DE_1,
	EFUSE_INFO_RF_2G_CCK_C_TSSI_DE_2,
	EFUSE_INFO_RF_2G_CCK_C_TSSI_DE_3,
	EFUSE_INFO_RF_2G_CCK_C_TSSI_DE_4,
	EFUSE_INFO_RF_2G_CCK_C_TSSI_DE_5,
	EFUSE_INFO_RF_2G_CCK_C_TSSI_DE_6,
	EFUSE_INFO_RF_2G_BW40M_C_TSSI_DE_1,
	EFUSE_INFO_RF_2G_BW40M_C_TSSI_DE_2,
	EFUSE_INFO_RF_2G_BW40M_C_TSSI_DE_3,
	EFUSE_INFO_RF_2G_BW40M_C_TSSI_DE_4,
	EFUSE_INFO_RF_2G_BW40M_C_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_1,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_2,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_3,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_4,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_6,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_7,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_8,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_9,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_10,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_11,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_12,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_13,
	EFUSE_INFO_RF_5G_BW40M_C_TSSI_DE_14,
	EFUSE_INFO_RF_5G_BW20M1S_BW40M1S_C_DIFF,
	EFUSE_INFO_RF_5G_OFDM1T_BW40M1S_C_DIFF,
	EFUSE_INFO_RF_5G_BW40M2S_BW40M1S_C_DIFF,
	EFUSE_INFO_RF_5G_BW20M2S_BW20M1S_C_DIFF,
	EFUSE_INFO_RF_5G_BW40M3S_BW40M2S_C_DIFF,
	EFUSE_INFO_RF_5G_BW20M3S_BW20M2S_C_DIFF,
	EFUSE_INFO_RF_5G_BW40M4S_BW40M3S_C_DIFF,
	EFUSE_INFO_RF_5G_BW20M4S_BW20M3S_C_DIFF,
	EFUSE_INFO_RF_5G_OFDM2T_OFDM1T_C_DIFF,
	EFUSE_INFO_RF_5G_OFDM3T_OFDM2T_C_DIFF,
	EFUSE_INFO_RF_5G_OFDM4T_OFDM3T_C_DIFF,
	EFUSE_INFO_RF_5G_BW80M1S_BW40M1S_C_DIFF,
	EFUSE_INFO_RF_5G_BW160M1S_BW80M1S_C_DIFF,
	EFUSE_INFO_RF_5G_BW80M2S_BW80M1S_C_DIFF,
	EFUSE_INFO_RF_5G_BW160M2S_BW160M1S_C_DIFF,
	EFUSE_INFO_RF_5G_BW80M3S_BW80M2S_C_DIFF,
	EFUSE_INFO_RF_5G_BW160M3S_BW160M2S_C_DIFF,
	EFUSE_INFO_RF_5G_BW80M4S_BW80M3S_C_DIFF,
	EFUSE_INFO_RF_5G_BW160M4S_BW160M3S_C_DIFF,
	EFUSE_INFO_RF_2G_CCK_D_TSSI_DE_1,
	EFUSE_INFO_RF_2G_CCK_D_TSSI_DE_2,
	EFUSE_INFO_RF_2G_CCK_D_TSSI_DE_3,
	EFUSE_INFO_RF_2G_CCK_D_TSSI_DE_4,
	EFUSE_INFO_RF_2G_CCK_D_TSSI_DE_5,
	EFUSE_INFO_RF_2G_CCK_D_TSSI_DE_6,
	EFUSE_INFO_RF_2G_BW40M_D_TSSI_DE_1,
	EFUSE_INFO_RF_2G_BW40M_D_TSSI_DE_2,
	EFUSE_INFO_RF_2G_BW40M_D_TSSI_DE_3,
	EFUSE_INFO_RF_2G_BW40M_D_TSSI_DE_4,
	EFUSE_INFO_RF_2G_BW40M_D_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_1,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_2,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_3,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_4,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_5,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_6,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_7,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_8,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_9,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_10,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_11,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_12,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_13,
	EFUSE_INFO_RF_5G_BW40M_D_TSSI_DE_14,
	EFUSE_INFO_RF_5G_BW20M1S_BW40M1S_D_DIFF,
	EFUSE_INFO_RF_5G_OFDM1T_BW40M1S_D_DIFF,
	EFUSE_INFO_RF_5G_BW40M2S_BW40M1S_D_DIFF,
	EFUSE_INFO_RF_5G_BW20M2S_BW20M1S_D_DIFF,
	EFUSE_INFO_RF_5G_BW40M3S_BW40M2S_D_DIFF,
	EFUSE_INFO_RF_5G_BW20M3S_BW20M2S_D_DIFF,
	EFUSE_INFO_RF_5G_BW40M4S_BW40M3S_D_DIFF,
	EFUSE_INFO_RF_5G_BW20M4S_BW20M3S_D_DIFF,
	EFUSE_INFO_RF_5G_OFDM2T_OFDM1T_D_DIFF,
	EFUSE_INFO_RF_5G_OFDM3T_OFDM2T_D_DIFF,
	EFUSE_INFO_RF_5G_OFDM4T_OFDM3T_D_DIFF,
	EFUSE_INFO_RF_5G_BW80M1S_BW40M1S_D_DIFF,
	EFUSE_INFO_RF_5G_BW160M1S_BW80M1S_D_DIFF,
	EFUSE_INFO_RF_5G_BW80M2S_BW80M1S_D_DIFF,
	EFUSE_INFO_RF_5G_BW160M2S_BW160M1S_D_DIFF,
	EFUSE_INFO_RF_5G_BW80M3S_BW80M2S_D_DIFF,
	EFUSE_INFO_RF_5G_BW160M3S_BW160M2S_D_DIFF,
	EFUSE_INFO_RF_5G_BW80M4S_BW80M3S_D_DIFF,
	EFUSE_INFO_RF_5G_BW160M4S_BW160M3S_D_DIFF,
	EFUSE_INFO_RF_THERMAL_A,
	EFUSE_INFO_RF_THERMAL_B,
	EFUSE_INFO_RF_THERMAL_C,
	EFUSE_INFO_RF_THERMAL_D,
	EFUSE_INFO_RF_XTAL,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_1,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_2,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_3,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_4,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_5,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_6,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_7,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_8,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_9,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_10,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_11,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_12,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_13,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_14,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_15,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_16,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_17,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_18,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_19,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_20,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_21,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_22,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_23,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_24,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_25,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_26,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_27,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_28,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_29,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_30,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_31,
	EFUSE_INFO_RF_6G_BW40M_A_TSSI_DE_32,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_1,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_2,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_3,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_4,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_5,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_6,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_7,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_8,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_9,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_10,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_11,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_12,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_13,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_14,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_15,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_16,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_17,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_18,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_19,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_20,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_21,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_22,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_23,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_24,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_25,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_26,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_27,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_28,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_29,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_30,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_31,
	EFUSE_INFO_RF_6G_BW40M_B_TSSI_DE_32,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_1,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_2,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_3,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_4,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_5,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_6,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_7,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_8,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_9,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_10,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_11,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_12,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_13,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_14,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_15,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_16,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_17,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_18,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_19,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_20,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_21,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_22,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_23,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_24,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_25,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_26,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_27,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_28,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_29,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_30,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_31,
	EFUSE_INFO_RF_6G_BW40M_C_TSSI_DE_32,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_1,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_2,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_3,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_4,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_5,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_6,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_7,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_8,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_9,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_10,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_11,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_12,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_13,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_14,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_15,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_16,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_17,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_18,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_19,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_20,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_21,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_22,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_23,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_24,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_25,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_26,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_27,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_28,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_29,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_30,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_31,
	EFUSE_INFO_RF_6G_BW40M_D_TSSI_DE_32,
	/*RX Gain K*/
        EFUSE_INFO_RF_RX_GAIN_K_A_2G_CCK,
        EFUSE_INFO_RF_RX_GAIN_K_A_2G_OFMD,
        EFUSE_INFO_RF_RX_GAIN_K_A_5GL,
        EFUSE_INFO_RF_RX_GAIN_K_A_5GM,
        EFUSE_INFO_RF_RX_GAIN_K_A_5GH,
	EFUSE_INFO_RF_RX_GAIN_K_A_6GL1,
        EFUSE_INFO_RF_RX_GAIN_K_A_6GL2,
        EFUSE_INFO_RF_RX_GAIN_K_A_6GL3,
        EFUSE_INFO_RF_RX_GAIN_K_A_6GM1,
        EFUSE_INFO_RF_RX_GAIN_K_A_6GM2,
        EFUSE_INFO_RF_RX_GAIN_K_A_6GM3,
        EFUSE_INFO_RF_RX_GAIN_K_A_6GH1,
        EFUSE_INFO_RF_RX_GAIN_K_A_6GH2,
	/*RF BW Power Diff*/
	EFUSE_INFO_RF_5G_BW160M_BW40M_DIFF,
	EFUSE_INFO_RF_6G_BW160M_BW40M_DIFF,
	EFUSE_INFO_RF_6G_BW320M_BW160M_DIFF,
	EFUSE_INFO_RF_MAX,
	/* BTCOEX Part */
	EFUSE_INFO_BTCOEX_COEX,
	EFUSE_INFO_BTCOEX_ANT_NUM,
	EFUSE_INFO_BTCOEX_ANT_PATH,
	EFUSE_INFO_BTCOEX_MAX,
};

enum rtw_cv {
	CAV,
	CBV,
	CCV,
	CDV,
	CEV,
	CFV,
	CGV,
	CTV,
	CMAXV,
};

enum rtw_fv {
	FTV,
	FUV,
	FSV,
};

enum rtw_dv_sel {
	DAV,
	DDV,
};

enum hal_pwr_by_rate_setting {
	PW_BY_RATE_ON = 0,
	PW_BY_RATE_ALL_SAME = 1
};

enum hal_pwr_limit_type {
	PWLMT_BY_EFUSE = 0,
	PWLMT_DISABLE = 1,
	PWBYRATE_AND_PWLMT = 2
};

enum wl_func {
	EFUSE_WL_FUNC_NONE = 0,
	EFUSE_WL_FUNC_DRAGON = 0xe,
	EFUSE_WL_FUNC_GENERAL = 0xf
};
enum hw_stype{
	EFUSE_HW_STYPE_NONE = 0x0,
	EFUSE_HW_STYPE_GENERAL = 0xf
};
#endif /* _HAL_GENERAL_DEF_H_*/

