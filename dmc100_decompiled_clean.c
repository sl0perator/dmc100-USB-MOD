/*
 * FNIRSI DMC-100 Clamp Multimeter — Firmware V1.4
 * Decompiled by Ghidra, cleaned & renamed. Analysis pseudocode only.
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#pragma GCC diagnostic ignored "-Wold-style-definition"
#pragma GCC diagnostic ignored "-Wreturn-mismatch"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t byte;
typedef int8_t sbyte;
typedef uint32_t uint3;
typedef int (*code)();

#define CONCAT11(a, b) ((uint16_t)(((uint16_t)((uint8_t)(a)) << 8) | (uint8_t)(b)))
#define CONCAT12(a, b) ((uint32_t)(((uint32_t)((uint8_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT13(a, b) ((uint32_t)(((uint32_t)((uint8_t)(a)) << 24) | (uint32_t)(b)))
#define CONCAT14(a, b) ((uint64_t)(((uint64_t)((uint8_t)(a)) << 32) | (uint32_t)(b)))
#define CONCAT22(a, b) ((uint32_t)(((uint32_t)((uint16_t)(a)) << 16) | (uint16_t)(b)))
#define CONCAT44(a, b) ((uint64_t)(((uint64_t)((uint32_t)(a)) << 32) | (uint32_t)(b)))
#define CARRY4(a, b) ((uint32_t)((uint32_t)(a) + (uint32_t)(b)) < (uint32_t)(a))
#define SCARRY4(a, b)                                                                              \
    (((int32_t)(((uint32_t)(a) + (uint32_t)(b)) ^ (uint32_t)(a)) < 0) &&                           \
     ((int32_t)(((uint32_t)(a) + (uint32_t)(b)) ^ (uint32_t)(b)) < 0))
#define SBORROW4(a, b)                                                                             \
    (((int32_t)(((uint32_t)(a) - (uint32_t)(b)) ^ (uint32_t)(a)) < 0) &&                           \
     ((int32_t)((uint32_t)(a) ^ (uint32_t)(b)) < 0))
#define SUB41(a, b) ((int8_t)((uint32_t)(a) - (uint32_t)(b)))
#define ZEXT48(a) ((uint64_t)(uint32_t)(a))
#define SEXT48(a) ((int64_t)(int32_t)(a))
#define LZCOUNT(x) __builtin_clz(x)
#define DataSynchronizationBarrier(...) __asm__ volatile("dsb" ::: "memory")
#define DataMemoryBarrier(...) __asm__ volatile("dmb" ::: "memory")
#define InstructionSynchronizationBarrier() __asm__ volatile("isb")
#define software_interrupt(...) __asm__ volatile("svc #0")
extern void halt_baddata(void);

/* Hardware registers */
extern void (*const DAT_08000244)(void);
extern void (*const DAT_08000248)(void);
extern const uint32_t DAT_0800024c;
extern const uint32_t DAT_08000250;
extern const uint32_t DAT_08000434;
extern const uint32_t DAT_08000744;
extern const uint32_t DAT_0800089c;
extern const uint32_t DAT_08000a20;
extern const uint32_t DAT_08000a24;
extern uint32_t *const DAT_08000e14;
extern const uint32_t DAT_08000e18;
extern const uint32_t DAT_08000e40;
extern const uint32_t DAT_08000f90;
extern const uint32_t DAT_08000f94;
extern const uint32_t DAT_08001068;
extern const uint32_t DAT_080010ec;
extern const uint32_t DAT_080010f0;
extern const uint32_t DAT_080010f4;
extern const uint32_t DAT_080014f8;
extern const uint32_t DAT_080014fc;
extern const uint32_t DAT_08001500;
extern const uint32_t DAT_08001504;
extern const uint32_t DAT_080015d0;
extern const uint32_t DAT_080015d4;
extern const uint32_t DAT_080015d8;
extern const uint32_t DAT_080015dc;
extern const uint32_t DAT_080016d4;
extern const uint32_t DAT_080017c8;
extern const uint32_t DAT_080018c0;
extern const uint32_t DAT_08001984;
extern const uint32_t DAT_08001a78;
extern const uint32_t DAT_08001ae8;
extern const uint32_t DAT_08001b18;
extern const uint32_t DAT_08001b5c;
extern uint32_t *const DAT_08001b70;
extern const uint32_t DAT_08001ec4;
extern const uint32_t DAT_08001ec8;
extern const uint32_t DAT_08001ecc;
extern const uint32_t DAT_08001ed0;
extern const uint32_t DAT_08001ed4;
extern const uint32_t DAT_08002178;
extern const uint32_t DAT_0800217c;
extern const uint32_t DAT_080023fc;
extern const uint32_t DAT_0800244c;
extern const uint32_t DAT_08002460;
extern const uint32_t DAT_08002464;
extern const uint32_t DAT_08002524;
extern const uint32_t DAT_08002528;
extern const uint32_t DAT_0800252c;
extern const uint32_t DAT_08002530;
extern const uint32_t DAT_08002554;
extern const uint32_t DAT_08002558;
extern const uint32_t DAT_0800255c;
extern const uint32_t DAT_080029e0;
extern const uint32_t DAT_080029f0;
extern const uint32_t DAT_08002a00;
extern const uint32_t DAT_08002a1c;
extern uint32_t *const DAT_08002a60;
extern const uint32_t DAT_08002b48;
extern const uint32_t DAT_08002b4c;
extern const uint32_t DAT_08002b50;
extern const uint32_t DAT_08002b54;
extern const uint32_t DAT_08002b58;
extern const uint32_t DAT_08002b78;
extern const uint32_t DAT_08002bc4;
extern const uint32_t DAT_08002c1c;
extern uint32_t *const DAT_08002c60;
extern const uint32_t DAT_08002c64;
extern const uint32_t DAT_08002c9c;
extern const uint32_t DAT_08002cac;
extern uint32_t *const DAT_08002d0c;
extern const uint32_t DAT_08002d10;
extern uint32_t *const DAT_08002d14;
extern const uint32_t DAT_08002d60;
extern uint32_t *const DAT_08003084;
extern uint32_t *const DAT_080030d8;
extern const uint32_t DAT_08003118;
extern const uint32_t DAT_0800311c;
extern const uint32_t DAT_08003428;
extern const uint32_t DAT_0800342c;
extern const uint32_t DAT_080034d0;
extern const uint32_t DAT_080034f0;
extern const uint32_t DAT_080034f8;
extern const uint32_t DAT_080035c4;
extern const uint32_t DAT_080035c8;
extern const uint32_t DAT_080035cc;
extern const uint32_t DAT_080035d0;
extern const uint32_t DAT_080035d8;
extern const uint32_t DAT_08003664;
extern const uint32_t DAT_08003ad8;
extern const uint32_t DAT_08003adc;
extern const uint32_t DAT_08003af8;
extern const uint32_t DAT_08003b28;
extern const uint32_t DAT_08003b3c;
extern const uint32_t DAT_08003b54;
extern const uint32_t DAT_08003b60;
extern const uint32_t DAT_08003b64;
extern const uint32_t DAT_08003b68;
extern const uint32_t DAT_08003b6c;
extern const uint32_t DAT_08003b70;
extern const uint32_t DAT_08003b74;
extern const uint32_t DAT_08003b78;
extern const uint32_t DAT_08003b7c;
extern const uint32_t DAT_08003b80;
extern const uint32_t DAT_08003b84;
extern const uint32_t DAT_08003ba8;
extern const uint32_t DAT_08003bb0;
extern const uint32_t DAT_08003bb4;
extern const uint32_t DAT_08003bb8;
extern const uint32_t DAT_08003bbc;
extern const uint32_t DAT_08003bc0;
extern const uint32_t DAT_08003bc4;
extern const uint32_t DAT_08003bc8;
extern const uint32_t DAT_08003bcc;
extern const uint32_t DAT_08003bd0;
extern const uint32_t DAT_08003bd4;
extern const uint32_t DAT_08003bd8;
extern const uint32_t DAT_08003bdc;
extern const uint32_t DAT_08003c5c;
extern const uint32_t DAT_08003df4;
extern const uint32_t DAT_08003e04;
extern const uint32_t DAT_08003ec8;
extern const uint32_t DAT_08003ecc;
extern const uint32_t DAT_08003ed8;
extern const uint32_t DAT_08003ef4;
extern const uint32_t DAT_08003efc;
extern const uint32_t DAT_08003f10;
extern const uint32_t DAT_08003fd0;
extern const uint32_t DAT_08003fd4;
extern const uint32_t DAT_08003fd8;
extern const uint32_t DAT_080041cc;
extern const uint32_t DAT_080041d0;
extern const uint32_t DAT_080045d8;
extern const uint32_t DAT_080045dc;
extern const uint32_t DAT_080045e0;
extern const uint32_t DAT_080045e4;
extern const uint32_t DAT_080045e8;
extern const uint32_t DAT_080045f4;
extern const uint32_t DAT_080045f8;
extern const uint32_t DAT_08004604;
extern const uint32_t DAT_08004608;
extern const uint32_t DAT_08004614;
extern const uint32_t DAT_08004618;
extern const uint32_t DAT_08004624;
extern const uint32_t DAT_08004628;
extern const uint32_t DAT_08004634;
extern const uint32_t DAT_08004638;
extern const uint32_t DAT_08004644;
extern const uint32_t DAT_08004648;
extern const uint32_t DAT_08004654;
extern const uint32_t DAT_08004658;
extern const uint32_t DAT_08004664;
extern const uint32_t DAT_08004668;
extern const uint32_t DAT_08004674;
extern const uint32_t DAT_08004678;
extern const uint32_t DAT_08004684;
extern const uint32_t DAT_08004688;
extern const uint32_t DAT_0800468c;
extern const uint32_t DAT_08004690;
extern const uint32_t DAT_08004694;
extern const uint32_t DAT_08004698;
extern const uint32_t DAT_0800469c;
extern const uint32_t DAT_080046a0;
extern const uint32_t DAT_080046a4;
extern const uint32_t DAT_080046a8;
extern const uint32_t DAT_080046ac;
extern const uint32_t DAT_080046b0;
extern const uint32_t DAT_080046b4;
extern const uint32_t DAT_080046d8;
extern const uint32_t DAT_080046dc;
extern const uint32_t DAT_080046e0;
extern const uint32_t DAT_080046e4;
extern const uint32_t DAT_080046e8;
extern const uint32_t DAT_080046ec;
extern const uint32_t DAT_080046f0;
extern const uint32_t DAT_080046f4;
extern const uint32_t DAT_080046f8;
extern const uint32_t DAT_080046fc;
extern const uint32_t DAT_08004700;
extern const uint32_t DAT_08004704;
extern const uint32_t DAT_08004708;
extern const uint32_t DAT_0800472c;
extern const uint32_t DAT_08004b18;
extern const uint32_t DAT_08004b1c;
extern const uint32_t DAT_08004b20;
extern const uint32_t DAT_08004b24;
extern uint32_t *const DAT_08004b28;
extern const uint32_t DAT_08004b2c;
extern const uint32_t DAT_08004b30;
extern const uint32_t DAT_08004b34;
extern const uint32_t DAT_08004b38;
extern const uint32_t DAT_08004b78;
extern const uint32_t DAT_08004e24;
extern const uint32_t DAT_08004e28;
extern const uint32_t DAT_08004e2c;
extern const uint32_t DAT_08004e30;
extern const uint32_t DAT_08004e3c;
extern const uint32_t DAT_08004e48;
extern const uint32_t DAT_08004e4c;
extern const uint32_t DAT_08004e58;
extern const uint32_t DAT_08004e64;
extern const uint32_t DAT_08004e68;
extern const uint32_t DAT_08004e6c;
extern const uint32_t DAT_08004e70;
extern const uint32_t DAT_08004e74;
extern const uint32_t DAT_08004e84;
extern const uint32_t DAT_08004e94;
extern const uint32_t DAT_08004f8c;
extern const uint32_t DAT_08004f90;
extern const uint32_t DAT_08004f94;
extern const uint32_t DAT_08004f98;
extern const uint32_t DAT_08004f9c;
extern const uint32_t DAT_08004fa0;
extern const uint32_t DAT_08004fa4;
extern const uint32_t DAT_08004fa8;
extern const uint32_t DAT_08004fac;
extern const uint32_t DAT_08004fb0;
extern const uint32_t DAT_08004fb4;
extern const uint32_t DAT_08004fb8;
extern const uint32_t DAT_08004fbc;
extern const uint32_t DAT_08004fc0;
extern const uint32_t DAT_08004fc4;
extern const uint32_t DAT_080050b0;
extern const uint32_t DAT_080050b4;
extern const uint32_t DAT_080050b8;
extern const uint32_t DAT_080050bc;
extern const uint32_t DAT_080050c0;
extern const uint32_t DAT_080050c4;
extern const uint32_t DAT_080050c8;
extern const uint32_t DAT_080050cc;
extern const uint32_t DAT_080050d0;
extern const uint32_t DAT_080050d4;
extern const uint32_t DAT_080050d8;
extern const uint32_t DAT_080050dc;
extern const uint32_t DAT_080050e0;
extern const uint32_t DAT_080050e4;
extern const uint32_t DAT_080050e8;
extern const uint32_t DAT_080050ec;
extern const uint32_t DAT_080050f0;
extern const uint32_t DAT_080051bc;
extern const uint32_t DAT_080051c0;
extern const uint32_t DAT_080051c4;
extern const uint32_t DAT_080051c8;
extern const uint32_t DAT_080051cc;
extern const uint32_t DAT_080051d0;
extern const uint32_t DAT_080051d4;
extern const uint32_t DAT_080051d8;
extern const uint32_t DAT_080051dc;
extern const uint32_t DAT_080051e0;
extern const uint32_t DAT_080051e4;
extern const uint32_t DAT_080051e8;
extern const uint32_t DAT_080051ec;
extern const uint32_t DAT_080051f0;
extern const uint32_t DAT_080051f4;
extern const uint32_t DAT_080051f8;
extern const uint32_t DAT_08005374;
extern const uint32_t DAT_08005378;
extern const uint32_t DAT_08005544;
extern const uint32_t DAT_08005548;
extern const uint32_t DAT_08005564;
extern const uint32_t DAT_08005568;
extern const uint32_t DAT_08005570;
extern const uint32_t DAT_080055e4;
extern uint32_t *const DAT_0800562c;
extern uint32_t *const DAT_08005630;
extern uint32_t *const DAT_08005634;
extern uint32_t *const DAT_080057a0;
extern const uint32_t DAT_080057a4;
extern uint32_t *const DAT_080057a8;
extern const uint32_t DAT_080057ac;
extern const uint32_t DAT_08005910;
extern const uint32_t DAT_0800591c;
extern const uint32_t DAT_08005920;
extern const uint32_t DAT_08005a3c;
extern const uint32_t DAT_08005a40;
extern const uint32_t DAT_08005a50;
extern const uint32_t DAT_08005a64;
extern const uint32_t DAT_08005bec;
extern const uint32_t DAT_08005bf0;
extern const uint32_t DAT_08005bf4;
extern const uint32_t DAT_08005bf8;
extern const uint32_t DAT_08005bfc;
extern const uint32_t DAT_08005c20;
extern const uint32_t DAT_08005c28;
extern const uint32_t DAT_080060c0;
extern const uint32_t DAT_080060c4;
extern const uint32_t DAT_080060d8;
extern const uint32_t DAT_080060dc;
extern const uint32_t DAT_080060e0;
extern const uint32_t DAT_080060e4;
extern const uint32_t DAT_08006114;
extern const uint32_t DAT_08006120;
extern const uint32_t DAT_080065a4;
extern const uint32_t DAT_080065a8;
extern const uint32_t DAT_08006844;
extern const uint32_t DAT_080069ec;
extern const uint32_t DAT_080069f0;
extern const uint32_t DAT_080069f4;
extern const uint32_t DAT_080069f8;
extern const uint32_t DAT_080069fc;
extern const uint32_t DAT_08006a00;
extern const uint32_t DAT_08006a04;
extern const uint32_t DAT_08006a08;
extern const uint32_t DAT_08006a0c;
extern const uint32_t DAT_08006a10;
extern const uint32_t DAT_08006a14;
extern const uint32_t DAT_08006a18;
extern const uint32_t DAT_08006bb4;
extern const uint32_t DAT_08006bb8;
extern const uint32_t DAT_08006bbc;
extern const uint32_t DAT_08006bc0;
extern const uint32_t DAT_08006bc4;
extern const uint32_t DAT_08006bc8;
extern const uint32_t DAT_08006bcc;
extern const uint32_t DAT_08006bd0;
extern const uint32_t DAT_08006bd4;
extern const uint32_t DAT_08006bd8;
extern const uint32_t DAT_08006bdc;
extern const uint32_t DAT_08006be0;
extern const uint32_t DAT_08006d40;
extern const uint32_t DAT_08006d44;
extern const uint32_t DAT_08006d48;
extern const uint32_t DAT_08006d4c;
extern const uint32_t DAT_08006d50;
extern const uint32_t DAT_08006d54;
extern const uint32_t DAT_08006d58;
extern const uint32_t DAT_08006d5c;
extern const uint32_t DAT_08006d60;
extern const uint32_t DAT_08006d64;
extern const uint32_t DAT_08006d68;
extern const uint32_t DAT_08006f08;
extern const uint32_t DAT_08006f0c;
extern const uint32_t DAT_08006f10;
extern const uint32_t DAT_08006f14;
extern const uint32_t DAT_08006f18;
extern const uint32_t DAT_08006f1c;
extern const uint32_t DAT_08006f20;
extern const uint32_t DAT_08006f24;
extern const uint32_t DAT_08006f28;
extern const uint32_t DAT_08006f2c;
extern const uint32_t DAT_08006f30;
extern const uint32_t DAT_08006f34;
extern const uint32_t DAT_08007100;
extern const uint32_t DAT_08007104;
extern uint32_t *const DAT_08007108;
extern const uint32_t DAT_080072bc;
extern const uint32_t DAT_080072d0;
extern const uint32_t DAT_080072d4;
extern const uint32_t DAT_080072d8;
extern uint32_t *const DAT_080072dc;
extern const uint32_t DAT_0800736c;
extern const uint32_t DAT_08007580;
extern const uint32_t DAT_08007584;
extern const uint32_t DAT_08007588;
extern const uint32_t DAT_0800758c;
extern uint32_t *const DAT_08007590;
extern const uint32_t DAT_08007594;
extern const uint32_t DAT_08007598;
extern const uint32_t DAT_0800759c;
extern const uint32_t DAT_080075a0;
extern const uint32_t DAT_080075a4;
extern const uint32_t DAT_080075a8;
extern const uint32_t DAT_080075ac;
extern const uint32_t DAT_0800763c;
extern const uint32_t DAT_08007640;
extern const uint32_t DAT_08007644;
extern const uint32_t DAT_080076d0;
extern const uint32_t DAT_080076d4;
extern const uint32_t DAT_080076d8;
extern uint32_t *const DAT_0800770c;
extern const uint32_t DAT_08007710;
extern const uint32_t DAT_08007730;
extern const uint32_t DAT_08007734;
extern const uint32_t DAT_08007830;
extern const uint32_t DAT_08007834;
extern const uint32_t DAT_0800788c;
extern uint32_t *const DAT_08007890;
extern const uint32_t DAT_0800793c;
extern const uint32_t DAT_08007940;
extern const uint32_t DAT_08007944;
extern const uint32_t DAT_08007948;
extern const uint32_t DAT_080079ec;
extern const uint32_t DAT_080079f0;
extern const uint32_t DAT_08007c6c;
extern const uint32_t DAT_08007e24;
extern const uint32_t DAT_08008068;
extern uint32_t *const DAT_08008134;
extern const uint32_t DAT_08008208;
extern const uint32_t DAT_0800820c;
extern const uint32_t DAT_08008238;
extern const uint32_t DAT_08008278;
extern const uint32_t DAT_0800829c;
extern const uint32_t DAT_080082ac;
extern const uint32_t DAT_080082d4;
extern const uint32_t DAT_08008340;
extern uint32_t *const DAT_0800834c;
extern const uint32_t DAT_08008474;
extern const uint32_t DAT_08008478;
extern const uint32_t DAT_0800847c;
extern uint32_t *const DAT_08008480;
extern const uint32_t DAT_080084d4;
extern const uint32_t DAT_080084e8;
extern const uint32_t DAT_0800851c;
extern const uint32_t DAT_08008548;
extern const uint32_t DAT_08008614;
extern const uint32_t DAT_08008618;
extern const uint32_t DAT_080086a0;
extern const uint32_t DAT_080086c4;
extern const uint32_t DAT_080086d4;
extern const uint32_t DAT_080086d8;
extern const uint32_t DAT_080086dc;
extern const uint32_t DAT_080087c4;
extern uint32_t *const DAT_08008958;
extern const uint32_t DAT_0800895c;
extern const uint32_t DAT_08008960;
extern const uint32_t DAT_08008964;
extern const uint32_t DAT_08008968;
extern const uint32_t DAT_0800896c;
extern const uint32_t DAT_08008970;
extern const uint32_t DAT_08008974;
extern const uint32_t DAT_08008be4;
extern const uint32_t DAT_08008be8;
extern const uint32_t DAT_08008c4c;
extern const uint32_t DAT_08008c50;
extern const uint32_t DAT_08008c54;
extern const uint32_t DAT_08008dd0;
extern const uint32_t DAT_08008dd4;
extern const uint32_t DAT_08008dd8;
extern const uint32_t DAT_08009270;
extern const uint32_t DAT_08009308;
extern uint32_t *const DAT_0800930c;
extern const uint32_t DAT_08009310;
extern const uint32_t DAT_08009314;
extern const uint32_t DAT_0800940c;
extern const uint32_t DAT_08009410;
extern const uint32_t DAT_08009470;
extern const uint32_t DAT_08009474;
extern const uint32_t DAT_080094ac;
extern const uint32_t DAT_080094ec;
extern const uint32_t DAT_080094f0;
extern const uint32_t DAT_080095ac;
extern const uint32_t DAT_080095b0;
extern const uint32_t DAT_08009968;
extern const uint32_t DAT_08009c84;
extern const uint32_t DAT_0800a094;
extern const uint32_t DAT_0800a098;
extern const uint32_t DAT_0800a09c;
extern const uint32_t DAT_0800a0a0;
extern const uint32_t DAT_0800a0a4;
extern const uint32_t DAT_0800a0a8;
extern const uint32_t DAT_0800a0ac;
extern const uint32_t DAT_0800a0b8;
extern const uint32_t DAT_0800a0dc;
extern const uint32_t DAT_0800a0e0;
extern const uint32_t DAT_0800a0e4;
extern const uint32_t DAT_0800a4e0;
extern const uint32_t DAT_0800a4e4;
extern const uint32_t DAT_0800a4e8;
extern const uint32_t DAT_0800a4ec;
extern const uint32_t DAT_0800a4f0;
extern const uint32_t DAT_0800a4f4;
extern const uint32_t DAT_0800a4f8;
extern const uint32_t DAT_0800a4fc;
extern const uint32_t DAT_0800a500;
extern const uint32_t DAT_0800a504;
extern const uint32_t DAT_0800a508;
extern const uint32_t DAT_0800a610;
extern const uint32_t DAT_0800a614;
extern const uint32_t DAT_0800a694;
extern const uint32_t DAT_0800a698;
extern const uint32_t DAT_0800a69c;
extern const uint32_t DAT_0800a6a0;
extern const uint32_t DAT_0800a6a4;
extern const uint32_t DAT_0800a6a8;
extern const uint32_t DAT_0800a6ac;
extern const uint32_t DAT_0800a6b0;
extern const uint32_t DAT_0800a6b4;
extern const uint32_t DAT_0800a6b8;
extern const uint32_t DAT_0800a6bc;
extern const uint32_t DAT_0800a6c0;
extern const uint32_t DAT_0800a6c4;
extern const uint32_t DAT_0800a6c8;
extern const uint32_t DAT_0800a908;
extern const uint32_t DAT_0800a90c;
extern const uint32_t DAT_0800a910;
extern const uint32_t DAT_0800a914;
extern const uint32_t DAT_0800a918;
extern uint32_t *const DAT_0800aa74;
extern uint32_t *const DAT_0800aa94;
extern const uint32_t DAT_0800aa98;
extern uint32_t *const DAT_0800aab8;
extern const uint32_t DAT_0800aabc;
extern const uint32_t DAT_0800ada4;
extern const uint32_t DAT_0800ada8;
extern const uint32_t DAT_0800adac;
extern const uint32_t DAT_0800adb0;
extern const uint32_t DAT_0800adb4;
extern const uint32_t DAT_0800adf8;
extern const uint32_t DAT_0800ae0c;
extern const uint32_t DAT_0800ae18;
extern const uint32_t DAT_0800ae20;
extern const uint32_t DAT_0800ae60;
extern const uint32_t DAT_0800b06c;
extern const uint32_t DAT_0800b070;
extern const uint32_t DAT_0800b074;
extern const uint32_t DAT_0800b170;
extern const uint32_t DAT_0800b174;
extern const uint32_t DAT_0800b1b4;
extern const uint32_t DAT_0800b2ac;
extern const uint32_t DAT_0800b2b0;
extern const uint32_t DAT_0800b2b4;
extern const uint32_t DAT_0800b418;
extern const uint32_t DAT_0800b41c;
extern const uint32_t DAT_0800b420;
extern const uint32_t DAT_0800b424;
extern const uint32_t DAT_0800b428;
extern const uint32_t DAT_0800b42c;
extern const uint32_t DAT_0800b430;
extern const uint32_t DAT_0800b434;
extern const uint32_t DAT_0800b438;
extern const uint32_t DAT_0800b43c;
extern const uint32_t DAT_0800b4b8;
extern const uint32_t DAT_0800b4bc;
extern const uint32_t DAT_0800b998;
extern const uint32_t DAT_0800b99c;
extern const uint32_t DAT_0800b9a0;
extern const uint32_t DAT_0800b9a4;
extern uint32_t *const DAT_0800b9a8;
extern const uint32_t DAT_0800b9ac;
extern uint32_t *const DAT_0800b9b0;
extern const uint32_t DAT_0800b9b4;
extern const uint32_t DAT_0800b9b8;
extern const uint32_t DAT_0800b9bc;
extern uint32_t *const DAT_0800b9c0;
extern uint32_t *const DAT_0800b9c4;
extern const uint32_t DAT_0800ba70;
extern const uint32_t DAT_0800ba9c;
extern const uint32_t DAT_0800baf4;
extern const uint32_t DAT_0800baf8;
extern uint32_t *const DAT_0800bafc;
extern uint32_t *const DAT_0800bb00;
extern const uint32_t DAT_0800bb04;
extern const uint32_t DAT_0800bd18;
extern const uint32_t DAT_0800bd1c;
extern const uint32_t DAT_0800bd20;
extern const uint32_t DAT_0800bda0;
extern const uint32_t DAT_0800bda4;
extern const uint32_t DAT_0800bf08;
extern const uint32_t DAT_0800bf0c;
extern uint32_t *const DAT_0800bf10;
extern const uint32_t DAT_0800bf14;
extern const uint32_t DAT_0800bf18;
extern const uint32_t DAT_0800bf1c;
extern const uint32_t DAT_0800c100;
extern const uint32_t DAT_0800c104;
extern const uint32_t DAT_0800c180;
extern const uint32_t DAT_0800c184;
extern const uint32_t DAT_0800c188;
extern const uint32_t DAT_0800c528;
extern uint32_t *const DAT_0800c85c;
extern const uint32_t DAT_0800c888;
extern uint32_t *const DAT_0800d49c;
extern uint32_t *const DAT_0800d5a0;
extern const uint32_t DAT_0800d5a4;
extern const uint32_t DAT_0800d5f0;
extern const uint32_t DAT_0800d5f4;
extern const uint32_t DAT_0800d5f8;
extern const uint32_t DAT_0800d664;
extern const uint32_t DAT_0800d668;
extern const uint32_t DAT_0800d66c;
extern const uint32_t DAT_0800d670;
extern const uint32_t DAT_0800d674;
extern const uint32_t DAT_0800d6b8;
extern const uint32_t DAT_0800d6bc;
extern uint32_t *const DAT_0800dabc;
extern const uint32_t DAT_0800dac0;
extern const uint32_t DAT_0800dcf0;
extern const uint32_t DAT_0800dfc4;
extern const uint32_t DAT_0800dfc8;
extern const uint32_t DAT_0800e240;
extern const uint32_t DAT_0800e544;
extern const uint32_t DAT_0800e7f0;

/* _DAT_ base declarations + aliases */
extern const uint32_t DAT_08003150;
extern const uint32_t DAT_0800340c;
extern const uint32_t DAT_08003de0;
extern const uint32_t DAT_0800528c;
extern const uint32_t DAT_0800537c;
extern const uint32_t DAT_080058fc;
extern const uint32_t DAT_08006248;
extern const uint32_t DAT_080065ac;
extern const uint32_t DAT_08006848;
extern const uint32_t DAT_0800823c;
extern const uint32_t DAT_080092f0;
extern const uint32_t DAT_0800b28c;
#define DAT_e000e010 (*(volatile uint32_t *)0xe000e010U) /* SYSTICK_CTRL */
#define DAT_e000e014 (*(volatile uint32_t *)0xe000e014U) /* SYSTICK_LOAD */
#define DAT_e000e018 (*(volatile uint32_t *)0xe000e018U) /* SYSTICK_VAL */
#define _DAT_08003150 DAT_08003150
#define _DAT_0800340c DAT_0800340c
#define _DAT_08003de0 DAT_08003de0
#define _DAT_0800528c DAT_0800528c
#define _DAT_0800537c DAT_0800537c
#define _DAT_080058fc DAT_080058fc
#define _DAT_08006248 DAT_08006248
#define _DAT_080065ac DAT_080065ac
#define _DAT_08006848 DAT_08006848
#define _DAT_0800823c DAT_0800823c
#define _DAT_080092f0 DAT_080092f0
#define _DAT_0800b28c DAT_0800b28c
#define _DAT_e000e010 DAT_e000e010
#define _DAT_e000e014 DAT_e000e014
#define _DAT_e000e018 DAT_e000e018

/* String symbols */
extern char s_15min_08005928[];
extern char s_15min_080060ec[];
extern char s_2_APPusbflash_init_err_0800823f[];
extern char s_2_APPusbflash_init_ok_08008258[];
extern char s_2__LOGO_jpg_08008210[];
extern char s_2__UI_cel_1_jpg_08003c60[];
extern char s_2__UI_cel_2_jpg_08003cd4[];
extern char s_2__UI_cel_3_jpg_08003ce4[];
extern char s_2__UI_cel_4_jpg_08003cf4[];
extern char s_2__UI_cel_5_jpg_08003d04[];
extern char s_2__UI_cell_1_jpg_08003c70[];
extern char s_2__UI_cell_2_jpg_08003c84[];
extern char s_2__UI_cell_3_jpg_08003c98[];
extern char s_2__UI_cell_4_jpg_08003cac[];
extern char s_2__UI_cell_5_jpg_08003cc0[];
extern char s_2__UI_decorat_decorate_jpg_08003490[];
extern char s_2__UI_decorat_down_jpg_08003448[];
extern char s_2__UI_decorat_hold_jpg_08003153[];
extern char s_2__UI_decorat_holdoff_jpg_080031a0[];
extern char s_2__UI_decorat_led_jpg_0800528f[];
extern char s_2__UI_decorat_ledoff_jpg_080052dc[];
extern char s_2__UI_decorat_lig_jpg_08006748[];
extern char s_2__UI_decorat_live_jpg_08005398[];
extern char s_2__UI_decorat_menu_jpg_080060fc[];
extern char s_2__UI_decorat_menu_jpg_0800624b[];
extern char s_2__UI_decorat_menu_jpg_0800adb8[];
extern char s_2__UI_decorat_mode_jpg_0800340f[];
extern char s_2__UI_decorat_ncv0_jpg_080053b0[];
extern char s_2__UI_decorat_ncv0_jpg_080065af[];
extern char s_2__UI_decorat_ncv1_1_jpg_08006638[];
extern char s_2__UI_decorat_ncv1_2_jpg_08006600[];
extern char s_2__UI_decorat_ncv1_3_jpg_080065c8[];
extern char s_2__UI_decorat_ncv1_4_jpg_080065e4[];
extern char s_2__UI_decorat_ncv1_5_jpg_0800661c[];
extern char s_2__UI_decorat_ncv1_6_jpg_08006654[];
extern char s_2__UI_decorat_ncv1__08006760[];
extern char s_2__UI_decorat_ncv1_jpg_08006730[];
extern char s_2__UI_decorat_ncv2__080067d4[];
extern char s_2__UI_decorat_ncv2_jpg_080067bc[];
extern char s_2__UI_decorat_ncv3__08006830[];
extern char s_2__UI_decorat_ncv3_jpg_0800537f[];
extern char s_2__UI_decorat_ncv3_jpg_08006818[];
extern char s_2__UI_decorat_up_jpg_08003430[];
extern char s_2__UI_decorate_decorate_jpg_080034b4[];
extern char s_2__UI_decorate_down_jpg_08003478[];
extern char s_2__UI_decorate_hold_jpg_0800316c[];
extern char s_2__UI_decorate_holdoff_jpg_08003184[];
extern char s_2__UI_decorate_led_jpg_080052a8[];
extern char s_2__UI_decorate_ledoff_jpg_080052c0[];
extern char s_2__UI_decorate_lig_jpg_0800678c[];
extern char s_2__UI_decorate_live_jpg_080053f8[];
extern char s_2__UI_decorate_menu_jpg_08006128[];
extern char s_2__UI_decorate_menu_jpg_08006264[];
extern char s_2__UI_decorate_menu_jpg_0800add0[];
extern char s_2__UI_decorate_mode_jpg_080034d8[];
extern char s_2__UI_decorate_ncv0_jpg_080053c8[];
extern char s_2__UI_decorate_ncv0_jpg_08006670[];
extern char s_2__UI_decorate_ncv1_1_jpg_080066f8[];
extern char s_2__UI_decorate_ncv1_2_jpg_080066c0[];
extern char s_2__UI_decorate_ncv1_3_jpg_08006688[];
extern char s_2__UI_decorate_ncv1_4_jpg_080066a4[];
extern char s_2__UI_decorate_ncv1_5_jpg_080066dc[];
extern char s_2__UI_decorate_ncv1_6_jpg_08006714[];
extern char s_2__UI_decorate_ncv1__080067a4[];
extern char s_2__UI_decorate_ncv1_jpg_08006774[];
extern char s_2__UI_decorate_ncv2__08006800[];
extern char s_2__UI_decorate_ncv2_jpg_080067e8[];
extern char s_2__UI_decorate_ncv3__08006864[];
extern char s_2__UI_decorate_ncv3_jpg_080053e0[];
extern char s_2__UI_decorate_ncv3_jpg_0800684b[];
extern char s_2__UI_decorate_up_jpg_08003460[];
extern char s_2__UI_mode_1_A_jpg_08003730[];
extern char s_2__UI_mode_1_C_jpg_080036b8[];
extern char s_2__UI_mode_1_H_jpg_080036e0[];
extern char s_2__UI_mode_1_L_jpg_08003708[];
extern char s_2__UI_mode_1_R_jpg_08003690[];
extern char s_2__UI_mode_1_V_jpg_08003668[];
extern char s_2__UI_mode_A_jpg_08003744[];
extern char s_2__UI_mode_C_jpg_080036cc[];
extern char s_2__UI_mode_H_jpg_080036f4[];
extern char s_2__UI_mode_L_jpg_0800371c[];
extern char s_2__UI_mode_R_jpg_080036a4[];
extern char s_2__UI_mode_V_jpg_0800367c[];
extern char s_30min_08005930[];
extern char s_30min_080060f4[];
extern char s_AUTO_shut_down_080058ff[];
extern char s_About_0800ae58[];
extern char s_Brightness_08005c00[];
extern char s_DMC_100_V1_4_08007370[];
extern char s_Data_saved_08004b6c[];
extern char s_Do_not_use_while_charging_0800b28f[];
extern char s_English_08005a5c[];
extern char s_English_080060d0[];
extern char s_English_080072c8[];
extern char s_FAT32_08002624[];
extern char s_History_record_0800ade8[];
extern char s_Language_08005a44[];
extern char s_Language_08006150[];
extern char s_Low_battery_0800554c[];
extern char s_Measurement_0800ae00[];
extern char s_Power__080034ac[];
extern char s_Reset_08003de3[];
extern char s_Reset_0800ae44[];
extern char s_Reset_all_08003edc[];
extern char s_Return_08003dec[];
extern char s_SIGRTMEM__Out_of_heap_memory_08000934[];
extern char s_Shutdown_08005558[];
extern char s_System_settings_08006140[];
extern char s_System_settings_0800ae28[];
extern char s_Temperature_unit_08005c0c[];
extern char s__03_2f_W_08004e78[];
extern char s__04_0f_0800a0bc[];
extern char s__04d_08004b44[];
extern char s__0800b9c8[];
extern char s__0_0f_080046b8[];
extern char s__0_0f_0800a0d4[];
extern char s__0_0f_c_08008984[];
extern char s__0_1f_080046c0[];
extern char s__0_1f_08004b4c[];
extern char s__0_1f_08004b5c[];
extern char s__0_1f_0800a0cc[];
extern char s__0_1f_KW_08004ea4[];
extern char s__0_1f_c_080089dc[];
extern char s__0_2f_080046c8[];
extern char s__0_2f_08004b54[];
extern char s__0_2f_08004b64[];
extern char s__0_2f_0800a0c4[];
extern char s__0_2f_KW_08004e98[];
extern char s__0_2f_c_080089e4[];
extern char s__0_3f_080046d0[];
extern char s__0_3f_0800a0b0[];
extern char s__0_3f_KW_08004e88[];
extern char s__0_3f_c_080089ec[];
extern char s___04d_08004b3c[];
extern char s___Heap_memory_corrupted_08000954[];
extern char s__c_0_0f_c_08008978[];
extern char s__c_0_1f_c_080089b8[];
extern char s__c_0_2f_c_080089c4[];
extern char s__c_0_3f_c_080089d0[];
extern char s__c_c_0_0f_c_0800898c[];
extern char s__c_c_c_0_0f_c_08008998[];
extern char s__c_c_c_c_0_0f_c_080089a8[];
extern char s__d_c_0800557c[];
extern char s__s_open_error_080092f3[];
extern char s_http___www_fnirsi_cn_08003ff4[];
extern char s_settings____08003ee8[];
extern char s_write_flash_err_0800d6c0[];
extern char s_write_flash_ok_0800d6d4[];
extern uint32_t _uStack_1c;
extern uint32_t stack0xfffffff0;
extern uint32_t _MasterStackPointer;
extern void _FUN_080079f4(void);

/* Flash data symbols (used as address references) */
extern const char LAB_080029a8[];
extern const char LAB_08004fc8[];
extern const char LAB_080051fc[];
extern const char LAB_08005584[];
extern const char LAB_0800687c[];

/* Forward declarations */
uint32_t FUN_080001e4(int param_1, int param_2, uint32_t *param_3);
uint64_t FUN_080001ee(uint32_t param_1, uint32_t param_2);
void FUN_080001fa(void);
uint64_t FUN_08000238(void);
uint64_t FUN_0800030a();
int64_t FUN_080003f8(uint32_t param_1, int param_2, uint32_t param_3);
uint32_t FUN_08000438(uint32_t *param_1, int param_2);
byte FUN_080004a0();
char FUN_080004f2();
int FUN_08000506(uint32_t *param_1, uint32_t *param_2, uint32_t param_3);
void FUN_0800055e(uint32_t *param_1, uint32_t *param_2);
uint64_t FUN_080005a6();
uint32_t FUN_08000694();
uint32_t FUN_080006a4();
uint32_t FUN_080006e8();
void FUN_080009f8(void);
void FUN_08000a28(void);
void FUN_08000e1c(uint32_t param_1, uint32_t param_2);
void FUN_0800106c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
void FUN_080018c4();
void FUN_08001a7c(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, uint32_t param_7);
void FUN_08001e54(void);
void FUN_08001eda();
int FUN_08002180(int param_1, int param_2);
int FUN_0800219c(int *param_1, int param_2);
void FUN_08002218(int *param_1, uint8_t *param_2);
uint32_t FUN_08002400(short *param_1, short *param_2, uint32_t param_3);
void FUN_08002420(void);
int FUN_08002630();
int FUN_08002654();
void FUN_0800266c(byte *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
void FUN_0800269c(char *param_1);
uint32_t FUN_08002726();
uint64_t FUN_08002800(int param_1, byte *param_2, uint32_t param_3);
uint32_t FUN_080028cc(int param_1, int *param_2);
void FUN_080029d4(uint32_t param_1);
void FUN_080029e4(uint32_t param_1);
void FUN_080029f4(uint32_t param_1);
void FUN_08002a04(int param_1);
void FUN_08002a20();
void FUN_08002a64(uint32_t *param_1);
bool FUN_08002b5c(uint32_t param_1);
bool FUN_08002b7c(void);
void FUN_08002bc8(int param_1, uint32_t param_2);
void FUN_08002c20(void);
void FUN_08002c68(uint32_t param_1);
uint32_t FUN_08002ca0(void);
uint32_t FUN_08002cb0(uint32_t param_1);
uint32_t FUN_08002cc6(uint32_t param_1);
int FUN_08002d64(uint32_t *param_1, int param_2);
uint32_t FUN_08002dac(int param_1, uint32_t param_2);
uint32_t FUN_08002e04(int *param_1, int param_2);
int FUN_08002eb2(uint32_t *param_1, uint32_t param_2);
int FUN_08002f12(int *param_1);
uint32_t FUN_08002f52();
void FUN_080041d4(int param_1);
void FUN_0800558c(int param_1, int param_2);
void FUN_08006884();
void FUN_08006a1c();
void FUN_08006be4();
void FUN_08006d6c();
uint64_t FUN_08006fd8();
uint64_t FUN_08007380();
void FUN_080075b0(uint32_t *param_1, uint32_t param_2);
void FUN_080075bc(void);
void FUN_08007648(void);
void FUN_080076dc(uint32_t *param_1);
void FUN_080076f4(uint32_t param_1);
bool FUN_08007714(uint32_t param_1);
void FUN_08007738();
void FUN_080077a6(uint32_t *param_1, uint32_t *param_2);
void FUN_08007802(uint32_t *param_1, uint32_t param_2, int param_3);
bool FUN_08007814(uint32_t param_1);
void FUN_08007838(uint32_t *param_1);
void FUN_08007894(int param_1, int param_2);
void FUN_0800794c(void);
void FUN_080079f4(void);
uint64_t FUN_08007a16();
uint32_t FUN_08007c28();
int FUN_08007e28(int *param_1, uint32_t param_2);
uint64_t FUN_08007e8a();
int FUN_08007fdc();
void FUN_08008270(uint32_t param_1);
uint32_t FUN_0800827c();
void FUN_080082a0(void);
uint32_t FUN_080082b0(void);
int FUN_080082d8();
void FUN_080082fc(uint16_t *param_1, int param_2, uint32_t param_3);
uint32_t FUN_08008318(uint32_t param_1);
uint32_t FUN_08008344(void);
uint32_t FUN_08008350();
uint32_t FUN_08008484(uint8_t *param_1, uint32_t param_2, uint32_t param_3);
uint32_t FUN_080084d8(void);
uint32_t FUN_080084e0(void);
uint8_t FUN_080084ec(uint32_t param_1);
void FUN_08008520(void);
uint32_t FUN_0800854c(int param_1, uint32_t param_2, uint32_t param_3);
void FUN_0800861c(uint8_t *param_1, uint32_t param_2, uint32_t param_3);
void FUN_080086a4(void);
void FUN_080086c8(void);
uint64_t FUN_080086e0(int param_1, int param_2, uint32_t param_3);
int FUN_080089f4();
uint32_t FUN_08008ae4();
uint32_t FUN_08008ba0();
byte FUN_08008bec(void);
uint32_t FUN_08008c58();
void FUN_08008c90(int param_1, uint32_t param_2);
void FUN_08008c94(int param_1, uint32_t param_2);
void FUN_08008c98(uint32_t *param_1);
void FUN_08008cb0(uint32_t *param_1, uint16_t *param_2);
void FUN_08008d04(uint32_t *param_1, uint32_t param_2, int param_3, uint32_t param_4);
bool FUN_08008d5e();
void FUN_08008d6c(void);
uint32_t FUN_08008ddc();
int FUN_08008e82(int param_1, int param_2, int param_3, int param_4);
uint8_t FUN_080093bc();
uint8_t FUN_08009414(void);
int FUN_08009478(void);
uint8_t FUN_080094b0(void);
uint64_t FUN_080094f4();
uint32_t FUN_080095c8(char *param_1, int param_2);
uint32_t FUN_080095ee();
uint16_t FUN_08009604();
char FUN_080097fc();
uint32_t FUN_0800996c(int param_1, code *param_2, uint32_t param_3, uint32_t param_4);
void FUN_08009c88(uint32_t param_1);
void FUN_0800a618();
uint32_t FUN_0800a6cc();
int FUN_0800a91c();
uint32_t FUN_0800a94e();
void FUN_0800a9fc();
void FUN_0800aa78(uint32_t param_1);
int FUN_0800b078(char *param_1, uint32_t param_2, uint32_t param_3);
int FUN_0800b2c4(int *param_1, uint32_t param_2, int param_3);
void FUN_0800b338(void);
void FUN_0800b9d2(uint32_t param_1, int param_2);
uint32_t FUN_0800ba2c(void);
void FUN_0800bb08(uint8_t *param_1);
void FUN_0800bb1e(uint32_t *param_1, uint32_t param_2);
void FUN_0800bb28(uint32_t *param_1, uint32_t param_2);
uint32_t FUN_0800bb32(int param_1);
void FUN_0800bb38(int param_1, uint32_t param_2);
bool FUN_0800bb3c(int param_1, uint32_t param_2);
void FUN_0800bb4a(uint32_t *param_1, char *param_2);
void FUN_0800bc30(char *param_1, int param_2, uint32_t param_3);
void FUN_0800bc58(uint8_t *param_1, uint32_t param_2);
void FUN_0800bc68(uint8_t *param_1, uint32_t param_2);
void FUN_0800bc70(void);
int FUN_0800bd24();
uint32_t FUN_0800bda8();
void FUN_0800bdf2(uint32_t param_1, uint32_t *param_2);
void FUN_0800bf70(void);
void FUN_0800c108(int param_1);
void FUN_0800c120(void);
void FUN_0800c18c(int param_1, uint32_t param_2, uint32_t param_3);
void FUN_0800c19a(int param_1, int param_2, uint32_t param_3);
void FUN_0800c1b8(uint32_t *param_1, uint32_t param_2);
void FUN_0800c1c2(uint32_t *param_1, uint32_t param_2);
void FUN_0800c1d2();
void FUN_0800c1fc(int param_1, int param_2, uint32_t param_3);
void FUN_0800c22e(int param_1, int param_2, byte *param_3);
void FUN_0800c2f8(uint8_t *param_1);
void FUN_0800c30a(int param_1, uint32_t param_2);
void FUN_0800c314(uint32_t *param_1, uint32_t param_2);
void FUN_0800c498(int param_1, uint32_t param_2);
void FUN_0800c4a0(int param_1, uint32_t param_2);
uint64_t FUN_0800c4b4(uint32_t *param_1, uint32_t param_2);
bool FUN_0800c4c4(uint32_t *param_1, uint32_t param_2);
void FUN_0800c4d0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
void FUN_0800c52c(int param_1, uint32_t param_2, int param_3);
bool FUN_0800c54a(uint32_t *param_1, uint32_t param_2);
void FUN_0800c5ea(int param_1);
void FUN_0800c604(int param_1);
void FUN_0800c634(int param_1, byte *param_2);
void FUN_0800c692(int param_1, int param_2, uint32_t param_3);
uint32_t FUN_0800c69c(int param_1, uint32_t param_2);
void FUN_0800c7d2(int param_1, int param_2, uint32_t param_3);
uint32_t FUN_0800c7dc(int param_1, int param_2);
void FUN_0800c7ec(int param_1, byte *param_2);
void FUN_0800c848(uint32_t param_1);
void FUN_0800c860(int param_1, uint32_t param_2);
uint32_t FUN_0800c88c(int param_1);
uint32_t FUN_0800c89a();
void FUN_0800c8a8(int param_1, uint32_t param_2);
uint32_t FUN_0800c8ac(int param_1);
void FUN_0800c8b4(int param_1, uint32_t param_2, int param_3);
void FUN_0800c8c4(int param_1);
void FUN_0800c8d2(int param_1, uint32_t *param_2, uint32_t param_3, int param_4);
void FUN_0800c8ec(int param_1, uint32_t param_2);
void FUN_0800c8fa(int param_1, uint32_t param_2);
void FUN_0800c900(int param_1, int param_2, int param_3);
uint32_t FUN_0800c94c(int param_1);
void FUN_0800c956(int *param_1, uint32_t param_2);
void FUN_0800c9da(int param_1, uint32_t *param_2, int param_3, int param_4);
void FUN_0800c9f8(uint32_t *param_1, uint32_t param_2);
void FUN_0800ca24(int param_1, uint32_t param_2);
void FUN_0800cad2(int param_1, uint32_t param_2);
uint32_t FUN_0800cb42();
void FUN_0800cba2();
void FUN_0800cbba(int param_1);
void FUN_0800cbca(uint32_t param_1);
void FUN_0800cce6(int param_1);
uint32_t FUN_0800ccf4(int param_1);
void FUN_0800cdd6(int *param_1);
void FUN_0800cdf0(int *param_1);
void FUN_0800ce38();
void FUN_0800ce6c();
void FUN_0800cf04();
void FUN_0800cff2(int *param_1);
uint32_t FUN_0800d032();
void FUN_0800d0be(int param_1);
void FUN_0800d0cc(int param_1);
void FUN_0800d0da(int *param_1);
uint32_t FUN_0800d170(int param_1);
void FUN_0800d1a4(int *param_1);
void FUN_0800d296(int *param_1);
void FUN_0800d318(int *param_1);
void FUN_0800d3bc(int *param_1);
uint32_t FUN_0800d428();
void FUN_0800d4a0(uint32_t *param_1, uint32_t param_2);
void FUN_0800d4f4(int param_1);
void FUN_0800d500(int *param_1);
void FUN_0800d536(int *param_1);
int FUN_0800d6e8(byte *param_1, int param_2, byte *param_3, uint32_t *param_4);
uint32_t FUN_0800db40();
uint64_t FUN_0800dba4(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
int64_t FUN_0800dd1c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
uint32_t FUN_0800dfcc();
uint64_t FUN_0800e026();
uint64_t FUN_0800e054(int param_1);
void FUN_0800e07c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
int64_t FUN_0800e0f4(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
int FUN_0800e248();
void FUN_0800e2f0();
uint64_t FUN_0800e35c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
uint64_t FUN_0800e374(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
int64_t FUN_0800e548();
uint32_t FUN_0800e5a0(uint32_t param_1, uint32_t param_2);
uint64_t FUN_0800e670();
uint32_t FUN_0800e7f4();
uint32_t FUN_0800e82c(uint32_t param_1);
uint32_t FUN_0800e86c(uint32_t param_1);
uint32_t FUN_0800e89c(uint32_t param_1);
uint32_t FUN_0800e8c4();
uint32_t FUN_0800e9c6();
void display_debug_printf();
void display_draw_arc();
void display_draw_arc_solid();
uint64_t display_draw_char_12px();
void display_draw_char_12px_b();
void display_draw_char_16px(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                            uint32_t param_5, uint32_t param_6, int param_7);
void display_draw_char_24px(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                            uint32_t param_5, uint32_t param_6, int param_7);
void display_draw_char_32px(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                            uint32_t param_5, uint32_t param_6, int param_7);
void display_draw_char_8px(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4,
                           uint32_t param_5, uint32_t param_6, int param_7);
uint64_t display_draw_circle(int param_1, int param_2, uint32_t param_3, uint32_t param_4);
void display_draw_hline();
void display_draw_line();
void display_draw_line_aa();
void display_draw_pixel(uint32_t param_1, uint32_t param_2, uint32_t param_3);
void display_draw_rect_outline(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                               uint32_t param_4, uint32_t param_5);
void display_draw_rounded_filled_rect();
void display_draw_rounded_rect();
void display_draw_text();
void display_draw_text_rtl(uint32_t param_1, uint32_t param_2, byte *param_3, uint32_t param_4,
                           uint32_t param_5, uint32_t param_6, uint32_t param_7);
void display_fill_rect();
void display_fill_rect_masked();
void display_record_graph_pixel(uint32_t param_1, uint32_t param_2, uint16_t param_3);
uint32_t display_send_pixel_burst(int param_1, int param_2, uint32_t param_3);
void display_set_address_window();
void display_state_reset(void);
void display_write_byte_spi(int param_1);
void display_write_cmd(uint32_t param_1);
void display_write_data16(uint32_t param_1);
void display_write_data8(uint32_t param_1);
uint32_t fs_fat32_check_media_attr();
uint32_t fs_fat32_get_sector_info();
uint64_t fs_fat32_init(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
uint32_t fs_fat32_is_writable(int param_1);
void fs_fat32_mount_notify();
uint8_t fs_fat32_read_block();
void fs_fat32_reset_dir_state(void);
uint32_t fs_fat32_seek_cluster();
uint32_t fs_fat32_time_update();
uint32_t fs_fat32_validate_bpb();
uint8_t fs_fat32_write_block();
void fs_file_close();
int fs_file_open(int *param_1, uint32_t param_2, uint32_t param_3);
uint32_t fs_find_open_handle(uint32_t *param_1, uint32_t *param_2);
int fs_open_jpeg_file(uint32_t param_1);
void gpio_configure_pin(int param_1, uint32_t param_2, uint32_t param_3, int param_4);
void gpio_write(uint32_t param_1, int param_2);
int jpeg_decode_render(int *param_1, uint32_t param_2, uint32_t param_3);
uint32_t jpeg_parse_header(uint32_t *param_1, uint32_t param_2, int param_3, uint32_t param_4,
                           uint32_t param_5);
void measure_format_value(uint32_t param_1, uint32_t param_2);
void rtos_free(int param_1);
void rtos_heap_coalesce(uint32_t *param_1);
int64_t rtos_heap_expand();
uint32_t rtos_heap_get_ptr(void);
void rtos_heap_merge_free();
uint32_t rtos_heap_oom_handler();
uint32_t rtos_malloc();
uint32_t rtos_msg_alloc();
void rtos_msg_enqueue();
uint32_t rtos_queue_process();
void rtos_scheduler_init(void);
void rtos_systick_handler();
byte rtos_task_is_blocked(int param_1);
void rtos_task_wake(uint32_t param_1, uint32_t param_2);
void sensor_touch_poll_init(void);
uint32_t sensor_touch_query(int param_1);
void sensor_touch_send_cmd(int param_1);
void sys_auto_shutdown_tick(void);
void sys_clock_init(void);
int sys_decimal_digit_count();
void sys_delay_cycles(int param_1);
void sys_delay_ms(uint32_t param_1);
int sys_get_decimal_digit();
void sys_handle_mode_switch(byte *param_1);
void sys_handle_reset_menu(void);
void sys_handle_rotary_input(void);
int sys_hex_digit_count(uint32_t param_1);
uint32_t sys_is_usb_charging(void);
void sys_main_measurement_loop(void);
int sys_pow_int();
void sys_power_off(void);
void sys_print_string(char *param_1, char *param_2);
void sys_record_history_sample(uint32_t param_1, uint32_t param_2);
void sys_settings_load(void);
void sys_settings_struct_copy(uint8_t *param_1, uint8_t *param_2);
void sys_sprintf();
int sys_strlen(char *param_1);
void sys_uart_putchar_stub();
void sys_usb_detect_init(void);
void sys_write_settings_to_flash(void);
void ui_draw_about_screen();
void ui_draw_auto_shutdown_menu();
void ui_draw_battery_icon();
void ui_draw_brightness_menu();
void ui_draw_charging_level_bars(int param_1);
void ui_draw_hold_icon();
void ui_draw_hold_reading(void);
void ui_draw_language_menu();
void ui_draw_led_icon(int param_1);
void ui_draw_main_menu();
void ui_draw_measurement_unit();
void ui_draw_menu_background(void);
void ui_draw_mode_icon(uint32_t param_1);
void ui_draw_range_nav_arrows();
void ui_draw_reset_return_button();
void ui_draw_scale_boxes();
void ui_draw_settings_page();
void ui_draw_settings_tab_dots(uint32_t param_1);
void ui_draw_unit_label(uint32_t param_1, uint32_t param_2);
void ui_draw_unit_text_large(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                             uint32_t param_4);
void ui_draw_unit_text_small(void);
void ui_handle_settings_nav();
void ui_language_confirm_screen(void);
void ui_language_input_handler(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                               uint32_t param_4);
void ui_language_select_screen();
uint32_t ui_load_and_draw_jpeg();
uint64_t ui_show_charging_screen(uint32_t param_1, uint32_t param_2, uint32_t param_3);
void ui_show_low_battery_warning(void);
void ui_update_ncv_level_animated(void);
void ui_update_ncv_status(void);

/* ================================================================
 * FUN_080001e4  @  0x080001E4
 */

uint32_t FUN_080001e4(int param_1, int param_2, uint32_t *param_3)

{
    if (param_2 == 0x73) {
        if (*(int *)(param_1 + 0x14) == 0) {
            FUN_080004a0(param_1, *param_3, 0xffffffff);
        }
        return 1;
    }
    return 0;
}

/* ================================================================
 * FUN_080001ee  @  0x080001EE
 */

uint64_t FUN_080001ee(uint32_t param_1, uint32_t param_2)

{
    rtos_heap_merge_free(param_1, param_2);
    return CONCAT44(param_2, param_1);
}

/* ================================================================
 * FUN_080001fa  @  0x080001FA
 */

void FUN_080001fa(void)

{
    return;
}

/* ================================================================
 * FUN_08000238  @  0x08000238
 */

uint64_t FUN_08000238(void)

{
    return CONCAT44(DAT_08000250, DAT_0800024c);
}

/* ================================================================
 * rtos_malloc  @  0x0800025E
 */

uint32_t rtos_malloc() {
    uint32_t param_1 = 0;
    uint32_t *puVar1;
    uint32_t *puVar2;
    uint32_t *puVar3;
    int *piVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t *puVar7;

    puVar3 = (uint32_t *)rtos_heap_get_ptr();
    puVar7 = (uint32_t *)*puVar3;
    uVar6 = param_1 + 0xb & 0xfffffff8;
    if (uVar6 <= param_1) {
        return (uint32_t *)0x0;
    }
    do {
        puVar1 = puVar7;
        for (puVar2 = (uint32_t *)puVar7[1]; puVar2 != (uint32_t *)0x0;
             puVar2 = (uint32_t *)puVar2[1]) {
            if (uVar6 <= *puVar2) {
                if (*puVar2 < uVar6 + 8) {
                    puVar1[1] = puVar2[1];
                } else {
                    piVar4 = (int *)((int)puVar2 + uVar6);
                    piVar4[1] = puVar2[1];
                    *piVar4 = *puVar2 - uVar6;
                    puVar1[1] = (uint32_t)piVar4;
                    *puVar2 = uVar6;
                }
                return puVar2 + 1;
            }
            puVar1 = puVar2;
        }
        iVar5 = rtos_heap_expand(puVar7, uVar6);
    } while (iVar5 != 0);
    return (uint32_t *)0x0;
}

/* ================================================================
 * rtos_free  @  0x080002BC
 */

void rtos_free(int param_1)

{
    int *piVar1;
    int *piVar2;
    int *piVar3;

    piVar3 = (int *)(param_1 + -4);
    piVar1 = (int *)rtos_heap_get_ptr();
    if (param_1 == 0) {
        return;
    }
    piVar2 = (int *)*piVar1;
    for (piVar1 = (int *)((int *)*piVar1)[1]; piVar1 != (int *)0x0 && piVar1 < piVar3;
         piVar1 = (int *)piVar1[1]) {
        piVar2 = piVar1;
    }
    if ((int *)(*piVar2 + (int)piVar2) == piVar3) {
        *piVar2 = *piVar2 + *piVar3;
    } else {
        piVar2[1] = (int)piVar3;
        piVar2 = piVar3;
    }
    if ((int *)(*piVar2 + (int)piVar2) == piVar1) {
        piVar2[1] = piVar1[1];
        *piVar2 = *piVar2 + *piVar1;
        return;
    }
    piVar2[1] = (int)piVar1;
    return;
}

/* ================================================================
 * FUN_0800030a  @  0x0800030A
 */

uint64_t FUN_0800030a() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    bool bVar10;

    if (param_4 == 0 && param_3 == 0) {
        return 0;
    }
    uVar5 = 0;
    if (param_4 != 0) {
        iVar3 = LZCOUNT(param_4);
        uVar1 = param_4 << iVar3;
        uVar5 = uVar1 >> iVar3 ^ param_4 | param_3;
    } else {
        iVar3 = LZCOUNT(param_3);
        uVar1 = param_3 << iVar3;
    }
    uVar4 = -iVar3 + 0x20;
    if (param_4 != 0) {
        uVar1 = uVar1 | param_3 >> (uVar4 & 0xff);
        uVar4 = -iVar3 + 0x40;
    }
    uVar2 = uVar1 >> 0x10;
    if (uVar5 != 0 || (uVar1 & 0xffff) != 0) {
        uVar2 = uVar2 + 1;
    }
    iVar3 = 0;
    uVar5 = 0;
    for (; param_4 < param_2 || param_2 - param_4 < (uint32_t)(param_3 <= param_1);
         param_2 = (param_2 - (uVar6 * param_4 + uVar8 * param_3 +
                               (int)((uint64_t)uVar6 * (uint64_t)param_3 >> 0x20))) -
                   (uint32_t)bVar10) {
        if (param_2 != 0) {
            iVar7 = LZCOUNT(param_2);
            uVar1 = param_2 << iVar7;
        } else {
            iVar7 = LZCOUNT(param_1);
            uVar1 = param_1 << iVar7;
        }
        uVar8 = -iVar7 + 0x20;
        if (param_2 != 0) {
            uVar1 = uVar1 | param_1 >> (uVar8 & 0xff);
            uVar8 = -iVar7 + 0x40;
        }
        uVar9 = (uVar8 - uVar4) - 0x10;
        uVar6 = uVar1 / uVar2 >> (0x20 - (uVar9 & 0x1f) & 0xff);
        uVar8 = uVar6;
        uVar1 = uVar1 / uVar2 << (uVar9 & 0x1f);
        if ((int)uVar9 < 0) {
            uVar8 = 0;
            uVar1 = uVar6;
        }
        uVar6 = uVar1;
        if (0x1f < (int)uVar9) {
            uVar6 = 0;
            uVar8 = uVar1;
        }
        if (uVar6 == 0 && uVar8 == 0) {
            uVar6 = 1;
        }
        bVar10 = CARRY4(uVar5, uVar6);
        uVar5 = uVar5 + uVar6;
        uVar1 = (uint32_t)((uint64_t)uVar6 * (uint64_t)param_3);
        iVar3 = iVar3 + uVar8 + bVar10;
        bVar10 = param_1 < uVar1;
        param_1 = param_1 - uVar1;
    }
    return CONCAT44(iVar3, uVar5);
}

/* ================================================================
 * FUN_080003f8  @  0x080003F8
 */

int64_t FUN_080003f8(uint32_t param_1, int param_2, uint32_t param_3)

{
    if ((int)(param_3 - 0x20) < 0) {
        return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                        param_1 << (param_3 & 0xff));
    }
    return (uint64_t)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
}

/* ================================================================
 * display_debug_printf  @  0x08000420
 */

void display_debug_printf() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uStack_c;
    uint32_t uStack_8;
    uint32_t uStack_4;

    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    rtos_msg_alloc(param_1, DAT_08000434, &uStack_c);
    return;
}

/* ================================================================
 * FUN_08000438  @  0x08000438
 */

uint32_t FUN_08000438(uint32_t *param_1, int param_2)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    iVar1 = 0;
    do {
        param_1[8] = iVar1;
    LAB_08000444:
        iVar1 = (*(code *)param_1[3])(param_1);
        if (iVar1 == 0) {
        LAB_0800049a:
            return param_1[8];
        }
        if (iVar1 == 0x25) {
            uVar3 = 0;
            iVar1 = (*(code *)param_1[3])(param_1);
            if (iVar1 == 0)
                /* goto LAB_0800049a; */ (void)0;
            if (iVar1 - 0x41U < 0x1a) {
                iVar1 = iVar1 + 0x20;
                uVar3 = 0x800;
            }
            *param_1 = uVar3;
            iVar2 = FUN_080001e4(param_1, iVar1, param_2);
            if (iVar2 == 0)
                /* goto LAB_08000450; */ (void)0;
            if (iVar2 == 1) {
                param_2 = param_2 + 4;
            } else {
                param_2 = (param_2 + 7U & 0xfffffff8) + 8;
            }
            /* goto LAB_08000444; */ (void)0;
        }
    LAB_08000450:
        (*(code *)param_1[1])(iVar1, param_1[2]);
        iVar1 = param_1[8] + 1;
    } while (true);
}

/* ================================================================
 * FUN_080004a0  @  0x080004A0
 */

byte FUN_080004a0() {
    byte *param_1 = 0;
    uint8_t *param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t uVar1;
    uint8_t *puVar2;

    if (param_3 == 1) {
        uVar1 = 1;
    } else {
        if ((int)((uint32_t)*param_1 << 0x1a) < 0) {
            param_3 = *(uint32_t *)(param_1 + 0x1c);
        }
        for (uVar1 = 0; (uVar1 < param_3 && (param_2[uVar1] != '\0')); uVar1 = uVar1 + 1) {
        }
    }
    puVar2 = param_2 + uVar1;
    *(uint32_t *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar1;
    *(uint32_t *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar1;
    for (; param_2 < puVar2; param_2 = param_2 + 1) {
        (**(code **)(param_1 + 4))(*param_2, *(uint32_t *)(param_1 + 8));
    }
    return param_1;
}

/* ================================================================
 * FUN_080004f2  @  0x080004F2
 */

char FUN_080004f2() {
    int param_1 = 0;
    char param_2 = 0;
    char *pcVar1;

    pcVar1 = (char *)(param_1 + -1);
    do {
        pcVar1 = pcVar1 + 1;
        if (param_2 == *pcVar1) {
            return pcVar1;
        }
    } while (*pcVar1 != '\0');
    return (char *)0x0;
}

/* ================================================================
 * FUN_08000506  @  0x08000506
 */

int FUN_08000506(uint32_t *param_1, uint32_t *param_2, uint32_t param_3)

{
    uint32_t *puVar1;
    uint32_t *puVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;

    if ((((uint32_t)param_1 | (uint32_t)param_2) & 3) == 0) {
        while (3 < param_3) {
            uVar5 = *param_1;
            param_1 = param_1 + 1;
            uVar3 = *param_2;
            param_2 = param_2 + 1;
            param_3 = param_3 - 4;
            if (uVar5 != uVar3) {
                if ((uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                     uVar5 >> 0x18) <= (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                        (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18)) {
                    return -1;
                }
                return 1;
            }
        }
    }
    if (param_3 != 0) {
        if ((param_3 & 1) == 0)
            /* goto LAB_0800053e; */ (void)0;
        param_3 = param_3 + 1;
        puVar1 = param_1;
        puVar2 = param_2;
        while (true) {
            param_1 = (uint32_t *)((int)puVar1 + 1);
            param_2 = (uint32_t *)((int)puVar2 + 1);
            iVar4 = (uint32_t)(byte)*puVar1 - (uint32_t)(byte)*puVar2;
            if (iVar4 != 0) {
                return iVar4;
            }
            param_3 = param_3 - 2;
            if (param_3 == 0)
                break;
        LAB_0800053e:
            puVar1 = (uint32_t *)((int)param_1 + 1);
            puVar2 = (uint32_t *)((int)param_2 + 1);
            iVar4 = (uint32_t)(byte)*param_1 - (uint32_t)(byte)*param_2;
            if (iVar4 != 0) {
                return iVar4;
            }
        }
        return 0;
    }
    return 0;
}

/* ================================================================
 * FUN_0800055e  @  0x0800055E
 */

void FUN_0800055e(uint32_t *param_1, uint32_t *param_2)

{
    char cVar1;
    char *pcVar2;
    char *pcVar3;
    uint32_t uVar4;

    if ((((uint32_t)param_1 | (uint32_t)param_2) & 3) == 0) {
        while (true) {
            uVar4 = *param_2;
            param_2 = param_2 + 1;
            if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0)
                break;
            *param_1 = uVar4;
            param_1 = param_1 + 1;
        }
        while (true) {
            *(char *)param_1 = (char)uVar4;
            if ((uVar4 & 0xff) == 0)
                break;
            uVar4 = uVar4 >> 8;
            param_1 = (uint32_t *)((int)param_1 + 1);
        }
    } else {
        do {
            pcVar2 = (char *)((int)param_2 + 1);
            uVar4 = *param_2;
            pcVar3 = (char *)((int)param_1 + 1);
            *(char *)param_1 = (char)uVar4;
            if ((char)uVar4 == '\0') {
                return;
            }
            param_2 = (uint32_t *)((int)param_2 + 2);
            cVar1 = *pcVar2;
            param_1 = (uint32_t *)((int)param_1 + 2);
            *pcVar3 = cVar1;
        } while (cVar1 != '\0');
    }
    return;
}

/* ================================================================
 * FUN_080005a6  @  0x080005A6
 */

uint64_t FUN_080005a6() {
    uint32_t *param_1 = 0;
    uint32_t *param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    bool bVar1;
    uint32_t *puVar2;
    uint32_t *puVar3;
    uint32_t *puVar4;
    byte *pbVar5;
    byte bVar6;
    uint16_t uVar7;
    byte in_r12;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    bool bVar13;

    puVar4 = param_2;
    if (3 < param_3) {
        uVar8 = (uint32_t)param_1 & 3;
        puVar2 = param_1;
        uVar9 = uVar8;
        if (uVar8 != 0) {
            bVar6 = (byte)*param_2;
            puVar4 = (uint32_t *)((int)param_2 + 1);
            if (uVar8 < 3) {
                puVar4 = (uint32_t *)((int)param_2 + 2);
                uVar9 = (uint32_t)*(byte *)((int)param_2 + 1);
            }
            *(byte *)param_1 = bVar6;
            param_2 = puVar4;
            if (uVar8 < 2) {
                param_2 = (uint32_t *)((int)puVar4 + 1);
                bVar6 = (byte)*puVar4;
            }
            param_3 = (param_3 + uVar8) - 4;
            puVar4 = (uint32_t *)((int)param_1 + 1);
            if (uVar8 < 3) {
                puVar4 = (uint32_t *)((int)param_1 + 2);
                *(byte *)((int)param_1 + 1) = (byte)uVar9;
            }
            puVar2 = puVar4;
            if (uVar8 < 2) {
                puVar2 = (uint32_t *)((int)puVar4 + 1);
                *(byte *)puVar4 = bVar6;
            }
        }
        param_4 = (uint32_t)param_2 & 3;
        if (param_4 == 0) {
            uVar9 = 0;
            while (uVar8 = param_3 - 0x20, 0x1f < param_3) {
                uVar9 = param_2[1];
                uVar10 = param_2[2];
                uVar11 = param_2[3];
                *puVar2 = *param_2;
                puVar2[1] = uVar9;
                puVar2[2] = uVar10;
                puVar2[3] = uVar11;
                uVar9 = param_2[4];
                uVar10 = param_2[5];
                uVar11 = param_2[6];
                uVar12 = param_2[7];
                param_2 = param_2 + 8;
                puVar2[4] = uVar9;
                puVar2[5] = uVar10;
                puVar2[6] = uVar11;
                puVar2[7] = uVar12;
                puVar2 = puVar2 + 8;
                param_3 = uVar8;
            }
            if ((uVar8 & 0x10) != 0) {
                uVar9 = *param_2;
                uVar10 = param_2[1];
                uVar11 = param_2[2];
                uVar12 = param_2[3];
                param_2 = param_2 + 4;
                *puVar2 = uVar9;
                puVar2[1] = uVar10;
                puVar2[2] = uVar11;
                puVar2[3] = uVar12;
                puVar2 = puVar2 + 4;
            }
            if ((int)(param_3 << 0x1c) < 0) {
                uVar9 = *param_2;
                uVar10 = param_2[1];
                param_2 = param_2 + 2;
                *puVar2 = uVar9;
                puVar2[1] = uVar10;
                puVar2 = puVar2 + 2;
            }
            puVar3 = puVar2;
            puVar4 = param_2;
            if ((uVar8 & 4) != 0) {
                puVar4 = param_2 + 1;
                uVar9 = *param_2;
                puVar3 = puVar2 + 1;
                *puVar2 = uVar9;
            }
            uVar7 = (uint16_t)uVar9;
            if ((uVar8 & 3) != 0) {
                bVar1 = (uVar8 & 2) != 0;
                param_3 = param_3 << 0x1f;
                bVar13 = (int)param_3 < 0;
                puVar2 = puVar4;
                if (bVar1) {
                    puVar2 = (uint32_t *)((int)puVar4 + 2);
                    uVar7 = (uint16_t)*puVar4;
                }
                puVar4 = puVar2;
                if (bVar13) {
                    puVar4 = (uint32_t *)((int)puVar2 + 1);
                    param_3 = (uint32_t)(byte)*puVar2;
                }
                puVar2 = puVar3;
                if (bVar1) {
                    puVar2 = (uint32_t *)((int)puVar3 + 2);
                    *(uint16_t *)puVar3 = uVar7;
                }
                puVar3 = puVar2;
                if (bVar13) {
                    puVar3 = (uint32_t *)((int)puVar2 + 1);
                    *(byte *)puVar2 = (byte)param_3;
                }
                return CONCAT44(puVar4, puVar3);
            }
            return CONCAT44(puVar4, puVar3);
        }
        while (true) {
            in_r12 = (byte)uVar9;
            if (param_3 < 8)
                break;
            puVar4 = param_2 + 1;
            param_4 = *param_2;
            param_2 = param_2 + 2;
            uVar9 = *puVar4;
            *puVar2 = param_4;
            puVar2[1] = uVar9;
            puVar2 = puVar2 + 2;
            param_3 = param_3 - 8;
        }
        param_3 = param_3 - 4;
        param_1 = puVar2;
        puVar4 = param_2;
        if (-1 < (int)param_3) {
            puVar4 = param_2 + 1;
            param_4 = *param_2;
            param_1 = puVar2 + 1;
            *puVar2 = param_4;
        }
    }
    bVar6 = (byte)param_4;
    bVar1 = (param_3 & 2) != 0;
    param_3 = param_3 << 0x1f;
    bVar13 = (int)param_3 < 0;
    if (bVar1) {
        pbVar5 = (byte *)((int)puVar4 + 1);
        bVar6 = (byte)*puVar4;
        puVar4 = (uint32_t *)((int)puVar4 + 2);
        in_r12 = *pbVar5;
    }
    puVar2 = puVar4;
    if (bVar13) {
        puVar2 = (uint32_t *)((int)puVar4 + 1);
        param_3 = (uint32_t)(byte)*puVar4;
    }
    if (bVar1) {
        pbVar5 = (byte *)((int)param_1 + 1);
        *(byte *)param_1 = bVar6;
        param_1 = (uint32_t *)((int)param_1 + 2);
        *pbVar5 = in_r12;
    }
    puVar4 = param_1;
    if (bVar13) {
        puVar4 = (uint32_t *)((int)param_1 + 1);
        *(byte *)param_1 = (byte)param_3;
    }
    return CONCAT44(puVar2, puVar4);
}

/* ================================================================
 * FUN_08000694  @  0x08000694
 */

uint32_t FUN_08000694() {
    uint32_t *param_1 = 0;
    uint32_t param_2 = 0;
    uint8_t param_3 = 0;
    uint16_t uVar1;
    uint32_t *puVar2;
    uint8_t *puVar3;
    uint32_t *puVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar7;
    bool bVar8;

    uVar1 = CONCAT11(param_3, param_3);
    uVar6 = CONCAT22(uVar1, uVar1);
    if (param_2 < 4) {
        if ((param_2 & 2) != 0) {
            puVar3 = (uint8_t *)((int)param_1 + 1);
            *(uint8_t *)param_1 = param_3;
            param_1 = (uint32_t *)((int)param_1 + 2);
            *puVar3 = param_3;
        }
        puVar2 = param_1;
        if ((int)(param_2 << 0x1f) < 0) {
            puVar2 = (uint32_t *)((int)param_1 + 1);
            *(uint8_t *)param_1 = param_3;
        }
        return puVar2;
    }
    if (((uint32_t)param_1 & 3) != 0) {
        iVar7 = 4 - ((uint32_t)param_1 & 3);
        puVar2 = param_1;
        if (iVar7 != 2) {
            puVar2 = (uint32_t *)((int)param_1 + 1);
            *(uint8_t *)param_1 = param_3;
        }
        param_1 = puVar2;
        if (1 < iVar7) {
            param_1 = (uint32_t *)((int)puVar2 + 2);
            *(uint16_t *)puVar2 = uVar1;
        }
        param_2 = param_2 - iVar7;
    }
    bVar8 = 0x1f < param_2;
    param_2 = param_2 - 0x20;
    do {
        if (bVar8) {
            *param_1 = uVar6;
            param_1[1] = uVar6;
            param_1[2] = uVar6;
            param_1[3] = uVar6;
            param_1[4] = uVar6;
            param_1[5] = uVar6;
            param_1[6] = uVar6;
            param_1[7] = uVar6;
            param_1 = param_1 + 8;
            bVar8 = 0x1f < param_2;
            param_2 = param_2 - 0x20;
        }
    } while (bVar8);
    if ((param_2 & 0x10) != 0) {
        *param_1 = uVar6;
        param_1[1] = uVar6;
        param_1[2] = uVar6;
        param_1[3] = uVar6;
        param_1 = param_1 + 4;
    }
    if ((int)(param_2 << 0x1c) < 0) {
        *param_1 = uVar6;
        param_1[1] = uVar6;
        param_1 = param_1 + 2;
    }
    uVar5 = param_2 << 0x1e;
    puVar2 = param_1;
    if ((param_2 << 0x1c & 0x40000000) != 0) {
        puVar2 = param_1 + 1;
        *param_1 = uVar6;
    }
    if (uVar5 != 0) {
        puVar4 = puVar2;
        if ((int)uVar5 < 0) {
            puVar4 = (uint32_t *)((int)puVar2 + 2);
            *(uint16_t *)puVar2 = uVar1;
        }
        puVar2 = puVar4;
        if ((uVar5 & 0x40000000) != 0) {
            puVar2 = (uint32_t *)((int)puVar4 + 1);
            *(uint8_t *)puVar4 = param_3;
        }
        return puVar2;
    }
    return puVar2;
}

/* ================================================================
 * FUN_080006a4  @  0x080006A4
 */

uint32_t FUN_080006a4() {
    uint32_t *param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t *puVar1;
    uint8_t *puVar2;
    uint32_t *puVar3;
    uint32_t uVar4;
    int iVar5;
    bool bVar6;

    if (param_2 < 4) {
        if ((param_2 & 2) != 0) {
            puVar2 = (uint8_t *)((int)param_1 + 1);
            *(uint8_t *)param_1 = 0;
            param_1 = (uint32_t *)((int)param_1 + 2);
            *puVar2 = 0;
        }
        puVar1 = param_1;
        if ((int)(param_2 << 0x1f) < 0) {
            puVar1 = (uint32_t *)((int)param_1 + 1);
            *(uint8_t *)param_1 = 0;
        }
        return puVar1;
    }
    if (((uint32_t)param_1 & 3) != 0) {
        iVar5 = 4 - ((uint32_t)param_1 & 3);
        puVar1 = param_1;
        if (iVar5 != 2) {
            puVar1 = (uint32_t *)((int)param_1 + 1);
            *(uint8_t *)param_1 = 0;
        }
        param_1 = puVar1;
        if (1 < iVar5) {
            param_1 = (uint32_t *)((int)puVar1 + 2);
            *(uint16_t *)puVar1 = 0;
        }
        param_2 = param_2 - iVar5;
    }
    bVar6 = 0x1f < param_2;
    param_2 = param_2 - 0x20;
    do {
        if (bVar6) {
            *param_1 = 0;
            param_1[1] = 0;
            param_1[2] = 0;
            param_1[3] = 0;
            param_1[4] = 0;
            param_1[5] = 0;
            param_1[6] = 0;
            param_1[7] = 0;
            param_1 = param_1 + 8;
            bVar6 = 0x1f < param_2;
            param_2 = param_2 - 0x20;
        }
    } while (bVar6);
    if ((param_2 & 0x10) != 0) {
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = 0;
        param_1[3] = 0;
        param_1 = param_1 + 4;
    }
    if ((int)(param_2 << 0x1c) < 0) {
        *param_1 = 0;
        param_1[1] = 0;
        param_1 = param_1 + 2;
    }
    uVar4 = param_2 << 0x1e;
    puVar1 = param_1;
    if ((param_2 << 0x1c & 0x40000000) != 0) {
        puVar1 = param_1 + 1;
        *param_1 = 0;
    }
    if (uVar4 != 0) {
        puVar3 = puVar1;
        if ((int)uVar4 < 0) {
            puVar3 = (uint32_t *)((int)puVar1 + 2);
            *(uint16_t *)puVar1 = 0;
        }
        puVar1 = puVar3;
        if ((uVar4 & 0x40000000) != 0) {
            puVar1 = (uint32_t *)((int)puVar3 + 1);
            *(uint8_t *)puVar3 = 0;
        }
        return puVar1;
    }
    return puVar1;
}

/* ================================================================
 * FUN_080006e8  @  0x080006E8
 */

uint32_t FUN_080006e8() {
    uint32_t *param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t *puVar1;
    uint32_t *puVar2;
    uint32_t uVar3;
    bool bVar4;

    bVar4 = 0x1f < param_2;
    param_2 = param_2 - 0x20;
    do {
        if (bVar4) {
            *param_1 = 0;
            param_1[1] = 0;
            param_1[2] = 0;
            param_1[3] = 0;
            param_1[4] = 0;
            param_1[5] = 0;
            param_1[6] = 0;
            param_1[7] = 0;
            param_1 = param_1 + 8;
            bVar4 = 0x1f < param_2;
            param_2 = param_2 - 0x20;
        }
    } while (bVar4);
    if ((param_2 & 0x10) != 0) {
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = 0;
        param_1[3] = 0;
        param_1 = param_1 + 4;
    }
    if ((int)(param_2 << 0x1c) < 0) {
        *param_1 = 0;
        param_1[1] = 0;
        param_1 = param_1 + 2;
    }
    uVar3 = param_2 << 0x1e;
    puVar2 = param_1;
    if ((param_2 << 0x1c & 0x40000000) != 0) {
        puVar2 = param_1 + 1;
        *param_1 = 0;
    }
    if (uVar3 != 0) {
        puVar1 = puVar2;
        if ((int)uVar3 < 0) {
            puVar1 = (uint32_t *)((int)puVar2 + 2);
            *(uint16_t *)puVar2 = 0;
        }
        puVar2 = puVar1;
        if ((uVar3 & 0x40000000) != 0) {
            puVar2 = (uint32_t *)((int)puVar1 + 1);
            *(uint8_t *)puVar1 = 0;
        }
        return puVar2;
    }
    return puVar2;
}

/* ================================================================
 * rtos_heap_get_ptr  @  0x08000740
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

uint32_t rtos_heap_get_ptr(void)

{
    return DAT_08000744;
}

/* ================================================================
 * rtos_heap_expand  @  0x08000750
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

/* WARNING: Removing unreachable block (ram,0x08000764) */

int64_t rtos_heap_expand() {
    uint8_t local_10[4];

    return ZEXT48(local_10) << 0x20;
}

/* ================================================================
 * rtos_heap_merge_free  @  0x08000778
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

void rtos_heap_merge_free() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t *puVar1;
    uint32_t uVar2;
    bool bVar3;
    uint32_t local_18;

    local_18 = param_4;
    if ((param_2 < param_1 + 0x10) && (rtos_systick_handler(0, &local_18, 0x10),
                                       bVar3 = local_18 != param_2, param_2 = local_18, bVar3)) {
        param_1 = local_18;
    }
    puVar1 = (uint32_t *)rtos_heap_get_ptr();
    *puVar1 = param_1;
    uVar2 = param_1 + 0x10;
    rtos_heap_coalesce(param_1);
    if (param_2 == uVar2) {
        return;
    }
    rtos_msg_enqueue(*puVar1, uVar2, param_2 - uVar2, local_18);
    return;
}

/* ================================================================
 * rtos_heap_coalesce  @  0x080007D6
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

void rtos_heap_coalesce(uint32_t *param_1)

{
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = param_1;
    return;
}

/* ================================================================
 * rtos_msg_alloc  @  0x08000810
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

uint32_t rtos_msg_alloc() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t uVar1;
    int iVar2;

    uVar1 = rtos_queue_process();
    iVar2 = rtos_task_is_blocked(param_2);
    if (iVar2 != 0) {
        return 0xffffffff;
    }
    return uVar1;
}

/* ================================================================
 * rtos_msg_enqueue  @  0x0800083C
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

void rtos_msg_enqueue() {
    int *param_1 = 0;
    int *param_2 = 0;
    int param_3 = 0;
    int *piVar1;

    piVar1 = (int *)param_1[1];
    for (; piVar1 != (int *)0x0 && piVar1 < param_2; piVar1 = (int *)piVar1[1]) {
        param_1 = piVar1;
    }
    piVar1 = param_2;
    if ((int *)(*param_1 + (int)param_1) != param_2) {
        piVar1 = (int *)(((int)param_2 + 3U & 0xfffffff8) + 4);
        param_3 = param_3 - ((int)piVar1 - (int)param_2);
    }
    *piVar1 = param_3;
    rtos_free(piVar1 + 1);
    return;
}

/* ================================================================
 * rtos_queue_process  @  0x0800087A
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

uint32_t rtos_queue_process() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint8_t auStack_40[4];
    uint32_t local_3c;
    uint32_t uStack_38;
    int local_34;
    uint32_t uStack_30;
    uint32_t local_2c;

    local_2c = 0;
    local_34 = DAT_0800089c + 0x800088c;
    local_3c = param_4;
    uStack_38 = param_2;
    uStack_30 = param_1;
    FUN_08000438(auStack_40, param_3);
    return;
}

/* ================================================================
 * rtos_task_is_blocked  @  0x080008A0
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

byte rtos_task_is_blocked(int param_1)

{
    return *(byte *)(param_1 + 0xc) & 0x80;
}

/* ================================================================
 * rtos_systick_handler  @  0x080008A8
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

void rtos_systick_handler() {
    int iVar1;

    iVar1 = rtos_heap_oom_handler();
    if (iVar1 != 0) {
        FUN_08001eda();
        return;
    }
    return;
}

/* ================================================================
 * rtos_scheduler_init  @  0x080008CC
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

void rtos_scheduler_init(void)

{
    uint32_t *unaff_r5;

    FUN_08000238();
    *unaff_r5 = 0;
    unaff_r5[1] = 0;
    unaff_r5[2] = 0;
    unaff_r5[3] = 0;
    unaff_r5[4] = 0;
    unaff_r5[5] = 0;
    unaff_r5[6] = 0;
    unaff_r5[7] = 0;
    unaff_r5[8] = 0;
    unaff_r5[9] = 0;
    unaff_r5[10] = 0;
    unaff_r5[0xb] = 0;
    unaff_r5[0xc] = 0;
    unaff_r5[0xd] = 0;
    unaff_r5[0xe] = 0;
    unaff_r5[0xf] = 0;
    return;
}

/* ================================================================
 * rtos_task_wake  @  0x08000900
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

void rtos_task_wake(uint32_t param_1, uint32_t param_2)

{
    FUN_080001fa();
    FUN_08001eda(param_1, param_2);
    (*DAT_08000244)();
    /* WARNING: Could not recover jumptable at 0x08000222. Too many branches */
    /* WARNING: Treating indirect jump as call */
    (*DAT_08000248)();
    return;
}

/* ================================================================
 * rtos_heap_oom_handler  @  0x0800091C
 * nearby string: "SIGRTMEM: Out of heap memory"
 */

uint32_t rtos_heap_oom_handler() {
    int param_1 = 0;
    char *pcVar1;

    if (param_1 == 1) {
        pcVar1 = s___Heap_memory_corrupted_08000954;
    } else {
        pcVar1 = (char *)0x0;
    }
    sys_print_string(s_SIGRTMEM__Out_of_heap_memory_08000934, pcVar1);
    return 1;
}

/* ================================================================
 * sys_print_string  @  0x0800096C
 */

void sys_print_string(char *param_1, char *param_2)

{
    char cVar1;

    cVar1 = '\n';
    for (; (sys_uart_putchar_stub(cVar1),
            param_1 != (char *)0x0 && (cVar1 = *param_1, cVar1 != '\0'));
         param_1 = param_1 + 1) {
    }
    for (; (param_2 != (char *)0x0 && (*param_2 != '\0')); param_2 = param_2 + 1) {
        sys_uart_putchar_stub();
    }
    sys_uart_putchar_stub(10);
    return;
}

/* ================================================================
 * FUN_080009f8  @  0x080009F8
 */

void FUN_080009f8(void)

{
    int iVar1;

    iVar1 = FUN_08007714(2);
    if (iVar1 != 0) {
        FUN_080076f4(2);
        *(uint16_t *)(DAT_08000a20 + 2) = 1;
        *(uint32_t *)(DAT_08000a24 + 8) = *(uint32_t *)(DAT_08000a24 + 8) & 0xfffffeff;
        return;
    }
    return;
}

/* ================================================================
 * FUN_08000a28  @  0x08000A28
 */

void FUN_08000a28(void)

{
    int iVar1;

    iVar1 = FUN_08007814(0x20000);
    if (iVar1 != 0) {
        FUN_080076f4(0x20000);
        return;
    }
    return;
}

/* ================================================================
 * display_draw_circle  @  0x08000A46
 */

uint64_t display_draw_circle(int param_1, int param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    short sVar2;
    short sVar3;
    short sVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;
    int iVar9;
    uint32_t uVar10;

    sVar2 = (short)param_3;
    uVar1 = param_3 >> 1;
    uVar7 = (uint32_t)(sVar2 * 0x2c3) / 1000 + 1;
    iVar8 = param_1;
    iVar9 = param_2;
    uVar10 = param_3;
    display_draw_hline(param_1 - param_3 & 0xffff, param_2, param_3 << 1, param_4, param_1, param_2,
                       param_3);
    for (uVar6 = 1; uVar6 <= uVar7; uVar6 = uVar6 + 1) {
        if ((int)sVar2 * (int)sVar2 + uVar1 < param_3 * param_3 + uVar6 * uVar6) {
            if (uVar7 < param_3) {
                sVar3 = (short)uVar6 * 2 + -2;
                sVar4 = ((short)param_1 - (short)uVar6) + 1;
                display_draw_hline(sVar4, param_2 + param_3 & 0xffff, sVar3, param_4, iVar8, iVar9,
                                   uVar10);
                display_draw_hline(sVar4, param_2 - param_3 & 0xffff, sVar3, param_4);
            }
            param_3 = param_3 - 1;
        }
        iVar5 = (param_3 & 0x7fff) << 1;
        sVar3 = (short)param_1 - (short)param_3;
        display_draw_hline(sVar3, param_2 + uVar6 & 0xffff, iVar5, param_4, iVar8, iVar9, uVar10);
        display_draw_hline(sVar3, param_2 - uVar6 & 0xffff, iVar5, param_4);
    }
    return CONCAT44(iVar9, iVar8);
}

/* ================================================================
 * display_set_address_window  @  0x08000AFA
 */

void display_set_address_window() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    display_write_cmd(0x2a);
    display_write_data16(param_1);
    display_write_data16(param_3);
    display_write_cmd(0x2b);
    display_write_data16(param_2);
    display_write_data16(param_4);
    display_write_cmd(0x2c);
    return;
}

/* ================================================================
 * display_draw_line  @  0x08000B34
 */

void display_draw_line() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    int param_4 = 0;
    uint32_t param_5 = 0;
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t local_30;
    uint32_t local_2c;

    param_3 = param_3 - param_1;
    iVar5 = 0;
    param_4 = param_4 - param_2;
    iVar4 = 0;
    if (param_3 < 1) {
        if (param_3 == 0) {
            iVar2 = 0;
        } else {
            iVar2 = -1;
            param_3 = -param_3;
        }
    } else {
        iVar2 = 1;
    }
    if (param_4 < 1) {
        if (param_4 == 0) {
            iVar1 = 0;
        } else {
            iVar1 = -1;
            param_4 = -param_4;
        }
    } else {
        iVar1 = 1;
    }
    iVar3 = param_4;
    if (param_4 < param_3) {
        iVar3 = param_3;
    }
    local_30 = param_2;
    local_2c = param_1;
    for (uVar6 = 0; (int)uVar6 < iVar3 + 1; uVar6 = uVar6 + 1 & 0xffff) {
        display_draw_pixel(local_2c & 0xffff, local_30 & 0xffff, param_5);
        iVar5 = iVar5 + param_3;
        iVar4 = iVar4 + param_4;
        if (iVar3 < iVar5) {
            iVar5 = iVar5 - iVar3;
            local_2c = local_2c + iVar2;
        }
        if (iVar3 < iVar4) {
            iVar4 = iVar4 - iVar3;
            local_30 = local_30 + iVar1;
        }
    }
    return;
}

/* ================================================================
 * display_draw_line_aa  @  0x08000BD0
 */

void display_draw_line_aa() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    int param_4 = 0;
    uint32_t param_5 = 0;
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t local_30;
    uint32_t local_2c;

    param_3 = param_3 - param_1;
    iVar5 = 0;
    param_4 = param_4 - param_2;
    iVar4 = 0;
    if (param_3 < 1) {
        if (param_3 == 0) {
            iVar2 = 0;
        } else {
            iVar2 = -1;
            param_3 = -param_3;
        }
    } else {
        iVar2 = 1;
    }
    if (param_4 < 1) {
        if (param_4 == 0) {
            iVar1 = 0;
        } else {
            iVar1 = -1;
            param_4 = -param_4;
        }
    } else {
        iVar1 = 1;
    }
    iVar3 = param_4;
    if (param_4 < param_3) {
        iVar3 = param_3;
    }
    local_30 = param_2;
    local_2c = param_1;
    for (uVar6 = 0; (int)uVar6 < iVar3 + 1; uVar6 = uVar6 + 1 & 0xffff) {
        display_record_graph_pixel(local_2c & 0xffff, local_30 & 0xffff, param_5);
        iVar5 = iVar5 + param_3;
        iVar4 = iVar4 + param_4;
        if (iVar3 < iVar5) {
            iVar5 = iVar5 - iVar3;
            local_2c = local_2c + iVar2;
        }
        if (iVar3 < iVar4) {
            iVar4 = iVar4 - iVar3;
            local_30 = local_30 + iVar1;
        }
    }
    return;
}

/* ================================================================
 * display_draw_arc  @  0x08000C6C
 */

void display_draw_arc() {
    int param_1 = 0;
    short param_2 = 0;
    short param_3 = 0;
    uint16_t param_4 = 0;
    uint16_t param_5 = 0;
    int param_6 = 0;
    uint16_t uVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    uint16_t uVar4;
    short sVar5;
    byte bVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    byte *pbVar9;
    byte *pbVar10;

    uVar1 = *(uint16_t *)(param_1 + 2);
    uVar2 = *(uint16_t *)(param_1 + 4);
    pbVar9 = (byte *)(param_1 + 6);
    for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1 & 0xff) {
        pbVar10 = pbVar9;
        sVar5 = param_2;
        for (uVar7 = 0; uVar7 < (uVar1 & 0x7ff) >> 3; uVar7 = uVar7 + 1 & 0xff) {
            uVar8 = (uint32_t)*pbVar10;
            bVar6 = 0;
            do {
                uVar4 = param_4;
                if ((-1 < (int)(uVar8 << 0x18)) || (uVar4 = param_5, param_6 != 0)) {
                    display_draw_pixel(sVar5, param_3, uVar4);
                }
                sVar5 = sVar5 + 1;
                bVar6 = bVar6 + 1;
                uVar8 = (uVar8 & 0x7f) << 1;
            } while (bVar6 < 8);
            pbVar10 = pbVar10 + 1;
        }
        pbVar9 = pbVar10;
        if ((uVar1 & 7) != 0) {
            pbVar9 = pbVar10 + 1;
            uVar8 = (uint32_t)*pbVar10;
            for (uVar7 = 0; uVar7 < (uVar1 & 7); uVar7 = uVar7 + 1 & 0xff) {
                uVar4 = param_4;
                if ((-1 < (int)(uVar8 << 0x18)) || (uVar4 = param_5, param_6 != 0)) {
                    display_draw_pixel(sVar5, param_3, uVar4);
                }
                sVar5 = sVar5 + 1;
                uVar8 = (uVar8 & 0x7f) << 1;
            }
        }
        param_3 = param_3 + 1;
    }
    return;
}

/* ================================================================
 * display_draw_arc_solid  @  0x08000D20
 */

void display_draw_arc_solid() {
    int param_1 = 0;
    short param_2 = 0;
    short param_3 = 0;
    uint16_t uVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    short sVar4;
    byte bVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    byte *pbVar8;
    byte *pbVar9;

    uVar1 = *(uint16_t *)(param_1 + 2);
    uVar2 = *(uint16_t *)(param_1 + 4);
    pbVar8 = (byte *)(param_1 + 6);
    for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1 & 0xff) {
        pbVar9 = pbVar8;
        sVar4 = param_2;
        for (uVar6 = 0; uVar6 < (uVar1 & 0x7ff) >> 3; uVar6 = uVar6 + 1 & 0xff) {
            uVar7 = (uint32_t)*pbVar9;
            bVar5 = 0;
            do {
                if ((int)(uVar7 << 0x18) < 0) {
                    FUN_08000e1c(sVar4, param_3);
                }
                sVar4 = sVar4 + 1;
                bVar5 = bVar5 + 1;
                uVar7 = (uVar7 & 0x7f) << 1;
            } while (bVar5 < 8);
            pbVar9 = pbVar9 + 1;
        }
        pbVar8 = pbVar9;
        if ((uVar1 & 7) != 0) {
            pbVar8 = pbVar9 + 1;
            uVar7 = (uint32_t)*pbVar9;
            for (uVar6 = 0; uVar6 < (uVar1 & 7); uVar6 = uVar6 + 1 & 0xff) {
                if ((int)(uVar7 << 0x18) < 0) {
                    FUN_08000e1c(sVar4, param_3);
                }
                sVar4 = sVar4 + 1;
                uVar7 = (uVar7 & 0x7f) << 1;
            }
        }
        param_3 = param_3 + 1;
    }
    return;
}

/* ================================================================
 * display_draw_pixel  @  0x08000DBA
 */

void display_draw_pixel(uint32_t param_1, uint32_t param_2, uint32_t param_3)

{
    display_set_address_window(param_1, param_2, param_1, param_2);
    display_write_data16(param_3);
    return;
}

/* ================================================================
 * display_record_graph_pixel  @  0x08000DD0
 */

void display_record_graph_pixel(uint32_t param_1, uint32_t param_2, uint16_t param_3)

{
    uint32_t uVar1;

    uVar1 = (uint32_t)*DAT_08000e14;
    if ((((uVar1 * 10 <= param_2) && (param_2 <= (uVar1 + 1) * 10)) &&
         (uVar1 = param_2 + uVar1 * -10 & 0xffff, uVar1 < 10)) &&
        (param_1 < 0x9e)) {
        *(uint16_t *)(DAT_08000e18 + uVar1 * 0x13c + param_1 * 2) = param_3;
    }
    return;
}

/* ================================================================
 * FUN_08000e1c  @  0x08000E1C
 */

void FUN_08000e1c(uint32_t param_1, uint32_t param_2)

{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t *puVar3;
    uint64_t uVar4;

    if (param_1 < 0xf1) {
        puVar3 = (uint32_t *)(DAT_08000e40 + param_1 * 8);
        uVar1 = *puVar3;
        uVar2 = puVar3[1];
        uVar4 = FUN_080003f8(1, 0, param_2);
        *puVar3 = uVar1 | (uint32_t)uVar4;
        puVar3[1] = uVar2 | (uint32_t)((uint64_t)uVar4 >> 0x20);
    }
    return;
}

/* ================================================================
 * display_draw_rect_outline  @  0x08000E44
 */

void display_draw_rect_outline(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                               uint32_t param_4, uint32_t param_5)

{
    display_draw_line();
    display_draw_line(param_1, param_2, param_1, param_4, param_5);
    display_draw_line(param_1, param_4, param_3, param_4, param_5);
    display_draw_line(param_3, param_2, param_3, param_4, param_5);
    return;
}

/* ================================================================
 * display_draw_rounded_rect  @  0x08000E88
 */

void display_draw_rounded_rect() {
    int param_1 = 0;
    int param_2 = 0;
    int param_3 = 0;
    int param_4 = 0;
    int param_5 = 0;
    uint32_t param_6 = 0;
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;

    uVar4 = param_3 - param_5;
    uVar3 = param_1 + param_5;
    display_draw_line(uVar3 & 0xffff, param_2, uVar4 & 0xffff, param_2, param_6, param_1, param_2,
                      param_3);
    uVar1 = param_4 - param_5;
    uVar2 = param_5 + param_2;
    display_draw_line(param_1, uVar2 & 0xffff, param_1, uVar1 & 0xffff, param_6);
    display_draw_line(uVar3 & 0xffff, param_4, uVar4 & 0xffff, param_4, param_6);
    display_draw_line(param_3, uVar2 & 0xffff, param_3, uVar1 + 1 & 0xffff, param_6);
    display_draw_line(uVar3 & 0xffff, param_2, param_1, uVar2 & 0xffff, param_6);
    display_draw_line(uVar4 & 0xffff, param_2, param_3, uVar2 & 0xffff, param_6);
    display_draw_line(param_1, uVar1 & 0xffff, uVar3 & 0xffff, param_4, param_6);
    display_draw_line(uVar4 & 0xffff, param_4, param_3, uVar1 & 0xffff, param_6);
    return;
}

/* ================================================================
 * display_fill_rect  @  0x08000F24
 */

void display_fill_rect() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t param_5 = 0;
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int *piVar4;
    uint32_t *puVar5;

    display_set_address_window();
    iVar1 = DAT_08000f90;
    FUN_0800bb28(DAT_08000f90, 1);
    uVar2 = DAT_08000f94;
    FUN_08008c90(DAT_08000f94, 0x4000);
    piVar4 = (int *)(DAT_08000f90 + 8);
    puVar5 = (uint32_t *)(DAT_08000f90 + 0xc);
    for (; uVar3 = param_1, param_2 <= param_4; param_2 = param_2 + 1 & 0xffff) {
        for (; uVar3 <= param_3; uVar3 = uVar3 + 1 & 0xffff) {
            do {
            } while (-1 < *piVar4 << 0x1e);
            *puVar5 = param_5;
        }
    }
    sys_delay_cycles(10);
    FUN_08008c94(uVar2, 0x4000);
    FUN_0800bb28(iVar1, 0);
    return;
}

/* ================================================================
 * display_fill_rect_masked  @  0x08000F98
 */

void display_fill_rect_masked() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uVar1;

    for (; uVar1 = param_1, param_2 < param_4; param_2 = param_2 + 1 & 0xffff) {
        for (; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
            FUN_08000e1c(uVar1, param_2);
        }
    }
    return;
}

/* ================================================================
 * display_draw_rounded_filled_rect  @  0x08000FC8
 */

void display_draw_rounded_filled_rect() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    int param_4 = 0;
    uint32_t param_5 = 0;
    uint32_t param_6 = 0;
    short sVar1;
    short sVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;

    display_fill_rect(param_1, param_2, param_3, param_4 - 1U & 0xffff, param_6, param_1, param_2,
                      param_3, param_4);
    for (uVar4 = 0; iVar3 = DAT_08001068, uVar4 < param_5; uVar4 = uVar4 + 1 & 0xff) {
        uVar5 = param_1 + uVar4;
        sVar1 = (((short)param_2 + (short)param_5) - (short)uVar4) + -1;
        display_draw_line(uVar5 & 0xffff, param_2, uVar5 & 0xffff, sVar1,
                          *(uint16_t *)(DAT_08001068 + 0x1a));
        sVar2 = ((short)param_4 - ((short)param_5 - (short)uVar4)) + 1;
        display_draw_line(uVar5 & 0xffff, sVar2, uVar5 & 0xffff, param_4,
                          *(uint16_t *)(iVar3 + 0x1a));
        uVar5 = (param_3 - param_1) + uVar5 + uVar4 * -2;
        display_draw_line(uVar5 & 0xffff, param_2, uVar5 & 0xffff, sVar1,
                          *(uint16_t *)(iVar3 + 0x1a));
        display_draw_line(uVar5 & 0xffff, sVar2, uVar5 & 0xffff, param_4,
                          *(uint16_t *)(iVar3 + 0x1a));
    }
    return;
}

/* ================================================================
 * FUN_0800106c  @  0x0800106C
 */

void FUN_0800106c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t local_20;
    uint32_t local_1c;

    local_20 = param_3;
    local_1c = param_4;
    gpio_write(DAT_080010ec, 1);
    iVar3 = DAT_080010ec + 1;
    gpio_write(iVar3, 1);
    gpio_write(iVar3, 1);
    uVar1 = DAT_080010f0;
    local_1c = 0x3101800;
    local_20 = 0x100;
    FUN_08008cb0(DAT_080010f0, &local_20);
    uVar2 = DAT_080010f4;
    local_20 = 0x1000;
    FUN_08008cb0(DAT_080010f4, &local_20);
    local_20 = 0x4000;
    FUN_08008cb0(uVar2, &local_20);
    FUN_08008c94(uVar1, 0x100);
    FUN_08008c94(uVar2, 0x1000);
    FUN_08008c94(uVar2, 0x4000);
    return;
}

/* ================================================================
 * display_draw_text  @  0x080012F2
 */

void display_draw_text() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    byte *param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t param_5 = 0;
    uint32_t param_6 = 0;
    uint32_t param_7 = 0;
    byte bVar1;

    do {
        while (true) {
            bVar1 = *param_3;
            if (bVar1 == 0) {
                return;
            }
            if (0x7f < bVar1)
                break;
            display_draw_char_8px(param_1, param_2, bVar1, param_4, param_5, param_6, param_7);
            param_1 = param_1 + (param_6 >> 1) & 0xffff;
            param_3 = param_3 + 1;
        }
        if (param_6 == 0xc) {
            display_draw_char_12px_b(param_1, param_2, param_3, param_4, param_5, 0xc, param_7);
        } else if (param_6 == 0x10) {
            display_draw_char_16px(param_1, param_2, param_3, param_4, param_5, 0x10, param_7);
        } else if (param_6 == 0x18) {
            display_draw_char_24px(param_1, param_2, param_3, param_4, param_5, 0x18, param_7);
        } else {
            if (param_6 != 0x20) {
                return;
            }
            display_draw_char_32px(param_1, param_2, param_3, param_4, param_5, 0x20, param_7);
        }
        param_1 = param_1 + param_6 & 0xffff;
        param_3 = param_3 + 2;
    } while (true);
}

/* ================================================================
 * display_draw_text_rtl  @  0x0800139E
 */

void display_draw_text_rtl(uint32_t param_1, uint32_t param_2, byte *param_3, uint32_t param_4,
                           uint32_t param_5, uint32_t param_6, uint32_t param_7)

{
    byte bVar1;

    while (bVar1 = *param_3, bVar1 != 0) {
        if (bVar1 < 0x80) {
            display_draw_char_12px(param_1, param_2, bVar1, param_4, param_5, param_6, param_7);
            param_1 = param_1 + (param_6 >> 1) & 0xffff;
            param_3 = param_3 + 1;
        } else {
            if (param_6 == 0x18) {
                FUN_080018c4(param_1, param_2, param_3, param_4, param_5, 0x18, param_7);
            }
            param_1 = param_1 + param_6 & 0xffff;
            param_3 = param_3 + 2;
        }
    }
    return;
}

/* ================================================================
 * display_draw_char_8px  @  0x080013FC
 */

void display_draw_char_8px(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4,
                           uint32_t param_5, uint32_t param_6, int param_7)

{
    byte bVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t local_30;

    uVar8 = param_6 >> 1;
    uVar9 = 0;
    uVar2 = param_3 - 0x20U & 0xff;
    uVar10 = param_1;
    display_set_address_window(param_1, param_2, (param_1 + uVar8) - 1 & 0xffff,
                               (param_2 + param_6) - 1 & 0xffff, param_1, param_1);
    uVar6 = 0;
    local_30 = param_2;
    do {
        if (((uint32_t)((uVar8 & 7) != 0) + (param_6 >> 4)) * param_6 <= uVar6) {
            return;
        }
        if (param_6 == 0xc) {
            iVar3 = DAT_080014fc + uVar2 * 0xc;
        } else {
            uVar7 = uVar2;
            iVar3 = DAT_08001500;
            if (param_6 != 0x10) {
                if (param_6 != 0x18) {
                    if (param_6 != 0x20) {
                        return;
                    }
                    iVar3 = DAT_080014f8 + uVar2 * 0x40;
                    /* goto LAB_08001460; */ (void)0;
                }
                uVar7 = uVar2 * 3;
                iVar3 = DAT_08001504;
            }
            iVar3 = iVar3 + uVar7 * 0x10;
        }
    LAB_08001460:
        uVar7 = 0;
        bVar1 = *(byte *)(iVar3 + uVar6);
        do {
            uVar4 = 1 << uVar7 & (uint32_t)bVar1;
            if (param_7 == 0) {
                uVar5 = param_5;
                if (uVar4 != 0) {
                    uVar5 = param_4;
                }
                display_write_data16(uVar5);
                uVar9 = uVar9 + 1 & 0xff;
                if (uVar9 == uVar8 * (uVar9 / uVar8)) {
                    uVar9 = 0;
                    break;
                }
            } else {
                if (uVar4 != 0) {
                    display_draw_pixel(param_1, local_30, param_4);
                }
                param_1 = param_1 + 1 & 0xffff;
                if (param_1 - uVar10 == uVar8) {
                    local_30 = local_30 + 1 & 0xffff;
                    param_1 = uVar10;
                    break;
                }
            }
            uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 8);
        uVar6 = uVar6 + 1 & 0xffff;
    } while (true);
}

/* ================================================================
 * display_draw_char_12px  @  0x08001508
 */

uint64_t display_draw_char_12px() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t param_5 = 0;
    uint32_t param_6 = 0;
    byte bVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t local_34;

    uVar7 = param_6 >> 1;
    uVar2 = param_3 - 0x20U & 0xff;
    display_set_address_window(param_1, param_2, (param_1 + uVar7) - 1 & 0xffff,
                               (param_2 + param_6) - 1 & 0xffff);
    uVar5 = 0;
    uVar4 = param_1;
    local_34 = param_2;
    do {
        if (((uint32_t)((uVar7 & 7) != 0) + (param_6 >> 4)) * param_6 <= uVar5) {
        LAB_080015ca:
            return CONCAT44(local_34, param_1);
        }
        if (param_6 == 0xc) {
            iVar3 = DAT_080015d4 + uVar2 * 0xc;
        } else {
            uVar6 = uVar2;
            iVar3 = DAT_080015d8;
            if (param_6 != 0x10) {
                if (param_6 != 0x18) {
                    if (param_6 == 0x20) {
                        iVar3 = DAT_080015d0 + uVar2 * 0x40;
                        /* goto LAB_08001568; */ (void)0;
                    }
                    /* goto LAB_080015ca; */ (void)0;
                }
                uVar6 = uVar2 * 3;
                iVar3 = DAT_080015dc;
            }
            iVar3 = iVar3 + uVar6 * 0x10;
        }
    LAB_08001568:
        uVar6 = 0;
        bVar1 = *(byte *)(iVar3 + uVar5);
        do {
            if ((1 << uVar6 & (uint32_t)bVar1) != 0) {
                FUN_08000e1c(uVar4, local_34);
            }
            uVar4 = uVar4 + 1 & 0xffff;
            if (uVar4 - param_1 == uVar7) {
                local_34 = local_34 + 1 & 0xffff;
                uVar4 = param_1;
                break;
            }
            uVar6 = uVar6 + 1 & 0xff;
        } while (uVar6 < 8);
        uVar5 = uVar5 + 1 & 0xffff;
    } while (true);
}

/* ================================================================
 * display_draw_char_12px_b  @  0x080015E0
 */

void display_draw_char_12px_b() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    char *param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t param_5 = 0;
    uint32_t param_6 = 0;
    int param_7 = 0;
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t local_30;

    uVar8 = 0;
    uVar5 = 0;
    uVar7 = param_1;
    local_30 = param_2;
    do {
        if ((*(char *)(DAT_080016d4 + uVar5 * 0x1a) == *param_3) &&
            (iVar1 = DAT_080016d4 + uVar5 * 0x1a, *(char *)(iVar1 + 1) == param_3[1])) {
            display_set_address_window(uVar7, local_30, (uVar7 + param_6) - 1 & 0xffff,
                                       (local_30 + param_6) - 1 & 0xffff);
            for (uVar6 = 0; uVar6 < ((uint32_t)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
                 uVar6 = uVar6 + 1 & 0xff) {
                uVar4 = 0;
                do {
                    uVar3 = (uint32_t)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
                    if (param_7 == 0) {
                        uVar2 = param_5;
                        if (uVar3 != 0) {
                            uVar2 = param_4;
                        }
                        display_write_data16(uVar2);
                        uVar8 = uVar8 + 1 & 0xff;
                        if (uVar8 == param_6 * (uVar8 / param_6)) {
                            uVar8 = 0;
                            break;
                        }
                    } else {
                        if (uVar3 != 0) {
                            display_draw_pixel(uVar7, local_30, param_4);
                        }
                        uVar7 = uVar7 + 1 & 0xffff;
                        if (uVar7 - param_1 == param_6) {
                            local_30 = local_30 + 1 & 0xffff;
                            uVar7 = param_1;
                            break;
                        }
                    }
                    uVar4 = uVar4 + 1 & 0xff;
                } while (uVar4 < 8);
            }
        }
        uVar5 = uVar5 + 1 & 0xffff;
        if (0x10 < uVar5) {
            return;
        }
    } while (true);
}

/* ================================================================
 * display_draw_char_16px  @  0x080016D8
 */

void display_draw_char_16px(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                            uint32_t param_5, uint32_t param_6, int param_7)

{
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t local_30;

    uVar8 = 0;
    uVar5 = 0;
    uVar7 = param_1;
    local_30 = param_2;
    do {
        if ((*(char *)(DAT_080017c8 + uVar5 * 0x22) == *param_3) &&
            (iVar1 = DAT_080017c8 + uVar5 * 0x22, *(char *)(iVar1 + 1) == param_3[1])) {
            display_set_address_window(uVar7, local_30, (uVar7 + param_6) - 1 & 0xffff,
                                       (local_30 + param_6) - 1 & 0xffff);
            for (uVar6 = 0; uVar6 < ((uint32_t)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
                 uVar6 = uVar6 + 1 & 0xff) {
                uVar4 = 0;
                do {
                    uVar3 = (uint32_t)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
                    if (param_7 == 0) {
                        uVar2 = param_5;
                        if (uVar3 != 0) {
                            uVar2 = param_4;
                        }
                        display_write_data16(uVar2);
                        uVar8 = uVar8 + 1 & 0xff;
                        if (uVar8 == param_6 * (uVar8 / param_6)) {
                            uVar8 = 0;
                            break;
                        }
                    } else {
                        if (uVar3 != 0) {
                            display_draw_pixel(uVar7, local_30, param_4);
                        }
                        uVar7 = uVar7 + 1 & 0xffff;
                        if (uVar7 - param_1 == param_6) {
                            local_30 = local_30 + 1 & 0xffff;
                            uVar7 = param_1;
                            break;
                        }
                    }
                    uVar4 = uVar4 + 1 & 0xff;
                } while (uVar4 < 8);
            }
        }
        uVar5 = uVar5 + 1 & 0xffff;
        if (0x48 < uVar5) {
            return;
        }
    } while (true);
}

/* ================================================================
 * display_draw_char_24px  @  0x080017CC
 */

void display_draw_char_24px(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                            uint32_t param_5, uint32_t param_6, int param_7)

{
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t local_30;

    uVar8 = 0;
    uVar5 = 0;
    uVar7 = param_1;
    local_30 = param_2;
    do {
        if ((*(char *)(DAT_080018c0 + uVar5 * 0x4a) == *param_3) &&
            (iVar1 = DAT_080018c0 + uVar5 * 0x4a, *(char *)(iVar1 + 1) == param_3[1])) {
            display_set_address_window(uVar7, local_30, (uVar7 + param_6) - 1 & 0xffff,
                                       (local_30 + param_6) - 1 & 0xffff);
            for (uVar6 = 0; uVar6 < ((uint32_t)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
                 uVar6 = uVar6 + 1 & 0xff) {
                uVar4 = 0;
                do {
                    uVar3 = (uint32_t)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
                    if (param_7 == 0) {
                        uVar2 = param_5;
                        if (uVar3 != 0) {
                            uVar2 = param_4;
                        }
                        display_write_data16(uVar2);
                        uVar8 = uVar8 + 1 & 0xff;
                        if (uVar8 == param_6 * (uVar8 / param_6)) {
                            uVar8 = 0;
                            break;
                        }
                    } else {
                        if (uVar3 != 0) {
                            display_draw_pixel(uVar7, local_30, param_4);
                        }
                        uVar7 = uVar7 + 1 & 0xffff;
                        if (uVar7 - param_1 == param_6) {
                            local_30 = local_30 + 1 & 0xffff;
                            uVar7 = param_1;
                            break;
                        }
                    }
                    uVar4 = uVar4 + 1 & 0xff;
                } while (uVar4 < 8);
            }
        }
        uVar5 = uVar5 + 1 & 0xffff;
        if (0x25 < uVar5) {
            return;
        }
    } while (true);
}

/* ================================================================
 * FUN_080018c4  @  0x080018C4
 */

void FUN_080018c4() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    char *param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t param_5 = 0;
    uint32_t param_6 = 0;
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t local_30;

    uVar4 = 0;
    uVar2 = param_1;
    local_30 = param_2;
    do {
        if ((*(char *)(DAT_08001984 + uVar4 * 0x4a) == *param_3) &&
            (iVar1 = DAT_08001984 + uVar4 * 0x4a, *(char *)(iVar1 + 1) == param_3[1])) {
            display_set_address_window(uVar2, local_30, (uVar2 + param_6) - 1 & 0xffff,
                                       (local_30 + param_6) - 1 & 0xffff);
            for (uVar5 = 0; uVar5 < ((uint32_t)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
                 uVar5 = uVar5 + 1 & 0xff) {
                uVar3 = 0;
                do {
                    if (((uint32_t)*(byte *)(iVar1 + uVar5 + 2) & 1 << uVar3) != 0) {
                        FUN_08000e1c(uVar2, local_30);
                    }
                    uVar2 = uVar2 + 1 & 0xffff;
                    if (uVar2 - param_1 == param_6) {
                        local_30 = local_30 + 1 & 0xffff;
                        uVar2 = param_1;
                        break;
                    }
                    uVar3 = uVar3 + 1 & 0xff;
                } while (uVar3 < 8);
            }
        }
        uVar4 = uVar4 + 1 & 0xffff;
        if (0x25 < uVar4) {
            return;
        }
    } while (true);
}

/* ================================================================
 * display_draw_char_32px  @  0x08001988
 */

void display_draw_char_32px(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                            uint32_t param_5, uint32_t param_6, int param_7)

{
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t local_30;

    uVar8 = 0;
    uVar5 = 0;
    uVar7 = param_1;
    local_30 = param_2;
    do {
        if ((*(char *)(DAT_08001a78 + uVar5 * 0x82) == *param_3) &&
            (iVar1 = DAT_08001a78 + uVar5 * 0x82, *(char *)(iVar1 + 1) == param_3[1])) {
            display_set_address_window(uVar7, local_30, (uVar7 + param_6) - 1 & 0xffff,
                                       (local_30 + param_6) - 1 & 0xffff);
            for (uVar6 = 0; uVar6 < ((uint32_t)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
                 uVar6 = uVar6 + 1 & 0xff) {
                uVar4 = 0;
                do {
                    uVar3 = (uint32_t)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
                    if (param_7 == 0) {
                        uVar2 = param_5;
                        if (uVar3 != 0) {
                            uVar2 = param_4;
                        }
                        display_write_data16(uVar2);
                        uVar8 = uVar8 + 1 & 0xff;
                        if (uVar8 == param_6 * (uVar8 / param_6)) {
                            uVar8 = 0;
                            break;
                        }
                    } else {
                        if (uVar3 != 0) {
                            display_draw_pixel(uVar7, local_30, param_4);
                        }
                        uVar7 = uVar7 + 1 & 0xffff;
                        if (uVar7 - param_1 == param_6) {
                            local_30 = local_30 + 1 & 0xffff;
                            uVar7 = param_1;
                            break;
                        }
                    }
                    uVar4 = uVar4 + 1 & 0xff;
                } while (uVar4 < 8);
            }
        }
        uVar5 = uVar5 + 1 & 0xffff;
        if (0x18 < uVar5) {
            return;
        }
    } while (true);
}

/* ================================================================
 * FUN_08001a7c  @  0x08001A7C
 */

void FUN_08001a7c(uint32_t param_1, uint32_t param_2, char *param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, uint32_t param_7)

{
    for (; *param_3 != '\0'; param_3 = param_3 + 1) {
        display_draw_char_12px(param_1, param_2, *param_3, param_4, param_5, param_6, param_7);
        param_1 = param_1 + (param_6 >> 1) & 0xffff;
    }
    return;
}

/* ================================================================
 * display_write_data16  @  0x08001AB8
 */

void display_write_data16(uint32_t param_1)

{
    uint32_t uVar1;

    uVar1 = DAT_08001ae8;
    FUN_08008c90(DAT_08001ae8, 0x4000);
    display_write_byte_spi(param_1 >> 8);
    display_write_byte_spi(param_1 & 0xff);
    sys_delay_cycles(5);
    FUN_08008c94(uVar1, 0x4000);
    return;
}

/* ================================================================
 * display_write_data8  @  0x08001AEC
 */

void display_write_data8(uint32_t param_1)

{
    uint32_t uVar1;

    uVar1 = DAT_08001b18;
    FUN_08008c90(DAT_08001b18, 0x4000);
    display_write_byte_spi(param_1);
    sys_delay_cycles(5);
    FUN_08008c94(uVar1, 0x4000);
    return;
}

/* ================================================================
 * display_write_cmd  @  0x08001B1C
 */

void display_write_cmd(uint32_t param_1)

{
    uint32_t uVar1;

    uVar1 = DAT_08001b5c;
    FUN_08008c90(DAT_08001b5c, 0x1000);
    FUN_08008c90(uVar1, 0x4000);
    display_write_byte_spi(param_1);
    sys_delay_cycles(5);
    FUN_08008c94(uVar1, 0x4000);
    FUN_08008c94(uVar1, 0x1000);
    return;
}

/* ================================================================
 * display_write_byte_spi  @  0x08001B60
 */

void display_write_byte_spi(int param_1)

{
    do {
    } while (-1 < *DAT_08001b70 << 0x1e);
    DAT_08001b70[1] = param_1;
    return;
}

/* ================================================================
 * FUN_08001e54  @  0x08001E54
 */

void FUN_08001e54(void)

{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;

    uVar1 = DAT_08001ec4;
    uVar4 = 0;
    iVar3 = FUN_0800c54a(DAT_08001ec4, 0x10);
    iVar2 = DAT_08001ec8;
    if (iVar3 == 0) {
        return;
    }
    FUN_080075b0(DAT_08001ec8, 0);
    FUN_0800c4b4(uVar1, 0x10);
    *(uint32_t *)(DAT_08001ec8 + 4) = 0xf;
    FUN_080075b0(iVar2, 1);
    iVar2 = DAT_08001ecc;
    if (*(char *)(DAT_08001ecc + 2) == -3) {
        *(uint8_t *)(DAT_08001ed0 + 8) = 1;
        do {
            *(uint8_t *)(iVar2 + 0xf + uVar4) = *(uint8_t *)(iVar2 + uVar4);
            uVar4 = uVar4 + 1 & 0xff;
        } while (uVar4 < 0xd);
    } else {
        if (*(char *)(DAT_08001ed4 + 0x2a) != '\0') {
            *(char *)(DAT_08001ed4 + 0x2a) = *(char *)(DAT_08001ed4 + 0x2a) + -1;
            return;
        }
        if (*(char *)(DAT_08001ed4 + 0xe) == '\0') {
            *(uint8_t *)(DAT_08001ed0 + 9) = 1;
            return;
        }
    }
    return;
}

/* ================================================================
 * FUN_08001eda  @  0x08001EDA
 */

void FUN_08001eda() { return; }

/* ================================================================
 * sys_uart_putchar_stub  @  0x08001EDC
 */

void sys_uart_putchar_stub() { return; }

/* ================================================================
 * gpio_configure_pin  @  0x08001FE0
 */

void gpio_configure_pin(int param_1, uint32_t param_2, uint32_t param_3, int param_4)

{
    uint32_t uVar1;

    if (param_2 < 10) {
        *(uint32_t *)(param_1 + 0x10) =
            param_4 << (param_2 * 3 & 0xff) |
            *(uint32_t *)(param_1 + 0x10) & ~(7 << (param_2 * 3 & 0xff));
    } else {
        uVar1 = (param_2 - 10) * 3;
        *(uint32_t *)(param_1 + 0xc) =
            param_4 << (uVar1 & 0xff) | *(uint32_t *)(param_1 + 0xc) & ~(7 << (uVar1 & 0xff));
    }
    if (0xc < param_3) {
        uVar1 = (param_3 - 0xd) * 5;
        *(uint32_t *)(param_1 + 0x2c) =
            param_2 << (uVar1 & 0xff) | *(uint32_t *)(param_1 + 0x2c) & ~(0x1f << (uVar1 & 0xff));
        return;
    }
    if (6 < param_3) {
        uVar1 = (param_3 - 7) * 5;
        *(uint32_t *)(param_1 + 0x30) =
            param_2 << (uVar1 & 0xff) | *(uint32_t *)(param_1 + 0x30) & ~(0x1f << (uVar1 & 0xff));
        return;
    }
    uVar1 = (param_3 - 1) * 5;
    *(uint32_t *)(param_1 + 0x34) =
        param_2 << (uVar1 & 0xff) | *(uint32_t *)(param_1 + 0x34) & ~(0x1f << (uVar1 & 0xff));
    return;
}

/* ================================================================
 * sys_handle_rotary_input  @  0x0800209C
 */

void sys_handle_rotary_input(void)

{
    int iVar1;
    uint8_t uVar2;
    int iVar3;
    int iVar4;

    iVar4 = DAT_0800217c;
    iVar1 = DAT_08002178;
    if (*(char *)(DAT_08002178 + 2) == '\x02') {
        iVar3 = sensor_touch_query(0x15);
        if (iVar3 == 1) {
            uVar2 = *(uint8_t *)(iVar4 + 0x24);
            /* goto LAB_08002174; */ (void)0;
        }
    } else {
        switch (*(uint8_t *)(DAT_0800217c + 0x24)) {
        case 0:
            iVar4 = sensor_touch_query(0xc);
            if (iVar4 == 1) {
                uVar2 = 0;
            LAB_08002174:
                *(uint8_t *)(iVar1 + 3) = uVar2;
                return;
            }
            break;
        case 1:
            iVar4 = sensor_touch_query(0xd);
            uVar2 = 1;
            if (iVar4 == 1)
                /* goto LAB_08002174; */ (void)0;
            break;
        case 2:
            iVar4 = sensor_touch_query(0xb);
            if (iVar4 == 1) {
                uVar2 = 2;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 3:
            iVar4 = sensor_touch_query(0x14);
            if (iVar4 == 1) {
                uVar2 = 3;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 4:
            iVar4 = sensor_touch_query(0xe);
            if (iVar4 == 1) {
                uVar2 = 4;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 5:
            iVar4 = sensor_touch_query(10);
            if (iVar4 == 1) {
                uVar2 = 5;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 6:
            iVar4 = sensor_touch_query(0xf);
            if (iVar4 == 1) {
                uVar2 = 6;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 7:
            iVar4 = sensor_touch_query(0x12);
            if (iVar4 == 1) {
                uVar2 = 7;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 8:
            iVar4 = sensor_touch_query(0x13);
            if (iVar4 == 1) {
                uVar2 = 8;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 9:
            iVar4 = sensor_touch_query(9);
            if (iVar4 == 1) {
                uVar2 = 9;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 10:
            iVar4 = sensor_touch_query(0x10);
            if (iVar4 == 1) {
                uVar2 = 10;
                /* goto LAB_08002174; */ (void)0;
            }
            break;
        case 0xb:
            iVar4 = sensor_touch_query(0x11);
            if (iVar4 == 1) {
                uVar2 = 0xb;
                /* goto LAB_08002174; */ (void)0;
            }
        }
    }
    return;
}

/* ================================================================
 * FUN_08002180  @  0x08002180
 */

int FUN_08002180(int param_1, int param_2)

{
    uint32_t uVar1;
    int iVar2;

    iVar2 = 0;
    uVar1 = param_2 + 3U & 0xfffffffc;
    if (uVar1 <= *(uint32_t *)(param_1 + 0x70)) {
        *(uint32_t *)(param_1 + 0x70) = *(uint32_t *)(param_1 + 0x70) - uVar1;
        iVar2 = *(int *)(param_1 + 0x6c);
        *(uint32_t *)(param_1 + 0x6c) = uVar1 + iVar2;
    }
    return iVar2;
}

/* ================================================================
 * FUN_0800219c  @  0x0800219C
 */

int FUN_0800219c(int *param_1, int param_2)

{
    bool bVar1;
    int iVar2;
    uint32_t uVar3;
    byte *pbVar4;
    uint32_t uVar5;
    int iVar6;

    uVar5 = (uint32_t)*(byte *)(param_1 + 3);
    iVar2 = *param_1;
    pbVar4 = (byte *)param_1[1];
    uVar3 = (uint32_t)*pbVar4;
    iVar6 = 0;
    bVar1 = false;
    do {
        if (uVar5 == 0) {
            if (iVar2 == 0) {
                pbVar4 = (byte *)param_1[2];
                iVar2 = (*(code *)param_1[0x1d])(param_1, pbVar4, 0x200);
                if (iVar2 == 0) {
                    return -2;
                }
            } else {
                pbVar4 = pbVar4 + 1;
            }
            iVar2 = iVar2 + -1;
            if (bVar1) {
                bVar1 = false;
                if (*pbVar4 != 0) {
                    return -6;
                }
                uVar3 = 0xff;
                *pbVar4 = 0xff;
            LAB_080021f0:
                uVar5 = 0x80;
                /* goto LAB_080021f2; */ (void)0;
            }
            uVar3 = (uint32_t)*pbVar4;
            if (uVar3 != 0xff)
                /* goto LAB_080021f0; */ (void)0;
            bVar1 = true;
        } else {
        LAB_080021f2:
            iVar6 = iVar6 * 2;
            if ((uVar3 & uVar5) != 0) {
                iVar6 = iVar6 + 1;
            }
            uVar5 = uVar5 >> 1;
            param_2 = param_2 + -1;
        }
        if (param_2 == 0) {
            *(char *)(param_1 + 3) = (char)uVar5;
            *param_1 = iVar2;
            param_1[1] = (int)pbVar4;
            return iVar6;
        }
    } while (true);
}

/* ================================================================
 * FUN_08002218  @  0x08002218
 */

void FUN_08002218(int *param_1, uint8_t *param_2)

{
    int *piVar1;
    uint8_t *puVar2;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    int iVar11;
    int iVar12;
    int iVar13;
    int iVar14;

    uVar3 = 0;
    do {
        piVar1 = param_1;
        iVar9 = piVar1[0x20];
        iVar6 = *piVar1 + iVar9;
        iVar9 = *piVar1 - iVar9;
        iVar4 = piVar1[0x30] + piVar1[0x10];
        iVar10 = ((piVar1[0x10] - piVar1[0x30]) * 0x16a0 >> 0xc) - iVar4;
        iVar5 = iVar6 + iVar4;
        iVar6 = iVar6 - iVar4;
        iVar12 = iVar10 + iVar9;
        iVar9 = iVar9 - iVar10;
        iVar10 = piVar1[8] - piVar1[0x38];
        iVar13 = piVar1[8] + piVar1[0x38];
        iVar4 = piVar1[0x28] - piVar1[0x18];
        iVar7 = piVar1[0x28] + piVar1[0x18];
        iVar8 = iVar7 + iVar13;
        iVar11 = (iVar10 + iVar4) * 0x1d90 >> 0xc;
        iVar4 = (iVar11 - (iVar4 * 0x29cf >> 0xc)) - iVar8;
        *piVar1 = iVar5 + iVar8;
        iVar7 = ((iVar13 - iVar7) * 0x16a0 >> 0xc) - iVar4;
        piVar1[0x38] = iVar5 - iVar8;
        piVar1[8] = iVar12 + iVar4;
        piVar1[0x30] = iVar12 - iVar4;
        piVar1[0x10] = iVar9 + iVar7;
        iVar4 = (iVar11 - (iVar10 * 0x1151 >> 0xc)) - iVar7;
        piVar1[0x28] = iVar9 - iVar7;
        piVar1[0x18] = iVar6 + iVar4;
        uVar3 = uVar3 + 1;
        piVar1[0x20] = iVar6 - iVar4;
        iVar4 = DAT_080023fc;
        param_1 = piVar1 + 1;
    } while (uVar3 < 8);
    uVar3 = 0;
    piVar1 = piVar1 + -7;
    do {
        iVar11 = *piVar1 + 0x8000 + piVar1[4];
        iVar5 = (*piVar1 + 0x8000) - piVar1[4];
        iVar9 = piVar1[6] + piVar1[2];
        iVar10 = ((piVar1[2] - piVar1[6]) * 0x16a0 >> 0xc) - iVar9;
        iVar13 = iVar10 + iVar5;
        iVar5 = iVar5 - iVar10;
        iVar8 = iVar11 + iVar9;
        iVar11 = iVar11 - iVar9;
        iVar6 = piVar1[1] - piVar1[7];
        iVar14 = piVar1[1] + piVar1[7];
        iVar7 = piVar1[5] - piVar1[3];
        iVar9 = piVar1[5] + piVar1[3];
        iVar10 = iVar9 + iVar14;
        iVar12 = (iVar6 + iVar7) * 0x1d90 >> 0xc;
        iVar7 = (iVar12 - (iVar7 * 0x29cf >> 0xc)) - iVar10;
        iVar9 = ((iVar14 - iVar9) * 0x16a0 >> 0xc) - iVar7;
        iVar6 = (iVar12 - (iVar6 * 0x1151 >> 0xc)) - iVar9;
        *param_2 = *(uint8_t *)(iVar4 + ((iVar8 + iVar10 & 0x3ffffU) >> 8));
        param_2[7] = *(uint8_t *)(iVar4 + ((iVar8 - iVar10 & 0x3ffffU) >> 8));
        param_2[1] = *(uint8_t *)(iVar4 + ((iVar13 + iVar7 & 0x3ffffU) >> 8));
        param_2[6] = *(uint8_t *)(iVar4 + ((iVar13 - iVar7 & 0x3ffffU) >> 8));
        puVar2 = param_2 + 4;
        param_2[2] = *(uint8_t *)(iVar4 + ((iVar5 + iVar9 & 0x3ffffU) >> 8));
        param_2[5] = *(uint8_t *)(iVar4 + ((iVar5 - iVar9 & 0x3ffffU) >> 8));
        param_2[3] = *(uint8_t *)(iVar4 + ((iVar11 + iVar6 & 0x3ffffU) >> 8));
        uVar3 = uVar3 + 1;
        param_2 = param_2 + 8;
        *puVar2 = *(uint8_t *)(iVar4 + ((iVar11 - iVar6 & 0x3ffffU) >> 8));
        piVar1 = piVar1 + 8;
    } while (uVar3 < 8);
    return;
}

/* ================================================================
 * FUN_08002400  @  0x08002400
 */

uint32_t FUN_08002400(short *param_1, short *param_2, uint32_t param_3)

{
    bool bVar1;

    while (true) {
        bVar1 = param_3 == 0;
        param_3 = param_3 - 1 & 0xffff;
        if (bVar1) {
            return 1;
        }
        if (*param_1 != *param_2)
            break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
    }
    return 0;
}

/* ================================================================
 * FUN_08002420  @  0x08002420
 */

void FUN_08002420(void)

{
    uint32_t uVar1;
    byte bVar2;

    uVar1 = DAT_0800244c;
    bVar2 = 0;
    do {
        gpio_write(uVar1, 1);
        sys_delay_ms(0x96);
        gpio_write(uVar1, 0);
        sys_delay_ms(0x96);
        bVar2 = bVar2 + 1;
    } while (bVar2 < 3);
    return;
}

/* ================================================================
 * fs_fat32_mount_notify  @  0x08002450
 * nearby string: "FAT32   "
 */

void fs_fat32_mount_notify() {
    *(uint8_t *)(DAT_08002460 + 0xf) = 1;
    gpio_write(DAT_08002464, 1);
    return;
}

/* ================================================================
 * fs_fat32_init  @  0x08002468
 * nearby string: "FAT32   "
 */

uint64_t fs_fat32_init(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    uint32_t uVar2;
    uint8_t local_30;
    uint8_t local_2f;
    uint8_t local_2e;
    uint8_t local_2d;
    uint8_t local_2c;
    uint8_t local_2b;
    uint8_t local_2a;
    uint8_t uStack_29;
    uint32_t local_28;
    uint32_t local_24;

    uVar1 = DAT_08002524;
    local_2c = (uint8_t)param_2;
    local_2b = (uint8_t)((uint32_t)param_2 >> 8);
    local_2a = (uint8_t)((uint32_t)param_2 >> 0x10);
    uStack_29 = (uint8_t)((uint32_t)param_2 >> 0x18);
    local_30 = (uint8_t)param_1;
    local_2f = (uint8_t)((uint32_t)param_1 >> 8);
    local_2e = (uint8_t)((uint32_t)param_1 >> 0x10);
    local_2d = (uint8_t)((uint32_t)param_1 >> 0x18);
    local_28 = param_3;
    local_24 = param_4;
    gpio_write(DAT_08002524, 1);
    gpio_write(DAT_08002528, 1);
    FUN_08008c98(&local_28);
    local_28 = 0x100;
    local_24 = 0x1080400;
    FUN_08008cb0(DAT_0800252c, &local_28);
    uVar2 = DAT_08002530;
    FUN_0800c18c(DAT_08002530, param_1, param_2);
    FUN_0800c1b8(uVar2, 0);
    FUN_0800c2f8(&local_30);
    local_30 = 7;
    local_2b = 1;
    local_2d = 1;
    local_2f = 1;
    local_2a = 1;
    local_2c = 0;
    local_2e = 0;
    FUN_0800c22e(uVar2, 4, &local_30);
    FUN_0800c19a(uVar2, 4, param_3);
    FUN_0800c1fc(uVar2, 4, 1);
    FUN_0800c314(uVar2, 1);
    FUN_0800c1c2(uVar2, 1);
    gpio_write(uVar1, 0);
    return CONCAT17(
        uStack_29,
        CONCAT16(local_2a,
                 CONCAT15(local_2b,
                          CONCAT14(local_2c,
                                   CONCAT13(local_2d,
                                            CONCAT12(local_2e, CONCAT11(local_2f, local_30)))))));
}

/* ================================================================
 * fs_fat32_time_update  @  0x08002534
 * nearby string: "FAT32   "
 */

uint32_t fs_fat32_time_update() {
    uint64_t uVar1;

    uVar1 = FUN_0800e548();
    uVar1 = FUN_0800e0f4((int)uVar1, (int)((uint64_t)uVar1 >> 0x20), DAT_08002554, DAT_08002558);
    FUN_0800dba4((int)uVar1, (int)((uint64_t)uVar1 >> 0x20), 0, DAT_0800255c);
    FUN_0800db40();
    return;
}

/* ================================================================
 * fs_fat32_validate_bpb  @  0x08002560
 * nearby string: "FAT32   "
 */

uint32_t fs_fat32_validate_bpb() {
    int param_1 = 0;
    char cVar1;
    byte bVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;

    *(uint8_t *)(param_1 + 3) = 0;
    *(uint32_t *)(param_1 + 0x2c) = 0xffffffff;
    iVar3 = FUN_0800a91c(param_1);
    if (iVar3 != 0) {
        return 4;
    }
    iVar3 = FUN_08009604(param_1 + 0x22e);
    cVar1 = *(char *)(param_1 + 0x30);
    if (((cVar1 == -0x15) || (cVar1 == -0x17)) || (cVar1 == -0x18)) {
        if ((iVar3 == 0xaa55) &&
            (iVar4 = FUN_08000506(param_1 + 0x82, s_FAT32_08002624, 8), iVar4 == 0)) {
            return 0;
        }
        uVar5 = FUN_08009604(param_1 + 0x3b);
        bVar2 = *(byte *)(param_1 + 0x3d);
        if ((((((uVar5 & uVar5 - 1) == 0) && (0xfff < uVar5)) &&
              ((uVar5 < 0x1001 && ((((bVar2 != 0 && ((bVar2 & bVar2 - 1) == 0)) &&
                                     (iVar4 = FUN_08009604(param_1 + 0x3e), iVar4 != 0)) &&
                                    ((*(byte *)(param_1 + 0x40) - 1 < 2 &&
                                      (iVar4 = FUN_08009604(param_1 + 0x41), iVar4 != 0)))))))) &&
             ((uVar5 = FUN_08009604(param_1 + 0x43),
               0x7f < uVar5 || (uVar5 = FUN_080095ee(param_1 + 0x50), 0xffff < uVar5)))) &&
            (iVar4 = FUN_08009604(param_1 + 0x46), iVar4 != 0)) {
            return 0;
        }
    }
    if (iVar3 != 0xaa55) {
        return 3;
    }
    return 2;
}

/* ================================================================
 * FUN_08002630  @  0x08002630
 */

int FUN_08002630() {
    int *param_1 = 0;
    uint32_t param_2 = 0;
    int *piVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    piVar1 = (int *)param_1[10];
    uVar2 = (param_2 >> 0xc) / (uint32_t)*(uint16_t *)(*param_1 + 10);
    while (true) {
        uVar3 = piVar1[1];
        piVar1 = piVar1 + 2;
        if (uVar3 == 0) {
            return 0;
        }
        if (uVar2 < uVar3)
            break;
        uVar2 = uVar2 - uVar3;
    }
    return *piVar1 + uVar2;
}

/* ================================================================
 * FUN_08002654  @  0x08002654
 */

int FUN_08002654() {
    int param_1 = 0;
    int param_2 = 0;
    if (*(int *)(param_1 + 0x14) - 2U <= param_2 - 2U) {
        return 0;
    }
    return (uint32_t)*(uint16_t *)(param_1 + 10) * (param_2 - 2U) + *(int *)(param_1 + 0x28);
}

/* ================================================================
 * FUN_0800266c  @  0x0800266C
 */

void FUN_0800266c(byte *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    int iVar2;
    uint32_t local_18[3];

    iVar2 = 0;
    local_18[0] = param_2;
    local_18[1] = param_3;
    local_18[2] = param_4;
    while (true) {
        uVar1 = (uint32_t)*param_1;
        if (uVar1 == 0)
            break;
        if (((uVar1 - 0x30 < 10) || (uVar1 == 0x2e)) || (uVar1 == 0x2d)) {
            *(byte *)((int)local_18 + iVar2) = *param_1;
            iVar2 = iVar2 + 1;
        }
        param_1 = param_1 + 1;
    }
    *(uint8_t *)((int)local_18 + iVar2) = 0;
    FUN_0800269c(local_18);
    return;
}

/* ================================================================
 * FUN_0800269c  @  0x0800269C
 */

void FUN_0800269c(char *param_1)

{
    bool bVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    uint32_t uVar9;

    iVar8 = 0;
    uVar9 = 1;
    iVar7 = 0;
    bVar1 = false;
    iVar6 = 1;
    iVar4 = 0;
    if (*param_1 == '-') {
        uVar9 = 0xffffffff;
    } else if (*param_1 != '+')
        /* goto LAB_080026dc; */ (void)0;
    param_1 = param_1 + 1;
LAB_080026dc:
    for (; uVar5 = (uint32_t)(byte)param_1[iVar4], uVar5 != 0; iVar4 = iVar4 + 1) {
        if (uVar5 == 0x2e) {
            bVar1 = true;
        } else if (bVar1) {
            iVar7 = iVar7 * 10 + -0x30 + uVar5;
            iVar6 = iVar6 * 10;
        } else {
            iVar8 = iVar8 * 10 + -0x30 + uVar5;
        }
    }
    uVar2 = FUN_0800e86c(iVar6);
    uVar3 = FUN_0800e86c(iVar7);
    uVar2 = FUN_0800e670(uVar3, uVar2);
    uVar3 = FUN_0800e86c(iVar8);
    uVar2 = FUN_0800e5a0(uVar3, uVar2);
    uVar9 = FUN_0800e86c(uVar9);
    FUN_0800e8c4(uVar9, uVar2);
    return;
}

/* ================================================================
 * FUN_08002726  @  0x08002726
 */

uint32_t FUN_08002726() {
    int *param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t uVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    int iVar5;

    iVar5 = *param_1;
    if (param_2 == 0) {
        uVar3 = *(uint32_t *)(iVar5 + 0xc);
        if ((uVar3 == 0) || (*(uint32_t *)(iVar5 + 0x14) <= uVar3)) {
            uVar3 = 1;
        }
    } else {
        uVar1 = FUN_08008ae4();
        if (uVar1 < 2) {
            return 1;
        }
        if (uVar1 == 0xffffffff) {
            return 0xffffffff;
        }
        uVar3 = param_2;
        if (uVar1 < *(uint32_t *)(iVar5 + 0x14)) {
            return uVar1;
        }
    }
    if (*(int *)(iVar5 + 0x10) != 0) {
        uVar1 = uVar3;
        if (uVar3 == param_2) {
            uVar4 = uVar3 + 1;
            if (*(uint32_t *)(iVar5 + 0x14) <= uVar4) {
                uVar4 = 2;
            }
            iVar2 = FUN_08008ae4(param_1, uVar4);
            if (iVar2 == 1) {
                return 1;
            }
            if (iVar2 == -1) {
                return 0xffffffff;
            }
            if (iVar2 == 0) {
                if (uVar4 != 0) {
                LAB_080027bc:
                    iVar2 = FUN_0800b078(iVar5, uVar4, 0xffffffff);
                    if ((iVar2 == 0) &&
                        ((param_2 == 0 ||
                          (iVar2 = FUN_0800b078(iVar5, param_2, uVar4), iVar2 == 0)))) {
                        *(uint32_t *)(iVar5 + 0xc) = uVar4;
                        if (*(uint32_t *)(iVar5 + 0x10) <= *(int *)(iVar5 + 0x14) - 2U) {
                            *(uint32_t *)(iVar5 + 0x10) = *(uint32_t *)(iVar5 + 0x10) - 1;
                        }
                        *(byte *)(iVar5 + 4) = *(byte *)(iVar5 + 4) | 1;
                        return uVar4;
                    }
                    if (iVar2 == 1) {
                        return 0xffffffff;
                    }
                    return 1;
                }
            } else {
                uVar4 = *(uint32_t *)(iVar5 + 0xc);
                if ((1 < uVar4) && (uVar4 < *(uint32_t *)(iVar5 + 0x14))) {
                    uVar3 = uVar4;
                    uVar1 = uVar4;
                }
            }
        }
        do {
            uVar4 = uVar3 + 1;
            if ((*(uint32_t *)(iVar5 + 0x14) <= uVar4) && (uVar4 = 2, uVar1 < 2)) {
                return 0;
            }
            iVar2 = FUN_08008ae4(param_1, uVar4);
            if (iVar2 == 0)
                /* goto LAB_080027bc; */ (void)0;
            if (iVar2 == 1) {
                return 1;
            }
            if (iVar2 == -1) {
                return 0xffffffff;
            }
            uVar3 = uVar4;
        } while (uVar4 != uVar1);
    }
    return 0;
}

/* ================================================================
 * FUN_08002800  @  0x08002800
 */

uint64_t FUN_08002800(int param_1, byte *param_2, uint32_t param_3)

{
    byte bVar1;
    byte bVar2;
    int iVar3;
    uint32_t uVar4;
    int iVar5;
    byte *pbVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    int iVar9;
    uint32_t uVar10;
    int iVar11;
    uint32_t uVar12;
    bool bVar13;

    do {
        if (param_3 == 0) {
            uVar7 = 0;
        LAB_080028a6:
            return CONCAT44(param_1, uVar7);
        }
        if (param_3 < 0x11) {
        LAB_080028b6:
            uVar7 = 6;
            /* goto LAB_080028a6; */ (void)0;
        }
        bVar1 = *param_2;
        if ((bVar1 & 0xee) != 0)
            /* goto LAB_080028b6; */ (void)0;
        iVar3 = FUN_08002180(param_1, 0x10);
        if (iVar3 == 0) {
        LAB_080028a4:
            uVar7 = 3;
            /* goto LAB_080028a6; */ (void)0;
        }
        iVar11 = param_1 + (bVar1 & 0xf) * 8 + (uint32_t)(bVar1 >> 4) * 4;
        uVar4 = 0;
        uVar10 = 0;
        *(int *)(iVar11 + 0x24) = iVar3;
        pbVar6 = param_2 + 1;
        do {
            param_2 = pbVar6 + 1;
            bVar2 = *pbVar6;
            *(byte *)(iVar3 + uVar4) = bVar2;
            uVar4 = uVar4 + 1;
            uVar10 = uVar10 + bVar2;
            pbVar6 = param_2;
        } while (uVar4 < 0x10);
        iVar5 = FUN_08002180(param_1, uVar10 * 2);
        if (iVar5 == 0)
            /* goto LAB_080028a4; */ (void)0;
        uVar4 = 0;
        uVar8 = 0;
        iVar9 = 0;
        *(int *)(iVar11 + 0x34) = iVar5;
        do {
            uVar12 = (uint32_t)*(byte *)(iVar3 + uVar8);
            while (bVar13 = uVar12 != 0, uVar12 = uVar12 - 1, bVar13) {
                *(short *)(iVar5 + iVar9 * 2) = (short)uVar4;
                uVar4 = uVar4 + 1 & 0xffff;
                iVar9 = iVar9 + 1;
            }
            uVar8 = uVar8 + 1;
            uVar4 = (uVar4 & 0x7fff) << 1;
        } while (uVar8 < 0x10);
        if (param_3 - 0x11 < uVar10)
            /* goto LAB_080028b6; */ (void)0;
        param_3 = (param_3 - 0x11) - uVar10;
        pbVar6 = (byte *)FUN_08002180(param_1, uVar10);
        if (pbVar6 == (byte *)0x0)
            /* goto LAB_080028a4; */ (void)0;
        *(byte **)(iVar11 + 0x44) = pbVar6;
        for (uVar4 = 0; uVar4 < uVar10; uVar4 = uVar4 + 1) {
            if ((bVar1 >> 4 == 0) && (0xb < *param_2))
                /* goto LAB_080028b6; */ (void)0;
            *pbVar6 = *param_2;
            pbVar6 = pbVar6 + 1;
            param_2 = param_2 + 1;
        }
    } while (true);
}

/* ================================================================
 * FUN_080028cc  @  0x080028CC
 */

uint32_t FUN_080028cc(int param_1, int *param_2)

{
    char cVar1;
    uint8_t uVar2;
    char *pcVar3;
    uint32_t uVar4;
    int iVar5;
    int iVar6;
    uint32_t uVar7;
    byte bVar8;
    uint32_t uVar9;
    int iVar10;
    int iVar11;
    uint32_t uVar12;

    pcVar3 = (char *)(param_1 + 0x20);
    iVar11 = *param_2;
    FUN_08000694(pcVar3, 0xb, 0x20);
    uVar12 = 0;
    uVar4 = 8;
    iVar6 = 0;
    while (true) {
        bVar8 = *(byte *)(iVar11 + iVar6);
        uVar9 = (uint32_t)bVar8;
        iVar10 = iVar6 + 1;
        if (uVar9 < 0x21)
            break;
        if ((uVar9 == 0x2f) || (uVar9 == 0x5c))
            /* goto LAB_0800290e; */ (void)0;
        if ((uVar9 == 0x2e) || (uVar4 <= uVar12)) {
            if ((uVar4 == 0xb) || (uVar9 != 0x2e))
                /* goto LAB_0800296e; */ (void)0;
            uVar12 = 8;
            uVar4 = 0xb;
            iVar6 = iVar10;
        } else {
            iVar5 = FUN_08002cb0(uVar9);
            if (iVar5 == 0) {
                iVar6 = FUN_080004f2(&LAB_080029a8, uVar9);
                if (iVar6 != 0)
                    /* goto LAB_0800296e; */ (void)0;
                if (uVar9 - 0x61 < 0x1a) {
                    bVar8 = bVar8 - 0x20;
                }
                pcVar3[uVar12] = bVar8;
                uVar12 = uVar12 + 1;
                iVar6 = iVar10;
            } else {
                cVar1 = *(char *)(iVar11 + iVar10);
                iVar10 = FUN_08002cc6(cVar1);
                if ((iVar10 == 0) || (uVar4 - 1 <= uVar12))
                    /* goto LAB_0800296e; */ (void)0;
                pcVar3[uVar12] = bVar8;
                pcVar3[uVar12 + 1] = cVar1;
                uVar12 = uVar12 + 2;
                iVar6 = iVar6 + 2;
            }
        }
    }
LAB_08002918:
    *param_2 = iVar11 + iVar10;
    if (uVar12 == 0) {
    LAB_0800296e:
        uVar7 = 6;
    } else {
        if (*pcVar3 == -0x1b) {
            *pcVar3 = '\x05';
        }
        if ((uVar9 < 0x21) || (*(byte *)(iVar11 + iVar10) < 0x21)) {
            uVar2 = 4;
        } else {
            uVar2 = 0;
        }
        *(uint8_t *)(param_1 + 0x2b) = uVar2;
        uVar7 = 0;
    }
    return uVar7;
LAB_0800290e:
    for (; (*(char *)(iVar11 + iVar10) == '/' || (*(char *)(iVar11 + iVar10) == '\\'));
         iVar10 = iVar10 + 1) {
    }
    /* goto LAB_08002918; */ (void)0;
}

/* ================================================================
 * FUN_080029d4  @  0x080029D4
 */

void FUN_080029d4(uint32_t param_1)

{
    *(uint32_t *)(DAT_080029e0 + 4) = *(uint32_t *)(DAT_080029e0 + 4) & 0xffffff0f | (param_1 & 0xf)
                                                                                         << 4;
    return;
}

/* ================================================================
 * FUN_080029e4  @  0x080029E4
 */

void FUN_080029e4(uint32_t param_1)

{
    *(uint32_t *)(DAT_080029f0 + 4) = *(uint32_t *)(DAT_080029f0 + 4) & 0xfffff8ff | (param_1 & 7)
                                                                                         << 8;
    return;
}

/* ================================================================
 * FUN_080029f4  @  0x080029F4
 */

void FUN_080029f4(uint32_t param_1)

{
    *(uint32_t *)(DAT_08002a00 + 4) = *(uint32_t *)(DAT_08002a00 + 4) & 0xffffc7ff | (param_1 & 7)
                                                                                         << 0xb;
    return;
}

/* ================================================================
 * FUN_08002a04  @  0x08002A04
 */

void FUN_08002a04(int param_1)

{
    uint32_t uVar1;

    if (param_1 == 1) {
        uVar1 = *(uint32_t *)(DAT_08002a1c + 0x54) | 0x30;
    } else {
        uVar1 = *(uint32_t *)(DAT_08002a1c + 0x54) & 0xffffffcf;
    }
    *(uint32_t *)(DAT_08002a1c + 0x54) = uVar1;
    return;
}

/* ================================================================
 * FUN_08002a20  @  0x08002A20
 */

void FUN_08002a20() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t uVar1;

    switch (param_1) {
    case 0:
        uVar1 = *DAT_08002a60 & 0xfffffffe | param_2 & 1;
        break;
    case 1:
        uVar1 = *DAT_08002a60 & 0xfffeffff | (param_2 & 1) << 0x10;
        break;
    case 2:
        uVar1 = *DAT_08002a60 & 0xfeffffff | (param_2 & 1) << 0x18;
        break;
    case 3:
        DAT_08002a60[8] = DAT_08002a60[8] & 0xfffffffe | param_2 & 1;
        return;
    case 4:
        DAT_08002a60[9] = DAT_08002a60[9] & 0xfffffffe | param_2 & 1;
        return;
    default:
        goto switchD_08002a26_default;
    }
    *DAT_08002a60 = uVar1;
switchD_08002a26_default:
    return;
}

/* ================================================================
 * FUN_08002a64  @  0x08002A64
 */

void FUN_08002a64(uint32_t *param_1)

{
    int64_t lVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t uVar6;

    iVar3 = FUN_08002ca0();
    iVar2 = DAT_08002b4c;
    uVar4 = DAT_08002b48;
    if (iVar3 == 0) {
        if ((*(int *)(DAT_08002b4c + 0x54) << 0x16 < 0) &&
            (*(int *)(DAT_08002b4c + 0x30) << 6 < 0)) {
            uVar4 = DAT_08002b50;
        }
    } else if ((iVar3 != 1) && (iVar3 == 2)) {
        iVar3 = *(int *)(DAT_08002b4c + 4) << 0xf;
        if (*(int *)(DAT_08002b4c + 0x2c) < 0) {
            if ((-1 < iVar3) || (*(int *)(DAT_08002b4c + 4) << 0xe < 0)) {
                uVar4 = DAT_08002b54;
            }
            lVar1 =
                (uint64_t)uVar4 * (uint64_t)((*(uint32_t *)(DAT_08002b4c + 0x2c) & 0x1ffff) >> 8);
            uVar4 = FUN_0800030a((int)lVar1, (int)((uint64_t)lVar1 >> 0x20),
                                 ((*(uint32_t *)(DAT_08002b4c + 0x2c) & 0xff) >> 4)
                                     << (*(uint32_t *)(DAT_08002b4c + 0x2c) & 7),
                                 0);
        } else {
            uVar4 = (*(uint32_t *)(DAT_08002b4c + 4) & 0x3fffff) >> 0x12;
            uVar6 = (*(uint32_t *)(DAT_08002b4c + 4) & 0x7fffffff) >> 0x1d;
            if ((uVar6 == 0) && (uVar4 != 0xf)) {
                iVar5 = uVar4 + 2;
            } else {
                iVar5 = uVar4 + uVar6 * 0x10 + 1;
            }
            if ((-1 < iVar3) || (uVar4 = DAT_08002b48, *(int *)(DAT_08002b4c + 4) << 0xe < 0)) {
                uVar4 = DAT_08002b54;
            }
            uVar4 = uVar4 * iVar5;
        }
    }
    *param_1 = uVar4;
    uVar4 = *param_1 >> *(sbyte *)(DAT_08002b58 + ((*(uint32_t *)(iVar2 + 4) & 0xff) >> 4));
    param_1[1] = uVar4;
    iVar3 = DAT_08002b58;
    param_1[3] =
        uVar4 >> *(sbyte *)(DAT_08002b58 + -0x18 + ((*(uint32_t *)(iVar2 + 4) & 0x7ff) >> 8));
    uVar4 = uVar4 >> *(sbyte *)(iVar3 + -0x10 + ((*(uint32_t *)(iVar2 + 4) & 0x3fff) >> 0xb));
    param_1[2] = uVar4;
    param_1[4] = uVar4 / *(byte *)(DAT_08002b58 + -8 +
                                   ((*(uint32_t *)(iVar2 + 4) & 0xffff) >> 0xe |
                                    ((*(uint32_t *)(iVar2 + 4) & 0x1fffffff) >> 0x1c) << 2));
    return;
}

/* ================================================================
 * FUN_08002b5c  @  0x08002B5C
 */

bool FUN_08002b5c(uint32_t param_1)

{
    return (1 << (param_1 & 0x1f) & ~*(uint32_t *)(DAT_08002b78 + (param_1 >> 0x10))) == 0;
}

/* ================================================================
 * FUN_08002b7c  @  0x08002B7C
 */

bool FUN_08002b7c(void)

{
    int iVar1;
    uint32_t uVar2;

    for (uVar2 = 0; (iVar1 = FUN_08002b5c(0x11), iVar1 != 1 && (uVar2 < 0x3000));
         uVar2 = uVar2 + 1) {
    }
    iVar1 = FUN_08002b5c(0x11);
    return iVar1 == 1;
}

/* ================================================================
 * gpio_write  @  0x08002BA4
 */

void gpio_write(uint32_t param_1, int param_2)

{
    uint32_t *puVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    uVar3 = 1 << (param_1 & 0x1f);
    puVar1 = (uint32_t *)(DAT_08002bc4 + (param_1 >> 0x10));
    uVar2 = *puVar1;
    if (param_2 == 1) {
        uVar2 = uVar2 | uVar3;
    } else {
        uVar2 = uVar2 & ~uVar3;
    }
    *puVar1 = uVar2;
    return;
}

/* ================================================================
 * FUN_08002bc8  @  0x08002BC8
 */

void FUN_08002bc8(int param_1, uint32_t param_2)

{
    int iVar1;
    int iVar2;

    iVar1 = DAT_08002c1c;
    iVar2 = 0;
    if (param_1 == 0) {
        *(uint32_t *)(DAT_08002c1c + 4) = *(uint32_t *)(DAT_08002c1c + 4) & 0xfffeffff;
        *(uint32_t *)(iVar1 + 0x30) = *(uint32_t *)(iVar1 + 0x30) | 0x2000000;
    } else {
        *(uint32_t *)(DAT_08002c1c + 4) = *(uint32_t *)(DAT_08002c1c + 4) | 0x10000;
        if (param_1 == 1) {
            *(uint32_t *)(iVar1 + 4) = *(uint32_t *)(iVar1 + 4) & 0xfffdffff;
            iVar2 = 2;
        } else {
            *(uint32_t *)(iVar1 + 4) = *(uint32_t *)(iVar1 + 4) | 0x20000;
        }
    }
    *(uint32_t *)(iVar1 + 4) = *(uint32_t *)(iVar1 + 4) & 0xffc3ffff | (param_2 & 0xf) << 0x12;
    *(uint32_t *)(iVar1 + 4) = *(uint32_t *)(iVar1 + 4) & 0x9fffffff | (param_2 >> 4 & 3) << 0x1d;
    *(uint32_t *)(iVar1 + 0x2c) = *(uint32_t *)(iVar1 + 0x2c) & 0xf8ffffff | iVar2 << 0x18;
    return;
}

/* ================================================================
 * FUN_08002c20  @  0x08002C20
 */

void FUN_08002c20(void)

{
    uint32_t *puVar1;

    puVar1 = DAT_08002c60;
    *DAT_08002c60 = *DAT_08002c60 | 1;
    do {
    } while (-1 < (int)(*puVar1 << 0x1e));
    puVar1[1] = puVar1[1] & 0xfffffffc;
    do {
    } while ((puVar1[1] & 0xc) != 0);
    *puVar1 = *puVar1 & DAT_08002c64;
    puVar1[1] = 0;
    puVar1[0xb] = 0x1f10;
    puVar1[0xc] = 0x100000;
    puVar1[2] = 0x9f0000;
    return;
}

/* ================================================================
 * FUN_08002c68  @  0x08002C68
 */

void FUN_08002c68(uint32_t param_1)

{
    *(uint32_t *)(DAT_08002c9c + 4) = *(uint32_t *)(DAT_08002c9c + 4) & 0xfffffffc | param_1 & 3;
    return;
}

/* ================================================================
 * FUN_08002ca0  @  0x08002CA0
 */

uint32_t FUN_08002ca0(void)

{
    return (*(uint32_t *)(DAT_08002cac + 4) & 0xf) >> 2;
}

/* ================================================================
 * FUN_08002cb0  @  0x08002CB0
 */

uint32_t FUN_08002cb0(uint32_t param_1)

{
    if ((0x80 < param_1) && ((param_1 < 0xa0 || (param_1 - 0xe0 < 0x1d)))) {
        return 1;
    }
    return 0;
}

/* ================================================================
 * FUN_08002cc6  @  0x08002CC6
 */

uint32_t FUN_08002cc6(uint32_t param_1)

{
    if ((0x3f < param_1) && ((param_1 < 0x7f || (param_1 - 0x80 < 0x7d)))) {
        return 1;
    }
    return 0;
}

/* ================================================================
 * sys_delay_cycles  @  0x08002CDC
 */

void sys_delay_cycles(int param_1)

{
    bool bVar1;
    uint32_t local_8;

    local_8 = param_1;
    do {
        bVar1 = local_8 != 0;
        local_8 = local_8 + -1;
    } while (bVar1);
    return;
}

/* ================================================================
 * sys_clock_init  @  0x08002CE8
 */

void sys_clock_init(void)

{
    uint32_t *puVar1;

    FUN_0800c108(4);
    puVar1 = DAT_08002d14;
    *DAT_08002d14 = *DAT_08002d0c / DAT_08002d10;
    puVar1[1] = *puVar1 * 1000;
    return;
}

/* ================================================================
 * sys_delay_ms  @  0x08002D18
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sys_delay_ms(uint32_t param_1)

{
    while (param_1 != 0) {
        if (param_1 < 0x33) {
            _DAT_e000e014 = *(int *)(DAT_08002d60 + 4) * param_1;
            param_1 = 0;
        } else {
            _DAT_e000e014 = *(int *)(DAT_08002d60 + 4) * 0x32;
            param_1 = param_1 - 0x32 & 0xffff;
        }
        do {
        } while (-1 < (int)((_DAT_e000e010 | 1) << 0xf));
        _DAT_e000e010 = _DAT_e000e010 & 0xfffffffe;
        _DAT_e000e018 = 0;
    }
    return;
}

/* ================================================================
 * FUN_08002d64  @  0x08002D64
 */

int FUN_08002d64(uint32_t *param_1, int param_2)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    uVar3 = *param_1;
    iVar1 = fs_fat32_seek_cluster(param_1, 0);
    if (iVar1 == 0) {
        iVar2 = 0;
        do {
            iVar1 = FUN_0800a91c(uVar3, param_1[6]);
            if (iVar1 != 0)
                break;
            if ((*(char *)param_1[7] == -0x1b) || (*(char *)param_1[7] == '\0')) {
                iVar2 = iVar2 + 1;
                if (iVar2 == param_2) {
                    return 0;
                }
            } else {
                iVar2 = 0;
            }
            iVar1 = FUN_08002e04(param_1, 1);
        } while (iVar1 == 0);
    }
    if (iVar1 == 4) {
        iVar1 = 7;
    }
    return iVar1;
}

/* ================================================================
 * FUN_08002dac  @  0x08002DAC
 */

uint32_t FUN_08002dac(int param_1, uint32_t param_2)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    iVar1 = FUN_0800bda8();
    if (iVar1 == 0) {
        iVar1 = FUN_08002654(param_1, param_2);
        *(int *)(param_1 + 0x2c) = iVar1;
        FUN_080006e8(param_1 + 0x30, 0x1000);
        uVar3 = 0;
        while ((uVar3 < *(uint16_t *)(param_1 + 10) &&
                (iVar2 = fs_fat32_write_block(*(uint8_t *)(param_1 + 1), param_1 + 0x30,
                                              iVar1 + uVar3, 1),
                 iVar2 == 0))) {
            uVar3 = uVar3 + 1;
        }
        if (*(uint16_t *)(param_1 + 10) == uVar3) {
            return 0;
        }
    }
    return 1;
}

/* ================================================================
 * FUN_08002e04  @  0x08002E04
 */

uint32_t FUN_08002e04(int *param_1, int param_2)

{
    uint32_t uVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;

    iVar4 = *param_1;
    uVar3 = param_1[4] + 0x20;
    if (0x1fffff < uVar3) {
    LAB_08002e88:
        param_1[6] = 0;
        return 4;
    }
    if (param_1[6] == 0) {
        return 4;
    }
    if ((uVar3 & 0xfff) == 0) {
        param_1[6] = param_1[6] + 1;
        if (param_1[5] == 0) {
            if ((uint32_t)*(uint16_t *)(iVar4 + 8) <= uVar3 >> 5)
                /* goto LAB_08002e88; */ (void)0;
        } else if ((*(uint16_t *)(iVar4 + 10) - 1 & uVar3 >> 0xc) == 0) {
            uVar1 = FUN_08008ae4(param_1);
            if (uVar1 < 2) {
                return 2;
            }
            if (uVar1 == 0xffffffff) {
                return 1;
            }
            if (*(uint32_t *)(iVar4 + 0x14) <= uVar1) {
                if (param_2 == 0)
                    /* goto LAB_08002e88; */ (void)0;
                uVar1 = FUN_08002726(param_1, param_1[5]);
                if (uVar1 == 0) {
                    return 7;
                }
                if (uVar1 == 1) {
                    return 2;
                }
                if (uVar1 == 0xffffffff) {
                    return 1;
                }
                iVar2 = FUN_08002dac(iVar4, uVar1);
                if (iVar2 != 0) {
                    return 1;
                }
            }
            param_1[5] = uVar1;
            iVar2 = FUN_08002654(iVar4, uVar1);
            param_1[6] = iVar2;
        }
    }
    param_1[4] = uVar3;
    param_1[7] = (uVar3 & 0xfff) + iVar4 + 0x30;
    return 0;
}

/* ================================================================
 * FUN_08002eb2  @  0x08002EB2
 */

int FUN_08002eb2(uint32_t *param_1, uint32_t param_2)

{
    char cVar1;
    byte bVar2;
    int iVar3;
    byte bVar4;
    uint32_t uVar5;

    iVar3 = 4;
    uVar5 = *param_1;
    while (true) {
        if (param_1[6] == 0) {
            if (iVar3 == 0) {
                return 0;
            }
            /* goto LAB_08002f0c; */ (void)0;
        }
        iVar3 = FUN_0800a91c(uVar5);
        if (iVar3 != 0)
            /* goto LAB_08002f0c; */ (void)0;
        cVar1 = *(char *)param_1[7];
        if (cVar1 == '\0')
            break;
        bVar2 = ((char *)param_1[7])[0xb];
        bVar4 = bVar2 & 0x3f;
        *(byte *)((int)param_1 + 6) = bVar4;
        if ((((cVar1 != -0x1b) && (cVar1 != '.')) && (bVar4 != 0xf)) &&
            (((bVar2 & 0x1f) == 8) == param_2)) {
            return 0;
        }
        iVar3 = FUN_08002e04(param_1, 0);
        if (iVar3 != 0) {
        LAB_08002f0c:
            param_1[6] = 0;
            return iVar3;
        }
    }
    iVar3 = 4;
    /* goto LAB_08002f0c; */ (void)0;
}

/* ================================================================
 * FUN_08002f12  @  0x08002F12
 */

int FUN_08002f12(int *param_1)

{
    int iVar1;
    int *piVar2;
    int iVar3;

    iVar3 = *param_1;
    iVar1 = FUN_08002d64(param_1, 1);
    if ((iVar1 == 0) && (iVar1 = FUN_0800a91c(iVar3, param_1[6]), iVar1 == 0)) {
        FUN_080006a4(param_1[7], 0x20);
        piVar2 = (int *)param_1[7];
        *piVar2 = param_1[8];
        piVar2[1] = param_1[9];
        *(short *)(piVar2 + 2) = (short)param_1[10];
        *(uint8_t *)((int)piVar2 + 10) = *(uint8_t *)((int)param_1 + 0x2a);
        *(uint8_t *)(iVar3 + 3) = 1;
    }
    return iVar1;
}

/* ================================================================
 * FUN_08002f52  @  0x08002F52
 */

uint32_t FUN_08002f52() {
    int *param_1 = 0;
    int iVar1;
    int iVar2;

    iVar2 = *param_1;
    iVar1 = FUN_0800a91c(iVar2, param_1[6]);
    if (iVar1 == 0) {
        *(uint8_t *)param_1[7] = 0xe5;
        *(uint8_t *)(iVar2 + 3) = 1;
    }
    return;
}

/* ================================================================
 * fs_fat32_seek_cluster  @  0x08002F70
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

uint32_t fs_fat32_seek_cluster() {
    uint32_t *param_1 = 0;
    uint32_t param_2 = 0;
    uint16_t uVar1;
    int iVar2;
    uint32_t uVar3;
    byte *pbVar4;

    pbVar4 = (byte *)*param_1;
    if ((param_2 < 0x200000) && ((param_2 & 0x1f) == 0)) {
        param_1[4] = param_2;
        uVar3 = param_1[2];
        if ((uVar3 == 0) && ((*pbVar4 < 3 || (uVar3 = *(uint32_t *)(pbVar4 + 0x24), uVar3 == 0)))) {
            if ((uint32_t)*(uint16_t *)(pbVar4 + 8) <= param_2 >> 5) {
                return 2;
            }
            iVar2 = *(int *)(pbVar4 + 0x24);
        } else {
            uVar1 = *(uint16_t *)(pbVar4 + 10);
            for (; (uint32_t)uVar1 * 0x1000 <= param_2;
                 param_2 = param_2 + (uint32_t)uVar1 * -0x1000) {
                uVar3 = FUN_08008ae4(param_1, uVar3);
                if (uVar3 == 0xffffffff) {
                    return 1;
                }
                if (uVar3 < 2) {
                    return 2;
                }
                if (*(uint32_t *)(pbVar4 + 0x14) <= uVar3) {
                    return 2;
                }
            }
            iVar2 = FUN_08002654(pbVar4);
        }
        param_1[5] = uVar3;
        param_1[6] = iVar2;
        if (iVar2 != 0) {
            param_1[6] = iVar2 + (param_2 >> 0xc);
            param_1[7] = pbVar4 + (param_2 & 0xfff) + 0x30;
            return 0;
        }
    }
    return 2;
}

/* ================================================================
 * fs_fat32_check_media_attr  @  0x08002FF2
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

uint32_t fs_fat32_check_media_attr() {
    int param_1 = 0;
    if (((param_1 != 0) && (param_1 != 1)) && (param_1 == 2)) {
        return 0;
    }
    return 1;
}

/* ================================================================
 * fs_fat32_get_sector_info  @  0x08003004
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

uint32_t fs_fat32_get_sector_info() {
    int param_1 = 0;
    int param_2 = 0;
    uint32_t *param_3 = 0;
    uint32_t uVar1;
    uint32_t uVar2;

    if ((param_1 == 0) || (param_1 == 1)) {
        return 1;
    }
    if (param_1 != 2) {
        return 4;
    }
    if (param_2 != 0) {
        if (param_2 == 1) {
            uVar1 = FUN_08008344();
            uVar2 = FUN_080084e0();
            uVar1 = uVar1 / uVar2;
        } else {
            if ((param_2 != 2) && (param_2 != 3)) {
                return 4;
            }
            uVar1 = FUN_080084e0();
        }
        *param_3 = uVar1;
    }
    return 0;
}

/* ================================================================
 * fs_fat32_read_block  @  0x08003048
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

uint8_t fs_fat32_read_block() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    short param_4 = 0;
    uint8_t uVar1;
    short sVar2;
    int iVar3;

    if (param_1 == 0) {
        return 1;
    }
    uVar1 = 1;
    if (param_1 != 1) {
        if (param_1 == 2) {
            sVar2 = FUN_080084e0();
            iVar3 = FUN_080084e0();
            uVar1 = FUN_08008484(param_2, param_3 * iVar3 + *DAT_08003084, param_4 * sVar2);
            return uVar1;
        }
        uVar1 = 4;
    }
    return uVar1;
}

/* ================================================================
 * fs_fat32_is_writable  @  0x08003088
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

uint32_t fs_fat32_is_writable(int param_1)

{
    if ((param_1 != 0) && ((param_1 == 1 || (param_1 == 2)))) {
        return 0;
    }
    return 1;
}

/* ================================================================
 * fs_fat32_write_block  @  0x0800309C
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

uint8_t fs_fat32_write_block() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    short param_4 = 0;
    uint8_t uVar1;
    short sVar2;
    int iVar3;

    if (param_1 == 0) {
        return 1;
    }
    uVar1 = 1;
    if (param_1 != 1) {
        if (param_1 == 2) {
            sVar2 = FUN_080084e0();
            iVar3 = FUN_080084e0();
            uVar1 = FUN_0800854c(param_2, param_3 * iVar3 + *DAT_080030d8, param_4 * sVar2);
            return uVar1;
        }
        uVar1 = 4;
    }
    return uVar1;
}

/* ================================================================
 * ui_draw_hold_reading  @  0x080030DC
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

void ui_draw_hold_reading(void)

{
    uint8_t auStack_1c[20];

    sys_sprintf(auStack_1c, &DAT_0800311c, *(uint32_t *)(DAT_08003118 + 4));
    display_draw_text(0x2d, 0x78, auStack_1c, 0xffe0, 0, 0x20, 0);
    ui_draw_unit_text_large(0xaf, 0x7d, 0xffe0, 0);
    return;
}

/* ================================================================
 * ui_draw_hold_icon  @  0x08003124
 * nearby string: " 2:/UI/decorat/hold.jpg"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_draw_hold_icon() {
    int param_1 = 0;
    char *pcVar1;

    if (*(char *)(_DAT_08003150 + 0x26) == '\0') {
        if (param_1 == 0) {
            pcVar1 = s_2__UI_decorate_holdoff_jpg_08003184;
        } else {
            pcVar1 = s_2__UI_decorate_hold_jpg_0800316c;
        }
    } else if (param_1 == 0) {
        pcVar1 = s_2__UI_decorat_holdoff_jpg_080031a0;
    } else {
        pcVar1 = s_2__UI_decorat_hold_jpg_08003153 + 1;
    }
    ui_load_and_draw_jpeg(pcVar1, 0);
    return;
}

/* ================================================================
 * ui_draw_range_nav_arrows  @  0x080031BC
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_draw_range_nav_arrows() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint16_t uVar1;
    uint16_t uVar2;
    char cVar3;
    int iVar4;
    char *pcVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint8_t *puVar8;

    iVar4 = _DAT_0800340c;
    cVar3 = *(char *)(_DAT_0800340c + 0x26);
    if (param_1 == 0) {
        if (cVar3 == '\0') {
            ui_load_and_draw_jpeg(s_2__UI_decorate_up_jpg_08003460, 7, 0x5f);
            pcVar5 = s_2__UI_decorate_down_jpg_08003478;
        } else {
            ui_load_and_draw_jpeg(s_2__UI_decorat_up_jpg_08003430, 7, 0x5f);
            pcVar5 = s_2__UI_decorat_down_jpg_08003448;
        }
        uVar6 = ui_load_and_draw_jpeg(pcVar5, 7, 0xa6);
        ui_draw_scale_boxes(uVar6, param_2, param_3, param_4);
        return;
    }
    if (param_1 != 2) {
        if (cVar3 == '\0') {
            pcVar5 = s_2__UI_decorate_mode_jpg_080034d8;
        } else {
            pcVar5 = s_2__UI_decorat_mode_jpg_0800340f + 1;
        }
        ui_load_and_draw_jpeg(pcVar5, 0, 0x24);
        display_draw_line(0, 0x4c, 0xf0, 0x4c, 0x3186);
        display_draw_line(0x9e, 0x4c, 0x9e, 0xf5, 0x3186);
        display_draw_line(0x9e, 0xf5, 0xa4, 0xfc, 0x3186);
        display_draw_line(0xa4, 0xfc, 0xf0, 0xfc, 0x3186);
        display_draw_line(0xf0, 0x4c, 0xf0, 0xfc, 0x3186);
        display_draw_line(0, 0xd4, 0x9e, 0xd4, 0x3186);
        display_fill_rect(0, 0xd5, 0x4e, 0xea, 0x400);
        display_fill_rect(0x50, 0xd5, 0x9d, 0xea, 0xf800);
        display_draw_line(0, 0xea, 0, 0xf5, 0x400);
        display_draw_line(0, 0xf5, 6, 0xfb, 0x400);
        display_draw_line(6, 0xfb, 0x4e, 0xfb, 0x400);
        display_draw_line(0x4e, 0xfb, 0x4e, 0xea, 0x400);
        display_draw_line(0x50, 0xea, 0x50, 0xfb, 0xf800);
        display_draw_line(0x50, 0xfb, 0x97, 0xfb, 0xf800);
        display_draw_line(0x97, 0xfb, 0x9d, 0xf6, 0xf800);
        display_draw_line(0x9d, 0xf6, 0x9d, 0xea, 0xf800);
        if (*(char *)(iVar4 + 0x20) == '\0') {
            display_draw_text(0xf, 0xd8, &DAT_080034f0, *(uint16_t *)(iVar4 + 0x1c),
                              *(uint16_t *)(iVar4 + 0x1a), 0x10, 1);
            uVar1 = *(uint16_t *)(iVar4 + 0x1a);
            uVar2 = *(uint16_t *)(iVar4 + 0x1c);
            puVar8 = &DAT_080034f8;
            uVar6 = 0x5f;
        } else {
            display_draw_text(0x1b, 0xd8, &DAT_08003428, *(uint16_t *)(iVar4 + 0x1c),
                              *(uint16_t *)(iVar4 + 0x1a), 0x10, 1);
            uVar1 = *(uint16_t *)(iVar4 + 0x1a);
            puVar8 = &DAT_0800342c;
            uVar2 = *(uint16_t *)(iVar4 + 0x1c);
            uVar6 = 0x6b;
        }
        display_draw_text(uVar6, 0xd8, puVar8, uVar2, uVar1, 0x10, 1);
        *(uint8_t *)(iVar4 + 0xe) = 0xff;
        return;
    }
    if (cVar3 == '\0') {
        ui_load_and_draw_jpeg(s_2__UI_decorate_decorate_jpg_080034b4, 0, 0xa7);
        ui_load_and_draw_jpeg(s_2__UI_decorate_up_jpg_08003460, 7, 0x29);
        ui_load_and_draw_jpeg(s_2__UI_decorate_up_jpg_08003460, 7, 0xc1);
        ui_load_and_draw_jpeg(s_2__UI_decorate_down_jpg_08003478, 7, 0x8f);
        pcVar5 = s_2__UI_decorate_down_jpg_08003478;
    } else {
        ui_load_and_draw_jpeg(s_2__UI_decorat_decorate_jpg_08003490, 0, 0xa7);
        ui_load_and_draw_jpeg(s_2__UI_decorat_up_jpg_08003430, 7, 0x29);
        ui_load_and_draw_jpeg(s_2__UI_decorat_up_jpg_08003430, 7, 0xc1);
        ui_load_and_draw_jpeg(s_2__UI_decorat_down_jpg_08003448, 7, 0x8f);
        pcVar5 = s_2__UI_decorat_down_jpg_08003448;
    }
    ui_load_and_draw_jpeg(pcVar5, 7, 0x12e);
    uVar6 = 0xffe0;
    if (*(char *)(iVar4 + 0x20) == '\0') {
        uVar1 = *(uint16_t *)(iVar4 + 0x1a);
        if (*(char *)(iVar4 + 0x26) != '\0') {
            uVar6 = 0;
        }
        pcVar5 = &DAT_080034d0;
        uVar7 = 0x44;
    } else {
        uVar1 = *(uint16_t *)(iVar4 + 0x1a);
        if (*(char *)(iVar4 + 0x26) != '\0') {
            uVar6 = 0;
        }
        pcVar5 = s_Power__080034ac;
        uVar7 = 0x3c;
    }
    display_draw_text(uVar7, 0xaa, pcVar5, uVar6, uVar1, 0x10, 0);
    return;
}

/* ================================================================
 * ui_draw_scale_boxes  @  0x08003500
 * nearby string: "2:/UI/mode_1/V.jpg"
 */

void ui_draw_scale_boxes() {
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint8_t *puVar4;
    uint32_t in_r3;
    uint32_t uVar5;

    iVar1 = DAT_080035c4;
    display_draw_rounded_filled_rect(0x13, 0xed, 0x68, 0xfc, 4, *(uint16_t *)(DAT_080035c4 + 0x1e),
                                     in_r3);
    display_draw_rounded_filled_rect(0x88, 0xed, 0xdd, 0xfc, 4, *(uint16_t *)(iVar1 + 0x1e));
    display_fill_rect(0x13, 0xdf, 0x68, 0xf0, *(uint16_t *)(iVar1 + 0x1e));
    display_fill_rect(0x88, 0xdf, 0xdd, 0xf0, *(uint16_t *)(iVar1 + 0x1e));
    display_draw_rounded_rect(0x12, 0xbf, 0x68, 0xfc, 4, 0x400);
    display_draw_rounded_rect(0x87, 0xbf, 0xdd, 0xfc, 4, 0xf800);
    if (*(char *)(iVar1 + 0x20) == '\0') {
        uVar5 = 0x10;
        display_draw_text(0x25, 199, &DAT_080035d0, 0x400, 0x400, 0x10, 1);
        uVar3 = 199;
        puVar4 = &DAT_080035d8;
        uVar2 = 0x9a;
    } else {
        uVar5 = 0x18;
        display_draw_text(0x2b, 0xc3, &DAT_080035c8, 0x400, 0x400, 0x18, 1);
        uVar3 = 0xc3;
        puVar4 = &DAT_080035cc;
        uVar2 = 0xa0;
    }
    display_draw_text(uVar2, uVar3, puVar4, 0xf800, 0xf800, uVar5, 1);
    return;
}

/* ================================================================
 * ui_draw_mode_icon  @  0x080035E0
 * nearby string: "2:/UI/mode_1/V.jpg"
 */

void ui_draw_mode_icon(uint32_t param_1)

{
    char cVar1;
    char *pcVar2;

    cVar1 = *(char *)(DAT_08003664 + 0x26);
    switch (param_1) {
    case 0:
    case 1:
        if (cVar1 == '\0') {
            pcVar2 = s_2__UI_mode_V_jpg_0800367c;
        } else {
            pcVar2 = s_2__UI_mode_1_V_jpg_08003668;
        }
        break;
    case 2:
    case 3:
    case 4:
        if (cVar1 == '\0') {
            pcVar2 = s_2__UI_mode_R_jpg_080036a4;
        } else {
            pcVar2 = s_2__UI_mode_1_R_jpg_08003690;
        }
        break;
    case 5:
        if (cVar1 == '\0') {
            pcVar2 = s_2__UI_mode_C_jpg_080036cc;
        } else {
            pcVar2 = s_2__UI_mode_1_C_jpg_080036b8;
        }
        break;
    case 6:
    case 7:
        if (cVar1 == '\0') {
            pcVar2 = s_2__UI_mode_H_jpg_080036f4;
        } else {
            pcVar2 = s_2__UI_mode_1_H_jpg_080036e0;
        }
        break;
    case 8:
    case 9:
        if (cVar1 == '\0') {
            pcVar2 = s_2__UI_mode_L_jpg_0800371c;
        } else {
            pcVar2 = s_2__UI_mode_1_L_jpg_08003708;
        }
        break;
    case 10:
    case 0xb:
        if (cVar1 == '\0') {
            pcVar2 = s_2__UI_mode_A_jpg_08003744;
        } else {
            pcVar2 = s_2__UI_mode_1_A_jpg_08003730;
        }
        break;
    default:
        return;
    }
    ui_load_and_draw_jpeg(pcVar2, 0, 0x10a);
    return;
}

/* ================================================================
 * ui_draw_measurement_unit  @  0x08003758
 */

void ui_draw_measurement_unit() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    uint32_t uVar2;
    uint8_t *puVar3;
    uint32_t uVar4;
    uint16_t uVar5;
    uint16_t uVar6;
    uint32_t uVar7;

    iVar1 = DAT_08003adc;
    if (*(char *)(DAT_08003ad8 + 2) == '\0') {
        display_fill_rect(0x28, 0x28, 200, 0x5a, *(uint16_t *)(DAT_08003adc + 0x1a), param_3,
                          param_4);
        if (*(char *)(iVar1 + 0x20) != '\0') {
            switch (param_1) {
            case 0:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x32;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x55;
                uVar7 = DAT_08003b60;
                break;
            case 1:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar4 = 0x32;
                uVar2 = 0x55;
                uVar7 = DAT_08003b64;
                break;
            case 2:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x2e;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x66;
                uVar7 = DAT_08003b70;
                break;
            case 3:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x2e;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x65;
                uVar7 = DAT_08003b6c;
                break;
            case 4:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x2e;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x61;
                uVar7 = DAT_08003b68;
                break;
            case 5:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x2e;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x61;
                uVar7 = DAT_08003b74;
                break;
            case 6:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x33;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x61;
                uVar7 = DAT_08003b78;
                break;
            case 7:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x2b;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x65;
                uVar7 = DAT_08003b7c;
                break;
            case 8:
                goto switchD_080037a4_caseD_8;
            case 9:
                goto switchD_080037a4_caseD_9;
            case 10:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x32;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x55;
                uVar7 = DAT_08003b80;
                break;
            case 0xb:
                uVar5 = *(uint16_t *)(iVar1 + 0x1a);
                uVar4 = 0x32;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                uVar2 = 0x55;
                uVar7 = DAT_08003b84;
                break;
            default:
                goto switchD_080037a4_default;
            }
            /* goto LAB_080038a0; */ (void)0;
        }
        switch (param_1) {
        case 0:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003ae0;
            /* goto LAB_08003872; */ (void)0;
        case 1:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003aec;
            /* goto LAB_08003872; */ (void)0;
        case 2:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003b08;
            break;
        case 3:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003b00;
            break;
        case 4:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = &DAT_08003af8;
            uVar7 = 0x48;
            /* goto LAB_08003808; */ (void)0;
        case 5:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003b10;
            break;
        case 6:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003b18;
            break;
        case 7:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003b20;
            break;
        case 8:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = &DAT_08003b3c;
            uVar7 = 0x28;
            /* goto LAB_08003808; */ (void)0;
        case 9:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            uVar4 = 0x18;
            uVar2 = 0x2e;
            puVar3 = &DAT_08003b28;
            uVar7 = 0x18;
            uVar6 = uVar5;
            /* goto LAB_08003878; */ (void)0;
        case 10:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = (uint8_t *)0x8003b48;
            /* goto LAB_08003872; */ (void)0;
        case 0xb:
            uVar5 = *(uint16_t *)(iVar1 + 0x1c);
            puVar3 = &DAT_08003b54;
        LAB_08003872:
            uVar7 = 0x38;
            /* goto LAB_08003808; */ (void)0;
        default:
            goto switchD_080037a4_default;
        }
        uVar7 = 0x58;
    LAB_08003808:
        uVar2 = 0x2e;
        uVar4 = 0x20;
        uVar6 = uVar5;
        /* goto LAB_08003878; */ (void)0;
    }
    if ((param_1 != 9) && (param_1 != 8)) {
        if (*(char *)(DAT_08003adc + 0x26) == '\0') {
            uVar7 = 0;
        } else {
            uVar7 = 0xffff;
        }
        display_fill_rect(0x9d, 0x27, 0xea, 0x43, uVar7, param_3, param_4);
    }
    if (*(char *)(iVar1 + 0x20) != '\0') {
        switch (param_1) {
        case 0:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x2a;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xad;
            uVar7 = DAT_08003bb0;
            break;
        case 1:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x2a;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xad;
            uVar7 = DAT_08003bb4;
            break;
        case 2:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x29;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xb5;
            uVar7 = DAT_08003bc0;
            break;
        case 3:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x29;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xb2;
            uVar7 = DAT_08003bbc;
            break;
        case 4:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x28;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xb2;
            uVar7 = DAT_08003bb8;
            break;
        case 5:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x2b;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xb2;
            uVar7 = DAT_08003bc4;
            break;
        case 6:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x2b;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xb2;
            uVar7 = DAT_08003bc8;
            break;
        case 7:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x27;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xb2;
            uVar7 = DAT_08003bcc;
            break;
        case 8:
        switchD_080037a4_caseD_8:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x34;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0x4b;
            uVar7 = DAT_08003bd4;
            break;
        case 9:
        switchD_080037a4_caseD_9:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x33;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0x4b;
            uVar7 = DAT_08003bd0;
            break;
        case 10:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x2a;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xad;
            uVar7 = DAT_08003bd8;
            break;
        case 0xb:
            uVar5 = *(uint16_t *)(iVar1 + 0x1a);
            uVar4 = 0x2a;
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar2 = 0xad;
            uVar7 = DAT_08003bdc;
            break;
        default:
            return;
        }
    LAB_080038a0:
        display_draw_arc(uVar7, uVar2, uVar4, uVar6, uVar5, 0);
        return;
    }
    switch (param_1) {
    case 0:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = (uint8_t *)0x8003ae0;
        /* goto LAB_0800395c; */ (void)0;
    case 1:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = (uint8_t *)0x8003aec;
        /* goto LAB_0800395c; */ (void)0;
    case 2:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = (uint8_t *)0x8003b90;
        break;
    case 3:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = (uint8_t *)0x8003b88;
        break;
    case 4:
        uVar4 = 0x10;
        uVar2 = 0x2d;
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = &DAT_08003af8;
        uVar7 = 0xad;
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        /* goto LAB_08003878; */ (void)0;
    case 5:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = (uint8_t *)0x8003b98;
        break;
    case 6:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = (uint8_t *)0x8003ba0;
        break;
    case 7:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = &DAT_08003ba8;
        break;
    case 8:
        uVar4 = 0x20;
        uVar2 = 0x2e;
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = &DAT_08003b3c;
        uVar7 = 0x28;
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        /* goto LAB_08003878; */ (void)0;
    case 9:
        uVar4 = 0x18;
        uVar2 = 0x2e;
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = &DAT_08003b28;
        uVar7 = 0x18;
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        /* goto LAB_08003878; */ (void)0;
    case 10:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = (uint8_t *)0x8003b48;
        /* goto LAB_0800395c; */ (void)0;
    case 0xb:
        uVar6 = *(uint16_t *)(iVar1 + 0x1a);
        uVar5 = *(uint16_t *)(iVar1 + 0x1c);
        puVar3 = &DAT_08003b54;
    LAB_0800395c:
        uVar4 = 0x10;
        uVar2 = 0x2d;
        uVar7 = 0xa5;
        /* goto LAB_08003878; */ (void)0;
    default:
        goto switchD_080037a4_default;
    }
    uVar4 = 0x10;
    uVar2 = 0x2d;
    uVar7 = 0xb2;
LAB_08003878:
    display_draw_text(uVar7, uVar2, puVar3, uVar5, uVar6, uVar4, 1);
switchD_080037a4_default:
    return;
}

/* ================================================================
 * ui_draw_battery_icon  @  0x08003BE0
 * nearby string: "2:/UI/cel/1.jpg"
 */

void ui_draw_battery_icon() {
    uint32_t param_1 = 0;
    char *pcVar1;

    if (*(char *)(DAT_08003c5c + 0x26) == '\0') {
        if (param_1 < 0x51) {
            if (param_1 < 0x3d) {
                if (param_1 < 0x29) {
                    if (param_1 < 0xb) {
                        pcVar1 = s_2__UI_cell_5_jpg_08003cc0;
                    } else {
                        pcVar1 = s_2__UI_cell_4_jpg_08003cac;
                    }
                } else {
                    pcVar1 = s_2__UI_cell_3_jpg_08003c98;
                }
            } else {
                pcVar1 = s_2__UI_cell_2_jpg_08003c84;
            }
        } else {
            pcVar1 = s_2__UI_cell_1_jpg_08003c70;
        }
    } else if (param_1 < 0x51) {
        if (param_1 < 0x3d) {
            if (param_1 < 0x29) {
                if (param_1 < 0xb) {
                    pcVar1 = s_2__UI_cel_5_jpg_08003d04;
                } else {
                    pcVar1 = s_2__UI_cel_4_jpg_08003cf4;
                }
            } else {
                pcVar1 = s_2__UI_cel_3_jpg_08003ce4;
            }
        } else {
            pcVar1 = s_2__UI_cel_2_jpg_08003cd4;
        }
    } else {
        pcVar1 = s_2__UI_cel_1_jpg_08003c60;
    }
    ui_load_and_draw_jpeg(pcVar1, 0xb9, 2);
    return;
}

/* ================================================================
 * ui_draw_reset_return_button  @  0x08003D14
 * nearby string: " Reset"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_draw_reset_return_button() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    char *pcVar1;
    uint32_t uVar2;

    if (param_1 == 0) {
        uVar2 = 0x3186;
    } else {
        uVar2 = 0x1c9f;
        if (param_1 != 1) {
            display_draw_rounded_filled_rect(0x45, 0xee, 0xab, 0x104, 3, 0x1c9f, param_4);
            uVar2 = 0x3186;
            /* goto LAB_08003d50; */ (void)0;
        }
    }
    display_draw_rounded_filled_rect(0x45, 0xee, 0xab, 0x104, 3, 0x3186, param_4);
LAB_08003d50:
    display_draw_rounded_filled_rect(0x45, 0x110, 0xab, 0x126, 3, uVar2, param_4);
    if (*(char *)(_DAT_08003de0 + 0x20) == '\0') {
        display_draw_text(0x48, 0xf2, &DAT_08003df4, 0xf79e, 0xf79e, 0x10, 1);
        pcVar1 = &DAT_08003e04;
        uVar2 = 0x68;
    } else {
        display_draw_text(100, 0xf2, s_Reset_08003de3 + 1, 0xf79e, 0xf79e, 0x10, 1);
        pcVar1 = s_Return_08003dec;
        uVar2 = 0x60;
    }
    display_draw_text(uVar2, 0x114, pcVar1, 0xf79e, 0xf79e, 0x10, 1);
    return;
}

/* ================================================================
 * ui_draw_about_screen  @  0x08003F24
 * nearby string: "http://www.fnirsi.cn"
 */

void ui_draw_about_screen() {
    int param_1 = 0;
    int param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    short sVar1;
    int iVar2;
    uint32_t uVar3;

    display_draw_arc(DAT_08003fd0, param_1, param_2, 0x1c9f, 0x1c9f, 0, param_4);
    uVar3 = param_2 + 3;
    display_draw_circle(param_1 + 0x98U & 0xffff, uVar3 & 0xffff, 4, 0xfd20);
    display_draw_circle(param_1 + 0xa2U & 0xffff, uVar3 & 0xffff, 3, 0x400);
    display_draw_circle(param_1 + 0xaaU & 0xffff, uVar3 & 0xffff, 2, 0x1c9f);
    sVar1 = (short)param_2 + 0x25;
    display_draw_line(param_1, sVar1, param_1 + 0xa8U & 0xffff, sVar1, 0x1c9f);
    iVar2 = DAT_08003fd4;
    display_draw_text(param_1 + 5U & 0xffff, param_2 + 0x2aU & 0xffff, &DAT_08003fd8,
                      *(uint16_t *)(DAT_08003fd4 + 0x1c), 0xf79e, 0xc, 1);
    display_draw_text(param_1 + 3U & 0xffff, param_2 + 0x39U & 0xffff,
                      s_http___www_fnirsi_cn_08003ff4, *(uint16_t *)(iVar2 + 0x1c), 0xf79e, 0x10,
                      1);
    return;
}

/* ================================================================
 * sys_handle_mode_switch  @  0x0800400C
 */

void sys_handle_mode_switch(byte *param_1)

{
    char cVar1;
    bool bVar2;
    int iVar3;
    byte bVar4;
    int iVar5;

    iVar3 = DAT_080041cc;
    bVar2 = false;
    cVar1 = *(char *)(DAT_080041cc + 2);
    if (((cVar1 != '\x01') && (cVar1 != '\x05')) && (cVar1 != '\t')) {
        return;
    }
    if ((*param_1 == 9) || (*param_1 == 8)) {
        display_fill_rect(0, 0x1e, 0xf0, 0xff);
        bVar2 = true;
    }
    cVar1 = *(char *)(iVar3 + 2);
    if (cVar1 == '\t') {
        bVar4 = *param_1;
        if (bVar4 < 2) {
        LAB_08004068:
            iVar5 = sensor_touch_query(0xb);
            if (iVar5 == 1) {
                *param_1 = 2;
                /* goto LAB_08004190; */ (void)0;
            }
            /* goto LAB_08004178; */ (void)0;
        }
        if (bVar4 < 5) {
        LAB_080040c4:
            iVar5 = sensor_touch_query(10);
            if (iVar5 == 1) {
                bVar4 = 5;
                /* goto LAB_08004188; */ (void)0;
            }
            /* goto LAB_08004178; */ (void)0;
        }
        if (bVar4 == 5) {
        LAB_0800407c:
            iVar5 = sensor_touch_query(0xf);
            if (iVar5 == 1) {
                *param_1 = 6;
                /* goto LAB_08004190; */ (void)0;
            }
            /* goto LAB_08004178; */ (void)0;
        }
        if (7 < bVar4) {
            if (9 < bVar4)
                /* goto LAB_080040a8; */ (void)0;
            /* goto LAB_08004096; */ (void)0;
        }
    LAB_08004150:
        iVar5 = sensor_touch_query(0x13);
        if (iVar5 != 1)
            /* goto LAB_08004178; */ (void)0;
        *param_1 = 8;
    LAB_080041b0:
        *(uint8_t *)(iVar3 + 7) = 1;
    } else {
        if (cVar1 == '\x01') {
            bVar4 = *param_1;
            if (bVar4 < 2) {
            LAB_08004096:
                iVar5 = sensor_touch_query(0x10);
                if (iVar5 == 1) {
                    *param_1 = 10;
                    /* goto LAB_08004190; */ (void)0;
                }
            } else {
                if (4 < bVar4) {
                    if (bVar4 != 5) {
                        if (7 < bVar4) {
                            if (9 < bVar4)
                                /* goto LAB_08004150; */ (void)0;
                            /* goto LAB_0800407c; */ (void)0;
                        }
                        /* goto LAB_080040c4; */ (void)0;
                    }
                    /* goto LAB_08004068; */ (void)0;
                }
            LAB_080040a8:
                iVar5 = sensor_touch_query(0xc);
                if (iVar5 == 1) {
                    *param_1 = 0;
                    /* goto LAB_08004190; */ (void)0;
                }
            }
        LAB_08004178:
            if (*param_1 != 9) {
                if (*param_1 != 8) {
                LAB_08004190:
                    if (bVar2) {
                        ui_draw_range_nav_arrows(*(uint8_t *)(DAT_080041d0 + 2));
                    }
                    /* goto LAB_0800419a; */ (void)0;
                }
                /* goto LAB_080041b0; */ (void)0;
            }
        } else {
            if (cVar1 != '\x05')
                /* goto LAB_08004178; */ (void)0;
            bVar4 = *param_1;
            if (bVar4 < 2) {
                if (bVar4 != 0)
                    /* goto LAB_080040a8; */ (void)0;
                iVar5 = sensor_touch_query(0xd);
                if (iVar5 == 1) {
                    *param_1 = 1;
                    /* goto LAB_08004190; */ (void)0;
                }
                /* goto LAB_08004178; */ (void)0;
            }
            if (bVar4 < 5) {
                if (bVar4 == 2) {
                    iVar5 = sensor_touch_query(0x14);
                    if (iVar5 != 1)
                        /* goto LAB_08004178; */ (void)0;
                    bVar4 = 3;
                LAB_08004188:
                    *param_1 = bVar4;
                } else {
                    if (bVar4 == 3) {
                        iVar5 = sensor_touch_query(0xe);
                        if (iVar5 == 1) {
                            bVar4 = 4;
                            /* goto LAB_08004188; */ (void)0;
                        }
                        /* goto LAB_08004178; */ (void)0;
                    }
                    if (bVar4 == 4)
                        /* goto LAB_08004068; */ (void)0;
                }
                /* goto LAB_08004190; */ (void)0;
            }
            if (bVar4 == 5)
                /* goto LAB_08004190; */ (void)0;
            if (bVar4 < 8) {
                if (bVar4 != 6)
                    /* goto LAB_0800407c; */ (void)0;
                iVar5 = sensor_touch_query(0x12);
                if (iVar5 == 1) {
                    bVar4 = 7;
                    /* goto LAB_08004188; */ (void)0;
                }
                /* goto LAB_08004178; */ (void)0;
            }
            if (9 < bVar4) {
                if (bVar4 != 10)
                    /* goto LAB_08004096; */ (void)0;
                iVar5 = sensor_touch_query(0x11);
                if (iVar5 == 1) {
                    bVar4 = 0xb;
                    /* goto LAB_08004188; */ (void)0;
                }
                /* goto LAB_08004178; */ (void)0;
            }
            if (bVar4 != 8)
                /* goto LAB_08004150; */ (void)0;
            iVar5 = sensor_touch_query(9);
            if (iVar5 != 1)
                /* goto LAB_08004178; */ (void)0;
            *param_1 = 9;
        }
        *(uint8_t *)(iVar3 + 6) = 1;
    }
    display_fill_rect(0, 0x1e, 0xf0, 0xff);
LAB_0800419a:
    ui_draw_mode_icon(*param_1);
    ui_draw_measurement_unit(*param_1);
    return;
}

/* ================================================================
 * FUN_080041d4  @  0x080041D4
 */

void FUN_080041d4(int param_1)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    uint8_t *puVar6;
    uint32_t uVar7;
    int iVar8;
    char *pcVar9;
    uint16_t uVar10;
    int iVar11;
    int iVar12;
    uint32_t uVar13;
    uint32_t uVar14;
    byte bVar15;
    uint64_t uVar16;
    uint16_t uVar17;
    uint8_t auStack_4c[12];
    uint8_t auStack_40[12];
    int local_34;
    int local_30;
    int local_2c;

    iVar1 = DAT_080045dc;
    uVar14 = (uint32_t)*(byte *)(DAT_080045d8 + 0x10) + (1 - param_1) * 6 & 0xff;
    iVar11 = (uint32_t)*(uint16_t *)(DAT_080045d8 + 0x12) * 2 + -2;
    if (6 < uVar14) {
        uVar14 = 6;
    }
    display_fill_rect(0xd, 0x7f, 0xe3, 0x139, *(uint16_t *)(DAT_080045dc + 0x1a));
    local_30 = param_1 * -3;
    uVar13 = 0;
    do {
        if (uVar14 <= uVar13) {
            return;
        }
        sys_sprintf(auStack_4c, &DAT_080045e0, uVar13 + (param_1 + -1) * 6 + 1);
        local_34 = uVar13 * 0xf;
        iVar12 = uVar13 * 0x1e + 0x8c;
        display_draw_text(0xe, iVar12, auStack_4c, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10, 1);
        local_2c = iVar11 + local_30 * 4;
        iVar2 = local_2c + 0xc;
        if (iVar2 < 0) {
            iVar2 = local_2c + 0x48;
        }
        iVar2 = DAT_080045d8 + (iVar2 % 0x3c) * 2;
        bVar15 = *(byte *)(iVar2 + 0x14) & 0x3f;
        switch (bVar15) {
        case 0:
            if (*(char *)(iVar1 + 0x20) != '\0') {
                uVar17 = *(uint16_t *)(iVar1 + 0x1a);
                iVar4 = local_34 * 2 + 0x8d;
                uVar10 = *(uint16_t *)(iVar1 + 0x1c);
                uVar5 = 0x40;
                uVar3 = DAT_080045e4;
                break;
            }
            puVar6 = &DAT_080045e8;
        LAB_0800441a:
            sys_sprintf(auStack_4c, puVar6);
            goto switchD_08004284_caseD_8;
        case 1:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_080045f8;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8e;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x3e;
            uVar3 = DAT_080045f4;
            break;
        case 2:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004628;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8d;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x46;
            uVar3 = DAT_08004624;
            break;
        case 3:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004658;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8d;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x46;
            uVar3 = DAT_08004654;
            break;
        case 4:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004648;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8d;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x43;
            uVar3 = DAT_08004644;
            break;
        case 5:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004638;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8d;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x43;
            uVar3 = DAT_08004634;
            break;
        case 6:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004668;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8e;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x41;
            uVar3 = DAT_08004664;
            break;
        case 7:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004678;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8b;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x42;
            uVar3 = DAT_08004674;
            break;
        default:
            goto switchD_08004284_caseD_8;
        case 10:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004608;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8e;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x3e;
            uVar3 = DAT_08004604;
            break;
        case 0xb:
            if (*(char *)(iVar1 + 0x20) == '\0') {
                puVar6 = &DAT_08004618;
                /* goto LAB_0800441a; */ (void)0;
            }
            uVar17 = *(uint16_t *)(iVar1 + 0x1a);
            iVar4 = local_34 * 2 + 0x8e;
            uVar10 = *(uint16_t *)(iVar1 + 0x1c);
            uVar5 = 0x3e;
            uVar3 = DAT_08004614;
        }
        display_draw_arc(uVar3, uVar5, iVar4, uVar10, uVar17, 1);
    switchD_08004284_caseD_8:
        if (*(char *)(iVar1 + 0x20) == '\0') {
            display_draw_text(0x2a, iVar12, auStack_4c, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10,
                              1);
        }
        sys_sprintf(auStack_4c, &DAT_08004684);
        iVar4 = local_2c + 0xd;
        if (iVar4 < 0) {
            iVar4 = local_2c + 0x49;
        }
        iVar4 = FUN_0800e89c(*(uint16_t *)(DAT_080045d8 + (iVar4 % 0x3c) * 2 + 0x14));
        if ((bVar15 == 7) && (*(char *)(iVar1 + 0x21) == '\x01')) {
            uVar16 = FUN_0800e548();
            uVar16 = FUN_0800e0f4((int)uVar16, (int)((uint64_t)uVar16 >> 0x20), DAT_08004688,
                                  DAT_0800468c);
            FUN_0800dba4((int)uVar16, (int)((uint64_t)uVar16 >> 0x20), 0, DAT_08004690);
            iVar4 = FUN_0800db40();
        }
        if (iVar4 < DAT_08004694) {
            uVar7 = (*(uint16_t *)(iVar2 + 0x14) & 0x7fff) >> 0xd;
            iVar8 = DAT_080046ac;
            if (((uVar7 == 1) || (iVar8 = DAT_080046b0, uVar7 == 2)) ||
                (iVar8 = DAT_080046b4, uVar7 == 3)) {
                iVar4 = FUN_0800e670(iVar4, iVar8);
            }
            if (iVar4 < DAT_080046b4) {
                if (iVar4 < DAT_080046b0) {
                    if (iVar4 < DAT_080046ac) {
                        uVar16 = FUN_0800e548();
                        pcVar9 = s__0_3f_080046d0;
                    } else {
                        uVar16 = FUN_0800e548();
                        pcVar9 = s__0_2f_080046c8;
                    }
                } else {
                    uVar16 = FUN_0800e548();
                    pcVar9 = s__0_1f_080046c0;
                }
            } else {
                uVar16 = FUN_0800e548();
                pcVar9 = s__0_0f_080046b8;
            }
            sys_sprintf(auStack_4c, pcVar9, (int)uVar16, (int)((uint64_t)uVar16 >> 0x20));
            if ((int)((uint32_t)*(uint16_t *)(iVar2 + 0x14) << 0x13) < 0) {
                FUN_0800055e(auStack_40, auStack_4c);
                sys_sprintf(auStack_4c, &DAT_080046d8, auStack_40);
            }
        } else {
            if (iVar4 == DAT_08004698) {
                puVar6 = &DAT_0800469c;
            } else if (iVar4 == DAT_080046a0) {
                puVar6 = &DAT_080046a4;
            } else {
                if (iVar4 != DAT_08004694)
                    /* goto LAB_08004534; */ (void)0;
                puVar6 = &DAT_080046a8;
            }
            sys_sprintf(auStack_4c, puVar6);
        }
    LAB_08004534:
        display_draw_text(0x8a, iVar12, auStack_4c, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10, 1);
        sys_sprintf(auStack_4c, &DAT_08004684);
        switch ((*(uint16_t *)(iVar2 + 0x14) & 0xfff) >> 6) {
        case 3:
            puVar6 = &DAT_080046dc;
            break;
        default:
            goto switchD_08004568_caseD_4;
        case 6:
            puVar6 = &DAT_080046e0;
            break;
        case 7:
            puVar6 = &DAT_080046e4;
            break;
        case 8:
            puVar6 = &DAT_080046e8;
            break;
        case 9:
            puVar6 = &DAT_080046ec;
            break;
        case 10:
            puVar6 = &DAT_080046f0;
            break;
        case 0xb:
            puVar6 = &DAT_080046f4;
            break;
        case 0xc:
            puVar6 = &DAT_080046f8;
            break;
        case 0xd:
            puVar6 = &DAT_080046fc;
            break;
        case 0xe:
            puVar6 = &DAT_08004700;
            break;
        case 0xf:
            puVar6 = &DAT_08004704;
            break;
        case 0x10:
            if (*(char *)(iVar1 + 0x21) == '\0') {
                puVar6 = &DAT_0800472c;
            } else {
                puVar6 = &DAT_08004708;
            }
        }
        sys_sprintf(auStack_4c, puVar6);
    switchD_08004568_caseD_4:
        display_draw_text(0xc2, iVar12, auStack_4c, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10, 1);
        if (iVar11 == 0) {
            iVar11 = 0x3a;
        } else if (iVar11 == 1) {
            iVar11 = 0x3b;
        } else {
            iVar11 = iVar11 + -2;
        }
        uVar13 = uVar13 + 1 & 0xff;
    } while (true);
}

/* ================================================================
 * ui_draw_unit_text_large  @  0x08004EB0
 */

void ui_draw_unit_text_large(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint8_t *puVar1;

    switch (*(uint8_t *)(DAT_08004f8c + 0xd)) {
    case 2:
        puVar1 = &DAT_08004f90;
        break;
    case 3:
        puVar1 = &DAT_08004f94;
        break;
    case 4:
        puVar1 = &DAT_08004fa0;
        break;
    case 5:
        puVar1 = &DAT_08004f9c;
        break;
    case 6:
        puVar1 = &DAT_08004f98;
        break;
    case 7:
        puVar1 = &DAT_08004fac;
        break;
    case 8:
        puVar1 = &DAT_08004fa8;
        break;
    case 9:
        puVar1 = &DAT_08004fa4;
        break;
    case 10:
        puVar1 = &DAT_08004fb4;
        break;
    case 0xb:
        puVar1 = &DAT_08004fb0;
        break;
    case 0xc:
        puVar1 = &DAT_08004fb8;
        break;
    case 0xd:
        puVar1 = &DAT_08004fc4;
        break;
    case 0xe:
        puVar1 = &DAT_08004fc0;
        break;
    case 0xf:
        puVar1 = &DAT_08004fbc;
        break;
    case 0x10:
        puVar1 = &LAB_08004fc8;
        break;
    default:
        goto switchD_08004ec0_default;
    }
    display_draw_text(param_1, param_2, puVar1, param_3, param_4, 0x18, 0);
switchD_08004ec0_default:
    return;
}

/* ================================================================
 * ui_draw_unit_text_small  @  0x08004FCC
 */

void ui_draw_unit_text_small(void)

{
    uint8_t *puVar1;

    switch (*(uint8_t *)(DAT_080050b0 + 0xd)) {
    case 3:
        puVar1 = &DAT_080050b4;
        break;
    case 4:
        puVar1 = &DAT_080050c0;
        break;
    case 5:
        puVar1 = &DAT_080050bc;
        break;
    case 6:
        puVar1 = &DAT_080050b8;
        break;
    case 7:
        puVar1 = &DAT_080050cc;
        break;
    case 8:
        puVar1 = &DAT_080050c8;
        break;
    case 9:
        puVar1 = &DAT_080050c4;
        break;
    case 10:
        puVar1 = &DAT_080050d4;
        break;
    case 0xb:
        puVar1 = &DAT_080050d0;
        break;
    case 0xc:
        puVar1 = &DAT_080050d8;
        break;
    case 0xd:
        puVar1 = &DAT_080050e4;
        break;
    case 0xe:
        puVar1 = &DAT_080050e0;
        break;
    case 0xf:
        puVar1 = &DAT_080050dc;
        break;
    case 0x10:
        if (*(char *)(DAT_080050e8 + 0x21) == '\0') {
            puVar1 = &DAT_080050f0;
        } else {
            puVar1 = &DAT_080050ec;
        }
        break;
    default:
        goto switchD_08004fde_default;
    }
    display_draw_text_rtl(0xce, 0x1e, puVar1, 0, 0, 0x18, 1);
switchD_08004fde_default:
    return;
}

/* ================================================================
 * ui_draw_unit_label  @  0x080050F4
 * nearby string: "2:UI/cel/"
 */

void ui_draw_unit_label(uint32_t param_1, uint32_t param_2)

{
    uint8_t *puVar1;

    switch (*(uint8_t *)(DAT_080051bc + 0xd)) {
    case 3:
        puVar1 = &DAT_080051c0;
        break;
    case 4:
        puVar1 = &DAT_080051cc;
        break;
    case 5:
        puVar1 = &DAT_080051c8;
        break;
    case 6:
        puVar1 = &DAT_080051c4;
        break;
    case 7:
        puVar1 = &DAT_080051d8;
        break;
    case 8:
        puVar1 = &DAT_080051d4;
        break;
    case 9:
        puVar1 = &DAT_080051d0;
        break;
    case 10:
        puVar1 = &DAT_080051e0;
        break;
    case 0xb:
        puVar1 = &DAT_080051dc;
        break;
    case 0xc:
        puVar1 = &DAT_080051e4;
        break;
    case 0xd:
        puVar1 = &DAT_080051f0;
        break;
    case 0xe:
        puVar1 = &DAT_080051ec;
        break;
    case 0xf:
        puVar1 = &DAT_080051e8;
        break;
    case 0x10:
        if (*(char *)(DAT_080051f4 + 0x21) == '\0') {
            puVar1 = &LAB_080051fc;
        } else {
            puVar1 = &DAT_080051f8;
        }
        break;
    default:
        goto switchD_0800510c_default;
    }
    display_draw_text(param_1, param_2, puVar1, 0xf79e, 0x153f, 0x10, 0);
switchD_0800510c_default:
    return;
}

/* ================================================================
 * ui_draw_led_icon  @  0x0800525C
 * nearby string: " 2:/UI/decorat/led.jpg"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_draw_led_icon(int param_1)

{
    char *pcVar1;

    if (*(char *)(_DAT_0800528c + 0x26) == '\0') {
        if (param_1 == 0) {
            pcVar1 = s_2__UI_decorate_ledoff_jpg_080052c0;
        } else {
            pcVar1 = s_2__UI_decorate_led_jpg_080052a8;
        }
    } else if (param_1 == 0) {
        pcVar1 = s_2__UI_decorat_ledoff_jpg_080052dc;
    } else {
        pcVar1 = s_2__UI_decorat_led_jpg_0800528f + 1;
    }
    ui_load_and_draw_jpeg(pcVar1, 0x5e, 0);
    return;
}

/* ================================================================
 * ui_update_ncv_status  @  0x080052F8
 * nearby string: " 2:/UI/decorat/ncv3.jpg"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_update_ncv_status(void)

{
    uint16_t uVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    char *pcVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    bool bVar8;

    iVar4 = _DAT_0800537c;
    iVar3 = DAT_08005378;
    bVar8 = *(char *)(*(int *)(DAT_08005374 + 4) + 1) == 'L';
    *(bool *)(DAT_08005378 + 7) = bVar8;
    if (bVar8 != (bool)*(char *)(iVar4 + 1)) {
        *(bool *)(iVar4 + 1) = bVar8;
        uVar1 = *(uint16_t *)(iVar3 + 0x1a);
        display_fill_rect(0, 0x5f, 0xf0, 0xd2);
        cVar2 = *(char *)(iVar3 + 0x26);
        if (*(char *)(iVar4 + 1) == '\x01') {
            uVar7 = 0x9e;
            uVar6 = 0;
            if (cVar2 == '\0') {
                pcVar5 = s_2__UI_decorate_ncv0_jpg_080053c8;
            } else {
                pcVar5 = s_2__UI_decorat_ncv0_jpg_080053b0;
                uVar6 = 0;
                uVar7 = 0x9e;
            }
        } else if (cVar2 == '\0') {
            ui_load_and_draw_jpeg(s_2__UI_decorate_ncv3_jpg_080053e0, 0, 0xb9);
            pcVar5 = s_2__UI_decorate_live_jpg_080053f8;
            uVar6 = 0x32;
            uVar7 = 0x69;
        } else {
            ui_load_and_draw_jpeg(s_2__UI_decorat_ncv3_jpg_0800537f + 1, 0, 0xb9);
            pcVar5 = s_2__UI_decorat_live_jpg_08005398;
            uVar6 = 0x32;
            uVar7 = 0x69;
        }
        ui_load_and_draw_jpeg(pcVar5, uVar6, uVar7, uVar1);
        return;
    }
    return;
}

/* ================================================================
 * ui_show_low_battery_warning  @  0x08005410
 * nearby string: "Low battery"
 */

void ui_show_low_battery_warning(void)

{
    uint16_t uVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    char *pcVar5;
    char cVar6;
    uint8_t auStack_2c[8];

    cVar6 = '\n';
    display_draw_rounded_filled_rect(0x13, 0x6c, 0xdc, 0x7a, 4, 0xf800);
    display_fill_rect(0x13, 0x73, 0xdc, 0x8a, 0xf800);
    iVar2 = DAT_08005544;
    display_draw_rounded_filled_rect(0x14, 0x87, 0xdb, 199, 4, *(uint16_t *)(DAT_08005544 + 0x1a));
    display_draw_rounded_rect(0x13, 0x82, 0xdc, 200, 4, 0xf800);
    display_fill_rect(0x1b, 0x75, 0x3d, 0x84, *(uint16_t *)(iVar2 + 0x1a));
    display_fill_rect(0x3e, 0x7a, 0x40, 0x7f, *(uint16_t *)(iVar2 + 0x1a));
    display_draw_text(0x1e, 0x76, &DAT_08005548, 0xf800, 0xf800, 0xc, 1);
    uVar1 = *(uint16_t *)(iVar2 + 0x1c);
    if (*(char *)(iVar2 + 0x20) == '\0') {
        display_draw_text(0x60, 0x74, &DAT_08005568, uVar1, uVar1, 0x10, 1);
        pcVar5 = &DAT_08005570;
    } else {
        display_draw_text(0x4c, 0x74, s_Low_battery_0800554c, uVar1, uVar1, 0x10, 1);
        pcVar5 = s_Shutdown_08005558;
    }
    display_draw_text(0x58, 0xae, pcVar5, 0xf800, 0xf800, 0x10, 1);
    uVar3 = DAT_08005564;
    do {
        pcVar5 = &LAB_08005584;
        while (true) {
            sys_sprintf(auStack_2c, pcVar5, cVar6, 0x73);
            display_draw_text(0x66, 0x91, auStack_2c, 0xf800, *(uint16_t *)(iVar2 + 0x1a), 0x18, 0);
            sys_delay_ms(1000);
            if (cVar6 == '\x01') {
                sys_power_off();
                FUN_08008c90(uVar3, 0x40);
            }
            iVar4 = sys_is_usb_charging();
            if (iVar4 == 1) {
                *(uint8_t *)(iVar2 + 5) = 1;
                return;
            }
            cVar6 = cVar6 + -1;
            if (cVar6 == '\0') {
                return;
            }
            if (cVar6 == '\n')
                break;
            pcVar5 = s__d_c_0800557c;
        }
    } while (true);
}

/* ================================================================
 * FUN_0800558c  @  0x0800558C
 */

void FUN_0800558c(int param_1, int param_2)

{
    int iVar1;
    uint16_t uVar2;

    iVar1 = DAT_080055e4;
    display_draw_rounded_filled_rect(0x37, 0x9c, 0xb9, 0xad, 2, *(uint16_t *)(DAT_080055e4 + 0x1a));
    if (param_2 == 0) {
        uVar2 = *(uint16_t *)(iVar1 + 0x1c);
    } else {
        uVar2 = 0x1c9f;
    }
    display_draw_rounded_filled_rect(0x37, 0x9c, param_1 * 0xd + 0x37, 0xad, 2, uVar2);
    display_draw_rounded_rect(0x37, 0x9b, 0xba, 0xad, 2, 0x3186);
    return;
}

/* ================================================================
 * sys_main_measurement_loop  @  0x080055E8
 */

void sys_main_measurement_loop(void)

{
    uint16_t uVar1;
    uint16_t uVar2;
    byte bVar3;
    char *pcVar4;
    int iVar5;
    byte *pbVar6;
    char cVar7;
    int iVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    char *pcVar11;
    uint8_t *puVar12;
    uint8_t *puVar13;
    char cVar14;
    uint32_t in_r3;
    uint32_t extraout_r3;
    char *pcVar15;
    uint32_t uVar16;
    bool bVar17;
    uint64_t uVar18;
    uint8_t auStack_34[20];
    uint32_t local_20;

    pbVar6 = DAT_08005634;
    iVar5 = DAT_08005630;
    pcVar4 = DAT_0800562c;
    if (DAT_0800562c[1] != '\0') {
        bVar3 = *(byte *)(DAT_08005630 + 0x25);
        *DAT_08005634 = bVar3;
        if (2 < bVar3) {
            *pbVar6 = 0;
        }
        if (0xb < *(byte *)(iVar5 + 0x24)) {
            *(uint8_t *)(iVar5 + 0x24) = 10;
        }
        sys_handle_rotary_input();
        pcVar4[1] = '\0';
        in_r3 = extraout_r3;
    }
    iVar5 = DAT_080057a4;
    pcVar15 = DAT_080057a0;
    pcVar11 = DAT_08004b18;
    if (*pcVar4 == '\0') {
        pcVar15 = DAT_08004b18 + -3;
        *(char **)(DAT_08004b18 + 0x11) = DAT_08004b18;
        sys_auto_shutdown_tick();
        pcVar4 = DAT_08004b20;
        iVar5 = DAT_08004b1c;
        if (pcVar11[2] == '\0') {
            uVar1 = *(uint16_t *)(DAT_08004b1c + 0x1a);
            uVar16 = 0;
        LAB_08004774:
            display_fill_rect(0, uVar16, 0xf0, 0x140, uVar1);
            if ((((*pcVar11 == '\t') || (*pcVar11 == '\b')) && (pcVar11[-1] != '\x02')) ||
                (ui_draw_range_nav_arrows(pcVar11[-1]), pcVar11[-1] != '\x02')) {
                ui_draw_mode_icon(**(uint8_t **)(pcVar11 + 0x11));
                ui_draw_measurement_unit(**(uint8_t **)(pcVar11 + 0x11));
            }
            if (pcVar11[3] == '\0') {
                ui_draw_hold_icon(pcVar4[0xe]);
                ui_draw_battery_icon(*(uint8_t *)(iVar5 + 4));
                ui_draw_led_icon(*(uint8_t *)(iVar5 + 3));
            }
            if (((*pcVar11 != '\t') && (*pcVar11 != '\b')) && (pcVar11[-1] == '\0')) {
                ui_draw_scale_boxes();
                ui_draw_range_nav_arrows(pcVar11[-1]);
            }
            pcVar11[2] = '\x01';
            pcVar11[3] = '\0';
        } else if (pcVar11[3] == '\x01') {
            uVar1 = *(uint16_t *)(DAT_08004b1c + 0x1a);
            uVar16 = 0x24;
            /* goto LAB_08004774; */ (void)0;
        }
        if (pcVar11[-1] != '\x02') {
            sys_handle_mode_switch(*(uint32_t *)(pcVar11 + 0x11));
            if (*pcVar11 == '\t') {
                ui_update_ncv_level_animated();
            } else {
                *pcVar15 = '\0';
            }
            if (*pcVar11 == '\b') {
                ui_update_ncv_status();
            } else {
                pcVar11[-2] = '\0';
            }
            if (*pcVar11 == '\n') {
                uVar10 = *(uint32_t *)(iVar5 + 0x14) & 0x7f800000;
                if (*(char *)(iVar5 + 2) == '\x11') {
                    if (uVar10 == 0) {
                        *(uint32_t *)(iVar5 + 0x14) = *(uint32_t *)(pcVar4 + 8) ^ 0x80000000;
                        uVar1 = *(uint16_t *)(iVar5 + 0x1c);
                        /* goto LAB_08004828; */ (void)0;
                    }
                    *(uint32_t *)(iVar5 + 0x14) = 0;
                } else if (uVar10 != 0) {
                    uVar1 = *(uint16_t *)(iVar5 + 0x1a);
                LAB_08004828:
                    display_draw_arc(DAT_08004b24, 0x9d, 6, 0xfc60, uVar1, 0);
                    /* goto LAB_0800484e; */ (void)0;
                }
            }
            display_fill_rect(0x9d, 6, 0xae, 0x17, *(uint16_t *)(iVar5 + 0x1a));
        }
    LAB_0800484e:
        uVar16 = DAT_08004b2c;
        cVar7 = *(char *)(iVar5 + 2);
        if (cVar7 == '\x06') {
            if ((*pcVar11 != '\t') && (*pcVar11 != '\b')) {
                pcVar11[3] = '\x01';
            }
            if (pcVar11[-1] == '\x02') {
                iVar8 = sensor_touch_query(0xc);
                if (iVar8 == 1) {
                    pcVar11[-1] = '\0';
                    **(uint8_t **)(pcVar11 + 0x11) = 0;
                }
            } else {
                pcVar11[-1] = pcVar11[-1] == '\0';
            }
            if (pcVar4[0xe] == '\x01') {
                pcVar4[0xe] = '\0';
                ui_draw_hold_icon(0);
            }
        } else if (cVar7 == '\n') {
            if (pcVar11[-1] == '\x02') {
                uVar16 = 0;
                cVar7 = **(char **)(pcVar11 + 0x11);
                if (cVar7 == '\0') {
                    uVar16 = 0xc;
                } else if (cVar7 == '\x01') {
                    uVar16 = 0xd;
                } else if (cVar7 == '\x02') {
                    uVar16 = 0xb;
                } else if (cVar7 == '\x03') {
                    uVar16 = 0x14;
                } else if (cVar7 == '\x04') {
                    uVar16 = 0xe;
                } else if (cVar7 == '\x05') {
                    uVar16 = 10;
                } else if (cVar7 == '\x06') {
                    uVar16 = 0xf;
                } else if (cVar7 == '\a') {
                    uVar16 = 0x12;
                } else if (cVar7 == '\b') {
                    uVar16 = 0x13;
                } else if (cVar7 == '\t') {
                    uVar16 = 9;
                } else if (cVar7 == '\n') {
                    uVar16 = 0x10;
                } else if (cVar7 == '\v') {
                    uVar16 = 0x11;
                }
                iVar8 = sensor_touch_query(uVar16);
                if (iVar8 == 1) {
                    cVar7 = pcVar11[5];
                    /* goto LAB_0800493c; */ (void)0;
                }
            } else {
                iVar8 = sensor_touch_query(0x15);
                if (iVar8 == 1) {
                    *pcVar15 = '\0';
                    pcVar11[-2] = '\0';
                    pcVar11[5] = pcVar11[-1];
                    cVar7 = '\x02';
                LAB_0800493c:
                    pcVar11[-1] = cVar7;
                }
            }
            pcVar11[3] = '\x01';
        } else if (cVar7 == '\x0e') {
            *DAT_08004b28 = 1;
            pcVar11[2] = '\0';
            *pcVar15 = '\0';
            pcVar11[-2] = '\0';
        } else if (cVar7 == '\x11') {
            pcVar4[0x18] = '\0';
            pcVar4[0x19] = '\0';
            pcVar4[0x1a] = '\0';
            pcVar4[0x1b] = '\0';
            *(uint32_t *)(pcVar4 + 0x1c) = uVar16;
            uVar16 = DAT_08004b30;
            pcVar4[0x20] = '\0';
            pcVar4[0x21] = '\0';
            pcVar4[0x22] = '\0';
            pcVar4[0x23] = '\0';
            *(uint32_t *)(pcVar4 + 0x24) = uVar16;
        }
        if (*(char *)(iVar5 + 4) != pcVar11[1]) {
            ui_draw_battery_icon();
            pcVar11[1] = *(char *)(iVar5 + 4);
        }
        if (*(char *)(iVar5 + 5) == '\x01') {
            display_fill_rect(0, 0, 0xf0, 0x140, *(uint16_t *)(iVar5 + 0x1a));
            pcVar11[3] = '\x01';
            *(uint8_t *)(iVar5 + 5) = 0;
            *pcVar15 = '\0';
            pcVar11[-2] = '\0';
            pcVar4[0xe] = '\0';
            ui_draw_hold_icon(0);
            ui_draw_led_icon(*(uint8_t *)(iVar5 + 3));
            ui_draw_battery_icon(*(uint8_t *)(iVar5 + 4));
        }
        uVar10 = DAT_08004b38;
        iVar8 = DAT_08004b34;
        cVar7 = *pcVar11;
        bVar17 = cVar7 == '\t';
        do {
            if (bVar17)
                /* goto LAB_08004c24; */ (void)0;
            bVar17 = true;
        } while (cVar7 == '\b');
        if (pcVar11[-1] == '\0') {
            if (*(char *)(iVar5 + 10) == '\x01') {
                *(uint8_t *)(iVar5 + 10) = 0;
                if (cVar7 == '\a') {
                    if (*pcVar4 != '\x01')
                        /* goto LAB_08004a22; */ (void)0;
                    if (*(char *)(iVar5 + 0x21) != '\0') {
                        fs_fat32_time_update(*(uint32_t *)(pcVar4 + 8));
                    }
                    iVar8 = FUN_0800e7f4();
                    if (iVar8 < 0) {
                        iVar8 = -iVar8;
                        pcVar15 = s___04d_08004b3c;
                    } else {
                        pcVar15 = s__04d_08004b44;
                    }
                    sys_sprintf(auStack_34, pcVar15, iVar8);
                LAB_08004a18:
                    puVar12 = auStack_34;
                } else {
                    if ((cVar7 == '\n') && (*pcVar4 == '\x01')) {
                        uVar9 =
                            FUN_0800e5a0(*(uint32_t *)(pcVar4 + 8), *(uint32_t *)(iVar5 + 0x14));
                        if (uVar9 < 0x80800000) {
                            if ((int)uVar9 < iVar8) {
                                uVar18 = FUN_0800e548();
                                pcVar15 = s__0_2f_08004b54;
                            } else {
                                uVar18 = FUN_0800e548();
                                pcVar15 = s__0_1f_08004b4c;
                            }
                        } else if (uVar9 < uVar10) {
                            uVar18 = FUN_0800e548();
                            pcVar15 = s__0_2f_08004b64;
                        } else {
                            uVar18 = FUN_0800e548();
                            pcVar15 = s__0_1f_08004b5c;
                        }
                        sys_sprintf(auStack_34, pcVar15, (int)uVar18,
                                    (int)((uint64_t)uVar18 >> 0x20));
                        /* goto LAB_08004a18; */ (void)0;
                    }
                LAB_08004a22:
                    puVar12 = *(uint8_t **)(pcVar4 + 4);
                }
                FUN_08006d6c(0, 0, puVar12);
                ui_draw_unit_text_small();
                FUN_08007894(0, 0x72);
                if ((*pcVar4 != '\0') && (pcVar4[0x2a] == '\0')) {
                    FUN_08009c88(*pcVar11);
                }
            }
            if (*(char *)(iVar5 + 2) == '\r') {
                FUN_0800b338();
                if (*(char *)(iVar5 + 0x20) == '\0') {
                    pcVar15 = &DAT_08004b78;
                    uVar16 = 0x60;
                } else {
                    pcVar15 = s_Data_saved_08004b6c;
                    uVar16 = 0x50;
                }
                display_draw_text(uVar16, 0x1e, pcVar15, 0x400, *(uint16_t *)(iVar5 + 0x1a), 0x10,
                                  1);
                sys_delay_ms(500);
                if (*(char *)(iVar5 + 0x20) == '\0') {
                    pcVar15 = &DAT_08004b78;
                    uVar16 = 0x60;
                } else {
                    pcVar15 = s_Data_saved_08004b6c;
                    uVar16 = 0x50;
                }
                display_draw_text(uVar16, 0x1e, pcVar15, *(uint16_t *)(iVar5 + 0x1a),
                                  *(uint16_t *)(iVar5 + 0x1a), 0x10, 1);
            }
        } else if (pcVar11[-1] == '\x01') {
            if (*(char *)(iVar5 + 10) == '\x01') {
                if (pcVar11[4] == '\0') {
                    pcVar11[4] = '\r';
                }
                *(uint8_t *)(iVar5 + 10) = 0;
                if (cVar7 == '\a') {
                    if (*pcVar4 != '\x01')
                        /* goto LAB_08004bac; */ (void)0;
                    if (*(char *)(iVar5 + 0x21) != '\0') {
                        fs_fat32_time_update(*(uint32_t *)(pcVar4 + 8));
                    }
                    uVar16 = FUN_0800e7f4();
                    sys_sprintf(auStack_34, s__04d_08004b44, uVar16);
                LAB_08004be0:
                    puVar12 = auStack_34;
                } else {
                    if ((cVar7 == '\n') && (*pcVar4 == '\x01')) {
                        uVar9 =
                            FUN_0800e5a0(*(uint32_t *)(pcVar4 + 8), *(uint32_t *)(iVar5 + 0x14));
                        if ((iVar8 < (int)uVar9) || (uVar10 < uVar9)) {
                            uVar18 = FUN_0800e548();
                            pcVar15 = s__0_1f_08004b5c;
                        } else {
                            uVar18 = FUN_0800e548();
                            pcVar15 = s__0_2f_08004b64;
                        }
                        sys_sprintf(auStack_34, pcVar15, (int)uVar18,
                                    (int)((uint64_t)uVar18 >> 0x20));
                        /* goto LAB_08004be0; */ (void)0;
                    }
                LAB_08004bac:
                    puVar12 = *(uint8_t **)(pcVar4 + 4);
                }
                FUN_08006884(0, 0, puVar12);
                FUN_0800794c();
                ui_draw_unit_label(0x74, 0x32);
                if ((*pcVar4 != '\0') && (pcVar4[0x2a] == '\0')) {
                    FUN_08009c88(*pcVar11);
                }
            }
            if (pcVar11[4] != '\0') {
                FUN_08007380();
                pcVar11[4] = pcVar11[4] + -1;
            }
            FUN_08006fd8();
        }
    LAB_08004c24:
        if ((pcVar11[-1] != '\x02') || (*(char *)(iVar5 + 10) != '\x01'))
            /* goto LAB_08004e00; */ (void)0;
        if (pcVar4[0xc] == '\x02') {
            if (*(char *)(iVar5 + 0x20) == '\0') {
                uVar1 = *(uint16_t *)(iVar5 + 0x1a);
                uVar2 = *(uint16_t *)(iVar5 + 0x1c);
                puVar13 = &DAT_08004e30;
                /* goto LAB_08004caa; */ (void)0;
            }
            uVar1 = *(uint16_t *)(iVar5 + 0x1a);
            uVar2 = *(uint16_t *)(iVar5 + 0x1c);
            uVar16 = DAT_08004e2c;
        LAB_08004c50:
            display_draw_arc(uVar16, 0x55, 0xd0, uVar2, uVar1, 1);
        } else {
            if (*(char *)(iVar5 + 0x20) != '\0') {
                uVar1 = *(uint16_t *)(iVar5 + 0x1a);
                uVar2 = *(uint16_t *)(iVar5 + 0x1c);
                uVar16 = DAT_08004e24;
                /* goto LAB_08004c50; */ (void)0;
            }
            uVar1 = *(uint16_t *)(iVar5 + 0x1a);
            uVar2 = *(uint16_t *)(iVar5 + 0x1c);
            puVar13 = &DAT_08004e3c;
        LAB_08004caa:
            display_draw_text(0x38, 0xd3, puVar13, uVar2, uVar1, 0x20, 0);
        }
        if (pcVar4[0x14] == '\0') {
            if (*(char *)(iVar5 + 0x20) == '\0') {
                uVar1 = *(uint16_t *)(iVar5 + 0x1a);
                uVar2 = *(uint16_t *)(iVar5 + 0x1c);
                puVar13 = &DAT_08004e4c;
                /* goto LAB_08004ce2; */ (void)0;
            }
            uVar1 = *(uint16_t *)(iVar5 + 0x1a);
            uVar2 = *(uint16_t *)(iVar5 + 0x1c);
            uVar16 = DAT_08004e48;
        LAB_08004c70:
            display_draw_arc(uVar16, 0x55, 0x38, uVar2, uVar1, 1);
        } else {
            if (*(char *)(iVar5 + 0x20) != '\0') {
                uVar1 = *(uint16_t *)(iVar5 + 0x1a);
                uVar2 = *(uint16_t *)(iVar5 + 0x1c);
                uVar16 = DAT_08004e28;
                /* goto LAB_08004c70; */ (void)0;
            }
            uVar1 = *(uint16_t *)(iVar5 + 0x1a);
            uVar2 = *(uint16_t *)(iVar5 + 0x1c);
            puVar13 = &DAT_08004e58;
        LAB_08004ce2:
            display_draw_text(0x38, 0x3a, puVar13, uVar2, uVar1, 0x20, 0);
        }
        *(uint8_t *)(iVar5 + 10) = 0;
        if (pcVar4[0x14] == '\0') {
            uVar10 = FUN_0800e5a0(*(uint32_t *)(pcVar4 + 0x10), *(uint32_t *)(iVar5 + 0x14));
            *(uint32_t *)(pcVar4 + 0x10) = uVar10;
        } else {
            uVar10 = *(uint32_t *)(pcVar4 + 0x10);
        }
        if ((DAT_08004e64 < (int)uVar10) || (DAT_08004e68 <= uVar10)) {
            uVar18 = FUN_0800e548();
            pcVar11 = s__0_1f_08004b4c;
        } else {
            uVar18 = FUN_0800e548();
            pcVar11 = s__0_2f_08004b54;
        }
        sys_sprintf(auStack_34, pcVar11, (int)uVar18, (int)((uint64_t)uVar18 >> 0x20));
        uVar16 = 0xffe0;
        FUN_08001a7c(0xdc, 0x1d, &DAT_08004e6c, 0xffe0, *(uint16_t *)(iVar5 + 0x1a), 0x18, 0);
        iVar8 = DAT_08004e70;
        if (*(int *)(pcVar4 + 0x10) < DAT_08004e70) {
            FUN_08006d6c(0, 0, auStack_34);
        }
        FUN_08007894(0, 0x62);
        FUN_08006d6c(0, 0, *(uint32_t *)(pcVar4 + 4));
        FUN_08001a7c(0xdc, 0x1d, &DAT_08004e74, 0xffe0, *(uint16_t *)(iVar5 + 0x1a), 0x18, 0);
        FUN_08007894(0, 0xf8);
        uVar10 = FUN_0800e8c4(*(uint32_t *)(pcVar4 + 0x10), *(uint32_t *)(pcVar4 + 8));
        if (0x807fffff < uVar10) {
            uVar10 = uVar10 ^ 0x80000000;
        }
        if ((int)uVar10 < iVar8) {
            uVar18 = FUN_0800e548();
            pcVar11 = s__03_2f_W_08004e78;
        } else if ((int)uVar10 < DAT_08004e84) {
            FUN_0800e670();
            uVar18 = FUN_0800e548();
            pcVar11 = s__0_3f_KW_08004e88;
        } else if ((int)uVar10 < DAT_08004e94) {
            FUN_0800e670();
            uVar18 = FUN_0800e548();
            pcVar11 = s__0_2f_KW_08004e98;
        } else {
            FUN_0800e670();
            uVar18 = FUN_0800e548();
            pcVar11 = s__0_1f_KW_08004ea4;
        }
        sys_sprintf(auStack_34, pcVar11, (int)uVar18, (int)((uint64_t)uVar18 >> 0x20));
        if (*(char *)(iVar5 + 0x26) != '\0') {
            uVar16 = 0;
        }
        display_draw_text(0x74, 0xaa, auStack_34, uVar16, *(uint16_t *)(iVar5 + 0x1a), 0x10, 0);
    LAB_08004e00:
        if (*(char *)(iVar5 + 2) == '\x02') {
            pcVar4[0xe] = pcVar4[0xe] == '\0';
            ui_draw_hold_icon();
            fs_fat32_mount_notify();
        }
        return;
    }
    local_20 = in_r3;
    if (*DAT_080057a0 == '\0') {
        local_20 = (uint32_t)*(uint16_t *)(DAT_080057a4 + 0x1a);
        display_fill_rect(0, 0, 0xf0, 0x140);
        ui_draw_menu_background();
        local_20 = 0;
        ui_draw_main_menu(1, 1, 0);
        *pcVar15 = '\x01';
        pcVar15[2] = '\0';
        pcVar15[3] = '\0';
        pcVar15[4] = '\0';
    }
    if (*(char *)(iVar5 + 5) == '\x01') {
        local_20 = (uint32_t)*(uint16_t *)(iVar5 + 0x1a);
        display_fill_rect(0, 0, 0xf0, 0x140);
        if (pcVar15[3] == '\0') {
            ui_draw_menu_background();
            cVar7 = pcVar15[4] + '\x01';
            cVar14 = '\0';
        } else {
            ui_draw_menu_background();
            cVar7 = pcVar15[4] + '\x01';
            cVar14 = cVar7;
        }
        local_20 = 0;
        ui_draw_main_menu(1, cVar7, 0, cVar14);
    }
    if (pcVar15[3] == '\0') {
        cVar7 = *(char *)(iVar5 + 2);
        if ((cVar7 == '\x01') || (cVar7 == '\t')) {
            local_20 = 0;
            ui_draw_main_menu(0, 0, pcVar15[4] + '\x01');
            cVar7 = pcVar15[4];
            if (*(char *)(iVar5 + 2) == '\x01') {
                if (cVar7 == '\0') {
                    cVar7 = '\x03';
                } else {
                    cVar7 = cVar7 + -1;
                }
            LAB_080056ec:
                pcVar15[4] = cVar7;
            } else {
                if (cVar7 != '\x03') {
                    cVar7 = cVar7 + '\x01';
                    /* goto LAB_080056ec; */ (void)0;
                }
                pcVar15[4] = '\0';
            }
            local_20 = 0;
            ui_draw_main_menu(0, pcVar15[4] + '\x01', 0);
            ui_draw_settings_page(pcVar15[4]);
            pcVar15[2] = '\0';
            /* goto LAB_08005708; */ (void)0;
        }
        if (cVar7 != '\x05')
            /* goto LAB_0800570e; */ (void)0;
        local_20 = 0;
        ui_draw_main_menu(0, 0, 0, pcVar15[4] + '\x01');
        pcVar15[3] = '\x01';
        pcVar15[1] = '\0';
        *(uint8_t *)(iVar5 + 2) = 0;
    } else {
    LAB_08005708:
        if (pcVar15[3] != '\x01') {
        LAB_0800570e:
            if (*(char *)(iVar5 + 5) != '\x01')
                /* goto LAB_0800578a; */ (void)0;
        }
    }
    cVar7 = pcVar15[4];
    if (cVar7 == '\0') {
        FUN_08008d6c();
    } else if (cVar7 == '\x01') {
        FUN_0800bf70();
    } else if (cVar7 == '\x02') {
        sys_handle_reset_menu();
    } else if ((cVar7 == '\x03') && (*(char *)(iVar5 + 5) == '\x01')) {
        ui_draw_settings_page(4);
        *(uint8_t *)(iVar5 + 5) = 0;
    }
    if (*(char *)(iVar5 + 2) == '\r') {
        local_20 = (uint32_t)(byte)(pcVar15[4] + 1);
        ui_draw_main_menu(0, 0, 0);
        pcVar15[3] = '\0';
    }
LAB_0800578a:
    if (*(char *)(iVar5 + 2) == '\x0e') {
        *DAT_080057a8 = 0;
        iVar5 = DAT_080057ac;
        *pcVar15 = '\0';
        *(uint8_t *)(iVar5 + 0xe) = 0;
    }
    return;
}

/* ================================================================
 * ui_draw_auto_shutdown_menu  @  0x080057B0
 * nearby string: " AUTO shut_down"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_draw_auto_shutdown_menu() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    char cVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    char *pcVar5;
    uint16_t uVar6;
    uint32_t uVar7;

    iVar2 = _DAT_080058fc;
    uVar7 = 0;
    display_fill_rect(0xd, 0x68, 0xdf, 0x134, *(uint16_t *)(_DAT_080058fc + 0x1a), param_3,
                      param_4);
    ui_draw_settings_tab_dots(2);
    if (*(char *)(iVar2 + 0x20) == '\0') {
        pcVar5 = &DAT_08005910;
        uVar3 = 0x58;
    } else {
        pcVar5 = s_AUTO_shut_down_080058ff + 1;
        uVar3 = 0x40;
    }
    display_draw_text(uVar3, 0x78, pcVar5, *(uint16_t *)(iVar2 + 0x1c), 0xf79e, 0x10, 1);
    display_draw_rounded_rect(0x20, 0x98, 0xcf, 0x124, 5, 0x3186);
    do {
        if (*(byte *)(iVar2 + 0x22) == uVar7) {
            iVar4 = uVar7 * 0x1f;
            display_fill_rect(0x3b, iVar4 + 0xa6, 0x4f, iVar4 + 0xb9, 0x1c9f);
            cVar1 = *(char *)(iVar2 + 0x22);
            if (cVar1 == '\0') {
                pcVar5 = &DAT_0800591c;
            LAB_08005862:
                iVar4 = iVar4 + 0xa8;
                uVar6 = 0x1c9f;
                uVar3 = 0x1c9f;
                /* goto LAB_080058ea; */ (void)0;
            }
            if (cVar1 == '\x01') {
                pcVar5 = &DAT_08005920;
                /* goto LAB_08005862; */ (void)0;
            }
            if (cVar1 == '\x02') {
                pcVar5 = s_15min_08005928;
                /* goto LAB_08005862; */ (void)0;
            }
            if (cVar1 == '\x03') {
                pcVar5 = s_30min_08005930;
                /* goto LAB_08005862; */ (void)0;
            }
        } else {
            display_draw_rect_outline(0x3b, uVar7 * 0x1f + 0xa6, 0x4f, uVar7 * 0x1f + 0xb9,
                                      *(uint16_t *)(iVar2 + 0x1c));
            if (uVar7 == 0) {
                uVar6 = *(uint16_t *)(iVar2 + 0x1c);
                iVar4 = 0xa8;
                pcVar5 = &DAT_0800591c;
            } else if (uVar7 == 1) {
                uVar6 = *(uint16_t *)(iVar2 + 0x1c);
                iVar4 = 199;
                pcVar5 = &DAT_08005920;
            } else if (uVar7 == 2) {
                uVar6 = *(uint16_t *)(iVar2 + 0x1c);
                iVar4 = 0xe6;
                pcVar5 = s_15min_08005928;
            } else {
                if (uVar7 != 3)
                    /* goto LAB_080058ee; */ (void)0;
                uVar6 = *(uint16_t *)(iVar2 + 0x1c);
                iVar4 = 0x105;
                pcVar5 = s_30min_08005930;
            }
            uVar3 = 0xf79e;
        LAB_080058ea:
            display_draw_text(0x5c, iVar4, pcVar5, uVar6, uVar3, 0x10, 1);
        }
    LAB_080058ee:
        uVar7 = uVar7 + 1 & 0xff;
        if (3 < uVar7) {
            return;
        }
    } while (true);
}

/* ================================================================
 * ui_draw_language_menu  @  0x08005938
 * nearby string: "Language"
 */

void ui_draw_language_menu() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    uint32_t uVar2;
    char *pcVar3;
    uint16_t uVar4;

    iVar1 = DAT_08005a3c;
    display_fill_rect(0xd, 0x68, 0xdf, 0x139, *(uint16_t *)(DAT_08005a3c + 0x1a), param_3, param_4);
    display_draw_arc(DAT_08005a40, 0x6c, 0x81, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
    ui_draw_settings_tab_dots(0);
    if (*(char *)(iVar1 + 0x20) == '\0') {
        pcVar3 = &DAT_08005a64;
        uVar2 = 0x62;
    } else {
        pcVar3 = s_Language_08005a44;
        uVar2 = 0x5d;
    }
    display_draw_text(uVar2, 0x9e, pcVar3, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10, 1);
    display_draw_rounded_rect(0x2b, 0xc2, 0xcb, 0x10e, 5, 0x3186);
    if (*(char *)(iVar1 + 0x20) == '\0') {
        display_fill_rect(0x41, 0xca, 0x55, 0xde, 0x1c9f);
        display_draw_rect_outline(0x41, 0xf3, 0x55, 0x107, *(uint16_t *)(iVar1 + 0x1c));
        display_draw_text(0x6a, 0xcb, &DAT_08005a50, 0x1c9f, 0x1c9f, 0x10, 1);
        uVar2 = 0xf79e;
        uVar4 = *(uint16_t *)(iVar1 + 0x1c);
    } else {
        display_fill_rect(0x41, 0xf3, 0x55, 0x107, 0x1c9f);
        display_draw_rect_outline(0x41, 0xca, 0x55, 0xde, *(uint16_t *)(iVar1 + 0x1c));
        display_draw_text(0x6a, 0xcb, &DAT_08005a50, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10, 1);
        uVar2 = 0x1c9f;
        uVar4 = 0x1c9f;
    }
    display_draw_text(0x6a, 0xf4, s_English_08005a5c, uVar4, uVar2, 0x10, 1);
    return;
}

/* ================================================================
 * ui_draw_brightness_menu  @  0x08005A6C
 * nearby string: "Brightness"
 */

void ui_draw_brightness_menu() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    char *pcVar2;
    uint16_t uVar3;
    uint32_t uVar4;

    iVar1 = DAT_08005bec;
    display_fill_rect(0xd, 0x68, 0xdf, 0x134, *(uint16_t *)(DAT_08005bec + 0x1a), param_3, param_4);
    FUN_0800558c(*(char *)(iVar1 + 0x23) + '\x01', param_1);
    ui_draw_settings_tab_dots(1);
    uVar4 = 0x3186;
    display_draw_rounded_rect(0x29, 0xf0, 0xc9, 0x129, 5, 0x3186);
    if (*(char *)(iVar1 + 0x21) == '\0') {
        display_fill_rect(0x39, 0x105, 0x4c, 0x118, 0x1c9f, uVar4, param_4);
        display_draw_rect_outline(0x8c, 0x105, 0x9f, 0x118, *(uint16_t *)(iVar1 + 0x1c));
        display_draw_text(0x54, 0x108, &DAT_08005bf0, 0x1c9f, 0x1c9f, 0x10, 1);
        uVar4 = 0xf79e;
        uVar3 = *(uint16_t *)(iVar1 + 0x1c);
    } else {
        display_draw_rect_outline(0x39, 0x105, 0x4c, 0x118, *(uint16_t *)(iVar1 + 0x1c));
        display_fill_rect(0x8c, 0x105, 0x9f, 0x118, 0x1c9f);
        display_draw_text(0x54, 0x108, &DAT_08005bf0, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10, 1);
        uVar4 = 0x1c9f;
        uVar3 = 0x1c9f;
    }
    display_draw_text(0xa9, 0x108, &DAT_08005bf4, uVar3, uVar4, 0x10, 1);
    if (*(char *)(iVar1 + 0x20) == '\0') {
        display_draw_arc(DAT_08005bf8, 0x4f, 0x77, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
        display_draw_arc(DAT_08005bfc, 0x46, 0xd7, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
        display_draw_text(0x74, 0x7c, &DAT_08005c20, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0x10, 1);
        uVar3 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar2 = &DAT_08005c28;
        uVar4 = 0x5e;
    } else {
        display_draw_arc(DAT_08005bf8, 0x3d, 0x77, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
        display_draw_arc(DAT_08005bfc, 0x2f, 0xd7, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
        display_draw_text(0x62, 0x7c, s_Brightness_08005c00, *(uint16_t *)(iVar1 + 0x1c), 0xf79e,
                          0x10, 1);
        uVar3 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar2 = s_Temperature_unit_08005c0c;
        uVar4 = 0x47;
    }
    display_draw_text(uVar4, 0xd9, pcVar2, uVar3, 0xf79e, 0x10, 1);
    return;
}

/* ================================================================
 * ui_handle_settings_nav  @  0x08005C34
 */

void ui_handle_settings_nav() {
    int param_1 = 0;
    int param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    char *pcVar6;
    uint16_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    int iVar12;

    uVar9 = 0;
    uVar11 = 0x11d;
    iVar12 = param_2;
    uVar3 = param_4;
    switch (param_1) {
    default:
        goto switchD_08005c54_caseD_0;
    case 1:
        uVar8 = 0xe1;
        uVar4 = 0xc6;
        /* goto LAB_08005c70; */ (void)0;
    case 2:
        uVar8 = 0x10a;
        uVar4 = 0xef;
    LAB_08005c70:
        uVar5 = 0xb7;
        uVar2 = 0x37;
        break;
    case 3:
        uVar8 = 0xb1;
        uVar5 = 0xcc;
        uVar4 = 0x97;
        uVar2 = 0x29;
        break;
    case 4:
        uVar5 = 0x6e;
        uVar8 = 0x11d;
        uVar4 = 0x101;
        uVar2 = 0x33;
        break;
    case 5:
        uVar5 = 0xc0;
        uVar4 = 0x101;
        uVar2 = 0x85;
        uVar8 = uVar11;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        uVar10 = param_1 - 6;
        do {
            if (uVar10 == uVar9) {
                display_draw_rounded_rect(0x35, uVar9 * 0x1f + 0xa2, 0xba, uVar9 * 0x1f + 0xbc, 3,
                                          0x1c9f);
            }
            uVar9 = uVar9 + 1 & 0xff;
        } while (uVar9 < 4);
        goto switchD_08005c54_caseD_0;
    }
    display_draw_rounded_rect(uVar2, uVar4, uVar5, uVar8, 3, 0x1c9f);
switchD_08005c54_caseD_0:
    iVar1 = DAT_080060c0;
    switch (param_2) {
    default:
        goto switchD_08005cca_caseD_0;
    case 1:
        uVar11 = 0xe1;
        uVar7 = *(uint16_t *)(DAT_080060c0 + 0x1a);
        uVar2 = 0xc6;
        /* goto LAB_08005cea; */ (void)0;
    case 2:
        uVar7 = *(uint16_t *)(DAT_080060c0 + 0x1a);
        uVar11 = 0x10a;
        uVar2 = 0xef;
    LAB_08005cea:
        uVar4 = 0xb7;
        uVar8 = 0x37;
        break;
    case 3:
        uVar7 = *(uint16_t *)(DAT_080060c0 + 0x1a);
        uVar11 = 0xb1;
        uVar4 = 0xcc;
        uVar2 = 0x97;
        uVar8 = 0x29;
        break;
    case 4:
        uVar7 = *(uint16_t *)(DAT_080060c0 + 0x1a);
        uVar4 = 0x6e;
        uVar11 = 0x11d;
        uVar2 = 0x101;
        uVar8 = 0x33;
        break;
    case 5:
        uVar7 = *(uint16_t *)(DAT_080060c0 + 0x1a);
        uVar4 = 0xc0;
        uVar2 = 0x101;
        uVar8 = 0x85;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        uVar9 = 0;
        do {
            if (param_2 - 6U == uVar9) {
                display_draw_rounded_rect(0x35, uVar9 * 0x1f + 0xa2, 0xba, uVar9 * 0x1f + 0xbc, 3,
                                          *(uint16_t *)(iVar1 + 0x1a));
            }
            uVar9 = uVar9 + 1 & 0xff;
        } while (uVar9 < 4);
        goto switchD_08005cca_caseD_0;
    }
    display_draw_rounded_rect(uVar8, uVar2, uVar4, uVar11, 3, uVar7);
switchD_08005cca_caseD_0:
    switch (param_4) {
    default:
        goto switchD_08005d64_caseD_0;
    case 1:
        display_fill_rect(0x41, 0xca, 0x55, 0xde, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x41, 0xca, 0x55, 0xde, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = &DAT_080060c4;
        uVar11 = 0xcb;
        /* goto LAB_08005dd4; */ (void)0;
    case 2:
        display_fill_rect(0x41, 0xf3, 0x55, 0x107, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x41, 0xf3, 0x55, 0x107, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = s_English_080060d0;
        uVar11 = 0xf4;
    LAB_08005dd4:
        uVar8 = 0x6a;
        /* goto LAB_08005dd8; */ (void)0;
    case 3:
        FUN_0800558c(*(char *)(iVar1 + 0x23) + '\x01', 0);
        goto switchD_08005d64_caseD_0;
    case 4:
        display_fill_rect(0x39, 0x105, 0x4c, 0x118, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x39, 0x105, 0x4c, 0x118, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = &DAT_080060d8;
        uVar11 = 0x108;
        uVar8 = 0x54;
        /* goto LAB_08005dd8; */ (void)0;
    case 5:
        display_fill_rect(0x8c, 0x105, 0x9f, 0x118, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x8c, 0x105, 0x9f, 0x118, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = &DAT_080060dc;
        uVar11 = 0x108;
        uVar8 = 0xa9;
        /* goto LAB_08005dd8; */ (void)0;
    case 6:
        display_fill_rect(0x3b, 0xa6, 0x4f, 0xb9, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x3b, 0xa6, 0x4f, 0xb9, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = &DAT_080060e0;
        uVar11 = 0xa8;
        break;
    case 7:
        display_fill_rect(0x3b, 0xc5, 0x4f, 0xd8, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x3b, 0xc5, 0x4f, 0xd8, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = &DAT_080060e4;
        uVar11 = 199;
        break;
    case 8:
        display_fill_rect(0x3b, 0xe4, 0x4f, 0xf7, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x3b, 0xe4, 0x4f, 0xf7, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = s_15min_080060ec;
        uVar11 = 0xe6;
        break;
    case 9:
        display_fill_rect(0x3b, 0x103, 0x4f, 0x116, *(uint16_t *)(iVar1 + 0x1a));
        display_draw_rect_outline(0x3b, 0x103, 0x4f, 0x116, *(uint16_t *)(iVar1 + 0x1c));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = s_30min_080060f4;
        uVar11 = 0x105;
    }
    uVar8 = 0x5c;
LAB_08005dd8:
    display_draw_text(uVar8, uVar11, pcVar6, uVar7, 0xf79e, 0x10, 1);
switchD_08005d64_caseD_0:
    switch (param_3) {
    default:
        break;
    case 1:
        display_fill_rect(0x41, 0xca, 0x55, 0xde, 0x1c9f);
        display_draw_text(0x6a, 0xcb, &DAT_080060c4, 0x1c9f, 0x1c9f, 0x10, 1, param_1, iVar12,
                          param_3, uVar3);
        *(uint8_t *)(iVar1 + 0x20) = 0;
        if (*(char *)(iVar1 + 0x26) == '\0') {
            pcVar6 = s_2__UI_decorate_menu_jpg_08006128;
        } else {
            pcVar6 = s_2__UI_decorat_menu_jpg_080060fc;
        }
        ui_load_and_draw_jpeg(pcVar6, 5, 0x41);
        display_draw_text(0x12, 0x45, &DAT_08006114, 0xf79e, 0xf79e, 0x18, 1);
        display_fill_rect(0x5d, 0x9e, 0x9d, 0xae, *(uint16_t *)(iVar1 + 0x1a));
        uVar7 = 0xf79e;
        pcVar6 = &DAT_08006120;
        uVar3 = 0x62;
        /* goto LAB_0800602a; */ (void)0;
    case 2:
        display_fill_rect(0x41, 0xf3, 0x55, 0x107, 0x1c9f);
        display_draw_text(0x6a, 0xf4, s_English_080060d0, 0x1c9f, 0x1c9f, 0x10, 1);
        *(uint8_t *)(iVar1 + 0x20) = 1;
        if (*(char *)(iVar1 + 0x26) == '\0') {
            pcVar6 = s_2__UI_decorate_menu_jpg_08006128;
        } else {
            pcVar6 = s_2__UI_decorat_menu_jpg_080060fc;
        }
        ui_load_and_draw_jpeg(pcVar6, 5, 0x41);
        display_draw_text(10, 0x48, s_System_settings_08006140, 0xf79e, 0xf79e, 0x10, 1);
        display_fill_rect(0x62, 0x9e, 0x92, 0xae, *(uint16_t *)(iVar1 + 0x1a));
        uVar7 = *(uint16_t *)(iVar1 + 0x1c);
        pcVar6 = s_Language_08006150;
        uVar3 = 0x5d;
    LAB_0800602a:
        display_draw_text(uVar3, 0x9e, pcVar6, uVar7, 0xf79e, 0x10, 1);
        break;
    case 3:
        FUN_0800558c(*(char *)(iVar1 + 0x23) + '\x01', 1);
        return;
    case 4:
        display_fill_rect(0x39, 0x105, 0x4c, 0x118, 0x1c9f);
        display_draw_text(0x54, 0x108, &DAT_080060d8, 0x1c9f, 0x1c9f, 0x10, 1);
        *(uint8_t *)(iVar1 + 0x21) = 0;
        break;
    case 5:
        display_fill_rect(0x8c, 0x105, 0x9f, 0x118, 0x1c9f);
        display_draw_text(0xa9, 0x108, &DAT_080060dc, 0x1c9f, 0x1c9f, 0x10, 1);
        *(uint8_t *)(iVar1 + 0x21) = 1;
        break;
    case 6:
        display_fill_rect(0x3b, 0xa6, 0x4f, 0xb9, 0x1c9f);
        display_draw_text(0x5c, 0xa8, &DAT_080060e0, 0x1c9f, 0x1c9f, 0x10, 1);
        *(uint8_t *)(iVar1 + 0x22) = 0;
        break;
    case 7:
        display_fill_rect(0x3b, 0xc5, 0x4f, 0xd8, 0x1c9f);
        display_draw_text(0x5c, 199, &DAT_080060e4, 0x1c9f, 0x1c9f, 0x10, 1);
        *(uint8_t *)(iVar1 + 0x22) = 1;
        break;
    case 8:
        display_fill_rect(0x3b, 0xe4, 0x4f, 0xf7, 0x1c9f);
        display_draw_text(0x5c, 0xe6, s_15min_080060ec, 0x1c9f, 0x1c9f, 0x10, 1);
        *(uint8_t *)(iVar1 + 0x22) = 2;
        break;
    case 9:
        display_fill_rect(0x3b, 0x103, 0x4f, 0x116, 0x1c9f);
        display_draw_text(0x5c, 0x105, s_30min_080060f4, 0x1c9f, 0x1c9f, 0x10, 1);
        *(uint8_t *)(iVar1 + 0x22) = 3;
    }
    return;
}

/* ================================================================
 * ui_draw_menu_background  @  0x080061D8
 * nearby string: " 2:/UI/decorat/menu.jpg"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_draw_menu_background(void)

{
    char *pcVar1;
    uint32_t in_r3;

    if (*(char *)(_DAT_08006248 + 0x26) == '\0') {
        pcVar1 = s_2__UI_decorate_menu_jpg_08006264;
    } else {
        pcVar1 = s_2__UI_decorat_menu_jpg_0800624b + 1;
    }
    ui_load_and_draw_jpeg(pcVar1, 5, 0x41, in_r3, in_r3);
    display_draw_line(0xec, 0x5d, 0xec, 0x138, 0x3186);
    display_draw_line(0xec, 0x138, 0xe7, 0x13d, 0x3186);
    display_draw_line(0xe7, 0x13d, 0xc, 0x13d, 0x3186);
    display_draw_line(0xc, 0x13d, 5, 0x138, 0x3186);
    display_draw_line(5, 0x138, 5, 0x47, 0x3186);
    return;
}

/* ================================================================
 * ui_update_ncv_level_animated  @  0x0800627C
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ui_update_ncv_level_animated(void)

{
    char cVar1;
    int iVar2;
    byte *pbVar3;
    byte bVar4;
    int iVar5;
    char *pcVar6;
    uint8_t auStack_2c[32];

    pbVar3 = _DAT_080065ac;
    iVar2 = DAT_080065a8;
    iVar5 = *(int *)(DAT_080065a4 + 4);
    if (*(char *)(iVar5 + 4) == '-') {
        bVar4 = 4;
    } else if (*(char *)(iVar5 + 2) == '-') {
        bVar4 = 3;
    } else if (*(char *)(iVar5 + 1) == '-') {
        bVar4 = 2;
    } else {
        bVar4 = 1;
    }
    *(byte *)(DAT_080065a8 + 6) = bVar4;
    iVar5 = DAT_080065a8;
    if (bVar4 != *pbVar3) {
        *pbVar3 = bVar4;
        cVar1 = *(char *)(iVar5 + 0x26);
        if (bVar4 == 1) {
            if (cVar1 == '\0') {
                ui_load_and_draw_jpeg(s_2__UI_decorate_ncv0_jpg_08006670, 0, 0x9e);
                display_fill_rect(7, 0x83, 0x24, 0x99, *(uint16_t *)(iVar2 + 0x1a));
                display_fill_rect(0xca, 0x83, 0xe7, 0x99, *(uint16_t *)(iVar2 + 0x1a));
                ui_load_and_draw_jpeg(s_2__UI_decorate_ncv1_3_jpg_08006688, 0x46, 0x8a);
                ui_load_and_draw_jpeg(s_2__UI_decorate_ncv1_4_jpg_080066a4, 0x46, 0xbb);
                ui_load_and_draw_jpeg(s_2__UI_decorate_ncv1_2_jpg_080066c0, 0x2b, 0x76);
                ui_load_and_draw_jpeg(s_2__UI_decorate_ncv1_5_jpg_080066dc, 0x2b, 0xd0);
                ui_load_and_draw_jpeg(s_2__UI_decorate_ncv1_1_jpg_080066f8, 0x14, 0x60);
                pcVar6 = s_2__UI_decorate_ncv1_6_jpg_08006714;
            } else {
                ui_load_and_draw_jpeg(s_2__UI_decorat_ncv0_jpg_080065af + 1, 0, 0x9e);
                display_fill_rect(7, 0x83, 0x24, 0x99, *(uint16_t *)(iVar2 + 0x1a));
                display_fill_rect(0xca, 0x83, 0xe7, 0x99, *(uint16_t *)(iVar2 + 0x1a));
                ui_load_and_draw_jpeg(s_2__UI_decorat_ncv1_3_jpg_080065c8, 0x46, 0x8a);
                ui_load_and_draw_jpeg(s_2__UI_decorat_ncv1_4_jpg_080065e4, 0x46, 0xbb);
                ui_load_and_draw_jpeg(s_2__UI_decorat_ncv1_2_jpg_08006600, 0x2b, 0x76);
                ui_load_and_draw_jpeg(s_2__UI_decorat_ncv1_5_jpg_0800661c, 0x2b, 0xd0);
                ui_load_and_draw_jpeg(s_2__UI_decorat_ncv1_1_jpg_08006638, 0x14, 0x60);
                pcVar6 = s_2__UI_decorat_ncv1_6_jpg_08006654;
            }
            ui_load_and_draw_jpeg(pcVar6, 0x14, 0xe4);
        } else {
            if (bVar4 == 2) {
                if (cVar1 == '\0') {
                    ui_load_and_draw_jpeg(s_2__UI_decorate_ncv1_jpg_08006774, 0, 0x9e);
                    ui_load_and_draw_jpeg(s_2__UI_decorate_lig_jpg_0800678c, 7, 0x83);
                    ui_load_and_draw_jpeg(s_2__UI_decorate_lig_jpg_0800678c, 0xca, 0x83);
                    pcVar6 = s_2__UI_decorate_ncv1__080067a4;
                } else {
                    ui_load_and_draw_jpeg(s_2__UI_decorat_ncv1_jpg_08006730, 0, 0x9e);
                    ui_load_and_draw_jpeg(s_2__UI_decorat_lig_jpg_08006748, 7, 0x83);
                    ui_load_and_draw_jpeg(s_2__UI_decorat_lig_jpg_08006748, 0xca, 0x83);
                    pcVar6 = s_2__UI_decorat_ncv1__08006760;
                }
            } else if (bVar4 == 3) {
                if (cVar1 == '\0') {
                    ui_load_and_draw_jpeg(s_2__UI_decorate_ncv2_jpg_080067e8, 0, 0x9e);
                    ui_load_and_draw_jpeg(s_2__UI_decorate_lig_jpg_0800678c, 7, 0x83);
                    ui_load_and_draw_jpeg(s_2__UI_decorate_lig_jpg_0800678c, 0xca, 0x83);
                    pcVar6 = s_2__UI_decorate_ncv2__08006800;
                } else {
                    ui_load_and_draw_jpeg(s_2__UI_decorat_ncv2_jpg_080067bc, 0, 0x9e);
                    ui_load_and_draw_jpeg(s_2__UI_decorat_lig_jpg_08006748, 7, 0x83);
                    ui_load_and_draw_jpeg(s_2__UI_decorat_lig_jpg_08006748, 0xca, 0x83);
                    pcVar6 = s_2__UI_decorat_ncv2__080067d4;
                }
            } else {
                if (bVar4 != 4)
                    /* goto LAB_08006464; */ (void)0;
                if (cVar1 == '\0') {
                    ui_load_and_draw_jpeg(s_2__UI_decorate_ncv3_jpg_0800684b + 1, 0, 0x9e);
                    ui_load_and_draw_jpeg(s_2__UI_decorate_lig_jpg_0800678c, 7, 0x83);
                    ui_load_and_draw_jpeg(s_2__UI_decorate_lig_jpg_0800678c, 0xca, 0x83);
                    pcVar6 = s_2__UI_decorate_ncv3__08006864;
                } else {
                    ui_load_and_draw_jpeg(s_2__UI_decorat_ncv3_jpg_08006818, 0, 0x9e);
                    ui_load_and_draw_jpeg(s_2__UI_decorat_lig_jpg_08006748, 7, 0x83);
                    ui_load_and_draw_jpeg(s_2__UI_decorat_lig_jpg_08006748, 0xca, 0x83);
                    pcVar6 = s_2__UI_decorat_ncv3__08006830;
                }
            }
            sys_sprintf(_DAT_08006848, &DAT_08006844, pcVar6);
        }
    }
LAB_08006464:
    if (1 < *pbVar3) {
        if (pbVar3[9] == 1) {
            display_fill_rect(0x11, 0x5b, 0xe3, 0x74, *(uint16_t *)(iVar2 + 0x1a));
            display_fill_rect(0x2c, 0x75, 199, 0x88, *(uint16_t *)(iVar2 + 0x1a));
            display_fill_rect(0x47, 0x86, 0xab, 0x98, *(uint16_t *)(iVar2 + 0x1a));
            display_fill_rect(0x47, 0xbb, 0xa8, 0xcc, *(uint16_t *)(iVar2 + 0x1a));
            display_fill_rect(0x2b, 0xcd, 199, 0xde, *(uint16_t *)(iVar2 + 0x1a));
            display_fill_rect(0xf, 0xe1, 0xe4, 0xf7, *(uint16_t *)(iVar2 + 0x1a));
            sys_sprintf(auStack_2c, &LAB_0800687c, _DAT_08006848,
                        s_2__UI_decorate_ncv1_3_jpg_08006688 + 0x14);
            ui_load_and_draw_jpeg(auStack_2c, 0x46, 0x8a);
        }
        if (pbVar3[9] == 2) {
            sys_sprintf(auStack_2c, &LAB_0800687c, _DAT_08006848,
                        s_2__UI_decorate_ncv1_4_jpg_080066a4 + 0x14);
            ui_load_and_draw_jpeg(auStack_2c, 0x46, 0xbb);
        }
        if (pbVar3[9] == 3) {
            sys_sprintf(auStack_2c, &LAB_0800687c, _DAT_08006848,
                        s_2__UI_decorate_ncv1_2_jpg_080066c0 + 0x14);
            ui_load_and_draw_jpeg(auStack_2c, 0x2b, 0x76);
        }
        if (pbVar3[9] == 4) {
            sys_sprintf(auStack_2c, &LAB_0800687c, _DAT_08006848,
                        s_2__UI_decorate_ncv1_5_jpg_080066dc + 0x14);
            ui_load_and_draw_jpeg(auStack_2c, 0x2b, 0xd0);
        }
        if (pbVar3[9] == 5) {
            sys_sprintf(auStack_2c, &LAB_0800687c, _DAT_08006848,
                        s_2__UI_decorate_ncv1_1_jpg_080066f8 + 0x14);
            ui_load_and_draw_jpeg(auStack_2c, 0x14, 0x60);
        }
        bVar4 = pbVar3[9];
        if (bVar4 == 6) {
            sys_sprintf(auStack_2c, &LAB_0800687c, _DAT_08006848,
                        s_2__UI_decorate_ncv1_6_jpg_08006714 + 0x14);
            ui_load_and_draw_jpeg(auStack_2c, 0x14, 0xe4);
            bVar4 = 0;
            pbVar3[9] = 0;
        }
        pbVar3[9] = bVar4 + 1;
    }
    return;
}

/* ================================================================
 * FUN_08006884  @  0x08006884
 */

void FUN_08006884() {
    uint32_t param_1 = 0;
    int param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    char cVar1;
    byte bVar2;
    short sVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint16_t uVar11;
    uint16_t uVar12;

    uVar4 = 0;
    for (uVar10 = 0; cVar1 = *(char *)(param_3 + uVar10), cVar1 != '\0';
         uVar10 = uVar10 + 1 & 0xff) {
        sVar3 = (short)uVar4;
        if (cVar1 == '.') {
            uVar12 = sVar3 + 6;
        LAB_080068a0:
            uVar4 = (uint32_t)uVar12;
        } else {
            if (cVar1 == '-') {
                if (uVar10 != 0)
                    /* goto LAB_0800689e; */ (void)0;
                uVar12 = sVar3 + 0x12;
                /* goto LAB_080068a0; */ (void)0;
            }
            if (cVar1 != ' ') {
            LAB_0800689e:
                uVar12 = sVar3 + 0x19;
                /* goto LAB_080068a0; */ (void)0;
            }
        }
    }
    uVar10 = 0;
    uVar4 = (int)(0x6e - uVar4) / 2 + 5U & 0xffff;
    do {
        bVar2 = *(byte *)(param_3 + uVar10);
        if (bVar2 == 0) {
            return;
        }
        uVar5 = DAT_08006a00;
        if (bVar2 == 0x35)
            /* goto LAB_0800691e; */ (void)0;
        if (0x35 < bVar2) {
            uVar5 = DAT_08006a10;
            if (bVar2 == 0x39)
                /* goto LAB_0800691e; */ (void)0;
            if (0x39 < bVar2) {
                if (bVar2 != 0x4c) {
                    if (bVar2 == 0x4f)
                        goto switchD_080068e4_caseD_30;
                    goto switchD_080068e4_caseD_2f;
                }
                uVar11 = *(uint16_t *)(DAT_08006a14 + 0x1a);
                uVar5 = DAT_08006a18;
                /* goto LAB_08006924; */ (void)0;
            }
            uVar5 = DAT_08006a04;
            if (((bVar2 == 0x36) || (uVar5 = DAT_08006a08, bVar2 == 0x37)) ||
                (uVar5 = DAT_08006a0c, bVar2 == 0x38))
                /* goto LAB_0800691e; */ (void)0;
            goto switchD_080068e4_caseD_2f;
        }
        switch (bVar2) {
        case 0x2d:
            uVar6 = param_2 + 0xd;
            uVar7 = uVar4 + 0xf;
            uVar8 = param_2 + 10;
            uVar9 = uVar4 + 5 & 0xffff;
            /* goto LAB_080069ac; */ (void)0;
        case 0x2e:
            uVar6 = param_2 + 0x17;
            uVar7 = uVar4 + 3;
            uVar8 = param_2 + 0x15;
            uVar9 = uVar4;
        LAB_080069ac:
            display_fill_rect_masked(uVar9, uVar8 & 0xffff, uVar7 & 0xffff, uVar6 & 0xffff, 0xf79e,
                                     param_4);
        default:
            goto switchD_080068e4_caseD_2f;
        case 0x30:
        switchD_080068e4_caseD_30:
            uVar5 = DAT_080069ec;
            break;
        case 0x31:
            uVar5 = DAT_080069f0;
            break;
        case 0x32:
            uVar5 = DAT_080069f4;
            break;
        case 0x33:
            uVar5 = DAT_080069f8;
            break;
        case 0x34:
            uVar5 = DAT_080069fc;
        }
    LAB_0800691e:
        uVar11 = 0xf79e;
    LAB_08006924:
        param_4 = 1;
        display_draw_arc_solid(uVar5, uVar4, param_2, uVar11, 0x153f, 1);
    switchD_080068e4_caseD_2f:
        cVar1 = *(char *)(param_3 + uVar10);
        sVar3 = (short)uVar4;
        if (cVar1 == '.') {
            uVar12 = sVar3 + 6;
        LAB_080069c0:
            uVar4 = (uint32_t)uVar12;
        } else {
            if (cVar1 == '-') {
                if (uVar10 != 0)
                    /* goto LAB_080069be; */ (void)0;
                uVar12 = sVar3 + 0x16;
                /* goto LAB_080069c0; */ (void)0;
            }
            if (cVar1 != ' ') {
            LAB_080069be:
                uVar12 = sVar3 + 0x17;
                /* goto LAB_080069c0; */ (void)0;
            }
        }
        uVar10 = uVar10 + 1 & 0xff;
    } while (true);
}

/* ================================================================
 * FUN_08006a1c  @  0x08006A1C
 */

void FUN_08006a1c() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    byte bVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint16_t uVar8;
    uint16_t uVar9;
    uint32_t uVar10;
    uint16_t uVar11;

    iVar2 = DAT_08006bb4;
    uVar10 = 0;
    do {
        bVar1 = *(byte *)(param_3 + uVar10);
        if (bVar1 == 0) {
            return;
        }
        if (bVar1 == 0x34) {
            uVar11 = *(uint16_t *)(iVar2 + 0x1a);
            param_4 = 1;
            uVar8 = *(uint16_t *)(iVar2 + 0x1c);
            uVar3 = DAT_08006bc8;
            /* goto LAB_08006a96; */ (void)0;
        }
        if (bVar1 < 0x35) {
            if (bVar1 == 0x30) {
            LAB_08006a78:
                uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                param_4 = 1;
                uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                uVar3 = DAT_08006bb8;
                /* goto LAB_08006a96; */ (void)0;
            }
            if (0x30 < bVar1) {
                if (bVar1 == 0x31) {
                    uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                    param_4 = 1;
                    uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                    uVar3 = DAT_08006bbc;
                } else if (bVar1 == 0x32) {
                    uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                    param_4 = 1;
                    uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                    uVar3 = DAT_08006bc0;
                } else {
                    if (bVar1 != 0x33)
                        /* goto LAB_08006b68; */ (void)0;
                    uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                    param_4 = 1;
                    uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                    uVar3 = DAT_08006bc4;
                }
                /* goto LAB_08006a96; */ (void)0;
            }
            if (bVar1 == 0x20) {
                uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                uVar4 = param_2 + 0xb;
                uVar5 = param_1 + 9;
                uVar7 = param_2;
            LAB_08006baa:
                uVar4 = uVar4 & 0xffff;
                uVar6 = param_1;
            } else {
                if (bVar1 != 0x2d) {
                    if (bVar1 != 0x2e)
                        /* goto LAB_08006b68; */ (void)0;
                    display_fill_rect(param_1, param_2, param_1 + 5 & 0xffff,
                                      param_2 + 0xd & 0xffff, *(uint16_t *)(iVar2 + 0x1a), param_4);
                    uVar11 = *(uint16_t *)(iVar2 + 0x1c);
                    uVar4 = param_2 + 0xc;
                    uVar5 = param_1 + 2;
                    uVar7 = param_2 + 10 & 0xffff;
                    /* goto LAB_08006baa; */ (void)0;
                }
                uVar11 = *(uint16_t *)(iVar2 + 0x1c);
                uVar9 = (short)param_2 + 6;
                uVar5 = param_1 + 8;
                uVar4 = (uint32_t)uVar9;
                uVar7 = (uint32_t)uVar9;
                uVar6 = param_1 + 3 & 0xffff;
            }
            display_fill_rect(uVar6, uVar7, uVar5 & 0xffff, uVar4, uVar11, param_4);
        } else {
            if (bVar1 == 0x38) {
                uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                param_4 = 1;
                uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                uVar3 = DAT_08006bd8;
            } else if (bVar1 < 0x39) {
                if (bVar1 == 0x35) {
                    uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                    param_4 = 1;
                    uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                    uVar3 = DAT_08006bcc;
                } else if (bVar1 == 0x36) {
                    uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                    param_4 = 1;
                    uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                    uVar3 = DAT_08006bd0;
                } else {
                    if (bVar1 != 0x37)
                        /* goto LAB_08006b68; */ (void)0;
                    uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                    param_4 = 1;
                    uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                    uVar3 = DAT_08006bd4;
                }
            } else {
                if (bVar1 != 0x39) {
                    if (bVar1 == 0x4c) {
                        uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                        param_4 = 0x32;
                        uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                        uVar3 = DAT_08006be0;
                        /* goto LAB_08006a96; */ (void)0;
                    }
                    if (bVar1 == 0x4f)
                        /* goto LAB_08006a78; */ (void)0;
                    /* goto LAB_08006b68; */ (void)0;
                }
                uVar11 = *(uint16_t *)(iVar2 + 0x1a);
                param_4 = 1;
                uVar8 = *(uint16_t *)(iVar2 + 0x1c);
                uVar3 = DAT_08006bdc;
            }
        LAB_08006a96:
            display_draw_arc(uVar3, param_1, param_2, uVar8, uVar11, param_4);
        }
    LAB_08006b68:
        if (*(char *)(param_3 + uVar10) == '.') {
            uVar9 = (short)param_1 + 5;
        } else {
            uVar9 = (short)param_1 + 9;
        }
        param_1 = (uint32_t)uVar9;
        uVar10 = uVar10 + 1 & 0xff;
    } while (true);
}

/* ================================================================
 * FUN_08006be4  @  0x08006BE4
 */

void FUN_08006be4() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t param_5 = 0;
    byte bVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint16_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;

    uVar8 = 0;
    uVar9 = param_4;
    do {
        bVar1 = *(byte *)(param_3 + uVar8);
        if (bVar1 == 0) {
            return;
        }
        uVar2 = DAT_08006d50;
        if (bVar1 == 0x34)
            /* goto LAB_08006c58; */ (void)0;
        if (bVar1 < 0x35) {
            uVar2 = DAT_08006d40;
            if (bVar1 == 0x30)
                /* goto LAB_08006c58; */ (void)0;
            if (bVar1 < 0x31) {
                if (bVar1 == 0x20) {
                    uVar3 = param_1 + 10;
                    uVar5 = param_2;
                    uVar6 = param_2 + 0xd;
                    uVar2 = param_5;
                LAB_08006d36:
                    uVar6 = uVar6 & 0xffff;
                    uVar4 = param_1;
                } else {
                    uVar2 = param_4;
                    if (bVar1 != 0x2d) {
                        if (bVar1 != 0x2e)
                            /* goto LAB_08006cf8; */ (void)0;
                        display_fill_rect(param_1, param_2, param_1 + 5 & 0xffff,
                                          param_2 + 0xd & 0xffff, param_5, uVar9);
                        uVar3 = param_1 + 2;
                        uVar5 = param_2 + 10 & 0xffff;
                        uVar6 = param_2 + 0xc;
                        /* goto LAB_08006d36; */ (void)0;
                    }
                    uVar7 = (short)param_2 + 6;
                    uVar3 = param_1 + 8;
                    uVar6 = (uint32_t)uVar7;
                    uVar5 = (uint32_t)uVar7;
                    uVar4 = param_1 + 3 & 0xffff;
                }
                display_fill_rect(uVar4, uVar5, uVar3 & 0xffff, uVar6, uVar2, uVar9);
            } else {
                uVar2 = DAT_08006d44;
                if (((bVar1 == 0x31) || (uVar2 = DAT_08006d48, bVar1 == 0x32)) ||
                    (uVar2 = DAT_08006d4c, bVar1 == 0x33))
                    /* goto LAB_08006c58; */ (void)0;
            }
        } else {
            uVar2 = DAT_08006d60;
            if (bVar1 == 0x38) {
            LAB_08006c58:
                uVar9 = 1;
            } else {
                if (bVar1 < 0x39) {
                    uVar2 = DAT_08006d54;
                    if (((bVar1 != 0x35) && (uVar2 = DAT_08006d58, bVar1 != 0x36)) &&
                        (uVar2 = DAT_08006d5c, bVar1 != 0x37))
                        /* goto LAB_08006cf8; */ (void)0;
                    /* goto LAB_08006c58; */ (void)0;
                }
                uVar2 = DAT_08006d64;
                if (bVar1 == 0x39)
                    /* goto LAB_08006c58; */ (void)0;
                if (bVar1 != 0x4c) {
                    uVar2 = DAT_08006d40;
                    if (bVar1 != 0x4f)
                        /* goto LAB_08006cf8; */ (void)0;
                    /* goto LAB_08006c58; */ (void)0;
                }
                uVar9 = 0x32;
                uVar2 = DAT_08006d68;
            }
            display_draw_arc(uVar2, param_1, param_2, param_4, param_5, uVar9);
        }
    LAB_08006cf8:
        if (*(char *)(param_3 + uVar8) == '.') {
            uVar7 = (short)param_1 + 6;
        } else {
            uVar7 = (short)param_1 + 0xb;
        }
        param_1 = (uint32_t)uVar7;
        uVar8 = uVar8 + 1 & 0xff;
    } while (true);
}

/* ================================================================
 * FUN_08006d6c  @  0x08006D6C
 */

void FUN_08006d6c() {
    uint32_t param_1 = 0;
    int param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    char cVar1;
    byte bVar2;
    short sVar3;
    int iVar4;
    short sVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint16_t uVar12;
    uint16_t uVar13;

    iVar4 = DAT_08006f08;
    uVar6 = 0;
    for (uVar11 = 0; cVar1 = *(char *)(param_3 + uVar11), cVar1 != '\0';
         uVar11 = uVar11 + 1 & 0xff) {
        sVar3 = (short)uVar6;
        if (cVar1 == '.') {
            uVar13 = sVar3 + 6;
        LAB_08006d88:
            uVar6 = (uint32_t)uVar13;
        } else {
            if (cVar1 == '-') {
                if (uVar11 != 0)
                    /* goto LAB_08006d86; */ (void)0;
                uVar13 = sVar3 + 0x1e;
                /* goto LAB_08006d88; */ (void)0;
            }
            if (cVar1 != ' ') {
            LAB_08006d86:
                uVar13 = sVar3 + 0x2b;
                /* goto LAB_08006d88; */ (void)0;
            }
        }
    }
    uVar11 = 0;
    uVar6 = ((0xdc - uVar6) - ((int)(0xdc - uVar6) >> 0x1f) & 0x1ffff) >> 1;
    do {
        bVar2 = *(byte *)(param_3 + uVar11);
        if (bVar2 == 0) {
            return;
        }
        sVar3 = (short)uVar6;
        if (bVar2 == 0x35) {
            uVar12 = *(uint16_t *)(iVar4 + 0x1a);
            uVar7 = DAT_08006f20;
            /* goto LAB_08006e10; */ (void)0;
        }
        if (0x35 < bVar2) {
            if (bVar2 == 0x39) {
                uVar12 = *(uint16_t *)(iVar4 + 0x1a);
                uVar7 = DAT_08006f30;
            } else if (bVar2 < 0x3a) {
                if (bVar2 == 0x36) {
                    uVar12 = *(uint16_t *)(iVar4 + 0x1a);
                    uVar7 = DAT_08006f24;
                } else if (bVar2 == 0x37) {
                    uVar12 = *(uint16_t *)(iVar4 + 0x1a);
                    uVar7 = DAT_08006f28;
                } else {
                    if (bVar2 != 0x38)
                        goto switchD_08006dca_caseD_2f;
                    uVar12 = *(uint16_t *)(iVar4 + 0x1a);
                    uVar7 = DAT_08006f2c;
                }
            } else {
                if (bVar2 != 0x4c) {
                    if (bVar2 == 0x4f)
                        goto switchD_08006dca_caseD_30;
                    goto switchD_08006dca_caseD_2f;
                }
                uVar12 = *(uint16_t *)(iVar4 + 0x1a);
                uVar7 = DAT_08006f34;
            }
            /* goto LAB_08006e10; */ (void)0;
        }
        switch (bVar2) {
        case 0x2d:
            uVar8 = param_2 + 0x19;
            uVar9 = uVar6 + 0x14;
            uVar10 = param_2 + 0x14;
            sVar5 = sVar3 + 3;
            /* goto LAB_08006ec2; */ (void)0;
        case 0x2e:
            uVar8 = param_2 + 0x33;
            uVar9 = uVar6 + 4;
            uVar10 = param_2 + 0x2d;
            sVar5 = sVar3 + -2;
        LAB_08006ec2:
            display_fill_rect_masked(sVar5, uVar10 & 0xffff, uVar9 & 0xffff, uVar8 & 0xffff, 0xf79e,
                                     param_4);
        default:
            goto switchD_08006dca_caseD_2f;
        case 0x30:
        switchD_08006dca_caseD_30:
            uVar12 = *(uint16_t *)(iVar4 + 0x1a);
            uVar7 = DAT_08006f0c;
            break;
        case 0x31:
            uVar12 = *(uint16_t *)(iVar4 + 0x1a);
            uVar7 = DAT_08006f10;
            break;
        case 0x32:
            uVar12 = *(uint16_t *)(iVar4 + 0x1a);
            uVar7 = DAT_08006f14;
            break;
        case 0x33:
            uVar12 = *(uint16_t *)(iVar4 + 0x1a);
            uVar7 = DAT_08006f18;
            break;
        case 0x34:
            uVar12 = *(uint16_t *)(iVar4 + 0x1a);
            uVar7 = DAT_08006f1c;
        }
    LAB_08006e10:
        param_4 = 0x32;
        display_draw_arc_solid(uVar7, uVar6, param_2, uVar12, 0xf79e, 0x32);
    switchD_08006dca_caseD_2f:
        cVar1 = *(char *)(param_3 + uVar11);
        if (cVar1 == '.') {
            uVar13 = sVar3 + 0xe;
        LAB_08006ed8:
            uVar6 = (uint32_t)uVar13;
        } else {
            if (cVar1 == '-') {
                if (uVar11 != 0)
                    /* goto LAB_08006ed6; */ (void)0;
                uVar13 = sVar3 + 0x1e;
                /* goto LAB_08006ed8; */ (void)0;
            }
            if (cVar1 != ' ') {
            LAB_08006ed6:
                uVar13 = sVar3 + 0x2b;
                /* goto LAB_08006ed8; */ (void)0;
            }
        }
        uVar11 = uVar11 + 1 & 0xff;
    } while (true);
}

/* ================================================================
 * FUN_08006fd8  @  0x08006FD8
 */

uint64_t FUN_08006fd8() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    byte bVar1;
    uint16_t uVar2;
    int iVar3;
    int iVar4;
    char *pcVar5;
    uint32_t uVar6;
    uint32_t *puVar7;
    uint32_t local_28;
    uint32_t uStack_24;
    uint32_t uStack_20;
    uint32_t uStack_1c;

    iVar4 = DAT_08007104;
    iVar3 = DAT_08007100;
    if (*(char *)(DAT_08007100 + 0xe) == -1) {
        *(uint8_t *)(DAT_08007100 + 0xe) = 0;
        *(uint16_t *)(iVar4 + 0xc) = 0;
    }
    local_28 = param_1;
    uStack_24 = param_2;
    if (*(char *)(iVar3 + 2) != '\r')
        /* goto LAB_080070fa; */ (void)0;
    uStack_20 = param_3;
    uStack_1c = param_4;
    FUN_0800b338();
    pcVar5 = DAT_08007108;
    FUN_0800a618(DAT_08007108[0xd], 0x1c9f, 0xde, (uint32_t)*(byte *)(iVar3 + 0xe) * 0x15 + 0x57);
    if ((*(char *)(iVar3 + 0x21) == '\x01') && (*(char *)(iVar4 + 3) == '\a')) {
        uVar6 = fs_fat32_time_update(*(uint32_t *)(pcVar5 + 8));
        *(uint32_t *)(pcVar5 + 8) = uVar6;
    }
    if (*pcVar5 == '\0') {
        uVar2 = *(uint16_t *)(iVar3 + 0x1a);
        bVar1 = *(byte *)(iVar3 + 0xe);
        puVar7 = *(uint32_t **)(pcVar5 + 4);
    } else {
        if (*(char *)(iVar4 + 3) == '\n') {
            uVar6 = FUN_0800e5a0(*(uint32_t *)(pcVar5 + 8), *(uint32_t *)(iVar3 + 0x14));
            *(uint32_t *)(pcVar5 + 8) = uVar6;
        } else {
            uVar6 = *(uint32_t *)(pcVar5 + 8);
        }
        measure_format_value(uVar6, &uStack_24);
        uVar2 = *(uint16_t *)(iVar3 + 0x1a);
        bVar1 = *(byte *)(iVar3 + 0xe);
        puVar7 = &uStack_24;
    }
    FUN_08006be4(0xa0, (uint32_t)bVar1 * 0x15 + 0x54, puVar7, 0x1c9f);
    if (*(byte *)(iVar3 + 0xe) == 0) {
        if (*(short *)(iVar4 + 0xc) != 0) {
            FUN_0800a618(*(uint8_t *)(iVar4 + 10), *(uint16_t *)(iVar3 + 0x1c), 0xde);
            /* goto LAB_080070ac; */ (void)0;
        }
    } else {
        *(uint16_t *)(iVar4 + 0xc) = (uint16_t)*(byte *)(iVar3 + 0xe) * 0x15 + 0x42;
        FUN_0800a618(*(uint8_t *)(iVar4 + 10), *(uint16_t *)(iVar3 + 0x1c), 0xde);
        *(uint16_t *)(iVar4 + 0xe) = (uint16_t)*(byte *)(iVar3 + 0xe) * 0x15 + 0x3f;
    LAB_080070ac:
        measure_format_value(*(uint32_t *)(pcVar5 + 8), &uStack_24);
        uVar2 = *(uint16_t *)(iVar3 + 0x1a);
        FUN_08006be4(0xa0, *(uint16_t *)(iVar4 + 0xe), DAT_08007104 + 0x18,
                     *(uint16_t *)(iVar3 + 0x1c));
    }
    local_28 = (uint32_t)uVar2;
    *(uint16_t *)(iVar4 + 10) = (uint16_t)(byte)pcVar5[0xd];
    if (*pcVar5 == '\0') {
        puVar7 = *(uint32_t **)(pcVar5 + 4);
    } else {
        puVar7 = &uStack_24;
    }
    FUN_0800055e(DAT_08007104 + 0x18, puVar7);
    bVar1 = *(byte *)(iVar3 + 0xe);
    if (bVar1 < 7) {
        *(byte *)(iVar3 + 0xe) = bVar1 + 1;
        if (bVar1 != 0xff)
            /* goto LAB_080070fa; */ (void)0;
    } else {
        *(uint8_t *)(iVar3 + 0xe) = 0;
    }
    *(uint16_t *)(iVar4 + 0xc) = 0xea;
    *(uint16_t *)(iVar4 + 0xe) = 0xe7;
LAB_080070fa:
    return CONCAT44(uStack_24, local_28);
}

/* ================================================================
 * ui_language_select_screen  @  0x0800710C
 * nearby string: "English"
 */

void ui_language_select_screen() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    uint16_t *puVar2;
    int iVar3;
    uint32_t uVar4;
    char *pcVar5;
    uint16_t uVar6;
    uint16_t uVar7;

    uVar6 = 0;
    display_fill_rect(0, 0, 0xf0, 0x140, 0, param_3, param_4);
    display_draw_rect_outline(0x41, 0xa5, 0x55, 0xb9, 0xf79e);
    display_draw_rect_outline(0x41, 0x7c, 0x55, 0x90, 0xf79e);
    display_draw_text(0x6a, 0x7d, &DAT_080072bc, 0xf79e, 0xf79e, 0x10, 1);
    display_draw_text(0x6a, 0xa6, s_English_080072c8, 0xf79e, 0xf79e, 0x10, 1);
    display_draw_rounded_rect(0x38, 0x77, 0xb8, 0x93, 3, 0x1c9f);
    uVar4 = DAT_080072d4;
    iVar1 = DAT_080072d0;
    do {
        iVar3 = FUN_08008d5e(uVar4, 0x10);
        if ((iVar3 == 0) || (iVar3 = FUN_08008d5e(uVar4, 0x80), iVar3 == 0)) {
            sys_delay_ms(10);
            iVar3 = FUN_08008d5e(uVar4, 0x10);
            if ((iVar3 == 0) || (iVar3 = FUN_08008d5e(uVar4, 0x80), iVar3 == 0)) {
                if (uVar6 == 0) {
                    display_draw_rounded_rect(0x38, 0x77, 0xb8, 0x93, 3,
                                              *(uint16_t *)(iVar1 + 0x1a));
                    uVar7 = 0x1c9f;
                } else {
                    display_draw_rounded_rect(0x38, 0x77, 0xb8, 0x93, 3, 0x1c9f);
                    uVar7 = *(uint16_t *)(iVar1 + 0x1a);
                }
                uVar6 = (uint16_t)(uVar6 == 0);
                display_draw_rounded_rect(0x38, 0xa0, 0xb8, 0xbc, 3, uVar7);
                do {
                    iVar3 = FUN_08008d5e(uVar4, 0x10);
                } while (iVar3 == 0);
                do {
                    iVar3 = FUN_08008d5e(uVar4, 0x80);
                } while (iVar3 == 0);
            }
        }
        iVar3 = FUN_08008d5e(uVar4, 0x40);
        if (iVar3 == 0) {
            sys_delay_ms(10);
            iVar3 = FUN_08008d5e(uVar4, 0x40);
            if (iVar3 == 0) {
                if (uVar6 == 0) {
                    display_fill_rect(0x41, 0x7c, 0x55, 0x90, 0x1c9f);
                    pcVar5 = &DAT_080072bc;
                    uVar4 = 0x7d;
                } else {
                    display_fill_rect(0x41, 0xa5, 0x55, 0xb9, 0x1c9f);
                    pcVar5 = s_English_080072c8;
                    uVar4 = 0xa6;
                }
                display_draw_text(0x6a, uVar4, pcVar5, 0x1c9f, 0xf79e, 0x10, 1);
                sys_delay_ms(100);
                puVar2 = DAT_080072dc;
                *DAT_080072dc = 0;
                puVar2[1] = uVar6;
                *(char *)(iVar1 + 0x20) = (char)uVar6;
                *(uint8_t *)(iVar1 + 2) = 0xe;
                return;
            }
        }
        iVar3 = FUN_08008d5e(DAT_080072d8, 0x80);
        if (iVar3 == 0) {
            sys_delay_ms(10);
            iVar3 = FUN_08008d5e(DAT_080072d8, 0x80);
            if (iVar3 == 0) {
                sys_power_off();
            }
        }
    } while (true);
}

/* ================================================================
 * ui_language_input_handler  @  0x0800721C
 * nearby string: "English"
 */

void ui_language_input_handler(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                               uint32_t param_4)

{
    uint16_t *puVar1;
    int iVar2;
    uint32_t uVar3;
    char *pcVar4;
    int unaff_r4;
    int unaff_r11;

    do {
        display_draw_rounded_rect(0x38, param_2, param_3, param_4);
        while (true) {
            display_draw_rounded_rect(0x38, 0xa0, 0xb8, 0xbc);
            do {
                iVar2 = FUN_08008d5e();
            } while (iVar2 == 0);
            do {
                iVar2 = FUN_08008d5e();
            } while (iVar2 == 0);
            do {
                do {
                    iVar2 = FUN_08008d5e();
                    if (iVar2 == 0) {
                        sys_delay_ms(10);
                        iVar2 = FUN_08008d5e();
                        if (iVar2 == 0) {
                            if (unaff_r4 == 0) {
                                display_fill_rect(0x41, 0x7c, 0x55, 0x90);
                                pcVar4 = &DAT_080072bc;
                                uVar3 = 0x7d;
                            } else {
                                display_fill_rect(0x41, 0xa5, 0x55, 0xb9);
                                pcVar4 = s_English_080072c8;
                                uVar3 = 0xa6;
                            }
                            display_draw_text(0x6a, uVar3, pcVar4);
                            sys_delay_ms(100);
                            puVar1 = DAT_080072dc;
                            *DAT_080072dc = 0;
                            puVar1[1] = (short)unaff_r4;
                            *(char *)(unaff_r11 + 0x20) = (char)unaff_r4;
                            *(uint8_t *)(unaff_r11 + 2) = 0xe;
                            return;
                        }
                    }
                    iVar2 = FUN_08008d5e(DAT_080072d8, 0x80);
                    if (iVar2 == 0) {
                        sys_delay_ms(10);
                        iVar2 = FUN_08008d5e(DAT_080072d8, 0x80);
                        if (iVar2 == 0) {
                            sys_power_off();
                        }
                    }
                    iVar2 = FUN_08008d5e();
                } while ((iVar2 != 0) && (iVar2 = FUN_08008d5e(), iVar2 != 0));
                sys_delay_ms(10);
                iVar2 = FUN_08008d5e();
            } while ((iVar2 != 0) && (iVar2 = FUN_08008d5e(), iVar2 != 0));
            if (unaff_r4 == 0)
                break;
            unaff_r4 = 0;
            display_draw_rounded_rect(0x38, 0x77, 0xb8, 0x93);
        }
        unaff_r4 = 1;
        param_4 = 0x93;
        param_3 = 0xb8;
        param_2 = 0x77;
    } while (true);
}

/* ================================================================
 * ui_language_confirm_screen  @  0x08007236
 * nearby string: "English"
 */

void ui_language_confirm_screen(void)

{
    uint16_t *puVar1;
    int iVar2;
    uint32_t uVar3;
    char *pcVar4;
    uint32_t unaff_r4;
    int unaff_r11;

    while (iVar2 = FUN_08008d5e(), iVar2 != 0) {
        do {
            iVar2 = FUN_08008d5e(DAT_080072d8, 0x80);
            if (iVar2 == 0) {
                sys_delay_ms(10);
                iVar2 = FUN_08008d5e(DAT_080072d8, 0x80);
                if (iVar2 == 0) {
                    sys_power_off();
                }
            }
            iVar2 = FUN_08008d5e();
            if ((iVar2 == 0) || (iVar2 = FUN_08008d5e(), iVar2 == 0)) {
                sys_delay_ms(10);
                iVar2 = FUN_08008d5e();
                if ((iVar2 == 0) || (iVar2 = FUN_08008d5e(), iVar2 == 0)) {
                    if (unaff_r4 == 0) {
                        display_draw_rounded_rect(0x38, 0x77, 0xb8, 0x93);
                    } else {
                        display_draw_rounded_rect(0x38, 0x77, 0xb8, 0x93);
                    }
                    unaff_r4 = (uint32_t)(unaff_r4 == 0);
                    display_draw_rounded_rect(0x38, 0xa0, 0xb8, 0xbc);
                    do {
                        iVar2 = FUN_08008d5e();
                    } while (iVar2 == 0);
                    do {
                        iVar2 = FUN_08008d5e();
                    } while (iVar2 == 0);
                }
            }
            iVar2 = FUN_08008d5e();
        } while (iVar2 != 0);
        sys_delay_ms(10);
    }
    if (unaff_r4 == 0) {
        display_fill_rect(0x41, 0x7c, 0x55, 0x90);
        pcVar4 = &DAT_080072bc;
        uVar3 = 0x7d;
    } else {
        display_fill_rect(0x41, 0xa5, 0x55, 0xb9);
        pcVar4 = s_English_080072c8;
        uVar3 = 0xa6;
    }
    display_draw_text(0x6a, uVar3, pcVar4);
    sys_delay_ms(100);
    puVar1 = DAT_080072dc;
    *DAT_080072dc = 0;
    puVar1[1] = (short)unaff_r4;
    *(char *)(unaff_r11 + 0x20) = (char)unaff_r4;
    *(uint8_t *)(unaff_r11 + 2) = 0xe;
    return;
}

/* ================================================================
 * ui_draw_settings_tab_dots  @  0x080072E0
 * nearby string: "DMC-100  V1.4"
 */

void ui_draw_settings_tab_dots(uint32_t param_1)

{
    uint32_t uVar1;
    uint32_t uVar2;

    uVar2 = 0;
    do {
        if (uVar2 == param_1) {
            uVar1 = 0x1c9f;
        } else {
            uVar1 = 0x3186;
        }
        display_draw_circle(uVar2 * 9 + 0x73, 0x131, 3, uVar1);
        uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 3);
    return;
}

/* ================================================================
 * ui_draw_settings_page  @  0x08007318
 * nearby string: "DMC-100  V1.4"
 */

void ui_draw_settings_page() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint16_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    char *pcVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;

    iVar3 = DAT_0800736c;
    iVar2 = DAT_08003ec8;
    if (param_1 != 0) {
        if (param_1 == 1) {
            ui_draw_language_menu(1, param_2, param_3, param_4);
            return;
        }
        if (param_1 == 2) {
            display_fill_rect(0xd, 0x68, 0xe3, 0x139, *(uint16_t *)(DAT_08003ec8 + 0x1a), param_3,
                              param_4);
            if (*(char *)(iVar2 + 0x20) == '\0') {
                display_draw_text(0x4a, 0x7d, &DAT_08003ef4, 0xfc60, 0xfc60, 0x18, 1);
                display_draw_text(0x51, 0x83, &DAT_08003ed8, *(uint16_t *)(iVar2 + 0x1a),
                                  *(uint16_t *)(iVar2 + 0x1a), 0x10, 1);
                display_draw_text(0x38, 0xa5, &DAT_08003efc, *(uint16_t *)(iVar2 + 0x1c), 0xf79e,
                                  0x10, 1);
                uVar1 = *(uint16_t *)(iVar2 + 0x1c);
                pcVar5 = &DAT_08003f10;
                uVar4 = 0x38;
            } else {
                display_draw_text(0x3e, 0x7d, &DAT_08003ecc, 0xfc60, 0xfc60, 0x18, 1);
                display_draw_text(0x45, 0x83, &DAT_08003ed8, *(uint16_t *)(iVar2 + 0x1a),
                                  *(uint16_t *)(iVar2 + 0x1a), 0x10, 1);
                display_draw_text(0x54, 0xa5, s_Reset_all_08003edc, *(uint16_t *)(iVar2 + 0x1c),
                                  0xf79e, 0x10, 1);
                uVar1 = *(uint16_t *)(iVar2 + 0x1c);
                pcVar5 = s_settings____08003ee8;
                uVar4 = 0x4c;
            }
            uVar8 = 1;
            uVar7 = 0x10;
            uVar6 = 0xf79e;
            display_draw_text(uVar4, 0xbf, pcVar5, uVar1);
            ui_draw_reset_return_button(0, uVar6, uVar7, uVar8);
            return;
        }
        display_fill_rect(0xd, 0x68, 0xdf, 0x139, *(uint16_t *)(DAT_0800736c + 0x1a));
        ui_draw_about_screen(0x24, 0x96);
        display_draw_text(0x41, 0xeb, s_DMC_100_V1_4_08007370, *(uint16_t *)(iVar3 + 0x1c), 0xf79e,
                          0x10, 1);
    }
    return;
}

/* ================================================================
 * FUN_08007380  @  0x08007380
 */

uint64_t FUN_08007380() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    byte bVar1;
    int iVar2;
    int iVar3;
    byte *pbVar4;
    uint16_t uVar5;
    uint16_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t *puVar11;
    int *piVar12;
    uint32_t *puVar13;
    uint32_t uVar14;
    uint32_t uVar15;
    uint32_t uVar16;
    uint32_t uVar17;
    char cVar18;
    uint64_t uVar19;
    uint64_t uVar20;
    uint64_t uVar21;

    iVar3 = DAT_0800758c;
    iVar2 = DAT_08007588;
    uVar15 = DAT_08007584;
    uVar17 = DAT_08007580;
    uVar16 = 0;
    uVar6 = *(uint16_t *)(DAT_08007588 + 0x1a);
    uVar14 = 0;
    uVar10 = 0;
    do {
        uVar7 = 0;
        do {
            *(uint16_t *)(iVar3 + uVar10 * 0x13c + uVar7 * 2) = uVar6;
            uVar7 = uVar7 + 1 & 0xffff;
        } while (uVar7 < 0x9e);
        uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < 10);
    if (*(uint16_t *)(iVar2 + 0xc) < 0x9e) {
        uVar10 = 0xffffffff;
    } else {
        uVar10 = (uint32_t)*(uint16_t *)(DAT_08007590 + 2);
    }
    for (uVar7 = 0; cVar18 = uVar7 <= *(uint16_t *)(DAT_08007588 + 0xc),
        uVar7 < *(uint16_t *)(DAT_08007588 + 0xc);
         uVar7 = uVar7 + 1 & 0xffff) {
        puVar11 = (uint32_t *)(DAT_08007594 + uVar7 * 8);
        FUN_0800e2f0(*puVar11, puVar11[1], uVar16, uVar17, param_1, param_2, param_3, param_4);
        if (cVar18 == '\0') {
            uVar16 = *puVar11;
            uVar17 = puVar11[1];
        }
        FUN_0800e07c(*puVar11, puVar11[1], uVar14, uVar15);
        if (cVar18 == '\0') {
            uVar14 = *puVar11;
            uVar15 = puVar11[1];
        }
    }
    uVar19 = FUN_0800e374(uVar16, uVar17, uVar14, uVar15);
    uVar17 = (uint32_t)((uint64_t)uVar19 >> 0x20);
    FUN_0800e2f0((int)uVar19, uVar17, DAT_08007598, DAT_0800759c, param_1, param_2, param_3,
                 param_4);
    if (cVar18 == '\0') {
        uVar19 = FUN_0800dd1c(0, DAT_080075a0, (int)uVar19, uVar17);
    } else {
        uVar19 = 0;
    }
    iVar2 = DAT_08007588;
    uVar17 = (uint32_t)((uint64_t)uVar19 >> 0x20);
    for (uVar7 = 0; pbVar4 = DAT_08007590, uVar9 = (uint32_t)*(uint16_t *)(iVar2 + 0xc),
        (int)uVar7 < (int)(uVar9 - 2);
         uVar7 = uVar7 + 1 & 0xffff) {
        puVar11 = (uint32_t *)(DAT_08007594 + ((int)(uVar10 + 1) % 0x9e) * 8);
        uVar20 = FUN_0800e374(*puVar11, puVar11[1], uVar14, uVar15);
        uVar20 = FUN_0800e0f4((int)uVar20, (int)((uint64_t)uVar20 >> 0x20), (int)uVar19, uVar17);
        uVar20 = FUN_0800e35c((int)uVar20, (int)((uint64_t)uVar20 >> 0x20), 0, DAT_080075a4);
        puVar11 = (uint32_t *)(DAT_08007594 + ((int)(uVar10 + 2) % 0x9e) * 8);
        uVar21 = FUN_0800e374(*puVar11, puVar11[1], uVar14, uVar15);
        uVar21 = FUN_0800e0f4((int)uVar21, (int)((uint64_t)uVar21 >> 0x20), (int)uVar19, uVar17);
        FUN_0800e35c((int)uVar21, (int)((uint64_t)uVar21 >> 0x20), 0, DAT_080075a4);
        uVar5 = FUN_0800dfcc();
        param_2 = (uint32_t)((uint64_t)uVar20 >> 0x20);
        uVar8 = (uint32_t)uVar5;
        uVar6 = FUN_0800dfcc((int)uVar20, param_2);
        param_1 = (uint32_t)*(uint16_t *)(iVar2 + 0x1c);
        uVar9 = (0x9e - uVar9) + uVar7;
        display_draw_line_aa(uVar9 & 0xffff, uVar6, uVar9 + 1 & 0xffff, uVar8);
        uVar10 = uVar10 + 1;
    }
    display_set_address_window(0, (uint32_t)*DAT_08007590 * 10 + 0x50, 0x9b,
                               (uint32_t)*DAT_08007590 * 10 + 0x5a);
    iVar2 = DAT_080075a8;
    FUN_0800bb28(DAT_080075a8, 1);
    uVar17 = DAT_080075ac;
    FUN_08008c90(DAT_080075ac, 0x4000);
    uVar10 = 0;
    piVar12 = (int *)(DAT_080075a8 + 8);
    puVar13 = (uint32_t *)(DAT_080075a8 + 0xc);
    do {
        uVar7 = 0;
        do {
            do {
            } while (-1 < *piVar12 << 0x1e);
            *puVar13 = (uint32_t)*(uint16_t *)(iVar3 + uVar10 * 0x13c + uVar7 * 2);
            uVar7 = uVar7 + 1 & 0xffff;
        } while (uVar7 < 0x9c);
        uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < 10);
    sys_delay_cycles(10);
    FUN_08008c94(uVar17, 0x4000);
    FUN_0800bb28(iVar2, 0);
    bVar1 = *pbVar4;
    *pbVar4 = bVar1 + 1;
    if (0xc < (byte)(bVar1 + 1)) {
        *pbVar4 = 0;
    }
    return CONCAT44(param_2, param_1);
}

/* ================================================================
 * FUN_080075b0  @  0x080075B0
 */

void FUN_080075b0(uint32_t *param_1, uint32_t param_2)

{
    *param_1 = *param_1 & 0xfffffffe | param_2 & 1;
    return;
}

/* ================================================================
 * FUN_080075bc  @  0x080075BC
 */

void FUN_080075bc(void)

{
    int iVar1;
    uint32_t local_20;
    uint32_t local_1c;
    uint16_t local_18;
    uint16_t local_16;
    uint8_t local_14;
    uint8_t local_13;
    uint8_t local_12;
    uint8_t local_11;
    uint8_t local_10;
    uint8_t local_f;

    gpio_write(0x140000, 1);
    FUN_0800a9fc(0xb, 0);
    iVar1 = DAT_0800763c;
    FUN_08007838(DAT_0800763c);
    FUN_080076dc(&local_20);
    local_16 = 0x14;
    local_1c = DAT_08007640;
    local_20 = DAT_08007644;
    local_11 = 1;
    local_13 = 1;
    local_f = 2;
    local_12 = 1;
    local_10 = 1;
    local_18 = 0;
    local_14 = 0;
    FUN_080077a6(iVar1, &local_20);
    FUN_08007738(DAT_0800763c + -8, 1);
    FUN_08007802(iVar1, 2, 1);
    FUN_080075b0(iVar1, 1);
    return;
}

/* ================================================================
 * FUN_08007648  @  0x08007648
 */

void FUN_08007648(void)

{
    int iVar1;
    int local_20;
    uint32_t local_1c;
    uint16_t local_18;
    uint16_t local_16;
    uint8_t local_14;
    uint8_t local_13;
    uint8_t local_12;
    uint8_t local_11;
    uint8_t local_10;
    uint8_t local_f;

    gpio_write(0x140000, 1);
    iVar1 = DAT_080076d0;
    FUN_08007838(DAT_080076d0);
    FUN_080076dc(&local_20);
    local_16 = 0xf;
    local_11 = 0;
    local_1c = DAT_080076d4;
    local_13 = 1;
    local_12 = 0;
    local_18 = 0;
    local_20 = DAT_080076d8;
    local_14 = 0;
    local_f = 1;
    local_10 = 1;
    FUN_080077a6(iVar1, &local_20);
    FUN_08007738(DAT_080076d0 + -0x58, 5, 0x19);
    FUN_0800a9fc(0xf, 0);
    FUN_08007802(iVar1, 2, 1);
    FUN_080075b0(iVar1, 1);
    FUN_0800c4a0(DAT_080076d8 + -4, 1);
    return;
}

/* ================================================================
 * FUN_080076dc  @  0x080076DC
 */

void FUN_080076dc(uint32_t *param_1)

{
    *param_1 = 0;
    param_1[1] = 0;
    *(uint16_t *)(param_1 + 2) = 0;
    *(uint16_t *)((int)param_1 + 10) = 0;
    *(uint8_t *)(param_1 + 3) = 0;
    *(uint8_t *)((int)param_1 + 0xd) = 0;
    *(uint8_t *)((int)param_1 + 0xe) = 0;
    *(uint8_t *)((int)param_1 + 0xf) = 0;
    *(uint8_t *)(param_1 + 4) = 0;
    *(uint8_t *)((int)param_1 + 0x11) = 0;
    return;
}

/* ================================================================
 * FUN_080076f4  @  0x080076F4
 */

void FUN_080076f4(uint32_t param_1)

{
    if (0x10000000 < param_1) {
        *DAT_0800770c = param_1 & 0xfffffff;
        return;
    }
    *(uint32_t *)(DAT_08007710 + 4) = param_1;
    return;
}

/* ================================================================
 * FUN_08007714  @  0x08007714
 */

bool FUN_08007714(uint32_t param_1)

{
    uint32_t *puVar1;

    puVar1 = DAT_08007734;
    if (0x10000000 < param_1) {
        puVar1 = DAT_08007730;
    }
    return (*puVar1 & param_1) != 0;
}

/* ================================================================
 * FUN_08007738  @  0x08007738
 */

void FUN_08007738() {
    int param_1 = 0;
    int param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t *puVar1;
    uint32_t uVar2;

    if (-1 < *(int *)(param_1 + 0xa4) << 7) {
        *(uint32_t *)(param_1 + 0xa4) = *(uint32_t *)(param_1 + 0xa4) | 0x1000000;
    }
    if (param_2 == 1) {
        puVar1 = (uint32_t *)(param_1 + 0xa0);
        uVar2 = *puVar1;
    LAB_08007796:
        uVar2 = uVar2 & 0xffffff00 | param_3 & 0xff;
    } else {
        if (param_2 == 2) {
            puVar1 = (uint32_t *)(param_1 + 0xa0);
            uVar2 = *puVar1;
        LAB_080077a0:
            uVar2 = uVar2 & 0xffff00ff | (param_3 & 0xff) << 8;
            /* goto LAB_0800777e; */ (void)0;
        }
        if (param_2 == 3) {
            puVar1 = (uint32_t *)(param_1 + 0xa0);
            uVar2 = *puVar1;
        } else {
            if (param_2 == 4) {
                puVar1 = (uint32_t *)(param_1 + 0xa0);
                uVar2 = *puVar1 & 0xffffff | param_3 << 0x18;
                /* goto LAB_0800777e; */ (void)0;
            }
            if (param_2 == 5) {
                puVar1 = (uint32_t *)(param_1 + 0xa4);
                uVar2 = *puVar1;
                /* goto LAB_08007796; */ (void)0;
            }
            if (param_2 == 6) {
                puVar1 = (uint32_t *)(param_1 + 0xa4);
                uVar2 = *puVar1;
                /* goto LAB_080077a0; */ (void)0;
            }
            if (param_2 != 7) {
                return;
            }
            puVar1 = (uint32_t *)(param_1 + 0xa4);
            uVar2 = *puVar1;
        }
        uVar2 = uVar2 & 0xff00ffff | (param_3 & 0xff) << 0x10;
    }
LAB_0800777e:
    *puVar1 = uVar2;
    return;
}

/* ================================================================
 * FUN_080077a6  @  0x080077A6
 */

void FUN_080077a6(uint32_t *param_1, uint32_t *param_2)

{
    *param_1 = *param_1 & 0xbfef;
    *param_1 = *param_1 | (uint32_t)(uint16_t)param_2[2];
    *param_1 = *param_1 & 0xffffcfff | (*(byte *)((int)param_2 + 0x11) & 3) << 0xc;
    *param_1 = *param_1 & 0xfffff3ff | (*(byte *)((int)param_2 + 0xf) & 3) << 10;
    *param_1 = *param_1 & 0xfffffcff | (*(byte *)((int)param_2 + 0xe) & 3) << 8;
    *param_1 = *param_1 & 0xffffff7f | (*(byte *)((int)param_2 + 0xd) & 1) << 7;
    *param_1 = *param_1 & 0xffffffbf | ((byte)param_2[3] & 1) << 6;
    *param_1 = *param_1 & 0xffffffdf | ((byte)param_2[4] & 1) << 5;
    param_1[1] = (uint32_t)*(uint16_t *)((int)param_2 + 10);
    param_1[2] = *param_2;
    param_1[3] = param_2[1];
    return;
}

/* ================================================================
 * FUN_08007802  @  0x08007802
 */

void FUN_08007802(uint32_t *param_1, uint32_t param_2, int param_3)

{
    if (param_3 == 0) {
        param_2 = *param_1 & ~param_2;
    } else {
        param_2 = *param_1 | param_2;
    }
    *param_1 = param_2;
    return;
}

/* ================================================================
 * FUN_08007814  @  0x08007814
 */

bool FUN_08007814(uint32_t param_1)

{
    uint32_t *puVar1;

    puVar1 = DAT_08007834;
    if (0x10000000 < param_1) {
        puVar1 = DAT_08007830;
    }
    return (*puVar1 & param_1) != 0;
}

/* ================================================================
 * FUN_08007838  @  0x08007838
 */

void FUN_08007838(uint32_t *param_1)

{
    uint32_t uVar1;

    *param_1 = *param_1 & 0xfffffffe;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    uVar1 = ((uint32_t)param_1 & 0xff) - 8;
    if (((uint32_t)param_1 & 0x4ff) < 0x408) {
        *(uint32_t *)(DAT_0800788c + 4) =
            0xf << ((uVar1 / 0x14 & 0x3f) << 2) | *(uint32_t *)(DAT_0800788c + 4);
    } else if (((uint32_t)param_1 & 0x4ff) < 0x488) {
        *DAT_08007890 = 0xf << ((uVar1 / 0x14 & 0x3f) << 2) | *DAT_08007890;
        return;
    }
    return;
}

/* ================================================================
 * FUN_08007894  @  0x08007894
 */

void FUN_08007894(int param_1, int param_2)

{
    uint16_t uVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    int iVar4;
    int iVar5;
    uint32_t *puVar6;
    uint16_t uVar7;
    uint32_t uVar8;
    int *piVar9;
    uint32_t *puVar10;
    uint64_t uVar11;

    display_set_address_window(param_1, param_2, param_1 + 0xf0U & 0xffff,
                               param_2 + 0x40U & 0xffff);
    iVar4 = DAT_0800793c;
    FUN_0800bb28(DAT_0800793c, 1);
    FUN_08008c90(DAT_08007940, 0x4000);
    iVar5 = DAT_08007944;
    uVar7 = 0;
    piVar9 = (int *)(DAT_0800793c + 8);
    uVar1 = *(uint16_t *)(DAT_08007948 + 0x1a);
    uVar2 = *(uint16_t *)(DAT_08007948 + 0x1c);
    puVar10 = (uint32_t *)(DAT_0800793c + 0xc);
    do {
        uVar8 = 0;
        uVar11 = FUN_080003f8(1, 0, uVar7);
        do {
            do {
            } while (-1 < *piVar9 << 0x1e);
            puVar6 = (uint32_t *)(iVar5 + uVar8 * 8);
            uVar3 = uVar1;
            if ((*puVar6 & (uint32_t)uVar11) != 0 ||
                (puVar6[1] & (uint32_t)((uint64_t)uVar11 >> 0x20)) != 0) {
                uVar3 = uVar2;
            }
            *puVar10 = (uint32_t)uVar3;
            uVar8 = uVar8 + 1 & 0xffff;
        } while (uVar8 < 0xf0);
        uVar7 = uVar7 + 1;
    } while (uVar7 < 0x33);
    sys_delay_cycles(10);
    FUN_08008c94(DAT_08007940, 0x4000);
    FUN_0800bb28(iVar4, 0);
    FUN_080006e8(DAT_08007944, 0x788);
    return;
}

/* ================================================================
 * FUN_0800794c  @  0x0800794C
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800794c(void)

{
    int iVar1;
    int iVar2;
    uint32_t *puVar3;
    uint16_t uVar4;
    uint32_t uVar5;
    int *piVar6;
    uint32_t *puVar7;
    uint64_t uVar8;

    display_set_address_window(3, 0x29, 0x72, 0x44);
    iVar1 = DAT_080079ec;
    FUN_0800bb28(DAT_080079ec, 1);
    FUN_08008c90(DAT_080079f0, 0x4000);
    iVar2 = _FUN_080079f4;
    uVar4 = 0;
    piVar6 = (int *)(DAT_080079ec + 8);
    puVar7 = (uint32_t *)(DAT_080079ec + 0xc);
    do {
        uVar5 = 0;
        uVar8 = FUN_080003f8(1, 0, uVar4);
        do {
            do {
            } while (-1 < *piVar6 << 0x1e);
            puVar3 = (uint32_t *)(iVar2 + uVar5 * 8);
            if ((*puVar3 & (uint32_t)uVar8) == 0 &&
                (puVar3[1] & (uint32_t)((uint64_t)uVar8 >> 0x20)) == 0) {
                *puVar7 = 0x153f;
            } else {
                *puVar7 = 0xf79e;
            }
            uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < 0x70);
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x1c);
    sys_delay_cycles(10);
    FUN_08008c94(DAT_080079f0, 0x4000);
    FUN_0800bb28(iVar1, 0);
    FUN_080006e8(_FUN_080079f4, 0x788);
    return;
}

/* ================================================================
 * FUN_080079f4  @  0x080079F4
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_080079f4(void)

{
    int iVar1;
    uint32_t in_r3;
    uint32_t uStack_10;

    uStack_10 = in_r3;
    iVar1 = FUN_08007fdc();
    if ((iVar1 == 0) && (iVar1 = fs_find_open_handle(0, &uStack_10), iVar1 == 0)) {
        _MasterStackPointer = 0;
    }
    return;
}

/* ================================================================
 * fs_file_close  @  0x080079F8
 */

void fs_file_close() {
    uint32_t *param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    uint32_t uStack_10;

    uStack_10 = param_4;
    iVar1 = FUN_08007fdc();
    if ((iVar1 == 0) && (iVar1 = fs_find_open_handle(param_1, &uStack_10), iVar1 == 0)) {
        *param_1 = 0;
    }
    return;
}

/* ================================================================
 * FUN_08007a16  @  0x08007A16
 */

uint64_t FUN_08007a16() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint16_t uVar1;
    uint32_t uVar2;
    uint32_t *puVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int iVar11;
    int iVar12;
    bool bVar13;
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;

    local_30 = param_2;
    local_2c = param_3;
    local_28 = param_4;
    uVar2 = fs_find_open_handle(param_1, &local_30);
    bVar13 = uVar2 == 0;
    do {
        if (!bVar13)
            /* goto LAB_08007bfc; */ (void)0;
        uVar2 = (uint32_t)*(byte *)(param_1 + 0x11);
        bVar13 = uVar2 == 0;
    } while (!bVar13);
    puVar3 = *(uint32_t **)(param_1 + 0x28);
    iVar12 = param_1 + 0x2c;
    if (puVar3 == (uint32_t *)0x0) {
        if ((*(uint32_t *)(param_1 + 0xc) < param_2) &&
            (-1 < (int)((uint32_t)*(byte *)(param_1 + 0x10) << 0x1e))) {
            param_2 = *(uint32_t *)(param_1 + 0xc);
        }
        iVar11 = 0;
        iVar5 = *(int *)(param_1 + 0x14);
        *(uint32_t *)(param_1 + 0x14) = 0;
        if (param_2 != 0) {
            uVar1 = *(uint16_t *)(local_30 + 10);
            uVar7 = (uint32_t)uVar1 * 0x1000;
            if ((iVar5 == 0) || (uVar9 = iVar5 - 1, (param_2 - 1) / uVar7 < uVar9 / uVar7)) {
                iVar5 = *(int *)(param_1 + 8);
                if (iVar5 != 0) {
                LAB_08007b6e:
                    *(int *)(param_1 + 0x18) = iVar5;
                    /* goto LAB_08007b70; */ (void)0;
                }
                iVar5 = FUN_08002726(param_1, 0);
                if (iVar5 != 1) {
                    if (iVar5 == -1)
                        /* goto LAB_08007c18; */ (void)0;
                    *(int *)(param_1 + 8) = iVar5;
                    /* goto LAB_08007b6e; */ (void)0;
                }
            LAB_08007bf6:
                *(uint8_t *)(param_1 + 0x11) = 2;
                uVar2 = 2;
                /* goto LAB_08007bfc; */ (void)0;
            }
            uVar9 = uVar9 & ~(uVar7 - 1);
            *(uint32_t *)(param_1 + 0x14) = uVar9;
            param_2 = param_2 - uVar9;
            iVar5 = *(int *)(param_1 + 0x18);
        LAB_08007b70:
            if (iVar5 != 0) {
                while (uVar7 < param_2) {
                    param_2 = param_2 + (uint32_t)uVar1 * -0x1000;
                    *(uint32_t *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar7;
                    if ((int)((uint32_t)*(byte *)(param_1 + 0x10) << 0x1e) < 0) {
                        uVar9 = FUN_08002726();
                        if (uVar9 == 0) {
                            param_2 = 0;
                            break;
                        }
                    } else {
                        uVar9 = FUN_08008ae4(param_1);
                    }
                    if (uVar9 == 0xffffffff)
                        /* goto LAB_08007c18; */ (void)0;
                    if ((uVar9 < 2) || (*(uint32_t *)(local_30 + 0x14) <= uVar9))
                        /* goto LAB_08007bf6; */ (void)0;
                    *(uint32_t *)(param_1 + 0x18) = uVar9;
                }
                *(uint32_t *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_2;
                if ((param_2 & 0xfff) != 0) {
                    iVar11 = FUN_08002654(local_30);
                    if (iVar11 == 0)
                        /* goto LAB_08007bf6; */ (void)0;
                    iVar11 = iVar11 + (param_2 >> 0xc);
                }
            }
        }
        uVar7 = *(uint32_t *)(param_1 + 0x14);
        if (*(uint32_t *)(param_1 + 0xc) < uVar7) {
            *(uint32_t *)(param_1 + 0xc) = uVar7;
            *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 0x40;
        }
        if (((uVar7 & 0xfff) == 0) || (*(int *)(param_1 + 0x1c) == iVar11))
            /* goto LAB_08007bfc; */ (void)0;
        if ((int)((uint32_t)*(byte *)(param_1 + 0x10) << 0x18) < 0) {
            iVar5 = fs_fat32_write_block(*(uint8_t *)(local_30 + 1), iVar12,
                                         *(int *)(param_1 + 0x1c), 1);
            if (iVar5 != 0)
                /* goto LAB_08007c18; */ (void)0;
            *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0x7f;
        }
        iVar12 = fs_fat32_read_block(*(uint8_t *)(local_30 + 1), iVar12, iVar11, 1);
        if (iVar12 == 0) {
            *(int *)(param_1 + 0x1c) = iVar11;
            /* goto LAB_08007bfc; */ (void)0;
        }
    } else {
        if (param_2 == 0xffffffff) {
            local_2c = *puVar3;
            puVar3 = puVar3 + 1;
            uVar7 = *(uint32_t *)(param_1 + 8);
            uVar9 = 2;
            if (uVar7 != 0) {
                do {
                    uVar10 = 0;
                    uVar9 = uVar9 + 2;
                    uVar8 = uVar7;
                    local_28 = uVar7;
                    do {
                        uVar10 = uVar10 + 1;
                        uVar7 = FUN_08008ae4(param_1);
                        if (uVar7 < 2)
                            /* goto LAB_08007bf6; */ (void)0;
                        if (uVar7 == 0xffffffff)
                            /* goto LAB_08007c18; */ (void)0;
                        uVar6 = uVar8 + 1;
                        uVar8 = uVar7;
                    } while (uVar7 == uVar6);
                    if (uVar9 <= local_2c) {
                        *puVar3 = uVar10;
                        puVar3[1] = local_28;
                        puVar3 = puVar3 + 2;
                    }
                } while (uVar7 < *(uint32_t *)(local_30 + 0x14));
            }
            **(uint32_t **)(param_1 + 0x28) = uVar9;
            if (local_2c < uVar9) {
                uVar2 = 0x11;
            } else {
                *puVar3 = 0;
            }
            /* goto LAB_08007bfc; */ (void)0;
        }
        if (*(uint32_t *)(param_1 + 0xc) < param_2) {
            param_2 = *(uint32_t *)(param_1 + 0xc);
        }
        *(uint32_t *)(param_1 + 0x14) = param_2;
        bVar13 = param_2 == 0;
        do {
            do {
                if (bVar13)
                    /* goto LAB_08007bfc; */ (void)0;
                uVar4 = FUN_08002630(param_1, param_2 - 1);
                *(uint32_t *)(param_1 + 0x18) = uVar4;
                iVar5 = FUN_08002654(local_30, uVar4);
                if (iVar5 == 0)
                    /* goto LAB_08007bf6; */ (void)0;
                param_2 = (*(uint16_t *)(local_30 + 10) - 1 & param_2 - 1 >> 0xc) + iVar5;
                bVar13 = true;
            } while ((*(uint16_t *)(param_1 + 0x14) & 0xfff) == 0);
            bVar13 = true;
        } while (*(uint32_t *)(param_1 + 0x1c) == param_2);
        if ((int)((uint32_t)*(byte *)(param_1 + 0x10) << 0x18) < 0) {
            iVar5 = fs_fat32_write_block(*(uint8_t *)(local_30 + 1), iVar12,
                                         *(uint32_t *)(param_1 + 0x1c), 1);
            if (iVar5 != 0)
                /* goto LAB_08007c18; */ (void)0;
            *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0x7f;
        }
        iVar12 = fs_fat32_read_block(*(uint8_t *)(local_30 + 1), iVar12, param_2, 1);
        if (iVar12 == 0) {
            *(uint32_t *)(param_1 + 0x1c) = param_2;
            /* goto LAB_08007bfc; */ (void)0;
        }
    }
LAB_08007c18:
    *(uint8_t *)(param_1 + 0x11) = 1;
    uVar2 = 1;
LAB_08007bfc:
    return CONCAT44(local_30, uVar2);
}

/* ================================================================
 * FUN_08007c28  @  0x08007C28
 */

uint32_t FUN_08007c28() {
    uint8_t *param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    uint8_t *puVar4;
    uint32_t local_18;
    uint8_t *local_14;
    uint32_t local_10;
    int iStack_c;

    local_18 = param_2;
    local_14 = param_1;
    local_10 = param_2;
    iStack_c = param_3;
    iVar2 = FUN_08008c58(&local_18);
    iVar1 = DAT_08007c6c;
    if (iVar2 < 0) {
        uVar3 = 0xb;
    } else {
        puVar4 = *(uint8_t **)(DAT_08007c6c + iVar2 * 4);
        if (puVar4 != (uint8_t *)0x0) {
            *puVar4 = 0;
        }
        if (local_14 != (uint8_t *)0x0) {
            *local_14 = 0;
        }
        *(uint8_t **)(iVar1 + iVar2 * 4) = local_14;
        if (param_3 == 0) {
            uVar3 = 0;
        } else {
            uVar3 = FUN_0800a6cc(&local_10, &local_14, 0);
        }
    }
    return uVar3;
}

/* ================================================================
 * fs_file_open  @  0x08007C70
 */

int fs_file_open(int *param_1, uint32_t param_2, uint32_t param_3)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int local_58;
    int local_54;
    byte local_4e;
    int local_38;
    byte local_29;
    int *piStack_28;
    uint32_t local_24;
    uint32_t uStack_20;

    if (param_1 == (int *)0x0) {
        return 9;
    }
    uVar5 = param_3 & 0x3f;
    piStack_28 = param_1;
    local_24 = param_2;
    uStack_20 = param_3;
    iVar1 = FUN_0800a6cc(&local_24, &local_58, uVar5);
    if (iVar1 != 0)
        /* goto LAB_08007e16; */ (void)0;
    local_54 = local_58;
    iVar1 = FUN_080089f4(&local_54, local_24);
    if ((iVar1 == 0) && ((int)((uint32_t)local_29 << 0x18) < 0)) {
        iVar1 = 6;
    }
    if ((param_3 & 0x1c) == 0) {
        if (iVar1 != 0)
            /* goto LAB_08007e16; */ (void)0;
        if ((int)((uint32_t)local_4e << 0x1b) < 0) {
            iVar1 = 4;
            /* goto LAB_08007e16; */ (void)0;
        }
        if (((int)(param_3 << 0x1e) < 0) && ((local_4e & 1) != 0))
            /* goto LAB_08007cda; */ (void)0;
    LAB_08007d6a:
        if ((int)(uVar5 << 0x1c) < 0) {
        LAB_08007d6e:
            uVar5 = uVar5 | 0x40;
        }
    } else {
        if (iVar1 == 0) {
            if ((local_4e & 0x11) != 0) {
            LAB_08007cda:
                iVar1 = 7;
                /* goto LAB_08007e16; */ (void)0;
            }
            if ((int)(param_3 << 0x1d) < 0) {
                iVar1 = 8;
                /* goto LAB_08007e16; */ (void)0;
            }
        } else {
            if (iVar1 == 4) {
                iVar1 = FUN_08002f12(&local_54);
            }
            uVar5 = uVar5 | 8;
            if (iVar1 != 0)
                /* goto LAB_08007e16; */ (void)0;
        }
        uVar6 = DAT_08007e24;
        if ((int)(uVar5 << 0x1c) < 0) {
            FUN_0800bc58(local_38 + 0xe, DAT_08007e24);
            FUN_0800bc58(local_38 + 0x16, uVar6);
            iVar2 = FUN_080095c8(local_58, local_38);
            *(uint8_t *)(local_38 + 0xb) = 0x20;
            FUN_0800bc30(local_58, local_38, 0);
            FUN_0800bc58(local_38 + 0x1c, 0);
            *(uint8_t *)(local_58 + 3) = 1;
            if (iVar2 != 0) {
                uVar6 = *(uint32_t *)(local_58 + 0x2c);
                iVar1 = FUN_0800b2c4(&local_54, iVar2, 0);
                if (iVar1 != 0)
                    /* goto LAB_08007e16; */ (void)0;
                iVar1 = FUN_0800a91c(local_58, uVar6);
                *(int *)(local_58 + 0xc) = iVar2 + -1;
                if (iVar1 != 0)
                    /* goto LAB_08007e16; */ (void)0;
                /* goto LAB_08007d6a; */ (void)0;
            }
            /* goto LAB_08007d6e; */ (void)0;
        }
    }
    param_1[8] = *(int *)(local_58 + 0x2c);
    param_1[9] = local_38;
    iVar2 = FUN_080095c8(local_58, local_38);
    param_1[2] = iVar2;
    iVar2 = FUN_080095ee(local_38 + 0x1c);
    param_1[10] = 0;
    param_1[3] = iVar2;
    *param_1 = local_58;
    *(uint16_t *)(param_1 + 1) = *(uint16_t *)(local_58 + 6);
    *(char *)(param_1 + 4) = (char)uVar5;
    *(uint8_t *)((int)param_1 + 0x11) = 0;
    param_1[7] = 0;
    param_1[5] = 0;
    FUN_080006e8(param_1 + 0xb, 0x1000);
    if (-1 < (int)(uVar5 << 0x1a)) {
        return iVar1;
    }
    uVar5 = param_1[3];
    if (uVar5 == 0) {
        return iVar1;
    }
    param_1[5] = uVar5;
    uVar4 = param_1[2];
    uVar3 = (uint32_t)*(uint16_t *)(local_58 + 10);
    do {
        if (uVar5 <= uVar3 * 0x1000)
            break;
        uVar4 = FUN_08008ae4(param_1);
        if (uVar4 < 2) {
            iVar1 = 2;
        }
        if (uVar4 == 0xffffffff) {
            iVar1 = 1;
            uVar5 = uVar5 + uVar3 * -0x1000;
            break;
        }
        uVar5 = uVar5 + uVar3 * -0x1000;
    } while (iVar1 == 0);
    param_1[6] = uVar4;
    if (iVar1 == 0) {
        if ((uVar5 & 0xfff) == 0) {
            return 0;
        }
        iVar1 = FUN_08002654(local_58);
        if (iVar1 == 0) {
            iVar1 = 2;
        } else {
            iVar1 = iVar1 + (uVar5 >> 0xc);
            param_1[7] = iVar1;
            iVar1 = fs_fat32_read_block(*(uint8_t *)(local_58 + 1), param_1 + 0xb, iVar1, 1);
            if (iVar1 == 0) {
                return 0;
            }
            iVar1 = 1;
        }
    }
LAB_08007e16:
    *param_1 = 0;
    return iVar1;
}

/* ================================================================
 * FUN_08007e28  @  0x08007E28
 */

int FUN_08007e28(int *param_1, uint32_t param_2)

{
    int iVar1;
    int local_18[2];
    int *piStack_10;
    uint32_t local_c;

    if (param_1 == (int *)0x0) {
        return 9;
    }
    piStack_10 = param_1;
    local_c = param_2;
    iVar1 = FUN_0800a6cc(&local_c, local_18, 0);
    if (iVar1 != 0)
        /* goto LAB_08007e80; */ (void)0;
    *param_1 = local_18[0];
    iVar1 = FUN_080089f4(param_1, local_c);
    if (iVar1 == 0) {
        if ((int)((uint32_t)*(byte *)((int)param_1 + 0x2b) << 0x18) < 0) {
        LAB_08007e6a:
            *(uint16_t *)(param_1 + 1) = *(uint16_t *)(local_18[0] + 6);
            iVar1 = fs_fat32_seek_cluster(param_1, 0);
            /* goto LAB_08007e78; */ (void)0;
        }
        if ((int)((uint32_t)*(byte *)((int)param_1 + 6) << 0x1b) < 0) {
            iVar1 = FUN_080095c8(local_18[0], param_1[7]);
            param_1[2] = iVar1;
            /* goto LAB_08007e6a; */ (void)0;
        }
    } else {
    LAB_08007e78:
        if (iVar1 != 4) {
            if (iVar1 == 0) {
                return 0;
            }
            /* goto LAB_08007e80; */ (void)0;
        }
    }
    iVar1 = 5;
LAB_08007e80:
    *param_1 = 0;
    return iVar1;
}

/* ================================================================
 * FUN_08007e8a  @  0x08007E8A
 */

uint64_t FUN_08007e8a() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    int *param_4 = 0;
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t local_30;
    int *local_28;

    *param_4 = 0;
    local_28 = param_4;
    uVar1 = fs_find_open_handle(param_1, &local_28);
    local_30 = param_2;
    if ((uVar1 == 0) && (uVar1 = (uint32_t)*(byte *)(param_1 + 0x11), uVar1 == 0)) {
        if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
            uVar1 = 7;
        } else {
            uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x14);
            iVar5 = param_1 + 0x2c;
            if (uVar1 < param_3) {
                param_3 = uVar1;
            }
            for (; param_3 != 0; param_3 = param_3 - uVar1) {
                uVar1 = *(uint32_t *)(param_1 + 0x14);
                if ((uVar1 & 0xfff) == 0) {
                    uVar4 = *(uint16_t *)((int)local_28 + 10) - 1 & uVar1 >> 0xc;
                    if (uVar4 == 0) {
                        if (uVar1 == 0) {
                            uVar1 = *(uint32_t *)(param_1 + 8);
                        } else if (*(int *)(param_1 + 0x28) == 0) {
                            uVar1 = FUN_08008ae4(param_1, *(uint32_t *)(param_1 + 0x18));
                        } else {
                            uVar1 = FUN_08002630(param_1);
                        }
                        if (1 < uVar1) {
                            if (uVar1 != 0xffffffff) {
                                *(uint32_t *)(param_1 + 0x18) = uVar1;
                                /* goto LAB_08007f04; */ (void)0;
                            }
                            /* goto LAB_08007f98; */ (void)0;
                        }
                    } else {
                    LAB_08007f04:
                        iVar2 = FUN_08002654(local_28, *(uint32_t *)(param_1 + 0x18));
                        if (iVar2 != 0) {
                            iVar2 = iVar2 + uVar4;
                            local_30 = param_3 >> 0xc;
                            if (local_30 == 0) {
                                if (*(int *)(param_1 + 0x1c) != iVar2) {
                                    if ((int)((uint32_t)*(byte *)(param_1 + 0x10) << 0x18) < 0) {
                                        iVar3 = fs_fat32_write_block(
                                            *(uint8_t *)((int)local_28 + 1), iVar5,
                                            *(int *)(param_1 + 0x1c), 1);
                                        if (iVar3 != 0)
                                            /* goto LAB_08007f98; */ (void)0;
                                        *(byte *)(param_1 + 0x10) =
                                            *(byte *)(param_1 + 0x10) & 0x7f;
                                    }
                                    iVar3 = fs_fat32_read_block(*(uint8_t *)((int)local_28 + 1),
                                                                iVar5, iVar2, 1);
                                    if (iVar3 != 0)
                                        /* goto LAB_08007f98; */ (void)0;
                                }
                                *(int *)(param_1 + 0x1c) = iVar2;
                                /* goto LAB_08007fa2; */ (void)0;
                            }
                            if ((uint32_t)*(uint16_t *)((int)local_28 + 10) < uVar4 + local_30) {
                                local_30 = *(uint16_t *)((int)local_28 + 10) - uVar4;
                            }
                            iVar3 = fs_fat32_read_block(*(uint8_t *)((int)local_28 + 1), param_2,
                                                        iVar2, local_30);
                            if (iVar3 == 0) {
                                if (((int)((uint32_t)*(byte *)(param_1 + 0x10) << 0x18) < 0) &&
                                    (uVar1 = *(int *)(param_1 + 0x1c) - iVar2, uVar1 < local_30)) {
                                    FUN_080005a6(param_2 + uVar1 * 0x1000, iVar5, 0x1000);
                                }
                                uVar1 = local_30 << 0xc;
                                /* goto LAB_08007fbe; */ (void)0;
                            }
                        LAB_08007f98:
                            *(uint8_t *)(param_1 + 0x11) = 1;
                            uVar1 = 1;
                            /* goto LAB_08007eca; */ (void)0;
                        }
                    }
                    *(uint8_t *)(param_1 + 0x11) = 2;
                    uVar1 = 2;
                    /* goto LAB_08007eca; */ (void)0;
                }
            LAB_08007fa2:
                uVar4 = *(uint16_t *)(param_1 + 0x14) & 0xfff;
                uVar1 = 0x1000 - uVar4;
                if (param_3 < uVar1) {
                    uVar1 = param_3;
                }
                FUN_080005a6(param_2, uVar4 + param_1 + 0x2c, uVar1);
            LAB_08007fbe:
                *param_4 = *param_4 + uVar1;
                param_2 = param_2 + uVar1;
                *(uint32_t *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar1;
            }
            uVar1 = 0;
        }
    }
LAB_08007eca:
    return CONCAT44(local_30, uVar1);
}

/* ================================================================
 * FUN_08007fdc  @  0x08007FDC
 */

int FUN_08007fdc() {
    uint32_t *param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    int param_4 = 0;
    uint32_t uVar1;
    int iVar2;
    int local_18;

    local_18 = param_4;
    iVar2 = fs_find_open_handle(param_1, &local_18);
    if ((iVar2 == 0) && ((int)((uint32_t)*(byte *)(param_1 + 4) << 0x19) < 0)) {
        if ((int)((uint32_t)*(byte *)(param_1 + 4) << 0x18) < 0) {
            iVar2 = fs_fat32_write_block(*(uint8_t *)(local_18 + 1), param_1 + 0xb, param_1[7], 1);
            if (iVar2 != 0) {
                return 1;
            }
            *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0x7f;
        }
        uVar1 = DAT_08008068;
        iVar2 = FUN_0800a91c(local_18, param_1[8]);
        if (iVar2 == 0) {
            iVar2 = param_1[9];
            *(byte *)(iVar2 + 0xb) = *(byte *)(iVar2 + 0xb) | 0x20;
            FUN_0800bc30(*param_1, iVar2, param_1[2]);
            FUN_0800bc58(iVar2 + 0x1c, param_1[3]);
            FUN_0800bc58(iVar2 + 0x16, uVar1);
            FUN_0800bc68(iVar2 + 0x12, 0);
            *(uint8_t *)(local_18 + 3) = 1;
            iVar2 = FUN_0800bd24();
            *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
            return iVar2;
        }
    }
    return iVar2;
}

/* ================================================================
 * fs_open_jpeg_file  @  0x0800806C
 * nearby string: "2:/LOGO.jpg"
 */

int fs_open_jpeg_file(uint32_t param_1)

{
    int iVar1;
    int iVar2;
    uint32_t local_70;
    byte local_6a;
    uint32_t local_54;
    byte local_45;
    uint32_t local_44[2];
    uint32_t local_3c[2];
    int local_34;
    uint32_t local_c;

    local_c = param_1;
    iVar1 = FUN_0800a6cc(&local_c, local_44, 2);
    if (iVar1 != 0) {
        return iVar1;
    }
    local_70 = local_44[0];
    iVar1 = FUN_080089f4(&local_70, local_c);
    if (iVar1 != 0) {
        return iVar1;
    }
    if ((int)((uint32_t)local_45 << 0x18) < 0) {
        return 6;
    }
    if ((local_6a & 1) == 0) {
        iVar1 = FUN_080095c8(local_44[0], local_54);
        if ((int)((uint32_t)local_6a << 0x1b) < 0) {
            local_3c[0] = local_44[0];
            local_34 = iVar1;
            iVar2 = fs_fat32_seek_cluster(local_3c, 0);
            if (iVar2 != 0) {
                return iVar2;
            }
            iVar2 = FUN_08002eb2(local_3c, 0);
            if (iVar2 == 0)
                /* goto LAB_080080a4; */ (void)0;
            if (iVar2 != 4) {
                return iVar2;
            }
        }
        iVar2 = FUN_08002f52(&local_70);
        if ((iVar2 == 0) &&
            ((iVar1 == 0 || (iVar2 = FUN_0800b2c4(&local_70, iVar1, 0), iVar2 == 0)))) {
            iVar2 = FUN_0800bd24(local_44[0]);
        }
    } else {
    LAB_080080a4:
        iVar2 = 7;
    }
    return iVar2;
}

/* ================================================================
 * display_state_reset  @  0x08008100
 * nearby string: "2:/LOGO.jpg"
 */

void display_state_reset(void)

{
    uint16_t *puVar1;

    puVar1 = DAT_08008134;
    *DAT_08008134 = 0xff;
    puVar1[1] = 0;
    puVar1[4] = 0;
    puVar1[2] = 0;
    puVar1[3] = 9;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[5] = 10;
    puVar1[6] = 0;
    puVar1[7] = 0;
    *(uint8_t *)(puVar1 + 0x9c) = 0;
    *(uint8_t *)((int)puVar1 + 0x139) = 0;
    *(uint8_t *)(puVar1 + 0x9d) = 0;
    *(uint8_t *)((int)puVar1 + 0x13b) = 9;
    *(uint8_t *)(puVar1 + 0x9e) = 10;
    *(uint8_t *)(puVar1 + 0x9f) = 0;
    return;
}

/* ================================================================
 * sys_handle_reset_menu  @  0x08008138
 * nearby string: "2:/LOGO.jpg"
 */

void sys_handle_reset_menu(void)

{
    char cVar1;
    int iVar2;
    int iVar3;

    iVar2 = DAT_08008208;
    if (*(char *)(DAT_08008208 + 1) == '\0') {
        ui_draw_reset_return_button(1);
        *(uint8_t *)(iVar2 + 1) = 1;
        *(uint8_t *)(iVar2 + 7) = 0;
    }
    iVar3 = DAT_0800820c;
    cVar1 = *(char *)(DAT_0800820c + 2);
    if (cVar1 == '\x01') {
        if ((*(char *)(iVar2 + 7) == '\0') || (*(char *)(iVar2 + 7) == '\x01')) {
            ui_draw_reset_return_button(2);
            *(uint8_t *)(iVar2 + 7) = 2;
        }
    } else if (cVar1 == '\t') {
        if (*(char *)(iVar2 + 7) == '\x02') {
            ui_draw_reset_return_button(1);
            *(uint8_t *)(iVar2 + 7) = 1;
        }
    } else if (cVar1 == '\x05') {
        if ((*(char *)(iVar2 + 7) == '\0') || (*(char *)(iVar2 + 7) == '\x01')) {
            ui_draw_reset_return_button(0);
            *(uint8_t *)(iVar2 + 7) = 0;
            ui_draw_main_menu(0, 0, 0, 0, 3);
            *(uint8_t *)(iVar2 + 3) = 0;
        } else {
            display_state_reset();
            FUN_080094f4(9999, 0x8f,
                         (uint32_t)((short)(*(byte *)(iVar3 + 0x23) + 1) * 9999) / 10 & 0xffff);
            FUN_0800c848(0);
            fs_open_jpeg_file(s_2__LOGO_jpg_08008210);
            FUN_0800c848(0x100000);
            ui_language_select_screen();
        }
    } else if (cVar1 == '\r') {
        ui_draw_reset_return_button(0);
        *(uint8_t *)(iVar2 + 7) = 0;
    }
    if (*(char *)(iVar3 + 5) == '\x01') {
        ui_draw_settings_page(2);
        ui_draw_reset_return_button(*(uint8_t *)(iVar2 + 7));
        *(uint8_t *)(iVar3 + 5) = 0;
    }
    return;
}

/* ================================================================
 * FUN_08008270  @  0x08008270
 */

void FUN_08008270(uint32_t param_1)

{
    *(uint32_t *)(DAT_08008278 + 0xc) = param_1;
    return;
}

/* ================================================================
 * FUN_0800827c  @  0x0800827C
 */

uint32_t FUN_0800827c() {
    uint16_t *param_1 = 0;
    uint16_t param_2 = 0;
    int iVar1;

    iVar1 = DAT_0800829c;
    *(uint32_t *)(DAT_0800829c + 0x10) = *(uint32_t *)(DAT_0800829c + 0x10) | 1;
    *param_1 = param_2;
    FUN_080082d8(0x100000);
    *(uint32_t *)(iVar1 + 0x10) = *(uint32_t *)(iVar1 + 0x10) & 0xfffffffe;
    return;
}

/* ================================================================
 * FUN_080082a0  @  0x080082A0
 */

void FUN_080082a0(void)

{
    *(uint32_t *)(DAT_080082ac + 0x10) = *(uint32_t *)(DAT_080082ac + 0x10) | 0x80;
    return;
}

/* ================================================================
 * FUN_080082b0  @  0x080082B0
 */

uint32_t FUN_080082b0(void)

{
    uint32_t uVar1;

    uVar1 = 3;
    if ((*(uint32_t *)(DAT_080082d4 + 0xc) & 1) != 0) {
        return 0;
    }
    if (*(int *)(DAT_080082d4 + 0xc) << 0x1d < 0) {
        uVar1 = 1;
    } else if (*(int *)(DAT_080082d4 + 0xc) << 0x1b < 0) {
        return 2;
    }
    return uVar1;
}

/* ================================================================
 * FUN_080082d8  @  0x080082D8
 */

int FUN_080082d8() {
    int iVar1;
    int extraout_r3;
    int extraout_r3_00;
    int iVar2;

    iVar1 = FUN_080082b0();
    iVar2 = extraout_r3;
    while (iVar1 == 0) {
        if (iVar2 == 0)
            /* goto LAB_080082f0; */ (void)0;
        iVar1 = FUN_080082b0();
        iVar2 = extraout_r3_00 + -1;
    }
    if (iVar2 == 0) {
    LAB_080082f0:
        iVar1 = 4;
    }
    return iVar1;
}

/* ================================================================
 * FUN_080082fc  @  0x080082FC
 */

void FUN_080082fc(uint16_t *param_1, int param_2, uint32_t param_3)

{
    uint32_t uVar1;

    for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
        *(uint16_t *)(param_2 + uVar1 * 2) = *param_1;
        param_1 = param_1 + 1;
    }
    return;
}

/* ================================================================
 * FUN_08008318  @  0x08008318
 */

uint32_t FUN_08008318(uint32_t param_1)

{
    int iVar1;

    iVar1 = DAT_08008340;
    *(uint32_t *)(DAT_08008340 + 0x10) = *(uint32_t *)(DAT_08008340 + 0x10) | 2;
    *(uint32_t *)(iVar1 + 0x14) = param_1;
    *(uint32_t *)(iVar1 + 0x10) = *(uint32_t *)(iVar1 + 0x10) | 0x40;
    FUN_080082d8(iVar1 << 0x11);
    *(uint32_t *)(iVar1 + 0x10) = *(uint32_t *)(iVar1 + 0x10) & 0xfffffffd;
    return;
}

/* ================================================================
 * FUN_08008344  @  0x08008344
 */

uint32_t FUN_08008344(void)

{
    return *DAT_0800834c;
}

/* ================================================================
 * FUN_08008350  @  0x08008350
 */

uint32_t FUN_08008350() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t *puVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;

    local_28 = param_1;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    gpio_write(DAT_08008474, 1);
    gpio_write(0x180000, 1);
    iVar5 = DAT_08008474 + -10;
    gpio_write(iVar5, 1);
    gpio_write(iVar5, 1);
    gpio_write(iVar5, 1);
    gpio_write(iVar5, 1);
    uVar1 = DAT_08008478;
    local_28 = 0x10;
    local_24 = 0x1101800;
    FUN_08008cb0(DAT_08008478, &local_28);
    uVar2 = local_24;
    ((uint16_t *)&local_24)[0] = CONCAT11(0x18, (uint8_t)local_24);
    local_28 = 0x20;
    ((uint8_t *)&local_24)[3] = SUB41(uVar2, 3);
    ((uint8_t *)&local_24)[3] = CONCAT12(8, (uint16_t)local_24);
    FUN_08008cb0(uVar1, &local_28);
    uVar2 = local_24;
    ((uint16_t *)&local_24)[0] = CONCAT11(0x18, (uint8_t)local_24);
    local_28 = 0x40;
    ((uint8_t *)&local_24)[3] = SUB41(uVar2, 3);
    ((uint8_t *)&local_24)[3] = CONCAT12(8, (uint16_t)local_24);
    FUN_08008cb0(uVar1, &local_28);
    uVar2 = local_24;
    ((uint16_t *)&local_24)[0] = CONCAT11(0x18, (uint8_t)local_24);
    local_28 = 0x80;
    ((uint8_t *)&local_24)[3] = SUB41(uVar2, 3);
    ((uint8_t *)&local_24)[3] = CONCAT12(8, (uint16_t)local_24);
    FUN_08008cb0(uVar1, &local_28);
    FUN_08008c94(uVar1, 0x10);
    FUN_0800bb08(&local_20);
    uVar2 = DAT_0800847c;
    local_1c = 0x1010100;
    local_20 = 0x10100;
    FUN_0800bb4a(DAT_0800847c, &local_20);
    FUN_0800bb1e(uVar2, 1);
    FUN_08008c90(uVar1, 0x10);
    FUN_080084ec(0x90);
    FUN_080084ec(0);
    FUN_080084ec(0);
    FUN_080084ec(0);
    iVar5 = FUN_080084d8();
    uVar4 = FUN_080084d8();
    FUN_08008c94(uVar1, 0x10);
    puVar3 = DAT_08008480;
    DAT_08008480[2] = iVar5 << 8 | uVar4;
    *puVar3 = 0x300000;
    return 0;
}

/* ================================================================
 * FUN_08008484  @  0x08008484
 */

uint32_t FUN_08008484(uint8_t *param_1, uint32_t param_2, uint32_t param_3)

{
    uint32_t uVar1;
    uint8_t uVar2;
    bool bVar3;

    uVar1 = DAT_080084d4;
    FUN_08008c90(DAT_080084d4, 0x10);
    FUN_080084ec(3);
    FUN_080084ec((param_2 & 0xffffff) >> 0x10);
    FUN_080084ec((param_2 & 0xffff) >> 8);
    FUN_080084ec(param_2 & 0xff);
    while (bVar3 = param_3 != 0, param_3 = param_3 - 1 & 0xffff, bVar3) {
        uVar2 = FUN_080084ec(0xff);
        *param_1 = uVar2;
        param_1 = param_1 + 1;
    }
    FUN_08008c94(uVar1, 0x10);
    return 0;
}

/* ================================================================
 * FUN_080084d8  @  0x080084D8
 */

uint32_t FUN_080084d8(void)

{
    FUN_080084ec(0xff);
    return;
}

/* ================================================================
 * FUN_080084e0  @  0x080084E0
 */

uint32_t FUN_080084e0(void)

{
    return *(uint32_t *)(DAT_080084e8 + 4);
}

/* ================================================================
 * FUN_080084ec  @  0x080084EC
 */

uint8_t FUN_080084ec(uint32_t param_1)

{
    uint32_t uVar1;
    uint8_t uVar2;
    int iVar3;

    uVar1 = DAT_0800851c;
    do {
        iVar3 = FUN_0800bb3c(uVar1, 2);
    } while (iVar3 == 0);
    FUN_0800bb38(uVar1, param_1);
    do {
        iVar3 = FUN_0800bb3c(uVar1, 1);
    } while (iVar3 == 0);
    uVar2 = FUN_0800bb32(uVar1);
    return uVar2;
}

/* ================================================================
 * FUN_08008520  @  0x08008520
 */

void FUN_08008520(void)

{
    uint32_t uVar1;
    uint32_t uVar2;

    uVar1 = DAT_08008548;
    FUN_08008c90(DAT_08008548, 0x10);
    FUN_080084ec(5);
    do {
        uVar2 = FUN_080084ec(0xff);
    } while ((uVar2 & 1) != 0);
    FUN_08008c94(uVar1, 0x10);
    return;
}

/* ================================================================
 * FUN_0800854c  @  0x0800854C
 */

uint32_t FUN_0800854c(int param_1, uint32_t param_2, uint32_t param_3)

{
    int iVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;

    iVar1 = DAT_08008614;
    uVar8 = param_2 & 0xfff;
    uVar9 = param_2 >> 0xc;
    uVar7 = 0x1000 - uVar8;
    if (param_3 <= 0x1000 - uVar8) {
        uVar7 = param_3;
    }
    while (true) {
        uVar4 = uVar9 << 0xc;
        FUN_08008484(DAT_08008614, uVar4, 0x1000);
        for (uVar2 = 0; (uVar2 < uVar7 && (*(char *)(iVar1 + uVar8 + uVar2) == -1));
             uVar2 = uVar2 + 1) {
        }
        iVar3 = param_1;
        uVar5 = param_2;
        uVar6 = uVar7;
        if (uVar2 < uVar7) {
            FUN_080086a4();
            FUN_08008c90(DAT_08008618, 0x10);
            FUN_080084ec(0x20);
            FUN_080084ec((uVar4 & 0xffffff) >> 0x10);
            FUN_080084ec((uVar4 & 0xffff) >> 8);
            FUN_080084ec(0);
            FUN_08008c94(DAT_08008618, 0x10);
            FUN_08008520();
            for (uVar2 = 0; uVar2 < uVar7; uVar2 = uVar2 + 1) {
                *(uint8_t *)(iVar1 + uVar2 + uVar8) = *(uint8_t *)(param_1 + uVar2);
            }
            iVar3 = DAT_08008614;
            uVar5 = uVar4;
            uVar6 = 0x1000;
        }
        FUN_0800861c(iVar3, uVar5, uVar6);
        if (uVar7 == param_3)
            break;
        param_1 = param_1 + uVar7;
        param_2 = param_2 + uVar7;
        uVar8 = 0;
        param_3 = param_3 - uVar7 & 0xffff;
        uVar9 = uVar9 + 1;
        uVar7 = 0x1000;
        if (param_3 < 0x1001) {
            uVar7 = param_3;
        }
    }
    return 0;
}

/* ================================================================
 * FUN_0800861c  @  0x0800861C
 */

void FUN_0800861c(uint8_t *param_1, uint32_t param_2, uint32_t param_3)

{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint8_t *puVar4;
    bool bVar5;

    uVar1 = DAT_080086a0;
    uVar2 = 0x100 - (param_2 & 0xff);
    if (param_3 <= uVar2) {
        uVar2 = param_3;
    }
    while (true) {
        FUN_080086a4();
        FUN_08008c90(uVar1, 0x10);
        FUN_080084ec(2);
        FUN_080084ec((param_2 & 0xffffff) >> 0x10);
        FUN_080084ec((param_2 & 0xffff) >> 8);
        FUN_080084ec(param_2 & 0xff);
        uVar3 = uVar2;
        puVar4 = param_1;
        while (bVar5 = uVar3 != 0, uVar3 = uVar3 - 1 & 0xffff, bVar5) {
            FUN_080084ec(*puVar4);
            puVar4 = puVar4 + 1;
        }
        FUN_08008c94(uVar1, 0x10);
        FUN_08008520();
        if (uVar2 == param_3)
            break;
        param_1 = param_1 + uVar2;
        param_2 = param_2 + uVar2;
        param_3 = param_3 - uVar2 & 0xffff;
        uVar2 = 0x100;
        if (param_3 < 0x101) {
            uVar2 = param_3;
        }
    }
    return;
}

/* ================================================================
 * FUN_080086a4  @  0x080086A4
 */

void FUN_080086a4(void)

{
    uint32_t uVar1;

    uVar1 = DAT_080086c4;
    FUN_08008c90(DAT_080086c4, 0x10);
    FUN_080084ec(6);
    FUN_08008c94(uVar1, 0x10);
    return;
}

/* ================================================================
 * FUN_080086c8  @  0x080086C8
 */

void FUN_080086c8(void)

{
    int iVar1;

    iVar1 = DAT_080086d8;
    *(uint32_t *)(DAT_080086d8 + 4) = DAT_080086d4;
    *(uint32_t *)(iVar1 + 4) = DAT_080086dc;
    return;
}

/* ================================================================
 * FUN_080086e0  @  0x080086E0
 */

uint64_t FUN_080086e0(int param_1, int param_2, uint32_t param_3)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    int iVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int local_30;

    FUN_080086c8();
    iVar1 = DAT_080087c4;
    uVar9 = (param_1 + 0xf8000000U & 0x3ff) >> 1;
    uVar10 = param_1 + 0xf8000000U >> 10;
    uVar8 = 0x200 - uVar9;
    if (param_3 <= 0x200 - uVar9) {
        uVar8 = param_3;
    }
    local_30 = param_1;
    do {
        iVar2 = uVar10 * 0x400 + 0x8000000;
        FUN_080082fc(iVar2, DAT_080087c4, 0x200);
        uVar3 = 0;
        while ((uVar3 < uVar8 && (*(short *)(iVar1 + (uVar9 + uVar3) * 2) == -1))) {
            uVar3 = uVar3 + 1 & 0xffff;
        }
        iVar4 = local_30;
        iVar6 = param_2;
        uVar7 = uVar8;
        if (uVar3 < uVar8) {
            iVar4 = FUN_080082d8(0x40000000);
            if ((iVar4 == 1) || (iVar4 == 2)) {
                FUN_08008270(0x14);
            LAB_08008750:
                iVar4 = FUN_08008318(iVar2);
                if (iVar4 == 3) {
                    for (uVar3 = 0; uVar3 < uVar8; uVar3 = uVar3 + 1 & 0xffff) {
                        *(uint16_t *)(iVar1 + (uVar3 + uVar9) * 2) =
                            *(uint16_t *)(param_2 + uVar3 * 2);
                    }
                    iVar4 = iVar2;
                    iVar6 = DAT_080087c4;
                    uVar7 = 0x200;
                    /* goto LAB_08008784; */ (void)0;
                }
            } else if (iVar4 != 4)
                /* goto LAB_08008750; */ (void)0;
        LAB_0800878c:
            uVar5 = 0;
            /* goto LAB_0800878e; */ (void)0;
        }
    LAB_08008784:
        iVar2 = display_send_pixel_burst(iVar4, iVar6, uVar7);
        if (iVar2 != 1)
            /* goto LAB_0800878c; */ (void)0;
        if (param_3 == uVar8) {
            FUN_080082a0();
            uVar5 = 1;
        LAB_0800878e:
            return CONCAT44(local_30, uVar5);
        }
        param_2 = param_2 + uVar8 * 2;
        local_30 = local_30 + uVar8 * 2;
        uVar9 = 0;
        param_3 = param_3 - uVar8 & 0xffff;
        uVar10 = uVar10 + 1;
        uVar8 = 0x200;
        if (param_3 < 0x201) {
            uVar8 = param_3;
        }
    } while (true);
}

/* ================================================================
 * display_send_pixel_burst  @  0x080087C8
 * nearby string: "%c%0.0f%c"
 */

uint32_t display_send_pixel_burst(int param_1, int param_2, uint32_t param_3)

{
    int iVar1;
    uint32_t uVar2;

    uVar2 = 0;
    while (true) {
        if (param_3 <= uVar2) {
            return 1;
        }
        iVar1 = FUN_0800827c(param_1, *(uint16_t *)(param_2 + uVar2 * 2));
        if (iVar1 != 3)
            break;
        uVar2 = uVar2 + 1 & 0xffff;
        param_1 = param_1 + 2;
    }
    return 0;
}

/* ================================================================
 * measure_format_value  @  0x080087FC
 * nearby string: "%c%0.0f%c"
 */

void measure_format_value(uint32_t param_1, uint32_t param_2)

{
    uint32_t uVar1;
    char *pcVar2;
    uint32_t uVar3;
    uint64_t uVar4;

    if (*(char *)*DAT_08008958 == '\x12') {
        if ((int)param_1 < DAT_08008974) {
            if (DAT_0800895c <= (int)param_1) {
                uVar4 = FUN_0800e548();
                uVar3 = 0x20;
            LAB_080088a0:
                sys_sprintf(param_2, s__c_c_0_0f_c_0800898c, uVar3, 0x30, uVar4, 0);
                return;
            }
            if ((int)param_1 < DAT_08008960) {
                if (param_1 < DAT_08008964) {
                    FUN_0800e548();
                    uVar3 = 0x20;
                } else {
                    if (DAT_08008968 <= param_1)
                        /* goto LAB_08008880; */ (void)0;
                    uVar1 = param_1 ^ 0x80000000;
                    if (DAT_0800896c <= param_1) {
                        uVar4 = FUN_0800e548(uVar1);
                        uVar3 = 0x2d;
                        /* goto LAB_080088a0; */ (void)0;
                    }
                    if (DAT_08008970 <= param_1) {
                        FUN_0800e548(uVar1);
                        uVar3 = 0x2d;
                        /* goto LAB_080088be; */ (void)0;
                    }
                    FUN_0800e548(uVar1);
                    uVar3 = 0x2d;
                }
                pcVar2 = s__c_c_c_c_0_0f_c_080089a8;
            } else {
                FUN_0800e548();
                uVar3 = 0x20;
            LAB_080088be:
                pcVar2 = s__c_c_c_0_0f_c_08008998;
            }
            sys_sprintf(param_2, pcVar2, uVar3, 0x30, 0x30);
            return;
        }
    } else if ((int)param_1 < DAT_08008974) {
        if (DAT_0800895c <= (int)param_1) {
            FUN_0800e548();
            pcVar2 = s__c_0_1f_c_080089b8;
            /* goto LAB_080088ee; */ (void)0;
        }
        if (DAT_08008960 <= (int)param_1) {
            FUN_0800e548();
            pcVar2 = s__c_0_2f_c_080089c4;
            /* goto LAB_080088ee; */ (void)0;
        }
        if (param_1 < DAT_08008964) {
            FUN_0800e548();
            pcVar2 = s__c_0_3f_c_080089d0;
            /* goto LAB_080088ee; */ (void)0;
        }
        if (param_1 < DAT_08008968) {
            if (param_1 < DAT_0800896c) {
                if (param_1 < DAT_08008970) {
                    uVar4 = FUN_0800e548();
                    pcVar2 = s__0_3f_c_080089ec;
                } else {
                    uVar4 = FUN_0800e548();
                    pcVar2 = s__0_2f_c_080089e4;
                }
            } else {
                uVar4 = FUN_0800e548();
                pcVar2 = s__0_1f_c_080089dc;
            }
            /* goto LAB_0800892e; */ (void)0;
        }
    LAB_08008880:
        uVar4 = FUN_0800e548();
        pcVar2 = s__0_0f_c_08008984;
    LAB_0800892e:
        sys_sprintf(param_2, pcVar2, (int)uVar4, (int)((uint64_t)uVar4 >> 0x20), 0);
        return;
    }
    FUN_0800e548();
    pcVar2 = s__c_0_0f_c_08008978;
LAB_080088ee:
    sys_sprintf(param_2, pcVar2, 0x20);
    return;
}

/* ================================================================
 * FUN_080089f4  @  0x080089F4
 */

int FUN_080089f4() {
    int *param_1 = 0;
    byte *param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    char *pcVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    byte *local_1c;

    iVar4 = *param_1;
    for (; (*param_2 == 0x2f || (*param_2 == 0x5c)); param_2 = param_2 + 1) {
    }
    param_1[2] = 0;
    local_1c = param_2;
    if (*param_2 < 0x20) {
        *(uint8_t *)((int)param_1 + 0x2b) = 0x80;
        iVar1 = fs_fat32_seek_cluster(param_1, 0, param_3, param_4, param_1);
    } else {
        while (iVar1 = FUN_080028cc(param_1, &local_1c), iVar1 == 0) {
            iVar5 = *param_1;
            iVar1 = fs_fat32_seek_cluster(param_1, 0);
            if (iVar1 == 0) {
                while (iVar1 = FUN_0800a91c(iVar5, param_1[6]), iVar1 == 0) {
                    pcVar2 = (char *)param_1[7];
                    if (*pcVar2 == '\0') {
                        iVar1 = 4;
                        break;
                    }
                    *(byte *)((int)param_1 + 6) = pcVar2[0xb] & 0x3f;
                    if (((-1 < (int)((uint32_t)(byte)pcVar2[0xb] << 0x1c)) &&
                         (iVar3 = FUN_08000506(pcVar2, param_1 + 8, 0xb), iVar3 == 0)) ||
                        (iVar1 = FUN_08002e04(param_1, 0), iVar1 != 0))
                        break;
                }
            }
            if (iVar1 != 0) {
                if (iVar1 != 4) {
                    return iVar1;
                }
                if (-1 < (int)((uint32_t)*(byte *)((int)param_1 + 0x2b) << 0x1d)) {
                    return 5;
                }
                return 4;
            }
            if ((int)((uint32_t)*(byte *)((int)param_1 + 0x2b) << 0x1d) < 0) {
                return 0;
            }
            if (-1 < (int)((uint32_t)*(byte *)((int)param_1 + 6) << 0x1b)) {
                return 5;
            }
            iVar1 = FUN_080095c8(iVar4, (*(uint16_t *)(param_1 + 4) & 0xfff) + iVar4 + 0x30);
            param_1[2] = iVar1;
        }
    }
    return iVar1;
}

/* ================================================================
 * FUN_08008ae4  @  0x08008AE4
 */

uint32_t FUN_08008ae4() {
    uint32_t *param_1 = 0;
    uint32_t param_2 = 0;
    char cVar1;
    int iVar2;
    uint32_t uVar3;
    char *pcVar4;

    pcVar4 = (char *)*param_1;
    if ((1 < param_2) && (param_2 < *(uint32_t *)(pcVar4 + 0x14))) {
        cVar1 = *pcVar4;
        if (cVar1 == '\x01') {
            uVar3 = param_2 + (param_2 >> 1);
            iVar2 = FUN_0800a91c(pcVar4, *(int *)(pcVar4 + 0x20) + (uVar3 >> 0xc));
            if (iVar2 != 0) {
                return 0xffffffff;
            }
            cVar1 = pcVar4[(uVar3 & 0xfff) + 0x30];
            iVar2 = FUN_0800a91c(pcVar4, *(int *)(pcVar4 + 0x20) + (uVar3 + 1 >> 0xc));
            if (iVar2 != 0) {
                return 0xffffffff;
            }
            if ((param_2 & 1) != 0) {
                return (uint32_t)(uint16_t)(CONCAT11(pcVar4[(uVar3 + 1 & 0xfff) + 0x30], cVar1) >>
                                            4);
            }
            return CONCAT11(pcVar4[(uVar3 + 1 & 0xfff) + 0x30], cVar1) & 0xfff;
        }
        if (cVar1 == '\x02') {
            iVar2 = FUN_0800a91c(pcVar4, *(int *)(pcVar4 + 0x20) + (param_2 >> 0xb));
            if (iVar2 != 0) {
                return 0xffffffff;
            }
            uVar3 = FUN_08009604(pcVar4 + (param_2 & 0x7ff) * 2 + 0x30);
            return uVar3;
        }
        if (cVar1 == '\x03') {
            iVar2 = FUN_0800a91c(pcVar4, *(int *)(pcVar4 + 0x20) + (param_2 >> 10));
            if (iVar2 != 0) {
                return 0xffffffff;
            }
            uVar3 = FUN_080095ee(pcVar4 + (param_2 & 0x3ff) * 4 + 0x30);
            return uVar3 & 0xfffffff;
        }
    }
    return 1;
}

/* ================================================================
 * FUN_08008ba0  @  0x08008BA0
 */

uint32_t FUN_08008ba0() {
    uint32_t param_1 = 0;
    int iVar1;
    uint32_t uVar2;

    iVar1 = DAT_08008be4;
    uVar2 = 0;
    if (*(short *)(DAT_08008be4 + 2) == 0) {
        *(short *)(DAT_08008be4 + 4) = (short)param_1;
    } else {
        if (*(uint16_t *)(DAT_08008be4 + 4) == param_1) {
            if (*(short *)(DAT_08008be4 + 2) != 1) {
                return 6;
            }
            /* goto LAB_08008bc8; */ (void)0;
        }
        *(short *)(DAT_08008be4 + 4) = (short)param_1;
        *(uint16_t *)(iVar1 + 2) = 0;
    }
    *(uint16_t *)(iVar1 + 2) = 1;
LAB_08008bc8:
    *(uint8_t *)(iVar1 + 7) = 1;
    do {
        if (*(uint16_t *)(DAT_08008be8 + uVar2 * 8) == param_1) {
            return uVar2;
        }
        uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 6);
    return 6;
}

/* ================================================================
 * FUN_08008bec  @  0x08008BEC
 */

byte FUN_08008bec(void)

{
    uint32_t uVar1;
    int iVar2;
    byte bVar3;

    uVar1 = DAT_08008c4c;
    iVar2 = FUN_08008d5e(DAT_08008c4c, 0x10);
    bVar3 = iVar2 == 0;
    iVar2 = FUN_08008d5e(uVar1, 0x40);
    if (iVar2 == 0) {
        bVar3 = bVar3 | 2;
    }
    iVar2 = FUN_08008d5e(uVar1, 0x80);
    if (iVar2 == 0) {
        bVar3 = bVar3 | 8;
    }
    iVar2 = FUN_08008d5e(uVar1, 0x20);
    if (iVar2 == 0) {
        bVar3 = bVar3 | 0x10;
    }
    iVar2 = FUN_08008d5e(DAT_08008c50, 0x80);
    if (iVar2 == 0) {
        bVar3 = bVar3 | 0x20;
    }
    iVar2 = FUN_08008d5e(DAT_08008c54, 0x8000);
    if (iVar2 == 0) {
        bVar3 = bVar3 | 0x40;
    }
    return bVar3;
}

/* ================================================================
 * FUN_08008c58  @  0x08008C58
 */

uint32_t FUN_08008c58() {
    uint32_t *param_1 = 0;
    byte bVar1;
    uint32_t uVar2;
    byte *pbVar3;
    byte *pbVar4;
    uint32_t uVar6;
    byte *pbVar5;

    uVar2 = 0xffffffff;
    pbVar3 = (byte *)*param_1;
    pbVar5 = pbVar3;
    if (pbVar3 != (byte *)0x0) {
        do {
            pbVar4 = pbVar5 + 1;
            bVar1 = *pbVar5;
            if (bVar1 < 0x21) {
                return 0;
            }
            pbVar5 = pbVar4;
        } while (bVar1 != 0x3a);
        uVar6 = *pbVar3 - 0x30;
        if (((uVar6 < 10) && (pbVar3 + 2 == pbVar4)) && ((int)uVar6 < 3)) {
            *param_1 = pbVar4;
            uVar2 = uVar6;
        }
    }
    return uVar2;
}

/* ================================================================
 * FUN_08008c90  @  0x08008C90
 */

void FUN_08008c90(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0x14) = param_2;
    return;
}

/* ================================================================
 * FUN_08008c94  @  0x08008C94
 */

void FUN_08008c94(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0x10) = param_2;
    return;
}

/* ================================================================
 * FUN_08008c98  @  0x08008C98
 */

void FUN_08008c98(uint32_t *param_1)

{
    *param_1 = 0xffff;
    *(uint8_t *)((int)param_1 + 6) = 0;
    *(uint8_t *)(param_1 + 1) = 0;
    *(uint8_t *)((int)param_1 + 5) = 4;
    *(uint8_t *)((int)param_1 + 7) = 1;
    return;
}

/* ================================================================
 * FUN_08008cb0  @  0x08008CB0
 */

void FUN_08008cb0(uint32_t *param_1, uint16_t *param_2)

{
    uint16_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;

    uVar1 = *param_2;
    uVar4 = (uint32_t)uVar1;
    uVar3 = (uint32_t)(byte)param_2[3];
    if (uVar3 == 3) {
        uVar3 = 0;
    } else if (uVar3 == 0) {
        uVar2 = (uint32_t)*(byte *)((int)param_2 + 5);
        uVar3 = uVar2 & 0xf;
        if (uVar2 == 0x18) {
            param_1[4] = uVar4;
        } else if (uVar2 == 0x28) {
            param_1[5] = uVar4;
        }
    } else {
        uVar3 = uVar3 & 8 | (byte)param_2[2] & 4 | *(byte *)((int)param_2 + 7) & 3;
    }
    if ((uVar1 & 0xff) != 0) {
        uVar2 = 0;
        do {
            if ((1 << (uVar2 & 0xff) & uVar4) != 0) {
                *param_1 = *param_1 & ~(0xf << (uVar2 << 2 & 0xff));
                *param_1 = *param_1 | uVar3 << (uVar2 << 2 & 0xff);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
    }
    if (0xff < uVar4) {
        uVar4 = 0;
        do {
            if ((1 << (uVar4 & 0xff) & (uint32_t)(uVar1 >> 8)) != 0) {
                param_1[1] = param_1[1] & ~(0xf << (uVar4 << 2 & 0xff));
                param_1[1] = param_1[1] | uVar3 << (uVar4 << 2 & 0xff);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < 8);
    }
    return;
}

/* ================================================================
 * FUN_08008d04  @  0x08008D04
 */

void FUN_08008d04(uint32_t *param_1, uint32_t param_2, int param_3, uint32_t param_4)

{
    uint32_t uVar1;
    int unaff_r4;
    int unaff_r5;
    uint32_t unaff_r6;
    uint32_t unaff_r7;

    do {
        *param_1 = unaff_r6 | unaff_r7;
        do {
            param_2 = param_2 + 1;
            if (7 < param_2) {
                if (0xff < param_4) {
                    uVar1 = 0;
                    do {
                        if ((unaff_r5 << (uVar1 & 0xff) & param_4 >> 8) != 0) {
                            param_1[1] = param_1[1] & ~(unaff_r4 << (uVar1 << 2 & 0xff));
                            param_1[1] = param_1[1] | param_3 << (uVar1 << 2 & 0xff);
                        }
                        uVar1 = uVar1 + 1;
                    } while (uVar1 < 8);
                }
                return;
            }
        } while ((unaff_r5 << (param_2 & 0xff) & param_4) == 0);
        *param_1 = *param_1 & ~(unaff_r4 << (param_2 * 4 & 0xff));
        unaff_r6 = *param_1;
        unaff_r7 = param_3 << (param_2 * 4 & 0xff);
    } while (true);
}

/* ================================================================
 * FUN_08008d5e  @  0x08008D5E
 */

bool FUN_08008d5e() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    return (param_2 & ~*(uint32_t *)(param_1 + 8)) == 0;
}

/* ================================================================
 * FUN_08008d6c  @  0x08008D6C
 */

void FUN_08008d6c(void)

{
    int iVar1;
    int iVar2;
    short sVar3;

    iVar1 = DAT_08008dd0;
    if (*(char *)(DAT_08008dd0 + 1) == '\0') {
        *(uint8_t *)(DAT_08008dd0 + 1) = 1;
        if (*(char *)(iVar1 + 2) == '\0') {
            *(uint8_t *)(iVar1 + 2) = 1;
            *(uint8_t *)(iVar1 + 8) = 0;
        }
    }
    iVar2 = DAT_08008dd4;
    if (*(char *)(DAT_08008dd4 + 2) == '\x01') {
        if (*(byte *)(iVar1 + 8) == 0)
            /* goto LAB_08008dba; */ (void)0;
        sVar3 = *(byte *)(iVar1 + 8) - 1;
    } else {
        if (*(char *)(DAT_08008dd4 + 2) != '\t')
            /* goto LAB_08008dba; */ (void)0;
        sVar3 = *(byte *)(iVar1 + 8) + 1;
        if ((*(uint16_t *)(DAT_08008dd8 + 0x10) <= (uint16_t)(sVar3 * 6)) ||
            (3 < *(byte *)(iVar1 + 8)))
            /* goto LAB_08008dba; */ (void)0;
    }
    *(char *)(iVar1 + 8) = (char)sVar3;
    FUN_080041d4(sVar3 + 1U & 0xff);
LAB_08008dba:
    if (*(char *)(iVar2 + 5) == '\x01') {
        FUN_080041d4(*(char *)(iVar1 + 8) + '\x01');
        *(uint8_t *)(iVar2 + 5) = 0;
    }
    return;
}

/* ================================================================
 * FUN_08008ddc  @  0x08008DDC
 */

uint32_t FUN_08008ddc() {
    int *param_1 = 0;
    byte *param_2 = 0;
    uint16_t *param_3 = 0;
    byte *param_4 = 0;
    bool bVar1;
    int iVar2;
    byte *pbVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;

    uVar6 = (uint32_t)*(byte *)(param_1 + 3);
    iVar2 = *param_1;
    pbVar3 = (byte *)param_1[1];
    uVar4 = (uint32_t)*pbVar3;
    uVar7 = 0;
    iVar8 = 0x10;
    bVar1 = false;
    do {
        if (uVar6 == 0) {
            if (iVar2 == 0) {
                pbVar3 = (byte *)param_1[2];
                iVar2 = (*(code *)param_1[0x1d])(param_1, pbVar3, 0x200);
                if (iVar2 == 0) {
                    return 0xfffffffe;
                }
            } else {
                pbVar3 = pbVar3 + 1;
            }
            iVar2 = iVar2 + -1;
            if (bVar1) {
                bVar1 = false;
                if (*pbVar3 != 0) {
                    return 0xfffffffa;
                }
                uVar4 = 0xff;
                *pbVar3 = 0xff;
            LAB_08008e3e:
                uVar6 = 0x80;
                /* goto LAB_08008e40; */ (void)0;
            }
            uVar4 = (uint32_t)*pbVar3;
            if (uVar4 != 0xff)
                /* goto LAB_08008e3e; */ (void)0;
            bVar1 = true;
        } else {
        LAB_08008e40:
            uVar7 = uVar7 * 2;
            if ((uVar4 & uVar6) != 0) {
                uVar7 = uVar7 + 1;
            }
            uVar6 = uVar6 >> 1;
            for (uVar5 = (uint32_t)*param_2; uVar5 != 0; uVar5 = uVar5 - 1) {
                if (*param_3 == uVar7) {
                    *(char *)(param_1 + 3) = (char)uVar6;
                    *param_1 = iVar2;
                    param_1[1] = (int)pbVar3;
                    return (uint32_t)*param_4;
                }
                param_4 = param_4 + 1;
                param_3 = param_3 + 1;
            }
            iVar8 = iVar8 + -1;
            param_2 = param_2 + 1;
        }
        if (iVar8 == 0) {
            return 0xfffffffa;
        }
    } while (true);
}

/* ================================================================
 * FUN_08008e82  @  0x08008E82
 */

int FUN_08008e82(int param_1, int param_2, int param_3, int param_4)

{
    int iVar1;

    if (param_2 != 0) {
        FUN_08007e8a();
        return param_4;
    }
    iVar1 = FUN_08007a16(**(int **)(param_1 + 0x78),
                         *(int *)(**(int **)(param_1 + 0x78) + 0x14) + param_3);
    if (iVar1 != 0) {
        return 0;
    }
    return param_3;
}

/* ================================================================
 * jpeg_decode_render  @  0x08008EA8
 */

int jpeg_decode_render(int *param_1, uint32_t param_2, uint32_t param_3)

{
    byte bVar1;
    byte bVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    short sVar8;
    byte *pbVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    bool bVar13;

    if (param_3 < 4) {
        *(char *)((int)param_1 + 0xd) = (char)param_3;
        bVar1 = *(byte *)((int)param_1 + 0xe);
        bVar2 = *(byte *)((int)param_1 + 0xf);
        sVar8 = 0;
        *(uint16_t *)(param_1 + 5) = 0;
        *(uint16_t *)((int)param_1 + 0x16) = 0;
        *(uint16_t *)(param_1 + 6) = 0;
        uVar12 = 0;
        for (uVar5 = 0; iVar4 = 0, uVar5 < (uint32_t)param_1[8];
             uVar5 = uVar5 + (uint32_t)bVar2 * 8) {
            for (uVar6 = 0; uVar6 < (uint32_t)param_1[7]; uVar6 = uVar6 + (uint32_t)bVar1 * 8) {
                if ((*(short *)((int)param_1 + 0x1a) != 0) &&
                    (bVar13 = sVar8 == *(short *)((int)param_1 + 0x1a), sVar8 = sVar8 + 1,
                     bVar13)) {
                    iVar4 = *param_1;
                    pbVar9 = (byte *)param_1[1];
                    uVar11 = 0;
                    uVar10 = 0;
                    do {
                        if (iVar4 == 0) {
                            pbVar9 = (byte *)param_1[2];
                            iVar4 = (*(code *)param_1[0x1d])(param_1, pbVar9, 0x200);
                            if (iVar4 == 0) {
                                return 2;
                            }
                        } else {
                            pbVar9 = pbVar9 + 1;
                        }
                        iVar4 = iVar4 + -1;
                        uVar7 = (uint32_t)*pbVar9;
                        uVar11 = uVar11 + 1;
                        uVar3 = uVar10 << 8;
                        uVar10 = uVar7;
                    } while (uVar11 < 2);
                    *param_1 = iVar4;
                    param_1[1] = (int)pbVar9;
                    *(uint8_t *)(param_1 + 3) = 0;
                    if (((uVar7 & 0xffffffd8 | uVar3) != 0xffd0) || ((uVar7 & 7) != (uVar12 & 7))) {
                        return 6;
                    }
                    *(uint16_t *)(param_1 + 5) = 0;
                    *(uint16_t *)((int)param_1 + 0x16) = 0;
                    *(uint16_t *)(param_1 + 6) = 0;
                    sVar8 = 1;
                    uVar12 = uVar12 + 1 & 0xffff;
                }
                iVar4 = FUN_080097fc(param_1);
                if (iVar4 != 0) {
                    return iVar4;
                }
                iVar4 = FUN_0800996c(param_1, param_2, uVar6, uVar5);
                if (iVar4 != 0) {
                    return iVar4;
                }
            }
        }
    } else {
        iVar4 = 5;
    }
    return iVar4;
}

/* ================================================================
 * jpeg_parse_header  @  0x08008F9C
 */

/* WARNING: Type propagation algorithm not settling */

uint32_t jpeg_parse_header(uint32_t *param_1, uint32_t param_2, int param_3, uint32_t param_4,
                           uint32_t param_5)

{
    uint16_t uVar1;
    byte bVar2;
    uint16_t *puVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint16_t *puVar11;
    uint16_t *puVar12;
    bool bVar13;

    if (param_3 == 0) {
        return 5;
    }
    param_1[0x1d] = param_2;
    param_1[0x1e] = param_5;
    param_1[0x1b] = param_3;
    param_1[0x1c] = param_4;
    *(uint16_t *)((int)param_1 + 0x1a) = 0;
    uVar9 = 0;
    do {
        uVar8 = 0;
        do {
            uVar7 = uVar8 + 1;
            param_1[uVar9 * 2 + uVar8 + 9] = 0;
            param_1[uVar9 * 2 + uVar8 + 0xd] = 0;
            param_1[uVar9 * 2 + uVar8 + 0x11] = 0;
            uVar8 = uVar7;
        } while (uVar7 < 2);
        uVar9 = uVar9 + 1;
    } while (uVar9 < 2);
    uVar9 = 0;
    do {
        uVar8 = uVar9 + 1;
        param_1[uVar9 + 0x15] = 0;
        uVar9 = uVar8;
    } while (uVar8 < 4);
    puVar3 = (uint16_t *)FUN_08002180(param_1, 0x200);
    param_1[2] = puVar3;
    if (puVar3 == (uint16_t *)0x0) {
        return 3;
    }
    iVar4 = (*(code *)param_1[0x1d])(param_1, puVar3, 2);
    bVar13 = iVar4 == 2;
LAB_08009002:
    if (!bVar13) {
        return 2;
    }
    bVar13 = (uint16_t)(*puVar3 << 8 | *puVar3 >> 8) == 0xffd8;
LAB_08009018:
    if (!bVar13) {
        return 6;
    }
    uVar9 = 2;
LAB_0800901e:
    iVar4 = (*(code *)param_1[0x1d])(param_1, puVar3, 4);
    bVar13 = iVar4 == 4;
    if (!bVar13)
        /* goto LAB_08009002; */ (void)0;
    uVar8 = (puVar3[1] & 0xff) << 8 | (uint32_t)(puVar3[1] >> 8);
    if (uVar8 < 3) {
        return 6;
    }
    bVar13 = false;
    if ((*puVar3 & 0xff) == 0xff) {
        uVar8 = uVar8 - 2;
        uVar9 = uVar9 + uVar8 + 4;
        switch ((char)(*puVar3 >> 8)) {
        case -0x40:
            if (0x200 < uVar8) {
                return 4;
            }
            uVar7 = (*(code *)param_1[0x1d])(param_1, puVar3, uVar8);
            bVar13 = uVar7 == uVar8;
            if (!bVar13)
                /* goto LAB_08009002; */ (void)0;
            param_1[7] = (*(uint16_t *)((int)puVar3 + 3) & 0xff) << 8 |
                         (uint32_t)(*(uint16_t *)((int)puVar3 + 3) >> 8);
            param_1[8] = (*(uint16_t *)((int)puVar3 + 1) & 0xff) << 8 |
                         (uint32_t)(*(uint16_t *)((int)puVar3 + 1) >> 8);
            if (*(char *)((int)puVar3 + 5) != '\x03') {
                return 8;
            }
            uVar8 = 0;
            do {
                bVar2 = *(byte *)((int)puVar3 + uVar8 * 3 + 7);
                if (uVar8 == 0) {
                    if (((bVar2 != 0x11) && (bVar2 != 0x22)) && (bVar2 != 0x21)) {
                        return 8;
                    }
                    *(byte *)((int)param_1 + 0xe) = bVar2 >> 4;
                    *(byte *)((int)param_1 + 0xf) = bVar2 & 0xf;
                } else if (bVar2 != 0x11) {
                    return 8;
                }
                bVar2 = *(byte *)((int)puVar3 + uVar8 * 3 + 8);
                if (3 < bVar2) {
                    return 8;
                }
                uVar7 = uVar8 + 1;
                *(byte *)((int)param_1 + uVar8 + 0x10) = bVar2;
                uVar8 = uVar7;
            } while (uVar7 < 3);
            /* goto LAB_0800901e; */ (void)0;
        case -0x3f:
        case -0x3e:
        case -0x3d:
        case -0x3b:
        case -0x3a:
        case -0x39:
        case -0x37:
        case -0x36:
        case -0x35:
        case -0x33:
        case -0x32:
        case -0x31:
        case -0x27:
            return 8;
        case -0x3c:
            if (0x200 < uVar8) {
                return 4;
            }
            uVar7 = (*(code *)param_1[0x1d])(param_1, puVar3, uVar8);
            if (uVar7 != uVar8) {
                return 2;
            }
            bVar2 = FUN_08002800(param_1, puVar3, uVar8);
            uVar7 = (uint32_t)bVar2;
            break;
        default:
            uVar7 = (*(code *)param_1[0x1d])(param_1, 0, uVar8);
            bVar13 = true;
            if (uVar7 != uVar8) {
                return 2;
            }
            /* goto LAB_08009194; */ (void)0;
        case -0x26:
            if (0x200 < uVar8) {
                return 4;
            }
            uVar7 = (*(code *)param_1[0x1d])(param_1, puVar3, uVar8);
            if (uVar7 != uVar8) {
                return 2;
            }
            if (param_1[7] == 0) {
                return 6;
            }
            if (param_1[8] != 0) {
                if ((char)*puVar3 != '\x03') {
                    return 8;
                }
                uVar8 = 0;
                while (true) {
                    if (((char)puVar3[uVar8 + 1] != '\0') && ((char)puVar3[uVar8 + 1] != '\x11')) {
                        return 8;
                    }
                    if (param_1[(uint32_t)(uVar8 != 0) * 2 + 9] == 0) {
                        return 6;
                    }
                    if (param_1[(uint32_t)(uVar8 != 0) * 2 + 10] == 0)
                        break;
                    if (param_1[*(byte *)((int)param_1 + uVar8 + 0x10) + 0x15] == 0) {
                        return 6;
                    }
                    uVar8 = uVar8 + 1;
                    if (2 < uVar8) {
                        iVar4 = (int)(short)(uint16_t)*(byte *)((int)param_1 + 0xf) *
                                (int)(short)(uint16_t)*(byte *)((int)param_1 + 0xe);
                        if (iVar4 == 0) {
                            return 6;
                        }
                        uVar8 = iVar4 * 0x80 + 0x40;
                        if (uVar8 < 0x100) {
                            uVar8 = 0x100;
                        }
                        iVar5 = FUN_08002180(param_1, uVar8);
                        param_1[0x19] = iVar5;
                        if (iVar5 != 0) {
                            iVar4 = FUN_08002180(param_1, iVar4 * 0x40 + 0x80);
                            param_1[0x1a] = iVar4;
                            if (iVar4 != 0) {
                                *param_1 = 0;
                                param_1[1] = puVar3;
                                *(uint8_t *)(param_1 + 3) = 0;
                                uVar9 = uVar9 & 0x1ff;
                                if (uVar9 != 0) {
                                    uVar6 = (*(code *)param_1[0x1d])(
                                        param_1, (char *)((int)puVar3 + uVar9), 0x200 - uVar9);
                                    *param_1 = uVar6;
                                    param_1[1] = (char *)((int)puVar3 + uVar9) + -1;
                                }
                                return 0;
                            }
                        }
                        return 3;
                    }
                }
                return 6;
            }
            return 6;
        case -0x25:
            if (0x200 < uVar8) {
                return 4;
            }
            uVar7 = (*(code *)param_1[0x1d])(param_1, puVar3, uVar8);
            puVar12 = puVar3;
            if (uVar7 != uVar8) {
                return 2;
            }
            while (uVar8 != 0) {
                if (uVar8 < 0x41) {
                LAB_08009146:
                    uVar7 = 6;
                    /* goto LAB_08009192; */ (void)0;
                }
                uVar1 = *puVar12;
                uVar8 = uVar8 - 0x41;
                if ((byte)((byte)uVar1 >> 4) != 0)
                    /* goto LAB_08009146; */ (void)0;
                iVar5 = FUN_08002180(param_1, 0x100);
                iVar4 = DAT_08009270;
                if (iVar5 == 0) {
                    uVar7 = 3;
                    /* goto LAB_08009192; */ (void)0;
                }
                param_1[((byte)uVar1 & 3) + 0x15] = iVar5;
                uVar7 = 0;
                puVar11 = (uint16_t *)((int)puVar12 + 1);
                do {
                    uVar10 = (uint32_t)*(byte *)(iVar4 + uVar7);
                    uVar7 = uVar7 + 1;
                    *(uint32_t *)(iVar5 + uVar10 * 4) =
                        (uint32_t)(byte)*puVar11 *
                        (uint32_t)*(uint16_t *)(iVar4 + 0x40 + uVar10 * 2);
                    puVar12 = (uint16_t *)((int)puVar11 + 1);
                    puVar11 = (uint16_t *)((int)puVar11 + 1);
                } while (uVar7 < 0x40);
            }
            uVar7 = 0;
            break;
        case -0x23:
            goto switchD_08009052_caseD_dd;
        }
    LAB_08009192:
        bVar13 = uVar7 == 0;
    LAB_08009194:
        if (!bVar13) {
            return uVar7;
        }
        /* goto LAB_0800901e; */ (void)0;
    }
    /* goto LAB_08009018; */ (void)0;
switchD_08009052_caseD_dd:
    if (0x200 < uVar8) {
        return 4;
    }
    uVar7 = (*(code *)param_1[0x1d])(param_1, puVar3, uVar8);
    if (uVar7 != uVar8) {
        return 2;
    }
    *(uint16_t *)((int)param_1 + 0x1a) = *puVar3 << 8 | *puVar3 >> 8;
    /* goto LAB_0800901e; */ (void)0;
}

/* ================================================================
 * ui_load_and_draw_jpeg  @  0x08009274
 * nearby string: " %s  open_error
\n"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t ui_load_and_draw_jpeg() {
    uint32_t param_1 = 0;
    uint16_t param_2 = 0;
    uint16_t param_3 = 0;
    uint16_t *puVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint8_t auStack_a4[124];
    uint32_t local_28[4];

    iVar2 = fs_file_open(_DAT_080092f0, param_1, 1);
    if (iVar2 == 0) {
        local_28[0] = _DAT_080092f0;
        uVar4 = rtos_malloc(0x1c00);
        iVar2 = jpeg_parse_header(auStack_a4, DAT_08009308, uVar4, 0x1c00, local_28);
        uVar3 = DAT_08009310;
        puVar1 = DAT_0800930c;
        if (iVar2 == 0) {
            *DAT_0800930c = param_2;
            puVar1[1] = param_3;
            jpeg_decode_render(auStack_a4, uVar3, 0);
        } else if (iVar2 == 2) {
            display_debug_printf(&DAT_08009314, param_1);
        }
        rtos_free(uVar4);
        fs_file_close(local_28[0]);
        uVar3 = 0;
    } else {
        display_debug_printf(s__s_open_error_080092f3 + 1, param_1);
        uVar3 = 1;
    }
    return uVar3;
}

/* ================================================================
 * FUN_080093bc  @  0x080093BC
 */

uint8_t FUN_080093bc() {
    uint32_t param_1 = 0;
    byte *pbVar1;
    int iVar2;
    uint16_t uVar3;
    uint32_t uVar4;
    int iVar5;

    iVar2 = DAT_0800940c;
    if (*(uint16_t *)(DAT_0800940c + 4) == param_1) {
        pbVar1 = (byte *)(DAT_0800940c + 6);
        if (*pbVar1 < 6) {
            uVar3 = *(short *)(DAT_0800940c + 2) + 1;
            uVar4 = (uint32_t)uVar3;
            *(uint16_t *)(DAT_0800940c + 2) = uVar3;
            if (uVar4 == 1) {
                *(uint8_t *)(iVar2 + 7) = 1;
            } else {
                iVar5 = DAT_08009410 + (uint32_t)*pbVar1 * 8;
                uVar3 = *(uint16_t *)(iVar5 + 6);
                if (uVar3 == uVar4) {
                    return *(uint8_t *)(iVar5 + 3);
                }
                if (uVar3 + 0x14 == uVar4) {
                    *(uint16_t *)(iVar2 + 2) = uVar3;
                    return *(uint8_t *)(iVar5 + 4);
                }
            }
            return 0;
        }
    } else {
        *(short *)(DAT_0800940c + 4) = (short)param_1;
        *(uint8_t *)(iVar2 + 7) = 0;
        *(uint16_t *)(iVar2 + 2) = 0;
    }
    return 0;
}

/* ================================================================
 * FUN_08009414  @  0x08009414
 */

uint8_t FUN_08009414(void)

{
    int iVar1;
    int iVar2;
    uint8_t uVar3;
    int iVar4;
    uint32_t uVar5;

    iVar2 = DAT_08009474;
    iVar1 = DAT_08009470;
    uVar3 = 0;
    if ((*(char *)(DAT_08009470 + 7) != '\0') &&
        (uVar5 = (uint32_t)*(byte *)(DAT_08009470 + 6), uVar5 < 6)) {
        iVar4 = DAT_08009474 + uVar5 * 8;
        if ((*(uint16_t *)(DAT_08009470 + 2) < *(uint16_t *)(iVar4 + 6)) &&
            (uVar3 = *(uint8_t *)(iVar4 + 2), *(char *)(iVar4 + 5) != '\0')) {
            iVar4 = DAT_08009470 + 9;
            if (*(char *)(uVar5 + iVar4) == '\0') {
                *(uint8_t *)(uVar5 + iVar4) = 1;
                *(uint16_t *)(iVar1 + (uint32_t)*(byte *)(iVar1 + 6) * 2 + 0x10) = 0x1e;
                *(uint8_t *)(iVar1 + 8) = 1;
                uVar3 = 0;
            } else {
                *(uint8_t *)(uVar5 + iVar4) = 0;
                *(uint16_t *)(iVar1 + (uint32_t)*(byte *)(iVar1 + 6) * 2 + 0x10) = 0;
                uVar3 = *(uint8_t *)(iVar2 + (uint32_t)*(byte *)(iVar1 + 6) * 8 + 5);
            }
        }
    }
    *(uint16_t *)(iVar1 + 2) = 0;
    *(uint8_t *)(iVar1 + 7) = 0;
    *(uint16_t *)(iVar1 + 4) = 0;
    return uVar3;
}

/* ================================================================
 * FUN_08009478  @  0x08009478
 */

int FUN_08009478(void)

{
    int iVar1;
    uint8_t uVar2;
    int iVar3;

    iVar3 = FUN_08008bec();
    iVar1 = DAT_080094ac;
    if (iVar3 == 0) {
        iVar3 = FUN_08009414();
    } else {
        if (*(char *)(DAT_080094ac + 7) == '\0') {
            uVar2 = FUN_08008ba0();
            *(uint8_t *)(iVar1 + 6) = uVar2;
            /* goto LAB_08009498; */ (void)0;
        }
        iVar3 = FUN_080093bc();
    }
    if (iVar3 != 0) {
        return iVar3;
    }
LAB_08009498:
    iVar3 = 0;
    if (*(char *)(iVar1 + 8) != '\0') {
        iVar3 = FUN_080094b0();
    }
    return iVar3;
}

/* ================================================================
 * FUN_080094b0  @  0x080094B0
 */

uint8_t FUN_080094b0(void)

{
    int iVar1;
    uint32_t uVar2;
    int iVar3;

    iVar1 = DAT_080094ec;
    uVar2 = 0;
    *(uint8_t *)(DAT_080094ec + 8) = 0;
    do {
        iVar3 = iVar1 + uVar2 * 2;
        if (*(short *)(iVar3 + 0x10) != 0) {
            *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + -1;
            *(uint8_t *)(iVar1 + 8) = 1;
            if (*(short *)(iVar3 + 0x10) == 0) {
                *(uint8_t *)(iVar1 + uVar2 + 9) = 0;
                return *(uint8_t *)(DAT_080094f0 + uVar2 * 8 + 2);
            }
        }
        uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 6);
    return 0;
}

/* ================================================================
 * FUN_080094f4  @  0x080094F4
 */

uint64_t FUN_080094f4() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint8_t local_28;
    uint8_t local_27;
    uint8_t local_26;
    uint8_t local_25;
    uint8_t local_24;
    uint8_t local_23;
    uint8_t local_22;
    uint8_t uStack_21;
    uint32_t local_20;
    uint32_t local_1c;

    local_24 = (uint8_t)param_2;
    local_23 = (uint8_t)((uint32_t)param_2 >> 8);
    local_22 = (uint8_t)((uint32_t)param_2 >> 0x10);
    uStack_21 = (uint8_t)((uint32_t)param_2 >> 0x18);
    local_28 = (uint8_t)param_1;
    local_27 = (uint8_t)((uint32_t)param_1 >> 8);
    local_26 = (uint8_t)((uint32_t)param_1 >> 0x10);
    local_25 = (uint8_t)((uint32_t)param_1 >> 0x18);
    local_20 = param_3;
    local_1c = param_4;
    gpio_write(0x1c0000, 1);
    gpio_write(DAT_080095ac, 1);
    FUN_08008c98(&local_20);
    local_20 = 8;
    local_1c = 0x1080400;
    FUN_08008cb0(DAT_080095b0, &local_20);
    FUN_0800c18c(0x40000000, param_1, param_2);
    FUN_0800c1b8(0x40000000, 0);
    FUN_0800c2f8(&local_28);
    local_28 = 7;
    local_23 = 1;
    local_25 = 1;
    local_27 = 1;
    local_22 = 1;
    local_24 = 0;
    local_26 = 0;
    FUN_0800c22e(0x40000000, 6, &local_28);
    FUN_0800c19a(0x40000000, 6, param_3);
    FUN_0800c1fc(0x40000000, 6, 1);
    FUN_0800c314(0x40000000, 1);
    FUN_0800c1c2(0x40000000, 1);
    FUN_0800c30a(0x40000000, 1);
    return CONCAT17(
        uStack_21,
        CONCAT16(local_22,
                 CONCAT15(local_23,
                          CONCAT14(local_24,
                                   CONCAT13(local_25,
                                            CONCAT12(local_26, CONCAT11(local_27, local_28)))))));
}

/* ================================================================
 * display_draw_hline  @  0x080095B4
 */

void display_draw_hline() {
    int param_1 = 0;
    int param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    display_fill_rect(param_1, param_2, (param_3 + param_1) - 1U & 0xffff, param_2 + 1U & 0xffff,
                      param_4);
    return;
}

/* ================================================================
 * FUN_080095c8  @  0x080095C8
 */

uint32_t FUN_080095c8(char *param_1, int param_2)

{
    uint32_t uVar1;
    int iVar2;

    uVar1 = FUN_08009604(param_2 + 0x1a);
    if (*param_1 == '\x03') {
        iVar2 = FUN_08009604(param_2 + 0x14);
        uVar1 = uVar1 | iVar2 << 0x10;
    }
    return uVar1;
}

/* ================================================================
 * FUN_080095ee  @  0x080095EE
 */

uint32_t FUN_080095ee() {
    uint32_t *param_1 = 0;
    return *param_1;
}

/* ================================================================
 * FUN_08009604  @  0x08009604
 */

uint16_t FUN_08009604() {
    uint16_t *param_1 = 0;
    return *param_1;
}

/* ================================================================
 * FUN_080097fc  @  0x080097FC
 */

char FUN_080097fc() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    char cVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    int *piVar10;
    uint32_t uVar11;
    int iVar12;
    int *piVar13;
    char *local_2c;

    piVar10 = *(int **)(param_1 + 100);
    uVar11 = (int)(short)(uint16_t)*(byte *)(param_1 + 0xe) *
             (int)(short)(uint16_t)*(byte *)(param_1 + 0xf);
    local_2c = *(char **)(param_1 + 0x68);
    uVar9 = 0;
    iVar3 = param_1;
    do {
        if (uVar11 + 2 <= uVar9) {
            return '\0';
        }
        if (uVar9 < uVar11) {
            iVar12 = 0;
        LAB_08009830:
            iVar2 = 0;
        } else {
            iVar12 = (uVar9 - uVar11) + 1;
            if (iVar12 == 0)
                /* goto LAB_08009830; */ (void)0;
            iVar2 = 1;
        }
        iVar2 = param_1 + iVar2 * 8;
        iVar3 = FUN_08008ddc(param_1, *(uint32_t *)(iVar2 + 0x24), *(uint32_t *)(iVar2 + 0x34),
                             *(uint32_t *)(iVar2 + 0x44), iVar3, param_2, param_3);
        if (iVar3 < 0) {
            cVar1 = (char)iVar3;
        LAB_08009900:
            return -cVar1;
        }
        iVar4 = param_1 + iVar12 * 2;
        iVar5 = (int)*(short *)(iVar4 + 0x14);
        if (iVar3 != 0) {
            uVar6 = FUN_0800219c(param_1, iVar3);
            if ((int)uVar6 < 0) {
            LAB_080098fe:
                cVar1 = (char)uVar6;
                /* goto LAB_08009900; */ (void)0;
            }
            uVar8 = 1 << (iVar3 - 1U & 0xff);
            if ((uVar6 & uVar8) == 0) {
                uVar6 = uVar6 + uVar8 * -2 + 1;
            }
            iVar5 = uVar6 + iVar5;
            *(short *)(iVar4 + 0x14) = (short)iVar5;
        }
        piVar13 = *(int **)(param_1 + (uint32_t)*(byte *)(param_1 + iVar12 + 0x10) * 4 + 0x54);
        *piVar10 = iVar5 * *piVar13 >> 8;
        uVar6 = 1;
        do {
            piVar10[uVar6] = 0;
            uVar6 = uVar6 + 1;
        } while (uVar6 < 0x40);
        iVar3 = *(int *)(iVar2 + 0x28);
        param_2 = *(uint32_t *)(iVar2 + 0x38);
        param_3 = *(uint32_t *)(iVar2 + 0x48);
        uVar8 = 1;
        do {
            uVar6 = FUN_08008ddc(param_1, iVar3, param_2, param_3);
            if (uVar6 == 0)
                break;
            if ((int)uVar6 < 0)
                /* goto LAB_080098fe; */ (void)0;
            if ((uVar6 >> 4 != 0) && (uVar8 = uVar8 + (uVar6 >> 4), 0x3f < uVar8)) {
                return '\x06';
            }
            uVar7 = uVar6 & 0xf;
            if (uVar7 != 0) {
                uVar6 = FUN_0800219c(param_1, uVar7);
                if ((int)uVar6 < 0)
                    /* goto LAB_080098fe; */ (void)0;
                uVar7 = 1 << (uVar7 - 1 & 0xff);
                if ((uVar6 & uVar7) == 0) {
                    uVar6 = uVar6 + uVar7 * -2 + 1;
                }
                piVar10[*(byte *)(DAT_08009968 + uVar8)] =
                    (int)(uVar6 * piVar13[*(byte *)(DAT_08009968 + uVar8)]) >> 8;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < 0x40);
        if (*(char *)(param_1 + 0xd) == '\x03') {
            *local_2c = (char)(*piVar10 + ((uint32_t)(*piVar10 >> 0x1f) >> 0x18) >> 8) + -0x80;
        } else {
            FUN_08002218(piVar10, local_2c);
        }
        local_2c = local_2c + 0x40;
        uVar9 = uVar9 + 1;
    } while (true);
}

/* ================================================================
 * FUN_0800996c  @  0x0800996C
 */

uint32_t FUN_0800996c(int param_1, code *param_2, uint32_t param_3, uint32_t param_4)

{
    byte bVar1;
    byte bVar2;
    sbyte sVar3;
    byte bVar4;
    byte bVar5;
    short sVar6;
    uint16_t uVar7;
    uint32_t uVar8;
    uint8_t *puVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    byte *pbVar13;
    int iVar14;
    uint8_t *puVar15;
    uint8_t *puVar16;
    uint16_t *puVar17;
    byte *pbVar18;
    uint16_t *puVar19;
    uint32_t uVar20;
    uint8_t *puVar21;
    uint16_t *puVar22;
    uint32_t uVar23;
    uint32_t uVar24;
    uint32_t uVar25;
    int iVar26;
    uint32_t uVar27;
    uint32_t uVar28;
    uint32_t uVar29;
    uint32_t uVar30;
    uint32_t uVar31;
    uint32_t uVar32;
    bool bVar33;
    short local_44;
    short local_42;
    short local_40;
    short local_3e;
    uint8_t *local_3c;
    int iStack_34;
    code *local_30;
    uint32_t uStack_2c;
    uint32_t uStack_28;

    bVar1 = *(byte *)(param_1 + 0xe);
    uVar24 = (uint32_t)bVar1 * 8;
    bVar2 = *(byte *)(param_1 + 0xf);
    uVar27 = (uint32_t)bVar2 * 8;
    uVar25 = uVar24;
    if (*(uint32_t *)(param_1 + 0x1c) < param_3 + uVar24) {
        uVar25 = *(uint32_t *)(param_1 + 0x1c) - param_3;
    }
    uVar28 = uVar27;
    if (*(uint32_t *)(param_1 + 0x20) < param_4 + uVar27) {
        uVar28 = *(uint32_t *)(param_1 + 0x20) - param_4;
    }
    sVar3 = *(sbyte *)(param_1 + 0xd);
    uVar25 = uVar25 >> sVar3;
    bVar33 = uVar25 == 0;
    uVar28 = uVar28 >> sVar3;
    do {
        if (bVar33)
            /* goto LAB_08009c78; */ (void)0;
        bVar33 = true;
    } while (uVar28 == 0);
    local_44 = (short)(param_3 >> sVar3);
    local_42 = local_44 + (short)uVar25 + -1;
    local_40 = (short)(param_4 >> sVar3);
    local_3e = local_40 + (short)uVar28 + -1;
    puVar9 = *(uint8_t **)(param_1 + 100);
    if (*(char *)(param_1 + 0xd) == '\x03') {
        pbVar18 = (byte *)((int)(short)uVar24 * (int)(short)uVar27 + *(int *)(param_1 + 0x68));
        iVar26 = *pbVar18 - 0x80;
        sVar6 = pbVar18[0x40] - 0x80;
        for (uVar10 = 0; uVar10 < uVar27; uVar10 = uVar10 + 8) {
            pbVar18 = *(byte **)(param_1 + 0x68);
            if (uVar10 == 8) {
                pbVar18 = pbVar18 + 0x80;
            }
            for (uVar11 = 0; uVar11 < uVar24; uVar11 = uVar11 + 8) {
                uVar20 = (uint32_t)*pbVar18;
                iVar14 = sVar6 * 0x59b;
                *puVar9 =
                    *(uint8_t *)((uVar20 +
                                      ((int)(iVar14 + ((uint32_t)(iVar14 >> 0x1f) >> 0x16)) >> 10) &
                                  0x3ff) +
                                 DAT_08009c84);
                iVar14 = sVar6 * 0x2db + iVar26 * 0x160;
                puVar9[1] =
                    *(uint8_t *)((uVar20 -
                                      ((int)(iVar14 + ((uint32_t)(iVar14 >> 0x1f) >> 0x16)) >> 10) &
                                  0x3ff) +
                                 DAT_08009c84);
                iVar14 = (short)iVar26 * 0x716;
                puVar9[2] =
                    *(uint8_t *)((uVar20 +
                                      ((int)(iVar14 + ((uint32_t)(iVar14 >> 0x1f) >> 0x16)) >> 10) &
                                  0x3ff) +
                                 DAT_08009c84);
                pbVar18 = pbVar18 + 0x40;
                puVar9 = puVar9 + 3;
            }
        }
    } else {
        for (uVar10 = 0; uVar10 < uVar27; uVar10 = uVar10 + 1) {
            iVar26 = *(int *)(param_1 + 0x68);
            pbVar18 = (byte *)(iVar26 + uVar10 * 8);
            if (bVar2 == 2) {
                pbVar13 = (byte *)(iVar26 + (uVar10 >> 1) * 8 + 0x100);
                if (7 < uVar10) {
                    pbVar18 = pbVar18 + 0x40;
                }
            } else {
                pbVar13 = (byte *)(iVar26 + (uVar24 + uVar10) * 8);
            }
            for (uVar11 = 0; uVar11 < uVar24; uVar11 = uVar11 + 1) {
                bVar4 = *pbVar13;
                bVar5 = pbVar13[0x40];
                if (bVar1 == 2) {
                    if (uVar11 == 8) {
                        pbVar18 = pbVar18 + 0x38;
                    }
                    pbVar13 = pbVar13 + (uVar11 & 1);
                } else {
                    pbVar13 = pbVar13 + 1;
                }
                uVar20 = (uint32_t)*pbVar18;
                iVar26 = (short)(bVar5 - 0x80) * 0x59b;
                *puVar9 =
                    *(uint8_t *)((uVar20 +
                                      ((int)(iVar26 + ((uint32_t)(iVar26 >> 0x1f) >> 0x16)) >> 10) &
                                  0x3ff) +
                                 DAT_08009c84);
                iVar26 = (short)(bVar5 - 0x80) * 0x2db + (bVar4 - 0x80) * 0x160;
                puVar9[1] =
                    *(uint8_t *)((uVar20 -
                                      ((int)(iVar26 + ((uint32_t)(iVar26 >> 0x1f) >> 0x16)) >> 10) &
                                  0x3ff) +
                                 DAT_08009c84);
                iVar26 = (short)(bVar4 - 0x80) * 0x716;
                puVar9[2] =
                    *(uint8_t *)((uVar20 +
                                      ((int)(iVar26 + ((uint32_t)(iVar26 >> 0x1f) >> 0x16)) >> 10) &
                                  0x3ff) +
                                 DAT_08009c84);
                puVar9 = puVar9 + 3;
                pbVar18 = pbVar18 + 1;
            }
        }
        uVar10 = (uint32_t)*(byte *)(param_1 + 0xd);
        if (uVar10 != 0) {
            uVar20 = uVar10 << 1;
            uVar10 = 1 << uVar10;
            local_3c = *(uint8_t **)(param_1 + 100);
            for (uVar11 = 0; uVar11 < uVar27; uVar11 = uVar11 + uVar10) {
                for (uVar12 = 0; uVar12 < uVar24; uVar12 = uVar12 + uVar10) {
                    uVar30 = 0;
                    pbVar18 = (byte *)((uVar11 * uVar24 + uVar12) * 3 + *(int *)(param_1 + 100));
                    uVar32 = 0;
                    uVar31 = 0;
                    for (uVar29 = 0; uVar29 < uVar10; uVar29 = uVar29 + 1) {
                        for (uVar23 = 0; uVar23 < uVar10; uVar23 = uVar23 + 1) {
                            uVar31 = uVar31 + *pbVar18;
                            pbVar13 = pbVar18 + 2;
                            uVar32 = uVar32 + pbVar18[1];
                            pbVar18 = pbVar18 + 3;
                            uVar30 = uVar30 + *pbVar13;
                        }
                        pbVar18 = pbVar18 + (uVar24 - uVar10) * 3;
                    }
                    *local_3c = (char)(uVar31 >> (uVar20 & 0xff));
                    local_3c[1] = (char)(uVar32 >> (uVar20 & 0xff));
                    local_3c[2] = (char)(uVar30 >> (uVar20 & 0xff));
                    local_3c = local_3c + 3;
                }
            }
        }
    }
    uVar24 = uVar24 >> *(sbyte *)(param_1 + 0xd);
    if (uVar25 < uVar24) {
        puVar15 = *(uint8_t **)(param_1 + 100);
        puVar9 = puVar15;
        for (uVar27 = 0; uVar27 < uVar28; uVar27 = uVar27 + 1) {
            for (uVar10 = 0; uVar10 < uVar25; uVar10 = uVar10 + 1) {
                *puVar9 = *puVar15;
                puVar16 = puVar15 + 2;
                puVar21 = puVar9 + 2;
                puVar9[1] = puVar15[1];
                puVar15 = puVar15 + 3;
                puVar9 = puVar9 + 3;
                *puVar21 = *puVar16;
            }
            puVar15 = puVar15 + (uVar24 - uVar25) * 3;
        }
    }
    puVar17 = *(uint16_t **)(param_1 + 100);
    iVar26 = uVar28 * uVar25;
    puVar22 = puVar17;
    do {
        pbVar18 = (byte *)((int)puVar17 + 1);
        uVar7 = *puVar17;
        puVar19 = puVar17 + 1;
        puVar17 = (uint16_t *)((int)puVar17 + 3);
        iVar26 = iVar26 + -1;
        *puVar22 = ((byte)uVar7 & 0xf8) << 8 | (*pbVar18 & 0xfc) << 3 |
                   (uint16_t)(byte)((byte)*puVar19 >> 3);
        puVar22 = puVar22 + 1;
    } while (iVar26 != 0);
    iStack_34 = param_1;
    local_30 = param_2;
    uStack_2c = param_3;
    uStack_28 = param_4;
    iVar26 = (*param_2)(param_1, *(uint32_t *)(param_1 + 100), &local_44);
    if (iVar26 == 0) {
        uVar8 = 1;
    } else {
    LAB_08009c78:
        uVar8 = 0;
    }
    return uVar8;
}

/* ================================================================
 * FUN_08009c88  @  0x08009C88
 */

void FUN_08009c88(uint32_t param_1)

{
    byte bVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    uint8_t uVar5;
    uint32_t uVar6;
    char *pcVar7;
    uint8_t *puVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint16_t uVar11;
    uint32_t uVar12;
    uint32_t uVar13;
    uint32_t uVar14;
    bool bVar15;
    char cVar16;
    uint64_t uVar17;
    uint64_t uVar18;
    uint16_t uVar19;
    uint8_t auStack_54[12];
    uint8_t auStack_48[12];
    uint8_t auStack_3c[12];
    uint8_t auStack_30[12];

    iVar3 = DAT_0800a098;
    iVar2 = DAT_0800a094;
    uVar14 = *(uint32_t *)(DAT_0800a094 + 0x20);
    uVar9 = *(uint32_t *)(DAT_0800a094 + 0x24);
    uVar10 = *(uint32_t *)(DAT_0800a094 + 8);
    cVar16 = 0xb < param_1;
    uVar17 = 0;
    uVar18 = 0;
    switch (param_1) {
    case 0:
    case 1:
    case 4:
    case 10:
    case 0xb:
        cVar16 = 9 < param_1;
        if (param_1 == 10) {
            uVar5 = 6;
        } else {
            uVar5 = 3;
        }
        *(uint8_t *)(DAT_0800a094 + 0x28) = uVar5;
        *(uint8_t *)(iVar2 + 0x29) = uVar5;
        uVar17 = FUN_0800e548(uVar10);
        FUN_0800e07c((int)uVar17, (int)((uint64_t)uVar17 >> 0x20), uVar14, uVar9);
        if (cVar16 == '\0') {
            uVar17 = FUN_0800e548(*(uint32_t *)(iVar2 + 8));
            *(uint64_t *)(iVar2 + 0x20) = uVar17;
        }
        uVar17 = FUN_0800e548(*(uint32_t *)(iVar2 + 8));
        FUN_0800e2f0((int)uVar17, (int)((uint64_t)uVar17 >> 0x20), *(uint32_t *)(iVar2 + 0x18),
                     *(uint32_t *)(iVar2 + 0x1c));
        uVar17 = 0;
        uVar18 = 0;
        if (cVar16 == '\0') {
            uVar17 = FUN_0800e548(*(uint32_t *)(iVar2 + 8));
            *(uint64_t *)(iVar2 + 0x18) = uVar17;
            uVar17 = 0;
            uVar18 = 0;
        }
        break;
    case 2:
    case 5:
    case 6:
        bVar1 = *(byte *)(DAT_0800a094 + 0xd);
        if (bVar1 < *(byte *)(DAT_0800a094 + 0x28)) {
            *(byte *)(DAT_0800a094 + 0x28) = bVar1;
        }
        if (*(byte *)(iVar2 + 0x29) < bVar1) {
            *(byte *)(iVar2 + 0x29) = bVar1;
        }
        uVar13 = DAT_0800a09c;
        cVar16 = 7 < bVar1;
        uVar6 = DAT_0800a0a0;
        if (((((bVar1 == 8) || (cVar16 = 10 < bVar1, bVar1 == 0xb)) ||
              (cVar16 = 0xd < bVar1, bVar1 == 0xe)) ||
             ((cVar16 = 8 < bVar1, uVar6 = DAT_0800a0a4,
               bVar1 == 9 || (cVar16 = 0xb < bVar1, bVar1 == 0xc)))) ||
            (cVar16 = 0xe < bVar1, bVar1 == 0xf)) {
            uVar10 = FUN_0800e8c4(uVar10, uVar6);
        }
        uVar17 = FUN_0800e548(uVar10);
        uVar10 = (uint32_t)((uint64_t)uVar17 >> 0x20);
        FUN_0800e07c((int)uVar17, uVar10, uVar14, uVar9);
        if (cVar16 == '\0') {
            *(uint64_t *)(iVar2 + 0x20) = uVar17;
        }
        FUN_0800e2f0((int)uVar17, uVar10, *(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c));
        if (cVar16 == '\0') {
            *(uint64_t *)(iVar2 + 0x18) = uVar17;
        }
        bVar15 = true;
        FUN_0800e2f0(*(uint32_t *)(iVar2 + 0x20), *(uint32_t *)(iVar2 + 0x24), 0, uVar13);
        uVar10 = DAT_0800a0a8;
        uVar9 = uVar13;
        if ((!(bool)cVar16 || bVar15) ||
            (FUN_0800e2f0(*(uint32_t *)(iVar2 + 0x20), *(uint32_t *)(iVar2 + 0x24), 0,
                          DAT_0800a0a8),
             uVar9 = uVar10, !(bool)cVar16 || bVar15)) {
            uVar17 =
                FUN_0800dd1c(*(uint32_t *)(iVar2 + 0x20), *(uint32_t *)(iVar2 + 0x24), 0, uVar9);
        } else {
            uVar17 = *(uint64_t *)(iVar2 + 0x20);
        }
        bVar15 = true;
        FUN_0800e2f0(*(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c), 0, uVar13);
        uVar10 = DAT_0800a0a8;
        if ((bool)cVar16 && !bVar15) {
            bVar15 = true;
            FUN_0800e2f0(*(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c), 0, DAT_0800a0a8);
            uVar13 = uVar10;
            if ((bool)cVar16 && !bVar15) {
                uVar18 = *(uint64_t *)(iVar2 + 0x18);
                break;
            }
        }
        uVar18 = FUN_0800dd1c(*(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c), 0, uVar13);
        break;
    case 3:
        *(uint8_t *)(DAT_0800a094 + 0x28) = 7;
        *(uint8_t *)(iVar2 + 0x29) = 7;
        uVar17 = FUN_0800e548(uVar10);
        FUN_0800e07c((int)uVar17, (int)((uint64_t)uVar17 >> 0x20), uVar14, uVar9);
        if (cVar16 == '\0') {
            uVar17 = FUN_0800e548(*(uint32_t *)(iVar2 + 8));
            *(uint64_t *)(iVar2 + 0x20) = uVar17;
        }
        uVar17 = FUN_0800e548(*(uint32_t *)(iVar2 + 8));
        FUN_0800e2f0((int)uVar17, (int)((uint64_t)uVar17 >> 0x20), *(uint32_t *)(iVar2 + 0x18),
                     *(uint32_t *)(iVar2 + 0x1c));
        uVar18 = 0;
        if (cVar16 == '\0') {
            uVar17 = FUN_0800e548(*(uint32_t *)(iVar2 + 8));
            *(uint64_t *)(iVar2 + 0x18) = uVar17;
            uVar18 = 0;
        }
        /* goto LAB_08009e82; */ (void)0;
    case 7:
        *(uint8_t *)(DAT_0800a094 + 0x28) = 0x10;
        *(uint8_t *)(iVar2 + 0x29) = 0x10;
        cVar16 = '\x01';
        if (*(char *)(iVar3 + 0x21) != '\0') {
            fs_fat32_time_update(uVar10);
        }
        uVar17 = FUN_0800e548();
        uVar10 = (uint32_t)((uint64_t)uVar17 >> 0x20);
        FUN_0800e07c((int)uVar17, uVar10, *(uint32_t *)(iVar2 + 0x20), *(uint32_t *)(iVar2 + 0x24));
        if (cVar16 == '\0') {
            *(uint64_t *)(iVar2 + 0x20) = uVar17;
        }
        FUN_0800e2f0((int)uVar17, uVar10, *(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c));
        uVar18 = 0;
        if (cVar16 == '\0') {
            *(uint64_t *)(iVar2 + 0x18) = uVar17;
            uVar18 = 0;
        }
        /* goto LAB_08009e82; */ (void)0;
    }
    cVar16 = 1 < param_1;
    if (param_1 != 2) {
        cVar16 = 9 < param_1;
        if (param_1 == 10) {
            uVar17 = FUN_0800e548(*(uint32_t *)(iVar3 + 0x14));
            uVar17 = FUN_0800dba4((int)uVar17, (int)((uint64_t)uVar17 >> 0x20),
                                  *(uint32_t *)(iVar2 + 0x20), *(uint32_t *)(iVar2 + 0x24));
        } else {
        LAB_08009e82:
            uVar17 = *(uint64_t *)(iVar2 + 0x20);
        }
    }
    uVar12 = (uint32_t)((uint64_t)uVar17 >> 0x20);
    uVar10 = (uint32_t)uVar17;
    FUN_0800e07c(uVar10, uVar12, 0, 0);
    if (cVar16 == '\0') {
        uVar12 = uVar12 ^ 0x80000000;
    }
    cVar16 = 6 < param_1;
    if (param_1 == 7) {
        FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0ac);
        if ((cVar16 != '\0') && (FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0b8), cVar16 != '\0')) {
            FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0a8);
        }
        sys_sprintf(auStack_54, s__04_0f_0800a0bc, uVar10, uVar12);
    LAB_08009f44:
        uVar18 = *(uint64_t *)(iVar2 + 0x18);
    } else {
        FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0ac);
        if (cVar16 == '\0') {
            pcVar7 = s__0_3f_0800a0b0;
        } else {
            FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0b8);
            if (cVar16 == '\0') {
                pcVar7 = s__0_2f_0800a0c4;
            } else {
                FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0a8);
                if (cVar16 == '\0') {
                    pcVar7 = s__0_1f_0800a0cc;
                } else {
                    pcVar7 = s__0_0f_0800a0d4;
                }
            }
        }
        sys_sprintf(auStack_54, pcVar7, uVar10, uVar12);
        cVar16 = 1 < param_1;
        if (((param_1 != 2) && (cVar16 = 4 < param_1, param_1 != 5)) &&
            (cVar16 = 5 < param_1, param_1 != 6)) {
            cVar16 = 9 < param_1;
            if (param_1 != 10)
                /* goto LAB_08009f44; */ (void)0;
            uVar17 = FUN_0800e548(*(uint32_t *)(iVar3 + 0x14));
            uVar18 = FUN_0800dba4((int)uVar17, (int)((uint64_t)uVar17 >> 0x20),
                                  *(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c));
        }
    }
    uVar12 = (uint32_t)((uint64_t)uVar18 >> 0x20);
    uVar10 = (uint32_t)uVar18;
    FUN_0800e07c(uVar10, uVar12, 0, 0);
    iVar4 = DAT_0800a0dc;
    if (cVar16 == '\0') {
        uVar12 = uVar12 ^ 0x80000000;
    }
    cVar16 = 6 < param_1;
    if (param_1 == 7) {
        FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0ac);
        if ((cVar16 != '\0') && (FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0b8), cVar16 != '\0')) {
            FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0a8);
        }
        sys_sprintf(auStack_48, s__04_0f_0800a0bc, uVar10, uVar12);
    LAB_0800a4ca:
        FUN_0800e07c(*(uint32_t *)(iVar2 + 0x20), *(uint32_t *)(iVar2 + 0x24), 0, 0);
        if (cVar16 == '\0') {
            puVar8 = &DAT_0800a0e0;
        } else {
            puVar8 = &DAT_0800a0e4;
        }
        sys_sprintf(auStack_3c, puVar8, auStack_54);
        if (*(char *)(iVar4 + 2) == '\0') {
            FUN_08006be4(0x14, 0xe8, auStack_3c, *(uint16_t *)(iVar3 + 0x1c),
                         *(uint16_t *)(iVar3 + 0x1e));
        } else {
            FUN_08006a1c(4, 0xed, auStack_3c);
        }
        FUN_0800e07c(*(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c), 0, 0);
        if (cVar16 == '\0') {
            puVar8 = &DAT_0800a0e0;
        } else {
            puVar8 = &DAT_0800a0e4;
        }
        sys_sprintf(auStack_30, puVar8, auStack_48);
        if (*(char *)(iVar4 + 2) == '\0') {
            FUN_08006be4(0x8b, 0xe8, auStack_30, *(uint16_t *)(iVar3 + 0x1c),
                         *(uint16_t *)(iVar3 + 0x1e));
        } else {
            FUN_08006a1c(0x51, 0xed, auStack_30);
        }
        if (*(char *)(iVar4 + 2) == '\0') {
            if (*(char *)(iVar3 + 0x21) == '\0') {
                display_draw_text(0x53, 0xea, &DAT_0800a614, *(uint16_t *)(iVar3 + 0x1c),
                                  *(uint16_t *)(iVar3 + 0x1e), 0xc, 0);
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a614;
            } else {
                display_draw_text(0x53, 0xea, &DAT_0800a610, *(uint16_t *)(iVar3 + 0x1c),
                                  *(uint16_t *)(iVar3 + 0x1e), 0xc, 0);
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a610;
            }
            /* goto LAB_0800a5da; */ (void)0;
        }
        if (*(char *)(iVar3 + 0x21) == '\0') {
            display_draw_text(0x38, 0xef, &DAT_0800a614, *(uint16_t *)(iVar3 + 0x1c),
                              *(uint16_t *)(iVar3 + 0x1a), 0xc, 0);
            uVar19 = *(uint16_t *)(iVar3 + 0x1a);
            uVar11 = *(uint16_t *)(iVar3 + 0x1c);
            puVar8 = &DAT_0800a614;
        } else {
            display_draw_text(0x38, 0xef, &DAT_0800a610, *(uint16_t *)(iVar3 + 0x1c),
                              *(uint16_t *)(iVar3 + 0x1a), 0xc, 0);
            uVar19 = *(uint16_t *)(iVar3 + 0x1a);
            uVar11 = *(uint16_t *)(iVar3 + 0x1c);
            puVar8 = &DAT_0800a610;
        }
    LAB_0800a59e:
        uVar9 = 0xef;
        uVar10 = 0x85;
    } else {
        FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0ac);
        if (cVar16 == '\0') {
            pcVar7 = s__0_3f_0800a0b0;
        } else {
            FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0b8);
            if (cVar16 == '\0') {
                pcVar7 = s__0_2f_0800a0c4;
            } else {
                FUN_0800e07c(uVar10, uVar12, 0, DAT_0800a0a8);
                if (cVar16 == '\0') {
                    pcVar7 = s__0_1f_0800a0cc;
                } else {
                    pcVar7 = s__0_0f_0800a0d4;
                }
            }
        }
        sys_sprintf(auStack_48, pcVar7, uVar10, uVar12);
        cVar16 = 0xb < param_1;
        switch (param_1) {
        case 0:
        case 1:
        case 4:
        case 10:
        case 0xb:
            FUN_0800e07c(*(uint32_t *)(iVar2 + 0x20), *(uint32_t *)(iVar2 + 0x24), 0, 0);
            if (cVar16 == '\0') {
                puVar8 = &DAT_0800a0e0;
            } else {
                puVar8 = &DAT_0800a0e4;
            }
            sys_sprintf(auStack_3c, puVar8, auStack_54);
            if (*(char *)(iVar4 + 2) == '\0') {
                FUN_08006be4(0x14, 0xe8, auStack_3c, *(uint16_t *)(iVar3 + 0x1c),
                             *(uint16_t *)(iVar3 + 0x1e));
            } else {
                FUN_08006a1c(4, 0xed, auStack_3c);
            }
            FUN_0800e07c(*(uint32_t *)(iVar2 + 0x18), *(uint32_t *)(iVar2 + 0x1c), 0, 0);
            if (cVar16 == '\0') {
                puVar8 = &DAT_0800a0e0;
            } else {
                puVar8 = &DAT_0800a0e4;
            }
            sys_sprintf(auStack_30, puVar8, auStack_48);
            if (*(char *)(iVar4 + 2) == '\0') {
                FUN_08006be4(0x8b, 0xe8, auStack_30, *(uint16_t *)(iVar3 + 0x1c),
                             *(uint16_t *)(iVar3 + 0x1e));
            } else {
                FUN_08006a1c(0x51, 0xed, auStack_30);
            }
            if ((param_1 == 10) || (param_1 == 0xb)) {
                if (*(char *)(iVar4 + 2) != '\0') {
                    display_draw_text(0x38, 0xef, &DAT_0800a4e4, *(uint16_t *)(iVar3 + 0x1c),
                                      *(uint16_t *)(iVar3 + 0x1a), 0xc, 0);
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4e4;
                    /* goto LAB_0800a59e; */ (void)0;
                }
                display_draw_text(0x53, 0xea, &DAT_0800a4e4, *(uint16_t *)(iVar3 + 0x1c),
                                  *(uint16_t *)(iVar3 + 0x1e), 0xc, 0);
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a4e4;
            } else {
                if (*(char *)(iVar4 + 2) != '\0') {
                    display_draw_text(0x38, 0xef, &DAT_0800a4e0, *(uint16_t *)(iVar3 + 0x1c),
                                      *(uint16_t *)(iVar3 + 0x1a), 0xc, 0);
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4e0;
                    /* goto LAB_0800a59e; */ (void)0;
                }
                display_draw_text(0x53, 0xea, &DAT_0800a4e0, *(uint16_t *)(iVar3 + 0x1c),
                                  *(uint16_t *)(iVar3 + 0x1e), 0xc, 0);
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a4e0;
            }
            break;
        case 2:
        case 3:
        case 5:
        case 6:
            sys_sprintf(auStack_3c, &DAT_0800a0e4, auStack_54);
            sys_sprintf(auStack_30, &DAT_0800a0e4, auStack_48);
            if (*(char *)(iVar4 + 2) == '\0') {
                FUN_08006be4(0x14, 0xe8, auStack_3c, *(uint16_t *)(iVar3 + 0x1c),
                             *(uint16_t *)(iVar3 + 0x1e));
                FUN_08006be4(0x8b, 0xe8, auStack_30, *(uint16_t *)(iVar3 + 0x1c),
                             *(uint16_t *)(iVar3 + 0x1e));
            } else {
                FUN_08006a1c(4, 0xed, auStack_3c);
                FUN_08006a1c(0x51, 0xed, auStack_30);
            }
            cVar16 = *(char *)(iVar2 + 0x28);
            if (cVar16 == '\a') {
                if (*(char *)(iVar4 + 2) != '\0') {
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4e8;
                    /* goto LAB_0800a22a; */ (void)0;
                }
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a4e8;
            LAB_0800a23c:
                uVar9 = 0xea;
                uVar10 = 0x53;
            LAB_0800a240:
                display_draw_text(uVar10, uVar9, puVar8, uVar11, uVar19, 0xc, 0);
            } else {
                if (cVar16 == '\b') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4ec;
                        /* goto LAB_0800a23c; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4ec;
                LAB_0800a22a:
                    uVar9 = 0xef;
                    uVar10 = 0x38;
                    /* goto LAB_0800a240; */ (void)0;
                }
                if (cVar16 == '\t') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4f0;
                        /* goto LAB_0800a23c; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4f0;
                    /* goto LAB_0800a22a; */ (void)0;
                }
            }
            cVar16 = *(char *)(iVar2 + 0x29);
            if (cVar16 == '\a') {
                if (*(char *)(iVar4 + 2) != '\0') {
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4e8;
                    /* goto LAB_0800a2a6; */ (void)0;
                }
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a4e8;
            LAB_0800a2b8:
                uVar9 = 0xea;
                uVar10 = 0xca;
            LAB_0800a2bc:
                display_draw_text(uVar10, uVar9, puVar8, uVar11, uVar19, 0xc, 0);
            } else {
                if (cVar16 == '\b') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4ec;
                        /* goto LAB_0800a2b8; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4ec;
                LAB_0800a2a6:
                    uVar9 = 0xef;
                    uVar10 = 0x85;
                    /* goto LAB_0800a2bc; */ (void)0;
                }
                if (cVar16 == '\t') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4f0;
                        /* goto LAB_0800a2b8; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4f0;
                    /* goto LAB_0800a2a6; */ (void)0;
                }
            }
            cVar16 = *(char *)(iVar2 + 0x28);
            if (cVar16 == '\n') {
                if (*(char *)(iVar4 + 2) != '\0') {
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4f4;
                    /* goto LAB_0800a322; */ (void)0;
                }
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a4f4;
            LAB_0800a334:
                uVar9 = 0xea;
                uVar10 = 0x53;
            LAB_0800a338:
                display_draw_text(uVar10, uVar9, puVar8, uVar11, uVar19, 0xc, 0);
            } else {
                if (cVar16 == '\v') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4f8;
                        /* goto LAB_0800a334; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4f8;
                LAB_0800a322:
                    uVar9 = 0xef;
                    uVar10 = 0x38;
                    /* goto LAB_0800a338; */ (void)0;
                }
                if (cVar16 == '\f') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4fc;
                        /* goto LAB_0800a334; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4fc;
                    /* goto LAB_0800a322; */ (void)0;
                }
            }
            cVar16 = *(char *)(iVar2 + 0x29);
            if (cVar16 == '\n') {
                if (*(char *)(iVar4 + 2) != '\0') {
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4f4;
                    /* goto LAB_0800a3a0; */ (void)0;
                }
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a4f4;
            LAB_0800a3b2:
                uVar9 = 0xea;
                uVar10 = 0xca;
            LAB_0800a3b6:
                display_draw_text(uVar10, uVar9, puVar8, uVar11, uVar19, 0xc, 0);
            } else {
                if (cVar16 == '\v') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4f8;
                        /* goto LAB_0800a3b2; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4f8;
                LAB_0800a3a0:
                    uVar9 = 0xef;
                    uVar10 = 0x85;
                    /* goto LAB_0800a3b6; */ (void)0;
                }
                if (cVar16 == '\f') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a4fc;
                        /* goto LAB_0800a3b2; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a4fc;
                    /* goto LAB_0800a3a0; */ (void)0;
                }
            }
            cVar16 = *(char *)(iVar2 + 0x28);
            if (cVar16 == '\r') {
                if (*(char *)(iVar4 + 2) != '\0') {
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a500;
                    /* goto LAB_0800a41c; */ (void)0;
                }
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a500;
            LAB_0800a42e:
                uVar9 = 0xea;
                uVar10 = 0x53;
            LAB_0800a432:
                display_draw_text(uVar10, uVar9, puVar8, uVar11, uVar19, 0xc, 0);
            } else {
                if (cVar16 == '\x0e') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a504;
                        /* goto LAB_0800a42e; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a504;
                LAB_0800a41c:
                    uVar9 = 0xef;
                    uVar10 = 0x38;
                    /* goto LAB_0800a432; */ (void)0;
                }
                if (cVar16 == '\x0f') {
                    if (*(char *)(iVar4 + 2) == '\0') {
                        uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                        uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                        puVar8 = &DAT_0800a508;
                        /* goto LAB_0800a42e; */ (void)0;
                    }
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = &DAT_0800a508;
                    /* goto LAB_0800a41c; */ (void)0;
                }
            }
            cVar16 = *(char *)(iVar2 + 0x29);
            if (cVar16 == '\r') {
                if (*(char *)(iVar4 + 2) != '\0') {
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = (uint8_t *)0x800a50c;
                    /* goto LAB_0800a59e; */ (void)0;
                }
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = (uint8_t *)0x800a50c;
                break;
            }
            if (cVar16 == '\x0e') {
                if (*(char *)(iVar4 + 2) != '\0') {
                    uVar19 = *(uint16_t *)(iVar3 + 0x1a);
                    uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                    puVar8 = (uint8_t *)0x800a510;
                    /* goto LAB_0800a59e; */ (void)0;
                }
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = (uint8_t *)0x800a510;
                break;
            }
            if (cVar16 != '\x0f') {
                return;
            }
            if (*(char *)(iVar4 + 2) == '\0') {
                uVar19 = *(uint16_t *)(iVar3 + 0x1e);
                uVar11 = *(uint16_t *)(iVar3 + 0x1c);
                puVar8 = &DAT_0800a508;
                break;
            }
            uVar19 = *(uint16_t *)(iVar3 + 0x1a);
            uVar11 = *(uint16_t *)(iVar3 + 0x1c);
            puVar8 = &DAT_0800a508;
            /* goto LAB_0800a59e; */ (void)0;
        case 7:
            cVar16 = '\0';
            /* goto LAB_0800a4ca; */ (void)0;
        default:
            goto switchD_0800a000_caseD_8;
        }
    LAB_0800a5da:
        uVar9 = 0xea;
        uVar10 = 0xca;
    }
    display_draw_text(uVar10, uVar9, puVar8, uVar11, uVar19, 0xc, 0);
switchD_0800a000_caseD_8:
    return;
}

/* ================================================================
 * FUN_0800a618  @  0x0800A618
 */

void FUN_0800a618() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    uint8_t *puVar2;
    uint8_t auStack_1c[8];

    iVar1 = DAT_0800a694;
    switch (param_1) {
    case 3:
        puVar2 = &DAT_0800a698;
        break;
    default:
        goto switchD_0800a62a_caseD_4;
    case 6:
        puVar2 = &DAT_0800a69c;
        break;
    case 7:
        puVar2 = &DAT_0800a6a8;
        break;
    case 8:
        puVar2 = &DAT_0800a6a4;
        break;
    case 9:
        puVar2 = &DAT_0800a6a0;
        break;
    case 10:
        puVar2 = &DAT_0800a6b0;
        break;
    case 0xb:
        puVar2 = &DAT_0800a6ac;
        break;
    case 0xc:
        puVar2 = &DAT_0800a6b4;
        break;
    case 0xd:
        puVar2 = &DAT_0800a6c0;
        break;
    case 0xe:
        puVar2 = &DAT_0800a6bc;
        break;
    case 0xf:
        puVar2 = &DAT_0800a6b8;
        break;
    case 0x10:
        if (*(char *)(DAT_0800a694 + 0x21) == '\0') {
            puVar2 = &DAT_0800a6c8;
        } else {
            puVar2 = &DAT_0800a6c4;
        }
    }
    sys_sprintf(auStack_1c, puVar2);
switchD_0800a62a_caseD_4:
    display_draw_text(param_3, param_4, auStack_1c, param_2, *(uint16_t *)(iVar1 + 0x1a), 0xc, 0);
    return;
}

/* ================================================================
 * FUN_0800a6cc  @  0x0800A6CC
 */

uint32_t FUN_0800a6cc() {
    int param_1 = 0;
    uint32_t *param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    byte bVar1;
    short *psVar2;
    uint16_t uVar3;
    short sVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    char *pcVar10;
    char cVar11;
    uint32_t uVar12;
    int iVar13;
    int local_28;
    uint32_t *puStack_24;
    uint32_t uStack_20;
    uint32_t uStack_1c;

    *param_2 = 0;
    local_28 = param_1;
    puStack_24 = param_2;
    uStack_20 = param_3;
    uStack_1c = param_4;
    iVar5 = FUN_08008c58();
    if (iVar5 < 0) {
        return 0xb;
    }
    pcVar10 = *(char **)(DAT_0800a908 + iVar5 * 4);
    if (pcVar10 == (char *)0x0) {
        return 0xc;
    }
    *param_2 = pcVar10;
    if ((*pcVar10 == '\0') || (uVar6 = fs_fat32_is_writable(pcVar10[1]), (uVar6 & 1) != 0)) {
        *pcVar10 = '\0';
        pcVar10[1] = (char)iVar5;
        uVar6 = fs_fat32_check_media_attr();
        if ((uVar6 & 1) != 0) {
            return 3;
        }
        if (((param_3 & 0xfe) != 0) && ((int)(uVar6 << 0x1d) < 0)) {
            return 10;
        }
        uVar6 = fs_fat32_validate_bpb(pcVar10, 0);
        if (uVar6 == 2) {
            uVar6 = 0;
            do {
                iVar5 = FUN_080095ee(pcVar10 + uVar6 * 0x10 + 0x1f6);
                (&local_28)[uVar6] = iVar5;
                uVar6 = uVar6 + 1;
            } while (uVar6 < 4);
            uVar12 = 0;
            do {
                if ((&local_28)[uVar12] == 0) {
                    uVar6 = 3;
                } else {
                    uVar6 = fs_fat32_validate_bpb(pcVar10);
                    if (uVar6 < 2)
                        break;
                }
                uVar12 = uVar12 + 1;
            } while (uVar12 < 4);
        }
        if (uVar6 == 4) {
            return 1;
        }
        if (uVar6 < 2) {
            iVar13 = *(int *)(pcVar10 + 0x2c);
            iVar5 = FUN_08009604(pcVar10 + 0x3b);
            if (iVar5 == 0x1000) {
                iVar5 = FUN_08009604(pcVar10 + 0x46);
                if (iVar5 == 0) {
                    iVar5 = FUN_080095ee(pcVar10 + 0x54);
                }
                *(int *)(pcVar10 + 0x18) = iVar5;
                uVar6 = (uint32_t)(byte)pcVar10[0x40];
                pcVar10[2] = pcVar10[0x40];
                if ((uVar6 == 1) || (uVar6 == 2)) {
                    bVar1 = pcVar10[0x3d];
                    *(uint16_t *)(pcVar10 + 10) = (uint16_t)bVar1;
                    if ((bVar1 != 0) && ((bVar1 & bVar1 - 1) == 0)) {
                        uVar3 = FUN_08009604(pcVar10 + 0x41);
                        *(uint16_t *)(pcVar10 + 8) = uVar3;
                        if ((uVar3 & 0x7f) == 0) {
                            uVar12 = FUN_08009604(pcVar10 + 0x43);
                            if (uVar12 == 0) {
                                uVar12 = FUN_080095ee(pcVar10 + 0x50);
                            }
                            iVar7 = FUN_08009604(pcVar10 + 0x3e);
                            if (iVar7 != 0) {
                                uVar9 = iVar7 + iVar5 * uVar6 +
                                        (uint32_t)(*(uint16_t *)(pcVar10 + 8) >> 7);
                                if ((uVar9 <= uVar12) &&
                                    (uVar12 =
                                         (uVar12 - uVar9) / (uint32_t)*(uint16_t *)(pcVar10 + 10),
                                     uVar12 != 0)) {
                                    cVar11 = '\0';
                                    if (uVar12 <= DAT_0800a90c) {
                                        cVar11 = '\x03';
                                    }
                                    if (uVar12 < 0xfff6) {
                                        cVar11 = '\x02';
                                    }
                                    if (uVar12 < 0xff6) {
                                        cVar11 = '\x01';
                                    } else if (cVar11 == '\0')
                                        /* goto LAB_0800a864; */ (void)0;
                                    uVar12 = uVar12 + 2;
                                    *(uint32_t *)(pcVar10 + 0x28) = uVar9 + iVar13;
                                    *(uint32_t *)(pcVar10 + 0x14) = uVar12;
                                    *(int *)(pcVar10 + 0x1c) = iVar13;
                                    *(int *)(pcVar10 + 0x20) = iVar7 + iVar13;
                                    if (cVar11 == '\x03') {
                                        iVar5 = FUN_08009604(pcVar10 + 0x5a);
                                        if ((iVar5 == 0) && (*(short *)(pcVar10 + 8) == 0)) {
                                            uVar8 = FUN_080095ee(pcVar10 + 0x5c);
                                            *(uint32_t *)(pcVar10 + 0x24) = uVar8;
                                            iVar5 = *(int *)(pcVar10 + 0x14) << 2;
                                            /* goto LAB_0800a858; */ (void)0;
                                        }
                                    } else if (*(uint16_t *)(pcVar10 + 8) != 0) {
                                        *(uint32_t *)(pcVar10 + 0x24) =
                                            iVar7 + iVar13 + iVar5 * uVar6;
                                        if (cVar11 == '\x02') {
                                            iVar5 = uVar12 * 2;
                                        } else {
                                            iVar5 = (uVar12 & 1) + (uVar12 * 3 >> 1);
                                        }
                                    LAB_0800a858:
                                        if (iVar5 + 0xfffU >> 0xc <=
                                            *(uint32_t *)(pcVar10 + 0x18)) {
                                            pcVar10[0x10] = -1;
                                            pcVar10[0x11] = -1;
                                            pcVar10[0x12] = -1;
                                            pcVar10[0x13] = -1;
                                            pcVar10[0xc] = -1;
                                            pcVar10[0xd] = -1;
                                            pcVar10[0xe] = -1;
                                            pcVar10[0xf] = -1;
                                            pcVar10[4] = -0x80;
                                            if (((cVar11 == '\x03') &&
                                                 (iVar5 = FUN_08009604(pcVar10 + 0x60),
                                                  iVar5 == 1)) &&
                                                (iVar5 = FUN_0800a91c(pcVar10, iVar13 + 1),
                                                 iVar5 == 0)) {
                                                pcVar10[4] = '\0';
                                                iVar5 = FUN_08009604(pcVar10 + 0x22e);
                                                if (((iVar5 == 0xaa55) &&
                                                     (iVar5 = FUN_080095ee(pcVar10 + 0x30),
                                                      iVar5 == DAT_0800a910)) &&
                                                    (iVar5 = FUN_080095ee(pcVar10 + 0x214),
                                                     iVar5 == DAT_0800a914)) {
                                                    uVar8 = FUN_080095ee(pcVar10 + 0x218);
                                                    *(uint32_t *)(pcVar10 + 0x10) = uVar8;
                                                    uVar8 = FUN_080095ee(pcVar10 + 0x21c);
                                                    *(uint32_t *)(pcVar10 + 0xc) = uVar8;
                                                }
                                            }
                                            psVar2 = DAT_0800a918;
                                            *pcVar10 = cVar11;
                                            sVar4 = *psVar2 + 1;
                                            *psVar2 = sVar4;
                                            *(short *)(pcVar10 + 6) = sVar4;
                                            /* goto LAB_0800a722; */ (void)0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    LAB_0800a864:
        uVar8 = 0xd;
    } else {
        if (((param_3 & 0xfe) != 0) && ((int)(uVar6 << 0x1d) < 0)) {
            return 10;
        }
    LAB_0800a722:
        uVar8 = 0;
    }
    return uVar8;
}

/* ================================================================
 * FUN_0800a91c  @  0x0800A91C
 */

int FUN_0800a91c() {
    int param_1 = 0;
    int param_2 = 0;
    int iVar1;
    int iVar2;

    iVar2 = 0;
    if ((*(int *)(param_1 + 0x2c) != param_2) && (iVar2 = FUN_0800bda8(param_1), iVar2 == 0)) {
        iVar1 = fs_fat32_read_block(*(uint8_t *)(param_1 + 1), param_1 + 0x30, param_2, 1);
        if (iVar1 != 0) {
            param_2 = -1;
            iVar2 = 1;
        }
        *(int *)(param_1 + 0x2c) = param_2;
    }
    return iVar2;
}

/* ================================================================
 * FUN_0800a94e  @  0x0800A94E
 */

uint32_t FUN_0800a94e() {
    uint32_t param_1 = 0;
    param_1 = param_1 & 0xef;
    if (param_1 == 0xeb) {
        return 0x30;
    }
    if (param_1 == 10) {
        return 0x31;
    }
    if (param_1 == 0xad) {
        return 0x32;
    }
    if (param_1 == 0x8f) {
        return 0x33;
    }
    if (param_1 == 0x4e) {
        return 0x34;
    }
    if (param_1 == 199) {
        return 0x35;
    }
    if (param_1 == 0xe7) {
        return 0x36;
    }
    if (param_1 == 0x8a) {
        return 0x37;
    }
    if (param_1 == 0xef) {
        return 0x38;
    }
    if (param_1 == 0xcf) {
        return 0x39;
    }
    if (param_1 == 0xee) {
        return 0x41;
    }
    if (param_1 == 0x23) {
        return 0x55;
    }
    if (param_1 == 0x65) {
        return 0x54;
    }
    if (param_1 == 0x27) {
        return 0x4f;
    }
    if (param_1 == 0x61) {
        return 0x4c;
    }
    if (param_1 != 0xe5) {
        if (param_1 == 4) {
            return 0x2d;
        }
        if (param_1 == 0) {
            return 0x20;
        }
        if (param_1 == 0xe1) {
            return 0x43;
        }
        if (param_1 != 0xec) {
            if (param_1 != 0x24) {
                return 0xff;
            }
            return 0x52;
        }
        return 0x50;
    }
    return 0x45;
}

/* ================================================================
 * FUN_0800a9fc  @  0x0800A9FC
 */

void FUN_0800a9fc() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t uVar1;
    uint32_t uVar2;

    uVar1 = (*DAT_0800aa74 & 0x7ff) >> 8;
    uVar2 = 7 - uVar1;
    if (4 < uVar2) {
        uVar2 = 4;
    }
    if (uVar1 + 4 < 7) {
        uVar1 = 0;
    } else {
        uVar1 = uVar1 - 3;
    }
    uVar1 = ((1 << (uVar2 & 0xff)) - 1U & param_2) << (uVar1 & 0xff) |
            (1 << (uVar1 & 0xff)) - 1U & param_3;
    if ((int)param_1 < 0) {
        *(char *)((param_1 & 0xf) + 0xe000ed14) = (char)(uVar1 << 4);
    } else {
        *(char *)(param_1 + 0xe000e400) = (char)(uVar1 << 4);
        *(int *)((param_1 >> 5) * 4 + -0x1fff1f00) = 1 << (param_1 & 0x1f);
    }
    return;
}

/* ================================================================
 * FUN_0800aa78  @  0x0800AA78
 */

void FUN_0800aa78(uint32_t param_1)

{
    *DAT_0800aa94 = *DAT_0800aa94 & 0xf8ff | (param_1 & 7) << 8 | DAT_0800aa98;
    return;
}

/* ================================================================
 * ui_draw_main_menu  @  0x0800AAD4
 */

void ui_draw_main_menu() {
    int param_1 = 0;
    int param_2 = 0;
    int param_3 = 0;
    int param_4 = 0;
    int param_5 = 0;
    int iVar1;
    char *pcVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint16_t uVar6;
    uint32_t uVar7;

    iVar1 = DAT_0800ada4;
    uVar7 = 0;
    if (param_1 == 1) {
        do {
            display_draw_rounded_rect(uVar7 * 0x3d + 8, 8, uVar7 * 0x3d + 0x33, 0x33, 5,
                                      *(uint16_t *)(iVar1 + 0x1c));
            uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 4);
        display_draw_arc(DAT_0800ada8, 0xe, 0xe, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
        display_draw_arc(DAT_0800adac, 0x4a, 0xc, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
        display_draw_arc(DAT_0800adb0, 0x87, 0xd, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
        display_draw_arc(DAT_0800adb4, 0xc5, 0xe, *(uint16_t *)(iVar1 + 0x1c), 0xf79e, 0);
    }
    if (param_2 != 0) {
        if (*(char *)(iVar1 + 0x26) == '\0') {
            pcVar2 = s_2__UI_decorate_menu_jpg_0800add0;
        } else {
            pcVar2 = s_2__UI_decorat_menu_jpg_0800adb8;
        }
        ui_load_and_draw_jpeg(pcVar2, 5, 0x41);
        if (param_2 == 1) {
            display_draw_rounded_rect(8, 8, 0x33, 0x33, 5, 0xfc60);
            display_fill_rect(0xf, 0x68, 0xe6, 0x8c, *(uint16_t *)(iVar1 + 0x1a));
            if (*(char *)(iVar1 + 0x20) == '\0') {
                display_draw_text(0x12, 0x45, &DAT_0800ae0c, 0xf79e, 0xf79e, 0x18, 1);
                display_draw_text(0x30, 0x69, &DAT_0800ae18, *(uint16_t *)(iVar1 + 0x1c), 0xf79e,
                                  0x18, 1);
                uVar4 = 0x18;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                pcVar2 = &DAT_0800ae20;
                uVar3 = 0x8e;
            } else {
                display_draw_text(0xc, 0x48, s_History_record_0800ade8, *(uint16_t *)(iVar1 + 0x1c),
                                  0xf79e, 0x10, 1);
                display_draw_text(0x34, 0x69, &DAT_0800adf8, *(uint16_t *)(iVar1 + 0x1c), 0xf79e,
                                  0x10, 1);
                uVar4 = 0x10;
                uVar6 = *(uint16_t *)(iVar1 + 0x1c);
                pcVar2 = s_Measurement_0800ae00;
                uVar3 = 0x8c;
            }
            display_draw_text(uVar3, 0x69, pcVar2, uVar6, 0xf79e, uVar4, 1);
            FUN_080041d4(1);
        } else {
            if (param_2 == 2) {
                display_draw_rounded_rect(0x45, 8, 0x70, 0x33, 5, 0xfc60);
                if (*(char *)(iVar1 + 0x20) == '\0') {
                    pcVar2 = (char *)0x800ae38;
                LAB_0800ac76:
                    uVar5 = 0x18;
                    uVar4 = 0x45;
                    uVar3 = 0x12;
                } else {
                    uVar5 = 0x10;
                    uVar4 = 0x48;
                    pcVar2 = s_System_settings_0800ae28;
                    uVar3 = 10;
                }
            } else {
                if (param_2 == 3) {
                    display_draw_rounded_rect(0x82, 8, 0xad, 0x33, 5, 0xfc60);
                    if (*(char *)(iVar1 + 0x20) == '\0') {
                        pcVar2 = (char *)0x800ae4c;
                        /* goto LAB_0800ac76; */ (void)0;
                    }
                    pcVar2 = s_Reset_0800ae44;
                } else {
                    if (param_2 != 4)
                        /* goto LAB_0800acae; */ (void)0;
                    display_draw_rounded_rect(0xbf, 8, 0xea, 0x33, 5, 0xfc60);
                    if (*(char *)(iVar1 + 0x20) == '\0') {
                        pcVar2 = &DAT_0800ae60;
                        /* goto LAB_0800ac76; */ (void)0;
                    }
                    pcVar2 = s_About_0800ae58;
                }
                uVar5 = 0x18;
                uVar4 = 0x45;
                uVar3 = 0x2a;
            }
            display_draw_text(uVar3, uVar4, pcVar2, 0xf79e, 0xf79e, uVar5, 1);
        }
    }
LAB_0800acae:
    if (param_3 == 1) {
        uVar6 = *(uint16_t *)(iVar1 + 0x1c);
        uVar4 = 0x33;
        uVar3 = 8;
    LAB_0800ad04:
        display_draw_rounded_rect(uVar3, 8, uVar4, 0x33, 5, uVar6);
    } else {
        if (param_3 == 2) {
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar4 = 0x70;
            uVar3 = 0x45;
            /* goto LAB_0800ad04; */ (void)0;
        }
        if (param_3 == 3) {
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar4 = 0xad;
            uVar3 = 0x82;
            /* goto LAB_0800ad04; */ (void)0;
        }
        if (param_3 == 4) {
            uVar6 = *(uint16_t *)(iVar1 + 0x1c);
            uVar4 = 0xea;
            uVar3 = 0xbf;
            /* goto LAB_0800ad04; */ (void)0;
        }
    }
    if (param_4 == 1) {
        uVar5 = 0xe;
        uVar4 = 0xe;
        uVar3 = DAT_0800ada8;
    } else if (param_4 == 2) {
        uVar5 = 0xc;
        uVar4 = 0x4a;
        uVar3 = DAT_0800adac;
    } else if (param_4 == 3) {
        uVar5 = 0xd;
        uVar4 = 0x87;
        uVar3 = DAT_0800adb0;
    } else {
        if (param_4 != 4)
            /* goto LAB_0800ad4a; */ (void)0;
        uVar5 = 0xe;
        uVar4 = 0xc5;
        uVar3 = DAT_0800adb4;
    }
    display_draw_arc(uVar3, uVar4, uVar5, 0xfc60, 0xfc60, 0);
LAB_0800ad4a:
    if (param_5 == 1) {
        uVar5 = 0xe;
        uVar6 = *(uint16_t *)(iVar1 + 0x1c);
        uVar4 = 0xe;
        uVar3 = DAT_0800ada8;
    } else if (param_5 == 2) {
        uVar6 = *(uint16_t *)(iVar1 + 0x1c);
        uVar5 = 0xc;
        uVar4 = 0x4a;
        uVar3 = DAT_0800adac;
    } else if (param_5 == 3) {
        uVar5 = 0xd;
        uVar6 = *(uint16_t *)(iVar1 + 0x1c);
        uVar4 = 0x87;
        uVar3 = DAT_0800adb0;
    } else {
        if (param_5 != 4) {
            return;
        }
        uVar5 = 0xe;
        uVar6 = *(uint16_t *)(iVar1 + 0x1c);
        uVar4 = 0xc5;
        uVar3 = DAT_0800adb4;
    }
    display_draw_arc(uVar3, uVar4, uVar5, uVar6, 0xf79e, 0);
    return;
}

/* ================================================================
 * ui_draw_charging_level_bars  @  0x0800AF08
 */

void ui_draw_charging_level_bars(int param_1)

{
    uint32_t uVar1;
    uint16_t local_18[8];

    uVar1 = 0;
    if (param_1 == 5) {
        do {
            local_18[uVar1] = 0x400;
            uVar1 = uVar1 + 1 & 0xff;
        } while (uVar1 < 5);
    } else if (param_1 == 4) {
        do {
            local_18[uVar1] = 0x400;
            uVar1 = uVar1 + 1 & 0xff;
        } while (uVar1 < 4);
        local_18[4] = 0x3186;
    } else if (param_1 == 3) {
        do {
            local_18[uVar1] = 0x400;
            uVar1 = uVar1 + 1 & 0xff;
        } while (uVar1 < 3);
        local_18[4] = 0x3186;
        local_18[3] = 0x3186;
    } else {
        local_18[3] = 0x3186;
        local_18[4] = 0x3186;
        local_18[2] = 0x3186;
        if (param_1 == 2) {
            local_18[1] = 0x400;
        } else {
            local_18[1] = 0x3186;
        }
        local_18[0] = 0x400;
    }
    display_fill_rect(0x6d, 0x6a, 0x84, 0x6e, 0x3186);
    display_draw_rounded_filled_rect(0x5c, 0x71, 0x95, 0x83, 4, local_18[4]);
    display_fill_rect(0x5c, 0x7d, 0x95, 0x83, local_18[4]);
    display_fill_rect(0x5c, 0x85, 0x95, 0x96, local_18[3]);
    display_fill_rect(0x5c, 0x98, 0x95, 0xa9, local_18[2]);
    display_fill_rect(0x5c, 0xab, 0x95, 0xbc, local_18[1]);
    display_draw_rounded_filled_rect(0x5c, 0xbe, 0x95, 0xd2, 4, local_18[0]);
    display_fill_rect(0x5c, 0xbe, 0x95, 0xcb, local_18[0]);
    return;
}

/* ================================================================
 * FUN_0800b078  @  0x0800B078
 */

int FUN_0800b078(char *param_1, uint32_t param_2, uint32_t param_3)

{
    char cVar1;
    int iVar2;
    uint32_t uVar3;
    byte bVar4;

    if (param_2 < 2) {
        return 2;
    }
    if (*(uint32_t *)(param_1 + 0x14) <= param_2) {
        return 2;
    }
    cVar1 = *param_1;
    if (cVar1 == '\x01') {
        uVar3 = param_2 + (param_2 >> 1);
        iVar2 = FUN_0800a91c(param_1, *(int *)(param_1 + 0x20) + (uVar3 >> 0xc));
        if (iVar2 != 0) {
            return iVar2;
        }
        if ((param_2 & 1) == 0) {
            bVar4 = (byte)param_3;
        } else {
            bVar4 = param_1[(uVar3 & 0xfff) + 0x30] & 0xfU | (byte)((param_3 & 0xff) << 4);
        }
        param_1[(uVar3 & 0xfff) + 0x30] = bVar4;
        param_1[3] = '\x01';
        iVar2 = FUN_0800a91c(param_1, *(int *)(param_1 + 0x20) + (uVar3 + 1 >> 0xc));
        if (iVar2 != 0) {
            return iVar2;
        }
        if ((param_2 & 1) == 0) {
            bVar4 = param_1[(uVar3 + 1 & 0xfff) + 0x30] & 0xf0U | (byte)((param_3 << 0x14) >> 0x1c);
        } else {
            bVar4 = (byte)((param_3 << 0x14) >> 0x18);
        }
        param_1[(uVar3 + 1 & 0xfff) + 0x30] = bVar4;
    } else if (cVar1 == '\x02') {
        iVar2 = FUN_0800a91c(param_1, *(int *)(param_1 + 0x20) + (param_2 >> 0xb));
        if (iVar2 != 0) {
            return iVar2;
        }
        FUN_0800bc68(param_1 + (param_2 & 0x7ff) * 2 + 0x30, param_3 & 0xffff);
    } else {
        if (cVar1 != '\x03') {
            return 2;
        }
        iVar2 = FUN_0800a91c(param_1, *(int *)(param_1 + 0x20) + (param_2 >> 10));
        if (iVar2 != 0) {
            return iVar2;
        }
        uVar3 = FUN_080095ee();
        FUN_0800bc58(param_1 + (param_2 & 0x3ff) * 4 + 0x30,
                     uVar3 & 0xf0000000 | param_3 & 0xfffffff);
    }
    param_1[3] = '\x01';
    return 0;
}

/* ================================================================
 * sys_usb_detect_init  @  0x0800B164
 * nearby string: " Do not use while charging"
 */

void sys_usb_detect_init(void)

{
    FUN_080082fc(DAT_0800b174, DAT_0800b170, 0x46);
    return;
}

/* ================================================================
 * sys_is_usb_charging  @  0x0800B178
 * nearby string: " Do not use while charging"
 */

uint32_t sys_is_usb_charging(void)

{
    uint32_t uVar1;
    int iVar2;

    uVar1 = DAT_0800b1b4;
    iVar2 = FUN_08008d5e(DAT_0800b1b4, 1);
    if ((iVar2 == 0) || (iVar2 = FUN_08008d5e(uVar1, 2), iVar2 == 0)) {
        sys_delay_ms(10);
        iVar2 = FUN_08008d5e(uVar1, 1);
        if ((iVar2 == 0) || (iVar2 = FUN_08008d5e(uVar1, 2), iVar2 == 0)) {
            return 1;
        }
    }
    return 0;
}

/* ================================================================
 * ui_show_charging_screen  @  0x0800B1B8
 * nearby string: " Do not use while charging"
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint64_t ui_show_charging_screen(uint32_t param_1, uint32_t param_2, uint32_t param_3)

{
    uint16_t uVar1;
    uint16_t uVar2;
    short sVar3;
    bool bVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    char *pcVar9;
    byte bVar10;

    bVar4 = false;
    bVar10 = 0;
    sVar3 = 0;
    iVar7 = sys_is_usb_charging();
    iVar5 = _DAT_0800b28c;
    if (iVar7 == 1) {
        display_fill_rect(0, 0, 0xf0, 0x140, *(uint16_t *)(_DAT_0800b28c + 0x1a), param_2, param_3);
        if (*(char *)(iVar5 + 0x20) == '\0') {
            uVar1 = *(uint16_t *)(iVar5 + 0x1a);
            param_2 = 0x18;
            uVar2 = *(uint16_t *)(iVar5 + 0x1c);
            pcVar9 = &DAT_0800b2b4;
            uVar8 = 0x1e;
        } else {
            uVar1 = *(uint16_t *)(iVar5 + 0x1a);
            param_2 = 0x10;
            uVar2 = *(uint16_t *)(iVar5 + 0x1c);
            pcVar9 = s_Do_not_use_while_charging_0800b28f + 1;
            uVar8 = 0x14;
        }
        param_1 = (uint32_t)uVar1;
        display_draw_text(uVar8, 0xfa, pcVar9, uVar2, param_1, param_2, 0);
        uVar6 = DAT_0800b2b0;
        uVar8 = DAT_0800b2ac;
        while (true) {
            iVar7 = FUN_08008d5e(uVar8, 2);
            if (iVar7 == 0) {
                if (!bVar4) {
                    ui_draw_charging_level_bars(5);
                    bVar4 = true;
                }
            } else {
                if (sVar3 == 0) {
                    if (bVar10 < 5) {
                        bVar10 = bVar10 + 1;
                    } else {
                        bVar10 = 1;
                    }
                    ui_draw_charging_level_bars(bVar10);
                    sVar3 = 0x4f;
                }
                sVar3 = sVar3 + -1;
                bVar4 = false;
            }
            iVar7 = sys_is_usb_charging();
            if (iVar7 == 0)
                break;
            iVar7 = FUN_08008d5e(uVar6, 0x80);
            if (iVar7 == 0) {
                sys_delay_ms(10);
                iVar7 = FUN_08008d5e(uVar6, 0x80);
                if (iVar7 == 0) {
                    sys_power_off();
                }
            }
        }
        *(uint8_t *)(iVar5 + 5) = 1;
    }
    return CONCAT44(param_2, param_1);
}

/* ================================================================
 * FUN_0800b2c4  @  0x0800B2C4
 */

int FUN_0800b2c4(int *param_1, uint32_t param_2, int param_3)

{
    int iVar1;
    uint32_t uVar2;
    int iVar3;

    iVar3 = *param_1;
    if ((param_2 < 2) || (*(uint32_t *)(iVar3 + 0x14) <= param_2)) {
    LAB_0800b330:
        iVar1 = 2;
    } else if ((param_3 == 0) || (iVar1 = FUN_0800b078(iVar3, param_3, 0xffffffff), iVar1 == 0)) {
        do {
            uVar2 = FUN_08008ae4(param_1, param_2);
            if (uVar2 == 0)
                break;
            if (uVar2 == 1)
                /* goto LAB_0800b330; */ (void)0;
            if (uVar2 == 0xffffffff) {
                return 1;
            }
            iVar1 = FUN_0800b078(iVar3, param_2, 0);
            if (iVar1 != 0) {
                return iVar1;
            }
            if (*(uint32_t *)(iVar3 + 0x10) < *(uint32_t *)(iVar3 + 0x14) - 2) {
                *(uint32_t *)(iVar3 + 0x10) = *(uint32_t *)(iVar3 + 0x10) + 1;
                *(byte *)(iVar3 + 4) = *(byte *)(iVar3 + 4) | 1;
            }
            param_2 = uVar2;
        } while (uVar2 < *(uint32_t *)(iVar3 + 0x14));
        iVar1 = 0;
    }
    return iVar1;
}

/* ================================================================
 * FUN_0800b338  @  0x0800B338
 */

void FUN_0800b338(void)

{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    uint16_t uVar6;
    short sVar7;
    int iVar8;
    int iVar9;
    uint32_t uVar10;
    uint16_t uVar11;
    uint32_t uVar12;

    iVar3 = DAT_0800b420;
    iVar2 = DAT_0800b41c;
    iVar1 = DAT_0800b418;
    uVar12 = (uint32_t)(byte)(*(char *)(DAT_0800b418 + 0x12) * '\x02' + 10);
    *(uint16_t *)(DAT_0800b418 + uVar12 * 2) =
        (uint16_t)*(byte *)(DAT_0800b41c + 3) | (uint16_t)*(byte *)(DAT_0800b420 + 0xd) << 6;
    iVar8 = FUN_0800ba2c();
    iVar4 = DAT_0800b424;
    uVar10 = DAT_0800b430;
    if (((iVar8 != 1) && (iVar8 = FUN_0800ba2c(), uVar10 = DAT_0800b434, iVar8 != 2)) &&
        (iVar9 = FUN_0800ba2c(), iVar5 = DAT_0800b42c, iVar8 = DAT_0800b428, uVar10 = DAT_0800b438,
         iVar9 != 3)) {
        if (*(char *)(iVar2 + 3) == '\n') {
            uVar10 = FUN_0800e5a0(*(uint32_t *)(iVar3 + 8), *(uint32_t *)(DAT_0800b43c + 0x14));
        } else {
            uVar10 = *(uint32_t *)(iVar3 + 8);
        }
        if (0x807fffff < uVar10) {
            uVar10 = uVar10 ^ 0x80000000;
            *(uint16_t *)(iVar1 + uVar12 * 2) = *(uint16_t *)(iVar1 + uVar12 * 2) | 0x1000;
        }
        if ((int)uVar10 < iVar4) {
            uVar10 = FUN_0800e8c4(uVar10, iVar8);
            uVar11 = *(uint16_t *)(iVar1 + uVar12 * 2) | 0x6000;
        } else if ((int)uVar10 < iVar5) {
            uVar10 = FUN_0800e8c4(uVar10, iVar5);
            uVar11 = *(uint16_t *)(iVar1 + uVar12 * 2) | 0x4000;
        } else {
            if (iVar8 <= (int)uVar10)
                /* goto LAB_0800b3f0; */ (void)0;
            uVar10 = FUN_0800e8c4();
            uVar11 = *(uint16_t *)(iVar1 + uVar12 * 2) | 0x2000;
        }
        *(uint16_t *)(iVar1 + uVar12 * 2) = uVar11;
    }
LAB_0800b3f0:
    uVar6 = FUN_0800e82c(uVar10);
    *(uint16_t *)(iVar1 + uVar12 * 2 + 2) = uVar6;
    if (*(uint16_t *)(iVar1 + 0x10) < 0x1e) {
        *(uint16_t *)(iVar1 + 0x10) = *(uint16_t *)(iVar1 + 0x10) + 1;
    }
    if (*(uint16_t *)(iVar1 + 0x12) < 0x1e) {
        sVar7 = *(uint16_t *)(iVar1 + 0x12) + 1;
    } else {
        sVar7 = 1;
    }
    *(short *)(iVar1 + 0x12) = sVar7;
    return;
}

/* ================================================================
 * sys_auto_shutdown_tick  @  0x0800B440
 */

void sys_auto_shutdown_tick(void)

{
    char cVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;

    iVar3 = DAT_0800b4b8;
    cVar1 = *(char *)(DAT_0800b4b8 + 3);
    cVar2 = *(char *)(DAT_0800b4b8 + 2);
    if ((cVar1 == '\0') || (cVar1 == '\x01')) {
        if (cVar2 == '\x02')
            /* goto LAB_0800b46a; */ (void)0;
        uVar5 = 8000;
    } else {
        if (cVar2 != '\x02')
            /* goto LAB_0800b4b4; */ (void)0;
    LAB_0800b46a:
        uVar5 = 60000;
    }
    if (*(char *)(DAT_0800b4bc + 0xd) == '\x06') {
        *(int *)(DAT_0800b4b8 + 0x10) = *(int *)(DAT_0800b4b8 + 0x10) + 1;
        if (*(uint32_t *)(iVar3 + 0x10) <= uVar5) {
            return;
        }
        if (cVar2 == '\x02') {
            iVar4 = sensor_touch_query(0x15);
            if (iVar4 == 1) {
                *(uint8_t *)(iVar3 + 2) = 2;
            }
        } else if (cVar1 == '\x01') {
            iVar4 = sensor_touch_query(0xd);
            if (iVar4 == 1) {
                **(uint8_t **)(iVar3 + 0x14) = 1;
            }
        } else {
            iVar4 = sensor_touch_query(0xc);
            if (iVar4 == 1) {
                **(uint8_t **)(iVar3 + 0x14) = 0;
            }
        }
    }
LAB_0800b4b4:
    *(uint32_t *)(iVar3 + 0x10) = 0;
    return;
}

/* ================================================================
 * sensor_touch_poll_init  @  0x0800B4C0
 */

void sensor_touch_poll_init(void)

{
    sensor_touch_query(0xb);
    sensor_touch_query(0xa0);
    return;
}

/* ================================================================
 * sensor_touch_query  @  0x0800B868
 * nearby string: "     "
 */

uint32_t sensor_touch_query(int param_1)

{
    uint16_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t local_24;
    uint32_t uStack_20;
    uint8_t uStack_1c;
    char local_1b;
    uint16_t uStack_1a;

    local_24 = DAT_0800b998;
    uStack_20 = DAT_0800b99c;
    uVar9 = 0;
    if (param_1 == 0xa0) {
        ((uint8_t *)&local_24)[3] = CONCAT12(2, (short)DAT_0800b998);
        local_24 = (uint32_t)(uint3)local_24;
    }
    uVar4 = local_24;
    local_24 = CONCAT13((char)param_1, (uint3)local_24);
    uVar5 = local_24;
    ((uint8_t *)&local_24)[2] = SUB41(uVar4, 2);
    uStack_1a = (uint16_t)((uint32_t)DAT_0800b9a0 >> 0x10);
    _uStack_1c = CONCAT11(((uint8_t *)&local_24)[2] + (char)param_1, (char)DAT_0800b9a0);
    local_24 = uVar5;
    sensor_touch_send_cmd(&local_24);
    iVar2 = DAT_0800b9a4;
    while (*(char *)(iVar2 + 8) != '\x01') {
        sys_delay_ms(1);
        uVar9 = uVar9 + 1 & 0xffff;
        if (999 < uVar9) {
            return 0;
        }
        if (uVar9 % 200 == 0) {
            sensor_touch_send_cmd(&local_24);
        }
    }
    if (*DAT_0800b9a8 == '\0') {
        if (((param_1 == 0x10) || (param_1 == 0x11)) || (param_1 == 0x15)) {
            FUN_08008c94(DAT_0800b9ac, 4);
        } else {
            FUN_08008c90(DAT_0800b9ac, 4);
        }
    }
    iVar3 = DAT_0800b9b8;
    uVar5 = DAT_0800b9b4;
    if (*DAT_0800b9b0 != '\0') {
        return 1;
    }
    *(uint32_t *)(DAT_0800b9b8 + 0x18) = 0;
    *(uint32_t *)(iVar3 + 0x1c) = uVar5;
    uVar5 = DAT_0800b9bc;
    *(uint32_t *)(iVar3 + 8) = 0;
    *(uint32_t *)(iVar3 + 0x20) = 0;
    *(uint32_t *)(iVar3 + 0x24) = uVar5;
    *(uint8_t *)(iVar3 + 0x28) = 0x10;
    *(uint8_t *)(iVar3 + 0x29) = 1;
    if ((*(char *)*DAT_0800b9c0 != '\t') && (*(char *)*DAT_0800b9c0 != '\b')) {
        if (*DAT_0800b9c4 == '\0') {
            display_fill_rect(0x14, 0xdf, 0x66, 0xf7, *(uint16_t *)(iVar2 + 0x1e));
            uVar1 = *(uint16_t *)(iVar2 + 0x1e);
            uVar8 = 0xf7;
            uVar7 = 0xdb;
            uVar6 = 0xdf;
            uVar5 = 0x88;
        } else {
            if (*DAT_0800b9c4 != '\x01')
                /* goto LAB_0800b962; */ (void)0;
            display_fill_rect(7, 0xec, 0x4a, 0xfa, *(uint16_t *)(iVar2 + 0x1a));
            uVar1 = *(uint16_t *)(iVar2 + 0x1a);
            uVar8 = 0xf9;
            uVar7 = 0x96;
            uVar6 = 0xec;
            uVar5 = 0x51;
        }
        display_fill_rect(uVar5, uVar6, uVar7, uVar8, uVar1);
    }
LAB_0800b962:
    *(uint8_t *)(iVar3 + 0x2a) = 0;
    fs_fat32_reset_dir_state();
    if (*(char *)(iVar3 + 0xe) == '\x01') {
        *(uint8_t *)(iVar3 + 0xe) = 0;
        ui_draw_hold_icon(0);
    }
    sys_sprintf(*(uint32_t *)(iVar3 + 4), s__0800b9c8);
    return 1;
}

/* ================================================================
 * FUN_0800b9d2  @  0x0800B9D2
 */

void FUN_0800b9d2(uint32_t param_1, int param_2)

{
    uint8_t uVar1;
    int extraout_r1;
    int extraout_r1_00;
    int extraout_r1_01;
    uint8_t *extraout_r2;
    int extraout_r2_00;
    int extraout_r2_01;
    int extraout_r2_02;

    uVar1 = FUN_0800a94e(*(byte *)(param_2 + 2) & 0xf0 | *(byte *)(param_2 + 3) & 0xf, param_2,
                         param_1);
    *extraout_r2 = uVar1;
    uVar1 = FUN_0800a94e(*(byte *)(extraout_r1 + 3) & 0xf0 | *(byte *)(extraout_r1 + 4) & 0xf);
    *(uint8_t *)(extraout_r2_00 + 1) = uVar1;
    uVar1 =
        FUN_0800a94e(*(byte *)(extraout_r1_00 + 4) & 0xf0 | *(byte *)(extraout_r1_00 + 5) & 0xf);
    *(uint8_t *)(extraout_r2_01 + 2) = uVar1;
    uVar1 =
        FUN_0800a94e(*(byte *)(extraout_r1_01 + 5) & 0xf0 | *(byte *)(extraout_r1_01 + 6) & 0xf);
    *(uint8_t *)(extraout_r2_02 + 3) = uVar1;
    return;
}

/* ================================================================
 * FUN_0800ba2c  @  0x0800BA2C
 */

uint32_t FUN_0800ba2c(void)

{
    int iVar1;

    iVar1 = *(int *)(DAT_0800ba70 + 4);
    if (*(char *)(iVar1 + 2) == '.') {
        if ((*(char *)(iVar1 + 3) == '0') && (*(char *)(iVar1 + 4) == 'L')) {
            return 1;
        }
    } else if (*(char *)(iVar1 + 2) == '0') {
        if (*(char *)(iVar1 + 3) == '.') {
            if (*(char *)(iVar1 + 4) == 'L') {
                return 2;
            }
        } else if ((*(char *)(iVar1 + 3) == 'L') && (*(char *)(iVar1 + 4) == '.')) {
            return 3;
        }
    }
    return 0;
}

/* ================================================================
 * sensor_touch_send_cmd  @  0x0800BA74
 */

void sensor_touch_send_cmd(int param_1)

{
    uint32_t uVar1;
    int iVar2;
    uint32_t uVar3;

    uVar1 = DAT_0800ba9c;
    uVar3 = 0;
    do {
        do {
            iVar2 = FUN_0800c4c4(uVar1, 0x80);
        } while (iVar2 == 0);
        FUN_0800c498(uVar1, *(uint8_t *)(param_1 + uVar3));
        uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 10);
    return;
}

/* ================================================================
 * sys_power_off  @  0x0800BAA0
 */

void sys_power_off(void)

{
    int iVar1;
    int iVar2;

    FUN_080094f4(9999, 0x8f, 0);
    iVar2 = DAT_0800baf8;
    iVar1 = DAT_0800baf4;
    *(uint16_t *)(DAT_0800baf8 + 2) = (uint16_t)*(byte *)(DAT_0800baf4 + 0x20);
    *(uint16_t *)(iVar2 + 8) = (uint16_t)*(byte *)(iVar1 + 0x21);
    *(uint16_t *)(iVar2 + 4) = (uint16_t)*(byte *)(iVar1 + 0x22);
    *(uint16_t *)(iVar2 + 6) = (uint16_t)*(byte *)(iVar1 + 0x23);
    *(uint16_t *)(iVar2 + 10) = (uint16_t)*DAT_0800bafc;
    *(uint16_t *)(iVar2 + 0xc) = (uint16_t)*DAT_0800bb00;
    *(uint16_t *)(iVar2 + 0xe) = (uint16_t)*(byte *)(iVar1 + 0x26);
    sys_write_settings_to_flash();
    fs_fat32_mount_notify();
    sys_delay_ms(0xfa);
    FUN_08008c90(DAT_0800bb04, 0x40);
    DataSynchronizationBarrier(0xf);
    *DAT_0800aab8 = *DAT_0800aab8 & 0x700 | DAT_0800aabc;
    DataSynchronizationBarrier(0xf);
    do {
        /* WARNING: Do nothing block with infinite loop */
    } while (true);
}

/* ================================================================
 * FUN_0800bb08  @  0x0800BB08
 */

void FUN_0800bb08(uint8_t *param_1)

{
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 1;
    return;
}

/* ================================================================
 * FUN_0800bb1e  @  0x0800BB1E
 */

void FUN_0800bb1e(uint32_t *param_1, uint32_t param_2)

{
    *param_1 = *param_1 & 0xffffffbf | (param_2 & 1) << 6;
    return;
}

/* ================================================================
 * FUN_0800bb28  @  0x0800BB28
 */

void FUN_0800bb28(uint32_t *param_1, uint32_t param_2)

{
    *param_1 = *param_1 & 0xfffff7ff | (param_2 & 1) << 0xb;
    return;
}

/* ================================================================
 * FUN_0800bb32  @  0x0800BB32
 */

uint32_t FUN_0800bb32(int param_1)

{
    return *(uint32_t *)(param_1 + 0xc) & 0xffff;
}

/* ================================================================
 * FUN_0800bb38  @  0x0800BB38
 */

void FUN_0800bb38(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0xc) = param_2;
    return;
}

/* ================================================================
 * FUN_0800bb3c  @  0x0800BB3C
 */

bool FUN_0800bb3c(int param_1, uint32_t param_2)

{
    return (*(uint32_t *)(param_1 + 8) & param_2) != 0;
}

/* ================================================================
 * FUN_0800bb4a  @  0x0800BB4A
 */

void FUN_0800bb4a(uint32_t *param_1, char *param_2)

{
    char cVar1;
    uint32_t uVar2;

    param_1[7] = param_1[7] & 0xfffff7ff;
    cVar1 = *param_2;
    if (cVar1 == '\0') {
        uVar2 = *param_1 & 0xffff7fff;
    LAB_0800bb8a:
        *param_1 = uVar2;
        uVar2 = *param_1 & 0xffffbfff;
    LAB_0800bba2:
        *param_1 = uVar2;
        uVar2 = *param_1 & 0xfffffbff;
    } else {
        if (cVar1 != '\x01') {
            if (cVar1 == '\x02') {
                uVar2 = *param_1 | 0x8000;
                /* goto LAB_0800bb8a; */ (void)0;
            }
            if (cVar1 != '\x03')
                /* goto LAB_0800bbac; */ (void)0;
            *param_1 = *param_1 | 0x8000;
            uVar2 = *param_1 | 0x4000;
            /* goto LAB_0800bba2; */ (void)0;
        }
        *param_1 = *param_1 & 0xffff7fff;
        *param_1 = *param_1 & 0xffffbfff;
        uVar2 = *param_1 | 0x400;
    }
    *param_1 = uVar2;
LAB_0800bbac:
    *param_1 = *param_1 & 0xfffffdff | ((byte)param_2[7] & 1) << 9;
    if ((param_2[1] == '\x01') && (param_2[7] == '\x01')) {
        uVar2 = *param_1 | 0x100;
    } else {
        uVar2 = *param_1 & 0xfffffeff;
    }
    *param_1 = uVar2;
    *param_1 = *param_1 & 0xfffffffb | ((byte)param_2[1] & 1) << 2;
    if ((byte)param_2[2] < 8) {
        param_1[1] = param_1[1] & 0xfffffeff;
        *param_1 = *param_1 & 0xffffffc7 | ((byte)param_2[2] & 7) << 3;
    } else {
        param_1[1] = param_1[1] | 0x100;
        *param_1 = *param_1 & 0xffffffc7 | ((byte)param_2[2] & 7) << 3;
    }
    *param_1 = *param_1 & 0xffffff7f | ((byte)param_2[3] & 1) << 7;
    *param_1 = *param_1 & 0xfffff7ff | ((byte)param_2[4] & 1) << 0xb;
    *param_1 = *param_1 & 0xfffffffd | ((byte)param_2[5] & 1) << 1;
    *param_1 = *param_1 & 0xfffffffe | (byte)param_2[6] & 1;
    return;
}

/* ================================================================
 * FUN_0800bc30  @  0x0800BC30
 */

void FUN_0800bc30(char *param_1, int param_2, uint32_t param_3)

{
    FUN_0800bc68(param_2 + 0x1a, param_3 & 0xffff);
    if (*param_1 == '\x03') {
        FUN_0800bc68(param_2 + 0x14, param_3 >> 0x10);
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800bc58  @  0x0800BC58
 */

void FUN_0800bc58(uint8_t *param_1, uint32_t param_2)

{
    *param_1 = (char)param_2;
    param_1[1] = (char)((uint32_t)param_2 >> 8);
    param_1[2] = (char)((uint32_t)param_2 >> 0x10);
    param_1[3] = (char)((uint32_t)param_2 >> 0x18);
    return;
}

/* ================================================================
 * FUN_0800bc68  @  0x0800BC68
 */

void FUN_0800bc68(uint8_t *param_1, uint32_t param_2)

{
    *param_1 = (char)param_2;
    param_1[1] = (char)((uint32_t)param_2 >> 8);
    return;
}

/* ================================================================
 * FUN_0800bc70  @  0x0800BC70
 */

void FUN_0800bc70(void)

{
    short sVar1;
    bool bVar2;
    uint32_t uVar3;
    int iVar4;
    byte bVar5;

    uVar3 = DAT_0800bd18;
    bVar2 = false;
    bVar5 = 0xff;
    sVar1 = 0;
    do {
        while (iVar4 = FUN_08008d5e(uVar3, 0x80), iVar4 != 0) {
            iVar4 = sys_is_usb_charging();
            if (iVar4 == 1) {
                if (bVar5 == 0xff) {
                    FUN_080094f4(9999, 0x8f,
                                 (uint32_t)((short)(*(byte *)(DAT_0800bd1c + 0x23) + 1) * 9999) /
                                         10 &
                                     0xffff);
                }
                iVar4 = FUN_08008d5e(DAT_0800bd20, 2);
                if (iVar4 == 0) {
                    if (!bVar2) {
                        ui_draw_charging_level_bars(5);
                        bVar2 = true;
                    }
                } else {
                    if (sVar1 == 0) {
                        if (bVar5 < 5) {
                            bVar5 = bVar5 + 1;
                        } else {
                            bVar5 = 1;
                        }
                        ui_draw_charging_level_bars(bVar5);
                        sVar1 = 0x4f;
                    }
                    sVar1 = sVar1 + -1;
                    bVar2 = false;
                }
            }
        }
        sys_delay_ms(10);
        iVar4 = FUN_08008d5e(uVar3, 0x80);
    } while (iVar4 != 0);
    gpio_write(DAT_0800b06c, 1);
    gpio_write(DAT_0800b06c + -5, 1);
    uVar3 = DAT_0800b070;
    FUN_08008cb0(DAT_0800b070, &stack0xfffffff0);
    FUN_08008c94(uVar3, 0x40);
    uVar3 = DAT_0800b074;
    FUN_08008cb0(DAT_0800b074, &stack0xfffffff0);
    FUN_08008c90(uVar3, 4);
    return;
}

/* ================================================================
 * FUN_0800bd24  @  0x0800BD24
 */

int FUN_0800bd24() {
    char *param_1 = 0;
    int iVar1;
    char *pcVar2;
    int iVar3;

    iVar1 = FUN_0800bda8();
    if (iVar1 == 0) {
        if ((*param_1 == '\x03') && (param_1[4] == '\x01')) {
            pcVar2 = param_1 + 0x30;
            FUN_080006e8(pcVar2, 0x1000);
            FUN_0800bc68(param_1 + 0x22e, 0xaa55);
            FUN_0800bc58(pcVar2, DAT_0800bda0);
            FUN_0800bc58(param_1 + 0x214, DAT_0800bda4);
            FUN_0800bc58(param_1 + 0x218, *(uint32_t *)(param_1 + 0x10));
            FUN_0800bc58(param_1 + 0x21c, *(uint32_t *)(param_1 + 0xc));
            *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x1c) + 1;
            fs_fat32_write_block(param_1[1], pcVar2, *(int *)(param_1 + 0x1c) + 1, 1);
            param_1[4] = '\0';
        }
        iVar3 = fs_fat32_get_sector_info(param_1[1], 0);
        if (iVar3 != 0) {
            iVar1 = 1;
        }
    }
    return iVar1;
}

/* ================================================================
 * FUN_0800bda8  @  0x0800BDA8
 */

uint32_t FUN_0800bda8() {
    int param_1 = 0;
    int iVar1;
    uint32_t uVar2;

    uVar2 = 0;
    if (*(char *)(param_1 + 3) != '\0') {
        iVar1 = fs_fat32_write_block(*(uint8_t *)(param_1 + 1), param_1 + 0x30,
                                     *(uint32_t *)(param_1 + 0x2c), 1);
        if (iVar1 == 0) {
            *(uint8_t *)(param_1 + 3) = 0;
            if (((uint32_t)(*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x20)) <
                 *(uint32_t *)(param_1 + 0x18)) &&
                (*(char *)(param_1 + 2) == '\x02')) {
                fs_fat32_write_block(*(uint8_t *)(param_1 + 1), param_1 + 0x30,
                                     *(int *)(param_1 + 0x2c) + *(uint32_t *)(param_1 + 0x18), 1);
            }
        } else {
            uVar2 = 1;
        }
    }
    return uVar2;
}

/* ================================================================
 * FUN_0800bdf2  @  0x0800BDF2
 */

void FUN_0800bdf2(uint32_t param_1, uint32_t *param_2)

{
    int64_t lVar1;
    uint32_t *puVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;
    int iVar6;
    uint32_t uVar7;
    uint32_t unaff_r4;

    *param_2 = 0x14;
    FUN_08002c20();
    FUN_08002a20(1);
    do {
        iVar3 = FUN_08002b7c();
    } while (iVar3 == 0);
    FUN_08002bc8(2, 0x23);
    FUN_08002a20(2, 1);
    do {
        iVar3 = FUN_08002b5c(0x19);
    } while (iVar3 != 1);
    FUN_080029d4(0);
    FUN_080029f4(0);
    FUN_080029e4(0);
    FUN_08002a04(1);
    FUN_08002c68(2);
    do {
        iVar3 = FUN_08002ca0();
    } while (iVar3 != 2);
    FUN_08002a04(0);
    iVar4 = FUN_08002ca0();
    puVar2 = DAT_0800bf10;
    iVar3 = DAT_0800bf0c;
    if (iVar4 == 0) {
        if ((-1 < *(int *)(DAT_0800bf0c + 0x54) << 0x16) ||
            (uVar5 = DAT_0800bf14, -1 < *(int *)(DAT_0800bf0c + 0x30) << 6))
            /* goto LAB_0800be8a; */ (void)0;
    } else {
        if ((iVar4 == 1) || (iVar4 != 2)) {
        LAB_0800be8a:
            *DAT_0800bf10 = DAT_0800bf08;
            /* goto LAB_0800bef4; */ (void)0;
        }
        iVar4 = *(int *)(DAT_0800bf0c + 4) << 0xf;
        if (*(int *)(DAT_0800bf0c + 0x2c) < 0) {
            if ((-1 < iVar4) || (uVar5 = DAT_0800bf08, *(int *)(DAT_0800bf0c + 4) << 0xe < 0)) {
                uVar5 = DAT_0800bf18;
            }
            lVar1 =
                (uint64_t)uVar5 * (uint64_t)((*(uint32_t *)(DAT_0800bf0c + 0x2c) & 0x1ffff) >> 8);
            uVar5 = FUN_0800030a((int)lVar1, (int)((uint64_t)lVar1 >> 0x20),
                                 ((*(uint32_t *)(DAT_0800bf0c + 0x2c) & 0xff) >> 4)
                                     << (*(uint32_t *)(DAT_0800bf0c + 0x2c) & 7),
                                 0, unaff_r4);
        } else {
            uVar5 = (*(uint32_t *)(DAT_0800bf0c + 4) & 0x3fffff) >> 0x12;
            uVar7 = (*(uint32_t *)(DAT_0800bf0c + 4) & 0x7fffffff) >> 0x1d;
            if ((uVar7 == 0) && (uVar5 != 0xf)) {
                iVar6 = uVar5 + 2;
            } else {
                iVar6 = uVar5 + uVar7 * 0x10 + 1;
            }
            uVar5 = DAT_0800bf18;
            if ((iVar4 < 0) && (-1 < *(int *)(DAT_0800bf0c + 4) << 0xe)) {
                uVar5 = DAT_0800bf08;
            }
            uVar5 = uVar5 * iVar6;
        }
    }
    *puVar2 = uVar5;
LAB_0800bef4:
    *puVar2 = *puVar2 >> *(sbyte *)(DAT_0800bf1c + ((*(uint32_t *)(iVar3 + 4) & 0xff) >> 4));
    return;
}

/* ================================================================
 * FUN_0800bf70  @  0x0800BF70
 */

void FUN_0800bf70(void)

{
    int iVar1;
    int iVar2;
    char cVar3;
    uint8_t uVar4;
    uint8_t uVar5;
    byte bVar6;
    uint32_t uVar7;

    iVar1 = DAT_0800c100;
    if (*(char *)(DAT_0800c100 + 2) == '\0') {
        *(uint8_t *)(DAT_0800c100 + 5) = 1;
        *(uint8_t *)(iVar1 + 2) = 1;
        *(uint8_t *)(iVar1 + 6) = 0;
    }
    if (*(char *)(iVar1 + 1) == '\0') {
        ui_handle_settings_nav(*(uint8_t *)(iVar1 + 5), 0, 0);
        *(uint8_t *)(iVar1 + 1) = 1;
    }
    iVar2 = DAT_0800c104;
    cVar3 = *(char *)(DAT_0800c104 + 2);
    if (cVar3 == '\t') {
        if (*(char *)(iVar1 + 6) != '\0') {
            if (8 < *(byte *)(DAT_0800c104 + 0x23))
                /* goto LAB_0800c0b6; */ (void)0;
            bVar6 = *(byte *)(DAT_0800c104 + 0x23) + 1;
            /* goto LAB_0800bff4; */ (void)0;
        }
        bVar6 = *(byte *)(iVar1 + 5);
        if (8 < bVar6)
            /* goto LAB_0800c0b6; */ (void)0;
        *(byte *)(iVar1 + 5) = bVar6 + 1;
        if (bVar6 == 2) {
        LAB_0800c04a:
            ui_draw_brightness_menu(0);
        } else if (bVar6 == 5) {
            ui_draw_auto_shutdown_menu();
        } else {
        LAB_0800c036:
            ui_handle_settings_nav(0, bVar6, 0);
        }
    LAB_0800bfde:
        cVar3 = '\0';
        uVar7 = 0;
        uVar5 = 0;
        uVar4 = *(uint8_t *)(iVar1 + 5);
    } else {
        if (cVar3 == '\x01') {
            if (*(char *)(iVar1 + 6) == '\0') {
                bVar6 = *(byte *)(iVar1 + 5);
                if (bVar6 < 2)
                    /* goto LAB_0800c0b6; */ (void)0;
                *(byte *)(iVar1 + 5) = bVar6 - 1;
                if (bVar6 != 3) {
                    if (bVar6 != 6)
                        /* goto LAB_0800c036; */ (void)0;
                    /* goto LAB_0800c04a; */ (void)0;
                }
                ui_draw_language_menu();
                /* goto LAB_0800bfde; */ (void)0;
            }
            if (*(char *)(DAT_0800c104 + 0x23) == '\0')
                /* goto LAB_0800c0b6; */ (void)0;
            bVar6 = *(char *)(DAT_0800c104 + 0x23) - 1;
        LAB_0800bff4:
            *(byte *)(DAT_0800c104 + 0x23) = bVar6;
            FUN_080094f4(9999, 0x8f, (uint32_t)((short)(bVar6 + 1) * 9999) / 10 & 0xffff);
            FUN_0800558c(*(char *)(iVar2 + 0x23) + '\x01', 1);
            /* goto LAB_0800c0b6; */ (void)0;
        }
        if (cVar3 == '\x05') {
            uVar7 = (uint32_t)*(byte *)(iVar1 + 5);
            if (uVar7 < 3) {
                if ((uint32_t)*(byte *)(DAT_0800c104 + 0x20) == uVar7 - 1)
                    /* goto LAB_0800c0b6; */ (void)0;
                cVar3 = *(byte *)(DAT_0800c104 + 0x20) + 1;
            } else {
                if (uVar7 == 3) {
                    ui_handle_settings_nav(0, 0);
                    *(uint8_t *)(iVar1 + 6) = 1;
                    /* goto LAB_0800c0b6; */ (void)0;
                }
                if (uVar7 < 6) {
                    if ((uint32_t)*(byte *)(DAT_0800c104 + 0x21) == uVar7 - 4)
                        /* goto LAB_0800c0b6; */ (void)0;
                    cVar3 = *(byte *)(DAT_0800c104 + 0x21) + 4;
                } else {
                    if ((uint32_t)*(byte *)(DAT_0800c104 + 0x22) == uVar7 - 6)
                        /* goto LAB_0800c0b6; */ (void)0;
                    cVar3 = *(byte *)(DAT_0800c104 + 0x22) + 6;
                }
            }
            uVar5 = 0;
        } else {
            if (cVar3 != '\r')
                /* goto LAB_0800c0b6; */ (void)0;
            if (*(char *)(iVar1 + 6) != '\0') {
                FUN_0800558c(*(char *)(DAT_0800c104 + 0x23) + '\x01', 0);
                *(uint8_t *)(iVar1 + 6) = 0;
                *(uint8_t *)(iVar2 + 2) = 0;
                /* goto LAB_0800c0b6; */ (void)0;
            }
            cVar3 = '\0';
            uVar5 = *(uint8_t *)(iVar1 + 5);
            uVar7 = 0;
        }
        uVar4 = 0;
    }
    ui_handle_settings_nav(uVar4, uVar5, uVar7, cVar3);
LAB_0800c0b6:
    if (*(char *)(iVar2 + 5) == '\x01') {
        if (*(byte *)(iVar1 + 5) < 3) {
            ui_draw_language_menu();
        } else if (*(byte *)(iVar1 + 5) < 6) {
            ui_draw_brightness_menu(*(uint8_t *)(iVar1 + 6));
        } else {
            ui_draw_auto_shutdown_menu();
        }
        if (*(char *)(iVar1 + 3) == '\x01') {
            ui_handle_settings_nav(*(uint8_t *)(iVar1 + 5), 0, 0);
        }
        *(uint8_t *)(iVar2 + 5) = 0;
    }
    return;
}

/* ================================================================
 * FUN_0800c108  @  0x0800C108
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c108(int param_1)

{
    if (param_1 == 4) {
        _DAT_e000e010 = _DAT_e000e010 | 4;
    } else {
        _DAT_e000e010 = _DAT_e000e010 & 0xfffffffb;
    }
    return;
}

/* ================================================================
 * FUN_0800c120  @  0x0800C120
 */

void FUN_0800c120(void)

{
    uint32_t uVar1;
    uint8_t auStack_20[4];
    uint32_t local_1c;

    FUN_080006e8(auStack_20, 0x14);
    FUN_08002a64(auStack_20);
    gpio_write(DAT_0800c180, 1);
    uVar1 = DAT_0800c188;
    FUN_0800c18c(DAT_0800c188, 9999, local_1c / DAT_0800c184 - 1);
    FUN_0800c1b8(uVar1, 0);
    FUN_0800c1d2(uVar1, 1);
    FUN_0800aa78(3);
    FUN_0800a9fc(0x19, 0);
    FUN_0800c1c2(uVar1, 1);
    return;
}

/* ================================================================
 * FUN_0800c18c  @  0x0800C18C
 */

void FUN_0800c18c(int param_1, uint32_t param_2, uint32_t param_3)

{
    *(uint32_t *)(param_1 + 0x2c) = param_2;
    *(uint32_t *)(param_1 + 0x28) = param_3;
    *(uint32_t *)(param_1 + 0x14) = *(uint32_t *)(param_1 + 0x14) | 1;
    return;
}

/* ================================================================
 * FUN_0800c19a  @  0x0800C19A
 */

void FUN_0800c19a(int param_1, int param_2, uint32_t param_3)

{
    if (param_2 == 0) {
        *(uint32_t *)(param_1 + 0x34) = param_3;
        return;
    }
    if (param_2 != 2) {
        if (param_2 != 4) {
            if (param_2 == 6) {
                *(uint32_t *)(param_1 + 0x40) = param_3;
            }
            return;
        }
        *(uint32_t *)(param_1 + 0x3c) = param_3;
        return;
    }
    *(uint32_t *)(param_1 + 0x38) = param_3;
    return;
}

/* ================================================================
 * FUN_0800c1b8  @  0x0800C1B8
 */

void FUN_0800c1b8(uint32_t *param_1, uint32_t param_2)

{
    *param_1 = *param_1 & 0xffffff8f | (param_2 & 7) << 4;
    return;
}

/* ================================================================
 * FUN_0800c1c2  @  0x0800C1C2
 */

void FUN_0800c1c2(uint32_t *param_1, uint32_t param_2)

{
    *param_1 = *param_1 & 0xfffffffe | param_2 & 1;
    return;
}

/* ================================================================
 * FUN_0800c1d2  @  0x0800C1D2
 */

void FUN_0800c1d2() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    if (param_3 == 1) {
        param_2 = *(uint32_t *)(param_1 + 0xc) | param_2;
    } else {
        if (param_3 != 0) {
            return;
        }
        param_2 = *(uint32_t *)(param_1 + 0xc) & ~param_2;
    }
    *(uint32_t *)(param_1 + 0xc) = param_2;
    return;
}

/* ================================================================
 * FUN_0800c1fc  @  0x0800C1FC
 */

void FUN_0800c1fc(int param_1, int param_2, uint32_t param_3)

{
    uint32_t uVar1;

    if (param_2 == 0) {
        uVar1 = *(uint32_t *)(param_1 + 0x18) & 0xfffffff7 | (param_3 & 1) << 3;
    } else {
        if (param_2 != 2) {
            if (param_2 == 4) {
                uVar1 = *(uint32_t *)(param_1 + 0x1c) & 0xfffffff7 | (param_3 & 1) << 3;
            } else {
                if (param_2 != 6) {
                    return;
                }
                uVar1 = *(uint32_t *)(param_1 + 0x1c) & 0xfffff7ff | (param_3 & 1) << 0xb;
            }
            *(uint32_t *)(param_1 + 0x1c) = uVar1;
            return;
        }
        uVar1 = *(uint32_t *)(param_1 + 0x18) & 0xfffff7ff | (param_3 & 1) << 0xb;
    }
    *(uint32_t *)(param_1 + 0x18) = uVar1;
    return;
}

/* ================================================================
 * FUN_0800c22e  @  0x0800C22E
 */

void FUN_0800c22e(int param_1, int param_2, byte *param_3)

{
    byte bVar1;
    byte bVar2;
    uint32_t uVar3;
    uint32_t uVar4;

    bVar1 = param_3[1];
    bVar2 = param_3[2];
    *(uint32_t *)(param_1 + 4) = *(uint32_t *)(param_1 + 4) & ~(1 << (param_2 + 9U & 0xff));
    *(uint32_t *)(param_1 + 4) =
        *(uint32_t *)(param_1 + 4) | (uint32_t)bVar2 << (param_2 + 9U & 0xff) & 0xffff;
    *(uint32_t *)(param_1 + 4) = *(uint32_t *)(param_1 + 4) & ~(1 << (param_2 + 8U & 0xff));
    *(uint32_t *)(param_1 + 4) =
        *(uint32_t *)(param_1 + 4) | (uint32_t)bVar1 << (param_2 + 8U & 0xff) & 0xffff;
    if (param_2 == 0) {
        uVar3 = *(uint32_t *)(param_1 + 0x18) & 0xffffff8f | (*param_3 & 7) << 4;
    } else {
        if (param_2 != 2) {
            if (param_2 == 4) {
                uVar3 = *(uint32_t *)(param_1 + 0x1c) & 0xffffff8f | (*param_3 & 7) << 4;
            } else {
                if (param_2 != 6)
                    /* goto LAB_0800c2a4; */ (void)0;
                uVar3 = *(uint32_t *)(param_1 + 0x1c) & 0xffff8fff | (*param_3 & 7) << 0xc;
            }
            *(uint32_t *)(param_1 + 0x1c) = uVar3;
            /* goto LAB_0800c2a4; */ (void)0;
        }
        uVar3 = *(uint32_t *)(param_1 + 0x18) & 0xffff8fff | (*param_3 & 7) << 0xc;
    }
    *(uint32_t *)(param_1 + 0x18) = uVar3;
LAB_0800c2a4:
    uVar3 = param_2 * 2 + 3;
    uVar4 = param_2 * 2 + 1;
    uVar4 = (*(uint32_t *)(param_1 + 0x20) & ~(1 << (uVar3 & 0xff)) |
             (uint32_t)param_3[4] << (uVar3 & 0xff) & 0xffff) &
                ~(1 << (uVar4 & 0xff)) |
            (uint32_t)param_3[3] << (uVar4 & 0xff) & 0xffff;
    uVar3 = param_2 * 2 + 2;
    *(uint32_t *)(param_1 + 0x20) = uVar4;
    *(uint32_t *)(param_1 + 0x20) =
        (uVar4 & ~(1 << (uVar3 & 0xff)) | (uint32_t)param_3[6] << (uVar3 & 0xff) & 0xffff) &
            ~(1 << (param_2 << 1 & 0xffU)) |
        (uint32_t)param_3[5] << (param_2 << 1 & 0xffU) & 0xffff;
    return;
}

/* ================================================================
 * FUN_0800c2f8  @  0x0800C2F8
 */

void FUN_0800c2f8(uint8_t *param_1)

{
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    return;
}

/* ================================================================
 * FUN_0800c30a  @  0x0800C30A
 */

void FUN_0800c30a(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0x44) = *(uint32_t *)(param_1 + 0x44) & 0xffff7fff | (param_2 & 1)
                                                                                     << 0xf;
    return;
}

/* ================================================================
 * FUN_0800c314  @  0x0800C314
 */

void FUN_0800c314(uint32_t *param_1, uint32_t param_2)

{
    *param_1 = *param_1 & 0xffffff7f | (param_2 & 1) << 7;
    return;
}

/* ================================================================
 * FUN_0800c498  @  0x0800C498
 */

void FUN_0800c498(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 4) = param_2 & 0x1ff;
    return;
}

/* ================================================================
 * FUN_0800c4a0  @  0x0800C4A0
 */

void FUN_0800c4a0(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0x14) = *(uint32_t *)(param_1 + 0x14) & 0xffffffbf | (param_2 & 1) << 6;
    return;
}

/* ================================================================
 * FUN_0800c4b4  @  0x0800C4B4
 */

uint64_t FUN_0800c4b4(uint32_t *param_1, uint32_t param_2)

{
    if ((param_2 & 0x1f) != 0) {
        return CONCAT44(*param_1, param_1[1]);
    }
    *param_1 = ~param_2;
    return CONCAT44(~param_2, param_1);
}

/* ================================================================
 * FUN_0800c4c4  @  0x0800C4C4
 */

bool FUN_0800c4c4(uint32_t *param_1, uint32_t param_2)

{
    return (*param_1 & param_2) != 0;
}

/* ================================================================
 * FUN_0800c4d0  @  0x0800C4D0
 */

void FUN_0800c4d0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    uint8_t auStack_28[8];
    int local_20;
    int local_1c;

    FUN_08002a64(auStack_28);
    if (param_1 == DAT_0800c528) {
        local_1c = local_20;
    }
    param_2 = (uint32_t)(local_1c * 10) / param_2;
    uVar1 = param_2 / 10;
    if (4 < param_2 % 10) {
        uVar1 = uVar1 + 1;
    }
    *(uint32_t *)(param_1 + 8) = *(uint32_t *)(param_1 + 8) & 0xffff0000 | uVar1 & 0xffff;
    *(uint32_t *)(param_1 + 0xc) = *(uint32_t *)(param_1 + 0xc) & 0xffffefff | (param_3 & 1) << 0xc;
    *(uint32_t *)(param_1 + 0x10) = *(uint32_t *)(param_1 + 0x10) & 0xffffcfff | (param_4 & 3)
                                                                                     << 0xc;
    return;
}

/* ================================================================
 * FUN_0800c52c  @  0x0800C52C
 */

void FUN_0800c52c(int param_1, uint32_t param_2, int param_3)

{
    uint32_t *puVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    puVar1 = (uint32_t *)(param_1 + (param_2 >> 0x10));
    uVar3 = 1 << (param_2 & 0x1f);
    uVar2 = *puVar1;
    if (param_3 == 1) {
        uVar2 = uVar2 | uVar3;
    } else {
        uVar2 = uVar2 & ~uVar3;
    }
    *puVar1 = uVar2;
    return;
}

/* ================================================================
 * FUN_0800c54a  @  0x0800C54A
 */

bool FUN_0800c54a(uint32_t *param_1, uint32_t param_2)

{
    uint32_t uVar1;

    if (param_2 == 0x20) {
        uVar1 = (param_1[3] & 0x3f) >> 5;
        goto joined_r0x0800c5ac;
    }
    if ((int)param_2 < 0x21) {
        if (param_2 == 4) {
        LAB_0800c5b8:
            uVar1 = param_1[5] & 1;
        } else if ((int)param_2 < 5) {
            if (param_2 != 1) {
                if (param_2 != 2) {
                    return false;
                }
                /* goto LAB_0800c5b8; */ (void)0;
            }
            uVar1 = (param_1[3] & 0x1ff) >> 8;
        } else if (param_2 == 8) {
            if ((int)(param_1[3] << 0x1a) < 0)
                /* goto LAB_0800c5c8; */ (void)0;
            uVar1 = param_1[5] & 1;
        } else {
            if (param_2 != 0x10) {
                return false;
            }
            uVar1 = (param_1[3] & 0x1f) >> 4;
        }
    } else if (param_2 == 0x40) {
        uVar1 = param_1[3];
    LAB_0800c594:
        uVar1 = (uVar1 & 0x7f) >> 6;
    } else if (param_2 == 0x80) {
        uVar1 = (param_1[3] & 0xff) >> 7;
    } else {
        if (param_2 == 0x100) {
            uVar1 = param_1[4];
            /* goto LAB_0800c594; */ (void)0;
        }
        if (param_2 != 0x200) {
            return false;
        }
        uVar1 = (param_1[5] & 0x7ff) >> 10;
    }
joined_r0x0800c5ac:
    if (uVar1 == 0) {
        return false;
    }
LAB_0800c5c8:
    return (*param_1 & param_2) != 0;
}

/* ================================================================
 * FUN_0800c5ea  @  0x0800C5EA
 */

void FUN_0800c5ea(int param_1)

{
    *(uint32_t *)(param_1 + 0x900) = *(uint32_t *)(param_1 + 0x900) & 0xfffff800;
    *(uint32_t *)(param_1 + 0x804) = *(uint32_t *)(param_1 + 0x804) & 0xfffffeff;
    return;
}

/* ================================================================
 * FUN_0800c604  @  0x0800C604
 */

void FUN_0800c604(int param_1)

{
    *(uint32_t *)(param_1 + 0xb10) = 0;
    *(uint32_t *)(param_1 + 0xb10) = *(uint32_t *)(param_1 + 0xb10) & 0xe007ffff | 0x80000;
    *(uint32_t *)(param_1 + 0xb10) = (*(uint32_t *)(param_1 + 0xb10) & 0xfff80000) + 0x18;
    *(uint32_t *)(param_1 + 0xb10) = *(uint32_t *)(param_1 + 0xb10) | 0x60000000;
    return;
}

/* ================================================================
 * FUN_0800c634  @  0x0800C634
 */

void FUN_0800c634(int param_1, byte *param_2)

{
    int iVar1;

    iVar1 = param_1 + (uint32_t)*param_2 * 0x20;
    if (param_2[2] == 0) {
        *(uint32_t *)(iVar1 + 0x900) = *(uint32_t *)(iVar1 + 0x900) & 0xffdfffff;
        if ((param_2[3] == 3) || (param_2[3] == 2)) {
            param_1 = param_1 + (uint32_t)*param_2 * 0x20;
            *(uint32_t *)(param_1 + 0x900) = *(uint32_t *)(param_1 + 0x900) | 0x10000000;
            return;
        }
    } else {
        *(uint32_t *)(iVar1 + 0xb00) = *(uint32_t *)(iVar1 + 0xb00) & 0xffdfffff;
        if ((param_2[3] == 3) || (param_2[3] == 2)) {
            param_1 = param_1 + (uint32_t)*param_2 * 0x20;
            *(uint32_t *)(param_1 + 0xb00) = *(uint32_t *)(param_1 + 0xb00) | 0x10000000;
        }
    }
    return;
}

/* ================================================================
 * FUN_0800c692  @  0x0800C692
 */

void FUN_0800c692(int param_1, int param_2, uint32_t param_3)

{
    *(uint32_t *)(param_1 + param_2 * 0x20 + 0x908) = param_3;
    return;
}

/* ================================================================
 * FUN_0800c69c  @  0x0800C69C
 */

uint32_t FUN_0800c69c(int param_1, uint32_t param_2)

{
    return *(uint32_t *)(param_1 + param_2 * 0x20 + 0x908) &
           (*(uint32_t *)(param_1 + 0x810) |
            (*(uint32_t *)(param_1 + 0x834) >> (param_2 & 0xff) & 1) << 7);
}

/* ================================================================
 * FUN_0800c7d2  @  0x0800C7D2
 */

void FUN_0800c7d2(int param_1, int param_2, uint32_t param_3)

{
    *(uint32_t *)(param_1 + param_2 * 0x20 + 0xb08) = param_3;
    return;
}

/* ================================================================
 * FUN_0800c7dc  @  0x0800C7DC
 */

uint32_t FUN_0800c7dc(int param_1, int param_2)

{
    return *(uint32_t *)(param_1 + 0x814) & *(uint32_t *)(param_1 + param_2 * 0x20 + 0xb08);
}

/* ================================================================
 * FUN_0800c7ec  @  0x0800C7EC
 */

void FUN_0800c7ec(int param_1, byte *param_2)

{
    int iVar1;

    iVar1 = param_1 + (uint32_t)*param_2 * 0x20;
    if (param_2[2] != 0) {
        if (-1 < *(int *)(iVar1 + 0xb00)) {
            *(uint32_t *)(iVar1 + 0xb00) = *(uint32_t *)(iVar1 + 0xb00) & 0xbfffffff;
        }
        param_1 = param_1 + (uint32_t)*param_2 * 0x20;
        *(uint32_t *)(param_1 + 0xb00) = *(uint32_t *)(param_1 + 0xb00) | 0x200000;
        return;
    }
    if (-1 < *(int *)(iVar1 + 0x900)) {
        *(uint32_t *)(iVar1 + 0x900) = *(uint32_t *)(iVar1 + 0x900) & 0xbfffffff;
    }
    param_1 = param_1 + (uint32_t)*param_2 * 0x20;
    *(uint32_t *)(param_1 + 0x900) = *(uint32_t *)(param_1 + 0x900) | 0x200000;
    return;
}

/* ================================================================
 * FUN_0800c848  @  0x0800C848
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c848(uint32_t param_1)

{
    int iVar1;
    char *pcVar2;
    uint32_t extraout_r3;
    uint32_t unaff_r4;
    uint32_t unaff_lr;

    FUN_08008350();
    *DAT_0800c85c = param_1;
    iVar1 = FUN_08007c28(_DAT_0800823c, &DAT_08008238, 1, extraout_r3, unaff_r4, unaff_lr);
    if (iVar1 == 0) {
        pcVar2 = s_2_APPusbflash_init_ok_08008258;
    } else {
        pcVar2 = s_2_APPusbflash_init_err_0800823f + 1;
    }
    display_debug_printf(pcVar2);
    return;
}

/* ================================================================
 * FUN_0800c860  @  0x0800C860
 */

void FUN_0800c860(int param_1, uint32_t param_2)

{
    bool bVar1;
    uint32_t uVar2;

    *(uint32_t *)(param_1 + 0x10) = *(uint32_t *)(param_1 + 0x10) & 0xfffff83f | (param_2 & 0x1f)
                                                                                     << 6;
    *(uint32_t *)(param_1 + 0x10) = *(uint32_t *)(param_1 + 0x10) | 0x20;
    uVar2 = 0;
    do {
        if (-1 < *(int *)(param_1 + 0x10) << 0x1a) {
            return;
        }
        bVar1 = uVar2 <= DAT_0800c888;
        uVar2 = uVar2 + 1;
    } while (bVar1);
    return;
}

/* ================================================================
 * FUN_0800c88c  @  0x0800C88C
 */

uint32_t FUN_0800c88c(int param_1)

{
    return *(uint32_t *)(param_1 + 0x81c) & *(uint32_t *)(param_1 + 0x818) & 0xffff;
}

/* ================================================================
 * FUN_0800c89a  @  0x0800C89A
 */

uint32_t FUN_0800c89a() {
    int param_1 = 0;
    return (*(uint32_t *)(param_1 + 0x81c) & *(uint32_t *)(param_1 + 0x818)) >> 0x10;
}

/* ================================================================
 * FUN_0800c8a8  @  0x0800C8A8
 */

void FUN_0800c8a8(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0x14) = param_2;
    return;
}

/* ================================================================
 * FUN_0800c8ac  @  0x0800C8AC
 */

uint32_t FUN_0800c8ac(int param_1)

{
    return *(uint32_t *)(param_1 + 0x18) & *(uint32_t *)(param_1 + 0x14);
}

/* ================================================================
 * FUN_0800c8b4  @  0x0800C8B4
 */

void FUN_0800c8b4(int param_1, uint32_t param_2, int param_3)

{
    if (param_3 == 1) {
        param_2 = *(uint32_t *)(param_1 + 0x18) | param_2;
    } else {
        param_2 = *(uint32_t *)(param_1 + 0x18) & ~param_2;
    }
    *(uint32_t *)(param_1 + 0x18) = param_2;
    return;
}

/* ================================================================
 * FUN_0800c8c4  @  0x0800C8C4
 */

void FUN_0800c8c4(int param_1)

{
    *(uint32_t *)(param_1 + 0xe00) = *(uint32_t *)(param_1 + 0xe00) & 0xfffffffe;
    return;
}

/* ================================================================
 * FUN_0800c8d2  @  0x0800C8D2
 */

void FUN_0800c8d2(int param_1, uint32_t *param_2, uint32_t param_3, int param_4)

{
    uint32_t uVar1;

    for (uVar1 = 0; uVar1 < param_4 + 3U >> 2; uVar1 = uVar1 + 1) {
        *param_2 = *(uint32_t *)(param_1 + 0x1000);
        param_2 = param_2 + 1;
    }
    return;
}

/* ================================================================
 * FUN_0800c8ec  @  0x0800C8EC
 */

void FUN_0800c8ec(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0x800) = *(uint32_t *)(param_1 + 0x800) & 0xfffff80f | (param_2 & 0x7f)
                                                                                       << 4;
    return;
}

/* ================================================================
 * FUN_0800c8fa  @  0x0800C8FA
 */

void FUN_0800c8fa(int param_1, uint32_t param_2)

{
    *(uint32_t *)(param_1 + 0x24) = param_2;
    return;
}

/* ================================================================
 * FUN_0800c900  @  0x0800C900
 */

void FUN_0800c900(int param_1, int param_2, int param_3)

{
    uint32_t uVar1;
    uint32_t uVar2;

    uVar1 = 0;
    if (param_2 != 0) {
        uVar2 = *(uint32_t *)(param_1 + 0x24) + (*(uint32_t *)(param_1 + 0x28) >> 0x10);
        for (; (int)uVar1 < param_2 + -1; uVar1 = uVar1 + 1 & 0xff) {
            uVar2 = uVar2 + (*(uint32_t *)(param_1 + uVar1 * 4 + 0x104) >> 0x10);
        }
        *(uint32_t *)(param_1 + param_2 * 4 + 0x100) = uVar2 | param_3 << 0x10;
        return;
    }
    *(uint32_t *)(param_1 + 0x28) = *(uint32_t *)(param_1 + 0x24) | param_3 << 0x10;
    return;
}

/* ================================================================
 * FUN_0800c94c  @  0x0800C94C
 */

uint32_t FUN_0800c94c(int param_1)

{
    return *(uint32_t *)(param_1 + 0x808) & 1;
}

/* ================================================================
 * FUN_0800c956  @  0x0800C956
 */

void FUN_0800c956(int *param_1, uint32_t param_2)

{
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;

    iVar3 = *param_1;
    uVar2 = param_1[param_2 * 0xb + 9] - param_1[param_2 * 0xb + 10];
    if ((uint32_t)param_1[param_2 * 0xb + 5] <
        (uint32_t)(param_1[param_2 * 0xb + 9] - param_1[param_2 * 0xb + 10])) {
        uVar2 = param_1[param_2 * 0xb + 5];
    }
    while (uVar2 + 3 >> 2 < (*(uint32_t *)(iVar3 + param_2 * 0x20 + 0x918) & 0xffff)) {
        uVar1 = param_1[param_2 * 0xb + 9];
        if ((uVar1 <= (uint32_t)param_1[param_2 * 0xb + 10]) || (uVar1 == 0))
            break;
        uVar2 = uVar1 - param_1[param_2 * 0xb + 10];
        if ((uint32_t)param_1[param_2 * 0xb + 5] < uVar2) {
            uVar2 = param_1[param_2 * 0xb + 5];
        }
        FUN_0800c9da(iVar3, param_1[param_2 * 0xb + 8], param_2 & 0xffff, uVar2 & 0xffff);
        param_1[param_2 * 0xb + 8] = param_1[param_2 * 0xb + 8] + uVar2;
        param_1[param_2 * 0xb + 10] = param_1[param_2 * 0xb + 10] + uVar2;
    }
    if (uVar2 == 0) {
        *(uint32_t *)(iVar3 + 0x834) = *(uint32_t *)(iVar3 + 0x834) & ~(1 << (param_2 & 0xff));
    }
    return;
}

/* ================================================================
 * FUN_0800c9da  @  0x0800C9DA
 */

void FUN_0800c9da(int param_1, uint32_t *param_2, int param_3, int param_4)

{
    uint32_t uVar1;
    uint32_t uVar2;

    for (uVar2 = 0; uVar2 < param_4 + 3U >> 2; uVar2 = uVar2 + 1) {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        *(uint32_t *)(param_1 + param_3 * 0x1000 + 0x1000) = uVar1;
    }
    return;
}

/* ================================================================
 * FUN_0800c9f8  @  0x0800C9F8
 */

void FUN_0800c9f8(uint32_t *param_1, uint32_t param_2)

{
    int iVar1;

    if ((int)(param_2 << 0x18) < 0) {
        iVar1 = (param_2 & 0x7f) * 0xb + 3;
    } else {
        iVar1 = (param_2 & 0x7f) * 0xb + 0x2f;
    }
    FUN_0800c634(*param_1, param_1 + iVar1);
    *(uint8_t *)((int)(param_1 + iVar1) + 0xd) = 0;
    return;
}

/* ================================================================
 * FUN_0800ca24  @  0x0800CA24
 */

void FUN_0800ca24(int param_1, uint32_t param_2)

{
    uint32_t uVar1;
    int iVar2;
    code *UNRECOVERED_JUMPTABLE;

    iVar2 = param_1 + (param_2 & 0x7f) * 0x2c;
    if (param_2 == 0) {
        if (*(char *)(param_1 + 0x180) == '\x02') {
            uVar1 = *(uint32_t *)(iVar2 + 0x14);
            if (uVar1 < *(uint32_t *)(iVar2 + 0x30)) {
                uVar1 = *(uint32_t *)(iVar2 + 0x30) - uVar1;
                *(uint32_t *)(iVar2 + 0x30) = uVar1;
                if (*(uint32_t *)(iVar2 + 0x14) <= uVar1) {
                    uVar1 = *(uint32_t *)(iVar2 + 0x14);
                }
                FUN_0800cf04(param_1, 0, *(uint32_t *)(iVar2 + 0x20), uVar1 & 0xffff);
                return;
            }
            if (((*(uint32_t *)(iVar2 + 0x2c) == uVar1) &&
                 (uVar1 <= *(uint32_t *)(iVar2 + 0x34))) &&
                (*(uint32_t *)(iVar2 + 0x34) < (uint32_t)*(uint16_t *)(param_1 + 0x182))) {
                *(uint32_t *)(iVar2 + 0x2c) = 0;
                FUN_0800cf04(param_1, 0, 0, 0);
                FUN_0800ce6c(param_1, 0, 0);
                return;
            }
            UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0xc);
            if ((UNRECOVERED_JUMPTABLE != (code *)0x0) && (*(char *)(param_1 + 0x184) == '\x03')) {
                (*UNRECOVERED_JUMPTABLE)(param_1);
            }
            *(uint8_t *)(param_1 + 0x180) = 5;
            FUN_0800ce6c(param_1, 0, 0);
            return;
        }
    } else {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x14);
        if ((UNRECOVERED_JUMPTABLE != (code *)0x0) && (*(char *)(param_1 + 0x184) == '\x03')) {
            /* WARNING: Could not recover jumptable at 0x0800ca52. Too many branches */
            /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE)(param_1);
            return;
        }
    }
    return;
}

/* ================================================================
 * FUN_0800cad2  @  0x0800CAD2
 */

void FUN_0800cad2(int param_1, uint32_t param_2)

{
    uint32_t uVar1;
    int iVar2;
    code *UNRECOVERED_JUMPTABLE;

    iVar2 = param_1 + (param_2 & 0x7f) * 0x2c;
    if (param_2 == 0) {
        if (*(char *)(param_1 + 0x180) == '\x03') {
            if (*(uint32_t *)(iVar2 + 0xc4) < *(uint32_t *)(iVar2 + 0xe0)) {
                uVar1 = *(uint32_t *)(iVar2 + 0xe0) - *(uint32_t *)(iVar2 + 0xc4);
                *(uint32_t *)(iVar2 + 0xe0) = uVar1;
                if (*(uint32_t *)(iVar2 + 0xc4) <= uVar1) {
                    uVar1 = *(uint32_t *)(iVar2 + 0xc4);
                }
                FUN_0800ce6c(param_1, 0, *(uint32_t *)(iVar2 + 0xd0), uVar1 & 0xffff);
                return;
            }
            UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x10);
            if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                (*UNRECOVERED_JUMPTABLE)(param_1);
            }
            FUN_0800cbba(param_1);
            return;
        }
    } else {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x18);
        if ((UNRECOVERED_JUMPTABLE != (code *)0x0) && (*(char *)(param_1 + 0x184) == '\x03')) {
            /* WARNING: Could not recover jumptable at 0x0800cb00. Too many branches */
            /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE)(param_1);
            return;
        }
    }
    return;
}

/* ================================================================
 * FUN_0800cb42  @  0x0800CB42
 */

uint32_t FUN_0800cb42() {
    int param_1 = 0;
    uint32_t uVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t unaff_r4;

    sys_settings_struct_copy(param_1 + 0x16c, param_1 + 0x174);
    *(uint8_t *)(param_1 + 0x180) = 1;
    *(uint16_t *)(param_1 + 0x182) = *(uint16_t *)(param_1 + 0x172);
    uVar1 = *(byte *)(param_1 + 0x16c) & 0x1f;
    if ((*(byte *)(param_1 + 0x16c) & 0x1f) != 0) {
        if (uVar1 == 1) {
            uVar1 = FUN_0800d170(param_1);
            return uVar1;
        }
        if (uVar1 != 2) {
            return uVar1;
        }
        uVar1 = FUN_0800ccf4(param_1);
        return uVar1;
    }
    if ((*(byte *)(param_1 + 0x16c) & 0x60) != 0) {
        (**(code **)(*(int *)(param_1 + 4) + 8))();
        return 0;
    }
    switch (*(uint8_t *)(param_1 + 0x16d)) {
    case 0:
        if ((*(char *)(param_1 + 0x184) == '\x02') || (*(char *)(param_1 + 0x184) == '\x03')) {
            if (*(char *)(param_1 + 0x187) != '\0') {
                *(uint32_t *)(param_1 + 0x18c) = *(uint32_t *)(param_1 + 0x18c) | 2;
            }
            uVar3 = 2;
            iVar2 = param_1 + 0x18c;
            /* goto LAB_0800cccc; */ (void)0;
        }
        break;
    case 1:
        if ((*(char *)(param_1 + 0x184) != '\x02') && (*(char *)(param_1 + 0x184) != '\x03'))
            break;
        if (*(short *)(param_1 + 0x16e) != 1) {
            return 0;
        }
        *(uint8_t *)(param_1 + 0x187) = 0;
        *(uint32_t *)(param_1 + 0x18c) = *(uint32_t *)(param_1 + 0x18c) & 0xfffffffd;
        /* goto LAB_0800cc6e; */ (void)0;
    case 3:
        if (*(short *)(param_1 + 0x16e) != 1) {
            return 0;
        }
        *(uint8_t *)(param_1 + 0x187) = 1;
    LAB_0800cc6e:
        (**(code **)(*(int *)(param_1 + 4) + 8))(param_1);
    LAB_0800cca2:
        FUN_0800cbba(param_1);
        return 0;
    case 5:
        if ((*(short *)(param_1 + 0x170) != 0) || (*(short *)(param_1 + 0x172) != 0))
            break;
        if (*(char *)(param_1 + 0x184) == '\x03')
            break;
        *(byte *)(param_1 + 0x186) = *(byte *)(param_1 + 0x16e) & 0x7f;
        if ((*(byte *)(param_1 + 0x16e) & 0x7f) == 0) {
            *(uint8_t *)(param_1 + 0x184) = 1;
        } else {
            *(uint8_t *)(param_1 + 0x184) = 2;
        }
        /* goto LAB_0800cca2; */ (void)0;
    case 6:
        FUN_0800d032();
        return 0;
    case 8:
        if (*(short *)(param_1 + 0x172) == 1) {
            if (*(char *)(param_1 + 0x184) == '\x02') {
                *(uint8_t *)(param_1 + 0x188) = 0;
                uVar3 = 1;
                iVar2 = param_1 + 0x188;
            } else {
                if (*(char *)(param_1 + 0x184) != '\x03')
                    break;
                uVar3 = 1;
                iVar2 = param_1 + 0x189;
            }
        LAB_0800cccc:
            FUN_0800cba2(param_1, iVar2, uVar3, 0, unaff_r4);
            return 0;
        }
        break;
    case 9:
        FUN_0800d428();
        return 0;
    }
    FUN_0800cbca(param_1);
    return 0;
}

/* ================================================================
 * FUN_0800cba2  @  0x0800CBA2
 */

void FUN_0800cba2() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    *(uint32_t *)(param_1 + 0x34) = param_3;
    *(uint32_t *)(param_1 + 0x30) = param_3;
    *(uint8_t *)(param_1 + 0x180) = 2;
    FUN_0800cf04(param_1, 0, param_2, param_3);
    return;
}

/* ================================================================
 * FUN_0800cbba  @  0x0800CBBA
 */

void FUN_0800cbba(int param_1)

{
    *(uint8_t *)(param_1 + 0x180) = 4;
    FUN_0800cf04(param_1, 0, 0);
    return;
}

/* ================================================================
 * FUN_0800cbca  @  0x0800CBCA
 */

void FUN_0800cbca(uint32_t param_1)

{
    FUN_0800d4a0(param_1, 0);
    FUN_0800d4a0(param_1, 0x80);
    return;
}

/* ================================================================
 * FUN_0800cce6  @  0x0800CCE6
 */

void FUN_0800cce6(int param_1)

{
    code *UNRECOVERED_JUMPTABLE;

    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x20);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
        /* WARNING: Could not recover jumptable at 0x0800ccf0. Too many branches */
        /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1, 4);
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800ccf4  @  0x0800CCF4
 */

uint32_t FUN_0800ccf4(int param_1)

{
    byte bVar1;
    char cVar2;
    int iVar3;
    uint32_t uVar4;
    byte *pbVar5;

    pbVar5 = (byte *)(param_1 + 0x16c);
    bVar1 = *(byte *)(param_1 + 0x170);
    uVar4 = (uint32_t)bVar1;
    if ((*pbVar5 & 0x7f) >> 5 == 1) {
        (**(code **)(*(int *)(param_1 + 4) + 8))(param_1, pbVar5);
    }
    cVar2 = *(char *)(param_1 + 0x16d);
    if (cVar2 == '\0') {
        if (*(char *)(param_1 + 0x184) != '\x02') {
            if (*(char *)(param_1 + 0x184) == '\x03') {
                iVar3 = param_1 + (uVar4 & 0x7f) * 0x2c;
                if ((int)(uVar4 << 0x18) < 0) {
                    iVar3 = iVar3 + 0xc;
                } else {
                    iVar3 = iVar3 + 0xbc;
                }
                *(uint32_t *)(iVar3 + 0x10) = (uint32_t)(*(char *)(iVar3 + 0xd) == '\x01');
                FUN_0800cba2(param_1, (uint32_t *)(iVar3 + 0x10), 2);
                return 0;
            }
            /* goto LAB_0800cd9a; */ (void)0;
        }
        if ((bVar1 & 0x7f) == 0) {
            return 0;
        }
        /* goto LAB_0800cdae; */ (void)0;
    }
    if (cVar2 == '\x01') {
        if (*(char *)(param_1 + 0x184) == '\x02') {
        LAB_0800cda6:
            if (uVar4 == 0) {
                return 0;
            }
            if (uVar4 == 0x80) {
                return 0;
            }
        LAB_0800cdae:
            FUN_0800d4a0(param_1, uVar4);
            return 0;
        }
        if (*(char *)(param_1 + 0x184) != '\x03')
            /* goto LAB_0800cd9a; */ (void)0;
        if (*(short *)(param_1 + 0x16e) != 0) {
            return 0;
        }
        if ((bVar1 & 0x7f) == 0)
            /* goto LAB_0800cd86; */ (void)0;
        FUN_0800c9f8(param_1, uVar4);
    } else {
        if (cVar2 != '\x03') {
        LAB_0800cd9a:
            FUN_0800cbca(param_1);
            return 0;
        }
        if (*(char *)(param_1 + 0x184) == '\x02')
            /* goto LAB_0800cda6; */ (void)0;
        if (*(char *)(param_1 + 0x184) != '\x03')
            /* goto LAB_0800cd9a; */ (void)0;
        if (((*(short *)(param_1 + 0x16e) == 0) && (uVar4 != 0)) && (uVar4 != 0x80)) {
            FUN_0800d4a0(param_1, uVar4);
        }
    }
    (**(code **)(*(int *)(param_1 + 4) + 8))(param_1, pbVar5);
LAB_0800cd86:
    FUN_0800cbba(param_1);
    return 0;
}

/* ================================================================
 * FUN_0800cdd6  @  0x0800CDD6
 */

void FUN_0800cdd6(int *param_1)

{
    int iVar1;

    iVar1 = FUN_0800c94c(*param_1);
    if (iVar1 == 1) {
        *(uint32_t *)(*param_1 + 0xe00) = *(uint32_t *)(*param_1 + 0xe00) | 1;
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800cdf0  @  0x0800CDF0
 */

void FUN_0800cdf0(int *param_1)

{
    int iVar1;

    iVar1 = *param_1;
    FUN_0800c5ea(iVar1);
    *(uint32_t *)(iVar1 + 0xc) = (*(uint32_t *)(iVar1 + 0xc) & 0xffffc3ff) + 0x1400;
    FUN_0800ce38(param_1, 0, 0, 0x40);
    FUN_0800ce38(param_1, 0x80, 0, 0x40);
    *(uint8_t *)(param_1 + 0x61) = 1;
    if (*(code **)(param_1[1] + 4) != (code *)0x0) {
        /* WARNING: Could not recover jumptable at 0x0800ce34. Too many branches */
        /* WARNING: Treating indirect jump as call */
        (**(code **)(param_1[1] + 4))(param_1);
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800ce38  @  0x0800CE38
 */

void FUN_0800ce38() {
    int *param_1 = 0;
    uint32_t param_2 = 0;
    byte param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uVar1;
    byte *pbVar2;
    int iVar3;
    int iVar4;

    uVar1 = param_2 & 0x7f;
    iVar4 = *param_1;
    if ((int)(param_2 << 0x18) < 0) {
        *(uint8_t *)((int)param_1 + uVar1 * 0x2c + 0xe) = 0;
        iVar3 = uVar1 * 0xb + 3;
    } else {
        *(uint8_t *)((int)param_1 + uVar1 * 0x2c + 0xbe) = 1;
        iVar3 = uVar1 * 0xb + 0x2f;
    }
    pbVar2 = (byte *)(param_1 + iVar3);
    *(uint32_t *)(pbVar2 + 8) = param_4;
    pbVar2[3] = param_3;
    uVar1 = 0;
    if ((*pbVar2 == 0) && (iVar3 = *(int *)(pbVar2 + 8), iVar3 != 0x40)) {
        if (iVar3 == 0x20) {
            uVar1 = 1;
        } else if (iVar3 == 0x10) {
            uVar1 = 2;
        } else if (iVar3 == 8) {
            uVar1 = 3;
        }
    }
    if (pbVar2[2] == 0) {
        *(uint32_t *)(iVar4 + 0x81c) = *(uint32_t *)(iVar4 + 0x81c) | 1 << *pbVar2;
        if (*pbVar2 == 0) {
            *(uint32_t *)(iVar4 + 0x900) = *(uint32_t *)(iVar4 + 0x900) & 0xfffff800 | uVar1;
        } else {
            iVar3 = iVar4 + (uint32_t)*pbVar2 * 0x20;
            *(uint32_t *)(iVar3 + 0x900) =
                *(uint32_t *)(iVar3 + 0x900) & 0xfffff800 | *(uint16_t *)(pbVar2 + 8) & 0x7ff;
        }
        iVar3 = iVar4 + (uint32_t)*pbVar2 * 0x20;
        *(uint32_t *)(iVar3 + 0x900) = *(uint32_t *)(iVar3 + 0x900) & 0xfff3ffff | (pbVar2[3] & 3)
                                                                                       << 0x12;
        iVar3 = iVar4 + (uint32_t)*pbVar2 * 0x20;
        *(uint32_t *)(iVar3 + 0x900) = *(uint32_t *)(iVar3 + 0x900) & 0xfc3fffff | (*pbVar2 & 0xf)
                                                                                       << 0x16;
        iVar3 = iVar4 + (uint32_t)*pbVar2 * 0x20;
        *(uint32_t *)(iVar3 + 0x900) = *(uint32_t *)(iVar3 + 0x900) | 0x10000000;
        iVar4 = iVar4 + (uint32_t)*pbVar2 * 0x20;
        *(uint32_t *)(iVar4 + 0x900) = *(uint32_t *)(iVar4 + 0x900) | 0x8000;
        return;
    }
    *(uint32_t *)(iVar4 + 0x81c) = *(uint32_t *)(iVar4 + 0x81c) | (1 << *pbVar2) << 0x10;
    if (*pbVar2 == 0) {
        *(uint32_t *)(iVar4 + 0xb00) = *(uint32_t *)(iVar4 + 0xb00) & 0xfffff800 | uVar1;
    } else {
        iVar3 = iVar4 + (uint32_t)*pbVar2 * 0x20;
        *(uint32_t *)(iVar3 + 0xb00) =
            *(uint32_t *)(iVar3 + 0xb00) & 0xfffff800 | *(uint16_t *)(pbVar2 + 8) & 0x7ff;
    }
    iVar3 = iVar4 + (uint32_t)*pbVar2 * 0x20;
    *(uint32_t *)(iVar3 + 0xb00) = *(uint32_t *)(iVar3 + 0xb00) & 0xfff3ffff | (pbVar2[3] & 3)
                                                                                   << 0x12;
    iVar3 = iVar4 + (uint32_t)*pbVar2 * 0x20;
    *(uint32_t *)(iVar3 + 0xb00) = *(uint32_t *)(iVar3 + 0xb00) | 0x10000000;
    iVar4 = iVar4 + (uint32_t)*pbVar2 * 0x20;
    *(uint32_t *)(iVar4 + 0xb00) = *(uint32_t *)(iVar4 + 0xb00) | 0x8000;
    return;
}

/* ================================================================
 * FUN_0800ce6c  @  0x0800CE6C
 */

void FUN_0800ce6c() {
    int *param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    int param_4 = 0;
    int iVar1;
    uint32_t *puVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    int iVar6;

    uVar5 = param_2 & 0x7f;
    iVar6 = *param_1;
    param_1[uVar5 * 0xb + 0x34] = param_3;
    param_1[uVar5 * 0xb + 0x35] = param_4;
    iVar1 = iVar6 + (uint32_t)*(byte *)(param_1 + uVar5 * 0xb + 0x2f) * 0x20;
    param_1[uVar5 * 0xb + 0x36] = 0;
    puVar2 = (uint32_t *)(iVar1 + 0xb00);
    if ((param_2 & 0x7f) == 0) {
        param_4 = param_1[uVar5 * 0xb + 0x31];
        param_1[uVar5 * 0xb + 0x35] = param_4;
    }
    if ((param_4 == 0) || ((param_2 & 0x7f) == 0)) {
        *(uint32_t *)(iVar1 + 0xb10) =
            *(uint32_t *)(iVar1 + 0xb10) & 0xfff80000 | param_1[uVar5 * 0xb + 0x31] & 0x7ffffU;
        uVar4 = 1;
    } else {
        uVar3 = param_1[uVar5 * 0xb + 0x31];
        uVar4 = ((param_4 + uVar3) - 1) / uVar3;
        *(uint32_t *)(iVar1 + 0xb10) =
            *(uint32_t *)(iVar1 + 0xb10) & 0xfff80000 | uVar4 * uVar3 & 0x7ffff;
    }
    *(uint32_t *)(iVar1 + 0xb10) = *(uint32_t *)(iVar1 + 0xb10) & 0xe007ffff | (uVar4 & 0x3ff)
                                                                                   << 0x13;
    if (*(char *)((int)param_1 + uVar5 * 0x2c + 0xbf) == '\x01') {
        if ((*(uint32_t *)(iVar6 + 0x808) >> 8 & 1) == 0) {
            uVar5 = *puVar2 | 0x20000000;
        } else {
            uVar5 = *puVar2 | 0x10000000;
        }
        *puVar2 = uVar5;
    }
    *puVar2 = *puVar2 | 0x4000000;
    *puVar2 = *puVar2 | 0x80000000;
    return;
}

/* ================================================================
 * FUN_0800cf04  @  0x0800CF04
 */

void FUN_0800cf04() {
    int *param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    byte *pbVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t *puVar5;
    uint32_t uVar6;

    uVar6 = param_2 & 0x7f;
    iVar2 = *param_1;
    pbVar1 = (byte *)(param_1 + uVar6 * 0xb + 3);
    param_1[uVar6 * 0xb + 8] = param_3;
    param_1[uVar6 * 0xb + 9] = param_4;
    param_1[uVar6 * 0xb + 10] = 0;
    iVar4 = iVar2 + (uint32_t)*pbVar1 * 0x20;
    puVar5 = (uint32_t *)(iVar4 + 0x900);
    if (param_4 == 0) {
        *(uint32_t *)(iVar4 + 0x910) = *(uint32_t *)(iVar4 + 0x910) & 0xe007ffff | 0x80000;
        uVar3 = *(uint32_t *)(iVar4 + 0x910) & 0xfff80000;
    LAB_0800cf98:
        *(uint32_t *)(iVar4 + 0x910) = uVar3;
    LAB_0800cf9a:
        if (*(char *)((int)param_1 + uVar6 * 0x2c + 0xf) != '\x01')
            /* goto LAB_0800cfa0; */ (void)0;
    } else {
        uVar3 = param_1[uVar6 * 0xb + 5];
        if ((param_2 & 0x7f) == 0) {
            if (uVar3 < param_4) {
                param_1[uVar6 * 0xb + 9] = uVar3;
            }
            *(uint32_t *)(iVar4 + 0x910) =
                *(uint32_t *)(iVar4 + 0x910) & 0xfff80000 | param_1[uVar6 * 0xb + 9] & 0x7ffffU;
            *(uint32_t *)(iVar4 + 0x910) = *(uint32_t *)(iVar4 + 0x910) & 0xe007ffff | 0x80000;
            param_1[uVar6 * 0xb + 0xb] = param_1[uVar6 * 0xb + 9];
            /* goto LAB_0800cf9a; */ (void)0;
        }
        *(uint32_t *)(iVar4 + 0x910) =
            *(uint32_t *)(iVar4 + 0x910) & 0xfff80000 | param_4 & 0x7ffff;
        *(uint32_t *)(iVar4 + 0x910) = *(uint32_t *)(iVar4 + 0x910) & 0xe007ffff |
                                       (((param_4 + uVar3) - 1) / uVar3 & 0x3ff) << 0x13;
        if (*(char *)((int)param_1 + uVar6 * 0x2c + 0xf) == '\x01') {
            uVar3 = (*(uint32_t *)(iVar4 + 0x910) & 0x9fffffff) + 0x20000000;
            /* goto LAB_0800cf98; */ (void)0;
        }
    LAB_0800cfa0:
        if ((param_1[uVar6 * 0xb + 9] == 0) ||
            (*(uint32_t *)(iVar2 + 0x834) = *(uint32_t *)(iVar2 + 0x834) | 1 << *pbVar1,
             *(char *)((int)param_1 + uVar6 * 0x2c + 0xf) != '\x01'))
            /* goto LAB_0800cfc4; */ (void)0;
    }
    if ((*(uint32_t *)(iVar2 + 0x808) >> 8 & 1) == 0) {
        uVar3 = *puVar5 | 0x20000000;
    } else {
        uVar3 = *puVar5 | 0x10000000;
    }
    *puVar5 = uVar3;
LAB_0800cfc4:
    *puVar5 = *puVar5 | 0x4000000;
    *puVar5 = *puVar5 | 0x80000000;
    if (*(char *)((int)param_1 + uVar6 * 0x2c + 0xf) != '\x01') {
        return;
    }
    FUN_0800c9da(iVar2, param_1[uVar6 * 0xb + 8], *pbVar1, (short)param_1[uVar6 * 0xb + 9]);
    return;
}

/* ================================================================
 * FUN_0800cff2  @  0x0800CFF2
 */

void FUN_0800cff2(int *param_1)

{
    if (*param_1 == 0x50000000) {
        FUN_0800c8fa(0x50000000, 0x80);
        FUN_0800c900(0x50000000, 0, 0x18);
        FUN_0800c900(0x50000000, 1, 0x14);
        FUN_0800c900(0x50000000, 2, 0x14);
        FUN_0800c900(0x50000000, 3, 0x14);
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800d032  @  0x0800D032
 */

uint32_t FUN_0800d032() {
    int param_1 = 0;
    uint16_t uVar1;
    code *pcVar2;
    uint16_t *puVar3;
    uint16_t uVar4;

    switch (*(uint16_t *)(param_1 + 0x16e) >> 8) {
    default:
        FUN_0800cbca(param_1);
        return 0;
    case 1:
        pcVar2 = (code *)**(uint32_t **)(param_1 + 8);
        break;
    case 2:
        pcVar2 = *(code **)(*(int *)(param_1 + 8) + 8);
        break;
    case 3:
        switch ((char)*(uint16_t *)(param_1 + 0x16e)) {
        case '\0':
            pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x10);
            break;
        case '\x01':
            pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x14);
            break;
        case '\x02':
            pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x18);
            break;
        case '\x03':
            pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x1c);
            break;
        case '\x04':
            pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x24);
            break;
        case '\x05':
            pcVar2 = *(code **)(*(int *)(param_1 + 8) + 0x20);
            break;
        default:
            (**(code **)(*(int *)(param_1 + 4) + 8))(param_1, param_1 + 0x16c);
            return 0;
        }
    }
    puVar3 = (uint16_t *)(*pcVar2)();
    if (((puVar3 != (uint16_t *)0x0) && (uVar1 = *puVar3, uVar1 != 0)) &&
        (uVar4 = *(uint16_t *)(param_1 + 0x172), uVar4 != 0)) {
        if (uVar1 < uVar4) {
            uVar4 = uVar1;
        }
        FUN_0800cba2(param_1, *(uint32_t *)(puVar3 + 2), uVar4);
    }
    return 0;
}

/* ================================================================
 * FUN_0800d0be  @  0x0800D0BE
 */

void FUN_0800d0be(int param_1)

{
    code *UNRECOVERED_JUMPTABLE;

    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x20);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
        /* WARNING: Could not recover jumptable at 0x0800d0c8. Too many branches */
        /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1, 5);
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800d0cc  @  0x0800D0CC
 */

void FUN_0800d0cc(int param_1)

{
    code *UNRECOVERED_JUMPTABLE;

    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x20);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
        /* WARNING: Could not recover jumptable at 0x0800d0d6. Too many branches */
        /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1, 6);
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800d0da  @  0x0800D0DA
 */

void FUN_0800d0da(int *param_1)

{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;

    iVar4 = *param_1;
    uVar3 = 0;
    for (uVar1 = FUN_0800c88c(iVar4); uVar1 != 0; uVar1 = uVar1 >> 1) {
        if ((uVar1 & 1) != 0) {
            uVar2 = FUN_0800c69c(iVar4, uVar3);
            if ((uVar2 & 1) != 0) {
                *(uint32_t *)(iVar4 + 0x834) =
                    *(uint32_t *)(iVar4 + 0x834) & ~(1 << (uVar3 & 0xff));
                FUN_0800c692(iVar4, uVar3, 1);
                FUN_0800ca24(param_1, uVar3 & 0xff);
            }
            if ((int)(uVar2 << 0x1c) < 0) {
                FUN_0800c692(iVar4, uVar3, 8);
            }
            if ((int)(uVar2 << 0x1b) < 0) {
                FUN_0800c692(iVar4, uVar3, 0x10);
            }
            if ((int)(uVar2 << 0x19) < 0) {
                FUN_0800c692(iVar4, uVar3, 0x40);
            }
            if ((int)(uVar2 << 0x1e) < 0) {
                FUN_0800c692(iVar4, uVar3, 2);
            }
            if ((int)(uVar2 << 0x18) < 0) {
                FUN_0800c956(param_1, uVar3);
            }
        }
        uVar3 = uVar3 + 1;
    }
    return;
}

/* ================================================================
 * FUN_0800d170  @  0x0800D170
 */

uint32_t FUN_0800d170(int param_1)

{
    if (*(char *)(param_1 + 0x184) == '\x03') {
        (**(code **)(*(int *)(param_1 + 4) + 8))(param_1);
        if (*(short *)(param_1 + 0x172) == 0) {
            FUN_0800cbba(param_1);
        }
    } else {
        FUN_0800cbca(param_1);
    }
    return 0;
}

/* ================================================================
 * FUN_0800d1a4  @  0x0800D1A4
 */

void FUN_0800d1a4(int *param_1)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    iVar2 = *param_1;
    param_1 = param_1 + 1;
    iVar1 = FUN_0800c8ac(iVar2);
    if ((*(uint32_t *)(iVar2 + 0x14) & 1) == 0) {
        if (iVar1 << 0x1e < 0) {
            FUN_0800c8a8(iVar2, 2);
        }
        if (iVar1 << 0xd < 0) {
            FUN_0800d0da(param_1);
        }
        if (iVar1 << 0xc < 0) {
            FUN_0800d296(param_1);
        }
        if (iVar1 << 0x13 < 0) {
            FUN_0800d318(param_1);
            FUN_0800c8a8(iVar2, 0x1000);
        }
        if (iVar1 << 0x1c < 0) {
            FUN_0800d4f4(param_1);
            FUN_0800c8a8(iVar2, 8);
        }
        if (iVar1 << 0x12 < 0) {
            FUN_0800cdf0(param_1);
            FUN_0800c8a8(iVar2, 0x2000);
        }
        if (iVar1 << 0x1b < 0) {
            FUN_0800d3bc(param_1);
        }
        if (iVar1 << 0xb < 0) {
            FUN_0800d0be(param_1);
            FUN_0800c8a8(iVar2, 0x100000);
        }
        if (iVar1 << 0x1d < 0) {
            uVar3 = *(uint32_t *)(*param_1 + 4);
            if (*(int *)(*param_1 + 4) << 0x1d < 0) {
                FUN_0800cce6(param_1);
            }
            *(uint32_t *)(*param_1 + 4) = uVar3;
            FUN_0800c8a8(iVar2, 4);
        }
        if (iVar1 << 10 < 0) {
            FUN_0800d0cc(param_1);
            FUN_0800c8a8(iVar2, 0x200000);
        }
        if (iVar1 < 0) {
            FUN_0800d536(param_1);
            FUN_0800c8a8(iVar2, 0x80000000);
        }
        if (iVar1 << 0x14 < 0) {
            FUN_0800d500(param_1);
            FUN_0800c8a8(iVar2, 0x800);
            return;
        }
    }
    return;
}

/* ================================================================
 * FUN_0800d296  @  0x0800D296
 */

void FUN_0800d296(int *param_1)

{
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;

    iVar1 = *param_1;
    uVar4 = 0;
    for (uVar2 = FUN_0800c89a(); uVar2 != 0; uVar2 = uVar2 >> 1) {
        if ((uVar2 & 1) != 0) {
            uVar3 = FUN_0800c7dc(iVar1, uVar4);
            if ((uVar3 & 1) != 0) {
                FUN_0800c7d2(iVar1, uVar4, 1);
                FUN_0800cad2(param_1, uVar4 & 0xff);
            }
            if ((int)(uVar3 << 0x1c) < 0) {
                FUN_0800c7d2(iVar1, uVar4, 8);
                FUN_0800cb42(param_1, uVar4 & 0xff);
                if (*(byte *)((int)param_1 + 0x186) != 0) {
                    *(uint32_t *)(*param_1 + 0x800) = *(uint32_t *)(*param_1 + 0x800) & 0xfffff80f |
                                                      (*(byte *)((int)param_1 + 0x186) & 0x7f) << 4;
                    *(uint8_t *)((int)param_1 + 0x186) = 0;
                }
            }
            if ((int)(uVar3 << 0x1b) < 0) {
                FUN_0800c7d2(iVar1, uVar4, 0x10);
            }
        }
        uVar4 = uVar4 + 1;
    }
    return;
}

/* ================================================================
 * FUN_0800d318  @  0x0800D318
 */

void FUN_0800d318(int *param_1)

{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    iVar2 = *param_1;
    uVar3 = 0;
    *(uint32_t *)(iVar2 + 0x804) = *(uint32_t *)(iVar2 + 0x804) & 0xfffffffe;
    FUN_0800cff2(param_1);
    FUN_0800c860(iVar2, 0x10);
    do {
        iVar1 = iVar2 + uVar3 * 0x20;
        *(uint32_t *)(iVar1 + 0x908) = 0xff;
        *(uint32_t *)(iVar1 + 0xb08) = 0xff;
        uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
    *(uint32_t *)(iVar2 + 0x818) = 0xffffffff;
    *(uint32_t *)(iVar2 + 0x81c) = 0x10001;
    *(uint32_t *)(iVar2 + 0x814) = *(uint32_t *)(iVar2 + 0x814) | 1;
    *(uint32_t *)(iVar2 + 0x814) = *(uint32_t *)(iVar2 + 0x814) | 2;
    *(uint32_t *)(iVar2 + 0x814) = *(uint32_t *)(iVar2 + 0x814) | 8;
    *(uint32_t *)(iVar2 + 0x810) = *(uint32_t *)(iVar2 + 0x810) | 1;
    *(uint32_t *)(iVar2 + 0x810) = *(uint32_t *)(iVar2 + 0x810) | 2;
    *(uint32_t *)(iVar2 + 0x810) = *(uint32_t *)(iVar2 + 0x810) | 8;
    FUN_0800c8ec(iVar2, 0);
    FUN_0800c604(iVar2);
    *(uint8_t *)(param_1 + 0x61) = 1;
    if (*(code **)(param_1[1] + 0x20) != (code *)0x0) {
        /* WARNING: Could not recover jumptable at 0x0800d3b6. Too many branches */
        /* WARNING: Treating indirect jump as call */
        (**(code **)(param_1[1] + 0x20))(param_1, 1);
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800d3bc  @  0x0800D3BC
 */

void FUN_0800d3bc(int *param_1)

{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;

    iVar4 = *param_1;
    FUN_0800c8b4(iVar4, 0x10, 0);
    uVar1 = *(uint32_t *)(iVar4 + 0x20);
    uVar3 = (uVar1 & 0x7fff) >> 4;
    uVar2 = (uVar1 & 0x1fffff) >> 0x11;
    uVar1 = uVar1 & 0xf;
    if (uVar2 == 2) {
        if (uVar3 == 0)
            /* goto LAB_0800d41a; */ (void)0;
        FUN_0800c8d2(iVar4, param_1[uVar1 * 0xb + 0x34], uVar1, uVar3);
        param_1[uVar1 * 0xb + 0x34] = param_1[uVar1 * 0xb + 0x34] + uVar3;
    } else {
        if (uVar2 != 6)
            /* goto LAB_0800d41a; */ (void)0;
        FUN_0800c8d2(iVar4, param_1 + 0x5d, uVar1, uVar3);
    }
    param_1[uVar1 * 0xb + 0x36] = param_1[uVar1 * 0xb + 0x36] + uVar3;
LAB_0800d41a:
    FUN_0800c8b4(iVar4, 0x10, 1);
    return;
}

/* ================================================================
 * FUN_0800d428  @  0x0800D428
 */

uint32_t FUN_0800d428() {
    int param_1 = 0;
    char cVar1;
    char *pcVar2;
    code *pcVar3;

    pcVar2 = DAT_0800d49c;
    cVar1 = *(char *)(param_1 + 0x16e);
    *DAT_0800d49c = cVar1;
    if ((*(short *)(param_1 + 0x170) == 0) && (*(short *)(param_1 + 0x172) == 0)) {
        if (*(char *)(param_1 + 0x184) == '\x02') {
            if (cVar1 != '\0') {
                *(char *)(param_1 + 0x189) = cVar1;
                *(uint8_t *)(param_1 + 0x184) = 3;
            LAB_0800d47c:
                pcVar3 = (code *)**(uint32_t **)(param_1 + 4);
            LAB_0800d490:
                (*pcVar3)(param_1);
            }
        } else {
            if (*(char *)(param_1 + 0x184) != '\x03')
                /* goto LAB_0800d44c; */ (void)0;
            if (cVar1 == '\0') {
                *(uint8_t *)(param_1 + 0x184) = 2;
                *(uint8_t *)(param_1 + 0x189) = 0;
                pcVar3 = *(code **)(*(int *)(param_1 + 4) + 4);
                /* goto LAB_0800d490; */ (void)0;
            }
            if (*(char *)(param_1 + 0x189) == cVar1) {
                (**(code **)(*(int *)(param_1 + 4) + 4))(param_1);
                *(char *)(param_1 + 0x189) = *pcVar2;
                /* goto LAB_0800d47c; */ (void)0;
            }
        }
        FUN_0800cbba(param_1);
    } else {
    LAB_0800d44c:
        FUN_0800cbca(param_1);
    }
    return 0;
}

/* ================================================================
 * FUN_0800d4a0  @  0x0800D4A0
 */

void FUN_0800d4a0(uint32_t *param_1, uint32_t param_2)

{
    int iVar1;

    if ((int)(param_2 << 0x18) < 0) {
        iVar1 = (param_2 & 0x7f) * 0xb + 3;
    } else {
        iVar1 = (param_2 & 0x7f) * 0xb + 0x2f;
    }
    FUN_0800c7ec(*param_1, param_1 + iVar1);
    *(uint8_t *)((int)(param_1 + iVar1) + 0xd) = 1;
    return;
}

/* ================================================================
 * sys_settings_struct_copy  @  0x0800D4CC
 * nearby string: "write_flash_err
\n"
 */

void sys_settings_struct_copy(uint8_t *param_1, uint8_t *param_2)

{
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    *(uint16_t *)(param_1 + 2) = (uint16_t)(byte)param_2[2] + (uint16_t)(byte)param_2[3] * 0x100;
    *(uint16_t *)(param_1 + 4) = (uint16_t)(byte)param_2[4] + (uint16_t)(byte)param_2[5] * 0x100;
    *(uint16_t *)(param_1 + 6) = (uint16_t)(byte)param_2[6] + (uint16_t)(byte)param_2[7] * 0x100;
    return;
}

/* ================================================================
 * FUN_0800d4f4  @  0x0800D4F4
 * nearby string: "write_flash_err
\n"
 */

void FUN_0800d4f4(int param_1)

{
    code *UNRECOVERED_JUMPTABLE;

    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x1c);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
        /* WARNING: Could not recover jumptable at 0x0800d4fc. Too many branches */
        /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)();
        return;
    }
    return;
}

/* ================================================================
 * FUN_0800d500  @  0x0800D500
 * nearby string: "write_flash_err
\n"
 */

void FUN_0800d500(int *param_1)

{
    if ((*(uint32_t *)(*param_1 + 0x808) & 1) != 0) {
        *(char *)((int)param_1 + 0x185) = (char)param_1[0x61];
        *(uint8_t *)(param_1 + 0x61) = 4;
        FUN_0800cdd6(param_1);
        if (*(code **)(param_1[1] + 0x20) != (code *)0x0) {
            /* WARNING: Could not recover jumptable at 0x0800d532. Too many branches */
            /* WARNING: Treating indirect jump as call */
            (**(code **)(param_1[1] + 0x20))(param_1, 2);
            return;
        }
    }
    return;
}

/* ================================================================
 * FUN_0800d536  @  0x0800D536
 * nearby string: "write_flash_err
\n"
 */

void FUN_0800d536(int *param_1)

{
    *(uint32_t *)(*param_1 + 0x804) = *(uint32_t *)(*param_1 + 0x804) & 0xfffffffe;
    FUN_0800c8c4(*param_1);
    *(uint8_t *)(param_1 + 0x61) = *(uint8_t *)((int)param_1 + 0x185);
    if (*(code **)(param_1[1] + 0x20) != (code *)0x0) {
        /* WARNING: Could not recover jumptable at 0x0800d566. Too many branches */
        /* WARNING: Treating indirect jump as call */
        (**(code **)(param_1[1] + 0x20))(param_1, 3);
        return;
    }
    return;
}

/* ================================================================
 * sys_settings_load  @  0x0800D56C
 * nearby string: "write_flash_err
\n"
 */

void sys_settings_load(void)

{
    short *psVar1;
    int iVar2;

    sys_usb_detect_init();
    psVar1 = DAT_0800d5a0;
    if (*DAT_0800d5a0 != 0) {
        display_state_reset();
    }
    iVar2 = DAT_0800d5a4;
    *(char *)(DAT_0800d5a4 + 0x20) = (char)psVar1[1];
    *(char *)(iVar2 + 0x21) = (char)psVar1[4];
    *(char *)(iVar2 + 0x22) = (char)psVar1[2];
    *(char *)(iVar2 + 0x23) = (char)psVar1[3];
    *(char *)(iVar2 + 0x24) = (char)psVar1[5];
    *(char *)(iVar2 + 0x25) = (char)psVar1[6];
    *(char *)(iVar2 + 0x26) = (char)psVar1[7];
    return;
}

/* ================================================================
 * fs_find_open_handle  @  0x0800D5A8
 * nearby string: "write_flash_err
\n"
 */

uint32_t fs_find_open_handle(uint32_t *param_1, uint32_t *param_2)

{
    char *pcVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;

    uVar4 = 9;
    if (((param_1 != (uint32_t *)0x0) && (pcVar1 = (char *)*param_1, pcVar1 != (char *)0x0)) &&
        (*pcVar1 != '\0')) {
        if ((*(short *)(param_1 + 1) == *(short *)(pcVar1 + 6)) &&
            (uVar2 = fs_fat32_is_writable(pcVar1[1]), (uVar2 & 1) == 0)) {
            uVar4 = 0;
            uVar3 = *param_1;
            /* goto LAB_0800d5d0; */ (void)0;
        }
    }
    uVar3 = 0;
LAB_0800d5d0:
    *param_2 = uVar3;
    return uVar4;
}

/* ================================================================
 * fs_fat32_reset_dir_state  @  0x0800D5DC
 * nearby string: "write_flash_err
\n"
 */

void fs_fat32_reset_dir_state(void)

{
    *(uint16_t *)(DAT_0800d5f0 + 0xc) = 0;
    *(uint16_t *)(DAT_0800d5f4 + 2) = 0;
    FUN_080006e8(DAT_0800d5f8, 0x4f0);
    return;
}

/* ================================================================
 * sys_record_history_sample  @  0x0800D5FC
 * nearby string: "write_flash_err
\n"
 */

void sys_record_history_sample(uint32_t param_1, uint32_t param_2)

{
    char cVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint64_t uVar5;

    uVar5 = CONCAT44(param_2, param_1);
    uVar4 = *(uint32_t *)(DAT_0800d664 + 8);
    switch (param_1) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 7:
    case 10:
    case 0xb:
    switchD_0800d606_caseD_0:
        break;
    case 2:
    case 5:
    case 6:
        cVar1 = *(char *)(DAT_0800d664 + 0xd);
        uVar3 = DAT_0800d674;
        if ((((cVar1 != '\b') && (cVar1 != '\v')) && (cVar1 != '\x0e')) &&
            (((uVar3 = DAT_0800d668, cVar1 != '\t' && (cVar1 != '\f')) && (cVar1 != '\x0f'))))
            goto switchD_0800d606_caseD_0;
        uVar4 = FUN_0800e8c4(uVar4, uVar3);
        break;
    default:
        goto switchD_0800d606_caseD_8;
    }
    uVar5 = FUN_0800e548(uVar4);
switchD_0800d606_caseD_8:
    iVar2 = DAT_0800d670;
    *(uint64_t *)(DAT_0800d66c + (uint32_t)*(uint16_t *)(DAT_0800d670 + 2) * 8) = uVar5;
    *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + 1;
    if (0x9d < *(uint16_t *)(iVar2 + 2)) {
        *(uint16_t *)(iVar2 + 2) = 0;
    }
    return;
}

/* ================================================================
 * sys_write_settings_to_flash  @  0x0800D678
 * nearby string: "write_flash_err
\n"
 */

void sys_write_settings_to_flash(void)

{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    char *pcVar4;

    uVar1 = DAT_0800d6bc;
    iVar2 = FUN_080086e0(DAT_0800d6bc, DAT_0800d6b8, 0x46);
    FUN_080082fc(uVar1, DAT_0800d6b8 + 0x8c, 0x46);
    iVar3 = FUN_08002400(DAT_0800d6b8, DAT_0800d6b8 + 0x8c, 0x46);
    if ((iVar3 == 1) && (iVar2 == 1)) {
        pcVar4 = s_write_flash_ok_0800d6d4;
    } else {
        pcVar4 = s_write_flash_err_0800d6c0;
    }
    display_debug_printf(pcVar4);
    return;
}

/* ================================================================
 * FUN_0800d6e8  @  0x0800D6E8
 */

int FUN_0800d6e8(byte *param_1, int param_2, byte *param_3, uint32_t *param_4)

{
    byte bVar1;
    int *piVar2;
    byte bVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t *puVar6;
    char cVar7;
    int iVar8;
    byte *pbVar9;
    byte *pbVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    byte *pbVar13;
    uint32_t uVar14;
    uint32_t uVar15;
    uint32_t uVar16;
    bool bVar17;
    char cVar18;
    uint64_t uVar19;
    uint64_t uVar20;
    uint32_t local_70;
    uint32_t local_60;
    uint32_t local_5c;
    uint32_t local_58;
    uint32_t *local_28;

    local_70 = 0;
    uVar19 = 0;
    pbVar13 = (byte *)0x0;
    bVar1 = 0;
    *DAT_0800dabc = (int)param_1;
    local_28 = param_4;
LAB_0800d704:
    do {
        uVar15 = 0;
        local_58 = 0;
        pbVar10 = param_3 + 1;
        bVar3 = *param_3;
        uVar14 = 0;
        uVar12 = 6;
        if (bVar3 == 0) {
            pbVar10 = param_1 + 1;
            *param_1 = 0;
            /* goto LAB_0800daa2; */ (void)0;
        }
        if (bVar3 == 0x25) {
            param_3 = param_3 + 2;
            bVar3 = *pbVar10;
            uVar11 = (uint32_t)bVar3;
            if (uVar11 != 0x25) {
                if (uVar11 == 0x30) {
                    uVar15 = 1;
                    /* goto LAB_0800d744; */ (void)0;
                }
                pbVar10 = param_3;
                if (uVar11 == 0x2d) {
                    uVar15 = 2;
                    /* goto LAB_0800d744; */ (void)0;
                }
                while (uVar11 - 0x30 < 10) {
                    uVar14 = (uVar11 + uVar14 * 10) - 0x30 & 0xff;
                    param_3 = pbVar10;
                LAB_0800d744:
                    pbVar10 = param_3 + 1;
                    uVar11 = (uint32_t)*param_3;
                }
                if (uVar11 == 0x2e) {
                    uVar12 = 0;
                    pbVar9 = pbVar10;
                    while (true) {
                        pbVar10 = pbVar9 + 1;
                        uVar11 = (uint32_t)*pbVar9;
                        if (9 < uVar11 - 0x30)
                            break;
                        uVar12 = (uVar11 + uVar12 * 10) - 0x30 & 0xff;
                        pbVar9 = pbVar10;
                    }
                }
                param_3 = pbVar10;
                if (uVar11 == 0x6c) {
                    param_3 = pbVar10 + 1;
                    uVar11 = (uint32_t)*pbVar10;
                    uVar15 = uVar15 | 4;
                }
                bVar3 = (byte)uVar11;
                pbVar10 = param_1;
                if (uVar11 == 0)
                    /* goto LAB_0800daa2; */ (void)0;
                if (uVar11 == 0x66) {
                    cVar18 = (uint32_t *)0xfffffff8 < local_28;
                    puVar6 = (uint32_t *)((uint32_t)((int)local_28 + 7) & 0xfffffff8);
                    local_28 = puVar6 + 2;
                    uVar16 = *puVar6;
                    local_5c = puVar6[1];
                    FUN_0800e07c(uVar16, local_5c, 0, 0);
                    if (cVar18 == '\0') {
                        local_5c = local_5c ^ 0x80000000;
                        uVar15 = uVar15 | 0x80;
                    }
                    uVar19 = CONCAT44(local_5c, uVar16);
                    local_58 = (uint32_t)(cVar18 == '\0');
                    if (uVar12 != 0) {
                        local_58 = local_58 + 1;
                    }
                    local_70 = FUN_0800dfcc(uVar16, local_5c);
                    cVar18 = sys_decimal_digit_count();
                    bVar3 = cVar18 + (char)uVar12;
                LAB_0800d838:
                    uVar5 = (uint32_t)bVar3;
                } else {
                    if (0x66 < uVar11) {
                        if (uVar11 != 0x73) {
                            if ((uVar11 != 0x75) && (uVar11 != 0x78))
                                /* goto LAB_0800d7b2; */ (void)0;
                            /* goto LAB_0800d826; */ (void)0;
                        }
                        pbVar13 = (byte *)*local_28;
                        bVar3 = sys_strlen(pbVar13);
                        local_28 = local_28 + 1;
                        /* goto LAB_0800d838; */ (void)0;
                    }
                    if (uVar11 == 0x58) {
                    LAB_0800d826:
                        local_70 = *local_28;
                        if (uVar11 == 0x75)
                            /* goto LAB_0800d820; */ (void)0;
                        bVar3 = sys_hex_digit_count(local_70);
                        local_28 = local_28 + 1;
                        /* goto LAB_0800d838; */ (void)0;
                    }
                    if (uVar11 != 99) {
                        if (uVar11 != 100)
                            /* goto LAB_0800d7b2; */ (void)0;
                        local_70 = *local_28;
                        bVar17 = (int)local_70 < 0;
                        if (bVar17) {
                            local_70 = -local_70;
                            uVar15 = uVar15 | 0x80;
                        }
                        local_58 = (uint32_t)bVar17;
                    LAB_0800d820:
                        local_28 = local_28 + 1;
                        bVar3 = sys_decimal_digit_count(local_70);
                        /* goto LAB_0800d838; */ (void)0;
                    }
                    bVar1 = (byte)*local_28;
                    uVar5 = 1;
                    local_28 = local_28 + 1;
                }
                local_5c = (uint32_t)((uint64_t)uVar19 >> 0x20);
                local_60 = (uint32_t)uVar19;
                if ((-1 < (int)(uVar15 << 0x1e)) && (uVar5 + local_58 < uVar14)) {
                    iVar8 = *DAT_0800dabc;
                    for (uVar4 = 0; (int)uVar4 < (int)(uVar14 - (uVar5 + local_58));
                         uVar4 = uVar4 + 1 & 0xffff) {
                        if ((uVar15 & 1) == 0) {
                            bVar3 = 0x20;
                        } else {
                            bVar3 = 0x30;
                        }
                        pbVar10 = param_1 + 1;
                        *param_1 = bVar3;
                        if (((byte *)(iVar8 + param_2) <= pbVar10) && (param_2 != 0))
                            /* goto LAB_0800daa2; */ (void)0;
                        param_1 = pbVar10;
                    }
                }
                pbVar10 = param_1;
                if (uVar11 == 0x66) {
                    if ((int)(uVar15 << 0x18) < 0) {
                        pbVar10 = param_1 + 1;
                        *param_1 = 0x2d;
                        if (((byte *)(*DAT_0800dabc + param_2) <= pbVar10) && (param_2 != 0))
                            /* goto LAB_0800daa2; */ (void)0;
                    }
                    local_70 = FUN_0800dfcc(local_60, local_5c);
                    uVar11 = uVar5 - uVar12;
                    param_1 = pbVar10;
                    while ((uVar11 & 0xffff) != 0) {
                        uVar11 = (uVar11 & 0xffff) - 1;
                        bVar3 = sys_get_decimal_digit(local_70, uVar11 & 0xff);
                        pbVar10 = param_1 + 1;
                        *param_1 = bVar3;
                        param_1 = pbVar10;
                        if (((byte *)(*DAT_0800dabc + param_2) <= pbVar10) && (param_2 != 0))
                            /* goto LAB_0800daa2; */ (void)0;
                    }
                    if (uVar12 != 0) {
                        *param_1 = 0x2e;
                        uVar19 = FUN_0800e054(local_70);
                        uVar19 = FUN_0800e35c((int)uVar19, (int)((uint64_t)uVar19 >> 0x20),
                                              local_60, local_5c);
                        sys_pow_int(10, uVar12);
                        uVar20 = FUN_0800e026();
                        uVar19 = FUN_0800e0f4((int)uVar20, (int)((uint64_t)uVar20 >> 0x20),
                                              (int)uVar19, (int)((uint64_t)uVar19 >> 0x20));
                        uVar19 = FUN_0800dba4((int)uVar19, (int)((uint64_t)uVar19 >> 0x20), 0,
                                              DAT_0800dac0);
                        local_70 = FUN_0800dfcc();
                        piVar2 = DAT_0800dabc;
                        pbVar9 = param_1 + 1;
                        do {
                            bVar3 = sys_get_decimal_digit(local_70, uVar12 - 1 & 0xff);
                            pbVar10 = pbVar9 + 1;
                            *pbVar9 = bVar3;
                            if (((byte *)(*piVar2 + param_2) <= pbVar10) && (param_2 != 0))
                                /* goto LAB_0800daa2; */ (void)0;
                            uVar12 = uVar12 - 1 & 0xffff;
                            param_1 = pbVar10;
                            pbVar9 = pbVar10;
                        } while (uVar12 != 0);
                    }
                } else {
                    uVar12 = uVar5;
                    if (uVar11 < 0x67) {
                        if (uVar11 == 0x58) {
                        LAB_0800d9b0:
                            for (; uVar12 != 0; uVar12 = uVar12 - 1 & 0xffff) {
                                uVar4 = uVar12 - 1 & 0xff;
                                if (uVar11 == 0x78) {
                                    uVar4 = sys_pow_int(0x10, uVar4);
                                    uVar4 = local_70 / uVar4 & 0xf;
                                    cVar18 = (char)uVar4;
                                    if (uVar4 < 10)
                                        /* goto LAB_0800d992; */ (void)0;
                                    cVar7 = 'W';
                                } else {
                                    uVar4 = sys_pow_int(0x10, uVar4);
                                    uVar4 = local_70 / uVar4 & 0xf;
                                    cVar18 = (char)uVar4;
                                    if (uVar4 < 10) {
                                    LAB_0800d992:
                                        cVar7 = '0';
                                    } else {
                                        cVar7 = '7';
                                    }
                                }
                                pbVar10 = param_1 + 1;
                                *param_1 = cVar18 + cVar7;
                                if (((byte *)(*DAT_0800dabc + param_2) <= pbVar10) &&
                                    (param_2 != 0))
                                    /* goto LAB_0800daa2; */ (void)0;
                                param_1 = pbVar10;
                            }
                        } else if (uVar11 == 99) {
                            pbVar10 = param_1 + 1;
                            *param_1 = bVar1;
                            param_1 = pbVar10;
                            if (((byte *)(*DAT_0800dabc + param_2) <= pbVar10) && (param_2 != 0))
                                /* goto LAB_0800daa2; */ (void)0;
                        } else if (uVar11 == 100)
                            /* goto LAB_0800d906; */ (void)0;
                    } else if (uVar11 == 0x73) {
                        iVar8 = *DAT_0800dabc;
                        for (; param_1 = pbVar10, *pbVar13 != 0; pbVar13 = pbVar13 + 1) {
                            if (((byte *)(iVar8 + param_2) <= pbVar10) && (param_2 != 0))
                                /* goto LAB_0800daa2; */ (void)0;
                            *pbVar10 = *pbVar13;
                            pbVar10 = pbVar10 + 1;
                        }
                    } else if (uVar11 == 0x75) {
                    LAB_0800d906:
                        piVar2 = DAT_0800dabc;
                        if ((int)(uVar15 << 0x18) < 0) {
                            pbVar10 = param_1 + 1;
                            *param_1 = 0x2d;
                            param_1 = pbVar10;
                            piVar2 = DAT_0800dabc;
                            if (((byte *)(*DAT_0800dabc + param_2) <= pbVar10) && (param_2 != 0))
                                /* goto LAB_0800daa2; */ (void)0;
                        }
                        for (; uVar12 != 0; uVar12 = uVar12 - 1 & 0xffff) {
                            bVar3 = sys_get_decimal_digit(local_70, uVar12 - 1 & 0xff);
                            pbVar10 = param_1 + 1;
                            *param_1 = bVar3;
                            if (((byte *)(*piVar2 + param_2) <= pbVar10) && (param_2 != 0))
                                /* goto LAB_0800daa2; */ (void)0;
                            param_1 = pbVar10;
                        }
                    } else if (uVar11 == 0x78)
                        /* goto LAB_0800d9b0; */ (void)0;
                }
                if (((int)(uVar15 << 0x1e) < 0) && (local_58 + uVar5 < uVar14)) {
                    iVar8 = *DAT_0800dabc;
                    for (uVar15 = 0; (int)uVar15 < (int)(uVar14 - (local_58 + uVar5));
                         uVar15 = uVar15 + 1 & 0xffff) {
                        pbVar10 = param_1 + 1;
                        *param_1 = 0x20;
                        if (((byte *)(iVar8 + param_2) <= pbVar10) && (param_2 != 0))
                            /* goto LAB_0800daa2; */ (void)0;
                        param_1 = pbVar10;
                    }
                }
                /* goto LAB_0800d704; */ (void)0;
            }
        LAB_0800d7b2:
            *param_1 = bVar3;
        } else {
            *param_1 = bVar3;
            param_3 = pbVar10;
        }
        pbVar10 = param_1 + 1;
        param_1 = pbVar10;
        if (((byte *)(*DAT_0800dabc + param_2) <= pbVar10) && (param_2 != 0)) {
        LAB_0800daa2:
            return (int)pbVar10 - *DAT_0800dabc;
        }
    } while (true);
}

/* ================================================================
 * sys_hex_digit_count  @  0x0800DAC4
 */

int sys_hex_digit_count(uint32_t param_1)

{
    int iVar1;

    iVar1 = 1;
    for (; 0xf < param_1; param_1 = param_1 >> 4) {
        iVar1 = iVar1 + 1;
    }
    return iVar1;
}

/* ================================================================
 * sys_pow_int  @  0x0800DAD4
 */

int sys_pow_int() {
    int param_1 = 0;
    int param_2 = 0;
    int iVar1;
    bool bVar2;

    iVar1 = 1;
    while (bVar2 = param_2 != 0, param_2 = param_2 + -1, bVar2) {
        iVar1 = param_1 * iVar1;
    }
    return iVar1;
}

/* ================================================================
 * sys_strlen  @  0x0800DAE2
 */

int sys_strlen(char *param_1)

{
    int iVar1;

    iVar1 = 0;
    while (*param_1 != '\0') {
        iVar1 = iVar1 + 1;
        param_1 = param_1 + 1;
    }
    return iVar1;
}

/* ================================================================
 * sys_sprintf  @  0x0800DAF4
 */

void sys_sprintf() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uStack_8;
    uint32_t uStack_4;

    uStack_8 = param_3;
    uStack_4 = param_4;
    FUN_0800d6e8(param_1, 0, param_2, &uStack_8);
    return;
}

/* ================================================================
 * sys_get_decimal_digit  @  0x0800DB08
 */

int sys_get_decimal_digit() {
    uint32_t param_1 = 0;
    uint32_t uVar1;

    uVar1 = sys_pow_int(10);
    return (param_1 / uVar1) % 10 + 0x30;
}

/* ================================================================
 * sys_decimal_digit_count  @  0x0800DB28
 */

int sys_decimal_digit_count() {
    uint32_t param_1 = 0;
    int iVar1;

    iVar1 = 1;
    for (; 9 < param_1; param_1 = param_1 / 10) {
        iVar1 = iVar1 + 1;
    }
    return iVar1;
}

/* ================================================================
 * FUN_0800db40  @  0x0800DB40
 */

uint32_t FUN_0800db40() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t extraout_r1;
    uint32_t uVar1;
    bool bVar2;

    uVar1 = (param_2 & 0x7fffffff) + 0xc8000000;
    bVar2 = uVar1 == 0x100000;
    if (0xfffff < uVar1) {
        bVar2 = uVar1 == 0xff00000;
    }
    if ((0xfffff >= uVar1 || 0xff00000 < uVar1) || bVar2) {
        if (0xfffff < (int)uVar1) {
            if (0xffdfffff < param_2 << 1) {
                FUN_0800e248(param_1);
                param_2 = extraout_r1;
            }
            return (param_2 >> 0x17 | 0xff) << 0x17;
        }
        return param_2 & 0x80000000;
    }
    bVar2 = (param_1 & 0x10000000) != 0;
    uVar1 = (param_2 & 0x80000000 | uVar1 * 8) + (param_1 >> 0x1d) + (uint32_t)bVar2;
    if ((param_1 & 0xfffffff) == 0) {
        if (bVar2) {
            uVar1 = uVar1 & 0xfffffffe;
        }
        return uVar1;
    }
    return uVar1;
}

/* ================================================================
 * FUN_0800dba4  @  0x0800DBA4
 */

/* WARNING: Control flow encountered bad instruction data */

uint64_t FUN_0800dba4(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    bool bVar11;
    bool bVar12;
    byte bVar13;

    if ((int)(param_2 ^ param_4) < 0) {
        param_4 = param_4 ^ 0x80000000;
        bVar11 = param_3 <= param_1;
        uVar6 = param_1 - param_3;
        if (param_2 <= param_4 && (uint32_t)bVar11 <= param_2 - param_4) {
            bVar12 = CARRY4(param_3, uVar6);
            param_3 = param_3 + uVar6;
            uVar7 = (param_2 - param_4) - (uint32_t)!bVar11 ^ 0x80000000;
            param_4 = param_4 + uVar7 + bVar12;
            bVar11 = param_1 < uVar6;
            param_1 = param_1 - uVar6;
            param_2 = (param_2 - uVar7) - (uint32_t)bVar11;
        }
        uVar7 = param_2 >> 0x14;
        uVar6 = uVar7 - (param_4 >> 0x14);
        if ((DAT_0800e544 & param_4 << 1) == 0 || DAT_0800e544 == uVar7 << 0x15) {
            if (DAT_0800e544 != uVar7 << 0x15) {
                if ((param_2 & DAT_0800e544 >> 1) == 0) {
                    param_2 = 0;
                    param_1 = 0;
                }
                return CONCAT44(param_2, param_1);
            }
            FUN_0800e248();
            do {
                software_interrupt(0x40);
            } while (true);
        }
        uVar5 = -param_3;
        uVar1 = param_2 & ~(uVar7 << 0x14);
        iVar8 = ((int)DAT_0800e544 >> 1) - (param_4 & ~((int)DAT_0800e544 >> 1));
        if (param_3 != 0) {
            iVar8 = iVar8 + -1;
        }
        if (uVar6 < 0x21) {
            uVar2 = uVar5 >> (uVar6 & 0xff);
            uVar9 = param_1 + uVar2;
            uVar1 = uVar1 + (iVar8 >> (uVar6 & 0xff)) + (uint32_t)CARRY4(param_1, uVar2);
            uVar10 = iVar8 << (0x20 - uVar6 & 0xff);
            uVar2 = uVar9 + uVar10;
            bVar11 = CARRY4(uVar1, (uint32_t)CARRY4(uVar9, uVar10));
            iVar8 = uVar1 + CARRY4(uVar9, uVar10);
            uVar6 = 0x20 - uVar6;
        } else {
            uVar5 =
                (uint32_t)(param_3 * -2 != 0) | (iVar8 * 2 + (uint32_t)CARRY4(uVar5, uVar5)) * 2;
            uVar6 = uVar6 - 0x20;
            if (0x1d < uVar6) {
                return CONCAT44(uVar1 + uVar7 * 0x100000, param_1);
            }
            uVar9 = iVar8 >> (uVar6 & 0xff);
            uVar2 = param_1 + uVar9;
            bVar11 = uVar1 != 0 || CARRY4(uVar1 - 1, (uint32_t)CARRY4(param_1, uVar9));
            iVar8 = (uVar1 - 1) + (uint32_t)CARRY4(param_1, uVar9);
            uVar6 = 0x1e - uVar6;
        }
        if (-1 < iVar8) {
            iVar4 = uVar5 << (uVar6 & 0xff);
            iVar8 = iVar8 + uVar7 * 0x100000;
            if (-1 < iVar4) {
                return CONCAT44(iVar8, uVar2);
            }
            uVar2 = uVar2 + 1;
            if (uVar2 != 0 && iVar4 != -0x80000000) {
                return CONCAT44(iVar8, uVar2);
            }
            if (uVar2 == 0) {
                iVar8 = iVar8 + 1;
                uVar2 = 0;
            } else {
                uVar2 = uVar2 & 0xfffffffe;
            }
            return CONCAT44(iVar8, uVar2);
        }
        uVar1 = uVar6 + 1 & 0xff;
        bVar11 = uVar1 == 0 && bVar11 || uVar1 != 0 && (uVar5 << uVar1 - 1 & 0x80000000) != 0;
        uVar9 = uVar2 * 2 + (uint32_t)bVar11;
        uVar6 = iVar8 * 2 + (uint32_t)(CARRY4(uVar2, uVar2) || CARRY4(uVar2 * 2, (uint32_t)bVar11));
        uVar2 = uVar6 + uVar7 * 0x200000;
        bVar11 = (uVar2 >> 0x14 & 1) != 0;
        if (bVar11 && uVar2 >> 0x15 != 0) {
            uVar2 = -((int)(uVar5 << uVar1) >> 0x1f);
            uVar10 = uVar9 + uVar2;
            bVar11 = uVar10 == 0;
            iVar8 = uVar6 + uVar7 * 0x100000;
            if (!CARRY4(uVar9, uVar2)) {
                bVar11 = uVar5 << uVar1 == -0x80000000;
            }
            if (!bVar11) {
                return CONCAT44(iVar8, uVar10);
            }
            if (uVar10 == 0) {
                iVar8 = iVar8 + 1;
                uVar10 = 0;
            } else {
                uVar10 = uVar10 & 0xfffffffe;
            }
            return CONCAT44(iVar8, uVar10);
        }
        if (!bVar11) {
            iVar8 = uVar6 + 0x200000;
            if (iVar8 == 0) {
                uVar6 = uVar9 << LZCOUNT(uVar9);
                if (uVar6 == 0) {
                    return (uint64_t)uVar9;
                }
                iVar4 = ((uVar7 & 0xfffff7ff) - LZCOUNT(uVar9)) + -0x17;
                iVar8 = uVar6 << 0x15;
                uVar6 = uVar6 >> 0xb;
            } else {
                uVar5 = LZCOUNT(iVar8) - 0xb;
                iVar4 = ((uVar7 & 0xfffff7ff) - uVar5) + -2;
                uVar6 = iVar8 << (uVar5 & 0xff) | uVar9 >> (0x20 - uVar5 & 0xff);
                iVar8 = uVar9 << (uVar5 & 0xff);
            }
            iVar3 = uVar6 + (param_2 & 0x80000000) + iVar4 * 0x100000;
            if (-1 < iVar4) {
                return CONCAT44(iVar3, iVar8);
            }
            return (uint64_t)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
        }
        uVar7 = ((int)uVar6 >> 1) + uVar7 * 0x100000;
        uVar6 = (uint32_t)((uVar6 & 1) != 0) << 0x1f | uVar9 >> 1;
        if (uVar7 * 2 == 0 && uVar6 == 0) {
            return (uint64_t)uVar6;
        }
        if (0x1fffff < uVar7 * 2) {
            return CONCAT44(uVar7, uVar6);
        }
        return (uint64_t)(uVar7 & 0x80000000) << 0x20;
    }
    uVar6 = param_1 - param_3;
    iVar8 = (param_2 - param_4) - (uint32_t)(param_3 > param_1);
    if (param_2 <= param_4 && (uint32_t)(param_3 <= param_1) <= param_2 - param_4) {
        bVar11 = CARRY4(param_3, uVar6);
        param_3 = param_3 + uVar6;
        param_4 = param_4 + iVar8 + (uint32_t)bVar11;
        bVar11 = param_1 < uVar6;
        param_1 = param_1 - uVar6;
        param_2 = (param_2 - iVar8) - (uint32_t)bVar11;
    }
    uVar7 = param_2 >> 0x14;
    uVar6 = uVar7 - (param_4 >> 0x14);
    if ((DAT_0800dcf0 & param_4 << 1) == 0 || DAT_0800dcf0 == uVar7 << 0x15) {
        if (DAT_0800dcf0 != uVar7 << 0x15) {
            if ((param_2 & DAT_0800dcf0 >> 1) == 0) {
                param_2 = param_2 & 0x80000000;
                param_1 = 0;
            }
            return CONCAT44(param_2, param_1);
        }
        FUN_0800e248();
        /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
    }
    param_2 = param_2 & ~(uVar7 << 0x14);
    uVar5 = param_4 & ~DAT_0800dcf0 | 0x100000;
    if (uVar6 < 0x21) {
        uVar9 = param_3 >> (uVar6 & 0xff);
        uVar1 = param_1 + uVar9;
        uVar10 = uVar5 << (0x20 - uVar6 & 0xff);
        uVar2 = uVar1 + uVar10;
        param_2 = param_2 + (uVar5 >> (uVar6 & 0xff)) + (uint32_t)CARRY4(param_1, uVar9) +
                  (uint32_t)CARRY4(uVar1, uVar10);
        uVar6 = 0x20 - uVar6;
        if (param_2 < 0x100000) {
            param_2 = param_2 + uVar7 * 0x100000;
            /* goto LAB_0800dc20; */ (void)0;
        }
    LAB_0800dc82:
        bVar13 = (byte)uVar2 & 1;
        uVar5 = (uint32_t)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar2 >> 1;
        param_2 = (param_2 + 0x100000 >> 1) + uVar7 * 0x100000;
        if ((uVar2 & 1) == 0) {
        LAB_0800dcb0:
            if (param_2 * 2 < 0xffe00000) {
                return CONCAT44(param_2, uVar5);
            }
            /* goto LAB_0800e2e4; */ (void)0;
        }
        bVar11 = CARRY4(uVar5, (uint32_t)bVar13);
        uVar5 = uVar5 + bVar13;
        uVar7 = uVar5;
        if (!bVar11) {
            uVar7 = param_3 << (uVar6 & 0xff);
        }
        if (uVar7 != 0)
            /* goto LAB_0800dcb0; */ (void)0;
    } else {
        param_3 = uVar5 * 2 + (uint32_t)(param_3 != 0);
        uVar1 = uVar6 - 0x20;
        uVar6 = 0x1f - uVar1;
        if (uVar1 < 0x20) {
            uVar5 = uVar5 >> (uVar1 & 0xff);
            uVar2 = param_1 + uVar5;
        } else {
            uVar6 = 0;
            uVar2 = param_1;
        }
        param_2 = param_2 + uVar7 * 0x100000 + (uint32_t)(uVar1 < 0x20 && CARRY4(param_1, uVar5));
        if (uVar7 != param_2 >> 0x14) {
            param_2 = param_2 + uVar7 * -0x100000;
            /* goto LAB_0800dc82; */ (void)0;
        }
    LAB_0800dc20:
        param_3 = param_3 << (uVar6 & 0xff);
        if (-1 < (int)param_3) {
            return CONCAT44(param_2, uVar2);
        }
        uVar5 = uVar2 + 1;
        uVar6 = uVar5;
        if (uVar2 != 0xffffffff) {
            uVar6 = param_3 & 0x7fffffff;
        }
        if (uVar6 != 0) {
            return CONCAT44(param_2, uVar5);
        }
    }
    if (uVar5 == 0) {
        param_2 = param_2 + 1;
        uVar5 = 0;
    } else {
        uVar5 = uVar5 & 0xfffffffe;
    }
    if (param_2 << 1 < 0xffe00000) {
        return CONCAT44(param_2, uVar5);
    }
LAB_0800e2e4:
    return (uint64_t)((uint32_t)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}

/* ================================================================
 * FUN_0800dd1c  @  0x0800DD1C
 */

int64_t FUN_0800dd1c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    int64_t lVar1;
    uint64_t uVar2;
    uint32_t uVar3;
    uint32_t extraout_r3;
    uint32_t uVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;
    uint32_t uVar9;
    int iVar10;
    int iVar11;
    uint32_t unaff_lr;
    uint32_t uVar12;
    bool bVar13;

    if ((DAT_0800dfc4 & ~(param_2 >> 4)) == 0 || (DAT_0800dfc4 & ~(param_4 >> 4)) == 0) {
        FUN_0800e248();
        param_2 = extraout_r3;
    } else {
        uVar7 = param_2 ^ param_4;
        uVar4 = DAT_0800dfc4 & param_2 >> 4;
        bVar13 = uVar4 == 0;
        uVar6 = uVar7 >> 0x1f;
        if (!bVar13) {
            uVar7 = DAT_0800dfc4 & param_4 >> 4;
            bVar13 = uVar7 == 0;
        }
        if (bVar13) {
            if ((param_2 & DAT_0800dfc4 << 4) == 0) {
                if ((param_4 & DAT_0800dfc4 << 4) == 0) {
                    return (uint64_t)DAT_0800dfc8 << 0x20;
                }
                return (uint64_t)((param_2 ^ param_4) & 0x80000000) << 0x20;
            }
            param_2 = param_2 ^ param_4;
        } else {
            iVar5 = (uVar4 | uVar6) - uVar7;
            uVar7 = param_4 << 0xb | 0x80000000;
            uVar4 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
            uVar3 = uVar7 | param_3 >> 0x15;
            uVar6 = iVar5 + 0x3fe0000;
            if (uVar4 == uVar3 && param_1 * 0x800 == param_3 * 0x800) {
                uVar3 = 0x100000;
                uVar4 = 0;
            } else {
                uVar9 = (uint32_t)*(byte *)((uVar7 >> 0x18) + 0x800dec4);
                uVar9 = uVar9 * (0x1000000 - uVar9 * (uVar7 >> 0x10)) >> 0xf;
                iVar10 = (int)((uint64_t)uVar9 * (uint64_t)uVar3);
                iVar8 = -(int)((uint64_t)uVar9 * (uint64_t)uVar3 >> 0x20);
                iVar11 = iVar8 + 0x10000;
                if (iVar10 != 0) {
                    iVar11 = iVar8 + 0xffff;
                }
                uVar9 =
                    uVar9 * iVar11 + (int)((uint64_t)uVar9 * (uint64_t)(uint32_t)-iVar10 >> 0x20);
                lVar1 = (uint64_t)uVar9 * (uint64_t)uVar3 +
                        ((uint64_t)uVar9 * (uint64_t)(param_3 * 0x800) >> 0x20);
                iVar10 = (int)lVar1;
                iVar8 = -(int)((uint64_t)lVar1 >> 0x20);
                uVar3 = iVar8 + 0x80000000;
                if (iVar10 != 0) {
                    uVar3 = iVar8 + 0x7fffffff;
                }
                uVar2 = (uint64_t)uVar9 * (uint64_t)uVar3 +
                        ((uint64_t)uVar9 * (uint64_t)(uint32_t)-iVar10 >> 0x20);
                uVar9 = (uint32_t)(uVar2 >> 0x20);
                uVar3 = (uint32_t)((uint64_t)uVar4 * (uVar2 & 0xffffffff) >> 0x20);
                uVar12 = (uint32_t)((uint64_t)(param_1 * 0x800) * (uint64_t)uVar9 >> 0x20);
                uVar2 = (uint64_t)uVar4 * (uint64_t)uVar9 +
                        (uint64_t)CONCAT14(CARRY4(uVar3, uVar12), uVar3 + uVar12);
                iVar8 = (int)(uVar2 >> 0x20);
                unaff_lr = iVar8 + 0x70000000;
                if (!SCARRY4(iVar8, 0x70000000)) {
                    uVar6 = iVar5 + 0x3fd0000;
                    uVar2 = CONCAT44(iVar8 * 2 + (uint32_t)((uVar2 & 0x80000000) != 0),
                                     (int)uVar2 << 1);
                }
                uVar3 = (uint32_t)(uVar2 + 0x80 >> 0x20);
                uVar4 = (uint32_t)(uVar2 + 0x80) >> 8 | uVar3 * 0x1000000;
                uVar3 = uVar3 >> 8;
                if ((int)uVar2 * 0x1000000 + 0x91000000U < 0x10000001) {
                    uVar9 = param_3 & 0x1fffff | (param_3 >> 0x15) << 0x15;
                    iVar5 = uVar3 * uVar9 + uVar4 * (uVar7 >> 0xb) +
                            (int)((uint64_t)uVar4 * (uint64_t)uVar9 >> 0x20);
                    if (-1 < (int)unaff_lr) {
                        iVar5 = iVar5 + param_1 * -0x100000;
                    }
                    unaff_lr = iVar5 + param_1 * -0x100000 + (uVar7 >> 0xc) +
                               (uint32_t)CARRY4((uint32_t)((uint64_t)uVar4 * (uint64_t)uVar9),
                                                uVar9 >> 1 | (uVar7 >> 0xb) << 0x1f);
                    if ((int)unaff_lr < 0) {
                        bVar13 = 0xfffffffe < uVar4;
                        uVar4 = uVar4 + 1;
                        uVar3 = uVar3 + bVar13;
                    }
                }
            }
            iVar5 = uVar3 + uVar6 * -0x80000000 + (uVar6 & 0xfffffffe) * 0x10;
            if ((uVar6 & 0xfffffffe) < 0x7f00001) {
                return CONCAT44(iVar5, uVar4);
            }
            if (-1 < (int)uVar6) {
                unaff_lr = iVar5 + 0x100000;
            }
            if (-1 < (int)uVar6 && -1 < (int)(unaff_lr ^ uVar6 << 0x1f)) {
                return CONCAT44(iVar5, uVar4);
            }
            if ((int)uVar6 < 0) {
                return (uint64_t)(iVar5 + 0x60000000U & 0x80000000) << 0x20;
            }
            param_2 = iVar5 + 0xa0000000;
        }
    }
    return (uint64_t)((uint32_t)((int)param_2 < 0) << 0x1f | 0x7ff00000) << 0x20;
}

/* ================================================================
 * FUN_0800dfcc  @  0x0800DFCC
 */

uint32_t FUN_0800dfcc() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    int iVar1;
    uint32_t uVar2;
    uint16_t *unaff_r4;
    uint32_t uVar3;
    bool bVar4;

    iVar1 = (param_2 >> 0x14) - 0x400;
    bVar4 = SBORROW4(0x1e, iVar1);
    uVar2 = -iVar1 + 0x1e;
    uVar3 = uVar2;
    if (iVar1 < 0x1f) {
        bVar4 = SBORROW4(0x20, uVar2);
        uVar3 = 0x20 - uVar2;
    }
    if ((int)uVar3 < 0 == bVar4) {
        return (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff);
    }
    if ((int)param_2 < 0) {
        return 0;
    }
    if (0x10 < (int)uVar2) {
        return 0;
    }
    if (-iVar1 != -0x3ff) {
        return 0xffffffff;
    }
    FUN_0800e248(param_1);
    do {
        *unaff_r4 = (short)unaff_r4;
    } while (true);
}

/* ================================================================
 * FUN_0800e026  @  0x0800E026
 */

uint64_t FUN_0800e026() {
    uint32_t param_1 = 0;
    uint32_t uVar1;
    uint32_t uVar2;

    uVar2 = param_1 & 0x80000000;
    if ((int)uVar2 < 0) {
        param_1 = -param_1;
    }
    uVar1 = param_1 << LZCOUNT(param_1);
    if (uVar1 != 0) {
        return CONCAT44(uVar2 + (0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),
                        uVar1 << 0x15);
    }
    return 0;
}

/* ================================================================
 * FUN_0800e054  @  0x0800E054
 */

uint64_t FUN_0800e054(int param_1)

{
    uint32_t uVar1;

    uVar1 = param_1 << LZCOUNT(param_1);
    if (uVar1 != 0) {
        return CONCAT44((0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb), uVar1 << 0x15);
    }
    return 0;
}

/* ================================================================
 * FUN_0800e07c  @  0x0800E07C
 */

void FUN_0800e07c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    bool bVar2;
    bool bVar3;

    uVar1 = param_2 | param_4;
    if ((int)uVar1 < 0) {
        if ((int)(uVar1 + 0x100000) < 0) {
            if (-1 < (int)(uVar1 - 0x100000)) {
                return;
            }
            if (param_4 == param_2) {
                return;
            }
            return;
        }
        if (param_2 << 1 < 0xffe00000 && param_4 << 1 < 0xffe00000) {
            return;
        }
    } else {
        bVar3 = SCARRY4(uVar1, 0x100000);
        bVar2 = -1 < (int)(uVar1 + 0x100000);
        if (bVar2) {
            bVar3 = SBORROW4(uVar1, 0x100000);
        }
        if (bVar2 && -1 < (int)(uVar1 - 0x100000)) {
            if (param_2 == param_4) {
                return;
            }
            return;
        }
        if (!bVar3) {
            return;
        }
        if (-1 < (int)(param_2 + 0x100000) && -1 < (int)(param_4 + 0x100000)) {
            return;
        }
    }
    FUN_0800e248();
    do {
        /* WARNING: Do nothing block with infinite loop */
    } while (true);
}

/* ================================================================
 * FUN_0800e0f4  @  0x0800E0F4
 */

int64_t FUN_0800e0f4(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    int64_t lVar1;
    int64_t lVar2;
    int64_t lVar3;
    int64_t lVar4;
    int64_t lVar5;
    uint32_t uVar6;
    int extraout_r1;
    int iVar7;
    uint32_t uVar8;
    uint32_t extraout_r3;
    uint32_t unaff_r5;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    uint32_t uVar13;
    int iVar14;
    int iVar15;
    bool bVar16;

    uVar13 = DAT_0800e240 & param_2 >> 4;
    bVar16 = uVar13 == 0;
    if (!bVar16) {
        unaff_r5 = DAT_0800e240 & param_4 >> 4;
        bVar16 = unaff_r5 == 0;
    }
    if (!bVar16) {
        bVar16 = uVar13 == DAT_0800e240;
    }
    if (!bVar16) {
        bVar16 = unaff_r5 == DAT_0800e240;
    }
    if (bVar16) {
        if (uVar13 != DAT_0800e240 && (DAT_0800e240 & param_4 >> 4) != DAT_0800e240) {
            return (uint64_t)((param_2 ^ param_4) & 0x80000000) << 0x20;
        }
        FUN_0800e248();
        uVar13 = extraout_r1 << 2 ^ extraout_r3;
    } else {
        uVar6 = param_2 & ~(DAT_0800e240 << 5) | 0x100000;
        uVar8 = param_4 & ~(DAT_0800e240 << 5) | 0x100000;
        iVar14 = (uVar13 | (param_2 ^ param_4) >> 0x1f) + unaff_r5;
        lVar1 = (uint64_t)uVar6 * (uint64_t)param_3;
        uVar11 = (uint32_t)((uint64_t)lVar1 >> 0x20);
        lVar2 = (uint64_t)param_1 * (uint64_t)uVar8;
        uVar9 = (uint32_t)((uint64_t)lVar2 >> 0x20);
        iVar15 = iVar14 + -0x3fc0000;
        lVar4 = lVar1 + lVar2;
        uVar10 = (uint32_t)((uint64_t)lVar4 >> 0x20);
        lVar3 = (uint64_t)uVar6 * (uint64_t)uVar8;
        uVar13 = (uint32_t)lVar3;
        uVar12 = (uint32_t)((uint64_t)param_1 * (uint64_t)param_3 >> 0x20);
        lVar5 = lVar4 + CONCAT44(uVar13, uVar12);
        uVar8 = (uint32_t)lVar5;
        uVar6 = (uint32_t)((uint64_t)lVar5 >> 0x20);
        uVar13 =
            (int)((uint64_t)lVar3 >> 0x20) +
            (uint32_t)(CARRY4(uVar9, uVar11) ||
                       CARRY4(uVar9 + uVar11, (uint32_t)CARRY4((uint32_t)lVar2, (uint32_t)lVar1))) +
            (uint32_t)(CARRY4(uVar10, uVar13) ||
                       CARRY4(uVar10 + uVar13, (uint32_t)CARRY4((uint32_t)lVar4, uVar12)));
        if ((int)((uint64_t)param_1 * (uint64_t)param_3) != 0) {
            uVar8 = uVar8 | 1;
        }
        if ((uVar13 & 0x200) == 0) {
            uVar9 = uVar8 << 0xc;
            uVar13 = uVar13 * 0x1000 | uVar6 >> 0x14;
            uVar6 = uVar6 << 0xc | uVar8 >> 0x14;
            iVar7 = -4;
        } else {
            uVar9 = uVar8 << 0xb;
            uVar13 = uVar13 * 0x800 | uVar6 >> 0x15;
            uVar6 = uVar6 << 0xb | uVar8 >> 0x15;
            iVar7 = -3;
        }
        uVar8 = iVar7 + (iVar15 >> 0x10);
        uVar13 = uVar13 + uVar8 * 0x100000 ^ iVar14 * -0x80000000;
        if (uVar9 != 0) {
            bVar16 = (uVar9 & 0x80000000) != 0;
            if ((uVar9 & 0x7fffffff) != 0) {
                uVar9 = 0;
            }
            uVar13 = uVar13 + CARRY4(uVar6, (uint32_t)bVar16);
            uVar6 = uVar6 + bVar16 & ~(uVar9 >> 0x1f);
        }
        if (uVar8 < 0x7fe) {
            return CONCAT44(uVar13, uVar6);
        }
        if (iVar15 < 0x4000000) {
            return (uint64_t)(uVar13 + 0x60000000 & 0x80000000) << 0x20;
        }
        uVar13 = uVar13 + 0xa0000000;
    }
    return (uint64_t)((uint32_t)((int)uVar13 < 0) << 0x1f | 0x7ff00000) << 0x20;
}

/* ================================================================
 * FUN_0800e248  @  0x0800E248
 */

int FUN_0800e248() {
    int param_1 = 0;
    uint32_t param_2 = 0;
    int param_3 = 0;
    uint32_t param_4 = 0;
    int iVar1;
    uint32_t unaff_r5;
    uint32_t uVar2;
    uint32_t uVar3;
    int unaff_lr;
    uint32_t *puVar4;
    bool bVar5;

    puVar4 = (uint32_t *)(unaff_lr + 2U & 0xfffffffc);
    uVar2 = *puVar4;
    if ((((int)uVar2 < 0) ||
         (unaff_r5 = param_4 * 2 + (uint32_t)(param_3 != 0), unaff_r5 < 0xffe00001)) &&
        (uVar3 = param_2 * 2 + (uint32_t)(param_1 != 0), uVar3 < 0xffe00001)) {
        if (uVar3 == 0xffe00000) {
            uVar3 = ((int)param_2 >> 0x1f) * -3 + 2;
            if (unaff_r5 == 0xffe00000) {
                uVar3 = uVar3 + (1 - ((int)param_4 >> 0x1f));
            }
        } else {
            uVar3 = param_4 >> 0x1f;
        }
    } else {
        uVar3 = 8;
    }
    uVar2 = uVar2 >> (uVar3 * 3 & 0xff) & 7;
    switch (uVar2) {
    case 4:
        param_1 = param_3;
        param_2 = param_4;
    switchD_0800e2b4_caseD_5:
        bVar5 = CARRY4(param_2, param_2) || CARRY4(param_2 * 2, (uint32_t)(param_1 != 0));
        uVar2 = param_2 * 2 + (uint32_t)(param_1 != 0);
        if (uVar2 != 0) {
            bVar5 = uVar2 < 0x200001;
        }
        if (bVar5 && (uVar2 != 0 && uVar2 != 0x200000)) {
            param_1 = 0;
        }
        return param_1;
    case 5:
        goto switchD_0800e2b4_caseD_5;
    case 6:
    case 7:
        return 0;
    default:
        /* WARNING: Could not recover jumptable at 0x0800e2b2. Too many branches */
        /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)(puVar4 + uVar2 + 1))();
        return iVar1;
    }
}

/* ================================================================
 * FUN_0800e2f0  @  0x0800E2F0
 */

void FUN_0800e2f0() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uVar1;
    bool bVar2;
    bool bVar3;

    uVar1 = param_4 | param_2;
    if ((int)uVar1 < 0) {
        if ((int)(uVar1 + 0x100000) < 0) {
            if (-1 < (int)(uVar1 - 0x100000)) {
                return;
            }
            if (param_2 == param_4) {
                return;
            }
            return;
        }
        if (param_4 << 1 < 0xffe00000 && param_2 << 1 < 0xffe00000) {
            return;
        }
    } else {
        bVar3 = SCARRY4(uVar1, 0x100000);
        bVar2 = -1 < (int)(uVar1 + 0x100000);
        if (bVar2) {
            bVar3 = SBORROW4(uVar1, 0x100000);
        }
        if (bVar2 && -1 < (int)(uVar1 - 0x100000)) {
            if (param_4 == param_2) {
                return;
            }
            return;
        }
        if (!bVar3) {
            return;
        }
        if (-1 < (int)(param_4 + 0x100000) && -1 < (int)(param_2 + 0x100000)) {
            return;
        }
    }
    FUN_0800e248(param_3, param_4, param_1, param_2);
    do {
        /* WARNING: Do nothing block with infinite loop */
    } while (true);
}

/* ================================================================
 * FUN_0800e35c  @  0x0800E35C
 */

/* WARNING: Control flow encountered bad instruction data */

uint64_t FUN_0800e35c(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    bool bVar12;
    bool bVar13;
    byte bVar14;

    uVar2 = param_2 ^ 0x80000000;
    if (-1 < (int)(param_2 ^ param_4)) {
        param_4 = param_4 ^ 0x80000000;
        bVar12 = param_3 <= param_1;
        uVar8 = param_1 - param_3;
        if (uVar2 <= param_4 && (uint32_t)bVar12 <= uVar2 - param_4) {
            bVar13 = CARRY4(param_3, uVar8);
            param_3 = param_3 + uVar8;
            uVar9 = (uVar2 - param_4) - (uint32_t)!bVar12 ^ 0x80000000;
            param_4 = param_4 + uVar9 + bVar13;
            bVar12 = param_1 < uVar8;
            param_1 = param_1 - uVar8;
            uVar2 = (uVar2 - uVar9) - (uint32_t)bVar12;
        }
        uVar9 = uVar2 >> 0x14;
        uVar8 = uVar9 - (param_4 >> 0x14);
        if ((DAT_0800e544 & param_4 << 1) == 0 || DAT_0800e544 == uVar9 << 0x15) {
            if (DAT_0800e544 != uVar9 << 0x15) {
                if ((uVar2 & DAT_0800e544 >> 1) == 0) {
                    uVar2 = 0;
                    param_1 = 0;
                }
                return CONCAT44(uVar2, param_1);
            }
            FUN_0800e248();
            do {
                software_interrupt(0x40);
            } while (true);
        }
        uVar6 = -param_3;
        uVar3 = uVar2 & ~(uVar9 << 0x14);
        iVar7 = ((int)DAT_0800e544 >> 1) - (param_4 & ~((int)DAT_0800e544 >> 1));
        if (param_3 != 0) {
            iVar7 = iVar7 + -1;
        }
        if (uVar8 < 0x21) {
            uVar10 = uVar6 >> (uVar8 & 0xff);
            uVar1 = param_1 + uVar10;
            uVar3 = uVar3 + (iVar7 >> (uVar8 & 0xff)) + (uint32_t)CARRY4(param_1, uVar10);
            uVar11 = iVar7 << (0x20 - uVar8 & 0xff);
            uVar10 = uVar1 + uVar11;
            bVar12 = CARRY4(uVar3, (uint32_t)CARRY4(uVar1, uVar11));
            iVar7 = uVar3 + CARRY4(uVar1, uVar11);
            uVar8 = 0x20 - uVar8;
        } else {
            uVar6 =
                (uint32_t)(param_3 * -2 != 0) | (iVar7 * 2 + (uint32_t)CARRY4(uVar6, uVar6)) * 2;
            uVar8 = uVar8 - 0x20;
            if (0x1d < uVar8) {
                return CONCAT44(uVar3 + uVar9 * 0x100000, param_1);
            }
            uVar1 = iVar7 >> (uVar8 & 0xff);
            uVar10 = param_1 + uVar1;
            bVar12 = uVar3 != 0 || CARRY4(uVar3 - 1, (uint32_t)CARRY4(param_1, uVar1));
            iVar7 = (uVar3 - 1) + (uint32_t)CARRY4(param_1, uVar1);
            uVar8 = 0x1e - uVar8;
        }
        if (-1 < iVar7) {
            iVar5 = uVar6 << (uVar8 & 0xff);
            iVar7 = iVar7 + uVar9 * 0x100000;
            if (-1 < iVar5) {
                return CONCAT44(iVar7, uVar10);
            }
            uVar10 = uVar10 + 1;
            if (uVar10 != 0 && iVar5 != -0x80000000) {
                return CONCAT44(iVar7, uVar10);
            }
            if (uVar10 == 0) {
                iVar7 = iVar7 + 1;
                uVar10 = 0;
            } else {
                uVar10 = uVar10 & 0xfffffffe;
            }
            return CONCAT44(iVar7, uVar10);
        }
        uVar3 = uVar8 + 1 & 0xff;
        bVar12 = uVar3 == 0 && bVar12 || uVar3 != 0 && (uVar6 << uVar3 - 1 & 0x80000000) != 0;
        uVar1 = uVar10 * 2 + (uint32_t)bVar12;
        uVar8 =
            iVar7 * 2 + (uint32_t)(CARRY4(uVar10, uVar10) || CARRY4(uVar10 * 2, (uint32_t)bVar12));
        uVar10 = uVar8 + uVar9 * 0x200000;
        bVar12 = (uVar10 >> 0x14 & 1) != 0;
        if (bVar12 && uVar10 >> 0x15 != 0) {
            uVar2 = -((int)(uVar6 << uVar3) >> 0x1f);
            uVar10 = uVar1 + uVar2;
            bVar12 = uVar10 == 0;
            iVar7 = uVar8 + uVar9 * 0x100000;
            if (!CARRY4(uVar1, uVar2)) {
                bVar12 = uVar6 << uVar3 == -0x80000000;
            }
            if (!bVar12) {
                return CONCAT44(iVar7, uVar10);
            }
            if (uVar10 == 0) {
                iVar7 = iVar7 + 1;
                uVar10 = 0;
            } else {
                uVar10 = uVar10 & 0xfffffffe;
            }
            return CONCAT44(iVar7, uVar10);
        }
        if (!bVar12) {
            iVar7 = uVar8 + 0x200000;
            if (iVar7 == 0) {
                uVar8 = uVar1 << LZCOUNT(uVar1);
                if (uVar8 == 0) {
                    return (uint64_t)uVar1;
                }
                iVar5 = ((uVar9 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
                iVar7 = uVar8 << 0x15;
                uVar8 = uVar8 >> 0xb;
            } else {
                uVar6 = LZCOUNT(iVar7) - 0xb;
                iVar5 = ((uVar9 & 0xfffff7ff) - uVar6) + -2;
                uVar8 = iVar7 << (uVar6 & 0xff) | uVar1 >> (0x20 - uVar6 & 0xff);
                iVar7 = uVar1 << (uVar6 & 0xff);
            }
            iVar4 = uVar8 + (uVar2 & 0x80000000) + iVar5 * 0x100000;
            if (-1 < iVar5) {
                return CONCAT44(iVar4, iVar7);
            }
            return (uint64_t)(iVar4 + 0x60000000U & 0x80000000) << 0x20;
        }
        uVar9 = ((int)uVar8 >> 1) + uVar9 * 0x100000;
        uVar2 = (uint32_t)((uVar8 & 1) != 0) << 0x1f | uVar1 >> 1;
        if (uVar9 * 2 == 0 && uVar2 == 0) {
            return (uint64_t)uVar2;
        }
        if (0x1fffff < uVar9 * 2) {
            return CONCAT44(uVar9, uVar2);
        }
        return (uint64_t)(uVar9 & 0x80000000) << 0x20;
    }
    uVar8 = param_1 - param_3;
    iVar7 = (uVar2 - param_4) - (uint32_t)(param_3 > param_1);
    if (uVar2 <= param_4 && (uint32_t)(param_3 <= param_1) <= uVar2 - param_4) {
        bVar12 = CARRY4(param_3, uVar8);
        param_3 = param_3 + uVar8;
        param_4 = param_4 + iVar7 + (uint32_t)bVar12;
        bVar12 = param_1 < uVar8;
        param_1 = param_1 - uVar8;
        uVar2 = (uVar2 - iVar7) - (uint32_t)bVar12;
    }
    uVar9 = uVar2 >> 0x14;
    uVar8 = uVar9 - (param_4 >> 0x14);
    if ((DAT_0800dcf0 & param_4 << 1) == 0 || DAT_0800dcf0 == uVar9 << 0x15) {
        if (DAT_0800dcf0 != uVar9 << 0x15) {
            if ((uVar2 & DAT_0800dcf0 >> 1) == 0) {
                uVar2 = uVar2 & 0x80000000;
                param_1 = 0;
            }
            return CONCAT44(uVar2, param_1);
        }
        FUN_0800e248();
        /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
    }
    uVar2 = uVar2 & ~(uVar9 << 0x14);
    uVar6 = param_4 & ~DAT_0800dcf0 | 0x100000;
    if (uVar8 < 0x21) {
        uVar1 = param_3 >> (uVar8 & 0xff);
        uVar3 = param_1 + uVar1;
        uVar11 = uVar6 << (0x20 - uVar8 & 0xff);
        uVar10 = uVar3 + uVar11;
        uVar2 = uVar2 + (uVar6 >> (uVar8 & 0xff)) + (uint32_t)CARRY4(param_1, uVar1) +
                (uint32_t)CARRY4(uVar3, uVar11);
        uVar8 = 0x20 - uVar8;
        if (uVar2 < 0x100000) {
            uVar2 = uVar2 + uVar9 * 0x100000;
            /* goto LAB_0800dc20; */ (void)0;
        }
    LAB_0800dc82:
        bVar14 = (byte)uVar10 & 1;
        uVar6 = (uint32_t)((uVar2 + 0x100000 & 1) != 0) << 0x1f | uVar10 >> 1;
        uVar2 = (uVar2 + 0x100000 >> 1) + uVar9 * 0x100000;
        if ((uVar10 & 1) == 0) {
        LAB_0800dcb0:
            if (uVar2 * 2 < 0xffe00000) {
                return CONCAT44(uVar2, uVar6);
            }
            /* goto LAB_0800e2e4; */ (void)0;
        }
        bVar12 = CARRY4(uVar6, (uint32_t)bVar14);
        uVar6 = uVar6 + bVar14;
        uVar9 = uVar6;
        if (!bVar12) {
            uVar9 = param_3 << (uVar8 & 0xff);
        }
        if (uVar9 != 0)
            /* goto LAB_0800dcb0; */ (void)0;
    } else {
        param_3 = uVar6 * 2 + (uint32_t)(param_3 != 0);
        uVar3 = uVar8 - 0x20;
        uVar8 = 0x1f - uVar3;
        if (uVar3 < 0x20) {
            uVar6 = uVar6 >> (uVar3 & 0xff);
            uVar10 = param_1 + uVar6;
        } else {
            uVar8 = 0;
            uVar10 = param_1;
        }
        uVar2 = uVar2 + uVar9 * 0x100000 + (uint32_t)(uVar3 < 0x20 && CARRY4(param_1, uVar6));
        if (uVar9 != uVar2 >> 0x14) {
            uVar2 = uVar2 + uVar9 * -0x100000;
            /* goto LAB_0800dc82; */ (void)0;
        }
    LAB_0800dc20:
        param_3 = param_3 << (uVar8 & 0xff);
        if (-1 < (int)param_3) {
            return CONCAT44(uVar2, uVar10);
        }
        uVar6 = uVar10 + 1;
        uVar8 = uVar6;
        if (uVar10 != 0xffffffff) {
            uVar8 = param_3 & 0x7fffffff;
        }
        if (uVar8 != 0) {
            return CONCAT44(uVar2, uVar6);
        }
    }
    if (uVar6 == 0) {
        uVar2 = uVar2 + 1;
        uVar6 = 0;
    } else {
        uVar6 = uVar6 & 0xfffffffe;
    }
    if (uVar2 << 1 < 0xffe00000) {
        return CONCAT44(uVar2, uVar6);
    }
LAB_0800e2e4:
    return (uint64_t)((uint32_t)((int)(uVar2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}

/* ================================================================
 * FUN_0800e374  @  0x0800E374
 */

/* WARNING: Control flow encountered bad instruction data */

uint64_t FUN_0800e374(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)

{
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;
    int iVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    bool bVar11;
    bool bVar12;
    byte bVar13;

    if (-1 < (int)(param_2 ^ param_4)) {
        bVar11 = param_3 <= param_1;
        uVar7 = param_1 - param_3;
        if (param_2 <= param_4 && (uint32_t)bVar11 <= param_2 - param_4) {
            bVar12 = CARRY4(param_3, uVar7);
            param_3 = param_3 + uVar7;
            uVar8 = (param_2 - param_4) - (uint32_t)!bVar11 ^ 0x80000000;
            param_4 = param_4 + uVar8 + bVar12;
            bVar11 = param_1 < uVar7;
            param_1 = param_1 - uVar7;
            param_2 = (param_2 - uVar8) - (uint32_t)bVar11;
        }
        uVar8 = param_2 >> 0x14;
        uVar7 = uVar8 - (param_4 >> 0x14);
        if ((DAT_0800e544 & param_4 << 1) == 0 || DAT_0800e544 == uVar8 << 0x15) {
            if (DAT_0800e544 != uVar8 << 0x15) {
                if ((param_2 & DAT_0800e544 >> 1) == 0) {
                    param_2 = 0;
                    param_1 = 0;
                }
                return CONCAT44(param_2, param_1);
            }
            FUN_0800e248();
            do {
                software_interrupt(0x40);
            } while (true);
        }
        uVar5 = -param_3;
        uVar2 = param_2 & ~(uVar8 << 0x14);
        iVar6 = ((int)DAT_0800e544 >> 1) - (param_4 & ~((int)DAT_0800e544 >> 1));
        if (param_3 != 0) {
            iVar6 = iVar6 + -1;
        }
        if (uVar7 < 0x21) {
            uVar9 = uVar5 >> (uVar7 & 0xff);
            uVar1 = param_1 + uVar9;
            uVar2 = uVar2 + (iVar6 >> (uVar7 & 0xff)) + (uint32_t)CARRY4(param_1, uVar9);
            uVar10 = iVar6 << (0x20 - uVar7 & 0xff);
            uVar9 = uVar1 + uVar10;
            bVar11 = CARRY4(uVar2, (uint32_t)CARRY4(uVar1, uVar10));
            iVar6 = uVar2 + CARRY4(uVar1, uVar10);
            uVar7 = 0x20 - uVar7;
        } else {
            uVar5 =
                (uint32_t)(param_3 * -2 != 0) | (iVar6 * 2 + (uint32_t)CARRY4(uVar5, uVar5)) * 2;
            uVar7 = uVar7 - 0x20;
            if (0x1d < uVar7) {
                return CONCAT44(uVar2 + uVar8 * 0x100000, param_1);
            }
            uVar1 = iVar6 >> (uVar7 & 0xff);
            uVar9 = param_1 + uVar1;
            bVar11 = uVar2 != 0 || CARRY4(uVar2 - 1, (uint32_t)CARRY4(param_1, uVar1));
            iVar6 = (uVar2 - 1) + (uint32_t)CARRY4(param_1, uVar1);
            uVar7 = 0x1e - uVar7;
        }
        if (-1 < iVar6) {
            iVar4 = uVar5 << (uVar7 & 0xff);
            iVar6 = iVar6 + uVar8 * 0x100000;
            if (-1 < iVar4) {
                return CONCAT44(iVar6, uVar9);
            }
            uVar9 = uVar9 + 1;
            if (uVar9 != 0 && iVar4 != -0x80000000) {
                return CONCAT44(iVar6, uVar9);
            }
            if (uVar9 == 0) {
                iVar6 = iVar6 + 1;
                uVar9 = 0;
            } else {
                uVar9 = uVar9 & 0xfffffffe;
            }
            return CONCAT44(iVar6, uVar9);
        }
        uVar2 = uVar7 + 1 & 0xff;
        bVar11 = uVar2 == 0 && bVar11 || uVar2 != 0 && (uVar5 << uVar2 - 1 & 0x80000000) != 0;
        uVar1 = uVar9 * 2 + (uint32_t)bVar11;
        uVar7 = iVar6 * 2 + (uint32_t)(CARRY4(uVar9, uVar9) || CARRY4(uVar9 * 2, (uint32_t)bVar11));
        uVar9 = uVar7 + uVar8 * 0x200000;
        bVar11 = (uVar9 >> 0x14 & 1) != 0;
        if (bVar11 && uVar9 >> 0x15 != 0) {
            uVar9 = -((int)(uVar5 << uVar2) >> 0x1f);
            uVar10 = uVar1 + uVar9;
            bVar11 = uVar10 == 0;
            iVar6 = uVar7 + uVar8 * 0x100000;
            if (!CARRY4(uVar1, uVar9)) {
                bVar11 = uVar5 << uVar2 == -0x80000000;
            }
            if (!bVar11) {
                return CONCAT44(iVar6, uVar10);
            }
            if (uVar10 == 0) {
                iVar6 = iVar6 + 1;
                uVar10 = 0;
            } else {
                uVar10 = uVar10 & 0xfffffffe;
            }
            return CONCAT44(iVar6, uVar10);
        }
        if (!bVar11) {
            iVar6 = uVar7 + 0x200000;
            if (iVar6 == 0) {
                uVar7 = uVar1 << LZCOUNT(uVar1);
                if (uVar7 == 0) {
                    return (uint64_t)uVar1;
                }
                iVar4 = ((uVar8 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
                iVar6 = uVar7 << 0x15;
                uVar7 = uVar7 >> 0xb;
            } else {
                uVar5 = LZCOUNT(iVar6) - 0xb;
                iVar4 = ((uVar8 & 0xfffff7ff) - uVar5) + -2;
                uVar7 = iVar6 << (uVar5 & 0xff) | uVar1 >> (0x20 - uVar5 & 0xff);
                iVar6 = uVar1 << (uVar5 & 0xff);
            }
            iVar3 = uVar7 + (param_2 & 0x80000000) + iVar4 * 0x100000;
            if (-1 < iVar4) {
                return CONCAT44(iVar3, iVar6);
            }
            return (uint64_t)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
        }
        uVar8 = ((int)uVar7 >> 1) + uVar8 * 0x100000;
        uVar7 = (uint32_t)((uVar7 & 1) != 0) << 0x1f | uVar1 >> 1;
        if (uVar8 * 2 == 0 && uVar7 == 0) {
            return (uint64_t)uVar7;
        }
        if (0x1fffff < uVar8 * 2) {
            return CONCAT44(uVar8, uVar7);
        }
        return (uint64_t)(uVar8 & 0x80000000) << 0x20;
    }
    param_4 = param_4 ^ 0x80000000;
    uVar7 = param_1 - param_3;
    iVar6 = (param_2 - param_4) - (uint32_t)(param_3 > param_1);
    if (param_2 <= param_4 && (uint32_t)(param_3 <= param_1) <= param_2 - param_4) {
        bVar11 = CARRY4(param_3, uVar7);
        param_3 = param_3 + uVar7;
        param_4 = param_4 + iVar6 + (uint32_t)bVar11;
        bVar11 = param_1 < uVar7;
        param_1 = param_1 - uVar7;
        param_2 = (param_2 - iVar6) - (uint32_t)bVar11;
    }
    uVar8 = param_2 >> 0x14;
    uVar7 = uVar8 - (param_4 >> 0x14);
    if ((DAT_0800dcf0 & param_4 << 1) == 0 || DAT_0800dcf0 == uVar8 << 0x15) {
        if (DAT_0800dcf0 != uVar8 << 0x15) {
            if ((param_2 & DAT_0800dcf0 >> 1) == 0) {
                param_2 = param_2 & 0x80000000;
                param_1 = 0;
            }
            return CONCAT44(param_2, param_1);
        }
        FUN_0800e248();
        /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
    }
    param_2 = param_2 & ~(uVar8 << 0x14);
    uVar5 = param_4 & ~DAT_0800dcf0 | 0x100000;
    if (uVar7 < 0x21) {
        uVar1 = param_3 >> (uVar7 & 0xff);
        uVar2 = param_1 + uVar1;
        uVar10 = uVar5 << (0x20 - uVar7 & 0xff);
        uVar9 = uVar2 + uVar10;
        param_2 = param_2 + (uVar5 >> (uVar7 & 0xff)) + (uint32_t)CARRY4(param_1, uVar1) +
                  (uint32_t)CARRY4(uVar2, uVar10);
        uVar7 = 0x20 - uVar7;
        if (param_2 < 0x100000) {
            param_2 = param_2 + uVar8 * 0x100000;
            /* goto LAB_0800dc20; */ (void)0;
        }
    LAB_0800dc82:
        bVar13 = (byte)uVar9 & 1;
        uVar5 = (uint32_t)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar9 >> 1;
        param_2 = (param_2 + 0x100000 >> 1) + uVar8 * 0x100000;
        if ((uVar9 & 1) == 0) {
        LAB_0800dcb0:
            if (param_2 * 2 < 0xffe00000) {
                return CONCAT44(param_2, uVar5);
            }
            /* goto LAB_0800e2e4; */ (void)0;
        }
        bVar11 = CARRY4(uVar5, (uint32_t)bVar13);
        uVar5 = uVar5 + bVar13;
        uVar8 = uVar5;
        if (!bVar11) {
            uVar8 = param_3 << (uVar7 & 0xff);
        }
        if (uVar8 != 0)
            /* goto LAB_0800dcb0; */ (void)0;
    } else {
        param_3 = uVar5 * 2 + (uint32_t)(param_3 != 0);
        uVar2 = uVar7 - 0x20;
        uVar7 = 0x1f - uVar2;
        if (uVar2 < 0x20) {
            uVar5 = uVar5 >> (uVar2 & 0xff);
            uVar9 = param_1 + uVar5;
        } else {
            uVar7 = 0;
            uVar9 = param_1;
        }
        param_2 = param_2 + uVar8 * 0x100000 + (uint32_t)(uVar2 < 0x20 && CARRY4(param_1, uVar5));
        if (uVar8 != param_2 >> 0x14) {
            param_2 = param_2 + uVar8 * -0x100000;
            /* goto LAB_0800dc82; */ (void)0;
        }
    LAB_0800dc20:
        param_3 = param_3 << (uVar7 & 0xff);
        if (-1 < (int)param_3) {
            return CONCAT44(param_2, uVar9);
        }
        uVar5 = uVar9 + 1;
        uVar7 = uVar5;
        if (uVar9 != 0xffffffff) {
            uVar7 = param_3 & 0x7fffffff;
        }
        if (uVar7 != 0) {
            return CONCAT44(param_2, uVar5);
        }
    }
    if (uVar5 == 0) {
        param_2 = param_2 + 1;
        uVar5 = 0;
    } else {
        uVar5 = uVar5 & 0xfffffffe;
    }
    if (param_2 << 1 < 0xffe00000) {
        return CONCAT44(param_2, uVar5);
    }
LAB_0800e2e4:
    return (uint64_t)((uint32_t)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}

/* ================================================================
 * FUN_0800e548  @  0x0800E548
 */

int64_t FUN_0800e548() {
    uint32_t param_1 = 0;
    int param_2 = 0;
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;

    uVar1 = (uint32_t)((param_1 & 0x80000000) != 0) << 0x1f;
    uVar2 = (param_1 & 0x7fffffff) >> 3;
    uVar4 = param_1 << 1 ^ param_1;
    if (uVar4 != 0) {
        param_1 = param_1 << 0x1d;
        param_2 = (uVar1 | uVar2) + 0x38000000;
    }
    if (uVar4 == 0 || (uVar4 & 0x7f000000) == 0) {
        if ((uVar2 & 0x8000000) != 0) {
            iVar3 = FUN_0800e9c6(uVar1 | param_1 >> 0x1d | uVar2 << 3, param_2);
            return (uint64_t)((uint32_t)(iVar3 < 0) << 0x1f | 0x7ff00000) << 0x20;
        }
        return (uint64_t)uVar1 << 0x20;
    }
    return CONCAT44(param_2, param_1);
}

/* ================================================================
 * FUN_0800e5a0  @  0x0800E5A0
 */

/* WARNING: Control flow encountered bad instruction data */

uint32_t FUN_0800e5a0(uint32_t param_1, uint32_t param_2)

{
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    bool bVar8;

    if ((int)(param_1 ^ param_2) < 0) {
        param_2 = param_2 ^ 0x80000000;
        if (param_1 < param_2 || param_1 - param_2 == 0) {
            uVar4 = param_1 - param_2 ^ 0x80000000;
            param_1 = param_1 - uVar4;
            param_2 = param_2 + uVar4;
        }
        uVar4 = param_1 >> 0x17;
        uVar5 = uVar4 - (param_2 >> 0x17);
        if ((param_2 & 0x7f800000) == 0 || (uVar4 & 0xff) == 0xff) {
            if ((uVar4 & 0xff) != 0xff) {
                if ((param_1 & 0x7f800000) == 0) {
                    param_1 = 0;
                }
                return param_1;
            }
            FUN_0800e9c6();
            do {
                software_interrupt(0x40);
            } while (true);
        }
        uVar1 = param_2 << 8 | 0x80000000;
        uVar2 = (param_1 << 8 | 0x80000000) - (uVar1 >> (uVar5 & 0xff));
        if (-1 < (int)uVar2) {
            if ((uVar4 & 0xfe) == 0) {
                if (uVar2 >> 7 == 0) {
                    return 0;
                }
            } else {
                iVar3 = uVar2 * 2;
                if (iVar3 < 0) {
                    bVar8 = (iVar3 >> 7 & 1U) != 0;
                    uVar4 = (iVar3 >> 8) + uVar4 * 0x800000 + (uint32_t)bVar8;
                    if (!bVar8) {
                        return uVar4;
                    }
                    if ((uVar2 & 0x3f) != 0) {
                        return uVar4;
                    }
                    /* goto LAB_0800eade; */ (void)0;
                }
                uVar5 = (uVar2 & 0x7fffffff) >> 1;
                if (uVar5 == 0) {
                    return 0;
                }
                uVar2 = uVar4 - LZCOUNT(uVar5);
                uVar1 = 0x28U - LZCOUNT(uVar5) & 0x1f;
                if ((uVar4 ^ uVar2) >> 8 == 0) {
                    return (uVar5 >> uVar1 | uVar5 << 0x20 - uVar1) + uVar2 * 0x800000;
                }
            }
            return param_1 & 0x80000000;
        }
        bVar8 = (uVar2 >> 7 & 1) != 0;
        uVar4 = (uVar2 >> 8) + (uVar4 - 1) * 0x800000 + (uint32_t)bVar8;
        if (!bVar8) {
            return uVar4;
        }
        if ((uVar2 & 0x7f) != 0) {
            return uVar4;
        }
    LAB_0800eade:
        if (uVar1 << (0x20 - uVar5 & 0xff) == 0) {
            uVar4 = uVar4 & 0xfffffffe;
        } else {
            uVar4 = uVar4 - 1;
        }
        return uVar4;
    }
    iVar3 = param_1 - param_2;
    if (param_1 < param_2) {
        param_1 = param_1 - iVar3;
        param_2 = param_2 + iVar3;
    }
    uVar4 = param_1 >> 0x17;
    uVar5 = uVar4 - (param_2 >> 0x17);
    if ((param_2 & 0x7f800000) == 0 || (uVar4 & 0xff) == 0xff) {
        if ((uVar4 & 0xff) != 0xff) {
            if ((param_1 & 0x7f800000) == 0) {
                param_1 = param_1 & 0x80000000;
            }
            return param_1;
        }
        FUN_0800e9c6();
        /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
    }
    uVar1 = param_1 << 8 | 0x80000000;
    uVar2 = param_2 << 8 | 0x80000000;
    uVar6 = uVar2 >> (uVar5 & 0xff);
    uVar7 = uVar1 + uVar6;
    if (CARRY4(uVar1, uVar6)) {
        bVar8 = (uVar7 >> 1 & 0x80) != 0;
        uVar1 = (uVar7 >> 1 | 0x80000000) >> 8;
        uVar4 = uVar1 + uVar4 * 0x800000 + (uint32_t)bVar8;
        if (bVar8) {
            uVar1 = uVar7 & 0xff;
        }
        uVar6 = uVar4 * 2;
        if (uVar1 != 0) {
            if (uVar6 < 0xff000000) {
                return uVar4;
            }
            /* goto LAB_0800e61c; */ (void)0;
        }
    } else {
        bVar8 = (uVar7 >> 7 & 1) != 0;
        uVar4 = (uVar7 >> 8) + (uVar4 - 1) * 0x800000 + (uint32_t)bVar8;
        if (!bVar8) {
            return uVar4;
        }
        uVar6 = uVar4 * 2;
        if ((uVar7 & 0x7f) != 0) {
            bVar8 = 0xfeffffff < uVar6;
        }
        if (!bVar8) {
            return uVar4;
        }
    }
    if (uVar2 << (0x20 - uVar5 & 0xff) == 0) {
        uVar4 = uVar4 & 0xfffffffe;
    }
    if (uVar6 < 0xff000000) {
        return uVar4;
    }
LAB_0800e61c:
    return (uVar4 + 0xa0000000 >> 0x17 | 0xff) << 0x17;
}

/* ================================================================
 * FUN_0800e670  @  0x0800E670
 */

uint64_t FUN_0800e670() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int iVar7;
    bool bVar8;

    uVar3 = param_1 >> 7 & 0xff0000;
    bVar8 = uVar3 == 0;
    if (!bVar8) {
        param_4 = param_2 >> 7 & 0xff0000;
        bVar8 = param_4 == 0;
    }
    if (!bVar8) {
        bVar8 = uVar3 == 0xff0000;
    }
    if (!bVar8) {
        bVar8 = param_4 == 0xff0000;
    }
    if (bVar8) {
        uVar6 = param_2 >> 7 & 0xff0000;
        if ((int)(param_1 ^ param_2) < 0) {
            uVar3 = uVar3 | 0x100;
        }
        if (uVar3 < 0xff0000 && uVar6 < 0xff0000) {
            if (uVar6 != 0) {
                return CONCAT44(param_2, param_1 ^ param_2) & 0xffffffff80000000;
            }
            if ((uVar3 & 0xff0000) == 0) {
                return CONCAT44(param_2, DAT_0800e7f0);
            }
            param_1 = param_1 ^ param_2;
        } else {
            param_1 = FUN_0800e9c6();
            param_1 = param_1 & 0x80000000;
        }
    } else {
        if ((int)(param_1 ^ param_2) < 0) {
            uVar3 = uVar3 | 0x100;
        }
        uVar2 = param_1 & 0xffffff | 0x800000;
        uVar1 = param_2 & 0xffffff | 0x800000;
        bVar8 = uVar1 <= uVar2;
        uVar6 = -uVar1;
        uVar1 = (uint32_t)*(byte *)(0x800e7b8 - (uVar1 >> 0x11));
        iVar7 = uVar1 * 2;
        if (!bVar8) {
            uVar2 = uVar2 << 1;
        }
        iVar4 = (uVar3 - param_4) + 0x7d0000;
        iVar7 = uVar1 * 0x100 + (((int)(uVar6 * iVar7) >> 4) * iVar7 >> 0x15);
        uVar1 = iVar4 + (iVar4 >> 0x10) + (uint32_t)bVar8;
        uVar5 = iVar7 * (uVar2 >> 8) >> 0x14;
        uVar3 = uVar6 * uVar5 + uVar2 * 0x800;
        uVar2 = iVar7 * (uVar3 >> 8) >> 0x13;
        uVar3 = uVar6 * uVar2 + uVar3 * 0x1000;
        bVar8 = CARRY4(uVar3, uVar6);
        if (bVar8) {
            uVar3 = uVar3 + uVar6;
        }
        iVar7 = uVar6 + uVar3 * 2;
        param_1 = uVar2 + uVar5 * 0x1000 + (uint32_t)bVar8 + uVar1 * 0x800000 +
                  (uint32_t)CARRY4(uVar6, uVar3 * 2);
        if (uVar1 < 0xfc0000) {
            return CONCAT44(iVar7, param_1);
        }
        if ((int)(uVar1 - 0xfc0000) < 0) {
            if ((uVar1 & 0xf0) != 0) {
                param_1 = param_1 + 0x60000000 & 0x80000000;
            }
            return CONCAT44(iVar7, param_1);
        }
        if (0xfdffffff < param_1 * 2 + 0x1000000) {
            return CONCAT44(iVar7, param_1);
        }
        param_1 = param_1 + 0xa0000000;
    }
    return CONCAT44(0xff, (param_1 >> 0x17 | 0xff) << 0x17);
}

/* ================================================================
 * FUN_0800e7f4  @  0x0800E7F4
 */

uint32_t FUN_0800e7f4() {
    uint32_t param_1 = 0;
    uint32_t uVar1;
    uint32_t uVar2;
    uint16_t *unaff_r4;

    uVar2 = (param_1 & 0x7fffffff) >> 0x17;
    uVar1 = 0x9e - uVar2;
    if (0x9e < uVar2 || uVar1 == 0) {
        FUN_0800e9c6();
        do {
            *unaff_r4 = (short)unaff_r4;
        } while (true);
    }
    uVar1 = ((param_1 | 0x800000) << 8) >> (uVar1 & 0xff);
    if ((int)(param_1 | 0x800000) < 0) {
        uVar1 = -uVar1;
    }
    return uVar1;
}

/* ================================================================
 * FUN_0800e82c  @  0x0800E82C
 */

uint32_t FUN_0800e82c(uint32_t param_1)

{
    uint16_t *unaff_r4;

    if (param_1 >> 0x17 < 0x9f) {
        return (param_1 << 8 | 0x80000000) >> (0x9e - (param_1 >> 0x17) & 0xff);
    }
    if (((int)param_1 < 0) && (param_1 << 1 < 0x7f000000)) {
        return 0;
    }
    FUN_0800e9c6();
    do {
        *unaff_r4 = (short)unaff_r4;
    } while (true);
}

/* ================================================================
 * FUN_0800e86c  @  0x0800E86C
 */

uint32_t FUN_0800e86c(uint32_t param_1)

{
    uint32_t uVar1;
    uint32_t uVar2;

    uVar1 = param_1 & 0x80000000;
    if ((int)uVar1 < 0) {
        param_1 = -param_1;
    }
    uVar2 = param_1 << LZCOUNT(param_1);
    if (uVar2 != 0) {
        param_1 = (uVar1 | (0x9d - LZCOUNT(param_1)) * 0x800000) + (uVar2 >> 8);
        if ((uVar2 & 0x80) == 0) {
            return param_1;
        }
        param_1 = param_1 + 1;
        if ((uVar2 & 0x7f) == 0) {
            param_1 = param_1 & 0xfffffffe;
        }
    }
    return param_1;
}

/* ================================================================
 * FUN_0800e89c  @  0x0800E89C
 */

uint32_t FUN_0800e89c(uint32_t param_1)

{
    uint32_t uVar1;

    uVar1 = param_1 << LZCOUNT(param_1);
    if (uVar1 != 0) {
        param_1 = (0x9d - LZCOUNT(param_1)) * 0x800000 + (uVar1 >> 8);
        if ((uVar1 & 0x80) == 0) {
            return param_1;
        }
        param_1 = param_1 + 1;
        if ((uVar1 & 0x7f) == 0) {
            param_1 = param_1 & 0xfffffffe;
        }
    }
    return param_1;
}

/* ================================================================
 * FUN_0800e8c4  @  0x0800E8C4
 */

uint32_t FUN_0800e8c4() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t param_4 = 0;
    int64_t lVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    bool bVar6;
    uint64_t uVar7;

    uVar2 = param_1 >> 7 & 0xff0000;
    bVar6 = uVar2 == 0;
    if (!bVar6) {
        param_4 = param_2 >> 7 & 0xff0000;
        bVar6 = param_4 == 0;
    }
    if (!bVar6) {
        bVar6 = uVar2 == 0xff0000;
    }
    if (!bVar6) {
        bVar6 = param_4 == 0xff0000;
    }
    if (bVar6) {
        if ((int)(param_1 ^ param_2) < 0) {
            uVar2 = uVar2 | 0x100;
        }
        if (uVar2 < 0xff0000 && (param_2 >> 7 & 0xff0000) < 0xff0000) {
            return (param_1 ^ param_2) & 0x80000000;
        }
        uVar7 = FUN_0800e9c6();
        uVar2 = (uint32_t)uVar7 ^ (int)((uint64_t)uVar7 >> 0x20) << 2;
    } else {
        if ((int)(param_1 ^ param_2) < 0) {
            uVar2 = uVar2 | 0x100;
        }
        lVar1 = (uint64_t)(param_1 << 8 | 0x80000000) * (uint64_t)(param_2 << 8 | 0x80000000);
        uVar4 = (uint32_t)((uint64_t)lVar1 >> 0x20);
        iVar3 = uVar2 + param_4 + -0x800000;
        if ((int)lVar1 != 0) {
            uVar4 = uVar4 | 1;
        }
        bVar6 = (uVar4 & 0x80000000) != 0;
        uVar5 = uVar4 << 1;
        if (bVar6) {
            uVar5 = uVar4 & 0x7fffffff | 0x80000000;
        }
        uVar4 = iVar3 + (iVar3 >> 0x10) + (uint32_t)bVar6;
        bVar6 = (uVar5 >> 7 & 1) != 0;
        uVar2 = (uVar5 >> 8) + uVar4 * 0x800000 + (uint32_t)bVar6;
        if ((!bVar6 || uVar5 >> 8 < uVar5 << 0x19) && uVar4 < 0xfc0000) {
            return uVar2;
        }
        if ((uVar5 & 0xff) == 0x80) {
            uVar2 = uVar2 & 0xfffffffe;
        }
        if (uVar4 < 0xfc0000) {
            return uVar2;
        }
        if ((int)(uVar4 - 0xfc0000) < 0) {
            if (-0x10000 < (int)(uVar4 ^ 0xff)) {
                return uVar2;
            }
            uVar2 = uVar2 + 0x60000000;
            if ((int)(uVar4 ^ 0xff) < -0xffff) {
                uVar2 = uVar2 & 0x80000000;
            }
            return uVar2;
        }
        if ((int)((uVar2 + 0x800000) * 2) < 0) {
            return uVar2;
        }
        uVar2 = uVar2 + 0xa0000000;
    }
    return (uVar2 >> 0x17 | 0xff) << 0x17;
}

/* ================================================================
 * FUN_0800e9c6  @  0x0800E9C6
 */

uint32_t FUN_0800e9c6() {
    uint32_t param_1 = 0;
    uint32_t param_2 = 0;
    uint32_t param_3 = 0;
    uint32_t uVar1;
    uint32_t uVar2;
    int unaff_lr;
    uint32_t *puVar3;
    bool bVar4;

    puVar3 = (uint32_t *)(unaff_lr + 2U & 0xfffffffc);
    uVar1 = *puVar3;
    if ((((int)uVar1 < 0) || (param_3 = param_2 * 2, param_3 < 0xff000001)) &&
        (param_1 * 2 < 0xff000001)) {
        if (param_1 * 2 == 0xff000000) {
            uVar2 = ((int)param_1 >> 0x1f) * -3 + 2;
            if (param_3 == 0xff000000) {
                uVar2 = uVar2 + (1 - ((int)param_2 >> 0x1f));
            }
        } else {
            uVar2 = param_2 >> 0x1f;
        }
    } else {
        uVar2 = 8;
    }
    uVar1 = uVar1 >> (uVar2 * 3 & 0xff) & 7;
    switch (uVar1) {
    case 4:
        param_1 = param_2;
    switchD_0800ea2e_caseD_5:
        bVar4 = (param_1 & 0x80000000) != 0;
        uVar1 = param_1 * 2;
        if (uVar1 != 0) {
            bVar4 = uVar1 < 0x1000001;
        }
        if (bVar4 && (uVar1 != 0 && uVar1 != 0x1000000)) {
            param_1 = param_1 & 0x80000000;
        }
        return param_1;
    case 5:
        goto switchD_0800ea2e_caseD_5;
    case 6:
    case 7:
        return 0x7fc00000;
    default:
        /* WARNING: Could not recover jumptable at 0x0800ea2c. Too many branches */
        /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)(puVar3 + uVar1 + 1))();
        return uVar1;
    }
}

/* EOF: 364 functions, 0 failed */
