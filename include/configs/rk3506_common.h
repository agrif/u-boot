/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2024 Rockchip Electronics Co., Ltd
 *
 */

#ifndef __CONFIG_RK3506_COMMON_H
#define __CONFIG_RK3506_COMMON_H

#define CFG_CPUID_OFFSET		0xa

#include "rockchip-common.h"

#define CFG_IRAM_BASE			0xfff80000
#define CFG_SYS_SDRAM_BASE		0
#define SDRAM_MAX_SIZE			0xc0000000

#ifndef ROCKCHIP_DEVICE_SETTINGS
#define ROCKCHIP_DEVICE_SETTINGS
#endif

/* SPL */
#define GICD_BASE			0xff581000
#define GICC_BASE			0xff582000

#define ATAGS_OFFSET			0x62000
#define ATAGS_SIZE			0x01000

/* secure otp */
#define OTP_UBOOT_ROLLBACK_OFFSET	0x350
#define OTP_UBOOT_ROLLBACK_WORDS	2	/* 64 bits, 2 words */
#define OTP_ALL_ONES_NUM_BITS		32
#define OTP_SECURE_BOOT_ENABLE_ADDR	0x20
#define OTP_SECURE_BOOT_ENABLE_SIZE	1
#define OTP_RSA_HASH_ADDR		0x180
#define OTP_RSA_HASH_SIZE		32

#define CFG_PRAM 6144

/*
 *   (trust):    0K - 392K
 * (ramoops):  524K - 704K
 *     Image:  1M+32k - 17M
 *    zImage:  17M - 24M
 *       fdt:  24M - 25M
 *   ramdisk:  25M - ...
 */
#define ENV_MEM_LAYOUT_SETTINGS			\
	"scriptaddr=0x00b00000\0"		\
	"pxefile_addr_r=0x00c00000\0"		\
	"kernel_addr_r=0x00108000\0"		\
	"kernel_comp_addr_r=0x01100000\0"	\
	"fdt_addr_r=0x01800000\0"		\
	"ramdisk_addr_r=0x01900000\0"

#include <config_distro_bootcmd.h>

#define CFG_EXTRA_ENV_SETTINGS			\
	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0"	\
	ENV_MEM_LAYOUT_SETTINGS			\
	ROCKCHIP_DEVICE_SETTINGS		\
	"boot_targets=" BOOT_TARGETS "\0"

#endif
