// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2024 Rockchip Electronics Co., Ltd.
 */

#include <dm.h>
#include <ram.h>
#include <asm/arch-rockchip/sdram.h>

#define GRF_PMU_BASE			0xff910000
#define OS_REG2_REG			0x208

static int rk3506_dmc_get_info(struct udevice *dev, struct ram_info *info)
{
	info->base = CFG_SYS_SDRAM_BASE;
	info->size = rockchip_sdram_size(GRF_PMU_BASE + OS_REG2_REG);

	return 0;
}

static struct ram_ops rk3506_dmc_ops = {
	.get_info = rk3506_dmc_get_info,
};

static const struct udevice_id rk3506_dmc_ids[] = {
	{ .compatible = "rockchip,rk3506-dmc" },
	{ }
};

U_BOOT_DRIVER(rockchip_rk3506_dmc) = {
	.name = "rockchip_rk3506_dmc",
	.id = UCLASS_RAM,
	.of_match = rk3506_dmc_ids,
	.ops = &rk3506_dmc_ops,
};
