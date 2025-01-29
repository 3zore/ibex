/*
 *  ibex - misc stuff
 *
 *  Copyright (c) 2025 m1zole
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

#include "plib.h"
#include "misc.h"

unsigned char wapper[] = {
  0xf0, 0xb5, 0x03, 0xaf, 0x84, 0xb0, 0xbc, 0x68, 0x00, 0x90, 0x01, 0x91,
  0x02, 0x92, 0x03, 0x93, 0x0b, 0x1c, 0x11, 0x1c, 0x22, 0x1c, 0x1b, 0x48,
  0x00, 0xf0, 0x0f, 0xf8, 0x00, 0x98, 0x01, 0x99, 0x02, 0x9a, 0x03, 0x9b,
  0x00, 0x94, 0x00, 0x68, 0xc4, 0x69, 0xa0, 0x47, 0x01, 0x1c, 0x16, 0x48,
  0x00, 0xf0, 0x03, 0xf8, 0x08, 0x1c, 0x04, 0xb0, 0xf0, 0xbd, 0xff, 0xb5,
  0x13, 0x4c, 0xa0, 0x47, 0xff, 0xbd, 0x48, 0x46, 0x53, 0x52, 0x65, 0x61,
  0x64, 0x42, 0x6c, 0x6f, 0x63, 0x6b, 0x3a, 0x20, 0x6f, 0x66, 0x66, 0x73,
  0x65, 0x74, 0x20, 0x30, 0x78, 0x25, 0x78, 0x20, 0x73, 0x69, 0x7a, 0x65,
  0x20, 0x30, 0x78, 0x25, 0x78, 0x20, 0x62, 0x75, 0x66, 0x66, 0x65, 0x72,
  0x20, 0x30, 0x78, 0x25, 0x78, 0x0a, 0x00, 0x52, 0x65, 0x74, 0x75, 0x72,
  0x6e, 0x65, 0x64, 0x3a, 0x20, 0x30, 0x78, 0x25, 0x78, 0x0a, 0x00, 0x00
};

int wapper_len = 132;

unsigned int
make_b(int pos, int tgt)
{
    int delta;
    unsigned short pfx;
    unsigned short sfx;

    unsigned int omask = 0xB800;
    unsigned int amask = 0x7FF;

    delta = tgt - pos - 4; /* range: 0x400000 */
    pfx = 0xF000 | ((delta >> 12) & 0x7FF);
    sfx =  omask | ((delta >>  1) & amask);

    return (unsigned int)pfx | ((unsigned int)sfx << 16);
}

int
hfswapperinject(void)
{
    int i;
    unsigned int addr = TARGET_BASEADDR + 0x108;
    unsigned int inst;
    
    for (i = 0; i < wapper_len; i++, addr++) {
        unsigned char val = wapper[i];
        *(unsigned char *)addr = val;
    }
    
    *(unsigned int *)addr = TARGET_BASEADDR + 0x14A;
    *(unsigned int *)(addr + 4) = TARGET_BASEADDR + 0x17B;
    *(unsigned int *)(addr + 8) = (unsigned int)printf_;
    
    if (!hfsreadblock) {
        return -1;
    }
    
    inst = make_b((unsigned int)hfsreadblock - 1, TARGET_BASEADDR + 0x108);
    printf_("inst: %x\n", inst);
    *(unsigned int*)((unsigned int)hfsreadblock - 1) = inst;
    
    flush_icache();
    
    printf_("hfsreadblock: %x\n", (unsigned int)hfsreadblock - 1);
    printf_("%x: %02x%02x%02x%02x\n",   (unsigned int)hfsreadblock - 1,
                                        *(unsigned char *)((unsigned int)hfsreadblock - 1),
                                        *(unsigned char *)((unsigned int)hfsreadblock),
                                        *(unsigned char *)((unsigned int)hfsreadblock + 1),
                                        *(unsigned char *)((unsigned int)hfsreadblock + 2));
    printf_("wapper: %x\n", TARGET_BASEADDR + 0x108);
    
    return 0;
}
