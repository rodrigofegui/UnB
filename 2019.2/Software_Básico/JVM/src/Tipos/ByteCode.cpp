#include <iostream>
#include "../../lib/Tipos/ByteCode.hpp"

std::vector<ByteCode> bytecodes;

void iniciar_bytecodes (){
    // 0 (0x00)
    bytecodes.push_back({"nop", nullptr, nullptr});

    // 1 (0x01)
    bytecodes.push_back({"aconst_null", nullptr, nullptr});
    // 2 (0x02)
    bytecodes.push_back({"iconst_null", nullptr, nullptr});
    // 3 (0x03)
    bytecodes.push_back({"iconst_0", nullptr, nullptr});
    // 4 (0x04)
    bytecodes.push_back({"iconst_1", nullptr, nullptr});
    // 5 (0x05)
    bytecodes.push_back({"iconst_2", nullptr, nullptr});

    // 6 (0x06)
    bytecodes.push_back({"iconst_3", nullptr, nullptr});
    // 7 (0x07)
    bytecodes.push_back({"iconst_4", nullptr, nullptr});
    // 8 (0x08)
    bytecodes.push_back({"iconst_5", nullptr, nullptr});
    // 9 (0x09)
    bytecodes.push_back({"lconst_0", nullptr, nullptr});
    // 10 (0x0A)
    bytecodes.push_back({"lconst_1", nullptr, nullptr});

    // 11 (0x0B)
    bytecodes.push_back({"fconst_0", nullptr, nullptr});
    // 12 (0x0C)
    bytecodes.push_back({"fconst_1", nullptr, nullptr});
    // 13 (0x0D)
    bytecodes.push_back({"fconst_2", nullptr, nullptr});
    // 14 (0x0E)
    bytecodes.push_back({"dconst_0", nullptr, nullptr});
    // 15 (0x0F)
    bytecodes.push_back({"dconst_1", nullptr, nullptr});

    // 16 (0x10)
    bytecodes.push_back({"bipush", nullptr, nullptr});
    // 17 (0x11)
    bytecodes.push_back({"sipush", nullptr, nullptr});
    // 18 (0x12)
    bytecodes.push_back({"ldc", nullptr, nullptr});
    // 19 (0x13)
    bytecodes.push_back({"ldc_w", nullptr, nullptr});
    // 20 (0x14)
    bytecodes.push_back({"ldc2_w", nullptr, nullptr});

    // 21 (0x15)
    bytecodes.push_back({"iload", nullptr, nullptr});
    // 22 (0x16)
    bytecodes.push_back({"lload", nullptr, nullptr});
    // 23 (0x17)
    bytecodes.push_back({"fload", nullptr, nullptr});
    // 24 (0x18)
    bytecodes.push_back({"dload", nullptr, nullptr});
    // 25 (0x19)
    bytecodes.push_back({"aload", nullptr, nullptr});

    // 26 (0x1A)
    bytecodes.push_back({"iload_0", nullptr, nullptr});
    // 27 (0x1B)
    bytecodes.push_back({"iload_1", nullptr, nullptr});
    // 28 (0x1C)
    bytecodes.push_back({"iload_2", nullptr, nullptr});
    // 29 (0x1D)
    bytecodes.push_back({"iload_3", nullptr, nullptr});
    // 30 (0x1E)
    bytecodes.push_back({"lload_0", nullptr, nullptr});

    // 31 (0x1F)
    bytecodes.push_back({"lload_1", nullptr, nullptr});
    // 32 (0x20)
    bytecodes.push_back({"lload_2", nullptr, nullptr});
    // 33 (0x21)
    bytecodes.push_back({"lload_3", nullptr, nullptr});
    // 34 (0x22)
    bytecodes.push_back({"fload_0", nullptr, nullptr});
    // 35 (0x23)
    bytecodes.push_back({"fload_1", nullptr, nullptr});

    // 36 (0x24)
    bytecodes.push_back({"fload_2", nullptr, nullptr});
    // 37 (0x25)
    bytecodes.push_back({"fload_3", nullptr, nullptr});
    // 38 (0x26)
    bytecodes.push_back({"dload_0", nullptr, nullptr});
    // 39 (0x27)
    bytecodes.push_back({"dload_1", nullptr, nullptr});
    // 40 (0x28)
    bytecodes.push_back({"dload_2", nullptr, nullptr});

    // 41 (0x29)
    bytecodes.push_back({"dload_3", nullptr, nullptr});
    // 42 (0x2A)
    bytecodes.push_back({"aload_0", nullptr, nullptr});
    // 43 (0x2B)
    bytecodes.push_back({"aload_1", nullptr, nullptr});
    // 44 (0x2C)
    bytecodes.push_back({"aload_2", nullptr, nullptr});
    // 45 (0x2D)
    bytecodes.push_back({"aload_3", nullptr, nullptr});

    // 46 (0x2E)
    bytecodes.push_back({"iaload", nullptr, nullptr});
    // 47 (0x2F)
    bytecodes.push_back({"laload", nullptr, nullptr});
    // 48 (0x30)
    bytecodes.push_back({"faload", nullptr, nullptr});
    // 49 (0x31)
    bytecodes.push_back({"daload", nullptr, nullptr});
    // 50 (0x32)
    bytecodes.push_back({"aaload", nullptr, nullptr});

    // 51 (0x33)
    bytecodes.push_back({"baload", nullptr, nullptr});
    // 52 (0x34)
    bytecodes.push_back({"caload", nullptr, nullptr});
    // 53 (0x35)
    bytecodes.push_back({"saload", nullptr, nullptr});
    // 54 (0x36)
    bytecodes.push_back({"istore", nullptr, nullptr});
    // 55 (0x37)
    bytecodes.push_back({"lstore", nullptr, nullptr});

    // 56 (0x38)
    bytecodes.push_back({"fstore", nullptr, nullptr});
    // 57 (0x39)
    bytecodes.push_back({"dstore", nullptr, nullptr});
    // 58 (0x3A)
    bytecodes.push_back({"astore", nullptr, nullptr});
    // 59 (0x3B)
    bytecodes.push_back({"istore_0", nullptr, nullptr});
    // 60 (0x3C)
    bytecodes.push_back({"istore_1", nullptr, nullptr});

    // 61 (0x3D)
    bytecodes.push_back({"istore_2", nullptr, nullptr});
    // 62 (0x3E)
    bytecodes.push_back({"istore_3", nullptr, nullptr});
    // 63 (0x3F)
    bytecodes.push_back({"lstore_0", nullptr, nullptr});
    // 64 (0x40)
    bytecodes.push_back({"lstore_1", nullptr, nullptr});
    // 65 (0x41)
    bytecodes.push_back({"lstore_2", nullptr, nullptr});

    // 66 (0x42)
    bytecodes.push_back({"lstore_3", nullptr, nullptr});
    // 67 (0x43)
    bytecodes.push_back({"fstore_0", nullptr, nullptr});
    // 68 (0x44)
    bytecodes.push_back({"fstore_1", nullptr, nullptr});
    // 69 (0x45)
    bytecodes.push_back({"fstore_2", nullptr, nullptr});
    // 70 (0x46)
    bytecodes.push_back({"fstore_3", nullptr, nullptr});

    // 71 (0x47)
    bytecodes.push_back({"dstore_0", nullptr, nullptr});
    // 72 (0x48)
    bytecodes.push_back({"dstore_1", nullptr, nullptr});
    // 73 (0x49)
    bytecodes.push_back({"dstore_2", nullptr, nullptr});
    // 74 (0x4A)
    bytecodes.push_back({"dstore_3", nullptr, nullptr});
    // 75 (0x4B)
    bytecodes.push_back({"astore_0", nullptr, nullptr});

    // 76 (0x4C)
    bytecodes.push_back({"astore_1", nullptr, nullptr});
    // 77 (0x4D)
    bytecodes.push_back({"astore_2", nullptr, nullptr});
    // 78 (0x4E)
    bytecodes.push_back({"astore_3", nullptr, nullptr});
    // 79 (0x4F)
    bytecodes.push_back({"iastore", nullptr, nullptr});
    // 80 (0x50)
    bytecodes.push_back({"lastore", nullptr, nullptr});

    // 81 (0x51)
    bytecodes.push_back({"fastore", nullptr, nullptr});
    // 82 (0x52)
    bytecodes.push_back({"dastore", nullptr, nullptr});
    // 83 (0x53)
    bytecodes.push_back({"aastore", nullptr, nullptr});
    // 84 (0x54)
    bytecodes.push_back({"bastore", nullptr, nullptr});
    // 85 (0x55)
    bytecodes.push_back({"castore", nullptr, nullptr});

    // 86 (0x56)
    bytecodes.push_back({"sastore", nullptr, nullptr});
    // 87 (0x57)
    bytecodes.push_back({"pop", nullptr, nullptr});
    // 88 (0x58)
    bytecodes.push_back({"pop2", nullptr, nullptr});
    // 89 (0x59)
    bytecodes.push_back({"dup", nullptr, nullptr});
    // 90 (0x5A)
    bytecodes.push_back({"dup_x1", nullptr, nullptr});

    // 91 (0x5B)
    bytecodes.push_back({"dup_x2", nullptr, nullptr});
    // 92 (0x5C)
    bytecodes.push_back({"dup2", nullptr, nullptr});
    // 93 (0x5D)
    bytecodes.push_back({"dup2_x1", nullptr, nullptr});
    // 94 (0x5E)
    bytecodes.push_back({"dup2_x2", nullptr, nullptr});
    // 95 (0x5F)
    bytecodes.push_back({"swap", nullptr, nullptr});

    // 96 (0x60)
    bytecodes.push_back({"iadd", nullptr, nullptr});
    // 97 (0x61)
    bytecodes.push_back({"ladd", nullptr, nullptr});
    // 98 (0x62)
    bytecodes.push_back({"fadd", nullptr, nullptr});
    // 99 (0x63)
    bytecodes.push_back({"dadd", nullptr, nullptr});
    // 100 (0x64)
    bytecodes.push_back({"isub", nullptr, nullptr});

    // 101 (0x65)
    bytecodes.push_back({"lsub", nullptr, nullptr});
    // 102 (0x66)
    bytecodes.push_back({"fsub", nullptr, nullptr});
    // 103 (0x67)
    bytecodes.push_back({"dsub", nullptr, nullptr});
    // 104 (0x68)
    bytecodes.push_back({"imul", nullptr, nullptr});
    // 105 (0x69)
    bytecodes.push_back({"lmul", nullptr, nullptr});

    // 106 (0x6A)
    bytecodes.push_back({"fmul", nullptr, nullptr});
    // 107 (0x6B)
    bytecodes.push_back({"dmul", nullptr, nullptr});
    // 108 (0x6C)
    bytecodes.push_back({"idiv", nullptr, nullptr});
    // 109 (0x6D)
    bytecodes.push_back({"ldiv", nullptr, nullptr});
    // 110 (0x6E)
    bytecodes.push_back({"fdiv", nullptr, nullptr});

    // 111 (0x6F)
    bytecodes.push_back({"ddiv", nullptr, nullptr});
    // 112 (0x70)
    bytecodes.push_back({"irem", nullptr, nullptr});
    // 113 (0x71)
    bytecodes.push_back({"lrem", nullptr, nullptr});
    // 114 (0x72)
    bytecodes.push_back({"frem", nullptr, nullptr});
    // 115 (0x73)
    bytecodes.push_back({"drem", nullptr, nullptr});

    // 116 (0x74)
    bytecodes.push_back({"ineg", nullptr, nullptr});
    // 117 (0x75)
    bytecodes.push_back({"lneg", nullptr, nullptr});
    // 118 (0x76)
    bytecodes.push_back({"fneg", nullptr, nullptr});
    // 119 (0x77)
    bytecodes.push_back({"dneg", nullptr, nullptr});
    // 120 (0x78)
    bytecodes.push_back({"ishl", nullptr, nullptr});

    // 121 (0x79)
    bytecodes.push_back({"lshl", nullptr, nullptr});
    // 122 (0x7A)
    bytecodes.push_back({"ishr", nullptr, nullptr});
    // 123 (0x7B)
    bytecodes.push_back({"lshr", nullptr, nullptr});
    // 124 (0x7C)
    bytecodes.push_back({"iushr", nullptr, nullptr});
    // 125 (0x7D)
    bytecodes.push_back({"lushr", nullptr, nullptr});

    // 126 (0x7E)
    bytecodes.push_back({"iand", nullptr, nullptr});
    // 127 (0x7F)
    bytecodes.push_back({"land", nullptr, nullptr});
    // 128 (0x80)
    bytecodes.push_back({"ior", nullptr, nullptr});
    // 129 (0x81)
    bytecodes.push_back({"lor", nullptr, nullptr});
    // 130 (0x82)
    bytecodes.push_back({"ixor", nullptr, nullptr});

    // 131 (0x83)
    bytecodes.push_back({"lxor", nullptr, nullptr});
    // 132 (0x84)
    bytecodes.push_back({"iinc", nullptr, nullptr});
    // 133 (0x85)
    bytecodes.push_back({"i2l", nullptr, nullptr});
    // 134 (0x86)
    bytecodes.push_back({"i2f", nullptr, nullptr});
    // 135 (0x87)
    bytecodes.push_back({"i2d", nullptr, nullptr});

    // 136 (0x88)
    bytecodes.push_back({"l2i", nullptr, nullptr});
    // 137 (0x89)
    bytecodes.push_back({"l2f", nullptr, nullptr});
    // 138 (0x8A)
    bytecodes.push_back({"l2d", nullptr, nullptr});
    // 139 (0x8B)
    bytecodes.push_back({"f2i", nullptr, nullptr});
    // 140 (0x8C)
    bytecodes.push_back({"f2l", nullptr, nullptr});

    // 141 (0x8D)
    bytecodes.push_back({"f2d", nullptr, nullptr});
    // 142 (0x8E)
    bytecodes.push_back({"d2i", nullptr, nullptr});
    // 143 (0x8F)
    bytecodes.push_back({"d2l", nullptr, nullptr});
    // 144 (0x90)
    bytecodes.push_back({"d2f", nullptr, nullptr});
    // 145 (0x91)
    bytecodes.push_back({"i2b", nullptr, nullptr});

    // 146 (0x92)
    bytecodes.push_back({"i2c", nullptr, nullptr});
    // 147 (0x93)
    bytecodes.push_back({"i2s", nullptr, nullptr});
    // 148 (0x94)
    bytecodes.push_back({"lcmp", nullptr, nullptr});
    // 149 (0x95)
    bytecodes.push_back({"fcmpl", nullptr, nullptr});
    // 150 (0x96)
    bytecodes.push_back({"fcmpg", nullptr, nullptr});

    // 151 (0x97)
    bytecodes.push_back({"dcmpl", nullptr, nullptr});
    // 152 (0x98)
    bytecodes.push_back({"dcmpg", nullptr, nullptr});
    // 153 (0x99)
    bytecodes.push_back({"ifeq", nullptr, nullptr});
    // 154 (0x9A)
    bytecodes.push_back({"ifne", nullptr, nullptr});
    // 155 (0x9B)
    bytecodes.push_back({"iflt", nullptr, nullptr});

    // 156 (0x9C)
    bytecodes.push_back({"ifge", nullptr, nullptr});
    // 157 (0x9D)
    bytecodes.push_back({"ifgt", nullptr, nullptr});
    // 158 (0x9E)
    bytecodes.push_back({"ifle", nullptr, nullptr});
    // 159 (0x9F)
    bytecodes.push_back({"if_icmpeq", nullptr, nullptr});
    // 160 (0xA0)
    bytecodes.push_back({"if_icmpne", nullptr, nullptr});

    // 161 (0xA1)
    bytecodes.push_back({"if_icmplt", nullptr, nullptr});
    // 162 (0xA2)
    bytecodes.push_back({"if_icmpge", nullptr, nullptr});
    // 163 (0xA3)
    bytecodes.push_back({"if_icmpgt", nullptr, nullptr});
    // 164 (0xA4)
    bytecodes.push_back({"if_icmple", nullptr, nullptr});
    // 165 (0xA5)
    bytecodes.push_back({"if_icmpeg", nullptr, nullptr});

    // 166 (0xA6)
    bytecodes.push_back({"if_icmpne", nullptr, nullptr});
    // 167 (0xA7)
    bytecodes.push_back({"goto", nullptr, nullptr});
    // 168 (0xA8)
    bytecodes.push_back({"jsr", nullptr, nullptr});
    // 169 (0xA9)
    bytecodes.push_back({"ret", nullptr, nullptr});
    // 170 (0xAA)
    bytecodes.push_back({"table_switch", nullptr, nullptr});

    // 171 (0xAB)
    bytecodes.push_back({"lookup_switch", nullptr, nullptr});
    // 172 (0xAC)
    bytecodes.push_back({"ireturn", nullptr, nullptr});
    // 173 (0xAD)
    bytecodes.push_back({"lreturn", nullptr, nullptr});
    // 174 (0xAE)
    bytecodes.push_back({"freturn", nullptr, nullptr});
    // 175 (0xAF)
    bytecodes.push_back({"dreturn", nullptr, nullptr});

    // 176 (0xB0)
    bytecodes.push_back({"areturn", nullptr, nullptr});
    // 177 (0xB1)
    bytecodes.push_back({"return", nullptr, nullptr});
    // 178 (0xB2)
    bytecodes.push_back({"get_static", nullptr, nullptr});
    // 179 (0xB3)
    bytecodes.push_back({"put_static", nullptr, nullptr});
    // 180 (0xB4)
    bytecodes.push_back({"getfield", nullptr, nullptr});

    // 181 (0xB5)
    bytecodes.push_back({"putfield", nullptr, nullptr});
    // 182 (0xB6)
    bytecodes.push_back({"invoke_virtual", nullptr, nullptr});
    // 183 (0xB7)
    bytecodes.push_back({"invoke_special", nullptr, nullptr});
    // 184 (0xB8)
    bytecodes.push_back({"invoke_static", nullptr, nullptr});
    // 185 (0xB9)
    bytecodes.push_back({"invoke_interface", nullptr, nullptr});

    // 186 (0xBA)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 187 (0xBB)
    bytecodes.push_back({"new", nullptr, nullptr});
    // 188 (0xBC)
    bytecodes.push_back({"new_array", nullptr, nullptr});
    // 189 (0xBD)
    bytecodes.push_back({"anew_array", nullptr, nullptr});
    // 190 (0xBE)
    bytecodes.push_back({"array_length", nullptr, nullptr});

    // 191 (0xBF)
    bytecodes.push_back({"athrow", nullptr, nullptr});
    // 192 (0xC0)
    bytecodes.push_back({"check_cast", nullptr, nullptr});
    // 193 (0xC1)
    bytecodes.push_back({"instance_of", nullptr, nullptr});
    // 194 (0xC2)
    bytecodes.push_back({"monitor_enter", nullptr, nullptr});
    // 195 (0xC3)
    bytecodes.push_back({"monitor_exit", nullptr, nullptr});

    // 196 (0xC4)
    bytecodes.push_back({"wide", nullptr, nullptr});
    // 197 (0xC5)
    bytecodes.push_back({"multi_anew_array", nullptr, nullptr});
    // 198 (0xC6)
    bytecodes.push_back({"ifnull", nullptr, nullptr});
    // 199 (0xC7)
    bytecodes.push_back({"ifnon_null", nullptr, nullptr});
    // 200 (0xC8)
    bytecodes.push_back({"goto_w", nullptr, nullptr});

    // 201 (0xC9)
    bytecodes.push_back({"jsr_w", nullptr, nullptr});
    // 202 (0xCA)
    bytecodes.push_back({"break_point", nullptr, nullptr});
    // 203 (0xCB)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 204 (0xCC)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 205 (0xCD)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 206 (0xCE)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 207 (0xCF)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 208 (0xD0)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 209 (0xD1)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 210 (0xD2)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 211 (0xD3)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 212 (0xD4)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 213 (0xD5)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 214 (0xD6)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 215 (0xD7)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 216 (0xD8)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 217 (0xD9)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 218 (0xDA)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 219 (0xDB)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 220 (0xDC)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 221 (0xDD)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 222 (0xDE)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 223 (0xDF)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 224 (0xE0)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 225 (0xE1)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 226 (0xE2)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 227 (0xE3)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 228 (0xE4)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 229 (0xE5)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 230 (0xE6)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 231 (0xE7)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 232 (0xE8)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 233 (0xE9)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 234 (0xEA)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 235 (0xEB)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 236 (0xEC)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 237 (0xED)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 238 (0xEE)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 239 (0xEF)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 240 (0xF0)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 241 (0xF1)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 242 (0xF2)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 243 (0xF3)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 244 (0xF4)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 245 (0xF5)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 246 (0xF6)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 247 (0xF7)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 248 (0xF8)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 249 (0xF9)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 250 (0xFA)
    bytecodes.push_back({"-", nullptr, nullptr});

    // 251 (0xFB)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 252 (0xFC)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 253 (0xFD)
    bytecodes.push_back({"-", nullptr, nullptr});
    // 254 (0xFE)
    bytecodes.push_back({"impdep_1", nullptr, nullptr});
    // 255 (0xFF)
    bytecodes.push_back({"impdep_2", nullptr, nullptr});
}

