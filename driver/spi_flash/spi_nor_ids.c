// Copyright (C) 2017 Microchip Technology Inc. and its subsidiaries
//
// SPDX-License-Identifier: MIT

#include "spi_flash/spi_nor.h"

#define ID5(_jedec_id, _ext_id)			\
	.id = {					\
		((_jedec_id) >> 16) & 0xff,	\
		((_jedec_id) >>  8) & 0xff,	\
		((_jedec_id) >>  0) & 0xff,	\
		((_ext_id) >> 8) & 0xff,	\
		((_ext_id) >> 0) & 0xff,	\
	},					\
	.id_len = ((_ext_id) ? 5 : 3)

#define SST26(_name, _jedec_id, _n_sectors)	\
	.name = _name,				\
	ID5(_jedec_id, 0),			\
	.sector_size = 4096U,			\
	.n_sectors = (_n_sectors),		\
	.page_size = 256,			\
	.flags = SNOR_SECT_4K_ONLY | SNOR_SST_ULBPR

#define N25Q(_name, _jedec_id, _n_sectors)	\
	.name = _name,				\
	ID5(_jedec_id, 0),			\
	.sector_size = 65536U,			\
	.n_sectors = (_n_sectors),		\
	.page_size = 256,			\
	.flags = SNOR_HAS_FSR | SNOR_SECT_4K | SNOR_NO_4BAIS

#define MX25(_name, _jedec_id, _n_sectors)      \
        .name = _name,                          \
        ID5(_jedec_id, 0),                      \
        .sector_size = 65536U,                  \
        .n_sectors = (_n_sectors),              \
        .page_size = 256,                       \
        .flags = SNOR_SECT_4K | SNOR_NO_4BAIS

#define MX66(_name, _jedec_id, _n_sectors)      \
	.name = _name,                          \
	ID5(_jedec_id, 0),                      \
	.sector_size = 65536U,                  \
	.n_sectors = (_n_sectors),              \
	.page_size = 256,                       \
	.flags = SNOR_SECT_4K

const struct spi_nor_info spi_nor_ids[] = {
	/* Macronix */
	{ MX25("mx25l25635f", 0xc22019,  512), },
	{ MX66("mx66lm1g45g", 0xc2853b, 2048), },

	/* Micron */
	{ N25Q("n25q032ax1", 0x20bb16,   64), },
	{ N25Q("n25q032ax3", 0x20ba16,   64), },
	{ N25Q("n25q064ax1", 0x20bb17,  128), },
	{ N25Q("n25q064ax3", 0x20ba17,  128), },
	{ N25Q("n25q128ax1", 0x20bb18,  256), },
	{ N25Q("n25q128ax3", 0x20ba18,  256), },
	{ N25Q("n25q256ax1", 0x20bb19,  512), },
	{ N25Q("n25q256ax3", 0x20ba19,  512), },
	{ N25Q("n25q512ax1", 0x20bb20, 1024), },
	{ N25Q("n25q512ax3", 0x20ba20, 1024), },
	{ N25Q("n25q00ax1",  0x20bb21, 2048), },
	{ N25Q("n25q00ax3",  0x20ba21, 2048), },

	/* SST */
	{ SST26("sst26vf016b", 0xbf2641,  512), },
	{ SST26("sst26vf032b", 0xbf2642, 1024), },
	{ SST26("sst26vf064b", 0xbf2643, 2048), },
	{ SST26("sst26wf040b", 0xbf2654,  128), },
	{ SST26("sst26wf080b", 0xbf2658,  256), },

	{}	/* Sentinel */
};
