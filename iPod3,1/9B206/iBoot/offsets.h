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

#define TARGET_BASEADDR			0x4FF00000
#define TARGET_LOADADDR			0x40000000
#define TARGET_JUMPADDR			0x44000000

#define TARGET_PRINTF			(0x240d4 + 1)
#define TARGET_SNPRINTF			(0x2a10b + 1)
#define TARGET_MEMMOVE			(0x24428)
#define TARGET_ENTER_CRITICAL_SECTION	(0x16034 + 1)
#define TARGET_EXIT_CRITICAL_SECTION	(0x16130 + 1)
#define TARGET_AES_CRYPTO_CMD		(0x1b4c  + 1)
#define TARGET_MALLOC			(0x10c20 + 1)
#define TARGET_FREE			(0x10cd0 + 1)
#define TARGET_JUMPTO			(0x15c18 + 1)
#define TARGET_H2FMI_SELECT		(0x2004 + 1)
#define TARGET_CREATE_ENVVAR		(0xf34c + 1)
#define TARGET_FS_MOUNT			(0x19f14 + 1)
#define TARGET_FS_LOADFILE		(0x1a094 + 1)

#define TARGET_BDEV_STACK		(0x36ce0)
#define TARGET_IMAGE_LIST		(0x2e294)

#endif
