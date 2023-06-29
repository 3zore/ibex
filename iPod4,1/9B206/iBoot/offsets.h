/*
 *  ibex - target specific addresses
 *
 *  Copyright (c) 2010, 2015 xerub
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef OFFSETS_H_included
#define OFFSETS_H_included

#define TARGET_BASEADDR			0x5FF00000
#define TARGET_LOADADDR			0x40000000
#define TARGET_JUMPADDR			0x44000000

#define TARGET_PRINTF			(0x2d6d0 + 1)
#define TARGET_SNPRINTF			(0x2d6d0 + 1)
#define TARGET_MEMMOVE			(0x2da24)
#define TARGET_ENTER_CRITICAL_SECTION	(0x18428 + 1)
#define TARGET_EXIT_CRITICAL_SECTION	(0x18524 + 1)
#define TARGET_AES_CRYPTO_CMD		(0x1ce4  + 1)
#define TARGET_MALLOC			(0x12e14 + 1)
#define TARGET_FREE			(0x12ec4 + 1)
#define TARGET_JUMPTO			(0x1800c + 1)
#define TARGET_H2FMI_SELECT		(0x2890 + 1)
#define TARGET_CREATE_ENVVAR		(0x11540 + 1)
#define TARGET_FS_MOUNT			(0x1c310 + 1)
#define TARGET_FS_LOADFILE		(0x1c490 + 1)

#define TARGET_BDEV_STACK		(0x402d0)
#define TARGET_IMAGE_LIST		(0x392e0)

#endif