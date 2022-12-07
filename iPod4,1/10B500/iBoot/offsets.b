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

#define TARGET_PRINTF			(0x32699 + 1)
#define TARGET_SNPRINTF			(0x32ced + 1)
#define TARGET_MEMMOVE			(0x3317c)
#define TARGET_ENTER_CRITICAL_SECTION	(0x1d2b9 + 1)
#define TARGET_EXIT_CRITICAL_SECTION	(0x1d325 + 1)
#define TARGET_AES_CRYPTO_CMD		(0x1f141  + 1)
#define TARGET_MALLOC			(0x176cd + 1)
#define TARGET_FREE			(0x1777d + 1)
#define TARGET_JUMPTO			(0x1cef1 + 1)
#define TARGET_H2FMI_SELECT		(0x02ab1 + 1)
#define TARGET_CREATE_ENVVAR		(0x15ef5 + 1)
#define TARGET_FS_MOUNT			(0x21869 + 1)
#define TARGET_FS_LOADFILE		(0x21ae5 + 1)

#define TARGET_BDEV_STACK		(0x44e7c)
#define TARGET_IMAGE_LIST		(0x422a8)

#endif
