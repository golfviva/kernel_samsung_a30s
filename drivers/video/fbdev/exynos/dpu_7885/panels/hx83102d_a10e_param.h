#ifndef __HX83102D_PARAM_H__
#define __HX83102D_PARAM_H__
#include <linux/types.h>
#include <linux/kernel.h>

#define EXTEND_BRIGHTNESS	306
#define UI_MAX_BRIGHTNESS	255
#define UI_DEFAULT_BRIGHTNESS	128

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

#define TYPE_WRITE	I2C_SMBUS_WRITE
#define TYPE_DELAY	U8_MAX

/* 0x20 for Enable */
enum {
	S2DPS01_BL_EN	= 0,
	S2DPS01_LCD_EN	= 1,
	S2DPS01_VPOS_EN	= 2,
	S2DPS01_VNEG_EN	= 3,
	S2DPS01_SVDD_EN	= 4,
};

static u8 S2DPS01_INIT[] = {
	TYPE_WRITE, 0x0E, 0x41,
	TYPE_WRITE, 0x11, 0xDF,
	TYPE_WRITE, 0x1C, 0x10,
	TYPE_WRITE, 0x1D, 0x86,
	TYPE_WRITE, 0x1E, 0x58,
	TYPE_WRITE, 0x1F, 0x12,
	TYPE_WRITE, 0x21, 0x0F,
	TYPE_WRITE, 0x22, 0x00,
	TYPE_WRITE, 0x23, 0x00,
	TYPE_WRITE, 0x24, 0x00,
	TYPE_WRITE, 0x25, 0x01,
	TYPE_WRITE, 0x26, 0x02,
	TYPE_WRITE, 0x20, BIT(S2DPS01_VPOS_EN),							/* 0x04 */
	TYPE_DELAY, 5, 0,
	TYPE_WRITE, 0x20, BIT(S2DPS01_VPOS_EN) | BIT(S2DPS01_VNEG_EN),				/* 0x0C */
	TYPE_DELAY, 5, 0,
	TYPE_WRITE, 0x20, BIT(S2DPS01_VPOS_EN) | BIT(S2DPS01_VNEG_EN) | BIT(S2DPS01_BL_EN),	/* 0x0D */
};

static u8 S2DPS01_EXIT[] = {
	TYPE_WRITE, 0x20, BIT(S2DPS01_VPOS_EN) | BIT(S2DPS01_VNEG_EN),				/* 0x0C */
	TYPE_WRITE, 0x20, BIT(S2DPS01_VPOS_EN),							/* 0x04 */
	TYPE_DELAY, 3, 0,
	TYPE_WRITE, 0x20, 0x00,
	TYPE_DELAY, 3, 0,
};

static const unsigned char SEQ_SET_B9_EXTC[] = {
	0xB9,
	0x83, 0x10, 0x2D
};

static const unsigned char SEQ_SET_B1_POWER[] = {
	0xB1,
	0x22, 0x44, 0x31, 0x31, 0x22, 0x34, 0x2F, 0x57,
	0x08, 0x08, 0x08, 0x67, 0x67, 0x71,
};


static const unsigned char SEQ_SET_B2_DISPLSAY[] = {
	0xB2,
	0x00, 0x00, 0x06, 0x18, 0x00, 0x0E, 0xFE, 0x40,
	0x00, 0x00, 0x00, 0x00, 0xF4, 0xA0,
};

static const unsigned char SEQ_SET_B4_TIMING[] = {
	0xB4,
	0x19, 0x59, 0x19, 0x59, 0x19, 0x59, 0x19, 0x59,
	0x06, 0xFF, 0x06, 0x20, 0x00, 0xFF,
};

static const unsigned char SEQ_SET_CC_PANEL_TYPE[] = {
	0xCC,
	0x02,
};

static const unsigned char SEQ_SET_D3_GIP[] = {
	0xD3,
	0x00, 0x00, 0x3C, 0x03, 0x00, 0x08, 0x00, 0x37,
	0x00, 0x33, 0x33, 0x08, 0x08, 0x00, 0x00, 0x32,
	0x10, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x05, 0x12, 0x00, 0x00,
};

static const unsigned char SEQ_SET_D5_GIP[] = {
	0xD5,
	0x18, 0x18, 0x18, 0x18, 0x39, 0x39, 0x18, 0x18,
	0x20, 0x21, 0x22, 0x23, 0x19, 0x19, 0x19, 0x19,
	0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03,
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18,
};

static const unsigned char SEQ_SET_D6_GIP[] = {
	0xD6,
	0x18, 0x18, 0x19, 0x19, 0x39, 0x39, 0x18, 0x18,
	0x23, 0x22, 0x21, 0x20, 0x18, 0x18, 0x19, 0x19,
	0x03, 0x02, 0x01, 0x00, 0x07, 0x06, 0x05, 0x04,
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18,
};

static const unsigned char SEQ_SET_E7_BANK0_TP[] = {
	0xE7,
	0xFF, 0x0F, 0x00, 0x00,
};

static const unsigned char SEQ_SET_BD_SWITCH_BANK1[] = {
	0xBD,
	0x01,
};

static const unsigned char SEQ_SET_E7_BANK1_TP[] = {
	0xE7,
	0x01,
};

static const unsigned char SEQ_SET_BD_SWITCH_BANK0[] = {
	0xBD,
	0x00,
};

static const unsigned char SEQ_SET_BD_SWITCH_BANK2[] = {
	0xBD,
	0x02,
};

static const unsigned char SEQ_SET_D8_BANK2[] = {
	0xD8,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xF0,
};

static const unsigned char SEQ_SET_BD_SWITCH_BANK3[] = {
	0xBD,
	0x03
};

static const unsigned char SEQ_SET_D8_BANK3[] = {
	0xD8,
	0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0xAA, 0xAA,
	0xAA, 0xAA, 0xAA, 0xA0, 0xAA, 0xAA, 0xAA, 0xAA,
	0xAA, 0xA0, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA0,
};

static const unsigned char SEQ_SET_E0_GAMMA[] = {
	0xE0,
	0x00, 0x01, 0x06, 0x0A, 0x0F, 0x11, 0x27, 0x2F,
	0x39, 0x39, 0x5C, 0x64, 0x72, 0x82, 0x87, 0x96,
	0xA3, 0xC4, 0xC6, 0x63, 0x6C, 0x77, 0x7F, 0x00,
	0x01, 0x06, 0x0A, 0x0F, 0x11, 0x27, 0x2F, 0x39,
	0x39, 0x5C, 0x6E, 0x7A, 0x98, 0x9B, 0xAA, 0xB7,
	0xC4, 0xC6, 0x63, 0x6C, 0x77, 0x7F,
};

static const unsigned char SEQ_SET_BA_DSI[] = {
	0xBA,
	0x70, 0x23, 0xA8, 0x8B, 0xB2, 0x80, 0x80, 0x01,
	0x10, 0x00, 0x00, 0x00, 0x08, 0x3D, 0x02, 0x77,
	0x04, 0x01, 0x00,
};

static const unsigned char SEQ_SET_CB_BANK1[] = {
	0xCB,
	0x01
};

static const unsigned char SEQ_SET_CB_BANK0[] = {
	0xCB,
	0x00, 0x53, 0x00, 0x02, 0x6C,
};

static const unsigned char SEQ_SET_BF_POWER[] = {
	0xBF,
	0xFC, 0x00, 0x24, 0x9E, 0xF6, 0x00, 0x5D,
};

static const unsigned char SEQ_SET_B4_BANK2[] = {
	0xB4,
	0x42, 0x00, 0x33, 0x00, 0x33, 0x88, 0xB3, 0x00,
};

static const unsigned char SEQ_SET_D1_TP[] = {
	0xD1,
	0x20, 0x01,
};

static const unsigned char SEQ_SET_B1_BANK2[] = {
	0xB1,
	0x7F, 0x03, 0xFF,
};

static const unsigned char SEQ_SET_D3_BANK1[] = {
	0xD3,
	0x01, 0x00, 0x39,
};

static const unsigned char SEQ_SLEEP_OUT[] = {
	0x11,
};

static const unsigned char SEQ_DISPLAY_ON[] = {
	0x29,
};

static const unsigned char SEQ_DISPLAY_OFF[] = {
	0x28,
	0x00, 0x00
};

static const unsigned char SEQ_SLEEP_IN[] = {
	0x10,
	0x00, 0x00
};

static const unsigned char SEQ_SET_C9_CABC_PWM[] = {
	0xC9,
	0x04, 0x65, 0x90, 0x01,
};

static const unsigned char SEQ_HX83102D_BL[] = {
	0x51,
	0x00, 0x00,
};

static const unsigned char SEQ_HX83102D_BLON[] = {
	0x53,
	0x24,
};

#if defined(CONFIG_EXYNOS_DECON_LCD_HX83102D_A10E_JPN)
/* platform brightness <-> bl reg */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	0,
	20, 21, 23, 25, 27, 28, 30, 32, 34, 36, /* 1: 20 */
	37, 39, 41, 43, 44, 46, 48, 50, 52, 53,
	55, 57, 59, 60, 62, 64, 66, 68, 69, 71,
	73, 75, 76, 78, 80, 82, 84, 85, 87, 89,
	91, 92, 94, 96, 98, 100, 101, 103, 105, 107,
	108, 110, 112, 114, 116, 117, 119, 121, 123, 124,
	126, 128, 130, 132, 133, 135, 137, 139, 141, 142,
	144, 146, 148, 149, 151, 153, 155, 157, 158, 160,
	162, 164, 165, 167, 169, 171, 173, 174, 176, 178,
	180, 181, 183, 185, 187, 189, 190, 192, 194, 196,
	197, 199, 201, 203, 205, 206, 208, 210, 212, 213,
	215, 217, 219, 221, 222, 224, 226, 228, 229, 231,
	233, 235, 237, 238, 240, 242, 244, 246, 263, 280, /* 128: 246 */
	297, 314, 332, 349, 366, 383, 401, 418, 435, 452,
	469, 487, 504, 521, 538, 556, 573, 590, 607, 625,
	642, 659, 676, 693, 711, 728, 745, 762, 780, 797,
	814, 831, 848, 866, 883, 900, 917, 935, 952, 969,
	986, 1004, 1021, 1038, 1055, 1072, 1090, 1107, 1124, 1141,
	1159, 1176, 1193, 1210, 1228, 1245, 1262, 1279, 1296, 1314,
	1331, 1348, 1365, 1383, 1400, 1417, 1434, 1451, 1469, 1486,
	1503, 1520, 1538, 1555, 1572, 1589, 1607, 1624, 1641, 1658,
	1675, 1693, 1710, 1727, 1744, 1762, 1779, 1796, 1813, 1831,
	1848, 1865, 1882, 1899, 1917, 1934, 1951, 1968, 1986, 2003,
	2020, 2037, 2054, 2072, 2089, 2106, 2123, 2141, 2158, 2175,
	2192, 2210, 2227, 2244, 2261, 2278, 2296, 2313, 2330, 2347,
	2365, 2382, 2399, 2416, 2434, 2434, 2434, 2434, 2434, 2434, /* 255: 2434 */
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2840,
};
#else
/* platform brightness <-> bl reg */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	0,
	20, 27, 35, 42, 50, 57, 65, 72, 80, 88,	/* 1: 20 */
	95, 103, 110, 118, 125, 133, 140, 148, 156, 163,
	171, 178, 186, 193, 201, 208, 216, 224, 231, 239,
	246, 254, 261, 269, 277, 284, 292, 299, 307, 314,
	322, 329, 337, 345, 352, 360, 367, 375, 382, 390,
	397, 405, 413, 420, 428, 435, 443, 450, 458, 465,
	473, 481, 488, 496, 503, 511, 518, 526, 534, 541,
	549, 556, 564, 571, 579, 586, 594, 602, 609, 617,
	624, 632, 639, 647, 654, 662, 670, 677, 685, 692,
	700, 707, 715, 722, 730, 738, 745, 753, 760, 768,
	775, 783, 791, 798, 806, 813, 821, 828, 836, 843,
	851, 859, 866, 874, 881, 889, 896, 904, 911, 919,
	927, 934, 942, 949, 957, 964, 972, 980, 991, 1002,	/* 128: 980 */
	1014, 1025, 1037, 1048, 1060, 1071, 1083, 1094, 1105, 1117,
	1128, 1140, 1151, 1163, 1174, 1186, 1197, 1208, 1220, 1231,
	1243, 1254, 1266, 1277, 1289, 1300, 1312, 1323, 1334, 1346,
	1357, 1369, 1380, 1392, 1403, 1415, 1426, 1437, 1449, 1460,
	1472, 1483, 1495, 1506, 1518, 1529, 1540, 1552, 1563, 1575,
	1586, 1598, 1609, 1621, 1632, 1644, 1655, 1666, 1678, 1689,
	1701, 1712, 1724, 1735, 1747, 1758, 1769, 1781, 1792, 1804,
	1815, 1827, 1838, 1850, 1861, 1873, 1884, 1895, 1907, 1918,
	1930, 1941, 1953, 1964, 1976, 1987, 1998, 2010, 2021, 2033,
	2044, 2056, 2067, 2079, 2090, 2101, 2113, 2124, 2136, 2147,
	2159, 2170, 2182, 2193, 2205, 2216, 2227, 2239, 2250, 2262,
	2273, 2285, 2296, 2308, 2319, 2330, 2342, 2353, 2365, 2376,
	2388, 2399, 2411, 2422, 2434, 2434, 2434, 2434, 2434, 2434,	/* 255: 2434 */
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434, 2434,
	2434, 2434, 2434, 2434, 2434, 2840,
};
#endif
#endif /* __HX83102D_PARAM_H__ */
