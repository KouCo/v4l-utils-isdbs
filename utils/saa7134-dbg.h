/*
    Copyright (C) 2008 Mauro Carvalho Chehab <mchehab@infradead.org>
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "v4l-board-dbg.h"

#define SAA7134_IDENT "saa7134"

/* Register name prefix */
#define SAA7134_PREFIX "SAA7134_"
#define SAA7135_PREFIX "SAA7135_"
#define SAA7133_PREFIX "SAA7133_"

static struct board_regs saa7134_regs[] = {
	{0x101, SAA7134_PREFIX "INCR_DELAY", 1},
	{0x102, SAA7134_PREFIX "ANALOG_IN_CTRL1", 1},
	{0x103, SAA7134_PREFIX "ANALOG_IN_CTRL2", 1},
	{0x104, SAA7134_PREFIX "ANALOG_IN_CTRL3", 1},
	{0x105, SAA7134_PREFIX "ANALOG_IN_CTRL4", 1},
	{0x106, SAA7134_PREFIX "HSYNC_START", 1},
	{0x107, SAA7134_PREFIX "HSYNC_STOP", 1},
	{0x108, SAA7134_PREFIX "SYNC_CTRL", 1},
	{0x109, SAA7134_PREFIX "LUMA_CTRL", 1},
	{0x10a, SAA7134_PREFIX "DEC_LUMA_BRIGHT", 1},
	{0x10b, SAA7134_PREFIX "DEC_LUMA_CONTRAST", 1},
	{0x10c, SAA7134_PREFIX "DEC_CHROMA_SATURATION", 1},
	{0x10d, SAA7134_PREFIX "DEC_CHROMA_HUE", 1},
	{0x10e, SAA7134_PREFIX "CHROMA_CTRL1", 1},
	{0x10f, SAA7134_PREFIX "CHROMA_GAIN", 1},
	{0x110, SAA7134_PREFIX "CHROMA_CTRL2", 1},
	{0x111, SAA7134_PREFIX "MODE_DELAY_CTRL", 1},
	{0x114, SAA7134_PREFIX "ANALOG_ADC", 1},
	{0x115, SAA7134_PREFIX "VGATE_START", 1},
	{0x116, SAA7134_PREFIX "VGATE_STOP", 1},
	{0x117, SAA7134_PREFIX "MISC_VGATE_MSB", 1},
	{0x118, SAA7134_PREFIX "RAW_DATA_GAIN", 1},
	{0x119, SAA7134_PREFIX "RAW_DATA_OFFSET", 1},
	{0x11e, SAA7134_PREFIX "STATUS_VIDEO1", 1},
	{0x11f, SAA7134_PREFIX "STATUS_VIDEO2", 1},
	{0x300, SAA7134_PREFIX "OFMT_VIDEO_A", 1},
	{0x301, SAA7134_PREFIX "OFMT_DATA_A", 1},
	{0x302, SAA7134_PREFIX "OFMT_VIDEO_B", 1},
	{0x303, SAA7134_PREFIX "OFMT_DATA_B", 1},
	{0x304, SAA7134_PREFIX "ALPHA_NOCLIP", 1},
	{0x305, SAA7134_PREFIX "ALPHA_CLIP", 1},
	{0x308, SAA7134_PREFIX "UV_PIXEL", 1},
	{0x309, SAA7134_PREFIX "CLIP_RED", 1},
	{0x30a, SAA7134_PREFIX "CLIP_GREEN", 1},
	{0x30b, SAA7134_PREFIX "CLIP_BLUE", 1},
	{0x180, SAA7134_PREFIX "I2C_ATTR_STATUS", 1},
	{0x181, SAA7134_PREFIX "I2C_DATA", 1},
	{0x182, SAA7134_PREFIX "I2C_CLOCK_SELECT", 1},
	{0x183, SAA7134_PREFIX "I2C_TIMER", 1},
	{0x140, SAA7134_PREFIX "NICAM_ADD_DATA1", 1},
	{0x141, SAA7134_PREFIX "NICAM_ADD_DATA2", 1},
	{0x142, SAA7134_PREFIX "NICAM_STATUS", 1},
	{0x143, SAA7134_PREFIX "AUDIO_STATUS", 1},
	{0x144, SAA7134_PREFIX "NICAM_ERROR_COUNT", 1},
	{0x145, SAA7134_PREFIX "IDENT_SIF", 1},
	{0x146, SAA7134_PREFIX "LEVEL_READOUT1", 1},
	{0x147, SAA7134_PREFIX "LEVEL_READOUT2", 1},
	{0x148, SAA7134_PREFIX "NICAM_ERROR_LOW", 1},
	{0x149, SAA7134_PREFIX "NICAM_ERROR_HIGH", 1},
	{0x14a, SAA7134_PREFIX "DCXO_IDENT_CTRL", 1},
	{0x14b, SAA7134_PREFIX "DEMODULATOR", 1},
	{0x14c, SAA7134_PREFIX "AGC_GAIN_SELECT", 1},
	{0x150, SAA7134_PREFIX "CARRIER1_FREQ0", 1},
	{0x151, SAA7134_PREFIX "CARRIER1_FREQ1", 1},
	{0x152, SAA7134_PREFIX "CARRIER1_FREQ2", 1},
	{0x154, SAA7134_PREFIX "CARRIER2_FREQ0", 1},
	{0x155, SAA7134_PREFIX "CARRIER2_FREQ1", 1},
	{0x156, SAA7134_PREFIX "CARRIER2_FREQ2", 1},
	{0x158, SAA7134_PREFIX "NUM_SAMPLES0", 1},
	{0x159, SAA7134_PREFIX "NUM_SAMPLES1", 1},
	{0x15a, SAA7134_PREFIX "NUM_SAMPLES2", 1},
	{0x15b, SAA7134_PREFIX "AUDIO_FORMAT_CTRL", 1},
	{0x160, SAA7134_PREFIX "MONITOR_SELECT", 1},
	{0x161, SAA7134_PREFIX "FM_DEEMPHASIS", 1},
	{0x162, SAA7134_PREFIX "FM_DEMATRIX", 1},
	{0x163, SAA7134_PREFIX "CHANNEL1_LEVEL", 1},
	{0x164, SAA7134_PREFIX "CHANNEL2_LEVEL", 1},
	{0x165, SAA7134_PREFIX "NICAM_CONFIG", 1},
	{0x166, SAA7134_PREFIX "NICAM_LEVEL_ADJUST", 1},
	{0x167, SAA7134_PREFIX "STEREO_DAC_OUTPUT_SELECT", 1},
	{0x168, SAA7134_PREFIX "I2S_OUTPUT_FORMAT", 1},
	{0x169, SAA7134_PREFIX "I2S_OUTPUT_SELECT", 1},
	{0x16a, SAA7134_PREFIX "I2S_OUTPUT_LEVEL", 1},
	{0x16b, SAA7134_PREFIX "DSP_OUTPUT_SELECT", 1},
	{0x16c, SAA7134_PREFIX "AUDIO_MUTE_CTRL", 1},
	{0x16d, SAA7134_PREFIX "SIF_SAMPLE_FREQ", 1},
	{0x16e, SAA7134_PREFIX "ANALOG_IO_SELECT", 1},
	{0x170, SAA7134_PREFIX "AUDIO_CLOCK0", 1},
	{0x171, SAA7134_PREFIX "AUDIO_CLOCK1", 1},
	{0x172, SAA7134_PREFIX "AUDIO_CLOCK2", 1},
	{0x173, SAA7134_PREFIX "AUDIO_PLL_CTRL", 1},
	{0x174, SAA7134_PREFIX "AUDIO_CLOCKS_PER_FIELD0", 1},
	{0x175, SAA7134_PREFIX "AUDIO_CLOCKS_PER_FIELD1", 1},
	{0x176, SAA7134_PREFIX "AUDIO_CLOCKS_PER_FIELD2", 1},
	{0x190, SAA7134_PREFIX "VIDEO_PORT_CTRL0", 1},
	{0x191, SAA7134_PREFIX "VIDEO_PORT_CTRL1", 1},
	{0x192, SAA7134_PREFIX "VIDEO_PORT_CTRL2", 1},
	{0x193, SAA7134_PREFIX "VIDEO_PORT_CTRL3", 1},
	{0x194, SAA7134_PREFIX "VIDEO_PORT_CTRL4", 1},
	{0x195, SAA7134_PREFIX "VIDEO_PORT_CTRL5", 1},
	{0x196, SAA7134_PREFIX "VIDEO_PORT_CTRL6", 1},
	{0x197, SAA7134_PREFIX "VIDEO_PORT_CTRL7", 1},
	{0x198, SAA7134_PREFIX "VIDEO_PORT_CTRL8", 1},
	{0x1a0, SAA7134_PREFIX "TS_PARALLEL", 1},
	{0x1a1, SAA7134_PREFIX "TS_PARALLEL_SERIAL", 1},
	{0x1a2, SAA7134_PREFIX "TS_SERIAL0", 1},
	{0x1a3, SAA7134_PREFIX "TS_SERIAL1", 1},
	{0x1a4, SAA7134_PREFIX "TS_DMA0", 1},
	{0x1a5, SAA7134_PREFIX "TS_DMA1", 1},
	{0x1a6, SAA7134_PREFIX "TS_DMA2", 1},
	{0x1B0, SAA7134_PREFIX "GPIO_GPMODE0", 1},
	{0x1B1, SAA7134_PREFIX "GPIO_GPMODE1", 1},
	{0x1B2, SAA7134_PREFIX "GPIO_GPMODE2", 1},
	{0x1B3, SAA7134_PREFIX "GPIO_GPMODE3", 1},
	{0x1B4, SAA7134_PREFIX "GPIO_GPSTATUS0", 1},
	{0x1B5, SAA7134_PREFIX "GPIO_GPSTATUS1", 1},
	{0x1B6, SAA7134_PREFIX "GPIO_GPSTATUS2", 1},
	{0x1B7, SAA7134_PREFIX "GPIO_GPSTATUS3", 1},
	{0x1c0, SAA7134_PREFIX "I2S_AUDIO_OUTPUT", 1},
	{0x1d0, SAA7134_PREFIX "SPECIAL_MODE", 1},
	{0x1d1, SAA7134_PREFIX "PRODUCTION_TEST_MODE", 1},
	{0x580, SAA7135_PREFIX "DSP_RWSTATE", 1},
	{0x586, SAA7135_PREFIX "DSP_RWCLEAR", 1},
	{0x591, SAA7133_PREFIX "I2S_AUDIO_CONTROL", 1},
};
