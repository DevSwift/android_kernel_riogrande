/*
 * Copyright (C) ST-Ericsson SA 2010
 *
 * Author: Ola Lilja <ola.o.lilja@stericsson.com>,
 *         Roger Nilsson <roger.xr.nilsson@stericsson.com>
 *         for ST-Ericsson.
 *
 * License terms:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 */
#ifndef UX500_PCM_H
#define UX500_PCM_H

#include <asm/page.h>
#include <linux/workqueue.h>

#define UX500_PLATFORM_MIN_RATE_PLAYBACK 8000
#define UX500_PLATFORM_MAX_RATE_PLAYBACK 48000
#define UX500_PLATFORM_MIN_RATE_CAPTURE	8000
#define UX500_PLATFORM_MAX_RATE_CAPTURE	48000

#define UX500_PLATFORM_MIN_CHANNELS 1
#define UX500_PLATFORM_MAX_CHANNELS 8

#define UX500_PLATFORM_PERIODS_BYTES_MIN	128
#define UX500_PLATFORM_PERIODS_BYTES_MAX	(64 * PAGE_SIZE)
#define UX500_PLATFORM_PERIODS_MIN		2
#define UX500_PLATFORM_PERIODS_MAX		48
#define UX500_PLATFORM_BUFFER_BYTES_MAX		(2048 * PAGE_SIZE)

extern struct snd_soc_platform ux500_soc_platform;
extern void ux500_pcm_wakeup(struct snd_pcm_substream *substream);

struct ux500_pcm_private {
	struct dma_chan *pipeid;
	struct workqueue_struct *wq;
	struct work_struct ws_stop;
	int msp_id;
	int stream_id;
	unsigned int offset;
	bool cyclic;
	int state;
};

struct ux500_pcm_dma_params {
	unsigned int data_size;
	struct stedma40_chan_cfg *dma_cfg;
	bool cyclic;
};

#endif
