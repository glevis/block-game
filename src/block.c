#include "../include/block.h"
#include <stdlib.h>
#include <stdio.h>

void block_init(struct block_t *block, block_type_t type) {

    //TODO: Change texture based on block type.

    //((32 * (int) type) % 32) + 0.0 / 32.0;
    float side_texture_pos = ((620 % 32) + 0.0) / 32.0;
    float top_texture_pos = ((620 % 32) + 0.0) / 32.0;
    float bot_texture_pos = ((620 % 32) + 0.0) / 32.0;

    if (type != grass) {
        top_texture_pos = side_texture_pos;
        bot_texture_pos = side_texture_pos;
    }
    
    block->vertices[0] = -0.5f; 
    block->vertices[1] = -0.5f; 
    block->vertices[2] = -0.5f; 
    block->vertices[3] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[4] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[5] = 0.5f; 
    block->vertices[6] = -0.5f; 
    block->vertices[7] = -0.5f; 
    block->vertices[8] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[9] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[10] = 0.5f; 
    block->vertices[11] = 0.5f; 
    block->vertices[12] = -0.5f; 
    block->vertices[13] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[14] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[15] = 0.5f; 
    block->vertices[16] = 0.5f; 
    block->vertices[17] = -0.5f; 
    block->vertices[18] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[19] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[20] = -0.5f; 
    block->vertices[21] = 0.5f; 
    block->vertices[22] = -0.5f; 
    block->vertices[23] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[24] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[25] = -0.5f; 
    block->vertices[26] = -0.5f; 
    block->vertices[27] = -0.5f; 
    block->vertices[28] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[29] = ((672 / 32.0) + 0.0f) / 32.0;

    block->vertices[30] = -0.5f; 
    block->vertices[31] = -0.5f; 
    block->vertices[32] = 0.5f; 
    block->vertices[33] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[34] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[35] = 0.5f; 
    block->vertices[36] = -0.5f; 
    block->vertices[37] = 0.5f; 
    block->vertices[38] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[39] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[40] = 0.5f; 
    block->vertices[41] = 0.5f; 
    block->vertices[42] = 0.5f; 
    block->vertices[43] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[44] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[45] = 0.5f; 
    block->vertices[46] = 0.5f; 
    block->vertices[47] = 0.5f; 
    block->vertices[48] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[49] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[50] = -0.5f; 
    block->vertices[51] = 0.5f; 
    block->vertices[52] = 0.5f; 
    block->vertices[53] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[54] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[55] = -0.5f; 
    block->vertices[56] = -0.5f; 
    block->vertices[57] = 0.5f; 
    block->vertices[58] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[59] = ((672 / 32.0) + 0.0f) / 32.0;

    block->vertices[60] = -0.5f; 
    block->vertices[61] = 0.5f; 
    block->vertices[62] = 0.5f; 
    block->vertices[63] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[64] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[65] = -0.5f; 
    block->vertices[66] = 0.5f; 
    block->vertices[67] = -0.5f; 
    block->vertices[68] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[69] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[70] = -0.5f; 
    block->vertices[71] = -0.5f; 
    block->vertices[72] = -0.5f; 
    block->vertices[73] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[74] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[75] = -0.5f; 
    block->vertices[76] = -0.5f; 
    block->vertices[77] = -0.5f; 
    block->vertices[78] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[79] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[80] = -0.5f; 
    block->vertices[81] = -0.5f; 
    block->vertices[82] = 0.5f; 
    block->vertices[83] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[84] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[85] = -0.5f; 
    block->vertices[86] = 0.5f; 
    block->vertices[87] = 0.5f; 
    block->vertices[88] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[89] = ((672 / 32.0) + 1.0f) / 32.0;

    block->vertices[90] = 0.5f; 
    block->vertices[91] = 0.5f; 
    block->vertices[92] = 0.5f; 
    block->vertices[93] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[94] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[95] = 0.5f; 
    block->vertices[96] = 0.5f; 
    block->vertices[97] = -0.5f; 
    block->vertices[98] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[99] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[100] = 0.5f; 
    block->vertices[101] = -0.5f; 
    block->vertices[102] = -0.5f; 
    block->vertices[103] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[104] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[105] = 0.5f; 
    block->vertices[106] = -0.5f; 
    block->vertices[107] = -0.5f; 
    block->vertices[108] = ((620 % 32) + 0.0f) / 32.0;
    block->vertices[109] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[110] = 0.5f; 
    block->vertices[111] = -0.5f; 
    block->vertices[112] = 0.5f; 
    block->vertices[113] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[114] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[115] = 0.5f; 
    block->vertices[116] = 0.5f; 
    block->vertices[117] = 0.5f; 
    block->vertices[118] = ((620 % 32) + 1.0f) / 32.0;
    block->vertices[119] = ((672 / 32.0) + 1.0f) / 32.0;

    block->vertices[120] = -0.5f;                             //bottom
    block->vertices[121] = -0.5f; 
    block->vertices[122] = -0.5f; 
    block->vertices[123] = ((616 % 32) + 0.0f) / 32.0;
    block->vertices[124] = ((800 / 32.0) + 0.0f) / 32.0;
    block->vertices[125] = 0.5f; 
    block->vertices[126] = -0.5f; 
    block->vertices[127] = -0.5f; 
    block->vertices[128] = ((616 % 32) + 1.0f) / 32.0;
    block->vertices[129] = ((800 / 32.0) + 0.0f) / 32.0;
    block->vertices[130] = 0.5f; 
    block->vertices[131] = -0.5f; 
    block->vertices[132] = 0.5f; 
    block->vertices[133] = ((616 % 32) + 1.0f) / 32.0;
    block->vertices[134] = ((800 / 32.0) + 1.0f) / 32.0;
    block->vertices[135] = 0.5f; 
    block->vertices[136] = -0.5f; 
    block->vertices[137] = 0.5f; 
    block->vertices[138] = ((616 % 32) + 1.0f) / 32.0;
    block->vertices[139] = ((800 / 32.0) + 1.0f) / 32.0;
    block->vertices[140] = -0.5f; 
    block->vertices[141] = -0.5f; 
    block->vertices[142] = 0.5f; 
    block->vertices[143] = ((616 % 32) + 0.0f) / 32.0;
    block->vertices[144] = ((800 / 32.0) + 1.0f) / 32.0;
    block->vertices[145] = -0.5f; 
    block->vertices[146] = -0.5f; 
    block->vertices[147] = -0.5f; 
    block->vertices[148] = ((616 % 32) + 0.0f) / 32.0;
    block->vertices[149] = ((800 / 32.0) + 0.0f) / 32.0;

    block->vertices[150] = 0.5f; 
    block->vertices[151] = 0.5f; 
    block->vertices[152] = -0.5f; 
    block->vertices[153] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[154] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[155] = -0.5f;                             //top
    block->vertices[156] = 0.5f; 
    block->vertices[157] = -0.5f; 
    block->vertices[158] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[159] = ((672 / 32.0) + 0.0f) / 32.0;
    block->vertices[160] = -0.5f; 
    block->vertices[161] = 0.5f; 
    block->vertices[162] = 0.5f; 
    block->vertices[163] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[164] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[165] = -0.5f; 
    block->vertices[166] = 0.5f; 
    block->vertices[167] = 0.5f; 
    block->vertices[168] = ((623 % 32) + 0.0f) / 32.0;
    block->vertices[169] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[170] = 0.5f; 
    block->vertices[171] = 0.5f; 
    block->vertices[172] = 0.5f; 
    block->vertices[173] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[174] = ((672 / 32.0) + 1.0f) / 32.0;
    block->vertices[175] = 0.5f; 
    block->vertices[176] = 0.5f; 
    block->vertices[177] = -0.5f; 
    block->vertices[178] = ((623 % 32) + 1.0f) / 32.0;
    block->vertices[179] = ((672 / 32.0) + 0.0f) / 32.0;

    printf("block initiated\n");
}
