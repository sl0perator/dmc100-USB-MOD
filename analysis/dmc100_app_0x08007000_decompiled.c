// ===== FUN_08007178 @ 08007178

void FUN_08007178(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = DAT_080071a4;
  puVar3 = (undefined4 *)((int)&DAT_080071a4 + DAT_080071a4);
  iVar2 = DAT_080071a4 + 0x80071a3;
  if (puVar3 == (undefined4 *)((int)&DAT_080071a4 + DAT_080071a8)) {
    FUN_080071fe();
  }
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x80071b0);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE = (code *)(iVar2 - (int)UNRECOVERED_JUMPTABLE);
  }
                    /* WARNING: Could not recover jumptable at 0x080071a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*puVar3,*(undefined4 *)((int)&DAT_080071a8 + iVar1),*(undefined4 *)(iVar1 + 0x80071ac))
  ;
  return;
}


// ===== FUN_080071e4 @ 080071e4

undefined4 FUN_080071e4(int param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0x73) {
    return 0;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    FUN_080074a0(param_1,*param_3,0xffffffff);
  }
  return 1;
}


// ===== FUN_080071ee @ 080071ee

undefined8 FUN_080071ee(undefined4 param_1,undefined4 param_2)

{
  FUN_08007778(param_1,param_2);
  return CONCAT44(param_2,param_1);
}


// ===== FUN_080071fa @ 080071fa

void FUN_080071fa(void)

{
  return;
}


// ===== FUN_080071fe @ 080071fe

void FUN_080071fe(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined8 uVar2;
  
  uVar1 = FUN_080078b6();
  FUN_080071ee(uVar1,extraout_r2);
  FUN_080106e4();
  uVar2 = FUN_08007900();
  FUN_080071fa();
  FUN_08008eda((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  (*DAT_08007244)();
                    /* WARNING: Could not recover jumptable at 0x08007222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_08007248)();
  return;
}


// ===== Reset_Handler @ 0800721c

void Reset_Handler(void)

{
  (*DAT_08007244)();
                    /* WARNING: Could not recover jumptable at 0x08007222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_08007248)();
  return;
}


// ===== vec_16 @ 08007236

void vec_16(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_08007238 @ 08007238

undefined8 FUN_08007238(void)

{
  return CONCAT44(DAT_08007250,DAT_0800724c);
}


// ===== FUN_0800725e @ 0800725e

uint * FUN_0800725e(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  
  puVar3 = (undefined4 *)FUN_08007740();
  puVar7 = (uint *)*puVar3;
  uVar6 = param_1 + 0xb & 0xfffffff8;
  if (uVar6 <= param_1) {
    return (uint *)0x0;
  }
  do {
    puVar1 = puVar7;
    for (puVar2 = (uint *)puVar7[1]; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[1]) {
      if (uVar6 <= *puVar2) {
        if (*puVar2 < uVar6 + 8) {
          puVar1[1] = puVar2[1];
        }
        else {
          piVar4 = (int *)((int)puVar2 + uVar6);
          piVar4[1] = puVar2[1];
          *piVar4 = *puVar2 - uVar6;
          puVar1[1] = (uint)piVar4;
          *puVar2 = uVar6;
        }
        return puVar2 + 1;
      }
      puVar1 = puVar2;
    }
    iVar5 = FUN_08007750(puVar7,uVar6);
  } while (iVar5 != 0);
  return (uint *)0x0;
}


// ===== FUN_080072bc @ 080072bc

void FUN_080072bc(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + -4);
  piVar1 = (int *)FUN_08007740();
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
  }
  else {
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


// ===== FUN_0800730a @ 0800730a

undefined8 FUN_0800730a(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_4 == 0 && param_3 == 0) {
    return 0;
  }
  uVar5 = 0;
  if (param_4 != 0) {
    iVar3 = LZCOUNT(param_4);
    uVar1 = param_4 << iVar3;
    uVar5 = uVar1 >> iVar3 ^ param_4 | param_3;
  }
  else {
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
  for (; param_4 < param_2 || param_2 - param_4 < (uint)(param_3 <= param_1);
      param_2 = (param_2 -
                (uVar6 * param_4 +
                uVar8 * param_3 + (int)((ulonglong)uVar6 * (ulonglong)param_3 >> 0x20))) -
                (uint)bVar10) {
    if (param_2 != 0) {
      iVar7 = LZCOUNT(param_2);
      uVar1 = param_2 << iVar7;
    }
    else {
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
    bVar10 = CARRY4(uVar5,uVar6);
    uVar5 = uVar5 + uVar6;
    uVar1 = (uint)((ulonglong)uVar6 * (ulonglong)param_3);
    iVar3 = iVar3 + uVar8 + bVar10;
    bVar10 = param_1 < uVar1;
    param_1 = param_1 - uVar1;
  }
  return CONCAT44(iVar3,uVar5);
}


// ===== FUN_080073f8 @ 080073f8

longlong FUN_080073f8(uint param_1,int param_2,uint param_3)

{
  if ((int)(param_3 - 0x20) < 0) {
    return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                    param_1 << (param_3 & 0xff));
  }
  return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
}


// ===== FUN_08007420 @ 08007420

void FUN_08007420(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_08007810(param_1,DAT_08007434,&uStack_c);
  return;
}


// ===== FUN_08007438 @ 08007438

undefined4 FUN_08007438(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = 0;
  do {
    param_1[8] = iVar1;
LAB_08007444:
    iVar1 = (*(code *)param_1[3])(param_1);
    if (iVar1 == 0) {
LAB_0800749a:
      return param_1[8];
    }
    if (iVar1 == 0x25) {
      uVar3 = 0;
      iVar1 = (*(code *)param_1[3])(param_1);
      if (iVar1 == 0) goto LAB_0800749a;
      if (iVar1 - 0x41U < 0x1a) {
        iVar1 = iVar1 + 0x20;
        uVar3 = 0x800;
      }
      *param_1 = uVar3;
      iVar2 = FUN_080071e4(param_1,iVar1,param_2);
      if (iVar2 == 0) goto LAB_08007450;
      if (iVar2 == 1) {
        param_2 = param_2 + 4;
      }
      else {
        param_2 = (param_2 + 7U & 0xfffffff8) + 8;
      }
      goto LAB_08007444;
    }
LAB_08007450:
    (*(code *)param_1[1])(iVar1,param_1[2]);
    iVar1 = param_1[8] + 1;
  } while( true );
}


// ===== FUN_080074a0 @ 080074a0

byte * FUN_080074a0(byte *param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  
  if (param_3 == 1) {
    uVar1 = 1;
  }
  else {
    if ((int)((uint)*param_1 << 0x1a) < 0) {
      param_3 = *(uint *)(param_1 + 0x1c);
    }
    for (uVar1 = 0; (uVar1 < param_3 && (param_2[uVar1] != '\0')); uVar1 = uVar1 + 1) {
    }
  }
  puVar2 = param_2 + uVar1;
  *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar1;
  *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar1;
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    (**(code **)(param_1 + 4))(*param_2,*(undefined4 *)(param_1 + 8));
  }
  return param_1;
}


// ===== FUN_080074f2 @ 080074f2

char * FUN_080074f2(int param_1,char param_2)

{
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


// ===== FUN_08007506 @ 08007506

int FUN_08007506(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      uVar5 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      if (uVar5 != uVar3) {
        if ((uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18) <
            (uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18)) {
          return 1;
        }
        return -1;
      }
    }
  }
  if (param_3 == 0) {
    return 0;
  }
  if ((param_3 & 1) == 0) goto LAB_0800753e;
  param_3 = param_3 + 1;
  puVar1 = param_1;
  puVar2 = param_2;
  while( true ) {
    param_1 = (uint *)((int)puVar1 + 1);
    param_2 = (uint *)((int)puVar2 + 1);
    iVar4 = (uint)(byte)*puVar1 - (uint)(byte)*puVar2;
    if (iVar4 != 0) {
      return iVar4;
    }
    param_3 = param_3 - 2;
    if (param_3 == 0) break;
LAB_0800753e:
    puVar1 = (uint *)((int)param_1 + 1);
    puVar2 = (uint *)((int)param_2 + 1);
    iVar4 = (uint)(byte)*param_1 - (uint)(byte)*param_2;
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  return 0;
}


// ===== FUN_0800755e @ 0800755e

void FUN_0800755e(uint *param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while( true ) {
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) break;
      *param_1 = uVar4;
      param_1 = param_1 + 1;
    }
    while( true ) {
      *(char *)param_1 = (char)uVar4;
      if ((uVar4 & 0xff) == 0) break;
      uVar4 = uVar4 >> 8;
      param_1 = (uint *)((int)param_1 + 1);
    }
  }
  else {
    do {
      pcVar2 = (char *)((int)param_2 + 1);
      uVar4 = *param_2;
      pcVar3 = (char *)((int)param_1 + 1);
      *(char *)param_1 = (char)uVar4;
      if ((char)uVar4 == '\0') {
        return;
      }
      param_2 = (uint *)((int)param_2 + 2);
      cVar1 = *pcVar2;
      param_1 = (uint *)((int)param_1 + 2);
      *pcVar3 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}


// ===== FUN_080075a6 @ 080075a6

undefined8 FUN_080075a6(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  byte *pbVar5;
  byte bVar6;
  undefined2 uVar7;
  byte in_r12;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  puVar4 = param_2;
  if (3 < param_3) {
    uVar8 = (uint)param_1 & 3;
    puVar2 = param_1;
    uVar9 = uVar8;
    if (uVar8 != 0) {
      bVar6 = (byte)*param_2;
      puVar4 = (uint *)((int)param_2 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_2 + 2);
        uVar9 = (uint)*(byte *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar6;
      param_2 = puVar4;
      if (uVar8 < 2) {
        param_2 = (uint *)((int)puVar4 + 1);
        bVar6 = (byte)*puVar4;
      }
      param_3 = (param_3 + uVar8) - 4;
      puVar4 = (uint *)((int)param_1 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_1 + 2);
        *(byte *)((int)param_1 + 1) = (byte)uVar9;
      }
      puVar2 = puVar4;
      if (uVar8 < 2) {
        puVar2 = (uint *)((int)puVar4 + 1);
        *(byte *)puVar4 = bVar6;
      }
    }
    param_4 = (uint)param_2 & 3;
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
      uVar7 = (undefined2)uVar9;
      if ((uVar8 & 3) == 0) {
        return CONCAT44(puVar4,puVar3);
      }
      bVar1 = (uVar8 & 2) != 0;
      param_3 = param_3 << 0x1f;
      bVar13 = (int)param_3 < 0;
      puVar2 = puVar4;
      if (bVar1) {
        puVar2 = (uint *)((int)puVar4 + 2);
        uVar7 = (undefined2)*puVar4;
      }
      puVar4 = puVar2;
      if (bVar13) {
        puVar4 = (uint *)((int)puVar2 + 1);
        param_3 = (uint)(byte)*puVar2;
      }
      puVar2 = puVar3;
      if (bVar1) {
        puVar2 = (uint *)((int)puVar3 + 2);
        *(undefined2 *)puVar3 = uVar7;
      }
      puVar3 = puVar2;
      if (bVar13) {
        puVar3 = (uint *)((int)puVar2 + 1);
        *(byte *)puVar2 = (byte)param_3;
      }
      return CONCAT44(puVar4,puVar3);
    }
    while( true ) {
      in_r12 = (byte)uVar9;
      if (param_3 < 8) break;
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
    puVar4 = (uint *)((int)puVar4 + 2);
    in_r12 = *pbVar5;
  }
  puVar2 = puVar4;
  if (bVar13) {
    puVar2 = (uint *)((int)puVar4 + 1);
    param_3 = (uint)(byte)*puVar4;
  }
  if (bVar1) {
    pbVar5 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = bVar6;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar5 = in_r12;
  }
  puVar4 = param_1;
  if (bVar13) {
    puVar4 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  return CONCAT44(puVar2,puVar4);
}


// ===== FUN_08007694 @ 08007694

undefined4 * FUN_08007694(undefined4 *param_1,uint param_2,undefined1 param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  uVar1 = CONCAT11(param_3,param_3);
  uVar6 = CONCAT22(uVar1,uVar1);
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar3 = (undefined1 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar3 = param_3;
    }
    puVar2 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
    }
    return puVar2;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar7 = 4 - ((uint)param_1 & 3);
    puVar2 = param_1;
    if (iVar7 != 2) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_3;
    }
    param_1 = puVar2;
    if (1 < iVar7) {
      param_1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
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
  if ((param_2 & 4) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = uVar6;
  }
  if (uVar5 == 0) {
    return puVar2;
  }
  puVar4 = puVar2;
  if ((int)uVar5 < 0) {
    puVar4 = (undefined4 *)((int)puVar2 + 2);
    *(undefined2 *)puVar2 = uVar1;
  }
  puVar2 = puVar4;
  if ((uVar5 & 0x40000000) != 0) {
    puVar2 = (undefined4 *)((int)puVar4 + 1);
    *(undefined1 *)puVar4 = param_3;
  }
  return puVar2;
}


// ===== FUN_080076a4 @ 080076a4

undefined4 * FUN_080076a4(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar2 = (undefined1 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar2 = 0;
    }
    puVar1 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    return puVar1;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar5 = 4 - ((uint)param_1 & 3);
    puVar1 = param_1;
    if (iVar5 != 2) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    param_1 = puVar1;
    if (1 < iVar5) {
      param_1 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
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
  if ((param_2 & 4) != 0) {
    puVar1 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar4 == 0) {
    return puVar1;
  }
  puVar3 = puVar1;
  if ((int)uVar4 < 0) {
    puVar3 = (undefined4 *)((int)puVar1 + 2);
    *(undefined2 *)puVar1 = 0;
  }
  puVar1 = puVar3;
  if ((uVar4 & 0x40000000) != 0) {
    puVar1 = (undefined4 *)((int)puVar3 + 1);
    *(undefined1 *)puVar3 = 0;
  }
  return puVar1;
}


// ===== FUN_080076e8 @ 080076e8

undefined4 * FUN_080076e8(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
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
  if ((param_2 & 4) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar3 == 0) {
    return puVar2;
  }
  puVar1 = puVar2;
  if ((int)uVar3 < 0) {
    puVar1 = (undefined4 *)((int)puVar2 + 2);
    *(undefined2 *)puVar2 = 0;
  }
  puVar2 = puVar1;
  if ((uVar3 & 0x40000000) != 0) {
    puVar2 = (undefined4 *)((int)puVar1 + 1);
    *(undefined1 *)puVar1 = 0;
  }
  return puVar2;
}


// ===== FUN_08007740 @ 08007740

undefined4 FUN_08007740(void)

{
  return DAT_08007744;
}


// ===== FUN_08007750 @ 08007750

/* WARNING: Removing unreachable block (ram,0x08007764) */

longlong FUN_08007750(void)

{
  undefined1 local_10 [4];
  
  return ZEXT48(local_10) << 0x20;
}


// ===== FUN_08007778 @ 08007778

void FUN_08007778(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint local_18;
  
  local_18 = param_4;
  if (param_2 < param_1 + 0x10) {
    FUN_080078a8(0,&local_18,0x10);
    if (local_18 != param_2) {
      param_1 = local_18;
    }
    param_2 = local_18;
  }
  puVar1 = (uint *)FUN_08007740();
  *puVar1 = param_1;
  uVar2 = param_1 + 0x10;
  FUN_080077d6(param_1);
  if (param_2 == uVar2) {
    return;
  }
  FUN_0800783c(*puVar1,uVar2,param_2 - uVar2,local_18);
  return;
}


// ===== FUN_080077d6 @ 080077d6

void FUN_080077d6(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_1;
  return;
}


// ===== FUN_08007810 @ 08007810

undefined4 FUN_08007810(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0800787a();
  iVar2 = FUN_080078a0(param_2);
  if (iVar2 == 0) {
    return uVar1;
  }
  return 0xffffffff;
}


// ===== FUN_08007834 @ 08007834

undefined4 FUN_08007834(void)

{
  return DAT_08007838;
}


// ===== FUN_0800783c @ 0800783c

void FUN_0800783c(int *param_1,int *param_2,int param_3)

{
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
  FUN_080072bc(piVar1 + 1);
  return;
}


// ===== FUN_0800787a @ 0800787a

void FUN_0800787a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined4 uStack_38;
  int local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  
  local_2c = 0;
  local_34 = DAT_0800789c + 0x800788c;
  local_3c = param_4;
  uStack_38 = param_2;
  uStack_30 = param_1;
  FUN_08007438(auStack_40,param_3);
  return;
}


// ===== FUN_080078a0 @ 080078a0

byte FUN_080078a0(int param_1)

{
  return *(byte *)(param_1 + 0xc) & 0x80;
}


// ===== FUN_080078a8 @ 080078a8

void FUN_080078a8(void)

{
  int iVar1;
  
  iVar1 = FUN_0800791c();
  if (iVar1 == 0) {
    return;
  }
  FUN_08008eda();
  return;
}


// ===== FUN_080078b6 @ 080078b6

void FUN_080078b6(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 unaff_lr;
  uint *puVar3;
  
  uVar1 = FUN_08007834();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = unaff_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_08007238();
  puVar2 = (undefined4 *)*puVar3;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  return;
}


// ===== FUN_08007900 @ 08007900

void FUN_08007900(undefined4 param_1,undefined4 param_2)

{
  FUN_080071fa();
  FUN_08008eda(param_1,param_2);
  (*DAT_08007244)();
                    /* WARNING: Could not recover jumptable at 0x08007222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_08007248)();
  return;
}


// ===== FUN_0800791c @ 0800791c

undefined4 FUN_0800791c(int param_1)

{
  char *pcVar1;
  
  if (param_1 == 1) {
    pcVar1 = s___Heap_memory_corrupted_08007954;
  }
  else {
    pcVar1 = (char *)0x0;
  }
  FUN_0800796c(s_SIGRTMEM__Out_of_heap_memory_08007934,pcVar1);
  return 1;
}


// ===== FUN_0800796c @ 0800796c

void FUN_0800796c(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = '\n';
  for (; (FUN_08008edc(cVar1), param_1 != (char *)0x0 && (cVar1 = *param_1, cVar1 != '\0'));
      param_1 = param_1 + 1) {
  }
  for (; (param_2 != (char *)0x0 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    FUN_08008edc();
  }
  FUN_08008edc(10);
  return;
}


// ===== FUN_080079a0 @ 080079a0

void FUN_080079a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_08009ba4(DAT_080079e8,1);
  FUN_0800fc98(&local_10);
  local_c = CONCAT13(local_c._3_1_,0x30000);
  local_10 = 2;
  local_c = CONCAT22((short)((uint)local_c >> 0x10),0x400);
  FUN_0800fcb0(DAT_080079ec,&local_10);
  FUN_0800e5bc();
  FUN_08008f48();
  FUN_0800907c(DAT_080079f0,1);
  uVar1 = DAT_08013368;
  FUN_08009ba4(DAT_08013368,1);
  FUN_08009ba4(uVar1,1);
  uVar1 = DAT_0801336c;
  local_10 = 1;
  local_c = 0x3001800;
  FUN_0800fcb0(DAT_0801336c,&local_10);
  local_10 = 2;
  FUN_0800fcb0(uVar1,&local_10);
  return;
}


// ===== vec_5 @ 080079f4

void vec_5(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== vec_12 @ 08007a44

void vec_12(void)

{
  return;
}


// ===== FUN_08007a46 @ 08007a46

undefined8 FUN_08007a46(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  sVar2 = (short)param_3;
  uVar1 = param_3 >> 1;
  uVar7 = (uint)(sVar2 * 0x2c3) / 1000 + 1;
  iVar8 = param_1;
  iVar9 = param_2;
  uVar10 = param_3;
  FUN_080105b4(param_1 - param_3 & 0xffff,param_2,param_3 << 1,param_4,param_1,param_2,param_3);
  for (uVar6 = 1; uVar6 <= uVar7; uVar6 = uVar6 + 1) {
    if ((int)sVar2 * (int)sVar2 + uVar1 < param_3 * param_3 + uVar6 * uVar6) {
      if (uVar7 < param_3) {
        sVar3 = (short)uVar6 * 2 + -2;
        sVar4 = ((short)param_1 - (short)uVar6) + 1;
        FUN_080105b4(sVar4,param_2 + param_3 & 0xffff,sVar3,param_4,iVar8,iVar9,uVar10);
        FUN_080105b4(sVar4,param_2 - param_3 & 0xffff,sVar3,param_4);
      }
      param_3 = param_3 - 1;
    }
    iVar5 = (param_3 & 0x7fff) << 1;
    sVar3 = (short)param_1 - (short)param_3;
    FUN_080105b4(sVar3,param_2 + uVar6 & 0xffff,iVar5,param_4,iVar8,iVar9,uVar10);
    FUN_080105b4(sVar3,param_2 - uVar6 & 0xffff,iVar5,param_4);
  }
  return CONCAT44(iVar9,iVar8);
}


// ===== vec_3 @ 08007af8

void vec_3(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_08007afa @ 08007afa

void FUN_08007afa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_08008b1c(0x2a);
  FUN_08008ab8(param_1);
  FUN_08008ab8(param_3);
  FUN_08008b1c(0x2b);
  FUN_08008ab8(param_2);
  FUN_08008ab8(param_4);
  FUN_08008b1c(0x2c);
  return;
}


// ===== FUN_08007b34 @ 08007b34

void FUN_08007b34(uint param_1,uint param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_30;
  uint local_2c;
  
  param_3 = param_3 - param_1;
  iVar5 = 0;
  param_4 = param_4 - param_2;
  iVar4 = 0;
  if (param_3 < 1) {
    if (param_3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = -1;
      param_3 = -param_3;
    }
  }
  else {
    iVar2 = 1;
  }
  if (param_4 < 1) {
    if (param_4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
      param_4 = -param_4;
    }
  }
  else {
    iVar1 = 1;
  }
  if (param_4 < param_3) {
    iVar3 = param_3;
  }
  else {
    iVar3 = param_4;
  }
  local_30 = param_2;
  local_2c = param_1;
  for (uVar6 = 0; (int)uVar6 < iVar3 + 1; uVar6 = uVar6 + 1 & 0xffff) {
    FUN_08007dba(local_2c & 0xffff,local_30 & 0xffff,param_5);
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


// ===== FUN_08007bd0 @ 08007bd0

void FUN_08007bd0(uint param_1,uint param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_30;
  uint local_2c;
  
  param_3 = param_3 - param_1;
  iVar5 = 0;
  param_4 = param_4 - param_2;
  iVar4 = 0;
  if (param_3 < 1) {
    if (param_3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = -1;
      param_3 = -param_3;
    }
  }
  else {
    iVar2 = 1;
  }
  if (param_4 < 1) {
    if (param_4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
      param_4 = -param_4;
    }
  }
  else {
    iVar1 = 1;
  }
  if (param_4 < param_3) {
    iVar3 = param_3;
  }
  else {
    iVar3 = param_4;
  }
  local_30 = param_2;
  local_2c = param_1;
  for (uVar6 = 0; (int)uVar6 < iVar3 + 1; uVar6 = uVar6 + 1 & 0xffff) {
    FUN_08007dd0(local_2c & 0xffff,local_30 & 0xffff,param_5);
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


// ===== FUN_08007c6c @ 08007c6c

void FUN_08007c6c(int param_1,short param_2,short param_3,undefined2 param_4,undefined2 param_5,
                 int param_6)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  short sVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  uVar1 = *(ushort *)(param_1 + 2);
  uVar2 = *(ushort *)(param_1 + 4);
  pbVar9 = (byte *)(param_1 + 6);
  for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1 & 0xff) {
    pbVar10 = pbVar9;
    sVar5 = param_2;
    for (uVar7 = 0; uVar7 < (uVar1 & 0x7ff) >> 3; uVar7 = uVar7 + 1 & 0xff) {
      uVar8 = (uint)*pbVar10;
      bVar6 = 0;
      do {
        uVar4 = param_4;
        if ((-1 < (int)(uVar8 << 0x18)) || (uVar4 = param_5, param_6 != 0)) {
          FUN_08007dba(sVar5,param_3,uVar4);
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
      uVar8 = (uint)*pbVar10;
      for (uVar7 = 0; uVar7 < (uVar1 & 7); uVar7 = uVar7 + 1 & 0xff) {
        uVar4 = param_4;
        if ((-1 < (int)(uVar8 << 0x18)) || (uVar4 = param_5, param_6 != 0)) {
          FUN_08007dba(sVar5,param_3,uVar4);
        }
        sVar5 = sVar5 + 1;
        uVar8 = (uVar8 & 0x7f) << 1;
      }
    }
    param_3 = param_3 + 1;
  }
  return;
}


// ===== FUN_08007d20 @ 08007d20

void FUN_08007d20(int param_1,short param_2,short param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  uVar1 = *(ushort *)(param_1 + 2);
  uVar2 = *(ushort *)(param_1 + 4);
  pbVar8 = (byte *)(param_1 + 6);
  for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1 & 0xff) {
    pbVar9 = pbVar8;
    sVar4 = param_2;
    for (uVar6 = 0; uVar6 < (uVar1 & 0x7ff) >> 3; uVar6 = uVar6 + 1 & 0xff) {
      uVar7 = (uint)*pbVar9;
      bVar5 = 0;
      do {
        if ((int)(uVar7 << 0x18) < 0) {
          FUN_08007e1c(sVar4,param_3);
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
      uVar7 = (uint)*pbVar9;
      for (uVar6 = 0; uVar6 < (uVar1 & 7); uVar6 = uVar6 + 1 & 0xff) {
        if ((int)(uVar7 << 0x18) < 0) {
          FUN_08007e1c(sVar4,param_3);
        }
        sVar4 = sVar4 + 1;
        uVar7 = (uVar7 & 0x7f) << 1;
      }
    }
    param_3 = param_3 + 1;
  }
  return;
}


// ===== FUN_08007dba @ 08007dba

void FUN_08007dba(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_08007afa(param_1,param_2,param_1,param_2);
  FUN_08008ab8(param_3);
  return;
}


// ===== FUN_08007dd0 @ 08007dd0

void FUN_08007dd0(uint param_1,uint param_2,undefined2 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*DAT_08007e14;
  if ((((uVar1 * 10 <= param_2) && (param_2 <= (uVar1 + 1) * 10)) &&
      (uVar1 = param_2 + uVar1 * -10 & 0xffff, uVar1 < 10)) && (param_1 < 0x9e)) {
    *(undefined2 *)(DAT_08007e18 + uVar1 * 0x13c + param_1 * 2) = param_3;
  }
  return;
}


// ===== FUN_08007e1c @ 08007e1c

void FUN_08007e1c(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined8 uVar4;
  
  if (param_1 < 0xf1) {
    puVar3 = (uint *)(DAT_08007e40 + param_1 * 8);
    uVar1 = *puVar3;
    uVar2 = puVar3[1];
    uVar4 = FUN_080073f8(1,0,param_2);
    *puVar3 = uVar1 | (uint)uVar4;
    puVar3[1] = uVar2 | (uint)((ulonglong)uVar4 >> 0x20);
  }
  return;
}


// ===== FUN_08007e44 @ 08007e44

void FUN_08007e44(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_08007b34();
  FUN_08007b34(param_1,param_2,param_1,param_4,param_5);
  FUN_08007b34(param_1,param_4,param_3,param_4,param_5);
  FUN_08007b34(param_3,param_2,param_3,param_4,param_5);
  return;
}


// ===== FUN_08007e88 @ 08007e88

void FUN_08007e88(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_3 - param_5;
  uVar3 = param_1 + param_5;
  FUN_08007b34(uVar3 & 0xffff,param_2,uVar4 & 0xffff,param_2,param_6,param_1,param_2,param_3);
  uVar1 = param_4 - param_5;
  uVar2 = param_5 + param_2;
  FUN_08007b34(param_1,uVar2 & 0xffff,param_1,uVar1 & 0xffff,param_6);
  FUN_08007b34(uVar3 & 0xffff,param_4,uVar4 & 0xffff,param_4,param_6);
  FUN_08007b34(param_3,uVar2 & 0xffff,param_3,uVar1 + 1 & 0xffff,param_6);
  FUN_08007b34(uVar3 & 0xffff,param_2,param_1,uVar2 & 0xffff,param_6);
  FUN_08007b34(uVar4 & 0xffff,param_2,param_3,uVar2 & 0xffff,param_6);
  FUN_08007b34(param_1,uVar1 & 0xffff,uVar3 & 0xffff,param_4,param_6);
  FUN_08007b34(uVar4 & 0xffff,param_4,param_3,uVar1 & 0xffff,param_6);
  return;
}


// ===== FUN_08007f24 @ 08007f24

void FUN_08007f24(uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  FUN_08007afa();
  iVar1 = DAT_08007f90;
  FUN_08012b28(DAT_08007f90,1);
  uVar2 = DAT_08007f94;
  FUN_0800fc90(DAT_08007f94,0x4000);
  piVar4 = (int *)(DAT_08007f90 + 8);
  puVar5 = (undefined4 *)(DAT_08007f90 + 0xc);
  for (; param_2 <= param_4; param_2 = param_2 + 1 & 0xffff) {
    for (uVar3 = param_1; uVar3 <= param_3; uVar3 = uVar3 + 1 & 0xffff) {
      do {
      } while (-1 < *piVar4 << 0x1e);
      *puVar5 = param_5;
    }
  }
  FUN_08009cdc(10);
  FUN_0800fc94(uVar2,0x4000);
  FUN_08012b28(iVar1,0);
  return;
}


// ===== FUN_08007f98 @ 08007f98

void FUN_08007f98(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  for (; param_2 < param_4; param_2 = param_2 + 1 & 0xffff) {
    for (uVar1 = param_1; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
      FUN_08007e1c(uVar1,param_2);
    }
  }
  return;
}


// ===== FUN_08007fc8 @ 08007fc8

void FUN_08007fc8(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,
                 undefined4 param_6)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_08007f24(param_1,param_2,param_3,param_4 - 1U & 0xffff,param_6,param_1,param_2,param_3,param_4
              );
  for (uVar4 = 0; iVar3 = DAT_08008068, uVar4 < param_5; uVar4 = uVar4 + 1 & 0xff) {
    uVar5 = param_1 + uVar4;
    sVar1 = (((short)param_2 + (short)param_5) - (short)uVar4) + -1;
    FUN_08007b34(uVar5 & 0xffff,param_2,uVar5 & 0xffff,sVar1,*(undefined2 *)(DAT_08008068 + 0x1a));
    sVar2 = ((short)param_4 - ((short)param_5 - (short)uVar4)) + 1;
    FUN_08007b34(uVar5 & 0xffff,sVar2,uVar5 & 0xffff,param_4,*(undefined2 *)(iVar3 + 0x1a));
    uVar5 = (param_3 - param_1) + uVar5 + uVar4 * -2;
    FUN_08007b34(uVar5 & 0xffff,param_2,uVar5 & 0xffff,sVar1,*(undefined2 *)(iVar3 + 0x1a));
    FUN_08007b34(uVar5 & 0xffff,sVar2,uVar5 & 0xffff,param_4,*(undefined2 *)(iVar3 + 0x1a));
  }
  return;
}


// ===== FUN_0800806c @ 0800806c

void FUN_0800806c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = param_3;
  local_1c = param_4;
  FUN_08009ba4(DAT_080080ec,1);
  iVar3 = DAT_080080ec + 1;
  FUN_08009ba4(iVar3,1);
  FUN_08009ba4(iVar3,1);
  uVar1 = DAT_080080f0;
  local_1c = 0x3101800;
  local_20 = 0x100;
  FUN_0800fcb0(DAT_080080f0,&local_20);
  uVar2 = DAT_080080f4;
  local_20 = 0x1000;
  FUN_0800fcb0(DAT_080080f4,&local_20);
  local_20 = 0x4000;
  FUN_0800fcb0(uVar2,&local_20);
  FUN_0800fc94(uVar1,0x100);
  FUN_0800fc94(uVar2,0x1000);
  FUN_0800fc94(uVar2,0x4000);
  return;
}


// ===== FUN_080080f8 @ 080080f8

void FUN_080080f8(void)

{
  undefined4 uVar1;
  
  FUN_0800806c();
  FUN_08008c7c();
  uVar1 = DAT_08008298;
  FUN_0800fc90(DAT_08008298,0x100);
  FUN_08009d18(100);
  FUN_0800fc94(uVar1,0x100);
  FUN_08009d18(100);
  FUN_08008b1c(0x11);
  FUN_08009d18(0x78);
  FUN_08008b1c(0x36);
  FUN_08008aec(0xc0);
  FUN_08008b1c(0x3a);
  FUN_08008aec(5);
  FUN_08008b1c(0xb2);
  FUN_08008aec(0xc);
  FUN_08008aec(0xc);
  FUN_08008aec(0);
  FUN_08008aec(0x33);
  FUN_08008aec(0x33);
  FUN_08008b1c(0xb7);
  FUN_08008aec(0x35);
  FUN_08008b1c(0xbb);
  FUN_08008aec(0x32);
  FUN_08008b1c(0xc2);
  FUN_08008aec(1);
  FUN_08008b1c(0xc3);
  FUN_08008aec(0x15);
  FUN_08008b1c(0xc4);
  FUN_08008aec(0x20);
  FUN_08008b1c(0xc6);
  FUN_08008aec(0xf);
  FUN_08008b1c(0xd0);
  FUN_08008aec(0xa4);
  FUN_08008aec(0xa1);
  FUN_08008b1c(0xe0);
  FUN_08008aec(0xd0);
  FUN_08008aec(8);
  FUN_08008aec(0xe);
  FUN_08008aec(9);
  FUN_08008aec(9);
  FUN_08008aec(5);
  FUN_08008aec(0x31);
  FUN_08008aec(0x33);
  FUN_08008aec(0x48);
  FUN_08008aec(0x17);
  FUN_08008aec(0x14);
  FUN_08008aec(0x15);
  FUN_08008aec(0x31);
  FUN_08008aec(0x34);
  FUN_08008b1c(0xe1);
  FUN_08008aec(0xd0);
  FUN_08008aec(8);
  FUN_08008aec(0xe);
  FUN_08008aec(9);
  FUN_08008aec(9);
  FUN_08008aec(0x15);
  FUN_08008aec(0x31);
  FUN_08008aec(0x33);
  FUN_08008aec(0x48);
  FUN_08008aec(0x17);
  FUN_08008aec(0x14);
  FUN_08008aec(0x15);
  FUN_08008aec(0x31);
  FUN_08008aec(0x34);
  FUN_08008b1c(0x21);
  FUN_08008b1c(0x29);
  FUN_08007f24(0,0,0xf0,0x140,0);
  return;
}


// ===== FUN_0800829c @ 0800829c

void FUN_0800829c(uint param_1,uint param_2,int param_3,int param_4)

{
  FUN_08008b1c(0x2a);
  FUN_08008aec(param_1 >> 8);
  FUN_08008aec(param_1 & 0xff);
  FUN_08008aec((param_1 + param_3 & 0xffff) >> 8);
  FUN_08008aec(param_1 + param_3 & 0xff);
  FUN_08008b1c(0x2b);
  FUN_08008aec(param_2 >> 8);
  FUN_08008aec(param_2 & 0xff);
  FUN_08008aec((param_2 + param_4 & 0xffff) >> 8);
  FUN_08008aec(param_2 + param_4 & 0xff);
  FUN_08008b1c(0x2c);
  return;
}


// ===== FUN_080082f2 @ 080082f2

void FUN_080082f2(uint param_1,undefined4 param_2,byte *param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,undefined4 param_7)

{
  byte bVar1;
  
  do {
    while( true ) {
      bVar1 = *param_3;
      if (bVar1 == 0) {
        return;
      }
      if (0x7f < bVar1) break;
      FUN_080083fc(param_1,param_2,bVar1,param_4,param_5,param_6,param_7);
      param_1 = param_1 + (param_6 >> 1) & 0xffff;
      param_3 = param_3 + 1;
    }
    if (param_6 == 0xc) {
      FUN_080085e0(param_1,param_2,param_3,param_4,param_5,0xc,param_7);
    }
    else if (param_6 == 0x10) {
      FUN_080086d8(param_1,param_2,param_3,param_4,param_5,0x10,param_7);
    }
    else if (param_6 == 0x18) {
      FUN_080087cc(param_1,param_2,param_3,param_4,param_5,0x18,param_7);
    }
    else {
      if (param_6 != 0x20) {
        return;
      }
      FUN_08008988(param_1,param_2,param_3,param_4,param_5,0x20,param_7);
    }
    param_1 = param_1 + param_6 & 0xffff;
    param_3 = param_3 + 2;
  } while( true );
}


// ===== FUN_0800839e @ 0800839e

void FUN_0800839e(uint param_1,undefined4 param_2,byte *param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,undefined4 param_7)

{
  byte bVar1;
  
  while (bVar1 = *param_3, bVar1 != 0) {
    if (bVar1 < 0x80) {
      FUN_08008508(param_1,param_2,bVar1,param_4,param_5,param_6,param_7);
      param_1 = param_1 + (param_6 >> 1) & 0xffff;
      param_3 = param_3 + 1;
    }
    else {
      if (param_6 == 0x18) {
        FUN_080088c4(param_1,param_2,param_3,param_4,param_5,0x18,param_7);
      }
      param_1 = param_1 + param_6 & 0xffff;
      param_3 = param_3 + 2;
    }
  }
  return;
}


// ===== FUN_080083fc @ 080083fc

void FUN_080083fc(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,int param_7)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_30;
  
  uVar8 = param_6 >> 1;
  uVar9 = 0;
  uVar2 = param_3 - 0x20U & 0xff;
  uVar10 = param_1;
  FUN_08007afa(param_1,param_2,(param_1 + uVar8) - 1 & 0xffff,(param_2 + param_6) - 1 & 0xffff,
               param_1,param_1);
  uVar6 = 0;
  local_30 = param_2;
  do {
    if (((uint)((uVar8 & 7) != 0) + (param_6 >> 4)) * param_6 <= uVar6) {
      return;
    }
    if (param_6 == 0xc) {
      iVar3 = DAT_080084fc + uVar2 * 0xc;
    }
    else {
      if (param_6 == 0x10) {
        uVar7 = uVar2;
        iVar3 = DAT_08008500;
      }
      else {
        if (param_6 != 0x18) {
          if (param_6 != 0x20) {
            return;
          }
          iVar3 = DAT_080084f8 + uVar2 * 0x40;
          goto LAB_08008460;
        }
        uVar7 = uVar2 * 3;
        iVar3 = DAT_08008504;
      }
      iVar3 = iVar3 + uVar7 * 0x10;
    }
LAB_08008460:
    uVar7 = 0;
    bVar1 = *(byte *)(iVar3 + uVar6);
    do {
      uVar4 = 1 << uVar7 & (uint)bVar1;
      if (param_7 == 0) {
        if (uVar4 == 0) {
          uVar5 = param_5;
        }
        else {
          uVar5 = param_4;
        }
        FUN_08008ab8(uVar5);
        uVar9 = uVar9 + 1 & 0xff;
        if (uVar9 == uVar8 * (uVar9 / uVar8)) {
          uVar9 = 0;
          break;
        }
      }
      else {
        if (uVar4 != 0) {
          FUN_08007dba(param_1,local_30,param_4);
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
  } while( true );
}


// ===== FUN_08008508 @ 08008508

undefined8
FUN_08008508(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            uint param_6)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_34;
  
  uVar7 = param_6 >> 1;
  uVar2 = param_3 - 0x20U & 0xff;
  FUN_08007afa(param_1,param_2,(param_1 + uVar7) - 1 & 0xffff,(param_2 + param_6) - 1 & 0xffff);
  uVar5 = 0;
  uVar4 = param_1;
  local_34 = param_2;
  do {
    if (((uint)((uVar7 & 7) != 0) + (param_6 >> 4)) * param_6 <= uVar5) {
LAB_080085ca:
      return CONCAT44(local_34,param_1);
    }
    if (param_6 == 0xc) {
      iVar3 = DAT_080085d4 + uVar2 * 0xc;
    }
    else {
      if (param_6 == 0x10) {
        uVar6 = uVar2;
        iVar3 = DAT_080085d8;
      }
      else {
        if (param_6 != 0x18) {
          if (param_6 == 0x20) {
            iVar3 = DAT_080085d0 + uVar2 * 0x40;
            goto LAB_08008568;
          }
          goto LAB_080085ca;
        }
        uVar6 = uVar2 * 3;
        iVar3 = DAT_080085dc;
      }
      iVar3 = iVar3 + uVar6 * 0x10;
    }
LAB_08008568:
    uVar6 = 0;
    bVar1 = *(byte *)(iVar3 + uVar5);
    do {
      if ((1 << uVar6 & (uint)bVar1) != 0) {
        FUN_08007e1c(uVar4,local_34);
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
  } while( true );
}


// ===== FUN_080085e0 @ 080085e0

void FUN_080085e0(uint param_1,uint param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_30;
  
  uVar8 = 0;
  uVar5 = 0;
  uVar7 = param_1;
  local_30 = param_2;
  do {
    if ((*(char *)(DAT_080086d4 + uVar5 * 0x1a) == *param_3) &&
       (iVar1 = DAT_080086d4 + uVar5 * 0x1a, *(char *)(iVar1 + 1) == param_3[1])) {
      FUN_08007afa(uVar7,local_30,(uVar7 + param_6) - 1 & 0xffff,(local_30 + param_6) - 1 & 0xffff);
      for (uVar6 = 0; uVar6 < ((uint)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
          uVar6 = uVar6 + 1 & 0xff) {
        uVar4 = 0;
        do {
          uVar3 = (uint)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
          if (param_7 == 0) {
            if (uVar3 == 0) {
              uVar2 = param_5;
            }
            else {
              uVar2 = param_4;
            }
            FUN_08008ab8(uVar2);
            uVar8 = uVar8 + 1 & 0xff;
            if (uVar8 == param_6 * (uVar8 / param_6)) {
              uVar8 = 0;
              break;
            }
          }
          else {
            if (uVar3 != 0) {
              FUN_08007dba(uVar7,local_30,param_4);
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
  } while( true );
}


// ===== FUN_080086d8 @ 080086d8

void FUN_080086d8(uint param_1,uint param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_30;
  
  uVar8 = 0;
  uVar5 = 0;
  uVar7 = param_1;
  local_30 = param_2;
  do {
    if ((*(char *)(DAT_080087c8 + uVar5 * 0x22) == *param_3) &&
       (iVar1 = DAT_080087c8 + uVar5 * 0x22, *(char *)(iVar1 + 1) == param_3[1])) {
      FUN_08007afa(uVar7,local_30,(uVar7 + param_6) - 1 & 0xffff,(local_30 + param_6) - 1 & 0xffff);
      for (uVar6 = 0; uVar6 < ((uint)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
          uVar6 = uVar6 + 1 & 0xff) {
        uVar4 = 0;
        do {
          uVar3 = (uint)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
          if (param_7 == 0) {
            if (uVar3 == 0) {
              uVar2 = param_5;
            }
            else {
              uVar2 = param_4;
            }
            FUN_08008ab8(uVar2);
            uVar8 = uVar8 + 1 & 0xff;
            if (uVar8 == param_6 * (uVar8 / param_6)) {
              uVar8 = 0;
              break;
            }
          }
          else {
            if (uVar3 != 0) {
              FUN_08007dba(uVar7,local_30,param_4);
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
  } while( true );
}


// ===== FUN_080087cc @ 080087cc

void FUN_080087cc(uint param_1,uint param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_30;
  
  uVar8 = 0;
  uVar5 = 0;
  uVar7 = param_1;
  local_30 = param_2;
  do {
    if ((*(char *)(DAT_080088c0 + uVar5 * 0x4a) == *param_3) &&
       (iVar1 = DAT_080088c0 + uVar5 * 0x4a, *(char *)(iVar1 + 1) == param_3[1])) {
      FUN_08007afa(uVar7,local_30,(uVar7 + param_6) - 1 & 0xffff,(local_30 + param_6) - 1 & 0xffff);
      for (uVar6 = 0; uVar6 < ((uint)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
          uVar6 = uVar6 + 1 & 0xff) {
        uVar4 = 0;
        do {
          uVar3 = (uint)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
          if (param_7 == 0) {
            if (uVar3 == 0) {
              uVar2 = param_5;
            }
            else {
              uVar2 = param_4;
            }
            FUN_08008ab8(uVar2);
            uVar8 = uVar8 + 1 & 0xff;
            if (uVar8 == param_6 * (uVar8 / param_6)) {
              uVar8 = 0;
              break;
            }
          }
          else {
            if (uVar3 != 0) {
              FUN_08007dba(uVar7,local_30,param_4);
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
  } while( true );
}


// ===== FUN_080088c4 @ 080088c4

void FUN_080088c4(uint param_1,uint param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_30;
  
  uVar4 = 0;
  uVar2 = param_1;
  local_30 = param_2;
  do {
    if ((*(char *)(DAT_08008984 + uVar4 * 0x4a) == *param_3) &&
       (iVar1 = DAT_08008984 + uVar4 * 0x4a, *(char *)(iVar1 + 1) == param_3[1])) {
      FUN_08007afa(uVar2,local_30,(uVar2 + param_6) - 1 & 0xffff,(local_30 + param_6) - 1 & 0xffff);
      for (uVar5 = 0; uVar5 < ((uint)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
          uVar5 = uVar5 + 1 & 0xff) {
        uVar3 = 0;
        do {
          if (((uint)*(byte *)(iVar1 + uVar5 + 2) & 1 << uVar3) != 0) {
            FUN_08007e1c(uVar2,local_30);
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
  } while( true );
}


// ===== FUN_08008988 @ 08008988

void FUN_08008988(uint param_1,uint param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,int param_7)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_30;
  
  uVar8 = 0;
  uVar5 = 0;
  uVar7 = param_1;
  local_30 = param_2;
  do {
    if ((*(char *)(DAT_08008a78 + uVar5 * 0x82) == *param_3) &&
       (iVar1 = DAT_08008a78 + uVar5 * 0x82, *(char *)(iVar1 + 1) == param_3[1])) {
      FUN_08007afa(uVar7,local_30,(uVar7 + param_6) - 1 & 0xffff,(local_30 + param_6) - 1 & 0xffff);
      for (uVar6 = 0; uVar6 < ((uint)((param_6 & 7) != 0) + (param_6 >> 3)) * param_6;
          uVar6 = uVar6 + 1 & 0xff) {
        uVar4 = 0;
        do {
          uVar3 = (uint)*(byte *)(iVar1 + uVar6 + 2) & 1 << uVar4;
          if (param_7 == 0) {
            if (uVar3 == 0) {
              uVar2 = param_5;
            }
            else {
              uVar2 = param_4;
            }
            FUN_08008ab8(uVar2);
            uVar8 = uVar8 + 1 & 0xff;
            if (uVar8 == param_6 * (uVar8 / param_6)) {
              uVar8 = 0;
              break;
            }
          }
          else {
            if (uVar3 != 0) {
              FUN_08007dba(uVar7,local_30,param_4);
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
  } while( true );
}


// ===== FUN_08008a7c @ 08008a7c

void FUN_08008a7c(uint param_1,undefined4 param_2,char *param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,undefined4 param_7)

{
  for (; *param_3 != '\0'; param_3 = param_3 + 1) {
    FUN_08008508(param_1,param_2,*param_3,param_4,param_5,param_6,param_7);
    param_1 = param_1 + (param_6 >> 1) & 0xffff;
  }
  return;
}


// ===== FUN_08008ab8 @ 08008ab8

void FUN_08008ab8(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_08008ae8;
  FUN_0800fc90(DAT_08008ae8,0x4000);
  FUN_08008b60(param_1 >> 8);
  FUN_08008b60(param_1 & 0xff);
  FUN_08009cdc(5);
  FUN_0800fc94(uVar1,0x4000);
  return;
}


// ===== FUN_08008aec @ 08008aec

void FUN_08008aec(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_08008b18;
  FUN_0800fc90(DAT_08008b18,0x4000);
  FUN_08008b60(param_1);
  FUN_08009cdc(5);
  FUN_0800fc94(uVar1,0x4000);
  return;
}


// ===== FUN_08008b1c @ 08008b1c

void FUN_08008b1c(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_08008b5c;
  FUN_0800fc90(DAT_08008b5c,0x1000);
  FUN_0800fc90(uVar1,0x4000);
  FUN_08008b60(param_1);
  FUN_08009cdc(5);
  FUN_0800fc94(uVar1,0x4000);
  FUN_0800fc94(uVar1,0x1000);
  return;
}


// ===== FUN_08008b60 @ 08008b60

void FUN_08008b60(int param_1)

{
  do {
  } while (-1 < *DAT_08008b70 << 0x1e);
  DAT_08008b70[1] = param_1;
  return;
}


// ===== vec_4 @ 08008b74

void vec_4(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== vec_2 @ 08008b76

void vec_2(void)

{
  return;
}


// ===== vec_14 @ 08008b84

void vec_14(void)

{
  return;
}


// ===== FUN_08008b88 @ 08008b88

void FUN_08008b88(void)

{
  undefined2 uVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  char cVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_2c [4];
  
  pbVar2 = DAT_08008c50;
  uVar8 = 0;
  uVar10 = 0;
  if (*(short *)(DAT_08008c50 + 2) != 0) {
    pbVar2[2] = 0;
    uVar3 = DAT_08008c58;
    iVar5 = DAT_08008c54;
    pbVar2[3] = 0;
    do {
      uVar11 = FUN_08015054(*(undefined2 *)(iVar5 + uVar8 * 2));
      uVar11 = FUN_080150f4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0x66666666,uVar3);
      uVar11 = FUN_08015baa((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0xfffffff4);
      uVar12 = FUN_08015548(uVar10);
      FUN_08014ba4((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,
                   (int)((ulonglong)uVar11 >> 0x20));
      uVar10 = FUN_08014b40();
      uVar8 = uVar8 + 1 & 0xff;
    } while (uVar8 < 0x14);
    uVar10 = FUN_08015670(uVar10,DAT_08008c5c);
    iVar5 = FUN_08015c06(uVar10,1);
    uVar11 = FUN_08015548();
    uVar11 = FUN_0801535c((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0x66666666,DAT_08008c60);
    uVar11 = FUN_08014d1c((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_08008c64,DAT_08008c68);
    uVar11 = FUN_0801535c((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_08008c6c);
    FUN_080150f4((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_08008c70);
    uVar4 = FUN_08014fcc();
    *(undefined1 *)(DAT_08008c74 + 4) = uVar4;
    if (iVar5 < DAT_08008c78) {
      *pbVar2 = *pbVar2 + 1;
      iVar5 = FUN_08012178();
      if ((iVar5 == 0) && (2 < *pbVar2)) {
        cVar9 = '\n';
        FUN_08007fc8(0x13,0x6c,0xdc,0x7a,4,0xf800);
        FUN_08007f24(0x13,0x73,0xdc,0x8a,0xf800);
        iVar5 = DAT_0800c544;
        FUN_08007fc8(0x14,0x87,0xdb,199,4,*(undefined2 *)(DAT_0800c544 + 0x1a));
        FUN_08007e88(0x13,0x82,0xdc,200,4,0xf800);
        FUN_08007f24(0x1b,0x75,0x3d,0x84,*(undefined2 *)(iVar5 + 0x1a));
        FUN_08007f24(0x3e,0x7a,0x40,0x7f,*(undefined2 *)(iVar5 + 0x1a));
        FUN_080082f2(0x1e,0x76,&DAT_0800c548,0xf800,0xf800,0xc,1);
        uVar1 = *(undefined2 *)(iVar5 + 0x1c);
        if (*(char *)(iVar5 + 0x20) == '\0') {
          FUN_080082f2(0x60,0x74,&DAT_0800c568,uVar1,uVar1,0x10,1);
          pcVar7 = &DAT_0800c570;
        }
        else {
          FUN_080082f2(0x4c,0x74,s_Low_battery_0800c54c,uVar1,uVar1,0x10,1);
          pcVar7 = s_Shutdown_0800c558;
        }
        FUN_080082f2(0x58,0xae,pcVar7,0xf800,0xf800,0x10,1);
        uVar10 = DAT_0800c564;
        do {
          pcVar7 = &DAT_0800c584;
          while( true ) {
            FUN_08014af4(auStack_2c,pcVar7,cVar9,0x73);
            FUN_080082f2(0x66,0x91,auStack_2c,0xf800,*(undefined2 *)(iVar5 + 0x1a),0x18,0);
            FUN_08009d18(1000);
            if (cVar9 == '\x01') {
              FUN_08012aa0();
              FUN_0800fc90(uVar10,0x40);
            }
            iVar6 = FUN_08012178();
            if (iVar6 == 1) {
              *(undefined1 *)(iVar5 + 5) = 1;
              return;
            }
            cVar9 = cVar9 + -1;
            if (cVar9 == '\0') {
              return;
            }
            if (cVar9 == '\n') break;
            pcVar7 = s__d_c_0800c57c;
          }
        } while( true );
      }
    }
    else {
      *pbVar2 = 0;
    }
  }
  return;
}


// ===== FUN_08008c7c @ 08008c7c

undefined8 FUN_08008c7c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_1c = (undefined1)param_2;
  local_1b = (undefined1)((uint)param_2 >> 8);
  local_1a = (undefined1)((uint)param_2 >> 0x10);
  local_19 = (undefined1)((uint)param_2 >> 0x18);
  local_20 = (undefined1)param_1;
  local_1f = (undefined1)((uint)param_1 >> 8);
  local_1e = (undefined1)((uint)param_1 >> 0x10);
  local_1d = (undefined1)((uint)param_1 >> 0x18);
  local_18 = param_3;
  uStack_14 = param_4;
  FUN_08009ba4(DAT_08008cf0,1);
  FUN_08009ba4(DAT_08008cf4,1);
  uVar1 = DAT_08008cf8;
  uStack_14 = CONCAT13(3,CONCAT12(8,CONCAT11(0x28,(undefined1)uStack_14)));
  local_18 = 0xa000;
  FUN_0800fcb0(DAT_08008cf8,&local_18);
  FUN_0800fc94(uVar1,0xa000);
  uVar1 = DAT_08008cfc;
  local_20 = 3;
  local_1c = 0;
  local_1f = 1;
  local_1b = 1;
  local_1e = 1;
  local_1a = 1;
  local_19 = 1;
  local_1d = 0;
  FUN_08012b4a(DAT_08008cfc,&local_20);
  FUN_08012b1e(uVar1,1);
  return CONCAT17(local_19,CONCAT16(local_1a,CONCAT15(local_1b,CONCAT14(local_1c,CONCAT13(local_1d,
                                                  CONCAT12(local_1e,CONCAT11(local_1f,local_20))))))
                 );
}


// ===== vec_11 @ 08008d00

void vec_11(void)

{
  return;
}


// ===== vec_15 @ 08008d02

void vec_15(void)

{
  return;
}


// ===== FUN_08008d04 @ 08008d04

void FUN_08008d04(void)

{
  uint *puVar1;
  
  puVar1 = DAT_08008d68;
  DAT_08008d68[7] = DAT_08008d68[7] | 0x10000000;
  *(byte *)(DAT_08008d6c + 0x50) = *(byte *)(DAT_08008d6c + 0x50) | 4;
  puVar1[7] = puVar1[7] & 0xefffffff;
  *puVar1 = *puVar1 | 1;
  do {
  } while (-1 < (int)(*puVar1 << 0x1e));
  puVar1[1] = puVar1[1] & 0xfffffffc;
  do {
  } while ((puVar1[1] & 0xc) != 0);
  *puVar1 = *puVar1 & DAT_08008d70;
  puVar1[1] = 0;
  puVar1[0xb] = 0x1f10;
  puVar1[0xc] = 0x100000;
  puVar1[2] = 0x9f0000;
  *DAT_08008d74 = 0x8000000;
  return;
}


// ===== FUN_08008d78 @ 08008d78

void FUN_08008d78(void)

{
  char cVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar6;
  undefined4 extraout_r2_02;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar7;
  undefined4 extraout_r3_02;
  byte bVar8;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_lr;
  
  uVar2 = DAT_08008e38;
  iVar4 = FUN_080131e8(DAT_08008e38,1);
  if (iVar4 == 0) {
    return;
  }
  iVar5 = FUN_08010478();
  iVar4 = DAT_08008e3c;
  if (iVar5 != 0) {
    *(char *)(DAT_08008e3c + 1) = (char)iVar5;
  }
  FUN_080131cc(uVar2,1);
  pbVar3 = DAT_08008e40;
  bVar8 = *DAT_08008e40;
  *DAT_08008e40 = bVar8 + 1;
  uVar2 = DAT_08008e44;
  uVar6 = extraout_r2;
  uVar7 = extraout_r3;
  if (4 < (byte)(bVar8 + 1)) {
    *pbVar3 = 0;
    FUN_08008fcc(uVar2,1);
    FUN_08008fd6(uVar2,1);
    FUN_08008b88();
    uVar6 = extraout_r2_00;
    uVar7 = extraout_r3_00;
  }
  if ((*(char *)(iVar4 + 0xf) == '\x01') &&
     (bVar8 = pbVar3[1], pbVar3[1] = bVar8 + 1, 0x18 < (byte)(bVar8 + 1))) {
    pbVar3[1] = 0;
    *(undefined1 *)(iVar4 + 0xf) = 0;
    FUN_08009ba4(DAT_08008e48,0);
    uVar6 = extraout_r2_01;
    uVar7 = extraout_r3_01;
  }
  if (iVar5 == 0) {
LAB_08008df8:
    if (*(char *)(iVar4 + 0x22) == '\0') {
      return;
    }
    iVar5 = *(int *)(iVar4 + 0x10);
  }
  else {
    cVar1 = *(char *)(iVar4 + 0x22);
    if (cVar1 == '\x01') {
      iVar5 = 30000;
    }
    else if (cVar1 == '\x02') {
      iVar5 = DAT_08008e4c;
    }
    else {
      if (cVar1 != '\x03') goto LAB_08008df8;
      iVar5 = DAT_08008e50;
    }
    *(int *)(iVar4 + 0x10) = iVar5;
  }
  *(int *)(iVar4 + 0x10) = iVar5 + -1;
  uVar2 = DAT_0800944c;
  if (iVar5 == 0x1771) {
    bVar8 = 0;
    do {
      FUN_08009ba4(uVar2,1,uVar6,uVar7,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
      FUN_08009d18(0x96);
      FUN_08009ba4(uVar2,0);
      FUN_08009d18(0x96);
      bVar8 = bVar8 + 1;
      uVar6 = extraout_r2_02;
      uVar7 = extraout_r3_02;
    } while (bVar8 < 3);
    return;
  }
  if (iVar5 + -1 == 0) {
    FUN_08012aa0();
    return;
  }
  return;
}


// ===== FUN_08008e54 @ 08008e54

void FUN_08008e54(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = DAT_08008ec4;
  uVar4 = 0;
  iVar3 = FUN_0801354a(DAT_08008ec4,0x10);
  iVar2 = DAT_08008ec8;
  if (iVar3 == 0) {
    return;
  }
  FUN_0800e5b0(DAT_08008ec8,0);
  FUN_080134b4(uVar1,0x10);
  *(undefined4 *)(DAT_08008ec8 + 4) = 0xf;
  FUN_0800e5b0(iVar2,1);
  iVar2 = DAT_08008ecc;
  if (*(char *)(DAT_08008ecc + 2) == -3) {
    *(undefined1 *)(DAT_08008ed0 + 8) = 1;
    do {
      *(undefined1 *)(iVar2 + 0xf + uVar4) = *(undefined1 *)(iVar2 + uVar4);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0xd);
  }
  else {
    if (*(char *)(DAT_08008ed4 + 0x2a) != '\0') {
      *(char *)(DAT_08008ed4 + 0x2a) = *(char *)(DAT_08008ed4 + 0x2a) + -1;
      return;
    }
    if (*(char *)(DAT_08008ed4 + 0xe) == '\0') {
      *(undefined1 *)(DAT_08008ed0 + 9) = 1;
      return;
    }
  }
  return;
}


// ===== vec_6 @ 08008ed8

void vec_6(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_08008eda @ 08008eda

void FUN_08008eda(void)

{
  return;
}


// ===== FUN_08008edc @ 08008edc

void FUN_08008edc(void)

{
  return;
}


// ===== FUN_08008ede @ 08008ede

void FUN_08008ede(int param_1,byte *param_2)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffeff | (*param_2 & 1) << 8;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffd | (param_2[1] & 1) << 1;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffff7ff | (param_2[2] & 1) << 0xb;
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) & 0xff0fffff | (param_2[3] - 1 & 0xf) << 0x14;
  return;
}


// ===== FUN_08008f0a @ 08008f0a

void FUN_08008f0a(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 1;
  return;
}


// ===== FUN_08008f18 @ 08008f18

void FUN_08008f18(int param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 8;
  return;
}


// ===== FUN_08008f22 @ 08008f22

undefined4 FUN_08008f22(int param_1)

{
  if (*(int *)(param_1 + 8) << 0x1c < 0) {
    return 1;
  }
  return 0;
}


// ===== FUN_08008f30 @ 08008f30

void FUN_08008f30(int param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  return;
}


// ===== FUN_08008f3a @ 08008f3a

undefined4 FUN_08008f3a(int param_1)

{
  if (*(int *)(param_1 + 8) << 0x1d < 0) {
    return 1;
  }
  return 0;
}


// ===== FUN_08008f48 @ 08008f48

void FUN_08008f48(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_r3;
  undefined4 local_10;
  
  local_10 = in_r3;
  FUN_08009ba4(DAT_08008fc4,1);
  FUN_080099b8(2);
  FUN_08008f0a(&local_10);
  uVar1 = DAT_08008fc8;
  local_10 = 0x1000001;
  FUN_08008ede(DAT_08008fc8,&local_10);
  FUN_08008fe0(uVar1,1,1,7);
  FUN_08009054(uVar1,7,1);
  FUN_08008fcc(uVar1,1);
  FUN_08008fd6(uVar1,1);
  FUN_08008f18(uVar1);
  do {
    iVar2 = FUN_08008f22(uVar1);
  } while (iVar2 != 0);
  FUN_08008f30(uVar1);
  do {
    iVar2 = FUN_08008f3a(uVar1);
  } while (iVar2 != 0);
  return;
}


// ===== FUN_08008fcc @ 08008fcc

void FUN_08008fcc(int param_1,uint param_2)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffeff | (param_2 & 1) << 8;
  return;
}


// ===== FUN_08008fd6 @ 08008fd6

void FUN_08008fd6(int param_1,uint param_2)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe | param_2 & 1;
  return;
}


// ===== FUN_08008fe0 @ 08008fe0

void FUN_08008fe0(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  if (param_2 < 10) {
    *(uint *)(param_1 + 0x10) =
         param_4 << (param_2 * 3 & 0xff) | *(uint *)(param_1 + 0x10) & ~(7 << (param_2 * 3 & 0xff));
  }
  else {
    uVar1 = (param_2 - 10) * 3;
    *(uint *)(param_1 + 0xc) =
         param_4 << (uVar1 & 0xff) | *(uint *)(param_1 + 0xc) & ~(7 << (uVar1 & 0xff));
  }
  if (0xc < param_3) {
    uVar1 = (param_3 - 0xd) * 5;
    *(uint *)(param_1 + 0x2c) =
         param_2 << (uVar1 & 0xff) | *(uint *)(param_1 + 0x2c) & ~(0x1f << (uVar1 & 0xff));
    return;
  }
  if (param_3 < 7) {
    uVar1 = (param_3 - 1) * 5;
    *(uint *)(param_1 + 0x34) =
         param_2 << (uVar1 & 0xff) | *(uint *)(param_1 + 0x34) & ~(0x1f << (uVar1 & 0xff));
    return;
  }
  uVar1 = (param_3 - 7) * 5;
  *(uint *)(param_1 + 0x30) =
       param_2 << (uVar1 & 0xff) | *(uint *)(param_1 + 0x30) & ~(0x1f << (uVar1 & 0xff));
  return;
}


// ===== FUN_08009054 @ 08009054

void FUN_08009054(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (param_2 < 8) {
    uVar1 = *(uint *)(param_1 + 8) & 0xfdffffff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 8) | 0x2000000;
  }
  *(uint *)(param_1 + 8) = uVar1;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfff1ffff | (param_2 & 7) << 0x11;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffefffff | (param_3 & 1) << 0x14;
  return;
}


// ===== FUN_0800907c @ 0800907c

void FUN_0800907c(int param_1,uint param_2)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffbfffff | (param_2 & 1) << 0x16;
  return;
}


// ===== FUN_08009088 @ 08009088

void FUN_08009088(void)

{
  if (*(ushort *)(DAT_08009098 + 0xc) < 0x9e) {
    *(ushort *)(DAT_08009098 + 0xc) = *(ushort *)(DAT_08009098 + 0xc) + 1;
  }
  return;
}


// ===== FUN_0800909c @ 0800909c

void FUN_0800909c(void)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0800917c;
  iVar1 = DAT_08009178;
  if (*(char *)(DAT_08009178 + 2) == '\x02') {
    iVar3 = FUN_08012868(0x15);
    if (iVar3 == 1) {
      uVar2 = *(undefined1 *)(iVar4 + 0x24);
      goto LAB_08009174;
    }
  }
  else {
    switch(*(undefined1 *)(DAT_0800917c + 0x24)) {
    case 0:
      iVar4 = FUN_08012868(0xc);
      if (iVar4 == 1) {
        uVar2 = 0;
LAB_08009174:
        *(undefined1 *)(iVar1 + 3) = uVar2;
        return;
      }
      break;
    case 1:
      iVar4 = FUN_08012868(0xd);
      uVar2 = 1;
      if (iVar4 == 1) goto LAB_08009174;
      break;
    case 2:
      iVar4 = FUN_08012868(0xb);
      if (iVar4 == 1) {
        uVar2 = 2;
        goto LAB_08009174;
      }
      break;
    case 3:
      iVar4 = FUN_08012868(0x14);
      if (iVar4 == 1) {
        uVar2 = 3;
        goto LAB_08009174;
      }
      break;
    case 4:
      iVar4 = FUN_08012868(0xe);
      if (iVar4 == 1) {
        uVar2 = 4;
        goto LAB_08009174;
      }
      break;
    case 5:
      iVar4 = FUN_08012868(10);
      if (iVar4 == 1) {
        uVar2 = 5;
        goto LAB_08009174;
      }
      break;
    case 6:
      iVar4 = FUN_08012868(0xf);
      if (iVar4 == 1) {
        uVar2 = 6;
        goto LAB_08009174;
      }
      break;
    case 7:
      iVar4 = FUN_08012868(0x12);
      if (iVar4 == 1) {
        uVar2 = 7;
        goto LAB_08009174;
      }
      break;
    case 8:
      iVar4 = FUN_08012868(0x13);
      if (iVar4 == 1) {
        uVar2 = 8;
        goto LAB_08009174;
      }
      break;
    case 9:
      iVar4 = FUN_08012868(9);
      if (iVar4 == 1) {
        uVar2 = 9;
        goto LAB_08009174;
      }
      break;
    case 10:
      iVar4 = FUN_08012868(0x10);
      if (iVar4 == 1) {
        uVar2 = 10;
        goto LAB_08009174;
      }
      break;
    case 0xb:
      iVar4 = FUN_08012868(0x11);
      if (iVar4 == 1) {
        uVar2 = 0xb;
        goto LAB_08009174;
      }
    }
  }
  return;
}


// ===== FUN_08009180 @ 08009180

int FUN_08009180(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = param_2 + 3U & 0xfffffffc;
  if (uVar1 <= *(uint *)(param_1 + 0x70)) {
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) - uVar1;
    iVar2 = *(int *)(param_1 + 0x6c);
    *(uint *)(param_1 + 0x6c) = uVar1 + iVar2;
  }
  return iVar2;
}


// ===== FUN_0800919c @ 0800919c

int FUN_0800919c(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = (uint)*(byte *)(param_1 + 3);
  iVar2 = *param_1;
  pbVar4 = (byte *)param_1[1];
  uVar3 = (uint)*pbVar4;
  iVar6 = 0;
  bVar1 = false;
  do {
    if (uVar5 == 0) {
      if (iVar2 == 0) {
        pbVar4 = (byte *)param_1[2];
        iVar2 = (*(code *)param_1[0x1d])(param_1,pbVar4,0x200);
        if (iVar2 == 0) {
          return -2;
        }
      }
      else {
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
LAB_080091f0:
        uVar5 = 0x80;
        goto LAB_080091f2;
      }
      uVar3 = (uint)*pbVar4;
      if (uVar3 != 0xff) goto LAB_080091f0;
      bVar1 = true;
    }
    else {
LAB_080091f2:
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
  } while( true );
}


// ===== FUN_08009218 @ 08009218

void FUN_08009218(int *param_1,undefined1 *param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  uint uVar3;
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
    iVar4 = DAT_080093fc;
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
    *param_2 = *(undefined1 *)(iVar4 + ((iVar8 + iVar10 & 0x3ffffU) >> 8));
    param_2[7] = *(undefined1 *)(iVar4 + ((iVar8 - iVar10 & 0x3ffffU) >> 8));
    param_2[1] = *(undefined1 *)(iVar4 + ((iVar13 + iVar7 & 0x3ffffU) >> 8));
    param_2[6] = *(undefined1 *)(iVar4 + ((iVar13 - iVar7 & 0x3ffffU) >> 8));
    puVar2 = param_2 + 4;
    param_2[2] = *(undefined1 *)(iVar4 + ((iVar5 + iVar9 & 0x3ffffU) >> 8));
    param_2[5] = *(undefined1 *)(iVar4 + ((iVar5 - iVar9 & 0x3ffffU) >> 8));
    param_2[3] = *(undefined1 *)(iVar4 + ((iVar11 + iVar6 & 0x3ffffU) >> 8));
    uVar3 = uVar3 + 1;
    param_2 = param_2 + 8;
    *puVar2 = *(undefined1 *)(iVar4 + ((iVar11 - iVar6 & 0x3ffffU) >> 8));
    piVar1 = piVar1 + 8;
  } while (uVar3 < 8);
  return;
}


// ===== FUN_08009400 @ 08009400

undefined4 FUN_08009400(short *param_1,short *param_2,uint param_3)

{
  bool bVar1;
  
  while( true ) {
    bVar1 = param_3 == 0;
    param_3 = param_3 - 1 & 0xffff;
    if (bVar1) {
      return 1;
    }
    if (*param_1 != *param_2) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return 0;
}


// ===== FUN_08009450 @ 08009450

void FUN_08009450(void)

{
  *(undefined1 *)(DAT_08009460 + 0xf) = 1;
  FUN_08009ba4(DAT_08009464,1);
  return;
}


// ===== FUN_08009468 @ 08009468

undefined8 FUN_08009468(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 uStack_29;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar1 = DAT_08009524;
  local_2c = (undefined1)param_2;
  local_2b = (undefined1)((uint)param_2 >> 8);
  local_2a = (undefined1)((uint)param_2 >> 0x10);
  uStack_29 = (undefined1)((uint)param_2 >> 0x18);
  local_30 = (undefined1)param_1;
  local_2f = (undefined1)((uint)param_1 >> 8);
  local_2e = (undefined1)((uint)param_1 >> 0x10);
  local_2d = (undefined1)((uint)param_1 >> 0x18);
  local_28 = param_3;
  local_24 = param_4;
  FUN_08009ba4(DAT_08009524,1);
  FUN_08009ba4(DAT_08009528,1);
  FUN_0800fc98(&local_28);
  local_28 = 0x100;
  local_24 = 0x1080400;
  FUN_0800fcb0(DAT_0800952c,&local_28);
  uVar2 = DAT_08009530;
  FUN_0801318c(DAT_08009530,param_1,param_2);
  FUN_080131b8(uVar2,0);
  FUN_080132f8(&local_30);
  local_30 = 7;
  local_2b = 1;
  local_2d = 1;
  local_2f = 1;
  local_2a = 1;
  local_2c = 0;
  local_2e = 0;
  FUN_0801322e(uVar2,4,&local_30);
  FUN_0801319a(uVar2,4,param_3);
  FUN_080131fc(uVar2,4,1);
  FUN_08013314(uVar2,1);
  FUN_080131c2(uVar2,1);
  FUN_08009ba4(uVar1,0);
  return CONCAT17(uStack_29,
                  CONCAT16(local_2a,CONCAT15(local_2b,CONCAT14(local_2c,CONCAT13(local_2d,CONCAT12(
                                                  local_2e,CONCAT11(local_2f,local_30)))))));
}


// ===== FUN_08009534 @ 08009534

void FUN_08009534(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_08015548();
  uVar1 = FUN_080150f4((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_08009554,DAT_08009558);
  FUN_08014ba4((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,DAT_0800955c);
  FUN_08014b40();
  return;
}


// ===== FUN_08009560 @ 08009560

undefined4 FUN_08009560(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  iVar3 = FUN_0801191c(param_1);
  if (iVar3 != 0) {
    return 4;
  }
  iVar3 = FUN_08010604(param_1 + 0x22e);
  cVar1 = *(char *)(param_1 + 0x30);
  if (((cVar1 == -0x15) || (cVar1 == -0x17)) || (cVar1 == -0x18)) {
    if ((iVar3 == 0xaa55) && (iVar4 = FUN_08007506(param_1 + 0x82,s_FAT32_08009624,8), iVar4 == 0))
    {
      return 0;
    }
    uVar5 = FUN_08010604(param_1 + 0x3b);
    bVar2 = *(byte *)(param_1 + 0x3d);
    if ((((((uVar5 & uVar5 - 1) == 0) && (0xfff < uVar5)) &&
         ((uVar5 < 0x1001 &&
          ((((bVar2 != 0 && ((bVar2 & bVar2 - 1) == 0)) &&
            (iVar4 = FUN_08010604(param_1 + 0x3e), iVar4 != 0)) &&
           ((*(byte *)(param_1 + 0x40) - 1 < 2 && (iVar4 = FUN_08010604(param_1 + 0x41), iVar4 != 0)
            ))))))) &&
        ((uVar5 = FUN_08010604(param_1 + 0x43), 0x7f < uVar5 ||
         (uVar5 = FUN_080105ee(param_1 + 0x50), 0xffff < uVar5)))) &&
       (iVar4 = FUN_08010604(param_1 + 0x46), iVar4 != 0)) {
      return 0;
    }
  }
  if (iVar3 == 0xaa55) {
    return 2;
  }
  return 3;
}


// ===== FUN_08009630 @ 08009630

int FUN_08009630(int *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  piVar1 = (int *)param_1[10];
  uVar2 = (param_2 >> 0xc) / (uint)*(ushort *)(*param_1 + 10);
  while( true ) {
    uVar3 = piVar1[1];
    piVar1 = piVar1 + 2;
    if (uVar3 == 0) {
      return 0;
    }
    if (uVar2 < uVar3) break;
    uVar2 = uVar2 - uVar3;
  }
  return *piVar1 + uVar2;
}


// ===== FUN_08009654 @ 08009654

int FUN_08009654(int param_1,int param_2)

{
  if (param_2 - 2U < *(int *)(param_1 + 0x14) - 2U) {
    return (uint)*(ushort *)(param_1 + 10) * (param_2 - 2U) + *(int *)(param_1 + 0x28);
  }
  return 0;
}


// ===== FUN_0800966c @ 0800966c

void FUN_0800966c(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 local_18 [3];
  
  iVar2 = 0;
  local_18[0] = param_2;
  local_18[1] = param_3;
  local_18[2] = param_4;
  while( true ) {
    uVar1 = (uint)*param_1;
    if (uVar1 == 0) break;
    if (((uVar1 - 0x30 < 10) || (uVar1 == 0x2e)) || (uVar1 == 0x2d)) {
      *(byte *)((int)local_18 + iVar2) = *param_1;
      iVar2 = iVar2 + 1;
    }
    param_1 = param_1 + 1;
  }
  *(undefined1 *)((int)local_18 + iVar2) = 0;
  FUN_0800969c(local_18);
  return;
}


// ===== FUN_0800969c @ 0800969c

void FUN_0800969c(char *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  iVar8 = 0;
  uVar9 = 1;
  iVar7 = 0;
  bVar1 = false;
  iVar6 = 1;
  iVar4 = 0;
  if (*param_1 == '-') {
    uVar9 = 0xffffffff;
  }
  else if (*param_1 != '+') goto LAB_080096dc;
  param_1 = param_1 + 1;
LAB_080096dc:
  for (; uVar5 = (uint)(byte)param_1[iVar4], uVar5 != 0; iVar4 = iVar4 + 1) {
    if (uVar5 == 0x2e) {
      bVar1 = true;
    }
    else if (bVar1) {
      iVar7 = iVar7 * 10 + -0x30 + uVar5;
      iVar6 = iVar6 * 10;
    }
    else {
      iVar8 = iVar8 * 10 + -0x30 + uVar5;
    }
  }
  uVar2 = FUN_0801586c(iVar6);
  uVar3 = FUN_0801586c(iVar7);
  uVar2 = FUN_08015670(uVar3,uVar2);
  uVar3 = FUN_0801586c(iVar8);
  uVar2 = FUN_080155a0(uVar3,uVar2);
  uVar9 = FUN_0801586c(uVar9);
  FUN_080158c4(uVar9,uVar2);
  return;
}


// ===== FUN_08009726 @ 08009726

uint FUN_08009726(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (param_2 == 0) {
    uVar1 = *(uint *)(iVar4 + 0xc);
    if ((uVar1 == 0) || (*(uint *)(iVar4 + 0x14) <= uVar1)) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = FUN_0800fae4();
    if (uVar1 < 2) {
      return 1;
    }
    if (uVar1 == 0xffffffff) {
      return 0xffffffff;
    }
    if (uVar1 < *(uint *)(iVar4 + 0x14)) {
      return uVar1;
    }
    uVar1 = param_2;
  }
  if (*(int *)(iVar4 + 0x10) != 0) {
    if (uVar1 == param_2) {
      uVar3 = uVar1 + 1;
      if (*(uint *)(iVar4 + 0x14) <= uVar3) {
        uVar3 = 2;
      }
      iVar2 = FUN_0800fae4(param_1,uVar3);
      if (iVar2 == 1) {
        return 1;
      }
      if (iVar2 == -1) {
        return 0xffffffff;
      }
      if (iVar2 == 0) {
        if (uVar3 != 0) {
LAB_080097bc:
          uVar1 = 0xffffffff;
          iVar2 = FUN_08012078(iVar4,uVar3,0xffffffff);
          if ((iVar2 == 0) &&
             ((param_2 == 0 || (iVar2 = FUN_08012078(iVar4,param_2,uVar3), iVar2 == 0)))) {
            *(uint *)(iVar4 + 0xc) = uVar3;
            if (*(uint *)(iVar4 + 0x10) <= *(int *)(iVar4 + 0x14) - 2U) {
              *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) - 1;
            }
            *(byte *)(iVar4 + 4) = *(byte *)(iVar4 + 4) | 1;
          }
          else {
            if (iVar2 != 1) {
              uVar1 = 1;
            }
            uVar3 = uVar1;
          }
          return uVar3;
        }
      }
      else {
        uVar3 = *(uint *)(iVar4 + 0xc);
        if ((1 < uVar3) && (uVar3 < *(uint *)(iVar4 + 0x14))) {
          uVar1 = uVar3;
        }
      }
    }
    uVar3 = uVar1;
    do {
      uVar3 = uVar3 + 1;
      if ((*(uint *)(iVar4 + 0x14) <= uVar3) && (uVar3 = 2, uVar1 < 2)) {
        return 0;
      }
      iVar2 = FUN_0800fae4(param_1,uVar3);
      if (iVar2 == 0) goto LAB_080097bc;
      if (iVar2 == 1) {
        return 1;
      }
      if (iVar2 == -1) {
        return 0xffffffff;
      }
    } while (uVar3 != uVar1);
  }
  return 0;
}


// ===== FUN_08009800 @ 08009800

undefined8 FUN_08009800(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  
  do {
    if (param_3 == 0) {
      uVar7 = 0;
LAB_080098a6:
      return CONCAT44(param_1,uVar7);
    }
    if (param_3 < 0x11) {
LAB_080098b6:
      uVar7 = 6;
      goto LAB_080098a6;
    }
    bVar1 = *param_2;
    if ((bVar1 & 0xee) != 0) goto LAB_080098b6;
    iVar3 = FUN_08009180(param_1,0x10);
    if (iVar3 == 0) {
LAB_080098a4:
      uVar7 = 3;
      goto LAB_080098a6;
    }
    iVar11 = param_1 + (bVar1 & 0xf) * 8 + (uint)(bVar1 >> 4) * 4;
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
    iVar5 = FUN_08009180(param_1,uVar10 * 2);
    if (iVar5 == 0) goto LAB_080098a4;
    uVar4 = 0;
    uVar8 = 0;
    iVar9 = 0;
    *(int *)(iVar11 + 0x34) = iVar5;
    do {
      uVar12 = (uint)*(byte *)(iVar3 + uVar8);
      while (bVar13 = uVar12 != 0, uVar12 = uVar12 - 1, bVar13) {
        *(short *)(iVar5 + iVar9 * 2) = (short)uVar4;
        uVar4 = uVar4 + 1 & 0xffff;
        iVar9 = iVar9 + 1;
      }
      uVar8 = uVar8 + 1;
      uVar4 = (uVar4 & 0x7fff) << 1;
    } while (uVar8 < 0x10);
    if (param_3 - 0x11 < uVar10) goto LAB_080098b6;
    param_3 = (param_3 - 0x11) - uVar10;
    pbVar6 = (byte *)FUN_08009180(param_1,uVar10);
    if (pbVar6 == (byte *)0x0) goto LAB_080098a4;
    *(byte **)(iVar11 + 0x44) = pbVar6;
    for (uVar4 = 0; uVar4 < uVar10; uVar4 = uVar4 + 1) {
      if ((bVar1 >> 4 == 0) && (0xb < *param_2)) goto LAB_080098b6;
      *pbVar6 = *param_2;
      pbVar6 = pbVar6 + 1;
      param_2 = param_2 + 1;
    }
  } while( true );
}


// ===== FUN_080098cc @ 080098cc

undefined4 FUN_080098cc(int param_1,int *param_2)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  pcVar3 = (char *)(param_1 + 0x20);
  iVar11 = *param_2;
  FUN_08007694(pcVar3,0xb,0x20);
  uVar12 = 0;
  uVar4 = 8;
  iVar6 = 0;
  while( true ) {
    bVar8 = *(byte *)(iVar11 + iVar6);
    uVar9 = (uint)bVar8;
    iVar10 = iVar6 + 1;
    if (uVar9 < 0x21) break;
    if ((uVar9 == 0x2f) || (uVar9 == 0x5c)) goto LAB_0800990e;
    if ((uVar9 == 0x2e) || (uVar4 <= uVar12)) {
      if ((uVar4 == 0xb) || (uVar9 != 0x2e)) goto LAB_0800996e;
      uVar12 = 8;
      uVar4 = 0xb;
      iVar6 = iVar10;
    }
    else {
      iVar5 = FUN_08009cb0(uVar9);
      if (iVar5 == 0) {
        iVar6 = FUN_080074f2(&DAT_080099a8,uVar9);
        if (iVar6 != 0) goto LAB_0800996e;
        if (uVar9 - 0x61 < 0x1a) {
          bVar8 = bVar8 - 0x20;
        }
        pcVar3[uVar12] = bVar8;
        uVar12 = uVar12 + 1;
      }
      else {
        cVar1 = *(char *)(iVar11 + iVar10);
        iVar10 = iVar6 + 2;
        iVar6 = FUN_08009cc6(cVar1);
        if ((iVar6 == 0) || (uVar4 - 1 <= uVar12)) goto LAB_0800996e;
        pcVar3[uVar12] = bVar8;
        pcVar3[uVar12 + 1] = cVar1;
        uVar12 = uVar12 + 2;
      }
      iVar6 = iVar10;
    }
  }
LAB_08009918:
  *param_2 = iVar11 + iVar10;
  if (uVar12 == 0) {
LAB_0800996e:
    uVar7 = 6;
  }
  else {
    if (*pcVar3 == -0x1b) {
      *pcVar3 = '\x05';
    }
    if ((uVar9 < 0x21) || (*(byte *)(iVar11 + iVar10) < 0x21)) {
      uVar2 = 4;
    }
    else {
      uVar2 = 0;
    }
    *(undefined1 *)(param_1 + 0x2b) = uVar2;
    uVar7 = 0;
  }
  return uVar7;
LAB_0800990e:
  for (; (*(char *)(iVar11 + iVar10) == '/' || (*(char *)(iVar11 + iVar10) == '\\'));
      iVar10 = iVar10 + 1) {
  }
  goto LAB_08009918;
}


// ===== FUN_080099b8 @ 080099b8

void FUN_080099b8(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_080099d0;
  *(uint *)(DAT_080099d0 + 4) = *(uint *)(DAT_080099d0 + 4) & 0xffff3fff | (param_1 & 3) << 0xe;
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xefffffff | (param_1 >> 2 & 1) << 0x1c;
  return;
}


// ===== FUN_080099d4 @ 080099d4

void FUN_080099d4(uint param_1)

{
  *(uint *)(DAT_080099e0 + 4) = *(uint *)(DAT_080099e0 + 4) & 0xffffff0f | (param_1 & 0xf) << 4;
  return;
}


// ===== FUN_080099e4 @ 080099e4

void FUN_080099e4(uint param_1)

{
  *(uint *)(DAT_080099f0 + 4) = *(uint *)(DAT_080099f0 + 4) & 0xfffff8ff | (param_1 & 7) << 8;
  return;
}


// ===== FUN_080099f4 @ 080099f4

void FUN_080099f4(uint param_1)

{
  *(uint *)(DAT_08009a00 + 4) = *(uint *)(DAT_08009a00 + 4) & 0xffffc7ff | (param_1 & 7) << 0xb;
  return;
}


// ===== FUN_08009a04 @ 08009a04

void FUN_08009a04(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *(uint *)(DAT_08009a1c + 0x54) | 0x30;
  }
  else {
    uVar1 = *(uint *)(DAT_08009a1c + 0x54) & 0xffffffcf;
  }
  *(uint *)(DAT_08009a1c + 0x54) = uVar1;
  return;
}


// ===== FUN_08009a20 @ 08009a20

void FUN_08009a20(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = *DAT_08009a60 & 0xfffffffe | param_2 & 1;
    break;
  case 1:
    uVar1 = *DAT_08009a60 & 0xfffeffff | (param_2 & 1) << 0x10;
    break;
  case 2:
    uVar1 = *DAT_08009a60 & 0xfeffffff | (param_2 & 1) << 0x18;
    break;
  case 3:
    DAT_08009a60[8] = DAT_08009a60[8] & 0xfffffffe | param_2 & 1;
    return;
  case 4:
    DAT_08009a60[9] = DAT_08009a60[9] & 0xfffffffe | param_2 & 1;
    return;
  default:
    goto switchD_08009a26_default;
  }
  *DAT_08009a60 = uVar1;
switchD_08009a26_default:
  return;
}


// ===== FUN_08009a64 @ 08009a64

void FUN_08009a64(uint *param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = FUN_08009ca0();
  iVar2 = DAT_08009b4c;
  uVar4 = DAT_08009b48;
  if (iVar3 == 0) {
    if ((*(int *)(DAT_08009b4c + 0x54) << 0x16 < 0) && (*(int *)(DAT_08009b4c + 0x30) << 6 < 0)) {
      uVar4 = DAT_08009b50;
    }
  }
  else if ((iVar3 != 1) && (iVar3 == 2)) {
    iVar3 = *(int *)(DAT_08009b4c + 4) << 0xf;
    if (*(int *)(DAT_08009b4c + 0x2c) < 0) {
      if ((-1 < iVar3) || (*(int *)(DAT_08009b4c + 4) << 0xe < 0)) {
        uVar4 = DAT_08009b54;
      }
      lVar1 = (ulonglong)uVar4 * (ulonglong)((*(uint *)(DAT_08009b4c + 0x2c) & 0x1ffff) >> 8);
      uVar4 = FUN_0800730a((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),
                           ((*(uint *)(DAT_08009b4c + 0x2c) & 0xff) >> 4) <<
                           (*(uint *)(DAT_08009b4c + 0x2c) & 7),0);
    }
    else {
      uVar4 = (*(uint *)(DAT_08009b4c + 4) & 0x3fffff) >> 0x12;
      uVar6 = (*(uint *)(DAT_08009b4c + 4) & 0x7fffffff) >> 0x1d;
      if ((uVar6 == 0) && (uVar4 != 0xf)) {
        iVar5 = uVar4 + 2;
      }
      else {
        iVar5 = uVar4 + uVar6 * 0x10 + 1;
      }
      if ((iVar3 < 0) && (-1 < *(int *)(DAT_08009b4c + 4) << 0xe)) {
        uVar4 = DAT_08009b48;
      }
      else {
        uVar4 = DAT_08009b54;
      }
      uVar4 = uVar4 * iVar5;
    }
  }
  *param_1 = uVar4;
  uVar4 = *param_1 >> *(sbyte *)(DAT_08009b58 + ((*(uint *)(iVar2 + 4) & 0xff) >> 4));
  param_1[1] = uVar4;
  iVar3 = DAT_08009b58;
  param_1[3] = uVar4 >> *(sbyte *)(DAT_08009b58 + -0x18 + ((*(uint *)(iVar2 + 4) & 0x7ff) >> 8));
  uVar4 = uVar4 >> *(sbyte *)(iVar3 + -0x10 + ((*(uint *)(iVar2 + 4) & 0x3fff) >> 0xb));
  param_1[2] = uVar4;
  param_1[4] = uVar4 / *(byte *)(DAT_08009b58 + -8 +
                                ((*(uint *)(iVar2 + 4) & 0xffff) >> 0xe |
                                ((*(uint *)(iVar2 + 4) & 0x1fffffff) >> 0x1c) << 2));
  return;
}


// ===== FUN_08009b5c @ 08009b5c

bool FUN_08009b5c(uint param_1)

{
  return (1 << (param_1 & 0x1f) & ~*(uint *)(DAT_08009b78 + (param_1 >> 0x10))) == 0;
}


// ===== FUN_08009b7c @ 08009b7c

bool FUN_08009b7c(void)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = 0; (iVar1 = FUN_08009b5c(0x11), iVar1 != 1 && (uVar2 < 0x3000)); uVar2 = uVar2 + 1) {
  }
  iVar1 = FUN_08009b5c(0x11);
  return iVar1 == 1;
}


// ===== FUN_08009ba4 @ 08009ba4

void FUN_08009ba4(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 1 << (param_1 & 0x1f);
  puVar1 = (uint *)(DAT_08009bc4 + (param_1 >> 0x10));
  uVar2 = *puVar1;
  if (param_2 == 1) {
    uVar2 = uVar2 | uVar3;
  }
  else {
    uVar2 = uVar2 & ~uVar3;
  }
  *puVar1 = uVar2;
  return;
}


// ===== FUN_08009bc8 @ 08009bc8

void FUN_08009bc8(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08009c1c;
  iVar2 = 0;
  if (param_1 == 0) {
    *(uint *)(DAT_08009c1c + 4) = *(uint *)(DAT_08009c1c + 4) & 0xfffeffff;
    *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) | 0x2000000;
  }
  else {
    *(uint *)(DAT_08009c1c + 4) = *(uint *)(DAT_08009c1c + 4) | 0x10000;
    if (param_1 == 1) {
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xfffdffff;
      iVar2 = 2;
    }
    else {
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 0x20000;
    }
  }
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xffc3ffff | (param_2 & 0xf) << 0x12;
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0x9fffffff | (param_2 >> 4 & 3) << 0x1d;
  *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xf8ffffff | iVar2 << 0x18;
  return;
}


// ===== FUN_08009c20 @ 08009c20

void FUN_08009c20(void)

{
  uint *puVar1;
  
  puVar1 = DAT_08009c60;
  *DAT_08009c60 = *DAT_08009c60 | 1;
  do {
  } while (-1 < (int)(*puVar1 << 0x1e));
  puVar1[1] = puVar1[1] & 0xfffffffc;
  do {
  } while ((puVar1[1] & 0xc) != 0);
  *puVar1 = *puVar1 & DAT_08009c64;
  puVar1[1] = 0;
  puVar1[0xb] = 0x1f10;
  puVar1[0xc] = 0x100000;
  puVar1[2] = 0x9f0000;
  return;
}


// ===== FUN_08009c68 @ 08009c68

void FUN_08009c68(uint param_1)

{
  *(uint *)(DAT_08009c9c + 4) = *(uint *)(DAT_08009c9c + 4) & 0xfffffffc | param_1 & 3;
  return;
}


// ===== FUN_08009ca0 @ 08009ca0

uint FUN_08009ca0(void)

{
  return (*(uint *)(DAT_08009cac + 4) & 0xf) >> 2;
}


// ===== FUN_08009cb0 @ 08009cb0

undefined4 FUN_08009cb0(uint param_1)

{
  if ((param_1 < 0x81) || ((0x9f < param_1 && (0x1c < param_1 - 0xe0)))) {
    return 0;
  }
  return 1;
}


// ===== FUN_08009cc6 @ 08009cc6

undefined4 FUN_08009cc6(uint param_1)

{
  if ((param_1 < 0x40) || ((0x7e < param_1 && (0x7c < param_1 - 0x80)))) {
    return 0;
  }
  return 1;
}


// ===== FUN_08009cdc @ 08009cdc

void FUN_08009cdc(int param_1)

{
  bool bVar1;
  int local_8;
  
  local_8 = param_1;
  do {
    bVar1 = local_8 != 0;
    local_8 = local_8 + -1;
  } while (bVar1);
  return;
}


// ===== FUN_08009ce8 @ 08009ce8

void FUN_08009ce8(void)

{
  uint *puVar1;
  
  FUN_08013108(4);
  puVar1 = DAT_08009d14;
  *DAT_08009d14 = *DAT_08009d0c / DAT_08009d10;
  puVar1[1] = *puVar1 * 1000;
  return;
}


// ===== FUN_08009d18 @ 08009d18

void FUN_08009d18(uint param_1)

{
  uint uVar1;
  
  do {
    if (param_1 == 0) {
      return;
    }
    if (param_1 < 0x33) {
      DAT_e000e014 = *(int *)(DAT_08009d60 + 4) * param_1;
      param_1 = 0;
    }
    else {
      DAT_e000e014 = *(int *)(DAT_08009d60 + 4) * 0x32;
      param_1 = param_1 - 0x32 & 0xffff;
    }
    DAT_e000e018 = 0;
    uVar1 = DAT_e000e010;
    DAT_e000e010 = uVar1 | 1;
    do {
      uVar1 = DAT_e000e010;
      if ((uVar1 & 1) == 0) break;
    } while (-1 < (int)(uVar1 << 0xf));
    uVar1 = DAT_e000e010;
    DAT_e000e010 = uVar1 & 0xfffffffe;
    DAT_e000e018 = 0;
  } while( true );
}


// ===== FUN_08009d64 @ 08009d64

int FUN_08009d64(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *param_1;
  iVar1 = FUN_08009f70(param_1,0);
  if (iVar1 == 0) {
    iVar2 = 0;
    do {
      iVar1 = FUN_0801191c(uVar3,param_1[6]);
      if (iVar1 != 0) break;
      if ((*(char *)param_1[7] == -0x1b) || (*(char *)param_1[7] == '\0')) {
        iVar2 = iVar2 + 1;
        if (iVar2 == param_2) {
          return 0;
        }
      }
      else {
        iVar2 = 0;
      }
      iVar1 = FUN_08009e04(param_1,1);
    } while (iVar1 == 0);
  }
  if (iVar1 == 4) {
    iVar1 = 7;
  }
  return iVar1;
}


// ===== FUN_08009dac @ 08009dac

undefined4 FUN_08009dac(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_08012da8();
  if (iVar1 == 0) {
    iVar1 = FUN_08009654(param_1,param_2);
    *(int *)(param_1 + 0x2c) = iVar1;
    FUN_080076e8(param_1 + 0x30,0x1000);
    uVar3 = 0;
    while ((uVar3 < *(ushort *)(param_1 + 10) &&
           (iVar2 = FUN_0800a09c(*(undefined1 *)(param_1 + 1),param_1 + 0x30,iVar1 + uVar3,1),
           iVar2 == 0))) {
      uVar3 = uVar3 + 1;
    }
    if (*(ushort *)(param_1 + 10) == uVar3) {
      return 0;
    }
  }
  return 1;
}


// ===== FUN_08009e04 @ 08009e04

undefined4 FUN_08009e04(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  uVar3 = param_1[4] + 0x20;
  if (0x1fffff < uVar3) {
LAB_08009e88:
    param_1[6] = 0;
    return 4;
  }
  if (param_1[6] == 0) {
    return 4;
  }
  if ((uVar3 & 0xfff) == 0) {
    param_1[6] = param_1[6] + 1;
    if (param_1[5] == 0) {
      if ((uint)*(ushort *)(iVar4 + 8) <= uVar3 >> 5) goto LAB_08009e88;
    }
    else if ((*(ushort *)(iVar4 + 10) - 1 & uVar3 >> 0xc) == 0) {
      uVar1 = FUN_0800fae4(param_1);
      if (uVar1 < 2) {
        return 2;
      }
      if (uVar1 == 0xffffffff) {
        return 1;
      }
      if (*(uint *)(iVar4 + 0x14) <= uVar1) {
        if (param_2 == 0) goto LAB_08009e88;
        uVar1 = FUN_08009726(param_1,param_1[5]);
        if (uVar1 == 0) {
          return 7;
        }
        if (uVar1 == 1) {
          return 2;
        }
        if (uVar1 == 0xffffffff) {
          return 1;
        }
        iVar2 = FUN_08009dac(iVar4,uVar1);
        if (iVar2 != 0) {
          return 1;
        }
      }
      param_1[5] = uVar1;
      iVar2 = FUN_08009654(iVar4,uVar1);
      param_1[6] = iVar2;
    }
  }
  param_1[4] = uVar3;
  param_1[7] = (uVar3 & 0xfff) + iVar4 + 0x30;
  return 0;
}


// ===== FUN_08009eb2 @ 08009eb2

int FUN_08009eb2(undefined4 *param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  
  iVar3 = 4;
  uVar5 = *param_1;
  while( true ) {
    if (param_1[6] == 0) {
      if (iVar3 == 0) {
        return 0;
      }
      goto LAB_08009f0c;
    }
    iVar3 = FUN_0801191c(uVar5);
    if (iVar3 != 0) goto LAB_08009f0c;
    cVar1 = *(char *)param_1[7];
    if (cVar1 == '\0') break;
    bVar2 = ((char *)param_1[7])[0xb];
    bVar4 = bVar2 & 0x3f;
    *(byte *)((int)param_1 + 6) = bVar4;
    if ((((cVar1 != -0x1b) && (cVar1 != '.')) && (bVar4 != 0xf)) &&
       (((bVar2 & 0x1f) == 8) == param_2)) {
      return 0;
    }
    iVar3 = FUN_08009e04(param_1,0);
    if (iVar3 != 0) {
LAB_08009f0c:
      param_1[6] = 0;
      return iVar3;
    }
  }
  iVar3 = 4;
  goto LAB_08009f0c;
}


// ===== FUN_08009f12 @ 08009f12

int FUN_08009f12(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = FUN_08009d64(param_1,1);
  if ((iVar1 == 0) && (iVar1 = FUN_0801191c(iVar3,param_1[6]), iVar1 == 0)) {
    FUN_080076a4(param_1[7],0x20);
    piVar2 = (int *)param_1[7];
    *piVar2 = param_1[8];
    piVar2[1] = param_1[9];
    *(short *)(piVar2 + 2) = (short)param_1[10];
    *(undefined1 *)((int)piVar2 + 10) = *(undefined1 *)((int)param_1 + 0x2a);
    *(undefined1 *)(iVar3 + 3) = 1;
  }
  return iVar1;
}


// ===== FUN_08009f52 @ 08009f52

void FUN_08009f52(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = FUN_0801191c(iVar2,param_1[6]);
  if (iVar1 == 0) {
    *(undefined1 *)param_1[7] = 0xe5;
    *(undefined1 *)(iVar2 + 3) = 1;
  }
  return;
}


// ===== FUN_08009f70 @ 08009f70

undefined4 FUN_08009f70(undefined4 *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  
  pbVar4 = (byte *)*param_1;
  if ((param_2 < 0x200000) && ((param_2 & 0x1f) == 0)) {
    param_1[4] = param_2;
    uVar3 = param_1[2];
    if ((uVar3 == 0) && ((*pbVar4 < 3 || (uVar3 = *(uint *)(pbVar4 + 0x24), uVar3 == 0)))) {
      if ((uint)*(ushort *)(pbVar4 + 8) <= param_2 >> 5) {
        return 2;
      }
      iVar2 = *(int *)(pbVar4 + 0x24);
    }
    else {
      uVar1 = *(ushort *)(pbVar4 + 10);
      for (; (uint)uVar1 * 0x1000 <= param_2; param_2 = param_2 + (uint)uVar1 * -0x1000) {
        uVar3 = FUN_0800fae4(param_1,uVar3);
        if (uVar3 == 0xffffffff) {
          return 1;
        }
        if (uVar3 < 2) {
          return 2;
        }
        if (*(uint *)(pbVar4 + 0x14) <= uVar3) {
          return 2;
        }
      }
      iVar2 = FUN_08009654(pbVar4);
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


// ===== FUN_08009ff2 @ 08009ff2

undefined4 FUN_08009ff2(int param_1)

{
  if (((param_1 == 0) || (param_1 == 1)) || (param_1 != 2)) {
    return 1;
  }
  return 0;
}


// ===== FUN_0800a004 @ 0800a004

undefined4 FUN_0800a004(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 == 0) || (param_1 == 1)) {
    return 1;
  }
  if (param_1 != 2) {
    return 4;
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      uVar1 = FUN_0800f344();
      uVar2 = FUN_0800f4e0();
      uVar1 = uVar1 / uVar2;
    }
    else {
      if ((param_2 != 2) && (param_2 != 3)) {
        return 4;
      }
      uVar1 = FUN_0800f4e0();
    }
    *param_3 = uVar1;
  }
  return 0;
}


// ===== FUN_0800a048 @ 0800a048

undefined1 FUN_0800a048(int param_1,undefined4 param_2,int param_3,short param_4)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar1 = 1;
  if (param_1 != 1) {
    if (param_1 == 2) {
      sVar2 = FUN_0800f4e0();
      iVar3 = FUN_0800f4e0();
      uVar1 = FUN_0800f484(param_2,param_3 * iVar3 + *DAT_0800a084,param_4 * sVar2);
      return uVar1;
    }
    uVar1 = 4;
  }
  return uVar1;
}


// ===== FUN_0800a088 @ 0800a088

undefined4 FUN_0800a088(int param_1)

{
  if ((param_1 == 0) || ((param_1 != 1 && (param_1 != 2)))) {
    return 1;
  }
  return 0;
}


// ===== FUN_0800a09c @ 0800a09c

undefined1 FUN_0800a09c(int param_1,undefined4 param_2,int param_3,short param_4)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar1 = 1;
  if (param_1 != 1) {
    if (param_1 == 2) {
      sVar2 = FUN_0800f4e0();
      iVar3 = FUN_0800f4e0();
      uVar1 = FUN_0800f54c(param_2,param_3 * iVar3 + *DAT_0800a0d8,param_4 * sVar2);
      return uVar1;
    }
    uVar1 = 4;
  }
  return uVar1;
}


// ===== FUN_0800a0dc @ 0800a0dc

void FUN_0800a0dc(void)

{
  undefined1 auStack_1c [20];
  
  FUN_08014af4(auStack_1c,&DAT_0800a11c,*(undefined4 *)(DAT_0800a118 + 4));
  FUN_080082f2(0x2d,0x78,auStack_1c,0xffe0,0,0x20,0);
  FUN_0800beb0(0xaf,0x7d,0xffe0,0);
  return;
}


// ===== FUN_0800a124 @ 0800a124

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800a124(int param_1)

{
  char *pcVar1;
  
  if (*(char *)(_DAT_0800a150 + 0x26) == '\0') {
    if (param_1 == 0) {
      pcVar1 = s_2__UI_decorate_holdoff_jpg_0800a184;
    }
    else {
      pcVar1 = s_2__UI_decorate_hold_jpg_0800a16c;
    }
  }
  else if (param_1 == 0) {
    pcVar1 = s_2__UI_decorat_holdoff_jpg_0800a1a0;
  }
  else {
    pcVar1 = s_2__UI_decorat_hold_jpg_0800a153 + 1;
  }
  FUN_08010274(pcVar1,0);
  return;
}


// ===== FUN_0800a1bc @ 0800a1bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800a1bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined *puVar8;
  
  iVar4 = _DAT_0800a40c;
  cVar3 = *(char *)(_DAT_0800a40c + 0x26);
  if (param_1 == 0) {
    if (cVar3 == '\0') {
      FUN_08010274(s_2__UI_decorate_up_jpg_0800a460,7,0x5f);
      pcVar5 = s_2__UI_decorate_down_jpg_0800a478;
    }
    else {
      FUN_08010274(s_2__UI_decorat_up_jpg_0800a430,7,0x5f);
      pcVar5 = s_2__UI_decorat_down_jpg_0800a448;
    }
    uVar6 = FUN_08010274(pcVar5,7,0xa6);
    FUN_0800a500(uVar6,param_2,param_3,param_4);
    return;
  }
  if (param_1 != 2) {
    if (cVar3 == '\0') {
      pcVar5 = s_2__UI_decorate_mode_jpg_0800a4d8;
    }
    else {
      pcVar5 = s_2__UI_decorat_mode_jpg_0800a40f + 1;
    }
    FUN_08010274(pcVar5,0,0x24);
    FUN_08007b34(0,0x4c,0xf0,0x4c,0x3186);
    FUN_08007b34(0x9e,0x4c,0x9e,0xf5,0x3186);
    FUN_08007b34(0x9e,0xf5,0xa4,0xfc,0x3186);
    FUN_08007b34(0xa4,0xfc,0xf0,0xfc,0x3186);
    FUN_08007b34(0xf0,0x4c,0xf0,0xfc,0x3186);
    FUN_08007b34(0,0xd4,0x9e,0xd4,0x3186);
    FUN_08007f24(0,0xd5,0x4e,0xea,0x400);
    FUN_08007f24(0x50,0xd5,0x9d,0xea,0xf800);
    FUN_08007b34(0,0xea,0,0xf5,0x400);
    FUN_08007b34(0,0xf5,6,0xfb,0x400);
    FUN_08007b34(6,0xfb,0x4e,0xfb,0x400);
    FUN_08007b34(0x4e,0xfb,0x4e,0xea,0x400);
    FUN_08007b34(0x50,0xea,0x50,0xfb,0xf800);
    FUN_08007b34(0x50,0xfb,0x97,0xfb,0xf800);
    FUN_08007b34(0x97,0xfb,0x9d,0xf6,0xf800);
    FUN_08007b34(0x9d,0xf6,0x9d,0xea,0xf800);
    if (*(char *)(iVar4 + 0x20) == '\0') {
      FUN_080082f2(0xf,0xd8,&DAT_0800a4f0,*(undefined2 *)(iVar4 + 0x1c),
                   *(undefined2 *)(iVar4 + 0x1a),0x10,1);
      uVar1 = *(undefined2 *)(iVar4 + 0x1a);
      uVar2 = *(undefined2 *)(iVar4 + 0x1c);
      puVar8 = &DAT_0800a4f8;
      uVar6 = 0x5f;
    }
    else {
      FUN_080082f2(0x1b,0xd8,&DAT_0800a428,*(undefined2 *)(iVar4 + 0x1c),
                   *(undefined2 *)(iVar4 + 0x1a),0x10,1);
      uVar1 = *(undefined2 *)(iVar4 + 0x1a);
      puVar8 = &DAT_0800a42c;
      uVar2 = *(undefined2 *)(iVar4 + 0x1c);
      uVar6 = 0x6b;
    }
    FUN_080082f2(uVar6,0xd8,puVar8,uVar2,uVar1,0x10,1);
    *(undefined1 *)(iVar4 + 0xe) = 0xff;
    return;
  }
  if (cVar3 == '\0') {
    FUN_08010274(s_2__UI_decorate_decorate_jpg_0800a4b4,0,0xa7);
    FUN_08010274(s_2__UI_decorate_up_jpg_0800a460,7,0x29);
    FUN_08010274(s_2__UI_decorate_up_jpg_0800a460,7,0xc1);
    FUN_08010274(s_2__UI_decorate_down_jpg_0800a478,7,0x8f);
    pcVar5 = s_2__UI_decorate_down_jpg_0800a478;
  }
  else {
    FUN_08010274(s_2__UI_decorat_decorate_jpg_0800a490,0,0xa7);
    FUN_08010274(s_2__UI_decorat_up_jpg_0800a430,7,0x29);
    FUN_08010274(s_2__UI_decorat_up_jpg_0800a430,7,0xc1);
    FUN_08010274(s_2__UI_decorat_down_jpg_0800a448,7,0x8f);
    pcVar5 = s_2__UI_decorat_down_jpg_0800a448;
  }
  FUN_08010274(pcVar5,7,0x12e);
  uVar6 = 0xffe0;
  if (*(char *)(iVar4 + 0x20) == '\0') {
    uVar1 = *(undefined2 *)(iVar4 + 0x1a);
    if (*(char *)(iVar4 + 0x26) != '\0') {
      uVar6 = 0;
    }
    pcVar5 = &DAT_0800a4d0;
    uVar7 = 0x44;
  }
  else {
    uVar1 = *(undefined2 *)(iVar4 + 0x1a);
    if (*(char *)(iVar4 + 0x26) != '\0') {
      uVar6 = 0;
    }
    pcVar5 = s_Power__0800a4ac;
    uVar7 = 0x3c;
  }
  FUN_080082f2(uVar7,0xaa,pcVar5,uVar6,uVar1,0x10,0);
  return;
}


// ===== FUN_0800a500 @ 0800a500

void FUN_0800a500(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 in_r3;
  undefined4 uVar5;
  
  iVar1 = DAT_0800a5c4;
  FUN_08007fc8(0x13,0xed,0x68,0xfc,4,*(undefined2 *)(DAT_0800a5c4 + 0x1e),in_r3);
  FUN_08007fc8(0x88,0xed,0xdd,0xfc,4,*(undefined2 *)(iVar1 + 0x1e));
  FUN_08007f24(0x13,0xdf,0x68,0xf0,*(undefined2 *)(iVar1 + 0x1e));
  FUN_08007f24(0x88,0xdf,0xdd,0xf0,*(undefined2 *)(iVar1 + 0x1e));
  FUN_08007e88(0x12,0xbf,0x68,0xfc,4,0x400);
  FUN_08007e88(0x87,0xbf,0xdd,0xfc,4,0xf800);
  if (*(char *)(iVar1 + 0x20) == '\0') {
    uVar5 = 0x10;
    FUN_080082f2(0x25,199,&DAT_0800a5d0,0x400,0x400,0x10,1);
    uVar3 = 199;
    puVar4 = &DAT_0800a5d8;
    uVar2 = 0x9a;
  }
  else {
    uVar5 = 0x18;
    FUN_080082f2(0x2b,0xc3,&DAT_0800a5c8,0x400,0x400,0x18,1);
    uVar3 = 0xc3;
    puVar4 = &DAT_0800a5cc;
    uVar2 = 0xa0;
  }
  FUN_080082f2(uVar2,uVar3,puVar4,0xf800,0xf800,uVar5,1);
  return;
}


// ===== FUN_0800a5e0 @ 0800a5e0

void FUN_0800a5e0(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *(char *)(DAT_0800a664 + 0x26);
  switch(param_1) {
  case 0:
  case 1:
    if (cVar1 == '\0') {
      pcVar2 = s_2__UI_mode_V_jpg_0800a67c;
    }
    else {
      pcVar2 = s_2__UI_mode_1_V_jpg_0800a668;
    }
    break;
  case 2:
  case 3:
  case 4:
    if (cVar1 == '\0') {
      pcVar2 = s_2__UI_mode_R_jpg_0800a6a4;
    }
    else {
      pcVar2 = s_2__UI_mode_1_R_jpg_0800a690;
    }
    break;
  case 5:
    if (cVar1 == '\0') {
      pcVar2 = s_2__UI_mode_C_jpg_0800a6cc;
    }
    else {
      pcVar2 = s_2__UI_mode_1_C_jpg_0800a6b8;
    }
    break;
  case 6:
  case 7:
    if (cVar1 == '\0') {
      pcVar2 = s_2__UI_mode_H_jpg_0800a6f4;
    }
    else {
      pcVar2 = s_2__UI_mode_1_H_jpg_0800a6e0;
    }
    break;
  case 8:
  case 9:
    if (cVar1 == '\0') {
      pcVar2 = s_2__UI_mode_L_jpg_0800a71c;
    }
    else {
      pcVar2 = s_2__UI_mode_1_L_jpg_0800a708;
    }
    break;
  case 10:
  case 0xb:
    if (cVar1 == '\0') {
      pcVar2 = s_2__UI_mode_A_jpg_0800a744;
    }
    else {
      pcVar2 = s_2__UI_mode_1_A_jpg_0800a730;
    }
    break;
  default:
    return;
  }
  FUN_08010274(pcVar2,0,0x10a);
  return;
}


// ===== FUN_0800a758 @ 0800a758

void FUN_0800a758(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  
  iVar1 = DAT_0800aadc;
  if (*(char *)(DAT_0800aad8 + 2) == '\0') {
    FUN_08007f24(0x28,0x28,200,0x5a,*(undefined2 *)(DAT_0800aadc + 0x1a),param_3,param_4);
    if (*(char *)(iVar1 + 0x20) != '\0') {
      switch(param_1) {
      case 0:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x32;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x55;
        uVar7 = DAT_0800ab60;
        break;
      case 1:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar4 = 0x32;
        uVar2 = 0x55;
        uVar7 = DAT_0800ab64;
        break;
      case 2:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x2e;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x66;
        uVar7 = DAT_0800ab70;
        break;
      case 3:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x2e;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x65;
        uVar7 = DAT_0800ab6c;
        break;
      case 4:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x2e;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x61;
        uVar7 = DAT_0800ab68;
        break;
      case 5:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x2e;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x61;
        uVar7 = DAT_0800ab74;
        break;
      case 6:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x33;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x61;
        uVar7 = DAT_0800ab78;
        break;
      case 7:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x2b;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x65;
        uVar7 = DAT_0800ab7c;
        break;
      case 8:
        goto switchD_0800a7a4_caseD_8;
      case 9:
        goto switchD_0800a7a4_caseD_9;
      case 10:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x32;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x55;
        uVar7 = DAT_0800ab80;
        break;
      case 0xb:
        uVar5 = *(undefined2 *)(iVar1 + 0x1a);
        uVar4 = 0x32;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        uVar2 = 0x55;
        uVar7 = DAT_0800ab84;
        break;
      default:
        goto switchD_0800a7a4_default;
      }
      goto LAB_0800a8a0;
    }
    switch(param_1) {
    case 0:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800aae0;
      goto LAB_0800a872;
    case 1:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800aaec;
      goto LAB_0800a872;
    case 2:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800ab08;
      break;
    case 3:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800ab00;
      break;
    case 4:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = &DAT_0800aaf8;
      uVar7 = 0x48;
      goto LAB_0800a808;
    case 5:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800ab10;
      break;
    case 6:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800ab18;
      break;
    case 7:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800ab20;
      break;
    case 8:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = &DAT_0800ab3c;
      uVar7 = 0x28;
      goto LAB_0800a808;
    case 9:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      uVar4 = 0x18;
      uVar2 = 0x2e;
      puVar3 = &DAT_0800ab28;
      uVar7 = 0x18;
      uVar6 = uVar5;
      goto LAB_0800a878;
    case 10:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = (undefined *)0x800ab48;
      goto LAB_0800a872;
    case 0xb:
      uVar5 = *(undefined2 *)(iVar1 + 0x1c);
      puVar3 = &DAT_0800ab54;
LAB_0800a872:
      uVar7 = 0x38;
      goto LAB_0800a808;
    default:
      goto switchD_0800a7a4_default;
    }
    uVar7 = 0x58;
LAB_0800a808:
    uVar2 = 0x2e;
    uVar4 = 0x20;
    uVar6 = uVar5;
    goto LAB_0800a878;
  }
  if ((param_1 != 9) && (param_1 != 8)) {
    if (*(char *)(DAT_0800aadc + 0x26) == '\0') {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xffff;
    }
    FUN_08007f24(0x9d,0x27,0xea,0x43,uVar7,param_3,param_4);
  }
  if (*(char *)(iVar1 + 0x20) != '\0') {
    switch(param_1) {
    case 0:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x2a;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xad;
      uVar7 = DAT_0800abb0;
      break;
    case 1:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x2a;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xad;
      uVar7 = DAT_0800abb4;
      break;
    case 2:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x29;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xb5;
      uVar7 = DAT_0800abc0;
      break;
    case 3:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x29;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xb2;
      uVar7 = DAT_0800abbc;
      break;
    case 4:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x28;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xb2;
      uVar7 = DAT_0800abb8;
      break;
    case 5:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x2b;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xb2;
      uVar7 = DAT_0800abc4;
      break;
    case 6:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x2b;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xb2;
      uVar7 = DAT_0800abc8;
      break;
    case 7:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x27;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xb2;
      uVar7 = DAT_0800abcc;
      break;
    case 8:
switchD_0800a7a4_caseD_8:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x34;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0x4b;
      uVar7 = DAT_0800abd4;
      break;
    case 9:
switchD_0800a7a4_caseD_9:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x33;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0x4b;
      uVar7 = DAT_0800abd0;
      break;
    case 10:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x2a;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xad;
      uVar7 = DAT_0800abd8;
      break;
    case 0xb:
      uVar5 = *(undefined2 *)(iVar1 + 0x1a);
      uVar4 = 0x2a;
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar2 = 0xad;
      uVar7 = DAT_0800abdc;
      break;
    default:
      return;
    }
LAB_0800a8a0:
    FUN_08007c6c(uVar7,uVar2,uVar4,uVar6,uVar5,0);
    return;
  }
  switch(param_1) {
  case 0:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = (undefined *)0x800aae0;
    goto LAB_0800a95c;
  case 1:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = (undefined *)0x800aaec;
    goto LAB_0800a95c;
  case 2:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = (undefined *)0x800ab90;
    break;
  case 3:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = (undefined *)0x800ab88;
    break;
  case 4:
    uVar4 = 0x10;
    uVar2 = 0x2d;
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = &DAT_0800aaf8;
    uVar7 = 0xad;
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    goto LAB_0800a878;
  case 5:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = (undefined *)0x800ab98;
    break;
  case 6:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = (undefined *)0x800aba0;
    break;
  case 7:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = &DAT_0800aba8;
    break;
  case 8:
    uVar4 = 0x20;
    uVar2 = 0x2e;
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = &DAT_0800ab3c;
    uVar7 = 0x28;
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    goto LAB_0800a878;
  case 9:
    uVar4 = 0x18;
    uVar2 = 0x2e;
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = &DAT_0800ab28;
    uVar7 = 0x18;
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    goto LAB_0800a878;
  case 10:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = (undefined *)0x800ab48;
    goto LAB_0800a95c;
  case 0xb:
    uVar6 = *(undefined2 *)(iVar1 + 0x1a);
    uVar5 = *(undefined2 *)(iVar1 + 0x1c);
    puVar3 = &DAT_0800ab54;
LAB_0800a95c:
    uVar4 = 0x10;
    uVar2 = 0x2d;
    uVar7 = 0xa5;
    goto LAB_0800a878;
  default:
    goto switchD_0800a7a4_default;
  }
  uVar4 = 0x10;
  uVar2 = 0x2d;
  uVar7 = 0xb2;
LAB_0800a878:
  FUN_080082f2(uVar7,uVar2,puVar3,uVar5,uVar6,uVar4,1);
switchD_0800a7a4_default:
  return;
}


// ===== FUN_0800abe0 @ 0800abe0

void FUN_0800abe0(uint param_1)

{
  char *pcVar1;
  
  if (*(char *)(DAT_0800ac5c + 0x26) == '\0') {
    if (param_1 < 0x51) {
      if (param_1 < 0x3d) {
        if (param_1 < 0x29) {
          if (param_1 < 0xb) {
            pcVar1 = s_2__UI_cell_5_jpg_0800acc0;
          }
          else {
            pcVar1 = s_2__UI_cell_4_jpg_0800acac;
          }
        }
        else {
          pcVar1 = s_2__UI_cell_3_jpg_0800ac98;
        }
      }
      else {
        pcVar1 = s_2__UI_cell_2_jpg_0800ac84;
      }
    }
    else {
      pcVar1 = s_2__UI_cell_1_jpg_0800ac70;
    }
  }
  else if (param_1 < 0x51) {
    if (param_1 < 0x3d) {
      if (param_1 < 0x29) {
        if (param_1 < 0xb) {
          pcVar1 = s_2__UI_cel_5_jpg_0800ad04;
        }
        else {
          pcVar1 = s_2__UI_cel_4_jpg_0800acf4;
        }
      }
      else {
        pcVar1 = s_2__UI_cel_3_jpg_0800ace4;
      }
    }
    else {
      pcVar1 = s_2__UI_cel_2_jpg_0800acd4;
    }
  }
  else {
    pcVar1 = s_2__UI_cel_1_jpg_0800ac60;
  }
  FUN_08010274(pcVar1,0xb9,2);
  return;
}


// ===== FUN_0800ad14 @ 0800ad14

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800ad14(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x3186;
  }
  else {
    uVar2 = 0x1c9f;
    if (param_1 != 1) {
      FUN_08007fc8(0x45,0xee,0xab,0x104,3,0x1c9f,param_4);
      uVar2 = 0x3186;
      goto LAB_0800ad50;
    }
  }
  FUN_08007fc8(0x45,0xee,0xab,0x104,3,0x3186,param_4);
LAB_0800ad50:
  FUN_08007fc8(0x45,0x110,0xab,0x126,3,uVar2,param_4);
  if (*(char *)(_DAT_0800ade0 + 0x20) == '\0') {
    FUN_080082f2(0x48,0xf2,&DAT_0800adf4,0xf79e,0xf79e,0x10,1);
    pcVar1 = &DAT_0800ae04;
    uVar2 = 0x68;
  }
  else {
    FUN_080082f2(100,0xf2,s_Reset_0800ade3 + 1,0xf79e,0xf79e,0x10,1);
    pcVar1 = s_Return_0800adec;
    uVar2 = 0x60;
  }
  FUN_080082f2(uVar2,0x114,pcVar1,0xf79e,0xf79e,0x10,1);
  return;
}


// ===== FUN_0800af24 @ 0800af24

void FUN_0800af24(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  FUN_08007c6c(DAT_0800afd0,param_1,param_2,0x1c9f,0x1c9f,0,param_4);
  uVar3 = param_2 + 3;
  FUN_08007a46(param_1 + 0x98U & 0xffff,uVar3 & 0xffff,4,0xfd20);
  FUN_08007a46(param_1 + 0xa2U & 0xffff,uVar3 & 0xffff,3,0x400);
  FUN_08007a46(param_1 + 0xaaU & 0xffff,uVar3 & 0xffff,2,0x1c9f);
  sVar1 = (short)param_2 + 0x25;
  FUN_08007b34(param_1,sVar1,param_1 + 0xa8U & 0xffff,sVar1,0x1c9f);
  iVar2 = DAT_0800afd4;
  FUN_080082f2(param_1 + 5U & 0xffff,param_2 + 0x2aU & 0xffff,&DAT_0800afd8,
               *(undefined2 *)(DAT_0800afd4 + 0x1c),0xf79e,0xc,1);
  FUN_080082f2(param_1 + 3U & 0xffff,param_2 + 0x39U & 0xffff,s_http___www_fnirsi_cn_0800aff4,
               *(undefined2 *)(iVar2 + 0x1c),0xf79e,0x10,1);
  return;
}


// ===== FUN_0800b00c @ 0800b00c

void FUN_0800b00c(byte *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  
  iVar3 = DAT_0800b1cc;
  bVar2 = false;
  cVar1 = *(char *)(DAT_0800b1cc + 2);
  if (((cVar1 != '\x01') && (cVar1 != '\x05')) && (cVar1 != '\t')) {
    return;
  }
  if ((*param_1 == 9) || (*param_1 == 8)) {
    FUN_08007f24(0,0x1e,0xf0,0xff);
    bVar2 = true;
  }
  cVar1 = *(char *)(iVar3 + 2);
  if (cVar1 == '\t') {
    bVar4 = *param_1;
    if (bVar4 < 2) {
LAB_0800b068:
      iVar5 = FUN_08012868(0xb);
      if (iVar5 == 1) {
        *param_1 = 2;
        goto LAB_0800b190;
      }
      goto LAB_0800b178;
    }
    if (bVar4 < 5) {
LAB_0800b0c4:
      iVar5 = FUN_08012868(10);
      if (iVar5 == 1) {
        bVar4 = 5;
        goto LAB_0800b188;
      }
      goto LAB_0800b178;
    }
    if (bVar4 == 5) {
LAB_0800b07c:
      iVar5 = FUN_08012868(0xf);
      if (iVar5 == 1) {
        *param_1 = 6;
        goto LAB_0800b190;
      }
      goto LAB_0800b178;
    }
    if (7 < bVar4) {
      if (9 < bVar4) goto LAB_0800b0a8;
      goto LAB_0800b096;
    }
LAB_0800b150:
    iVar5 = FUN_08012868(0x13);
    if (iVar5 != 1) goto LAB_0800b178;
    *param_1 = 8;
LAB_0800b1b0:
    *(undefined1 *)(iVar3 + 7) = 1;
  }
  else {
    if (cVar1 == '\x01') {
      bVar4 = *param_1;
      if (bVar4 < 2) {
LAB_0800b096:
        iVar5 = FUN_08012868(0x10);
        if (iVar5 == 1) {
          *param_1 = 10;
          goto LAB_0800b190;
        }
      }
      else {
        if (4 < bVar4) {
          if (bVar4 != 5) {
            if (7 < bVar4) {
              if (9 < bVar4) goto LAB_0800b150;
              goto LAB_0800b07c;
            }
            goto LAB_0800b0c4;
          }
          goto LAB_0800b068;
        }
LAB_0800b0a8:
        iVar5 = FUN_08012868(0xc);
        if (iVar5 == 1) {
          *param_1 = 0;
          goto LAB_0800b190;
        }
      }
LAB_0800b178:
      if (*param_1 != 9) {
        if (*param_1 != 8) {
LAB_0800b190:
          if (bVar2) {
            FUN_0800a1bc(*(undefined1 *)(DAT_0800b1d0 + 2));
          }
          goto LAB_0800b19a;
        }
        goto LAB_0800b1b0;
      }
    }
    else {
      if (cVar1 != '\x05') goto LAB_0800b178;
      bVar4 = *param_1;
      if (bVar4 < 2) {
        if (bVar4 != 0) goto LAB_0800b0a8;
        iVar5 = FUN_08012868(0xd);
        if (iVar5 == 1) {
          *param_1 = 1;
          goto LAB_0800b190;
        }
        goto LAB_0800b178;
      }
      if (bVar4 < 5) {
        if (bVar4 == 2) {
          iVar5 = FUN_08012868(0x14);
          if (iVar5 != 1) goto LAB_0800b178;
          bVar4 = 3;
LAB_0800b188:
          *param_1 = bVar4;
        }
        else {
          if (bVar4 == 3) {
            iVar5 = FUN_08012868(0xe);
            if (iVar5 == 1) {
              bVar4 = 4;
              goto LAB_0800b188;
            }
            goto LAB_0800b178;
          }
          if (bVar4 == 4) goto LAB_0800b068;
        }
        goto LAB_0800b190;
      }
      if (bVar4 == 5) goto LAB_0800b190;
      if (bVar4 < 8) {
        if (bVar4 != 6) goto LAB_0800b07c;
        iVar5 = FUN_08012868(0x12);
        if (iVar5 == 1) {
          bVar4 = 7;
          goto LAB_0800b188;
        }
        goto LAB_0800b178;
      }
      if (9 < bVar4) {
        if (bVar4 != 10) goto LAB_0800b096;
        iVar5 = FUN_08012868(0x11);
        if (iVar5 == 1) {
          bVar4 = 0xb;
          goto LAB_0800b188;
        }
        goto LAB_0800b178;
      }
      if (bVar4 != 8) goto LAB_0800b150;
      iVar5 = FUN_08012868(9);
      if (iVar5 != 1) goto LAB_0800b178;
      *param_1 = 9;
    }
    *(undefined1 *)(iVar3 + 6) = 1;
  }
  FUN_08007f24(0,0x1e,0xf0,0xff);
LAB_0800b19a:
  FUN_0800a5e0(*param_1);
  FUN_0800a758(*param_1);
  return;
}


// ===== FUN_0800b1d4 @ 0800b1d4

void FUN_0800b1d4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  undefined2 uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  undefined8 uVar16;
  undefined2 uVar17;
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [12];
  int local_34;
  int local_30;
  int local_2c;
  
  iVar1 = DAT_0800b5dc;
  uVar14 = (uint)*(byte *)(DAT_0800b5d8 + 0x10) + (1 - param_1) * 6 & 0xff;
  iVar11 = (uint)*(ushort *)(DAT_0800b5d8 + 0x12) * 2 + -2;
  if (6 < uVar14) {
    uVar14 = 6;
  }
  FUN_08007f24(0xd,0x7f,0xe3,0x139,*(undefined2 *)(DAT_0800b5dc + 0x1a));
  local_30 = param_1 * -3;
  uVar13 = 0;
  do {
    if (uVar14 <= uVar13) {
      return;
    }
    FUN_08014af4(auStack_4c,&DAT_0800b5e0,uVar13 + (param_1 + -1) * 6 + 1);
    local_34 = uVar13 * 0xf;
    iVar12 = uVar13 * 0x1e + 0x8c;
    FUN_080082f2(0xe,iVar12,auStack_4c,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    local_2c = iVar11 + local_30 * 4;
    iVar2 = local_2c + 0xc;
    if (iVar2 < 0) {
      iVar2 = local_2c + 0x48;
    }
    iVar2 = DAT_0800b5d8 + (iVar2 % 0x3c) * 2;
    bVar15 = *(byte *)(iVar2 + 0x14) & 0x3f;
    switch(bVar15) {
    case 0:
      if (*(char *)(iVar1 + 0x20) != '\0') {
        uVar17 = *(undefined2 *)(iVar1 + 0x1a);
        iVar4 = local_34 * 2 + 0x8d;
        uVar10 = *(undefined2 *)(iVar1 + 0x1c);
        uVar5 = 0x40;
        uVar3 = DAT_0800b5e4;
        break;
      }
      puVar6 = &DAT_0800b5e8;
LAB_0800b41a:
      FUN_08014af4(auStack_4c,puVar6);
      goto switchD_0800b284_caseD_8;
    case 1:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b5f8;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8e;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x3e;
      uVar3 = DAT_0800b5f4;
      break;
    case 2:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b628;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8d;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x46;
      uVar3 = DAT_0800b624;
      break;
    case 3:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b658;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8d;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x46;
      uVar3 = DAT_0800b654;
      break;
    case 4:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b648;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8d;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x43;
      uVar3 = DAT_0800b644;
      break;
    case 5:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b638;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8d;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x43;
      uVar3 = DAT_0800b634;
      break;
    case 6:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b668;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8e;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x41;
      uVar3 = DAT_0800b664;
      break;
    case 7:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b678;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8b;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x42;
      uVar3 = DAT_0800b674;
      break;
    default:
      goto switchD_0800b284_caseD_8;
    case 10:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b608;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8e;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x3e;
      uVar3 = DAT_0800b604;
      break;
    case 0xb:
      if (*(char *)(iVar1 + 0x20) == '\0') {
        puVar6 = &DAT_0800b618;
        goto LAB_0800b41a;
      }
      uVar17 = *(undefined2 *)(iVar1 + 0x1a);
      iVar4 = local_34 * 2 + 0x8e;
      uVar10 = *(undefined2 *)(iVar1 + 0x1c);
      uVar5 = 0x3e;
      uVar3 = DAT_0800b614;
    }
    FUN_08007c6c(uVar3,uVar5,iVar4,uVar10,uVar17,1);
switchD_0800b284_caseD_8:
    if (*(char *)(iVar1 + 0x20) == '\0') {
      FUN_080082f2(0x2a,iVar12,auStack_4c,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    }
    FUN_08014af4(auStack_4c,&DAT_0800b684);
    iVar4 = local_2c + 0xd;
    if (iVar4 < 0) {
      iVar4 = local_2c + 0x49;
    }
    iVar4 = FUN_0801589c(*(undefined2 *)(DAT_0800b5d8 + (iVar4 % 0x3c) * 2 + 0x14));
    if ((bVar15 == 7) && (*(char *)(iVar1 + 0x21) == '\x01')) {
      uVar16 = FUN_08015548();
      uVar16 = FUN_080150f4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_0800b688,DAT_0800b68c);
      FUN_08014ba4((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,DAT_0800b690);
      iVar4 = FUN_08014b40();
    }
    if (iVar4 < DAT_0800b694) {
      uVar7 = (*(ushort *)(iVar2 + 0x14) & 0x7fff) >> 0xd;
      if (uVar7 == 1) {
        iVar8 = DAT_0800b6ac;
LAB_0800b4cc:
        iVar4 = FUN_08015670(iVar4,iVar8);
      }
      else {
        if (uVar7 == 2) {
          iVar8 = DAT_0800b6b0;
          goto LAB_0800b4cc;
        }
        if (uVar7 == 3) {
          iVar8 = DAT_0800b6b4;
          goto LAB_0800b4cc;
        }
      }
      if (iVar4 < DAT_0800b6b4) {
        if (iVar4 < DAT_0800b6b0) {
          if (iVar4 < DAT_0800b6ac) {
            uVar16 = FUN_08015548();
            pcVar9 = s__0_3f_0800b6d0;
          }
          else {
            uVar16 = FUN_08015548();
            pcVar9 = s__0_2f_0800b6c8;
          }
        }
        else {
          uVar16 = FUN_08015548();
          pcVar9 = s__0_1f_0800b6c0;
        }
      }
      else {
        uVar16 = FUN_08015548();
        pcVar9 = s__0_0f_0800b6b8;
      }
      FUN_08014af4(auStack_4c,pcVar9,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
      if ((int)((uint)*(ushort *)(iVar2 + 0x14) << 0x13) < 0) {
        FUN_0800755e(auStack_40,auStack_4c);
        FUN_08014af4(auStack_4c,&DAT_0800b6d8,auStack_40);
      }
    }
    else {
      if (iVar4 == DAT_0800b698) {
        puVar6 = &DAT_0800b69c;
      }
      else {
        if (iVar4 != DAT_0800b6a0) {
          if (iVar4 == DAT_0800b694) {
            puVar6 = &DAT_0800b6a8;
            goto LAB_0800b4a8;
          }
          goto LAB_0800b534;
        }
        puVar6 = &DAT_0800b6a4;
      }
LAB_0800b4a8:
      FUN_08014af4(auStack_4c,puVar6);
    }
LAB_0800b534:
    FUN_080082f2(0x8a,iVar12,auStack_4c,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    FUN_08014af4(auStack_4c,&DAT_0800b684);
    switch((*(ushort *)(iVar2 + 0x14) & 0xfff) >> 6) {
    case 3:
      puVar6 = &DAT_0800b6dc;
      break;
    default:
      goto switchD_0800b568_caseD_4;
    case 6:
      puVar6 = &DAT_0800b6e0;
      break;
    case 7:
      puVar6 = &DAT_0800b6e4;
      break;
    case 8:
      puVar6 = &DAT_0800b6e8;
      break;
    case 9:
      puVar6 = &DAT_0800b6ec;
      break;
    case 10:
      puVar6 = &DAT_0800b6f0;
      break;
    case 0xb:
      puVar6 = &DAT_0800b6f4;
      break;
    case 0xc:
      puVar6 = &DAT_0800b6f8;
      break;
    case 0xd:
      puVar6 = &DAT_0800b6fc;
      break;
    case 0xe:
      puVar6 = &DAT_0800b700;
      break;
    case 0xf:
      puVar6 = &DAT_0800b704;
      break;
    case 0x10:
      if (*(char *)(iVar1 + 0x21) == '\0') {
        puVar6 = &DAT_0800b72c;
      }
      else {
        puVar6 = &DAT_0800b708;
      }
    }
    FUN_08014af4(auStack_4c,puVar6);
switchD_0800b568_caseD_4:
    FUN_080082f2(0xc2,iVar12,auStack_4c,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    if (iVar11 == 0) {
      iVar11 = 0x3a;
    }
    else if (iVar11 == 1) {
      iVar11 = 0x3b;
    }
    else {
      iVar11 = iVar11 + -2;
    }
    uVar13 = uVar13 + 1 & 0xff;
  } while( true );
}


// ===== FUN_0800beb0 @ 0800beb0

void FUN_0800beb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  switch(*(undefined1 *)(DAT_0800bf8c + 0xd)) {
  case 2:
    puVar1 = &DAT_0800bf90;
    break;
  case 3:
    puVar1 = &DAT_0800bf94;
    break;
  case 4:
    puVar1 = &DAT_0800bfa0;
    break;
  case 5:
    puVar1 = &DAT_0800bf9c;
    break;
  case 6:
    puVar1 = &DAT_0800bf98;
    break;
  case 7:
    puVar1 = &DAT_0800bfac;
    break;
  case 8:
    puVar1 = &DAT_0800bfa8;
    break;
  case 9:
    puVar1 = &DAT_0800bfa4;
    break;
  case 10:
    puVar1 = &DAT_0800bfb4;
    break;
  case 0xb:
    puVar1 = &DAT_0800bfb0;
    break;
  case 0xc:
    puVar1 = &DAT_0800bfb8;
    break;
  case 0xd:
    puVar1 = &DAT_0800bfc4;
    break;
  case 0xe:
    puVar1 = &DAT_0800bfc0;
    break;
  case 0xf:
    puVar1 = &DAT_0800bfbc;
    break;
  case 0x10:
    puVar1 = &DAT_0800bfc8;
    break;
  default:
    goto switchD_0800bec0_default;
  }
  FUN_080082f2(param_1,param_2,puVar1,param_3,param_4,0x18,0);
switchD_0800bec0_default:
  return;
}


// ===== FUN_0800bfcc @ 0800bfcc

void FUN_0800bfcc(void)

{
  undefined *puVar1;
  
  switch(*(undefined1 *)(DAT_0800c0b0 + 0xd)) {
  case 3:
    puVar1 = &DAT_0800c0b4;
    break;
  case 4:
    puVar1 = &DAT_0800c0c0;
    break;
  case 5:
    puVar1 = &DAT_0800c0bc;
    break;
  case 6:
    puVar1 = &DAT_0800c0b8;
    break;
  case 7:
    puVar1 = &DAT_0800c0cc;
    break;
  case 8:
    puVar1 = &DAT_0800c0c8;
    break;
  case 9:
    puVar1 = &DAT_0800c0c4;
    break;
  case 10:
    puVar1 = &DAT_0800c0d4;
    break;
  case 0xb:
    puVar1 = &DAT_0800c0d0;
    break;
  case 0xc:
    puVar1 = &DAT_0800c0d8;
    break;
  case 0xd:
    puVar1 = &DAT_0800c0e4;
    break;
  case 0xe:
    puVar1 = &DAT_0800c0e0;
    break;
  case 0xf:
    puVar1 = &DAT_0800c0dc;
    break;
  case 0x10:
    if (*(char *)(DAT_0800c0e8 + 0x21) == '\0') {
      puVar1 = &DAT_0800c0f0;
    }
    else {
      puVar1 = &DAT_0800c0ec;
    }
    break;
  default:
    goto switchD_0800bfde_default;
  }
  FUN_0800839e(0xce,0x1e,puVar1,0,0,0x18,1);
switchD_0800bfde_default:
  return;
}


// ===== FUN_0800c0f4 @ 0800c0f4

void FUN_0800c0f4(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  
  switch(*(undefined1 *)(DAT_0800c1bc + 0xd)) {
  case 3:
    puVar1 = &DAT_0800c1c0;
    break;
  case 4:
    puVar1 = &DAT_0800c1cc;
    break;
  case 5:
    puVar1 = &DAT_0800c1c8;
    break;
  case 6:
    puVar1 = &DAT_0800c1c4;
    break;
  case 7:
    puVar1 = &DAT_0800c1d8;
    break;
  case 8:
    puVar1 = &DAT_0800c1d4;
    break;
  case 9:
    puVar1 = &DAT_0800c1d0;
    break;
  case 10:
    puVar1 = &DAT_0800c1e0;
    break;
  case 0xb:
    puVar1 = &DAT_0800c1dc;
    break;
  case 0xc:
    puVar1 = &DAT_0800c1e4;
    break;
  case 0xd:
    puVar1 = &DAT_0800c1f0;
    break;
  case 0xe:
    puVar1 = &DAT_0800c1ec;
    break;
  case 0xf:
    puVar1 = &DAT_0800c1e8;
    break;
  case 0x10:
    if (*(char *)(DAT_0800c1f4 + 0x21) == '\0') {
      puVar1 = &DAT_0800c1fc;
    }
    else {
      puVar1 = &DAT_0800c1f8;
    }
    break;
  default:
    goto switchD_0800c10c_default;
  }
  FUN_080082f2(param_1,param_2,puVar1,0xf79e,0x153f,0x10,0);
switchD_0800c10c_default:
  return;
}


// ===== FUN_0800c200 @ 0800c200

void FUN_0800c200(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0800ee28(DAT_0800c250,s_2_UI_cel__0800c244);
  *(char *)(DAT_0800c254 + 2) = (char)iVar2;
  iVar1 = DAT_0800c258;
  if (iVar2 == 0) {
    *(undefined1 *)(DAT_0800c258 + 0x18) = 1;
    if (*(char *)(iVar1 + 0x26) != '\0') {
      *(undefined2 *)(iVar1 + 0x1a) = 0xf79e;
      *(undefined2 *)(iVar1 + 0x1c) = 0;
      *(undefined2 *)(iVar1 + 0x1e) = 0xe73c;
      return;
    }
  }
  else {
    *(undefined1 *)(DAT_0800c258 + 0x18) = 0;
  }
  *(undefined1 *)(iVar1 + 0x26) = 0;
  *(undefined2 *)(iVar1 + 0x1a) = 0;
  *(undefined2 *)(iVar1 + 0x1c) = 0xf79e;
  *(undefined2 *)(iVar1 + 0x1e) = 0x3186;
  return;
}


// ===== FUN_0800c25c @ 0800c25c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c25c(int param_1)

{
  char *pcVar1;
  
  if (*(char *)(_DAT_0800c28c + 0x26) == '\0') {
    if (param_1 == 0) {
      pcVar1 = s_2__UI_decorate_ledoff_jpg_0800c2c0;
    }
    else {
      pcVar1 = s_2__UI_decorate_led_jpg_0800c2a8;
    }
  }
  else if (param_1 == 0) {
    pcVar1 = s_2__UI_decorat_ledoff_jpg_0800c2dc;
  }
  else {
    pcVar1 = s_2__UI_decorat_led_jpg_0800c28f + 1;
  }
  FUN_08010274(pcVar1,0x5e,0);
  return;
}


// ===== FUN_0800c2f8 @ 0800c2f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c2f8(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  iVar4 = _DAT_0800c37c;
  iVar3 = DAT_0800c378;
  bVar8 = *(char *)(*(int *)(DAT_0800c374 + 4) + 1) == 'L';
  *(bool *)(DAT_0800c378 + 7) = bVar8;
  if (bVar8 == (bool)*(char *)(iVar4 + 1)) {
    return;
  }
  *(bool *)(iVar4 + 1) = bVar8;
  uVar1 = *(undefined2 *)(iVar3 + 0x1a);
  FUN_08007f24(0,0x5f,0xf0,0xd2);
  cVar2 = *(char *)(iVar3 + 0x26);
  if (*(char *)(iVar4 + 1) == '\x01') {
    uVar7 = 0x9e;
    uVar6 = 0;
    if (cVar2 == '\0') {
      pcVar5 = s_2__UI_decorate_ncv0_jpg_0800c3c8;
    }
    else {
      pcVar5 = s_2__UI_decorat_ncv0_jpg_0800c3b0;
    }
  }
  else if (cVar2 == '\0') {
    FUN_08010274(s_2__UI_decorate_ncv3_jpg_0800c3e0,0,0xb9);
    uVar7 = 0x69;
    uVar6 = 0x32;
    pcVar5 = s_2__UI_decorate_live_jpg_0800c3f8;
  }
  else {
    FUN_08010274(s_2__UI_decorat_ncv3_jpg_0800c37f + 1,0,0xb9);
    uVar7 = 0x69;
    uVar6 = 0x32;
    pcVar5 = s_2__UI_decorat_live_jpg_0800c398;
  }
  FUN_08010274(pcVar5,uVar6,uVar7,uVar1);
  return;
}


// ===== FUN_0800c58c @ 0800c58c

void FUN_0800c58c(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_0800c5e4;
  FUN_08007fc8(0x37,0x9c,0xb9,0xad,2,*(undefined2 *)(DAT_0800c5e4 + 0x1a));
  if (param_2 == 0) {
    uVar2 = *(undefined2 *)(iVar1 + 0x1c);
  }
  else {
    uVar2 = 0x1c9f;
  }
  FUN_08007fc8(0x37,0x9c,param_1 * 0xd + 0x37,0xad,2,uVar2);
  FUN_08007e88(0x37,0x9b,0xba,0xad,2,0x3186);
  return;
}


// ===== FUN_0800c5e8 @ 0800c5e8

void FUN_0800c5e8(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  char *pcVar4;
  int iVar5;
  byte *pbVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined1 *puVar12;
  undefined *puVar13;
  char cVar14;
  undefined4 uVar15;
  undefined4 in_r3;
  undefined4 extraout_r3;
  char *pcVar16;
  bool bVar17;
  undefined8 uVar18;
  undefined1 auStack_34 [20];
  uint local_20;
  
  pbVar6 = DAT_0800c634;
  iVar5 = DAT_0800c630;
  pcVar4 = DAT_0800c62c;
  if (DAT_0800c62c[1] != '\0') {
    bVar3 = *(byte *)(DAT_0800c630 + 0x25);
    *DAT_0800c634 = bVar3;
    if (2 < bVar3) {
      *pbVar6 = 0;
    }
    if (0xb < *(byte *)(iVar5 + 0x24)) {
      *(undefined1 *)(iVar5 + 0x24) = 10;
    }
    FUN_0800909c();
    pcVar4[1] = '\0';
    in_r3 = extraout_r3;
  }
  iVar5 = DAT_0800c7a4;
  pcVar16 = DAT_0800c7a0;
  pcVar11 = DAT_0800bb18;
  if (*pcVar4 == '\0') {
    pcVar16 = DAT_0800bb18 + -3;
    *(char **)(DAT_0800bb18 + 0x11) = DAT_0800bb18;
    FUN_08012440();
    pcVar4 = DAT_0800bb20;
    iVar5 = DAT_0800bb1c;
    if (pcVar11[2] == '\0') {
      uVar1 = *(undefined2 *)(DAT_0800bb1c + 0x1a);
      uVar15 = 0;
LAB_0800b774:
      FUN_08007f24(0,uVar15,0xf0,0x140,uVar1);
      if ((((*pcVar11 == '\t') || (*pcVar11 == '\b')) && (pcVar11[-1] != '\x02')) ||
         (FUN_0800a1bc(pcVar11[-1]), pcVar11[-1] != '\x02')) {
        FUN_0800a5e0(**(undefined1 **)(pcVar11 + 0x11));
        FUN_0800a758(**(undefined1 **)(pcVar11 + 0x11));
      }
      if (pcVar11[3] == '\0') {
        FUN_0800a124(pcVar4[0xe]);
        FUN_0800abe0(*(undefined1 *)(iVar5 + 4));
        FUN_0800c25c(*(undefined1 *)(iVar5 + 3));
      }
      if (((*pcVar11 != '\t') && (*pcVar11 != '\b')) && (pcVar11[-1] == '\0')) {
        FUN_0800a500();
        FUN_0800a1bc(pcVar11[-1]);
      }
      pcVar11[2] = '\x01';
      pcVar11[3] = '\0';
    }
    else if (pcVar11[3] == '\x01') {
      uVar1 = *(undefined2 *)(DAT_0800bb1c + 0x1a);
      uVar15 = 0x24;
      goto LAB_0800b774;
    }
    if (pcVar11[-1] != '\x02') {
      FUN_0800b00c(*(undefined4 *)(pcVar11 + 0x11));
      if (*pcVar11 == '\t') {
        FUN_0800d27c();
      }
      else {
        *pcVar16 = '\0';
      }
      if (*pcVar11 == '\b') {
        FUN_0800c2f8();
      }
      else {
        pcVar11[-2] = '\0';
      }
      if (*pcVar11 == '\n') {
        uVar10 = *(uint *)(iVar5 + 0x14) & 0x7f800000;
        if (*(char *)(iVar5 + 2) == '\x11') {
          if (uVar10 == 0) {
            *(uint *)(iVar5 + 0x14) = *(uint *)(pcVar4 + 8) ^ 0x80000000;
            uVar1 = *(undefined2 *)(iVar5 + 0x1c);
            goto LAB_0800b828;
          }
          *(undefined4 *)(iVar5 + 0x14) = 0;
        }
        else if (uVar10 != 0) {
          uVar1 = *(undefined2 *)(iVar5 + 0x1a);
LAB_0800b828:
          FUN_08007c6c(DAT_0800bb24,0x9d,6,0xfc60,uVar1,0);
          goto LAB_0800b84e;
        }
      }
      FUN_08007f24(0x9d,6,0xae,0x17,*(undefined2 *)(iVar5 + 0x1a));
    }
LAB_0800b84e:
    uVar15 = DAT_0800bb2c;
    cVar7 = *(char *)(iVar5 + 2);
    if (cVar7 == '\x06') {
      if ((*pcVar11 != '\t') && (*pcVar11 != '\b')) {
        pcVar11[3] = '\x01';
      }
      if (pcVar11[-1] == '\x02') {
        iVar8 = FUN_08012868(0xc);
        if (iVar8 == 1) {
          pcVar11[-1] = '\0';
          **(undefined1 **)(pcVar11 + 0x11) = 0;
        }
      }
      else {
        pcVar11[-1] = pcVar11[-1] == '\0';
      }
      if (pcVar4[0xe] == '\x01') {
        pcVar4[0xe] = '\0';
        FUN_0800a124(0);
      }
    }
    else if (cVar7 == '\n') {
      if (pcVar11[-1] == '\x02') {
        uVar15 = 0;
        cVar7 = **(char **)(pcVar11 + 0x11);
        if (cVar7 == '\0') {
          uVar15 = 0xc;
        }
        else if (cVar7 == '\x01') {
          uVar15 = 0xd;
        }
        else if (cVar7 == '\x02') {
          uVar15 = 0xb;
        }
        else if (cVar7 == '\x03') {
          uVar15 = 0x14;
        }
        else if (cVar7 == '\x04') {
          uVar15 = 0xe;
        }
        else if (cVar7 == '\x05') {
          uVar15 = 10;
        }
        else if (cVar7 == '\x06') {
          uVar15 = 0xf;
        }
        else if (cVar7 == '\a') {
          uVar15 = 0x12;
        }
        else if (cVar7 == '\b') {
          uVar15 = 0x13;
        }
        else if (cVar7 == '\t') {
          uVar15 = 9;
        }
        else if (cVar7 == '\n') {
          uVar15 = 0x10;
        }
        else if (cVar7 == '\v') {
          uVar15 = 0x11;
        }
        iVar8 = FUN_08012868(uVar15);
        if (iVar8 == 1) {
          cVar7 = pcVar11[5];
          goto LAB_0800b93c;
        }
      }
      else {
        iVar8 = FUN_08012868(0x15);
        if (iVar8 == 1) {
          *pcVar16 = '\0';
          pcVar11[-2] = '\0';
          pcVar11[5] = pcVar11[-1];
          cVar7 = '\x02';
LAB_0800b93c:
          pcVar11[-1] = cVar7;
        }
      }
      pcVar11[3] = '\x01';
    }
    else if (cVar7 == '\x0e') {
      *DAT_0800bb28 = 1;
      pcVar11[2] = '\0';
      *pcVar16 = '\0';
      pcVar11[-2] = '\0';
    }
    else if (cVar7 == '\x11') {
      pcVar4[0x18] = '\0';
      pcVar4[0x19] = '\0';
      pcVar4[0x1a] = '\0';
      pcVar4[0x1b] = '\0';
      *(undefined4 *)(pcVar4 + 0x1c) = uVar15;
      uVar15 = DAT_0800bb30;
      pcVar4[0x20] = '\0';
      pcVar4[0x21] = '\0';
      pcVar4[0x22] = '\0';
      pcVar4[0x23] = '\0';
      *(undefined4 *)(pcVar4 + 0x24) = uVar15;
    }
    if (*(char *)(iVar5 + 4) != pcVar11[1]) {
      FUN_0800abe0();
      pcVar11[1] = *(char *)(iVar5 + 4);
    }
    if (*(char *)(iVar5 + 5) == '\x01') {
      FUN_08007f24(0,0,0xf0,0x140,*(undefined2 *)(iVar5 + 0x1a));
      pcVar11[3] = '\x01';
      *(undefined1 *)(iVar5 + 5) = 0;
      *pcVar16 = '\0';
      pcVar11[-2] = '\0';
      pcVar4[0xe] = '\0';
      FUN_0800a124(0);
      FUN_0800c25c(*(undefined1 *)(iVar5 + 3));
      FUN_0800abe0(*(undefined1 *)(iVar5 + 4));
    }
    uVar10 = DAT_0800bb38;
    iVar8 = DAT_0800bb34;
    cVar7 = *pcVar11;
    bVar17 = cVar7 == '\t';
    do {
      if (bVar17) goto LAB_0800bc24;
      bVar17 = true;
    } while (cVar7 == '\b');
    if (pcVar11[-1] == '\0') {
      if (*(char *)(iVar5 + 10) == '\x01') {
        *(undefined1 *)(iVar5 + 10) = 0;
        if (cVar7 == '\a') {
          if (*pcVar4 != '\x01') goto LAB_0800ba22;
          if (*(char *)(iVar5 + 0x21) != '\0') {
            FUN_08009534(*(undefined4 *)(pcVar4 + 8));
          }
          iVar8 = FUN_080157f4();
          if (iVar8 < 0) {
            iVar8 = -iVar8;
            pcVar16 = s___04d_0800bb3c;
          }
          else {
            pcVar16 = s__04d_0800bb44;
          }
          FUN_08014af4(auStack_34,pcVar16,iVar8);
LAB_0800ba18:
          puVar12 = auStack_34;
        }
        else {
          if ((cVar7 == '\n') && (*pcVar4 == '\x01')) {
            uVar9 = FUN_080155a0(*(undefined4 *)(pcVar4 + 8),*(undefined4 *)(iVar5 + 0x14));
            if (uVar9 < 0x80800000) {
              if ((int)uVar9 < iVar8) {
                uVar18 = FUN_08015548();
                pcVar16 = s__0_2f_0800bb54;
              }
              else {
                uVar18 = FUN_08015548();
                pcVar16 = s__0_1f_0800bb4c;
              }
            }
            else if (uVar9 < uVar10) {
              uVar18 = FUN_08015548();
              pcVar16 = s__0_2f_0800bb64;
            }
            else {
              uVar18 = FUN_08015548();
              pcVar16 = s__0_1f_0800bb5c;
            }
            FUN_08014af4(auStack_34,pcVar16,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
            goto LAB_0800ba18;
          }
LAB_0800ba22:
          puVar12 = *(undefined1 **)(pcVar4 + 4);
        }
        FUN_0800dd6c(0,0,puVar12);
        FUN_0800bfcc();
        FUN_0800e894(0,0x72);
        if ((*pcVar4 != '\0') && (pcVar4[0x2a] == '\0')) {
          FUN_08010c88(*pcVar11);
        }
      }
      if (*(char *)(iVar5 + 2) == '\r') {
        FUN_08012338();
        if (*(char *)(iVar5 + 0x20) == '\0') {
          pcVar16 = &DAT_0800bb78;
          uVar15 = 0x60;
        }
        else {
          pcVar16 = s_Data_saved_0800bb6c;
          uVar15 = 0x50;
        }
        FUN_080082f2(uVar15,0x1e,pcVar16,0x400,*(undefined2 *)(iVar5 + 0x1a),0x10,1);
        FUN_08009d18(500);
        if (*(char *)(iVar5 + 0x20) == '\0') {
          pcVar16 = &DAT_0800bb78;
          uVar15 = 0x60;
        }
        else {
          pcVar16 = s_Data_saved_0800bb6c;
          uVar15 = 0x50;
        }
        FUN_080082f2(uVar15,0x1e,pcVar16,*(undefined2 *)(iVar5 + 0x1a),*(undefined2 *)(iVar5 + 0x1a)
                     ,0x10,1);
      }
    }
    else if (pcVar11[-1] == '\x01') {
      if (*(char *)(iVar5 + 10) == '\x01') {
        if (pcVar11[4] == '\0') {
          pcVar11[4] = '\r';
        }
        *(undefined1 *)(iVar5 + 10) = 0;
        if (cVar7 == '\a') {
          if (*pcVar4 != '\x01') goto LAB_0800bbac;
          if (*(char *)(iVar5 + 0x21) != '\0') {
            FUN_08009534(*(undefined4 *)(pcVar4 + 8));
          }
          uVar15 = FUN_080157f4();
          FUN_08014af4(auStack_34,s__04d_0800bb44,uVar15);
LAB_0800bbe0:
          puVar12 = auStack_34;
        }
        else {
          if ((cVar7 == '\n') && (*pcVar4 == '\x01')) {
            uVar9 = FUN_080155a0(*(undefined4 *)(pcVar4 + 8),*(undefined4 *)(iVar5 + 0x14));
            if ((iVar8 < (int)uVar9) || (uVar10 < uVar9)) {
              uVar18 = FUN_08015548();
              pcVar16 = s__0_1f_0800bb5c;
            }
            else {
              uVar18 = FUN_08015548();
              pcVar16 = s__0_2f_0800bb64;
            }
            FUN_08014af4(auStack_34,pcVar16,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
            goto LAB_0800bbe0;
          }
LAB_0800bbac:
          puVar12 = *(undefined1 **)(pcVar4 + 4);
        }
        FUN_0800d884(0,0,puVar12);
        FUN_0800e94c();
        FUN_0800c0f4(0x74,0x32);
        if ((*pcVar4 != '\0') && (pcVar4[0x2a] == '\0')) {
          FUN_08010c88(*pcVar11);
        }
      }
      if (pcVar11[4] != '\0') {
        FUN_0800e380();
        pcVar11[4] = pcVar11[4] + -1;
      }
      FUN_0800dfd8();
    }
LAB_0800bc24:
    if ((pcVar11[-1] != '\x02') || (*(char *)(iVar5 + 10) != '\x01')) goto LAB_0800be00;
    if (pcVar4[0xc] == '\x02') {
      if (*(char *)(iVar5 + 0x20) == '\0') {
        uVar1 = *(undefined2 *)(iVar5 + 0x1a);
        uVar2 = *(undefined2 *)(iVar5 + 0x1c);
        puVar13 = &DAT_0800be30;
        goto LAB_0800bcaa;
      }
      uVar1 = *(undefined2 *)(iVar5 + 0x1a);
      uVar2 = *(undefined2 *)(iVar5 + 0x1c);
      uVar15 = DAT_0800be2c;
LAB_0800bc50:
      FUN_08007c6c(uVar15,0x55,0xd0,uVar2,uVar1,1);
    }
    else {
      if (*(char *)(iVar5 + 0x20) != '\0') {
        uVar1 = *(undefined2 *)(iVar5 + 0x1a);
        uVar2 = *(undefined2 *)(iVar5 + 0x1c);
        uVar15 = DAT_0800be24;
        goto LAB_0800bc50;
      }
      uVar1 = *(undefined2 *)(iVar5 + 0x1a);
      uVar2 = *(undefined2 *)(iVar5 + 0x1c);
      puVar13 = &DAT_0800be3c;
LAB_0800bcaa:
      FUN_080082f2(0x38,0xd3,puVar13,uVar2,uVar1,0x20,0);
    }
    if (pcVar4[0x14] == '\0') {
      if (*(char *)(iVar5 + 0x20) == '\0') {
        uVar1 = *(undefined2 *)(iVar5 + 0x1a);
        uVar2 = *(undefined2 *)(iVar5 + 0x1c);
        puVar13 = &DAT_0800be4c;
        goto LAB_0800bce2;
      }
      uVar1 = *(undefined2 *)(iVar5 + 0x1a);
      uVar2 = *(undefined2 *)(iVar5 + 0x1c);
      uVar15 = DAT_0800be48;
LAB_0800bc70:
      FUN_08007c6c(uVar15,0x55,0x38,uVar2,uVar1,1);
    }
    else {
      if (*(char *)(iVar5 + 0x20) != '\0') {
        uVar1 = *(undefined2 *)(iVar5 + 0x1a);
        uVar2 = *(undefined2 *)(iVar5 + 0x1c);
        uVar15 = DAT_0800be28;
        goto LAB_0800bc70;
      }
      uVar1 = *(undefined2 *)(iVar5 + 0x1a);
      uVar2 = *(undefined2 *)(iVar5 + 0x1c);
      puVar13 = &DAT_0800be58;
LAB_0800bce2:
      FUN_080082f2(0x38,0x3a,puVar13,uVar2,uVar1,0x20,0);
    }
    *(undefined1 *)(iVar5 + 10) = 0;
    if (pcVar4[0x14] == '\0') {
      uVar10 = FUN_080155a0(*(undefined4 *)(pcVar4 + 0x10),*(undefined4 *)(iVar5 + 0x14));
      *(uint *)(pcVar4 + 0x10) = uVar10;
    }
    else {
      uVar10 = *(uint *)(pcVar4 + 0x10);
    }
    if ((DAT_0800be64 < (int)uVar10) || (DAT_0800be68 <= uVar10)) {
      uVar18 = FUN_08015548();
      pcVar11 = s__0_1f_0800bb4c;
    }
    else {
      uVar18 = FUN_08015548();
      pcVar11 = s__0_2f_0800bb54;
    }
    FUN_08014af4(auStack_34,pcVar11,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    FUN_08008a7c(0xdc,0x1d,&DAT_0800be6c,0xffe0,*(undefined2 *)(iVar5 + 0x1a),0x18,0);
    iVar8 = DAT_0800be70;
    if (*(int *)(pcVar4 + 0x10) < DAT_0800be70) {
      FUN_0800dd6c(0,0,auStack_34);
    }
    FUN_0800e894(0,0x62);
    FUN_0800dd6c(0,0,*(undefined4 *)(pcVar4 + 4));
    FUN_08008a7c(0xdc,0x1d,&DAT_0800be74,0xffe0,*(undefined2 *)(iVar5 + 0x1a),0x18,0);
    FUN_0800e894(0,0xf8);
    uVar10 = FUN_080158c4(*(undefined4 *)(pcVar4 + 0x10),*(undefined4 *)(pcVar4 + 8));
    if (0x807fffff < uVar10) {
      uVar10 = uVar10 ^ 0x80000000;
    }
    if ((int)uVar10 < iVar8) {
      uVar18 = FUN_08015548();
      pcVar11 = s__03_2f_W_0800be78;
    }
    else if ((int)uVar10 < DAT_0800be84) {
      FUN_08015670();
      uVar18 = FUN_08015548();
      pcVar11 = s__0_3f_KW_0800be88;
    }
    else if ((int)uVar10 < DAT_0800be94) {
      FUN_08015670();
      uVar18 = FUN_08015548();
      pcVar11 = s__0_2f_KW_0800be98;
    }
    else {
      FUN_08015670();
      uVar18 = FUN_08015548();
      pcVar11 = s__0_1f_KW_0800bea4;
    }
    FUN_08014af4(auStack_34,pcVar11,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    if (*(char *)(iVar5 + 0x26) == '\0') {
      uVar15 = 0xffe0;
    }
    else {
      uVar15 = 0;
    }
    FUN_080082f2(0x74,0xaa,auStack_34,uVar15,*(undefined2 *)(iVar5 + 0x1a),0x10,0);
LAB_0800be00:
    if (*(char *)(iVar5 + 2) == '\x02') {
      pcVar4[0xe] = pcVar4[0xe] == '\0';
      FUN_0800a124();
      FUN_08009450();
    }
    return;
  }
  local_20 = in_r3;
  if (*DAT_0800c7a0 == '\0') {
    local_20 = (uint)*(ushort *)(DAT_0800c7a4 + 0x1a);
    FUN_08007f24(0,0,0xf0,0x140);
    FUN_0800d1d8();
    local_20 = 0;
    FUN_08011ad4(1,1,0);
    *pcVar16 = '\x01';
    pcVar16[2] = '\0';
    pcVar16[3] = '\0';
    pcVar16[4] = '\0';
  }
  if (*(char *)(iVar5 + 5) == '\x01') {
    local_20 = (uint)*(ushort *)(iVar5 + 0x1a);
    FUN_08007f24(0,0,0xf0,0x140);
    if (pcVar16[3] == '\0') {
      FUN_0800d1d8();
      cVar7 = pcVar16[4] + '\x01';
      cVar14 = '\0';
    }
    else {
      FUN_0800d1d8();
      cVar7 = pcVar16[4] + '\x01';
      cVar14 = cVar7;
    }
    local_20 = 0;
    FUN_08011ad4(1,cVar7,0,cVar14);
  }
  if (pcVar16[3] == '\0') {
    cVar7 = *(char *)(iVar5 + 2);
    if ((cVar7 == '\x01') || (cVar7 == '\t')) {
      local_20 = 0;
      FUN_08011ad4(0,0,pcVar16[4] + '\x01');
      cVar7 = pcVar16[4];
      if (*(char *)(iVar5 + 2) == '\x01') {
        if (cVar7 == '\0') {
          cVar7 = '\x03';
        }
        else {
          cVar7 = cVar7 + -1;
        }
LAB_0800c6ec:
        pcVar16[4] = cVar7;
      }
      else {
        if (cVar7 != '\x03') {
          cVar7 = cVar7 + '\x01';
          goto LAB_0800c6ec;
        }
        pcVar16[4] = '\0';
      }
      local_20 = 0;
      FUN_08011ad4(0,pcVar16[4] + '\x01',0);
      FUN_0800e318(pcVar16[4]);
      pcVar16[2] = '\0';
      goto LAB_0800c708;
    }
    if (cVar7 != '\x05') goto LAB_0800c70e;
    local_20 = 0;
    FUN_08011ad4(0,0,0,pcVar16[4] + '\x01');
    pcVar16[3] = '\x01';
    pcVar16[1] = '\0';
    *(undefined1 *)(iVar5 + 2) = 0;
  }
  else {
LAB_0800c708:
    if (pcVar16[3] != '\x01') {
LAB_0800c70e:
      if (*(char *)(iVar5 + 5) != '\x01') goto LAB_0800c78a;
    }
  }
  cVar7 = pcVar16[4];
  if (cVar7 == '\0') {
    FUN_0800fd6c();
  }
  else if (cVar7 == '\x01') {
    FUN_08012f70();
  }
  else if (cVar7 == '\x02') {
    FUN_0800f138();
  }
  else if ((cVar7 == '\x03') && (*(char *)(iVar5 + 5) == '\x01')) {
    FUN_0800e318(4);
    *(undefined1 *)(iVar5 + 5) = 0;
  }
  if (*(char *)(iVar5 + 2) == '\r') {
    local_20 = (uint)(byte)(pcVar16[4] + 1);
    FUN_08011ad4(0,0,0);
    pcVar16[3] = '\0';
  }
LAB_0800c78a:
  if (*(char *)(iVar5 + 2) == '\x0e') {
    *DAT_0800c7a8 = 0;
    iVar5 = DAT_0800c7ac;
    *pcVar16 = '\0';
    *(undefined1 *)(iVar5 + 0xe) = 0;
  }
  return;
}


// ===== FUN_0800c7b0 @ 0800c7b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800c7b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined2 uVar6;
  uint uVar7;
  
  iVar2 = _DAT_0800c8fc;
  uVar7 = 0;
  FUN_08007f24(0xd,0x68,0xdf,0x134,*(undefined2 *)(_DAT_0800c8fc + 0x1a),param_3,param_4);
  FUN_0800e2e0(2);
  if (*(char *)(iVar2 + 0x20) == '\0') {
    pcVar5 = &DAT_0800c910;
    uVar3 = 0x58;
  }
  else {
    pcVar5 = s_AUTO_shut_down_0800c8ff + 1;
    uVar3 = 0x40;
  }
  FUN_080082f2(uVar3,0x78,pcVar5,*(undefined2 *)(iVar2 + 0x1c),0xf79e,0x10,1);
  FUN_08007e88(0x20,0x98,0xcf,0x124,5,0x3186);
  do {
    if (*(byte *)(iVar2 + 0x22) == uVar7) {
      iVar4 = uVar7 * 0x1f;
      FUN_08007f24(0x3b,iVar4 + 0xa6,0x4f,iVar4 + 0xb9,0x1c9f);
      cVar1 = *(char *)(iVar2 + 0x22);
      if (cVar1 == '\0') {
        pcVar5 = &DAT_0800c91c;
LAB_0800c862:
        iVar4 = iVar4 + 0xa8;
        uVar6 = 0x1c9f;
        uVar3 = 0x1c9f;
        goto LAB_0800c8ea;
      }
      if (cVar1 == '\x01') {
        pcVar5 = &DAT_0800c920;
        goto LAB_0800c862;
      }
      if (cVar1 == '\x02') {
        pcVar5 = s_15min_0800c928;
        goto LAB_0800c862;
      }
      if (cVar1 == '\x03') {
        pcVar5 = s_30min_0800c930;
        goto LAB_0800c862;
      }
    }
    else {
      FUN_08007e44(0x3b,uVar7 * 0x1f + 0xa6,0x4f,uVar7 * 0x1f + 0xb9,*(undefined2 *)(iVar2 + 0x1c));
      if (uVar7 == 0) {
        uVar6 = *(undefined2 *)(iVar2 + 0x1c);
        iVar4 = 0xa8;
        pcVar5 = &DAT_0800c91c;
      }
      else if (uVar7 == 1) {
        uVar6 = *(undefined2 *)(iVar2 + 0x1c);
        iVar4 = 199;
        pcVar5 = &DAT_0800c920;
      }
      else if (uVar7 == 2) {
        uVar6 = *(undefined2 *)(iVar2 + 0x1c);
        iVar4 = 0xe6;
        pcVar5 = s_15min_0800c928;
      }
      else {
        if (uVar7 != 3) goto LAB_0800c8ee;
        uVar6 = *(undefined2 *)(iVar2 + 0x1c);
        iVar4 = 0x105;
        pcVar5 = s_30min_0800c930;
      }
      uVar3 = 0xf79e;
LAB_0800c8ea:
      FUN_080082f2(0x5c,iVar4,pcVar5,uVar6,uVar3,0x10,1);
    }
LAB_0800c8ee:
    uVar7 = uVar7 + 1 & 0xff;
    if (3 < uVar7) {
      return;
    }
  } while( true );
}


// ===== FUN_0800c938 @ 0800c938

void FUN_0800c938(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined2 uVar4;
  
  iVar1 = DAT_0800ca3c;
  FUN_08007f24(0xd,0x68,0xdf,0x139,*(undefined2 *)(DAT_0800ca3c + 0x1a),param_3,param_4);
  FUN_08007c6c(DAT_0800ca40,0x6c,0x81,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
  FUN_0800e2e0(0);
  if (*(char *)(iVar1 + 0x20) == '\0') {
    pcVar3 = &DAT_0800ca64;
    uVar2 = 0x62;
  }
  else {
    pcVar3 = s_Language_0800ca44;
    uVar2 = 0x5d;
  }
  FUN_080082f2(uVar2,0x9e,pcVar3,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
  FUN_08007e88(0x2b,0xc2,0xcb,0x10e,5,0x3186);
  if (*(char *)(iVar1 + 0x20) == '\0') {
    FUN_08007f24(0x41,0xca,0x55,0xde,0x1c9f);
    FUN_08007e44(0x41,0xf3,0x55,0x107,*(undefined2 *)(iVar1 + 0x1c));
    FUN_080082f2(0x6a,0xcb,&DAT_0800ca50,0x1c9f,0x1c9f,0x10,1);
    uVar2 = 0xf79e;
    uVar4 = *(undefined2 *)(iVar1 + 0x1c);
  }
  else {
    FUN_08007f24(0x41,0xf3,0x55,0x107,0x1c9f);
    FUN_08007e44(0x41,0xca,0x55,0xde,*(undefined2 *)(iVar1 + 0x1c));
    FUN_080082f2(0x6a,0xcb,&DAT_0800ca50,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    uVar2 = 0x1c9f;
    uVar4 = 0x1c9f;
  }
  FUN_080082f2(0x6a,0xf4,s_English_0800ca5c,uVar4,uVar2,0x10,1);
  return;
}


// ===== FUN_0800ca6c @ 0800ca6c

void FUN_0800ca6c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  
  iVar1 = DAT_0800cbec;
  FUN_08007f24(0xd,0x68,0xdf,0x134,*(undefined2 *)(DAT_0800cbec + 0x1a),param_3,param_4);
  FUN_0800c58c(*(char *)(iVar1 + 0x23) + '\x01',param_1);
  FUN_0800e2e0(1);
  uVar4 = 0x3186;
  FUN_08007e88(0x29,0xf0,0xc9,0x129,5,0x3186);
  if (*(char *)(iVar1 + 0x21) == '\0') {
    FUN_08007f24(0x39,0x105,0x4c,0x118,0x1c9f,uVar4,param_4);
    FUN_08007e44(0x8c,0x105,0x9f,0x118,*(undefined2 *)(iVar1 + 0x1c));
    FUN_080082f2(0x54,0x108,&DAT_0800cbf0,0x1c9f,0x1c9f,0x10,1);
    uVar4 = 0xf79e;
    uVar3 = *(undefined2 *)(iVar1 + 0x1c);
  }
  else {
    FUN_08007e44(0x39,0x105,0x4c,0x118,*(undefined2 *)(iVar1 + 0x1c));
    FUN_08007f24(0x8c,0x105,0x9f,0x118,0x1c9f);
    FUN_080082f2(0x54,0x108,&DAT_0800cbf0,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    uVar4 = 0x1c9f;
    uVar3 = 0x1c9f;
  }
  FUN_080082f2(0xa9,0x108,&DAT_0800cbf4,uVar3,uVar4,0x10,1);
  if (*(char *)(iVar1 + 0x20) == '\0') {
    FUN_08007c6c(DAT_0800cbf8,0x4f,0x77,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
    FUN_08007c6c(DAT_0800cbfc,0x46,0xd7,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
    FUN_080082f2(0x74,0x7c,&DAT_0800cc20,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    uVar3 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar2 = &DAT_0800cc28;
    uVar4 = 0x5e;
  }
  else {
    FUN_08007c6c(DAT_0800cbf8,0x3d,0x77,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
    FUN_08007c6c(DAT_0800cbfc,0x2f,0xd7,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
    FUN_080082f2(0x62,0x7c,s_Brightness_0800cc00,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
    uVar3 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar2 = s_Temperature_unit_0800cc0c;
    uVar4 = 0x47;
  }
  FUN_080082f2(uVar4,0xd9,pcVar2,uVar3,0xf79e,0x10,1);
  return;
}


// ===== FUN_0800cc34 @ 0800cc34

void FUN_0800cc34(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar9 = 0;
  iVar11 = param_2;
  uVar3 = param_4;
  switch(param_1) {
  default:
    goto switchD_0800cc54_caseD_0;
  case 1:
    uVar8 = 0xe1;
    uVar4 = 0xc6;
    goto LAB_0800cc70;
  case 2:
    uVar8 = 0x10a;
    uVar4 = 0xef;
LAB_0800cc70:
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
    uVar8 = 0x11d;
    uVar4 = 0x101;
    uVar2 = 0x85;
    break;
  case 6:
  case 7:
  case 8:
  case 9:
    uVar10 = param_1 - 6;
    do {
      if (uVar10 == uVar9) {
        FUN_08007e88(0x35,uVar9 * 0x1f + 0xa2,0xba,uVar9 * 0x1f + 0xbc,3,0x1c9f);
      }
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < 4);
    goto switchD_0800cc54_caseD_0;
  }
  FUN_08007e88(uVar2,uVar4,uVar5,uVar8,3,0x1c9f);
switchD_0800cc54_caseD_0:
  iVar1 = DAT_0800d0c0;
  switch(param_2) {
  default:
    goto switchD_0800ccca_caseD_0;
  case 1:
    uVar8 = 0xe1;
    uVar7 = *(undefined2 *)(DAT_0800d0c0 + 0x1a);
    uVar4 = 0xc6;
    goto LAB_0800ccea;
  case 2:
    uVar7 = *(undefined2 *)(DAT_0800d0c0 + 0x1a);
    uVar8 = 0x10a;
    uVar4 = 0xef;
LAB_0800ccea:
    uVar5 = 0xb7;
    uVar2 = 0x37;
    break;
  case 3:
    uVar7 = *(undefined2 *)(DAT_0800d0c0 + 0x1a);
    uVar8 = 0xb1;
    uVar5 = 0xcc;
    uVar4 = 0x97;
    uVar2 = 0x29;
    break;
  case 4:
    uVar7 = *(undefined2 *)(DAT_0800d0c0 + 0x1a);
    uVar5 = 0x6e;
    uVar8 = 0x11d;
    uVar4 = 0x101;
    uVar2 = 0x33;
    break;
  case 5:
    uVar7 = *(undefined2 *)(DAT_0800d0c0 + 0x1a);
    uVar5 = 0xc0;
    uVar8 = 0x11d;
    uVar4 = 0x101;
    uVar2 = 0x85;
    break;
  case 6:
  case 7:
  case 8:
  case 9:
    uVar9 = 0;
    do {
      if (param_2 - 6U == uVar9) {
        FUN_08007e88(0x35,uVar9 * 0x1f + 0xa2,0xba,uVar9 * 0x1f + 0xbc,3,
                     *(undefined2 *)(iVar1 + 0x1a));
      }
      uVar9 = uVar9 + 1 & 0xff;
    } while (uVar9 < 4);
    goto switchD_0800ccca_caseD_0;
  }
  FUN_08007e88(uVar2,uVar4,uVar5,uVar8,3,uVar7);
switchD_0800ccca_caseD_0:
  switch(param_4) {
  default:
    goto switchD_0800cd64_caseD_0;
  case 1:
    FUN_08007f24(0x41,0xca,0x55,0xde,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x41,0xca,0x55,0xde,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = &DAT_0800d0c4;
    uVar2 = 0xcb;
    goto LAB_0800cdd4;
  case 2:
    FUN_08007f24(0x41,0xf3,0x55,0x107,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x41,0xf3,0x55,0x107,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = s_English_0800d0d0;
    uVar2 = 0xf4;
LAB_0800cdd4:
    uVar4 = 0x6a;
    goto LAB_0800cdd8;
  case 3:
    FUN_0800c58c(*(char *)(iVar1 + 0x23) + '\x01',0);
    goto switchD_0800cd64_caseD_0;
  case 4:
    FUN_08007f24(0x39,0x105,0x4c,0x118,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x39,0x105,0x4c,0x118,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = &DAT_0800d0d8;
    uVar2 = 0x108;
    uVar4 = 0x54;
    goto LAB_0800cdd8;
  case 5:
    FUN_08007f24(0x8c,0x105,0x9f,0x118,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x8c,0x105,0x9f,0x118,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = &DAT_0800d0dc;
    uVar2 = 0x108;
    uVar4 = 0xa9;
    goto LAB_0800cdd8;
  case 6:
    FUN_08007f24(0x3b,0xa6,0x4f,0xb9,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x3b,0xa6,0x4f,0xb9,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = &DAT_0800d0e0;
    uVar2 = 0xa8;
    break;
  case 7:
    FUN_08007f24(0x3b,0xc5,0x4f,0xd8,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x3b,0xc5,0x4f,0xd8,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = &DAT_0800d0e4;
    uVar2 = 199;
    break;
  case 8:
    FUN_08007f24(0x3b,0xe4,0x4f,0xf7,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x3b,0xe4,0x4f,0xf7,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = s_15min_0800d0ec;
    uVar2 = 0xe6;
    break;
  case 9:
    FUN_08007f24(0x3b,0x103,0x4f,0x116,*(undefined2 *)(iVar1 + 0x1a));
    FUN_08007e44(0x3b,0x103,0x4f,0x116,*(undefined2 *)(iVar1 + 0x1c));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = s_30min_0800d0f4;
    uVar2 = 0x105;
  }
  uVar4 = 0x5c;
LAB_0800cdd8:
  FUN_080082f2(uVar4,uVar2,pcVar6,uVar7,0xf79e,0x10,1);
switchD_0800cd64_caseD_0:
  switch(param_3) {
  default:
    break;
  case 1:
    FUN_08007f24(0x41,0xca,0x55,0xde,0x1c9f);
    FUN_080082f2(0x6a,0xcb,&DAT_0800d0c4,0x1c9f,0x1c9f,0x10,1,param_1,iVar11,param_3,uVar3);
    *(undefined1 *)(iVar1 + 0x20) = 0;
    if (*(char *)(iVar1 + 0x26) == '\0') {
      pcVar6 = s_2__UI_decorate_menu_jpg_0800d128;
    }
    else {
      pcVar6 = s_2__UI_decorat_menu_jpg_0800d0fc;
    }
    FUN_08010274(pcVar6,5,0x41);
    FUN_080082f2(0x12,0x45,&DAT_0800d114,0xf79e,0xf79e,0x18,1);
    FUN_08007f24(0x5d,0x9e,0x9d,0xae,*(undefined2 *)(iVar1 + 0x1a));
    uVar7 = 0xf79e;
    pcVar6 = &DAT_0800d120;
    uVar3 = 0x62;
    goto LAB_0800d02a;
  case 2:
    FUN_08007f24(0x41,0xf3,0x55,0x107,0x1c9f);
    FUN_080082f2(0x6a,0xf4,s_English_0800d0d0,0x1c9f,0x1c9f,0x10,1);
    *(undefined1 *)(iVar1 + 0x20) = 1;
    if (*(char *)(iVar1 + 0x26) == '\0') {
      pcVar6 = s_2__UI_decorate_menu_jpg_0800d128;
    }
    else {
      pcVar6 = s_2__UI_decorat_menu_jpg_0800d0fc;
    }
    FUN_08010274(pcVar6,5,0x41);
    FUN_080082f2(10,0x48,s_System_settings_0800d140,0xf79e,0xf79e,0x10,1);
    FUN_08007f24(0x62,0x9e,0x92,0xae,*(undefined2 *)(iVar1 + 0x1a));
    uVar7 = *(undefined2 *)(iVar1 + 0x1c);
    pcVar6 = s_Language_0800d150;
    uVar3 = 0x5d;
LAB_0800d02a:
    FUN_080082f2(uVar3,0x9e,pcVar6,uVar7,0xf79e,0x10,1);
    break;
  case 3:
    FUN_0800c58c(*(char *)(iVar1 + 0x23) + '\x01',1);
    return;
  case 4:
    FUN_08007f24(0x39,0x105,0x4c,0x118,0x1c9f);
    FUN_080082f2(0x54,0x108,&DAT_0800d0d8,0x1c9f,0x1c9f,0x10,1);
    *(undefined1 *)(iVar1 + 0x21) = 0;
    break;
  case 5:
    FUN_08007f24(0x8c,0x105,0x9f,0x118,0x1c9f);
    FUN_080082f2(0xa9,0x108,&DAT_0800d0dc,0x1c9f,0x1c9f,0x10,1);
    *(undefined1 *)(iVar1 + 0x21) = 1;
    break;
  case 6:
    FUN_08007f24(0x3b,0xa6,0x4f,0xb9,0x1c9f);
    FUN_080082f2(0x5c,0xa8,&DAT_0800d0e0,0x1c9f,0x1c9f,0x10,1);
    *(undefined1 *)(iVar1 + 0x22) = 0;
    break;
  case 7:
    FUN_08007f24(0x3b,0xc5,0x4f,0xd8,0x1c9f);
    FUN_080082f2(0x5c,199,&DAT_0800d0e4,0x1c9f,0x1c9f,0x10,1);
    *(undefined1 *)(iVar1 + 0x22) = 1;
    break;
  case 8:
    FUN_08007f24(0x3b,0xe4,0x4f,0xf7,0x1c9f);
    FUN_080082f2(0x5c,0xe6,s_15min_0800d0ec,0x1c9f,0x1c9f,0x10,1);
    *(undefined1 *)(iVar1 + 0x22) = 2;
    break;
  case 9:
    FUN_08007f24(0x3b,0x103,0x4f,0x116,0x1c9f);
    FUN_080082f2(0x5c,0x105,s_30min_0800d0f4,0x1c9f,0x1c9f,0x10,1);
    *(undefined1 *)(iVar1 + 0x22) = 3;
  }
  return;
}


// ===== FUN_0800d1d8 @ 0800d1d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d1d8(void)

{
  char *pcVar1;
  undefined4 in_r3;
  
  if (*(char *)(_DAT_0800d248 + 0x26) == '\0') {
    pcVar1 = s_2__UI_decorate_menu_jpg_0800d264;
  }
  else {
    pcVar1 = s_2__UI_decorat_menu_jpg_0800d24b + 1;
  }
  FUN_08010274(pcVar1,5,0x41,in_r3,in_r3);
  FUN_08007b34(0xec,0x5d,0xec,0x138,0x3186);
  FUN_08007b34(0xec,0x138,0xe7,0x13d,0x3186);
  FUN_08007b34(0xe7,0x13d,0xc,0x13d,0x3186);
  FUN_08007b34(0xc,0x13d,5,0x138,0x3186);
  FUN_08007b34(5,0x138,5,0x47,0x3186);
  return;
}


// ===== FUN_0800d27c @ 0800d27c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0800d27c(void)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  undefined1 auStack_2c [32];
  
  pbVar3 = _DAT_0800d5ac;
  iVar2 = DAT_0800d5a8;
  iVar5 = *(int *)(DAT_0800d5a4 + 4);
  if (*(char *)(iVar5 + 4) == '-') {
    bVar4 = 4;
  }
  else if (*(char *)(iVar5 + 2) == '-') {
    bVar4 = 3;
  }
  else if (*(char *)(iVar5 + 1) == '-') {
    bVar4 = 2;
  }
  else {
    bVar4 = 1;
  }
  *(byte *)(DAT_0800d5a8 + 6) = bVar4;
  iVar5 = DAT_0800d5a8;
  if (bVar4 != *pbVar3) {
    *pbVar3 = bVar4;
    cVar1 = *(char *)(iVar5 + 0x26);
    if (bVar4 == 1) {
      if (cVar1 == '\0') {
        FUN_08010274(s_2__UI_decorate_ncv0_jpg_0800d670,0,0x9e);
        FUN_08007f24(7,0x83,0x24,0x99,*(undefined2 *)(iVar2 + 0x1a));
        FUN_08007f24(0xca,0x83,0xe7,0x99,*(undefined2 *)(iVar2 + 0x1a));
        FUN_08010274(s_2__UI_decorate_ncv1_3_jpg_0800d688,0x46,0x8a);
        FUN_08010274(s_2__UI_decorate_ncv1_4_jpg_0800d6a4,0x46,0xbb);
        FUN_08010274(s_2__UI_decorate_ncv1_2_jpg_0800d6c0,0x2b,0x76);
        FUN_08010274(s_2__UI_decorate_ncv1_5_jpg_0800d6dc,0x2b,0xd0);
        FUN_08010274(s_2__UI_decorate_ncv1_1_jpg_0800d6f8,0x14,0x60);
        pcVar6 = s_2__UI_decorate_ncv1_6_jpg_0800d714;
      }
      else {
        FUN_08010274(s_2__UI_decorat_ncv0_jpg_0800d5af + 1,0,0x9e);
        FUN_08007f24(7,0x83,0x24,0x99,*(undefined2 *)(iVar2 + 0x1a));
        FUN_08007f24(0xca,0x83,0xe7,0x99,*(undefined2 *)(iVar2 + 0x1a));
        FUN_08010274(s_2__UI_decorat_ncv1_3_jpg_0800d5c8,0x46,0x8a);
        FUN_08010274(s_2__UI_decorat_ncv1_4_jpg_0800d5e4,0x46,0xbb);
        FUN_08010274(s_2__UI_decorat_ncv1_2_jpg_0800d600,0x2b,0x76);
        FUN_08010274(s_2__UI_decorat_ncv1_5_jpg_0800d61c,0x2b,0xd0);
        FUN_08010274(s_2__UI_decorat_ncv1_1_jpg_0800d638,0x14,0x60);
        pcVar6 = s_2__UI_decorat_ncv1_6_jpg_0800d654;
      }
      FUN_08010274(pcVar6,0x14,0xe4);
    }
    else {
      if (bVar4 == 2) {
        if (cVar1 == '\0') {
          FUN_08010274(s_2__UI_decorate_ncv1_jpg_0800d774,0,0x9e);
          FUN_08010274(s_2__UI_decorate_lig_jpg_0800d78c,7,0x83);
          FUN_08010274(s_2__UI_decorate_lig_jpg_0800d78c,0xca,0x83);
          pcVar6 = s_2__UI_decorate_ncv1__0800d7a4;
        }
        else {
          FUN_08010274(s_2__UI_decorat_ncv1_jpg_0800d730,0,0x9e);
          FUN_08010274(s_2__UI_decorat_lig_jpg_0800d748,7,0x83);
          FUN_08010274(s_2__UI_decorat_lig_jpg_0800d748,0xca,0x83);
          pcVar6 = s_2__UI_decorat_ncv1__0800d760;
        }
      }
      else if (bVar4 == 3) {
        if (cVar1 == '\0') {
          FUN_08010274(s_2__UI_decorate_ncv2_jpg_0800d7e8,0,0x9e);
          FUN_08010274(s_2__UI_decorate_lig_jpg_0800d78c,7,0x83);
          FUN_08010274(s_2__UI_decorate_lig_jpg_0800d78c,0xca,0x83);
          pcVar6 = s_2__UI_decorate_ncv2__0800d800;
        }
        else {
          FUN_08010274(s_2__UI_decorat_ncv2_jpg_0800d7bc,0,0x9e);
          FUN_08010274(s_2__UI_decorat_lig_jpg_0800d748,7,0x83);
          FUN_08010274(s_2__UI_decorat_lig_jpg_0800d748,0xca,0x83);
          pcVar6 = s_2__UI_decorat_ncv2__0800d7d4;
        }
      }
      else {
        if (bVar4 != 4) goto LAB_0800d464;
        if (cVar1 == '\0') {
          FUN_08010274(s_2__UI_decorate_ncv3_jpg_0800d84b + 1,0,0x9e);
          FUN_08010274(s_2__UI_decorate_lig_jpg_0800d78c,7,0x83);
          FUN_08010274(s_2__UI_decorate_lig_jpg_0800d78c,0xca,0x83);
          pcVar6 = s_2__UI_decorate_ncv3__0800d864;
        }
        else {
          FUN_08010274(s_2__UI_decorat_ncv3_jpg_0800d818,0,0x9e);
          FUN_08010274(s_2__UI_decorat_lig_jpg_0800d748,7,0x83);
          FUN_08010274(s_2__UI_decorat_lig_jpg_0800d748,0xca,0x83);
          pcVar6 = s_2__UI_decorat_ncv3__0800d830;
        }
      }
      FUN_08014af4(_DAT_0800d848,&DAT_0800d844,pcVar6);
    }
  }
LAB_0800d464:
  if (1 < *pbVar3) {
    if (pbVar3[9] == 1) {
      FUN_08007f24(0x11,0x5b,0xe3,0x74,*(undefined2 *)(iVar2 + 0x1a));
      FUN_08007f24(0x2c,0x75,199,0x88,*(undefined2 *)(iVar2 + 0x1a));
      FUN_08007f24(0x47,0x86,0xab,0x98,*(undefined2 *)(iVar2 + 0x1a));
      FUN_08007f24(0x47,0xbb,0xa8,0xcc,*(undefined2 *)(iVar2 + 0x1a));
      FUN_08007f24(0x2b,0xcd,199,0xde,*(undefined2 *)(iVar2 + 0x1a));
      FUN_08007f24(0xf,0xe1,0xe4,0xf7,*(undefined2 *)(iVar2 + 0x1a));
      FUN_08014af4(auStack_2c,&DAT_0800d87c,_DAT_0800d848,
                   s_2__UI_decorate_ncv1_3_jpg_0800d688 + 0x14);
      FUN_08010274(auStack_2c,0x46,0x8a);
    }
    if (pbVar3[9] == 2) {
      FUN_08014af4(auStack_2c,&DAT_0800d87c,_DAT_0800d848,
                   s_2__UI_decorate_ncv1_4_jpg_0800d6a4 + 0x14);
      FUN_08010274(auStack_2c,0x46,0xbb);
    }
    if (pbVar3[9] == 3) {
      FUN_08014af4(auStack_2c,&DAT_0800d87c,_DAT_0800d848,
                   s_2__UI_decorate_ncv1_2_jpg_0800d6c0 + 0x14);
      FUN_08010274(auStack_2c,0x2b,0x76);
    }
    if (pbVar3[9] == 4) {
      FUN_08014af4(auStack_2c,&DAT_0800d87c,_DAT_0800d848,
                   s_2__UI_decorate_ncv1_5_jpg_0800d6dc + 0x14);
      FUN_08010274(auStack_2c,0x2b,0xd0);
    }
    if (pbVar3[9] == 5) {
      FUN_08014af4(auStack_2c,&DAT_0800d87c,_DAT_0800d848,
                   s_2__UI_decorate_ncv1_1_jpg_0800d6f8 + 0x14);
      FUN_08010274(auStack_2c,0x14,0x60);
    }
    bVar4 = pbVar3[9];
    if (bVar4 == 6) {
      FUN_08014af4(auStack_2c,&DAT_0800d87c,_DAT_0800d848,
                   s_2__UI_decorate_ncv1_6_jpg_0800d714 + 0x14);
      FUN_08010274(auStack_2c,0x14,0xe4);
      bVar4 = 0;
      pbVar3[9] = 0;
    }
    pbVar3[9] = bVar4 + 1;
  }
  return;
}


// ===== FUN_0800d884 @ 0800d884

void FUN_0800d884(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 uVar11;
  ushort uVar12;
  
  uVar4 = 0;
  for (uVar10 = 0; cVar1 = *(char *)(param_3 + uVar10), cVar1 != '\0'; uVar10 = uVar10 + 1 & 0xff) {
    sVar3 = (short)uVar4;
    if (cVar1 == '.') {
      uVar12 = sVar3 + 6;
LAB_0800d8a0:
      uVar4 = (uint)uVar12;
    }
    else {
      if (cVar1 == '-') {
        if (uVar10 != 0) goto LAB_0800d89e;
        uVar12 = sVar3 + 0x12;
        goto LAB_0800d8a0;
      }
      if (cVar1 != ' ') {
LAB_0800d89e:
        uVar12 = sVar3 + 0x19;
        goto LAB_0800d8a0;
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
    if (bVar2 == 0x35) {
      uVar5 = DAT_0800da00;
      goto LAB_0800d91e;
    }
    if (0x35 < bVar2) {
      if (bVar2 == 0x39) {
        uVar5 = DAT_0800da10;
        goto LAB_0800d91e;
      }
      if (bVar2 < 0x3a) {
        if (bVar2 == 0x36) {
          uVar5 = DAT_0800da04;
        }
        else if (bVar2 == 0x37) {
          uVar5 = DAT_0800da08;
        }
        else {
          if (bVar2 != 0x38) goto switchD_0800d8e4_caseD_2f;
          uVar5 = DAT_0800da0c;
        }
        goto LAB_0800d91e;
      }
      if (bVar2 != 0x4c) {
        if (bVar2 == 0x4f) goto switchD_0800d8e4_caseD_30;
        goto switchD_0800d8e4_caseD_2f;
      }
      uVar11 = *(undefined2 *)(DAT_0800da14 + 0x1a);
      uVar5 = DAT_0800da18;
      goto LAB_0800d924;
    }
    switch(bVar2) {
    case 0x2d:
      uVar6 = param_2 + 0xd;
      uVar7 = uVar4 + 0xf;
      uVar8 = param_2 + 10;
      uVar9 = uVar4 + 5 & 0xffff;
      goto LAB_0800d9ac;
    case 0x2e:
      uVar6 = param_2 + 0x17;
      uVar7 = uVar4 + 3;
      uVar8 = param_2 + 0x15;
      uVar9 = uVar4;
LAB_0800d9ac:
      FUN_08007f98(uVar9,uVar8 & 0xffff,uVar7 & 0xffff,uVar6 & 0xffff,0xf79e,param_4);
    default:
      goto switchD_0800d8e4_caseD_2f;
    case 0x30:
switchD_0800d8e4_caseD_30:
      uVar5 = DAT_0800d9ec;
      break;
    case 0x31:
      uVar5 = DAT_0800d9f0;
      break;
    case 0x32:
      uVar5 = DAT_0800d9f4;
      break;
    case 0x33:
      uVar5 = DAT_0800d9f8;
      break;
    case 0x34:
      uVar5 = DAT_0800d9fc;
    }
LAB_0800d91e:
    uVar11 = 0xf79e;
LAB_0800d924:
    param_4 = 1;
    FUN_08007d20(uVar5,uVar4,param_2,uVar11,0x153f,1);
switchD_0800d8e4_caseD_2f:
    cVar1 = *(char *)(param_3 + uVar10);
    sVar3 = (short)uVar4;
    if (cVar1 == '.') {
      uVar12 = sVar3 + 6;
LAB_0800d9c0:
      uVar4 = (uint)uVar12;
    }
    else {
      if (cVar1 == '-') {
        if (uVar10 != 0) goto LAB_0800d9be;
        uVar12 = sVar3 + 0x16;
        goto LAB_0800d9c0;
      }
      if (cVar1 != ' ') {
LAB_0800d9be:
        uVar12 = sVar3 + 0x17;
        goto LAB_0800d9c0;
      }
    }
    uVar10 = uVar10 + 1 & 0xff;
  } while( true );
}


// ===== FUN_0800da1c @ 0800da1c

void FUN_0800da1c(uint param_1,uint param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  ushort uVar9;
  uint uVar10;
  undefined2 uVar11;
  
  iVar2 = DAT_0800dbb4;
  uVar10 = 0;
  do {
    bVar1 = *(byte *)(param_3 + uVar10);
    if (bVar1 == 0) {
      return;
    }
    if (bVar1 == 0x34) {
      uVar11 = *(undefined2 *)(iVar2 + 0x1a);
      param_4 = 1;
      uVar8 = *(undefined2 *)(iVar2 + 0x1c);
      uVar3 = DAT_0800dbc8;
      goto LAB_0800da96;
    }
    if (bVar1 < 0x35) {
      if (bVar1 == 0x30) {
LAB_0800da78:
        uVar11 = *(undefined2 *)(iVar2 + 0x1a);
        param_4 = 1;
        uVar8 = *(undefined2 *)(iVar2 + 0x1c);
        uVar3 = DAT_0800dbb8;
        goto LAB_0800da96;
      }
      if (0x30 < bVar1) {
        if (bVar1 == 0x31) {
          uVar11 = *(undefined2 *)(iVar2 + 0x1a);
          param_4 = 1;
          uVar8 = *(undefined2 *)(iVar2 + 0x1c);
          uVar3 = DAT_0800dbbc;
        }
        else if (bVar1 == 0x32) {
          uVar11 = *(undefined2 *)(iVar2 + 0x1a);
          param_4 = 1;
          uVar8 = *(undefined2 *)(iVar2 + 0x1c);
          uVar3 = DAT_0800dbc0;
        }
        else {
          if (bVar1 != 0x33) goto LAB_0800db68;
          uVar11 = *(undefined2 *)(iVar2 + 0x1a);
          param_4 = 1;
          uVar8 = *(undefined2 *)(iVar2 + 0x1c);
          uVar3 = DAT_0800dbc4;
        }
        goto LAB_0800da96;
      }
      if (bVar1 == 0x20) {
        uVar11 = *(undefined2 *)(iVar2 + 0x1a);
        uVar4 = param_2 + 0xb;
        uVar5 = param_1 + 9;
        uVar7 = param_2;
LAB_0800dbaa:
        uVar4 = uVar4 & 0xffff;
        uVar6 = param_1;
      }
      else {
        if (bVar1 != 0x2d) {
          if (bVar1 != 0x2e) goto LAB_0800db68;
          FUN_08007f24(param_1,param_2,param_1 + 5 & 0xffff,param_2 + 0xd & 0xffff,
                       *(undefined2 *)(iVar2 + 0x1a),param_4);
          uVar11 = *(undefined2 *)(iVar2 + 0x1c);
          uVar4 = param_2 + 0xc;
          uVar5 = param_1 + 2;
          uVar7 = param_2 + 10 & 0xffff;
          goto LAB_0800dbaa;
        }
        uVar11 = *(undefined2 *)(iVar2 + 0x1c);
        uVar9 = (short)param_2 + 6;
        uVar5 = param_1 + 8;
        uVar4 = (uint)uVar9;
        uVar7 = (uint)uVar9;
        uVar6 = param_1 + 3 & 0xffff;
      }
      FUN_08007f24(uVar6,uVar7,uVar5 & 0xffff,uVar4,uVar11,param_4);
    }
    else {
      if (bVar1 == 0x38) {
        uVar11 = *(undefined2 *)(iVar2 + 0x1a);
        param_4 = 1;
        uVar8 = *(undefined2 *)(iVar2 + 0x1c);
        uVar3 = DAT_0800dbd8;
      }
      else if (bVar1 < 0x39) {
        if (bVar1 == 0x35) {
          uVar11 = *(undefined2 *)(iVar2 + 0x1a);
          param_4 = 1;
          uVar8 = *(undefined2 *)(iVar2 + 0x1c);
          uVar3 = DAT_0800dbcc;
        }
        else if (bVar1 == 0x36) {
          uVar11 = *(undefined2 *)(iVar2 + 0x1a);
          param_4 = 1;
          uVar8 = *(undefined2 *)(iVar2 + 0x1c);
          uVar3 = DAT_0800dbd0;
        }
        else {
          if (bVar1 != 0x37) goto LAB_0800db68;
          uVar11 = *(undefined2 *)(iVar2 + 0x1a);
          param_4 = 1;
          uVar8 = *(undefined2 *)(iVar2 + 0x1c);
          uVar3 = DAT_0800dbd4;
        }
      }
      else {
        if (bVar1 != 0x39) {
          if (bVar1 == 0x4c) {
            uVar11 = *(undefined2 *)(iVar2 + 0x1a);
            param_4 = 0x32;
            uVar8 = *(undefined2 *)(iVar2 + 0x1c);
            uVar3 = DAT_0800dbe0;
            goto LAB_0800da96;
          }
          if (bVar1 == 0x4f) goto LAB_0800da78;
          goto LAB_0800db68;
        }
        uVar11 = *(undefined2 *)(iVar2 + 0x1a);
        param_4 = 1;
        uVar8 = *(undefined2 *)(iVar2 + 0x1c);
        uVar3 = DAT_0800dbdc;
      }
LAB_0800da96:
      FUN_08007c6c(uVar3,param_1,param_2,uVar8,uVar11,param_4);
    }
LAB_0800db68:
    if (*(char *)(param_3 + uVar10) == '.') {
      uVar9 = (short)param_1 + 5;
    }
    else {
      uVar9 = (short)param_1 + 9;
    }
    param_1 = (uint)uVar9;
    uVar10 = uVar10 + 1 & 0xff;
  } while( true );
}


// ===== FUN_0800dbe4 @ 0800dbe4

void FUN_0800dbe4(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  uVar8 = 0;
  uVar9 = param_4;
  do {
    bVar1 = *(byte *)(param_3 + uVar8);
    if (bVar1 == 0) {
      return;
    }
    if (bVar1 == 0x34) {
      uVar2 = DAT_0800dd50;
      goto LAB_0800dc58;
    }
    if (bVar1 < 0x35) {
      if (bVar1 == 0x30) {
LAB_0800dc46:
        uVar2 = DAT_0800dd40;
LAB_0800dc58:
        uVar9 = 1;
        goto LAB_0800dc5c;
      }
      if (0x30 < bVar1) {
        if (bVar1 == 0x31) {
          uVar2 = DAT_0800dd44;
        }
        else if (bVar1 == 0x32) {
          uVar2 = DAT_0800dd48;
        }
        else {
          if (bVar1 != 0x33) goto LAB_0800dcf8;
          uVar2 = DAT_0800dd4c;
        }
        goto LAB_0800dc58;
      }
      if (bVar1 == 0x20) {
        uVar3 = param_1 + 10;
        uVar5 = param_2;
        uVar6 = param_2 + 0xd;
        uVar2 = param_5;
LAB_0800dd36:
        uVar6 = uVar6 & 0xffff;
        uVar4 = param_1;
      }
      else {
        uVar2 = param_4;
        if (bVar1 != 0x2d) {
          if (bVar1 != 0x2e) goto LAB_0800dcf8;
          FUN_08007f24(param_1,param_2,param_1 + 5 & 0xffff,param_2 + 0xd & 0xffff,param_5,uVar9);
          uVar3 = param_1 + 2;
          uVar5 = param_2 + 10 & 0xffff;
          uVar6 = param_2 + 0xc;
          goto LAB_0800dd36;
        }
        uVar7 = (short)param_2 + 6;
        uVar3 = param_1 + 8;
        uVar6 = (uint)uVar7;
        uVar5 = (uint)uVar7;
        uVar4 = param_1 + 3 & 0xffff;
      }
      FUN_08007f24(uVar4,uVar5,uVar3 & 0xffff,uVar6,uVar2,uVar9);
    }
    else {
      if (bVar1 == 0x38) {
        uVar2 = DAT_0800dd60;
        goto LAB_0800dc58;
      }
      if (bVar1 < 0x39) {
        if (bVar1 == 0x35) {
          uVar2 = DAT_0800dd54;
        }
        else if (bVar1 == 0x36) {
          uVar2 = DAT_0800dd58;
        }
        else {
          if (bVar1 != 0x37) goto LAB_0800dcf8;
          uVar2 = DAT_0800dd5c;
        }
        goto LAB_0800dc58;
      }
      if (bVar1 == 0x39) {
        uVar2 = DAT_0800dd64;
        goto LAB_0800dc58;
      }
      if (bVar1 != 0x4c) {
        if (bVar1 == 0x4f) goto LAB_0800dc46;
        goto LAB_0800dcf8;
      }
      uVar9 = 0x32;
      uVar2 = DAT_0800dd68;
LAB_0800dc5c:
      FUN_08007c6c(uVar2,param_1,param_2,param_4,param_5,uVar9);
    }
LAB_0800dcf8:
    if (*(char *)(param_3 + uVar8) == '.') {
      uVar7 = (short)param_1 + 6;
    }
    else {
      uVar7 = (short)param_1 + 0xb;
    }
    param_1 = (uint)uVar7;
    uVar8 = uVar8 + 1 & 0xff;
  } while( true );
}


// ===== FUN_0800dd6c @ 0800dd6c

void FUN_0800dd6c(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined2 uVar12;
  ushort uVar13;
  
  iVar4 = DAT_0800df08;
  uVar6 = 0;
  for (uVar11 = 0; cVar1 = *(char *)(param_3 + uVar11), cVar1 != '\0'; uVar11 = uVar11 + 1 & 0xff) {
    sVar3 = (short)uVar6;
    if (cVar1 == '.') {
      uVar13 = sVar3 + 6;
LAB_0800dd88:
      uVar6 = (uint)uVar13;
    }
    else {
      if (cVar1 == '-') {
        if (uVar11 != 0) goto LAB_0800dd86;
        uVar13 = sVar3 + 0x1e;
        goto LAB_0800dd88;
      }
      if (cVar1 != ' ') {
LAB_0800dd86:
        uVar13 = sVar3 + 0x2b;
        goto LAB_0800dd88;
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
      uVar12 = *(undefined2 *)(iVar4 + 0x1a);
      uVar7 = DAT_0800df20;
      goto LAB_0800de10;
    }
    if (0x35 < bVar2) {
      if (bVar2 == 0x39) {
        uVar12 = *(undefined2 *)(iVar4 + 0x1a);
        uVar7 = DAT_0800df30;
      }
      else if (bVar2 < 0x3a) {
        if (bVar2 == 0x36) {
          uVar12 = *(undefined2 *)(iVar4 + 0x1a);
          uVar7 = DAT_0800df24;
        }
        else if (bVar2 == 0x37) {
          uVar12 = *(undefined2 *)(iVar4 + 0x1a);
          uVar7 = DAT_0800df28;
        }
        else {
          if (bVar2 != 0x38) goto switchD_0800ddca_caseD_2f;
          uVar12 = *(undefined2 *)(iVar4 + 0x1a);
          uVar7 = DAT_0800df2c;
        }
      }
      else {
        if (bVar2 != 0x4c) {
          if (bVar2 == 0x4f) goto switchD_0800ddca_caseD_30;
          goto switchD_0800ddca_caseD_2f;
        }
        uVar12 = *(undefined2 *)(iVar4 + 0x1a);
        uVar7 = DAT_0800df34;
      }
      goto LAB_0800de10;
    }
    switch(bVar2) {
    case 0x2d:
      uVar8 = param_2 + 0x19;
      uVar9 = uVar6 + 0x14;
      uVar10 = param_2 + 0x14;
      sVar5 = sVar3 + 3;
      goto LAB_0800dec2;
    case 0x2e:
      uVar8 = param_2 + 0x33;
      uVar9 = uVar6 + 4;
      uVar10 = param_2 + 0x2d;
      sVar5 = sVar3 + -2;
LAB_0800dec2:
      FUN_08007f98(sVar5,uVar10 & 0xffff,uVar9 & 0xffff,uVar8 & 0xffff,0xf79e,param_4);
    default:
      goto switchD_0800ddca_caseD_2f;
    case 0x30:
switchD_0800ddca_caseD_30:
      uVar12 = *(undefined2 *)(iVar4 + 0x1a);
      uVar7 = DAT_0800df0c;
      break;
    case 0x31:
      uVar12 = *(undefined2 *)(iVar4 + 0x1a);
      uVar7 = DAT_0800df10;
      break;
    case 0x32:
      uVar12 = *(undefined2 *)(iVar4 + 0x1a);
      uVar7 = DAT_0800df14;
      break;
    case 0x33:
      uVar12 = *(undefined2 *)(iVar4 + 0x1a);
      uVar7 = DAT_0800df18;
      break;
    case 0x34:
      uVar12 = *(undefined2 *)(iVar4 + 0x1a);
      uVar7 = DAT_0800df1c;
    }
LAB_0800de10:
    param_4 = 0x32;
    FUN_08007d20(uVar7,uVar6,param_2,uVar12,0xf79e,0x32);
switchD_0800ddca_caseD_2f:
    cVar1 = *(char *)(param_3 + uVar11);
    if (cVar1 == '.') {
      uVar13 = sVar3 + 0xe;
LAB_0800ded8:
      uVar6 = (uint)uVar13;
    }
    else {
      if (cVar1 == '-') {
        if (uVar11 != 0) goto LAB_0800ded6;
        uVar13 = sVar3 + 0x1e;
        goto LAB_0800ded8;
      }
      if (cVar1 != ' ') {
LAB_0800ded6:
        uVar13 = sVar3 + 0x2b;
        goto LAB_0800ded8;
      }
    }
    uVar11 = uVar11 + 1 & 0xff;
  } while( true );
}


// ===== FUN_0800df38 @ 0800df38

void FUN_0800df38(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_r3;
  undefined8 uVar3;
  undefined4 local_14;
  
  FUN_08007f24(0,0,0xf0,0x140);
  FUN_08013848(0);
  iVar2 = FUN_08010274(s_2__LOGO_jpg_0800dfbc,0);
  FUN_08013848(0x100000);
  local_14 = in_r3;
  if (iVar2 != 0) {
    local_14 = 0;
    FUN_08007c6c(DAT_0800dfc8,0x2a,0x81,0xf79e);
  }
  FUN_080104f4(9999,0x8f,(uint)((short)(*(byte *)(DAT_0800dfcc + 0x23) + 1) * 9999) / 10 & 0xffff);
  uVar1 = DAT_0800dfd0;
  do {
    uVar3 = FUN_0800fd5e(uVar1,0x80);
  } while ((int)uVar3 == 0);
  if (*DAT_0800dfd4 == 0) {
    return;
  }
  FUN_0800e10c(*DAT_0800dfd4,(int)((ulonglong)uVar3 >> 0x20),0,local_14);
  return;
}


// ===== FUN_0800dfd8 @ 0800dfd8

undefined8 FUN_0800dfd8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  iVar4 = DAT_0800e104;
  iVar3 = DAT_0800e100;
  if (*(char *)(DAT_0800e100 + 0xe) == -1) {
    *(undefined1 *)(DAT_0800e100 + 0xe) = 0;
    *(undefined2 *)(iVar4 + 0xc) = 0;
  }
  local_28 = param_1;
  uStack_24 = param_2;
  if (*(char *)(iVar3 + 2) != '\r') goto LAB_0800e0fa;
  uStack_20 = param_3;
  uStack_1c = param_4;
  FUN_08012338();
  pcVar5 = DAT_0800e108;
  FUN_08011618(DAT_0800e108[0xd],0x1c9f,0xde,(uint)*(byte *)(iVar3 + 0xe) * 0x15 + 0x57);
  if ((*(char *)(iVar3 + 0x21) == '\x01') && (*(char *)(iVar4 + 3) == '\a')) {
    uVar6 = FUN_08009534(*(undefined4 *)(pcVar5 + 8));
    *(undefined4 *)(pcVar5 + 8) = uVar6;
  }
  if (*pcVar5 == '\0') {
    uVar2 = *(ushort *)(iVar3 + 0x1a);
    bVar1 = *(byte *)(iVar3 + 0xe);
    puVar7 = *(undefined4 **)(pcVar5 + 4);
  }
  else {
    if (*(char *)(iVar4 + 3) == '\n') {
      uVar6 = FUN_080155a0(*(undefined4 *)(pcVar5 + 8),*(undefined4 *)(iVar3 + 0x14));
      *(undefined4 *)(pcVar5 + 8) = uVar6;
    }
    else {
      uVar6 = *(undefined4 *)(pcVar5 + 8);
    }
    FUN_0800f7fc(uVar6,&uStack_24);
    uVar2 = *(ushort *)(iVar3 + 0x1a);
    bVar1 = *(byte *)(iVar3 + 0xe);
    puVar7 = &uStack_24;
  }
  FUN_0800dbe4(0xa0,(uint)bVar1 * 0x15 + 0x54,puVar7,0x1c9f);
  if (*(byte *)(iVar3 + 0xe) == 0) {
    if (*(short *)(iVar4 + 0xc) != 0) {
      FUN_08011618(*(undefined1 *)(iVar4 + 10),*(undefined2 *)(iVar3 + 0x1c),0xde);
      goto LAB_0800e0ac;
    }
  }
  else {
    *(ushort *)(iVar4 + 0xc) = (ushort)*(byte *)(iVar3 + 0xe) * 0x15 + 0x42;
    FUN_08011618(*(undefined1 *)(iVar4 + 10),*(undefined2 *)(iVar3 + 0x1c),0xde);
    *(ushort *)(iVar4 + 0xe) = (ushort)*(byte *)(iVar3 + 0xe) * 0x15 + 0x3f;
LAB_0800e0ac:
    FUN_0800f7fc(*(undefined4 *)(pcVar5 + 8),&uStack_24);
    uVar2 = *(ushort *)(iVar3 + 0x1a);
    FUN_0800dbe4(0xa0,*(undefined2 *)(iVar4 + 0xe),DAT_0800e104 + 0x18,*(undefined2 *)(iVar3 + 0x1c)
                );
  }
  local_28 = (uint)uVar2;
  *(ushort *)(iVar4 + 10) = (ushort)(byte)pcVar5[0xd];
  if (*pcVar5 == '\0') {
    puVar7 = *(undefined4 **)(pcVar5 + 4);
  }
  else {
    puVar7 = &uStack_24;
  }
  FUN_0800755e(DAT_0800e104 + 0x18,puVar7);
  bVar1 = *(byte *)(iVar3 + 0xe);
  if (bVar1 < 7) {
    *(byte *)(iVar3 + 0xe) = bVar1 + 1;
    if (bVar1 != 0xff) goto LAB_0800e0fa;
  }
  else {
    *(undefined1 *)(iVar3 + 0xe) = 0;
  }
  *(undefined2 *)(iVar4 + 0xc) = 0xea;
  *(undefined2 *)(iVar4 + 0xe) = 0xe7;
LAB_0800e0fa:
  return CONCAT44(uStack_24,local_28);
}


// ===== FUN_0800e10c @ 0800e10c

void FUN_0800e10c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  ushort uVar6;
  undefined2 uVar7;
  
  uVar6 = 0;
  FUN_08007f24(0,0,0xf0,0x140,0,param_3,param_4);
  FUN_08007e44(0x41,0xa5,0x55,0xb9,0xf79e);
  FUN_08007e44(0x41,0x7c,0x55,0x90,0xf79e);
  FUN_080082f2(0x6a,0x7d,&DAT_0800e2bc,0xf79e,0xf79e,0x10,1);
  FUN_080082f2(0x6a,0xa6,s_English_0800e2c8,0xf79e,0xf79e,0x10,1);
  FUN_08007e88(0x38,0x77,0xb8,0x93,3,0x1c9f);
  uVar4 = DAT_0800e2d4;
  iVar1 = DAT_0800e2d0;
  do {
    iVar3 = FUN_0800fd5e(uVar4,0x10);
    if ((iVar3 == 0) || (iVar3 = FUN_0800fd5e(uVar4,0x80), iVar3 == 0)) {
      FUN_08009d18(10);
      iVar3 = FUN_0800fd5e(uVar4,0x10);
      if ((iVar3 == 0) || (iVar3 = FUN_0800fd5e(uVar4,0x80), iVar3 == 0)) {
        if (uVar6 == 0) {
          FUN_08007e88(0x38,0x77,0xb8,0x93,3,*(undefined2 *)(iVar1 + 0x1a));
          uVar7 = 0x1c9f;
        }
        else {
          FUN_08007e88(0x38,0x77,0xb8,0x93,3,0x1c9f);
          uVar7 = *(undefined2 *)(iVar1 + 0x1a);
        }
        uVar6 = (ushort)(uVar6 == 0);
        FUN_08007e88(0x38,0xa0,0xb8,0xbc,3,uVar7);
        do {
          iVar3 = FUN_0800fd5e(uVar4,0x10);
        } while (iVar3 == 0);
        do {
          iVar3 = FUN_0800fd5e(uVar4,0x80);
        } while (iVar3 == 0);
      }
    }
    iVar3 = FUN_0800fd5e(uVar4,0x40);
    if (iVar3 == 0) {
      FUN_08009d18(10);
      iVar3 = FUN_0800fd5e(uVar4,0x40);
      if (iVar3 == 0) {
        if (uVar6 == 0) {
          FUN_08007f24(0x41,0x7c,0x55,0x90,0x1c9f);
          pcVar5 = &DAT_0800e2bc;
          uVar4 = 0x7d;
        }
        else {
          FUN_08007f24(0x41,0xa5,0x55,0xb9,0x1c9f);
          pcVar5 = s_English_0800e2c8;
          uVar4 = 0xa6;
        }
        FUN_080082f2(0x6a,uVar4,pcVar5,0x1c9f,0xf79e,0x10,1);
        FUN_08009d18(100);
        puVar2 = DAT_0800e2dc;
        *DAT_0800e2dc = 0;
        puVar2[1] = uVar6;
        *(char *)(iVar1 + 0x20) = (char)uVar6;
        *(undefined1 *)(iVar1 + 2) = 0xe;
        return;
      }
    }
    iVar3 = FUN_0800fd5e(DAT_0800e2d8,0x80);
    if (iVar3 == 0) {
      FUN_08009d18(10);
      iVar3 = FUN_0800fd5e(DAT_0800e2d8,0x80);
      if (iVar3 == 0) {
        FUN_08012aa0();
      }
    }
  } while( true );
}


// ===== FUN_0800e2e0 @ 0800e2e0

void FUN_0800e2e0(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (uVar2 == param_1) {
      uVar1 = 0x1c9f;
    }
    else {
      uVar1 = 0x3186;
    }
    FUN_08007a46(uVar2 * 9 + 0x73,0x131,3,uVar1);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 3);
  return;
}


// ===== FUN_0800e318 @ 0800e318

void FUN_0800e318(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  iVar3 = DAT_0800e36c;
  iVar2 = DAT_0800aec8;
  if (param_1 != 0) {
    if (param_1 == 1) {
      FUN_0800c938(1,param_2,param_3,param_4);
      return;
    }
    if (param_1 == 2) {
      FUN_08007f24(0xd,0x68,0xe3,0x139,*(undefined2 *)(DAT_0800aec8 + 0x1a),param_3,param_4);
      if (*(char *)(iVar2 + 0x20) == '\0') {
        FUN_080082f2(0x4a,0x7d,&DAT_0800aef4,0xfc60,0xfc60,0x18,1);
        FUN_080082f2(0x51,0x83,&DAT_0800aed8,*(undefined2 *)(iVar2 + 0x1a),
                     *(undefined2 *)(iVar2 + 0x1a),0x10,1);
        FUN_080082f2(0x38,0xa5,&DAT_0800aefc,*(undefined2 *)(iVar2 + 0x1c),0xf79e,0x10,1);
        uVar1 = *(undefined2 *)(iVar2 + 0x1c);
        pcVar5 = &DAT_0800af10;
        uVar4 = 0x38;
      }
      else {
        FUN_080082f2(0x3e,0x7d,&DAT_0800aecc,0xfc60,0xfc60,0x18,1);
        FUN_080082f2(0x45,0x83,&DAT_0800aed8,*(undefined2 *)(iVar2 + 0x1a),
                     *(undefined2 *)(iVar2 + 0x1a),0x10,1);
        FUN_080082f2(0x54,0xa5,s_Reset_all_0800aedc,*(undefined2 *)(iVar2 + 0x1c),0xf79e,0x10,1);
        uVar1 = *(undefined2 *)(iVar2 + 0x1c);
        pcVar5 = s_settings____0800aee8;
        uVar4 = 0x4c;
      }
      uVar8 = 1;
      uVar7 = 0x10;
      uVar6 = 0xf79e;
      FUN_080082f2(uVar4,0xbf,pcVar5,uVar1);
      FUN_0800ad14(0,uVar6,uVar7,uVar8);
      return;
    }
    FUN_08007f24(0xd,0x68,0xdf,0x139,*(undefined2 *)(DAT_0800e36c + 0x1a));
    FUN_0800af24(0x24,0x96);
    FUN_080082f2(0x41,0xeb,s_DMC_100_V1_4_0800e370,*(undefined2 *)(iVar3 + 0x1c),0xf79e,0x10,1);
  }
  return;
}


// ===== FUN_0800e380 @ 0800e380

undefined8 FUN_0800e380(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  ushort uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int *piVar12;
  uint *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  char cVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  
  iVar3 = DAT_0800e58c;
  iVar2 = DAT_0800e588;
  uVar15 = DAT_0800e584;
  uVar17 = DAT_0800e580;
  uVar16 = 0;
  uVar6 = *(undefined2 *)(DAT_0800e588 + 0x1a);
  uVar14 = 0;
  uVar10 = 0;
  do {
    uVar7 = 0;
    do {
      *(undefined2 *)(iVar3 + uVar10 * 0x13c + uVar7 * 2) = uVar6;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 0x9e);
    uVar10 = uVar10 + 1 & 0xffff;
  } while (uVar10 < 10);
  if (*(ushort *)(iVar2 + 0xc) < 0x9e) {
    uVar10 = 0xffffffff;
  }
  else {
    uVar10 = (uint)*(ushort *)(DAT_0800e590 + 2);
  }
  for (uVar7 = 0; cVar18 = uVar7 <= *(ushort *)(DAT_0800e588 + 0xc),
      uVar7 < *(ushort *)(DAT_0800e588 + 0xc); uVar7 = uVar7 + 1 & 0xffff) {
    puVar11 = (undefined4 *)(DAT_0800e594 + uVar7 * 8);
    FUN_080152f0(*puVar11,puVar11[1],uVar16,uVar17,param_1,param_2,param_3,param_4);
    if (cVar18 == '\0') {
      uVar16 = *puVar11;
      uVar17 = puVar11[1];
    }
    FUN_0801507c(*puVar11,puVar11[1],uVar14,uVar15);
    if (cVar18 == '\0') {
      uVar14 = *puVar11;
      uVar15 = puVar11[1];
    }
  }
  uVar19 = FUN_08015374(uVar16,uVar17,uVar14,uVar15);
  uVar17 = (undefined4)((ulonglong)uVar19 >> 0x20);
  FUN_080152f0((int)uVar19,uVar17,DAT_0800e598,DAT_0800e59c,param_1,param_2,param_3,param_4);
  if (cVar18 == '\0') {
    uVar19 = FUN_08014d1c(0,DAT_0800e5a0,(int)uVar19,uVar17);
  }
  else {
    uVar19 = 0;
  }
  iVar2 = DAT_0800e588;
  uVar17 = (undefined4)((ulonglong)uVar19 >> 0x20);
  for (uVar7 = 0; pbVar4 = DAT_0800e590, uVar9 = (uint)*(ushort *)(iVar2 + 0xc),
      (int)uVar7 < (int)(uVar9 - 2); uVar7 = uVar7 + 1 & 0xffff) {
    puVar11 = (undefined4 *)(DAT_0800e594 + ((int)(uVar10 + 1) % 0x9e) * 8);
    uVar20 = FUN_08015374(*puVar11,puVar11[1],uVar14,uVar15);
    uVar20 = FUN_080150f4((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uVar17);
    uVar20 = FUN_0801535c((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0,DAT_0800e5a4);
    puVar11 = (undefined4 *)(DAT_0800e594 + ((int)(uVar10 + 2) % 0x9e) * 8);
    uVar21 = FUN_08015374(*puVar11,puVar11[1],uVar14,uVar15);
    uVar21 = FUN_080150f4((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),(int)uVar19,uVar17);
    FUN_0801535c((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),0,DAT_0800e5a4);
    uVar5 = FUN_08014fcc();
    param_2 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar8 = (uint)uVar5;
    uVar6 = FUN_08014fcc((int)uVar20,param_2);
    param_1 = (uint)*(ushort *)(iVar2 + 0x1c);
    uVar9 = (0x9e - uVar9) + uVar7;
    FUN_08007bd0(uVar9 & 0xffff,uVar6,uVar9 + 1 & 0xffff,uVar8);
    uVar10 = uVar10 + 1;
  }
  FUN_08007afa(0,(uint)*DAT_0800e590 * 10 + 0x50,0x9b,(uint)*DAT_0800e590 * 10 + 0x5a);
  iVar2 = DAT_0800e5a8;
  FUN_08012b28(DAT_0800e5a8,1);
  uVar17 = DAT_0800e5ac;
  FUN_0800fc90(DAT_0800e5ac,0x4000);
  uVar10 = 0;
  piVar12 = (int *)(DAT_0800e5a8 + 8);
  puVar13 = (uint *)(DAT_0800e5a8 + 0xc);
  do {
    uVar7 = 0;
    do {
      do {
      } while (-1 < *piVar12 << 0x1e);
      *puVar13 = (uint)*(ushort *)(iVar3 + uVar10 * 0x13c + uVar7 * 2);
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 0x9c);
    uVar10 = uVar10 + 1 & 0xffff;
  } while (uVar10 < 10);
  FUN_08009cdc(10);
  FUN_0800fc94(uVar17,0x4000);
  FUN_08012b28(iVar2,0);
  bVar1 = *pbVar4;
  *pbVar4 = bVar1 + 1;
  if (0xc < (byte)(bVar1 + 1)) {
    *pbVar4 = 0;
  }
  return CONCAT44(param_2,param_1);
}


// ===== FUN_0800e5b0 @ 0800e5b0

void FUN_0800e5b0(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xfffffffe | param_2 & 1;
  return;
}


// ===== FUN_0800e5bc @ 0800e5bc

void FUN_0800e5bc(void)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  
  FUN_08009ba4(0x140000,1);
  FUN_080119fc(0xb,0);
  iVar1 = DAT_0800e63c;
  FUN_0800e838(DAT_0800e63c);
  FUN_0800e6dc(&local_20);
  local_16 = 0x14;
  local_1c = DAT_0800e640;
  local_20 = DAT_0800e644;
  local_11 = 1;
  local_13 = 1;
  local_f = 2;
  local_12 = 1;
  local_10 = 1;
  local_18 = 0;
  local_14 = 0;
  FUN_0800e7a6(iVar1,&local_20);
  FUN_0800e738(DAT_0800e63c + -8,1);
  FUN_0800e802(iVar1,2,1);
  FUN_0800e5b0(iVar1,1);
  return;
}


// ===== FUN_0800e648 @ 0800e648

void FUN_0800e648(void)

{
  int iVar1;
  int local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  
  FUN_08009ba4(0x140000,1);
  iVar1 = DAT_0800e6d0;
  FUN_0800e838(DAT_0800e6d0);
  FUN_0800e6dc(&local_20);
  local_16 = 0xf;
  local_11 = 0;
  local_1c = DAT_0800e6d4;
  local_13 = 1;
  local_12 = 0;
  local_18 = 0;
  local_20 = DAT_0800e6d8;
  local_14 = 0;
  local_f = 1;
  local_10 = 1;
  FUN_0800e7a6(iVar1,&local_20);
  FUN_0800e738(DAT_0800e6d0 + -0x58,5,0x19);
  FUN_080119fc(0xf,0);
  FUN_0800e802(iVar1,2,1);
  FUN_0800e5b0(iVar1,1);
  FUN_080134a0(DAT_0800e6d8 + -4,1);
  return;
}


// ===== FUN_0800e6dc @ 0800e6dc

void FUN_0800e6dc(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)((int)param_1 + 0xe) = 0;
  *(undefined1 *)((int)param_1 + 0xf) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  return;
}


// ===== FUN_0800e6f4 @ 0800e6f4

void FUN_0800e6f4(uint param_1)

{
  if (param_1 < 0x10000001) {
    *(uint *)(DAT_0800e710 + 4) = param_1;
    return;
  }
  *DAT_0800e70c = param_1 & 0xfffffff;
  return;
}


// ===== FUN_0800e714 @ 0800e714

bool FUN_0800e714(uint param_1)

{
  uint *puVar1;
  
  if (param_1 < 0x10000001) {
    puVar1 = DAT_0800e734;
  }
  else {
    puVar1 = DAT_0800e730;
  }
  return (*puVar1 & param_1) != 0;
}


// ===== FUN_0800e738 @ 0800e738

void FUN_0800e738(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (-1 < *(int *)(param_1 + 0xa4) << 7) {
    *(uint *)(param_1 + 0xa4) = *(uint *)(param_1 + 0xa4) | 0x1000000;
  }
  if (param_2 == 1) {
    puVar1 = (uint *)(param_1 + 0xa0);
    uVar2 = *puVar1;
LAB_0800e796:
    uVar2 = uVar2 & 0xffffff00 | param_3 & 0xff;
  }
  else {
    if (param_2 == 2) {
      puVar1 = (uint *)(param_1 + 0xa0);
      uVar2 = *puVar1;
LAB_0800e7a0:
      uVar2 = uVar2 & 0xffff00ff | (param_3 & 0xff) << 8;
      goto LAB_0800e77e;
    }
    if (param_2 == 3) {
      puVar1 = (uint *)(param_1 + 0xa0);
      uVar2 = *puVar1;
    }
    else {
      if (param_2 == 4) {
        puVar1 = (uint *)(param_1 + 0xa0);
        uVar2 = *puVar1 & 0xffffff | param_3 << 0x18;
        goto LAB_0800e77e;
      }
      if (param_2 == 5) {
        puVar1 = (uint *)(param_1 + 0xa4);
        uVar2 = *puVar1;
        goto LAB_0800e796;
      }
      if (param_2 == 6) {
        puVar1 = (uint *)(param_1 + 0xa4);
        uVar2 = *puVar1;
        goto LAB_0800e7a0;
      }
      if (param_2 != 7) {
        return;
      }
      puVar1 = (uint *)(param_1 + 0xa4);
      uVar2 = *puVar1;
    }
    uVar2 = uVar2 & 0xff00ffff | (param_3 & 0xff) << 0x10;
  }
LAB_0800e77e:
  *puVar1 = uVar2;
  return;
}


// ===== FUN_0800e7a6 @ 0800e7a6

void FUN_0800e7a6(uint *param_1,uint *param_2)

{
  *param_1 = *param_1 & 0xbfef;
  *param_1 = *param_1 | (uint)(ushort)param_2[2];
  *param_1 = *param_1 & 0xffffcfff | (*(byte *)((int)param_2 + 0x11) & 3) << 0xc;
  *param_1 = *param_1 & 0xfffff3ff | (*(byte *)((int)param_2 + 0xf) & 3) << 10;
  *param_1 = *param_1 & 0xfffffcff | (*(byte *)((int)param_2 + 0xe) & 3) << 8;
  *param_1 = *param_1 & 0xffffff7f | (*(byte *)((int)param_2 + 0xd) & 1) << 7;
  *param_1 = *param_1 & 0xffffffbf | ((byte)param_2[3] & 1) << 6;
  *param_1 = *param_1 & 0xffffffdf | ((byte)param_2[4] & 1) << 5;
  param_1[1] = (uint)*(ushort *)((int)param_2 + 10);
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  return;
}


// ===== FUN_0800e802 @ 0800e802

void FUN_0800e802(uint *param_1,uint param_2,int param_3)

{
  if (param_3 == 0) {
    param_2 = *param_1 & ~param_2;
  }
  else {
    param_2 = *param_1 | param_2;
  }
  *param_1 = param_2;
  return;
}


// ===== FUN_0800e814 @ 0800e814

bool FUN_0800e814(uint param_1)

{
  uint *puVar1;
  
  if (param_1 < 0x10000001) {
    puVar1 = DAT_0800e834;
  }
  else {
    puVar1 = DAT_0800e830;
  }
  return (*puVar1 & param_1) != 0;
}


// ===== FUN_0800e838 @ 0800e838

void FUN_0800e838(uint *param_1)

{
  uint uVar1;
  
  *param_1 = *param_1 & 0xfffffffe;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  uVar1 = ((uint)param_1 & 0xff) - 8;
  if (((uint)param_1 & 0x4ff) < 0x408) {
    *(uint *)(DAT_0800e88c + 4) = 0xf << ((uVar1 / 0x14 & 0x3f) << 2) | *(uint *)(DAT_0800e88c + 4);
  }
  else if (((uint)param_1 & 0x4ff) < 0x488) {
    *DAT_0800e890 = 0xf << ((uVar1 / 0x14 & 0x3f) << 2) | *DAT_0800e890;
    return;
  }
  return;
}


// ===== FUN_0800e894 @ 0800e894

void FUN_0800e894(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  undefined8 uVar11;
  
  FUN_08007afa(param_1,param_2,param_1 + 0xf0U & 0xffff,param_2 + 0x40U & 0xffff);
  iVar4 = DAT_0800e93c;
  FUN_08012b28(DAT_0800e93c,1);
  FUN_0800fc90(DAT_0800e940,0x4000);
  iVar5 = DAT_0800e944;
  uVar7 = 0;
  piVar9 = (int *)(DAT_0800e93c + 8);
  uVar1 = *(ushort *)(DAT_0800e948 + 0x1a);
  uVar2 = *(ushort *)(DAT_0800e948 + 0x1c);
  puVar10 = (uint *)(DAT_0800e93c + 0xc);
  do {
    uVar8 = 0;
    uVar11 = FUN_080073f8(1,0,uVar7);
    do {
      do {
      } while (-1 < *piVar9 << 0x1e);
      puVar6 = (uint *)(iVar5 + uVar8 * 8);
      uVar3 = uVar1;
      if ((*puVar6 & (uint)uVar11) != 0 || (puVar6[1] & (uint)((ulonglong)uVar11 >> 0x20)) != 0) {
        uVar3 = uVar2;
      }
      *puVar10 = (uint)uVar3;
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 0xf0);
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0x33);
  FUN_08009cdc(10);
  FUN_0800fc94(DAT_0800e940,0x4000);
  FUN_08012b28(iVar4,0);
  FUN_080076e8(DAT_0800e944,0x788);
  return;
}


// ===== FUN_0800e94c @ 0800e94c

void FUN_0800e94c(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  
  FUN_08007afa(3,0x29,0x72,0x44);
  iVar1 = DAT_0800e9ec;
  FUN_08012b28(DAT_0800e9ec,1);
  FUN_0800fc90(DAT_0800e9f0,0x4000);
  iVar2 = DAT_0800e9f4;
  uVar4 = 0;
  piVar6 = (int *)(DAT_0800e9ec + 8);
  puVar7 = (undefined4 *)(DAT_0800e9ec + 0xc);
  do {
    uVar5 = 0;
    uVar8 = FUN_080073f8(1,0,uVar4);
    do {
      do {
      } while (-1 < *piVar6 << 0x1e);
      puVar3 = (uint *)(iVar2 + uVar5 * 8);
      if ((*puVar3 & (uint)uVar8) == 0 && (puVar3[1] & (uint)((ulonglong)uVar8 >> 0x20)) == 0) {
        *puVar7 = 0x153f;
      }
      else {
        *puVar7 = 0xf79e;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x70);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x1c);
  FUN_08009cdc(10);
  FUN_0800fc94(DAT_0800e9f0,0x4000);
  FUN_08012b28(iVar1,0);
  FUN_080076e8(DAT_0800e9f4,0x788);
  return;
}


// ===== FUN_0800e9f8 @ 0800e9f8

void FUN_0800e9f8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  iVar1 = FUN_0800efdc();
  if ((iVar1 == 0) && (iVar1 = FUN_080145a8(param_1,&uStack_10), iVar1 == 0)) {
    *param_1 = 0;
  }
  return;
}


// ===== FUN_0800ea16 @ 0800ea16

undefined8 FUN_0800ea16(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  local_30 = param_2;
  local_2c = param_3;
  local_28 = param_4;
  uVar2 = FUN_080145a8(param_1,&local_30);
  bVar13 = uVar2 == 0;
  do {
    if (!bVar13) goto LAB_0800ebfc;
    uVar2 = (uint)*(byte *)(param_1 + 0x11);
    bVar13 = uVar2 == 0;
  } while (!bVar13);
  puVar3 = *(uint **)(param_1 + 0x28);
  iVar12 = param_1 + 0x2c;
  if (puVar3 == (uint *)0x0) {
    if ((*(uint *)(param_1 + 0xc) < param_2) &&
       (-1 < (int)((uint)*(byte *)(param_1 + 0x10) << 0x1e))) {
      param_2 = *(uint *)(param_1 + 0xc);
    }
    iVar11 = 0;
    iVar5 = *(int *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(local_30 + 10);
      uVar7 = (uint)uVar1 * 0x1000;
      if ((iVar5 == 0) || (uVar9 = iVar5 - 1, (param_2 - 1) / uVar7 < uVar9 / uVar7)) {
        iVar5 = *(int *)(param_1 + 8);
        if (iVar5 != 0) {
LAB_0800eb6e:
          *(int *)(param_1 + 0x18) = iVar5;
          goto LAB_0800eb70;
        }
        iVar5 = FUN_08009726(param_1,0);
        if (iVar5 != 1) {
          if (iVar5 == -1) goto LAB_0800ec18;
          *(int *)(param_1 + 8) = iVar5;
          goto LAB_0800eb6e;
        }
LAB_0800ebf6:
        *(undefined1 *)(param_1 + 0x11) = 2;
        uVar2 = 2;
        goto LAB_0800ebfc;
      }
      uVar9 = uVar9 & ~(uVar7 - 1);
      *(uint *)(param_1 + 0x14) = uVar9;
      param_2 = param_2 - uVar9;
      iVar5 = *(int *)(param_1 + 0x18);
LAB_0800eb70:
      if (iVar5 != 0) {
        while (uVar7 < param_2) {
          param_2 = param_2 + (uint)uVar1 * -0x1000;
          *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar7;
          if ((int)((uint)*(byte *)(param_1 + 0x10) << 0x1e) < 0) {
            uVar9 = FUN_08009726();
            if (uVar9 == 0) {
              param_2 = 0;
              break;
            }
          }
          else {
            uVar9 = FUN_0800fae4(param_1);
          }
          if (uVar9 == 0xffffffff) goto LAB_0800ec18;
          if ((uVar9 < 2) || (*(uint *)(local_30 + 0x14) <= uVar9)) goto LAB_0800ebf6;
          *(uint *)(param_1 + 0x18) = uVar9;
        }
        *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_2;
        if ((param_2 & 0xfff) != 0) {
          iVar11 = FUN_08009654(local_30);
          if (iVar11 == 0) goto LAB_0800ebf6;
          iVar11 = iVar11 + (param_2 >> 0xc);
        }
      }
    }
    uVar7 = *(uint *)(param_1 + 0x14);
    if (*(uint *)(param_1 + 0xc) < uVar7) {
      *(uint *)(param_1 + 0xc) = uVar7;
      *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 0x40;
    }
    if (((uVar7 & 0xfff) == 0) || (*(int *)(param_1 + 0x1c) == iVar11)) goto LAB_0800ebfc;
    if ((int)((uint)*(byte *)(param_1 + 0x10) << 0x18) < 0) {
      iVar5 = FUN_0800a09c(*(undefined1 *)(local_30 + 1),iVar12,*(int *)(param_1 + 0x1c),1);
      if (iVar5 != 0) goto LAB_0800ec18;
      *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0x7f;
    }
    iVar12 = FUN_0800a048(*(undefined1 *)(local_30 + 1),iVar12,iVar11,1);
    if (iVar12 == 0) {
      *(int *)(param_1 + 0x1c) = iVar11;
      goto LAB_0800ebfc;
    }
  }
  else {
    if (param_2 == 0xffffffff) {
      local_2c = *puVar3;
      puVar3 = puVar3 + 1;
      uVar7 = *(uint *)(param_1 + 8);
      uVar9 = 2;
      if (uVar7 != 0) {
        do {
          uVar10 = 0;
          uVar9 = uVar9 + 2;
          uVar8 = uVar7;
          local_28 = uVar7;
          do {
            uVar10 = uVar10 + 1;
            uVar7 = FUN_0800fae4(param_1);
            if (uVar7 < 2) goto LAB_0800ebf6;
            if (uVar7 == 0xffffffff) goto LAB_0800ec18;
            uVar6 = uVar8 + 1;
            uVar8 = uVar7;
          } while (uVar7 == uVar6);
          if (uVar9 <= local_2c) {
            *puVar3 = uVar10;
            puVar3[1] = local_28;
            puVar3 = puVar3 + 2;
          }
        } while (uVar7 < *(uint *)(local_30 + 0x14));
      }
      **(uint **)(param_1 + 0x28) = uVar9;
      if (local_2c < uVar9) {
        uVar2 = 0x11;
      }
      else {
        *puVar3 = 0;
      }
      goto LAB_0800ebfc;
    }
    if (*(uint *)(param_1 + 0xc) < param_2) {
      param_2 = *(uint *)(param_1 + 0xc);
    }
    *(uint *)(param_1 + 0x14) = param_2;
    bVar13 = param_2 == 0;
    do {
      do {
        if (bVar13) goto LAB_0800ebfc;
        uVar4 = FUN_08009630(param_1,param_2 - 1);
        *(undefined4 *)(param_1 + 0x18) = uVar4;
        iVar5 = FUN_08009654(local_30,uVar4);
        if (iVar5 == 0) goto LAB_0800ebf6;
        param_2 = (*(ushort *)(local_30 + 10) - 1 & param_2 - 1 >> 0xc) + iVar5;
        bVar13 = true;
      } while ((*(ushort *)(param_1 + 0x14) & 0xfff) == 0);
      bVar13 = true;
    } while (*(uint *)(param_1 + 0x1c) == param_2);
    if ((int)((uint)*(byte *)(param_1 + 0x10) << 0x18) < 0) {
      iVar5 = FUN_0800a09c(*(undefined1 *)(local_30 + 1),iVar12,*(uint *)(param_1 + 0x1c),1);
      if (iVar5 != 0) goto LAB_0800ec18;
      *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0x7f;
    }
    iVar12 = FUN_0800a048(*(undefined1 *)(local_30 + 1),iVar12,param_2,1);
    if (iVar12 == 0) {
      *(uint *)(param_1 + 0x1c) = param_2;
      goto LAB_0800ebfc;
    }
  }
LAB_0800ec18:
  *(undefined1 *)(param_1 + 0x11) = 1;
  uVar2 = 1;
LAB_0800ebfc:
  return CONCAT44(local_30,uVar2);
}


// ===== FUN_0800ec28 @ 0800ec28

undefined4 FUN_0800ec28(undefined1 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 local_18;
  undefined1 *local_14;
  undefined4 local_10;
  int iStack_c;
  
  local_18 = param_2;
  local_14 = param_1;
  local_10 = param_2;
  iStack_c = param_3;
  iVar2 = FUN_0800fc58(&local_18);
  iVar1 = DAT_0800ec6c;
  if (iVar2 < 0) {
    uVar3 = 0xb;
  }
  else {
    puVar4 = *(undefined1 **)(DAT_0800ec6c + iVar2 * 4);
    if (puVar4 != (undefined1 *)0x0) {
      *puVar4 = 0;
    }
    if (local_14 != (undefined1 *)0x0) {
      *local_14 = 0;
    }
    *(undefined1 **)(iVar1 + iVar2 * 4) = local_14;
    if (param_3 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_080116cc(&local_10,&local_14,0);
    }
  }
  return uVar3;
}


// ===== FUN_0800ec70 @ 0800ec70

int FUN_0800ec70(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_58;
  int local_54;
  byte local_4e;
  int local_38;
  byte local_29;
  int *piStack_28;
  undefined4 local_24;
  uint uStack_20;
  
  if (param_1 == (int *)0x0) {
    return 9;
  }
  uVar5 = param_3 & 0x3f;
  piStack_28 = param_1;
  local_24 = param_2;
  uStack_20 = param_3;
  iVar1 = FUN_080116cc(&local_24,&local_58,uVar5);
  if (iVar1 != 0) goto LAB_0800ee16;
  local_54 = local_58;
  iVar1 = FUN_0800f9f4(&local_54,local_24);
  if ((iVar1 == 0) && ((int)((uint)local_29 << 0x18) < 0)) {
    iVar1 = 6;
  }
  if ((param_3 & 0x1c) == 0) {
    if (iVar1 != 0) goto LAB_0800ee16;
    if ((int)((uint)local_4e << 0x1b) < 0) {
      iVar1 = 4;
      goto LAB_0800ee16;
    }
    if (((int)(param_3 << 0x1e) < 0) && ((local_4e & 1) != 0)) goto LAB_0800ecda;
LAB_0800ed6a:
    if ((int)(uVar5 << 0x1c) < 0) {
LAB_0800ed6e:
      uVar5 = uVar5 | 0x40;
    }
  }
  else {
    if (iVar1 == 0) {
      if ((local_4e & 0x11) != 0) {
LAB_0800ecda:
        iVar1 = 7;
        goto LAB_0800ee16;
      }
      if ((int)(param_3 << 0x1d) < 0) {
        iVar1 = 8;
        goto LAB_0800ee16;
      }
    }
    else {
      if (iVar1 == 4) {
        iVar1 = FUN_08009f12(&local_54);
      }
      uVar5 = uVar5 | 8;
      if (iVar1 != 0) goto LAB_0800ee16;
    }
    uVar6 = DAT_0800ee24;
    if ((int)(uVar5 << 0x1c) < 0) {
      FUN_08012c58(local_38 + 0xe,DAT_0800ee24);
      FUN_08012c58(local_38 + 0x16,uVar6);
      iVar2 = FUN_080105c8(local_58,local_38);
      *(undefined1 *)(local_38 + 0xb) = 0x20;
      FUN_08012c30(local_58,local_38,0);
      FUN_08012c58(local_38 + 0x1c,0);
      *(undefined1 *)(local_58 + 3) = 1;
      if (iVar2 != 0) {
        uVar6 = *(undefined4 *)(local_58 + 0x2c);
        iVar1 = FUN_080122c4(&local_54,iVar2,0);
        if (iVar1 != 0) goto LAB_0800ee16;
        iVar1 = FUN_0801191c(local_58,uVar6);
        *(int *)(local_58 + 0xc) = iVar2 + -1;
        if (iVar1 != 0) goto LAB_0800ee16;
        goto LAB_0800ed6a;
      }
      goto LAB_0800ed6e;
    }
  }
  param_1[8] = *(int *)(local_58 + 0x2c);
  param_1[9] = local_38;
  iVar2 = FUN_080105c8(local_58,local_38);
  param_1[2] = iVar2;
  iVar2 = FUN_080105ee(local_38 + 0x1c);
  param_1[10] = 0;
  param_1[3] = iVar2;
  *param_1 = local_58;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(local_58 + 6);
  *(char *)(param_1 + 4) = (char)uVar5;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  param_1[7] = 0;
  param_1[5] = 0;
  FUN_080076e8(param_1 + 0xb,0x1000);
  if (-1 < (int)(uVar5 << 0x1a)) {
    return iVar1;
  }
  uVar5 = param_1[3];
  if (uVar5 == 0) {
    return iVar1;
  }
  param_1[5] = uVar5;
  uVar4 = param_1[2];
  uVar3 = (uint)*(ushort *)(local_58 + 10);
  do {
    if (uVar5 <= uVar3 * 0x1000) break;
    uVar4 = FUN_0800fae4(param_1);
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
    iVar1 = FUN_08009654(local_58);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    else {
      iVar1 = iVar1 + (uVar5 >> 0xc);
      param_1[7] = iVar1;
      iVar1 = FUN_0800a048(*(undefined1 *)(local_58 + 1),param_1 + 0xb,iVar1,1);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = 1;
    }
  }
LAB_0800ee16:
  *param_1 = 0;
  return iVar1;
}


// ===== FUN_0800ee28 @ 0800ee28

int FUN_0800ee28(int *param_1,undefined4 param_2)

{
  int iVar1;
  int local_18 [2];
  int *piStack_10;
  undefined4 local_c;
  
  if (param_1 == (int *)0x0) {
    return 9;
  }
  piStack_10 = param_1;
  local_c = param_2;
  iVar1 = FUN_080116cc(&local_c,local_18,0);
  if (iVar1 != 0) goto LAB_0800ee80;
  *param_1 = local_18[0];
  iVar1 = FUN_0800f9f4(param_1,local_c);
  if (iVar1 == 0) {
    if ((int)((uint)*(byte *)((int)param_1 + 0x2b) << 0x18) < 0) {
LAB_0800ee6a:
      *(undefined2 *)(param_1 + 1) = *(undefined2 *)(local_18[0] + 6);
      iVar1 = FUN_08009f70(param_1,0);
      goto LAB_0800ee78;
    }
    if ((int)((uint)*(byte *)((int)param_1 + 6) << 0x1b) < 0) {
      iVar1 = FUN_080105c8(local_18[0],param_1[7]);
      param_1[2] = iVar1;
      goto LAB_0800ee6a;
    }
  }
  else {
LAB_0800ee78:
    if (iVar1 != 4) {
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_0800ee80;
    }
  }
  iVar1 = 5;
LAB_0800ee80:
  *param_1 = 0;
  return iVar1;
}


// ===== FUN_0800ee8a @ 0800ee8a

undefined8 FUN_0800ee8a(int param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_30;
  int *local_28;
  
  *param_4 = 0;
  local_28 = param_4;
  uVar1 = FUN_080145a8(param_1,&local_28);
  local_30 = param_2;
  if ((uVar1 == 0) && (uVar1 = (uint)*(byte *)(param_1 + 0x11), uVar1 == 0)) {
    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
      uVar1 = 7;
    }
    else {
      uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x14);
      iVar5 = param_1 + 0x2c;
      if (uVar1 < param_3) {
        param_3 = uVar1;
      }
      for (; param_3 != 0; param_3 = param_3 - uVar1) {
        uVar1 = *(uint *)(param_1 + 0x14);
        if ((uVar1 & 0xfff) == 0) {
          uVar4 = *(ushort *)((int)local_28 + 10) - 1 & uVar1 >> 0xc;
          if (uVar4 == 0) {
            if (uVar1 == 0) {
              uVar1 = *(uint *)(param_1 + 8);
            }
            else if (*(int *)(param_1 + 0x28) == 0) {
              uVar1 = FUN_0800fae4(param_1,*(undefined4 *)(param_1 + 0x18));
            }
            else {
              uVar1 = FUN_08009630(param_1);
            }
            if (1 < uVar1) {
              if (uVar1 != 0xffffffff) {
                *(uint *)(param_1 + 0x18) = uVar1;
                goto LAB_0800ef04;
              }
              goto LAB_0800ef98;
            }
          }
          else {
LAB_0800ef04:
            iVar2 = FUN_08009654(local_28,*(undefined4 *)(param_1 + 0x18));
            if (iVar2 != 0) {
              iVar2 = iVar2 + uVar4;
              local_30 = param_3 >> 0xc;
              if (local_30 == 0) {
                if (*(int *)(param_1 + 0x1c) != iVar2) {
                  if ((int)((uint)*(byte *)(param_1 + 0x10) << 0x18) < 0) {
                    iVar3 = FUN_0800a09c(*(undefined1 *)((int)local_28 + 1),iVar5,
                                         *(int *)(param_1 + 0x1c),1);
                    if (iVar3 != 0) goto LAB_0800ef98;
                    *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) & 0x7f;
                  }
                  iVar3 = FUN_0800a048(*(undefined1 *)((int)local_28 + 1),iVar5,iVar2,1);
                  if (iVar3 != 0) goto LAB_0800ef98;
                }
                *(int *)(param_1 + 0x1c) = iVar2;
                goto LAB_0800efa2;
              }
              if ((uint)*(ushort *)((int)local_28 + 10) < uVar4 + local_30) {
                local_30 = *(ushort *)((int)local_28 + 10) - uVar4;
              }
              iVar3 = FUN_0800a048(*(undefined1 *)((int)local_28 + 1),param_2,iVar2,local_30);
              if (iVar3 == 0) {
                if (((int)((uint)*(byte *)(param_1 + 0x10) << 0x18) < 0) &&
                   (uVar1 = *(int *)(param_1 + 0x1c) - iVar2, uVar1 < local_30)) {
                  FUN_080075a6(param_2 + uVar1 * 0x1000,iVar5,0x1000);
                }
                uVar1 = local_30 << 0xc;
                goto LAB_0800efbe;
              }
LAB_0800ef98:
              *(undefined1 *)(param_1 + 0x11) = 1;
              uVar1 = 1;
              goto LAB_0800eeca;
            }
          }
          *(undefined1 *)(param_1 + 0x11) = 2;
          uVar1 = 2;
          goto LAB_0800eeca;
        }
LAB_0800efa2:
        uVar4 = *(ushort *)(param_1 + 0x14) & 0xfff;
        uVar1 = 0x1000 - uVar4;
        if (param_3 < uVar1) {
          uVar1 = param_3;
        }
        FUN_080075a6(param_2,uVar4 + param_1 + 0x2c,uVar1);
LAB_0800efbe:
        *param_4 = *param_4 + uVar1;
        param_2 = param_2 + uVar1;
        *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar1;
      }
      uVar1 = 0;
    }
  }
LAB_0800eeca:
  return CONCAT44(local_30,uVar1);
}


// ===== FUN_0800efdc @ 0800efdc

int FUN_0800efdc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  
  local_18 = param_4;
  iVar2 = FUN_080145a8(param_1,&local_18);
  if ((iVar2 == 0) && ((int)((uint)*(byte *)(param_1 + 4) << 0x19) < 0)) {
    if ((int)((uint)*(byte *)(param_1 + 4) << 0x18) < 0) {
      iVar2 = FUN_0800a09c(*(undefined1 *)(local_18 + 1),param_1 + 0xb,param_1[7],1);
      if (iVar2 != 0) {
        return 1;
      }
      *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0x7f;
    }
    uVar1 = DAT_0800f068;
    iVar2 = FUN_0801191c(local_18,param_1[8]);
    if (iVar2 == 0) {
      iVar2 = param_1[9];
      *(byte *)(iVar2 + 0xb) = *(byte *)(iVar2 + 0xb) | 0x20;
      FUN_08012c30(*param_1,iVar2,param_1[2]);
      FUN_08012c58(iVar2 + 0x1c,param_1[3]);
      FUN_08012c58(iVar2 + 0x16,uVar1);
      FUN_08012c68(iVar2 + 0x12,0);
      *(undefined1 *)(local_18 + 3) = 1;
      iVar2 = FUN_08012d24();
      *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
      return iVar2;
    }
  }
  return iVar2;
}


// ===== FUN_0800f06c @ 0800f06c

int FUN_0800f06c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_70;
  byte local_6a;
  undefined4 local_54;
  byte local_45;
  undefined4 local_44 [2];
  undefined4 local_3c [2];
  int local_34;
  undefined4 local_c;
  
  local_c = param_1;
  iVar1 = FUN_080116cc(&local_c,local_44,2);
  if (iVar1 != 0) {
    return iVar1;
  }
  local_70 = local_44[0];
  iVar1 = FUN_0800f9f4(&local_70,local_c);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((int)((uint)local_45 << 0x18) < 0) {
    return 6;
  }
  if ((local_6a & 1) == 0) {
    iVar1 = FUN_080105c8(local_44[0],local_54);
    if ((int)((uint)local_6a << 0x1b) < 0) {
      local_3c[0] = local_44[0];
      local_34 = iVar1;
      iVar2 = FUN_08009f70(local_3c,0);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_08009eb2(local_3c,0);
      if (iVar2 == 0) goto LAB_0800f0a4;
      if (iVar2 != 4) {
        return iVar2;
      }
    }
    iVar2 = FUN_08009f52(&local_70);
    if ((iVar2 == 0) && ((iVar1 == 0 || (iVar2 = FUN_080122c4(&local_70,iVar1,0), iVar2 == 0)))) {
      iVar2 = FUN_08012d24(local_44[0]);
    }
  }
  else {
LAB_0800f0a4:
    iVar2 = 7;
  }
  return iVar2;
}


// ===== FUN_0800f100 @ 0800f100

void FUN_0800f100(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_0800f134;
  *DAT_0800f134 = 0xff;
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
  *(undefined1 *)(puVar1 + 0x9c) = 0;
  *(undefined1 *)((int)puVar1 + 0x139) = 0;
  *(undefined1 *)(puVar1 + 0x9d) = 0;
  *(undefined1 *)((int)puVar1 + 0x13b) = 9;
  *(undefined1 *)(puVar1 + 0x9e) = 10;
  *(undefined1 *)(puVar1 + 0x9f) = 0;
  return;
}


// ===== FUN_0800f138 @ 0800f138

void FUN_0800f138(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0800f208;
  if (*(char *)(DAT_0800f208 + 1) == '\0') {
    FUN_0800ad14(1);
    *(undefined1 *)(iVar2 + 1) = 1;
    *(undefined1 *)(iVar2 + 7) = 0;
  }
  iVar3 = DAT_0800f20c;
  cVar1 = *(char *)(DAT_0800f20c + 2);
  if (cVar1 == '\x01') {
    if ((*(char *)(iVar2 + 7) == '\0') || (*(char *)(iVar2 + 7) == '\x01')) {
      FUN_0800ad14(2);
      *(undefined1 *)(iVar2 + 7) = 2;
    }
  }
  else if (cVar1 == '\t') {
    if (*(char *)(iVar2 + 7) == '\x02') {
      FUN_0800ad14(1);
      *(undefined1 *)(iVar2 + 7) = 1;
    }
  }
  else if (cVar1 == '\x05') {
    if ((*(char *)(iVar2 + 7) == '\0') || (*(char *)(iVar2 + 7) == '\x01')) {
      FUN_0800ad14(0);
      *(undefined1 *)(iVar2 + 7) = 0;
      FUN_08011ad4(0,0,0,0,3);
      *(undefined1 *)(iVar2 + 3) = 0;
    }
    else {
      FUN_0800f100();
      FUN_080104f4(9999,0x8f,(uint)((short)(*(byte *)(iVar3 + 0x23) + 1) * 9999) / 10 & 0xffff);
      FUN_08013848(0);
      FUN_0800f06c(s_2__LOGO_jpg_0800f210);
      FUN_08013848(0x100000);
      FUN_0800e10c();
    }
  }
  else if (cVar1 == '\r') {
    FUN_0800ad14(0);
    *(undefined1 *)(iVar2 + 7) = 0;
  }
  if (*(char *)(iVar3 + 5) == '\x01') {
    FUN_0800e318(2);
    FUN_0800ad14(*(undefined1 *)(iVar2 + 7));
    *(undefined1 *)(iVar3 + 5) = 0;
  }
  return;
}


// ===== FUN_0800f270 @ 0800f270

void FUN_0800f270(undefined4 param_1)

{
  *(undefined4 *)(DAT_0800f278 + 0xc) = param_1;
  return;
}


// ===== FUN_0800f27c @ 0800f27c

void FUN_0800f27c(undefined2 *param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = DAT_0800f29c;
  *(uint *)(DAT_0800f29c + 0x10) = *(uint *)(DAT_0800f29c + 0x10) | 1;
  *param_1 = param_2;
  FUN_0800f2d8(0x100000);
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffe;
  return;
}


// ===== FUN_0800f2a0 @ 0800f2a0

void FUN_0800f2a0(void)

{
  *(uint *)(DAT_0800f2ac + 0x10) = *(uint *)(DAT_0800f2ac + 0x10) | 0x80;
  return;
}


// ===== FUN_0800f2b0 @ 0800f2b0

undefined4 FUN_0800f2b0(void)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if ((*(uint *)(DAT_0800f2d4 + 0xc) & 1) != 0) {
    return 0;
  }
  if (*(int *)(DAT_0800f2d4 + 0xc) << 0x1d < 0) {
    uVar1 = 1;
  }
  else if (*(int *)(DAT_0800f2d4 + 0xc) << 0x1b < 0) {
    return 2;
  }
  return uVar1;
}


// ===== FUN_0800f2d8 @ 0800f2d8

int FUN_0800f2d8(void)

{
  int iVar1;
  int extraout_r3;
  int extraout_r3_00;
  int iVar2;
  
  iVar1 = FUN_0800f2b0();
  iVar2 = extraout_r3;
  while (iVar1 == 0) {
    if (iVar2 == 0) goto LAB_0800f2f0;
    iVar1 = FUN_0800f2b0();
    iVar2 = extraout_r3_00 + -1;
  }
  if (iVar2 == 0) {
LAB_0800f2f0:
    iVar1 = 4;
  }
  return iVar1;
}


// ===== FUN_0800f2fc @ 0800f2fc

void FUN_0800f2fc(undefined2 *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
    *(undefined2 *)(param_2 + uVar1 * 2) = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== FUN_0800f318 @ 0800f318

void FUN_0800f318(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_0800f340;
  *(uint *)(DAT_0800f340 + 0x10) = *(uint *)(DAT_0800f340 + 0x10) | 2;
  *(undefined4 *)(iVar1 + 0x14) = param_1;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
  FUN_0800f2d8(iVar1 << 0x11);
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffd;
  return;
}


// ===== FUN_0800f344 @ 0800f344

undefined4 FUN_0800f344(void)

{
  return *DAT_0800f34c;
}


// ===== FUN_0800f350 @ 0800f350

undefined4 FUN_0800f350(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = param_1;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  FUN_08009ba4(DAT_0800f474,1);
  FUN_08009ba4(0x180000,1);
  iVar5 = DAT_0800f474 + -10;
  FUN_08009ba4(iVar5,1);
  FUN_08009ba4(iVar5,1);
  FUN_08009ba4(iVar5,1);
  FUN_08009ba4(iVar5,1);
  uVar1 = DAT_0800f478;
  local_28 = 0x10;
  local_24 = 0x1101800;
  FUN_0800fcb0(DAT_0800f478,&local_28);
  uVar2 = local_24;
  local_24._0_2_ = CONCAT11(0x18,(undefined1)local_24);
  local_28 = 0x20;
  local_24._3_1_ = SUB41(uVar2,3);
  local_24._0_3_ = CONCAT12(8,(undefined2)local_24);
  FUN_0800fcb0(uVar1,&local_28);
  uVar2 = local_24;
  local_24._0_2_ = CONCAT11(0x18,(undefined1)local_24);
  local_28 = 0x40;
  local_24._3_1_ = SUB41(uVar2,3);
  local_24._0_3_ = CONCAT12(8,(undefined2)local_24);
  FUN_0800fcb0(uVar1,&local_28);
  uVar2 = local_24;
  local_24._0_2_ = CONCAT11(0x18,(undefined1)local_24);
  local_28 = 0x80;
  local_24._3_1_ = SUB41(uVar2,3);
  local_24._0_3_ = CONCAT12(8,(undefined2)local_24);
  FUN_0800fcb0(uVar1,&local_28);
  FUN_0800fc94(uVar1,0x10);
  FUN_08012b08(&local_20);
  uVar2 = DAT_0800f47c;
  local_1c = 0x1010100;
  local_20 = 0x10100;
  FUN_08012b4a(DAT_0800f47c,&local_20);
  FUN_08012b1e(uVar2,1);
  FUN_0800fc90(uVar1,0x10);
  FUN_0800f4ec(0x90);
  FUN_0800f4ec(0);
  FUN_0800f4ec(0);
  FUN_0800f4ec(0);
  iVar5 = FUN_0800f4d8();
  uVar4 = FUN_0800f4d8();
  FUN_0800fc94(uVar1,0x10);
  puVar3 = DAT_0800f480;
  DAT_0800f480[2] = iVar5 << 8 | uVar4;
  *puVar3 = 0x300000;
  return 0;
}


// ===== FUN_0800f484 @ 0800f484

undefined4 FUN_0800f484(undefined1 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  bool bVar3;
  
  uVar1 = DAT_0800f4d4;
  FUN_0800fc90(DAT_0800f4d4,0x10);
  FUN_0800f4ec(3);
  FUN_0800f4ec((param_2 & 0xffffff) >> 0x10);
  FUN_0800f4ec((param_2 & 0xffff) >> 8);
  FUN_0800f4ec(param_2 & 0xff);
  while (bVar3 = param_3 != 0, param_3 = param_3 - 1 & 0xffff, bVar3) {
    uVar2 = FUN_0800f4ec(0xff);
    *param_1 = uVar2;
    param_1 = param_1 + 1;
  }
  FUN_0800fc94(uVar1,0x10);
  return 0;
}


// ===== FUN_0800f4d8 @ 0800f4d8

void FUN_0800f4d8(void)

{
  FUN_0800f4ec(0xff);
  return;
}


// ===== FUN_0800f4e0 @ 0800f4e0

undefined4 FUN_0800f4e0(void)

{
  return *(undefined4 *)(DAT_0800f4e8 + 4);
}


// ===== FUN_0800f4ec @ 0800f4ec

undefined1 FUN_0800f4ec(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  
  uVar1 = DAT_0800f51c;
  do {
    iVar3 = FUN_08012b3c(uVar1,2);
  } while (iVar3 == 0);
  FUN_08012b38(uVar1,param_1);
  do {
    iVar3 = FUN_08012b3c(uVar1,1);
  } while (iVar3 == 0);
  uVar2 = FUN_08012b32(uVar1);
  return uVar2;
}


// ===== FUN_0800f520 @ 0800f520

void FUN_0800f520(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = DAT_0800f548;
  FUN_0800fc90(DAT_0800f548,0x10);
  FUN_0800f4ec(5);
  do {
    uVar2 = FUN_0800f4ec(0xff);
  } while ((uVar2 & 1) != 0);
  FUN_0800fc94(uVar1,0x10);
  return;
}


// ===== FUN_0800f54c @ 0800f54c

undefined4 FUN_0800f54c(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = DAT_0800f614;
  uVar5 = param_2 & 0xfff;
  uVar6 = param_2 >> 0xc;
  uVar4 = 0x1000 - uVar5;
  if (param_3 <= 0x1000 - uVar5) {
    uVar4 = param_3;
  }
  while( true ) {
    FUN_0800f484(DAT_0800f614,uVar6 << 0xc,0x1000);
    for (uVar2 = 0; (uVar2 < uVar4 && (*(char *)(iVar1 + uVar5 + uVar2) == -1)); uVar2 = uVar2 + 1)
    {
    }
    if (uVar2 < uVar4) {
      FUN_0800f6a4();
      FUN_0800fc90(DAT_0800f618,0x10);
      FUN_0800f4ec(0x20);
      FUN_0800f4ec((uVar6 & 0xfff) >> 4);
      FUN_0800f4ec((uVar6 & 0xf) << 4);
      FUN_0800f4ec(0);
      FUN_0800fc94(DAT_0800f618,0x10);
      FUN_0800f520();
      for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
        *(undefined1 *)(iVar1 + uVar2 + uVar5) = *(undefined1 *)(param_1 + uVar2);
      }
      iVar3 = DAT_0800f614;
      uVar5 = uVar6 << 0xc;
      uVar2 = 0x1000;
    }
    else {
      iVar3 = param_1;
      uVar5 = param_2;
      uVar2 = uVar4;
    }
    FUN_0800f61c(iVar3,uVar5,uVar2);
    if (uVar4 == param_3) break;
    param_1 = param_1 + uVar4;
    param_2 = param_2 + uVar4;
    uVar5 = 0;
    param_3 = param_3 - uVar4 & 0xffff;
    uVar6 = uVar6 + 1;
    uVar4 = 0x1000;
    if (param_3 < 0x1001) {
      uVar4 = param_3;
    }
  }
  return 0;
}


// ===== FUN_0800f61c @ 0800f61c

void FUN_0800f61c(undefined1 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar1 = DAT_0800f6a0;
  uVar2 = 0x100 - (param_2 & 0xff);
  if (param_3 <= uVar2) {
    uVar2 = param_3;
  }
  while( true ) {
    FUN_0800f6a4();
    FUN_0800fc90(uVar1,0x10);
    FUN_0800f4ec(2);
    FUN_0800f4ec((param_2 & 0xffffff) >> 0x10);
    FUN_0800f4ec((param_2 & 0xffff) >> 8);
    FUN_0800f4ec(param_2 & 0xff);
    uVar3 = uVar2;
    puVar4 = param_1;
    while (bVar5 = uVar3 != 0, uVar3 = uVar3 - 1 & 0xffff, bVar5) {
      FUN_0800f4ec(*puVar4);
      puVar4 = puVar4 + 1;
    }
    FUN_0800fc94(uVar1,0x10);
    FUN_0800f520();
    if (uVar2 == param_3) break;
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


// ===== FUN_0800f6a4 @ 0800f6a4

void FUN_0800f6a4(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0800f6c4;
  FUN_0800fc90(DAT_0800f6c4,0x10);
  FUN_0800f4ec(6);
  FUN_0800fc94(uVar1,0x10);
  return;
}


// ===== FUN_0800f6c8 @ 0800f6c8

void FUN_0800f6c8(void)

{
  int iVar1;
  
  iVar1 = DAT_0800f6d8;
  *(undefined4 *)(DAT_0800f6d8 + 4) = DAT_0800f6d4;
  *(undefined4 *)(iVar1 + 4) = DAT_0800f6dc;
  return;
}


// ===== FUN_0800f6e0 @ 0800f6e0

undefined8 FUN_0800f6e0(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_30;
  
  FUN_0800f6c8();
  iVar1 = DAT_0800f7c4;
  uVar7 = (param_1 & 0x3ff) >> 1;
  uVar8 = param_1 + 0xf8000000 >> 10;
  uVar6 = 0x200 - uVar7;
  local_30 = param_1;
  if (param_3 <= 0x200 - uVar7) {
    uVar6 = param_3;
  }
  do {
    uVar2 = uVar8 * 0x400 + 0x8000000;
    FUN_0800f2fc(uVar2,DAT_0800f7c4,0x200);
    uVar3 = 0;
    while ((uVar3 < uVar6 && (*(short *)(iVar1 + (uVar7 + uVar3) * 2) == -1))) {
      uVar3 = uVar3 + 1 & 0xffff;
    }
    if (uVar3 < uVar6) {
      iVar4 = FUN_0800f2d8(0x40000000);
      if ((iVar4 == 1) || (iVar4 == 2)) {
        FUN_0800f270(0x14);
LAB_0800f750:
        iVar4 = FUN_0800f318(uVar2);
        if (iVar4 == 3) {
          for (uVar3 = 0; uVar3 < uVar6; uVar3 = uVar3 + 1 & 0xffff) {
            *(undefined2 *)(iVar1 + (uVar3 + uVar7) * 2) = *(undefined2 *)(param_2 + uVar3 * 2);
          }
          iVar4 = DAT_0800f7c4;
          uVar7 = 0x200;
          goto LAB_0800f784;
        }
      }
      else if (iVar4 != 4) goto LAB_0800f750;
LAB_0800f78c:
      uVar5 = 0;
      goto LAB_0800f78e;
    }
    uVar2 = local_30;
    iVar4 = param_2;
    uVar7 = uVar6;
LAB_0800f784:
    iVar4 = FUN_0800f7c8(uVar2,iVar4,uVar7);
    if (iVar4 != 1) goto LAB_0800f78c;
    if (param_3 == uVar6) {
      FUN_0800f2a0();
      uVar5 = 1;
LAB_0800f78e:
      return CONCAT44(local_30,uVar5);
    }
    param_2 = param_2 + uVar6 * 2;
    local_30 = local_30 + uVar6 * 2;
    uVar7 = 0;
    param_3 = param_3 - uVar6 & 0xffff;
    uVar8 = uVar8 + 1;
    uVar6 = 0x200;
    if (param_3 < 0x201) {
      uVar6 = param_3;
    }
  } while( true );
}


// ===== FUN_0800f7c8 @ 0800f7c8

undefined4 FUN_0800f7c8(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (param_3 <= uVar2) {
      return 1;
    }
    iVar1 = FUN_0800f27c(param_1,*(undefined2 *)(param_2 + uVar2 * 2));
    if (iVar1 != 3) break;
    uVar2 = uVar2 + 1 & 0xffff;
    param_1 = param_1 + 2;
  }
  return 0;
}


// ===== FUN_0800f7fc @ 0800f7fc

void FUN_0800f7fc(uint param_1,undefined4 param_2)

{
  uint uVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (*(char *)*DAT_0800f958 == '\x12') {
    if ((int)param_1 < DAT_0800f974) {
      if (DAT_0800f95c <= (int)param_1) {
        uVar4 = FUN_08015548();
        uVar3 = 0x20;
LAB_0800f8a0:
        FUN_08014af4(param_2,s__c_c_0_0f_c_0800f98c,uVar3,0x30,uVar4,0);
        return;
      }
      if ((int)param_1 < DAT_0800f960) {
        if (param_1 < DAT_0800f964) {
          FUN_08015548();
          uVar3 = 0x20;
        }
        else {
          if (DAT_0800f968 <= param_1) goto LAB_0800f880;
          uVar1 = param_1 ^ 0x80000000;
          if (DAT_0800f96c <= param_1) {
            uVar4 = FUN_08015548(uVar1);
            uVar3 = 0x2d;
            goto LAB_0800f8a0;
          }
          if (DAT_0800f970 <= param_1) {
            FUN_08015548(uVar1);
            uVar3 = 0x2d;
            goto LAB_0800f8be;
          }
          FUN_08015548(uVar1);
          uVar3 = 0x2d;
        }
        pcVar2 = s__c_c_c_c_0_0f_c_0800f9a8;
      }
      else {
        FUN_08015548();
        uVar3 = 0x20;
LAB_0800f8be:
        pcVar2 = s__c_c_c_0_0f_c_0800f998;
      }
      FUN_08014af4(param_2,pcVar2,uVar3,0x30,0x30);
      return;
    }
  }
  else if ((int)param_1 < DAT_0800f974) {
    if (DAT_0800f95c <= (int)param_1) {
      FUN_08015548();
      pcVar2 = s__c_0_1f_c_0800f9b8;
      goto LAB_0800f8ee;
    }
    if (DAT_0800f960 <= (int)param_1) {
      FUN_08015548();
      pcVar2 = s__c_0_2f_c_0800f9c4;
      goto LAB_0800f8ee;
    }
    if (param_1 < DAT_0800f964) {
      FUN_08015548();
      pcVar2 = s__c_0_3f_c_0800f9d0;
      goto LAB_0800f8ee;
    }
    if (param_1 < DAT_0800f968) {
      if (param_1 < DAT_0800f96c) {
        if (param_1 < DAT_0800f970) {
          uVar4 = FUN_08015548();
          pcVar2 = s__0_3f_c_0800f9ec;
        }
        else {
          uVar4 = FUN_08015548();
          pcVar2 = s__0_2f_c_0800f9e4;
        }
      }
      else {
        uVar4 = FUN_08015548();
        pcVar2 = s__0_1f_c_0800f9dc;
      }
      goto LAB_0800f92e;
    }
LAB_0800f880:
    uVar4 = FUN_08015548();
    pcVar2 = s__0_0f_c_0800f984;
LAB_0800f92e:
    FUN_08014af4(param_2,pcVar2,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0);
    return;
  }
  FUN_08015548();
  pcVar2 = s__c_0_0f_c_0800f978;
LAB_0800f8ee:
  FUN_08014af4(param_2,pcVar2,0x20);
  return;
}


// ===== FUN_0800f9f4 @ 0800f9f4

int FUN_0800f9f4(int *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *local_1c;
  
  iVar4 = *param_1;
  for (local_1c = param_2; (*local_1c == 0x2f || (*local_1c == 0x5c)); local_1c = local_1c + 1) {
  }
  param_1[2] = 0;
  if (*local_1c < 0x20) {
    *(undefined1 *)((int)param_1 + 0x2b) = 0x80;
    iVar1 = FUN_08009f70(param_1,0,param_3,param_4,param_1);
  }
  else {
    while (iVar1 = FUN_080098cc(param_1,&local_1c), iVar1 == 0) {
      iVar5 = *param_1;
      iVar1 = FUN_08009f70(param_1,0);
      if (iVar1 == 0) {
        while (iVar1 = FUN_0801191c(iVar5,param_1[6]), iVar1 == 0) {
          pcVar2 = (char *)param_1[7];
          if (*pcVar2 == '\0') {
            iVar1 = 4;
            break;
          }
          *(byte *)((int)param_1 + 6) = pcVar2[0xb] & 0x3f;
          if (((-1 < (int)((uint)(byte)pcVar2[0xb] << 0x1c)) &&
              (iVar3 = FUN_08007506(pcVar2,param_1 + 8,0xb), iVar3 == 0)) ||
             (iVar1 = FUN_08009e04(param_1,0), iVar1 != 0)) break;
        }
      }
      if (iVar1 != 0) {
        if (iVar1 != 4) {
          return iVar1;
        }
        if ((int)((uint)*(byte *)((int)param_1 + 0x2b) << 0x1d) < 0) {
          return 4;
        }
        return 5;
      }
      if ((int)((uint)*(byte *)((int)param_1 + 0x2b) << 0x1d) < 0) {
        return 0;
      }
      if (-1 < (int)((uint)*(byte *)((int)param_1 + 6) << 0x1b)) {
        return 5;
      }
      iVar1 = FUN_080105c8(iVar4,(*(ushort *)(param_1 + 4) & 0xfff) + iVar4 + 0x30);
      param_1[2] = iVar1;
    }
  }
  return iVar1;
}


// ===== FUN_0800fae4 @ 0800fae4

uint FUN_0800fae4(undefined4 *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  pcVar4 = (char *)*param_1;
  if ((1 < param_2) && (param_2 < *(uint *)(pcVar4 + 0x14))) {
    cVar1 = *pcVar4;
    if (cVar1 == '\x01') {
      uVar3 = param_2 + (param_2 >> 1);
      iVar2 = FUN_0801191c(pcVar4,*(int *)(pcVar4 + 0x20) + (uVar3 >> 0xc));
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      cVar1 = pcVar4[(uVar3 & 0xfff) + 0x30];
      iVar2 = FUN_0801191c(pcVar4,*(int *)(pcVar4 + 0x20) + (uVar3 + 1 >> 0xc));
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      if ((param_2 & 1) == 0) {
        return CONCAT11(pcVar4[(uVar3 + 1 & 0xfff) + 0x30],cVar1) & 0xfff;
      }
      return (uint)(ushort)(CONCAT11(pcVar4[(uVar3 + 1 & 0xfff) + 0x30],cVar1) >> 4);
    }
    if (cVar1 == '\x02') {
      iVar2 = FUN_0801191c(pcVar4,*(int *)(pcVar4 + 0x20) + (param_2 >> 0xb));
      if (iVar2 == 0) {
        uVar3 = FUN_08010604(pcVar4 + (param_2 & 0x7ff) * 2 + 0x30);
        return uVar3;
      }
      return 0xffffffff;
    }
    if (cVar1 == '\x03') {
      iVar2 = FUN_0801191c(pcVar4,*(int *)(pcVar4 + 0x20) + (param_2 >> 10));
      if (iVar2 == 0) {
        uVar3 = FUN_080105ee(pcVar4 + (param_2 & 0x3ff) * 4 + 0x30);
        return uVar3 & 0xfffffff;
      }
      return 0xffffffff;
    }
  }
  return 1;
}


// ===== FUN_0800fba0 @ 0800fba0

uint FUN_0800fba0(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0800fbe4;
  uVar2 = 0;
  if (*(short *)(DAT_0800fbe4 + 2) == 0) {
    *(short *)(DAT_0800fbe4 + 4) = (short)param_1;
  }
  else {
    if (*(ushort *)(DAT_0800fbe4 + 4) == param_1) {
      if (*(short *)(DAT_0800fbe4 + 2) != 1) {
        return 6;
      }
      goto LAB_0800fbc8;
    }
    *(short *)(DAT_0800fbe4 + 4) = (short)param_1;
    *(undefined2 *)(iVar1 + 2) = 0;
  }
  *(undefined2 *)(iVar1 + 2) = 1;
LAB_0800fbc8:
  *(undefined1 *)(iVar1 + 7) = 1;
  do {
    if (*(ushort *)(DAT_0800fbe8 + uVar2 * 8) == param_1) {
      return uVar2;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 6);
  return 6;
}


// ===== FUN_0800fbec @ 0800fbec

byte FUN_0800fbec(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  
  uVar1 = DAT_0800fc4c;
  iVar2 = FUN_0800fd5e(DAT_0800fc4c,0x10);
  bVar3 = iVar2 == 0;
  iVar2 = FUN_0800fd5e(uVar1,0x40);
  if (iVar2 == 0) {
    bVar3 = bVar3 | 2;
  }
  iVar2 = FUN_0800fd5e(uVar1,0x80);
  if (iVar2 == 0) {
    bVar3 = bVar3 | 8;
  }
  iVar2 = FUN_0800fd5e(uVar1,0x20);
  if (iVar2 == 0) {
    bVar3 = bVar3 | 0x10;
  }
  iVar2 = FUN_0800fd5e(DAT_0800fc50,0x80);
  if (iVar2 == 0) {
    bVar3 = bVar3 | 0x20;
  }
  iVar2 = FUN_0800fd5e(DAT_0800fc54,0x8000);
  if (iVar2 == 0) {
    bVar3 = bVar3 | 0x40;
  }
  return bVar3;
}


// ===== FUN_0800fc58 @ 0800fc58

uint FUN_0800fc58(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar5;
  byte *pbVar4;
  uint uVar6;
  
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


// ===== FUN_0800fc90 @ 0800fc90

void FUN_0800fc90(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


// ===== FUN_0800fc94 @ 0800fc94

void FUN_0800fc94(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}


// ===== FUN_0800fc98 @ 0800fc98

void FUN_0800fc98(undefined4 *param_1)

{
  *param_1 = 0xffff;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 4;
  *(undefined1 *)((int)param_1 + 7) = 1;
  return;
}


// ===== FUN_0800fcb0 @ 0800fcb0

void FUN_0800fcb0(uint *param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_2;
  uVar4 = (uint)uVar1;
  uVar3 = (uint)(byte)param_2[3];
  if (uVar3 == 3) {
    uVar3 = 0;
  }
  else if (uVar3 == 0) {
    uVar2 = (uint)*(byte *)((int)param_2 + 5);
    uVar3 = uVar2 & 0xf;
    if (uVar2 == 0x18) {
      param_1[4] = uVar4;
    }
    else if (uVar2 == 0x28) {
      param_1[5] = uVar4;
    }
  }
  else {
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
      if ((1 << (uVar4 & 0xff) & (uint)(uVar1 >> 8)) != 0) {
        param_1[1] = param_1[1] & ~(0xf << (uVar4 << 2 & 0xff));
        param_1[1] = param_1[1] | uVar3 << (uVar4 << 2 & 0xff);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 8);
  }
  return;
}


// ===== FUN_0800fd5e @ 0800fd5e

bool FUN_0800fd5e(int param_1,uint param_2)

{
  return (param_2 & ~*(uint *)(param_1 + 8)) == 0;
}


// ===== FUN_0800fd6c @ 0800fd6c

void FUN_0800fd6c(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  iVar1 = DAT_0800fdd0;
  if (*(char *)(DAT_0800fdd0 + 1) == '\0') {
    *(undefined1 *)(DAT_0800fdd0 + 1) = 1;
    if (*(char *)(iVar1 + 2) == '\0') {
      *(undefined1 *)(iVar1 + 2) = 1;
      *(undefined1 *)(iVar1 + 8) = 0;
    }
  }
  iVar2 = DAT_0800fdd4;
  if (*(char *)(DAT_0800fdd4 + 2) == '\x01') {
    if (*(byte *)(iVar1 + 8) == 0) goto LAB_0800fdba;
    sVar3 = *(byte *)(iVar1 + 8) - 1;
  }
  else {
    if (*(char *)(DAT_0800fdd4 + 2) != '\t') goto LAB_0800fdba;
    sVar3 = *(byte *)(iVar1 + 8) + 1;
    if ((*(ushort *)(DAT_0800fdd8 + 0x10) <= (ushort)(sVar3 * 6)) || (3 < *(byte *)(iVar1 + 8)))
    goto LAB_0800fdba;
  }
  *(char *)(iVar1 + 8) = (char)sVar3;
  FUN_0800b1d4(sVar3 + 1U & 0xff);
LAB_0800fdba:
  if (*(char *)(iVar2 + 5) == '\x01') {
    FUN_0800b1d4(*(char *)(iVar1 + 8) + '\x01');
    *(undefined1 *)(iVar2 + 5) = 0;
  }
  return;
}


// ===== FUN_0800fddc @ 0800fddc

uint FUN_0800fddc(int *param_1,byte *param_2,ushort *param_3,byte *param_4)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar6 = (uint)*(byte *)(param_1 + 3);
  iVar2 = *param_1;
  pbVar3 = (byte *)param_1[1];
  uVar4 = (uint)*pbVar3;
  uVar7 = 0;
  iVar8 = 0x10;
  bVar1 = false;
  do {
    if (uVar6 == 0) {
      if (iVar2 == 0) {
        pbVar3 = (byte *)param_1[2];
        iVar2 = (*(code *)param_1[0x1d])(param_1,pbVar3,0x200);
        if (iVar2 == 0) {
          return 0xfffffffe;
        }
      }
      else {
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
LAB_0800fe3e:
        uVar6 = 0x80;
        goto LAB_0800fe40;
      }
      uVar4 = (uint)*pbVar3;
      if (uVar4 != 0xff) goto LAB_0800fe3e;
      bVar1 = true;
    }
    else {
LAB_0800fe40:
      uVar7 = uVar7 * 2;
      if ((uVar4 & uVar6) != 0) {
        uVar7 = uVar7 + 1;
      }
      uVar6 = uVar6 >> 1;
      for (uVar5 = (uint)*param_2; uVar5 != 0; uVar5 = uVar5 - 1) {
        if (*param_3 == uVar7) {
          *(char *)(param_1 + 3) = (char)uVar6;
          *param_1 = iVar2;
          param_1[1] = (int)pbVar3;
          return (uint)*param_4;
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
  } while( true );
}


// ===== FUN_0800fe82 @ 0800fe82

int FUN_0800fe82(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_2 != 0) {
    FUN_0800ee8a();
    return param_4;
  }
  iVar1 = FUN_0800ea16(**(int **)(param_1 + 0x78),
                       *(int *)(**(int **)(param_1 + 0x78) + 0x14) + param_3);
  if (iVar1 == 0) {
    return param_3;
  }
  return 0;
}


// ===== FUN_0800fea8 @ 0800fea8

int FUN_0800fea8(int *param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  if (param_3 < 4) {
    *(char *)((int)param_1 + 0xd) = (char)param_3;
    bVar1 = *(byte *)((int)param_1 + 0xe);
    bVar2 = *(byte *)((int)param_1 + 0xf);
    sVar8 = 0;
    *(undefined2 *)(param_1 + 5) = 0;
    *(undefined2 *)((int)param_1 + 0x16) = 0;
    *(undefined2 *)(param_1 + 6) = 0;
    uVar12 = 0;
    for (uVar5 = 0; iVar4 = 0, uVar5 < (uint)param_1[8]; uVar5 = uVar5 + (uint)bVar2 * 8) {
      for (uVar6 = 0; uVar6 < (uint)param_1[7]; uVar6 = uVar6 + (uint)bVar1 * 8) {
        if ((*(short *)((int)param_1 + 0x1a) != 0) &&
           (bVar13 = sVar8 == *(short *)((int)param_1 + 0x1a), sVar8 = sVar8 + 1, bVar13)) {
          iVar4 = *param_1;
          pbVar9 = (byte *)param_1[1];
          uVar11 = 0;
          uVar10 = 0;
          do {
            if (iVar4 == 0) {
              pbVar9 = (byte *)param_1[2];
              iVar4 = (*(code *)param_1[0x1d])(param_1,pbVar9,0x200);
              if (iVar4 == 0) {
                return 2;
              }
            }
            else {
              pbVar9 = pbVar9 + 1;
            }
            iVar4 = iVar4 + -1;
            uVar7 = (uint)*pbVar9;
            uVar11 = uVar11 + 1;
            uVar3 = uVar10 << 8;
            uVar10 = uVar7;
          } while (uVar11 < 2);
          *param_1 = iVar4;
          param_1[1] = (int)pbVar9;
          *(undefined1 *)(param_1 + 3) = 0;
          if (((uVar7 & 0xffffffd8 | uVar3) != 0xffd0) || ((uVar7 & 7) != (uVar12 & 7))) {
            return 6;
          }
          *(undefined2 *)(param_1 + 5) = 0;
          *(undefined2 *)((int)param_1 + 0x16) = 0;
          *(undefined2 *)(param_1 + 6) = 0;
          sVar8 = 1;
          uVar12 = uVar12 + 1 & 0xffff;
        }
        iVar4 = FUN_080107fc(param_1);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_0801096c(param_1,param_2,uVar6,uVar5);
        if (iVar4 != 0) {
          return iVar4;
        }
      }
    }
  }
  else {
    iVar4 = 5;
  }
  return iVar4;
}


// ===== FUN_0800ff9c @ 0800ff9c

/* WARNING: Type propagation algorithm not settling */

uint FUN_0800ff9c(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  ushort uVar1;
  byte bVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  ushort *puVar12;
  bool bVar13;
  
  if (param_3 == 0) {
    return 5;
  }
  param_1[0x1d] = param_2;
  param_1[0x1e] = param_5;
  param_1[0x1b] = param_3;
  param_1[0x1c] = param_4;
  *(undefined2 *)((int)param_1 + 0x1a) = 0;
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
  puVar3 = (ushort *)FUN_08009180(param_1,0x200);
  param_1[2] = puVar3;
  if (puVar3 == (ushort *)0x0) {
    return 3;
  }
  iVar4 = (*(code *)param_1[0x1d])(param_1,puVar3,2);
  bVar13 = iVar4 == 2;
LAB_08010002:
  if (!bVar13) {
    return 2;
  }
  bVar13 = (ushort)(*puVar3 << 8 | *puVar3 >> 8) == 0xffd8;
LAB_08010018:
  if (!bVar13) {
    return 6;
  }
  uVar9 = 2;
LAB_0801001e:
  iVar4 = (*(code *)param_1[0x1d])(param_1,puVar3,4);
  bVar13 = iVar4 == 4;
  if (!bVar13) goto LAB_08010002;
  uVar8 = (puVar3[1] & 0xff) << 8 | (uint)(puVar3[1] >> 8);
  if (uVar8 < 3) {
    return 6;
  }
  bVar13 = false;
  if ((*puVar3 & 0xff) == 0xff) {
    uVar8 = uVar8 - 2;
    uVar9 = uVar9 + uVar8 + 4;
    switch((char)(*puVar3 >> 8)) {
    case -0x40:
      if (0x200 < uVar8) {
        return 4;
      }
      uVar7 = (*(code *)param_1[0x1d])(param_1,puVar3,uVar8);
      bVar13 = uVar7 == uVar8;
      if (!bVar13) goto LAB_08010002;
      param_1[7] = (*(ushort *)((int)puVar3 + 3) & 0xff) << 8 |
                   (uint)(*(ushort *)((int)puVar3 + 3) >> 8);
      param_1[8] = (*(ushort *)((int)puVar3 + 1) & 0xff) << 8 |
                   (uint)(*(ushort *)((int)puVar3 + 1) >> 8);
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
        }
        else if (bVar2 != 0x11) {
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
      goto LAB_0801001e;
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
      uVar7 = (*(code *)param_1[0x1d])(param_1,puVar3,uVar8);
      if (uVar7 != uVar8) {
        return 2;
      }
      bVar2 = FUN_08009800(param_1,puVar3,uVar8);
      uVar7 = (uint)bVar2;
      break;
    default:
      uVar7 = (*(code *)param_1[0x1d])(param_1,0,uVar8);
      bVar13 = true;
      if (uVar7 != uVar8) {
        return 2;
      }
      goto LAB_08010194;
    case -0x26:
      if (0x200 < uVar8) {
        return 4;
      }
      uVar7 = (*(code *)param_1[0x1d])(param_1,puVar3,uVar8);
      if (uVar7 != uVar8) {
        return 2;
      }
      if (param_1[7] == 0) {
        return 6;
      }
      if (param_1[8] == 0) {
        return 6;
      }
      if ((char)*puVar3 != '\x03') {
        return 8;
      }
      uVar8 = 0;
      while( true ) {
        if (((char)puVar3[uVar8 + 1] != '\0') && ((char)puVar3[uVar8 + 1] != '\x11')) {
          return 8;
        }
        if (param_1[(uint)(uVar8 != 0) * 2 + 9] == 0) {
          return 6;
        }
        if (param_1[(uint)(uVar8 != 0) * 2 + 10] == 0) break;
        if (param_1[*(byte *)((int)param_1 + uVar8 + 0x10) + 0x15] == 0) {
          return 6;
        }
        uVar8 = uVar8 + 1;
        if (2 < uVar8) {
          iVar4 = (int)(short)(ushort)*(byte *)((int)param_1 + 0xf) *
                  (int)(short)(ushort)*(byte *)((int)param_1 + 0xe);
          if (iVar4 == 0) {
            return 6;
          }
          uVar8 = iVar4 * 0x80 + 0x40;
          if (uVar8 < 0x100) {
            uVar8 = 0x100;
          }
          iVar5 = FUN_08009180(param_1,uVar8);
          param_1[0x19] = iVar5;
          if (iVar5 != 0) {
            iVar4 = FUN_08009180(param_1,iVar4 * 0x40 + 0x80);
            param_1[0x1a] = iVar4;
            if (iVar4 != 0) {
              *param_1 = 0;
              param_1[1] = puVar3;
              *(undefined1 *)(param_1 + 3) = 0;
              uVar9 = uVar9 & 0x1ff;
              if (uVar9 != 0) {
                uVar6 = (*(code *)param_1[0x1d])
                                  (param_1,(char *)((int)puVar3 + uVar9),0x200 - uVar9);
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
    case -0x25:
      if (0x200 < uVar8) {
        return 4;
      }
      uVar7 = (*(code *)param_1[0x1d])(param_1,puVar3,uVar8);
      if (uVar7 != uVar8) {
        return 2;
      }
      puVar12 = puVar3;
      while (uVar8 != 0) {
        if (uVar8 < 0x41) {
LAB_08010146:
          uVar7 = 6;
          goto LAB_08010192;
        }
        uVar1 = *puVar12;
        uVar8 = uVar8 - 0x41;
        if ((byte)((byte)uVar1 >> 4) != 0) goto LAB_08010146;
        iVar5 = FUN_08009180(param_1,0x100);
        iVar4 = DAT_08010270;
        if (iVar5 == 0) {
          uVar7 = 3;
          goto LAB_08010192;
        }
        param_1[((byte)uVar1 & 3) + 0x15] = iVar5;
        uVar7 = 0;
        puVar11 = (ushort *)((int)puVar12 + 1);
        do {
          uVar10 = (uint)*(byte *)(iVar4 + uVar7);
          puVar12 = (ushort *)((int)puVar11 + 1);
          uVar7 = uVar7 + 1;
          *(uint *)(iVar5 + uVar10 * 4) =
               (uint)(byte)*puVar11 * (uint)*(ushort *)(iVar4 + 0x40 + uVar10 * 2);
          puVar11 = puVar12;
        } while (uVar7 < 0x40);
      }
      uVar7 = 0;
      break;
    case -0x23:
      goto switchD_08010052_caseD_dd;
    }
LAB_08010192:
    bVar13 = uVar7 == 0;
LAB_08010194:
    if (!bVar13) {
      return uVar7;
    }
    goto LAB_0801001e;
  }
  goto LAB_08010018;
switchD_08010052_caseD_dd:
  if (0x200 < uVar8) {
    return 4;
  }
  uVar7 = (*(code *)param_1[0x1d])(param_1,puVar3,uVar8);
  if (uVar7 != uVar8) {
    return 2;
  }
  *(ushort *)((int)param_1 + 0x1a) = *puVar3 << 8 | *puVar3 >> 8;
  goto LAB_0801001e;
}


// ===== FUN_08010274 @ 08010274

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_08010274(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_a4 [124];
  undefined4 local_28 [4];
  
  iVar2 = FUN_0800ec70(_DAT_080102f0,param_1,1);
  if (iVar2 == 0) {
    local_28[0] = _DAT_080102f0;
    uVar4 = FUN_0800725e(0x1c00);
    iVar2 = FUN_0800ff9c(auStack_a4,DAT_08010308,uVar4,0x1c00,local_28);
    uVar3 = DAT_08010310;
    puVar1 = DAT_0801030c;
    if (iVar2 == 0) {
      *DAT_0801030c = param_2;
      puVar1[1] = param_3;
      FUN_0800fea8(auStack_a4,uVar3,0);
    }
    else if (iVar2 == 2) {
      FUN_08007420(&DAT_08010314,param_1);
    }
    FUN_080072bc(uVar4);
    FUN_0800e9f8(local_28[0]);
    uVar3 = 0;
  }
  else {
    FUN_08007420(s__s_open_error_080102f3 + 1,param_1);
    uVar3 = 1;
  }
  return uVar3;
}


// ===== FUN_08010320 @ 08010320

void FUN_08010320(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = DAT_080103ac;
  local_18 = param_3;
  local_14 = param_4;
  FUN_08009ba4(DAT_080103ac,1);
  FUN_08009ba4(iVar1,1);
  FUN_08009ba4(iVar1,1);
  FUN_08009ba4(iVar1,1);
  FUN_08009ba4(iVar1 + 4,1);
  uVar2 = DAT_080103b0;
  local_18 = 0x10;
  local_14 = 0x3001800;
  FUN_0800fcb0(DAT_080103b0,&local_18);
  local_18 = 0x40;
  FUN_0800fcb0(uVar2,&local_18);
  local_18 = 0x80;
  FUN_0800fcb0(uVar2,&local_18);
  local_18 = 0x20;
  FUN_0800fcb0(uVar2,&local_18);
  local_18 = 0x80;
  FUN_0800fcb0(DAT_080103b4,&local_18);
  local_18 = 0x8000;
  FUN_0800fcb0(DAT_080103b8,&local_18);
  return;
}


// ===== FUN_080103bc @ 080103bc

undefined1 FUN_080103bc(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = DAT_0801040c;
  if (*(ushort *)(DAT_0801040c + 4) == param_1) {
    pbVar1 = (byte *)(DAT_0801040c + 6);
    if (*pbVar1 < 6) {
      uVar3 = *(short *)(DAT_0801040c + 2) + 1;
      uVar4 = (uint)uVar3;
      *(ushort *)(DAT_0801040c + 2) = uVar3;
      if (uVar4 == 1) {
        *(undefined1 *)(iVar2 + 7) = 1;
      }
      else {
        iVar5 = DAT_08010410 + (uint)*pbVar1 * 8;
        uVar3 = *(ushort *)(iVar5 + 6);
        if (uVar3 == uVar4) {
          return *(undefined1 *)(iVar5 + 3);
        }
        if (uVar3 + 0x14 == uVar4) {
          *(ushort *)(iVar2 + 2) = uVar3;
          return *(undefined1 *)(iVar5 + 4);
        }
      }
      return 0;
    }
  }
  else {
    *(short *)(DAT_0801040c + 4) = (short)param_1;
    *(undefined1 *)(iVar2 + 7) = 0;
    *(undefined2 *)(iVar2 + 2) = 0;
  }
  return 0;
}


// ===== FUN_08010414 @ 08010414

undefined1 FUN_08010414(void)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = DAT_08010474;
  iVar1 = DAT_08010470;
  uVar3 = 0;
  if ((*(char *)(DAT_08010470 + 7) != '\0') &&
     (uVar5 = (uint)*(byte *)(DAT_08010470 + 6), uVar5 < 6)) {
    iVar4 = DAT_08010474 + uVar5 * 8;
    if ((*(ushort *)(DAT_08010470 + 2) < *(ushort *)(iVar4 + 6)) &&
       (uVar3 = *(undefined1 *)(iVar4 + 2), *(char *)(iVar4 + 5) != '\0')) {
      iVar4 = DAT_08010470 + 9;
      if (*(char *)(uVar5 + iVar4) == '\0') {
        *(undefined1 *)(uVar5 + iVar4) = 1;
        *(undefined2 *)(iVar1 + (uint)*(byte *)(iVar1 + 6) * 2 + 0x10) = 0x1e;
        *(undefined1 *)(iVar1 + 8) = 1;
        uVar3 = 0;
      }
      else {
        *(undefined1 *)(uVar5 + iVar4) = 0;
        *(undefined2 *)(iVar1 + (uint)*(byte *)(iVar1 + 6) * 2 + 0x10) = 0;
        uVar3 = *(undefined1 *)(iVar2 + (uint)*(byte *)(iVar1 + 6) * 8 + 5);
      }
    }
  }
  *(undefined2 *)(iVar1 + 2) = 0;
  *(undefined1 *)(iVar1 + 7) = 0;
  *(undefined2 *)(iVar1 + 4) = 0;
  return uVar3;
}


// ===== FUN_08010478 @ 08010478

int FUN_08010478(void)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  
  iVar3 = FUN_0800fbec();
  iVar1 = DAT_080104ac;
  if (iVar3 == 0) {
    iVar3 = FUN_08010414();
  }
  else {
    if (*(char *)(DAT_080104ac + 7) == '\0') {
      uVar2 = FUN_0800fba0();
      *(undefined1 *)(iVar1 + 6) = uVar2;
      goto LAB_08010498;
    }
    iVar3 = FUN_080103bc();
  }
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_08010498:
  iVar3 = 0;
  if (*(char *)(iVar1 + 8) != '\0') {
    iVar3 = FUN_080104b0();
  }
  return iVar3;
}


// ===== FUN_080104b0 @ 080104b0

undefined1 FUN_080104b0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = DAT_080104ec;
  uVar2 = 0;
  *(undefined1 *)(DAT_080104ec + 8) = 0;
  do {
    iVar3 = iVar1 + uVar2 * 2;
    if (*(short *)(iVar3 + 0x10) != 0) {
      *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + -1;
      *(undefined1 *)(iVar1 + 8) = 1;
      if (*(short *)(iVar3 + 0x10) == 0) {
        *(undefined1 *)(iVar1 + uVar2 + 9) = 0;
        return *(undefined1 *)(DAT_080104f0 + uVar2 * 8 + 2);
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 6);
  return 0;
}


// ===== FUN_080104f4 @ 080104f4

undefined8 FUN_080104f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 uStack_21;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_24 = (undefined1)param_2;
  local_23 = (undefined1)((uint)param_2 >> 8);
  local_22 = (undefined1)((uint)param_2 >> 0x10);
  uStack_21 = (undefined1)((uint)param_2 >> 0x18);
  local_28 = (undefined1)param_1;
  local_27 = (undefined1)((uint)param_1 >> 8);
  local_26 = (undefined1)((uint)param_1 >> 0x10);
  local_25 = (undefined1)((uint)param_1 >> 0x18);
  local_20 = param_3;
  local_1c = param_4;
  FUN_08009ba4(0x1c0000,1);
  FUN_08009ba4(DAT_080105ac,1);
  FUN_0800fc98(&local_20);
  local_20 = 8;
  local_1c = 0x1080400;
  FUN_0800fcb0(DAT_080105b0,&local_20);
  FUN_0801318c(0x40000000,param_1,param_2);
  FUN_080131b8(0x40000000,0);
  FUN_080132f8(&local_28);
  local_28 = 7;
  local_23 = 1;
  local_25 = 1;
  local_27 = 1;
  local_22 = 1;
  local_24 = 0;
  local_26 = 0;
  FUN_0801322e(0x40000000,6,&local_28);
  FUN_0801319a(0x40000000,6,param_3);
  FUN_080131fc(0x40000000,6,1);
  FUN_08013314(0x40000000,1);
  FUN_080131c2(0x40000000,1);
  FUN_0801330a(0x40000000,1);
  return CONCAT17(uStack_21,
                  CONCAT16(local_22,CONCAT15(local_23,CONCAT14(local_24,CONCAT13(local_25,CONCAT12(
                                                  local_26,CONCAT11(local_27,local_28)))))));
}


// ===== FUN_080105b4 @ 080105b4

void FUN_080105b4(int param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_08007f24(param_1,param_2,(param_3 + param_1) - 1U & 0xffff,param_2 + 1U & 0xffff,param_4);
  return;
}


// ===== FUN_080105c8 @ 080105c8

uint FUN_080105c8(char *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_08010604(param_2 + 0x1a);
  if (*param_1 == '\x03') {
    iVar2 = FUN_08010604(param_2 + 0x14);
    uVar1 = uVar1 | iVar2 << 0x10;
  }
  return uVar1;
}


// ===== FUN_080105ee @ 080105ee

undefined4 FUN_080105ee(undefined4 *param_1)

{
  return *param_1;
}


// ===== FUN_08010604 @ 08010604

undefined2 FUN_08010604(undefined2 *param_1)

{
  return *param_1;
}


// ===== FUN_08010610 @ 08010610

void FUN_08010610(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08009ba4(DAT_08010658,1);
  FUN_08009ba4(0x180000,1);
  uVar1 = DAT_0801065c;
  local_14 = 0x3101800;
  local_18 = 0x200;
  FUN_0800fcb0(DAT_0801065c,&local_18);
  local_18 = 0x200;
  FUN_0800fc90(uVar1,0x200);
  return;
}


// ===== FUN_08010660 @ 08010660

void FUN_08010660(void)

{
  int iVar1;
  char *pcVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  
  pcVar2 = DAT_080106e0;
  iVar1 = DAT_080106d8;
  if (*(char *)(DAT_080106d8 + 2) == '\x16') {
    if (*(char *)(DAT_080106d8 + 3) == '\0') {
      FUN_0800fc94(DAT_080106dc,0x200);
      *(undefined1 *)(iVar1 + 3) = 1;
      if (*pcVar2 == '\0') {
        uVar3 = 1;
        goto LAB_080106b0;
      }
    }
    else {
      FUN_0800fc90();
      *(undefined1 *)(iVar1 + 3) = 0;
      uVar3 = 0;
      if (*pcVar2 == '\0') {
LAB_080106b0:
        FUN_0800c25c(uVar3);
        return;
      }
    }
  }
  else if ((*(char *)(DAT_080106d8 + 2) == '\x15') && (*(char *)(DAT_080106d8 + 0x18) == '\x01')) {
    *(undefined1 *)(DAT_080106d8 + 5) = 1;
    if (*(char *)(iVar1 + 0x26) == '\0') {
      *(undefined1 *)(iVar1 + 0x26) = 1;
      *(undefined2 *)(iVar1 + 0x1a) = 0xf79e;
      *(undefined2 *)(iVar1 + 0x1c) = 0;
      uVar4 = 0xe73c;
    }
    else {
      *(undefined1 *)(iVar1 + 0x26) = 0;
      *(undefined2 *)(iVar1 + 0x1a) = 0;
      *(undefined2 *)(iVar1 + 0x1c) = 0xf79e;
      uVar4 = 0x3186;
    }
    *(undefined2 *)(iVar1 + 0x1e) = uVar4;
  }
  return;
}


// ===== FUN_080106e4 @ 080106e4

void FUN_080106e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  FUN_08011ac0(0x8000000,0x7000,param_3,param_4,param_4);
  FUN_08012df0();
  FUN_08011a78(3);
  FUN_0801456c();
  FUN_08009ce8();
  FUN_08013370(0x1c200);
  FUN_080080f8();
  FUN_08009468(0xf9,0x8f,0x7c);
  FUN_08010320();
  FUN_08010610();
  FUN_080079a0();
  FUN_080133e0();
  FUN_08012f20();
  FUN_08012c70();
  FUN_08013120();
  uVar1 = DAT_080107ec;
  iVar5 = FUN_0800fd5e(DAT_080107ec,0x10);
  iVar4 = DAT_080107f8;
  pcVar3 = DAT_080107f4;
  uVar2 = DAT_080107f0;
  if ((iVar5 == 0) && (iVar5 = FUN_0800fd5e(uVar1,0x80), iVar5 == 0)) {
    *pcVar3 = '\x01';
    FUN_080124c0();
    FUN_08007f24(0,0,0xf0,0x140,0);
    FUN_080104f4(9999,0x8f,(uint)((short)(*(byte *)(iVar4 + 0x23) + 1) * 9999) / 10 & 0xffff);
    FUN_0800fc90(uVar2,4);
  }
  else {
    FUN_0800df38();
    FUN_08009d18(1000);
    FUN_0800fc94(uVar2,4);
  }
  *(undefined1 *)(iVar4 + 1) = 0;
  FUN_0800c200();
  do {
    if (*(char *)(iVar4 + 1) == '\0') {
      *(undefined1 *)(iVar4 + 2) = 0;
    }
    else {
      *(char *)(iVar4 + 2) = *(char *)(iVar4 + 1);
      *(undefined1 *)(iVar4 + 1) = 0;
    }
    FUN_08010660();
    if (*pcVar3 == '\0') {
      FUN_0800c5e8();
    }
    else {
      FUN_0800a0dc();
      FUN_080124d4();
    }
    FUN_080125d4();
    if (*(char *)(iVar4 + 2) == '\x12') {
      FUN_08012aa0();
    }
    FUN_080121b8();
  } while( true );
}


// ===== FUN_080107fc @ 080107fc

uint FUN_080107fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  char *local_2c;
  
  piVar8 = *(int **)(param_1 + 100);
  uVar9 = (int)(short)(ushort)*(byte *)(param_1 + 0xe) *
          (int)(short)(ushort)*(byte *)(param_1 + 0xf);
  local_2c = *(char **)(param_1 + 0x68);
  uVar7 = 0;
  iVar3 = param_1;
  do {
    if (uVar9 + 2 <= uVar7) {
      return 0;
    }
    if (uVar7 < uVar9) {
      iVar10 = 0;
LAB_08010830:
      iVar1 = 0;
    }
    else {
      iVar10 = (uVar7 - uVar9) + 1;
      if (iVar10 == 0) goto LAB_08010830;
      iVar1 = 1;
    }
    iVar1 = param_1 + iVar1 * 8;
    uVar2 = FUN_0800fddc(param_1,*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(iVar1 + 0x34),
                         *(undefined4 *)(iVar1 + 0x44),iVar3,param_2,param_3);
    uVar5 = uVar2;
    if ((int)uVar2 < 0) {
LAB_08010900:
      return -uVar5 & 0xff;
    }
    iVar3 = param_1 + iVar10 * 2;
    iVar4 = (int)*(short *)(iVar3 + 0x14);
    if (uVar2 != 0) {
      uVar5 = FUN_0800919c(param_1,uVar2);
      if ((int)uVar5 < 0) goto LAB_08010900;
      uVar2 = 1 << (uVar2 - 1 & 0xff);
      if ((uVar5 & uVar2) == 0) {
        uVar5 = uVar5 + uVar2 * -2 + 1;
      }
      iVar4 = uVar5 + iVar4;
      *(short *)(iVar3 + 0x14) = (short)iVar4;
    }
    piVar11 = *(int **)(param_1 + (uint)*(byte *)(param_1 + iVar10 + 0x10) * 4 + 0x54);
    *piVar8 = iVar4 * *piVar11 >> 8;
    uVar5 = 1;
    do {
      piVar8[uVar5] = 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x40);
    iVar3 = *(int *)(iVar1 + 0x28);
    param_2 = *(undefined4 *)(iVar1 + 0x38);
    param_3 = *(undefined4 *)(iVar1 + 0x48);
    uVar2 = 1;
    do {
      uVar5 = FUN_0800fddc(param_1,iVar3,param_2,param_3);
      if (uVar5 == 0) break;
      if ((int)uVar5 < 0) goto LAB_08010900;
      if ((uVar5 >> 4 != 0) && (uVar2 = uVar2 + (uVar5 >> 4), 0x3f < uVar2)) {
        return 6;
      }
      uVar6 = uVar5 & 0xf;
      if (uVar6 != 0) {
        uVar5 = FUN_0800919c(param_1,uVar6);
        if ((int)uVar5 < 0) goto LAB_08010900;
        uVar6 = 1 << (uVar6 - 1 & 0xff);
        if ((uVar5 & uVar6) == 0) {
          uVar5 = uVar5 + uVar6 * -2 + 1;
        }
        piVar8[*(byte *)(DAT_08010968 + uVar2)] =
             (int)(uVar5 * piVar11[*(byte *)(DAT_08010968 + uVar2)]) >> 8;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x40);
    if (*(char *)(param_1 + 0xd) == '\x03') {
      *local_2c = (char)(*piVar8 + ((uint)(*piVar8 >> 0x1f) >> 0x18) >> 8) + -0x80;
    }
    else {
      FUN_08009218(piVar8,local_2c);
    }
    local_2c = local_2c + 0x40;
    uVar7 = uVar7 + 1;
  } while( true );
}


// ===== FUN_0801096c @ 0801096c

undefined4 FUN_0801096c(int param_1,code *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  sbyte sVar3;
  byte bVar4;
  byte bVar5;
  short sVar6;
  ushort uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  ushort *puVar17;
  byte *pbVar18;
  ushort *puVar19;
  uint uVar20;
  undefined1 *puVar21;
  ushort *puVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  bool bVar33;
  short local_44;
  short local_42;
  short local_40;
  short local_3e;
  undefined1 *local_3c;
  int iStack_34;
  code *local_30;
  uint uStack_2c;
  uint uStack_28;
  
  bVar1 = *(byte *)(param_1 + 0xe);
  uVar24 = (uint)bVar1 * 8;
  bVar2 = *(byte *)(param_1 + 0xf);
  uVar27 = (uint)bVar2 * 8;
  if (*(uint *)(param_1 + 0x1c) < param_3 + uVar24) {
    uVar25 = *(uint *)(param_1 + 0x1c) - param_3;
  }
  else {
    uVar25 = uVar24;
  }
  if (*(uint *)(param_1 + 0x20) < param_4 + uVar27) {
    uVar28 = *(uint *)(param_1 + 0x20) - param_4;
  }
  else {
    uVar28 = uVar27;
  }
  sVar3 = *(sbyte *)(param_1 + 0xd);
  uVar25 = uVar25 >> sVar3;
  bVar33 = uVar25 == 0;
  uVar28 = uVar28 >> sVar3;
  do {
    if (bVar33) goto LAB_08010c78;
    bVar33 = true;
  } while (uVar28 == 0);
  local_44 = (short)(param_3 >> sVar3);
  local_42 = local_44 + (short)uVar25 + -1;
  local_40 = (short)(param_4 >> sVar3);
  local_3e = local_40 + (short)uVar28 + -1;
  puVar9 = *(undefined1 **)(param_1 + 100);
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
        uVar20 = (uint)*pbVar18;
        iVar14 = sVar6 * 0x59b;
        *puVar9 = *(undefined1 *)
                   ((uVar20 + ((int)(iVar14 + ((uint)(iVar14 >> 0x1f) >> 0x16)) >> 10) & 0x3ff) +
                   DAT_08010c84);
        iVar14 = sVar6 * 0x2db + iVar26 * 0x160;
        puVar9[1] = *(undefined1 *)
                     ((uVar20 - ((int)(iVar14 + ((uint)(iVar14 >> 0x1f) >> 0x16)) >> 10) & 0x3ff) +
                     DAT_08010c84);
        iVar14 = (short)iVar26 * 0x716;
        puVar9[2] = *(undefined1 *)
                     ((uVar20 + ((int)(iVar14 + ((uint)(iVar14 >> 0x1f) >> 0x16)) >> 10) & 0x3ff) +
                     DAT_08010c84);
        pbVar18 = pbVar18 + 0x40;
        puVar9 = puVar9 + 3;
      }
    }
  }
  else {
    for (uVar10 = 0; uVar10 < uVar27; uVar10 = uVar10 + 1) {
      iVar26 = *(int *)(param_1 + 0x68);
      pbVar18 = (byte *)(iVar26 + uVar10 * 8);
      if (bVar2 == 2) {
        pbVar13 = (byte *)(iVar26 + (uVar10 >> 1) * 8 + 0x100);
        if (7 < uVar10) {
          pbVar18 = pbVar18 + 0x40;
        }
      }
      else {
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
        }
        else {
          pbVar13 = pbVar13 + 1;
        }
        uVar20 = (uint)*pbVar18;
        iVar26 = (short)(bVar5 - 0x80) * 0x59b;
        *puVar9 = *(undefined1 *)
                   ((uVar20 + ((int)(iVar26 + ((uint)(iVar26 >> 0x1f) >> 0x16)) >> 10) & 0x3ff) +
                   DAT_08010c84);
        iVar26 = (short)(bVar5 - 0x80) * 0x2db + (bVar4 - 0x80) * 0x160;
        puVar9[1] = *(undefined1 *)
                     ((uVar20 - ((int)(iVar26 + ((uint)(iVar26 >> 0x1f) >> 0x16)) >> 10) & 0x3ff) +
                     DAT_08010c84);
        iVar26 = (short)(bVar4 - 0x80) * 0x716;
        puVar9[2] = *(undefined1 *)
                     ((uVar20 + ((int)(iVar26 + ((uint)(iVar26 >> 0x1f) >> 0x16)) >> 10) & 0x3ff) +
                     DAT_08010c84);
        puVar9 = puVar9 + 3;
        pbVar18 = pbVar18 + 1;
      }
    }
    uVar10 = (uint)*(byte *)(param_1 + 0xd);
    if (uVar10 != 0) {
      uVar20 = uVar10 << 1;
      uVar10 = 1 << uVar10;
      local_3c = *(undefined1 **)(param_1 + 100);
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
    puVar15 = *(undefined1 **)(param_1 + 100);
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
  puVar17 = *(ushort **)(param_1 + 100);
  iVar26 = uVar28 * uVar25;
  puVar22 = puVar17;
  do {
    pbVar18 = (byte *)((int)puVar17 + 1);
    uVar7 = *puVar17;
    puVar19 = puVar17 + 1;
    puVar17 = (ushort *)((int)puVar17 + 3);
    iVar26 = iVar26 + -1;
    *puVar22 = ((byte)uVar7 & 0xf8) << 8 | (*pbVar18 & 0xfc) << 3 |
               (ushort)(byte)((byte)*puVar19 >> 3);
    puVar22 = puVar22 + 1;
  } while (iVar26 != 0);
  iStack_34 = param_1;
  local_30 = param_2;
  uStack_2c = param_3;
  uStack_28 = param_4;
  iVar26 = (*param_2)(param_1,*(undefined4 *)(param_1 + 100),&local_44);
  if (iVar26 == 0) {
    uVar8 = 1;
  }
  else {
LAB_08010c78:
    uVar8 = 0;
  }
  return uVar8;
}


// ===== FUN_08010c88 @ 08010c88

void FUN_08010c88(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined2 uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  bool bVar15;
  char cVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined2 uVar19;
  undefined1 auStack_54 [12];
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  
  iVar3 = DAT_08011098;
  iVar2 = DAT_08011094;
  uVar14 = *(undefined4 *)(DAT_08011094 + 0x20);
  uVar9 = *(undefined4 *)(DAT_08011094 + 0x24);
  uVar10 = *(undefined4 *)(DAT_08011094 + 8);
  cVar16 = 0xb < param_1;
  uVar17 = 0;
  uVar18 = 0;
  switch(param_1) {
  case 0:
  case 1:
  case 4:
  case 10:
  case 0xb:
    cVar16 = 9 < param_1;
    if (param_1 == 10) {
      uVar5 = 6;
    }
    else {
      uVar5 = 3;
    }
    *(undefined1 *)(DAT_08011094 + 0x28) = uVar5;
    *(undefined1 *)(iVar2 + 0x29) = uVar5;
    uVar17 = FUN_08015548(uVar10);
    FUN_0801507c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar14,uVar9);
    if (cVar16 == '\0') {
      uVar17 = FUN_08015548(*(undefined4 *)(iVar2 + 8));
      *(undefined8 *)(iVar2 + 0x20) = uVar17;
    }
    uVar17 = FUN_08015548(*(undefined4 *)(iVar2 + 8));
    FUN_080152f0((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),*(undefined4 *)(iVar2 + 0x18),
                 *(undefined4 *)(iVar2 + 0x1c));
    uVar17 = 0;
    uVar18 = 0;
    if (cVar16 == '\0') {
      uVar17 = FUN_08015548(*(undefined4 *)(iVar2 + 8));
      *(undefined8 *)(iVar2 + 0x18) = uVar17;
      uVar17 = 0;
      uVar18 = 0;
    }
    break;
  case 2:
  case 5:
  case 6:
    bVar1 = *(byte *)(DAT_08011094 + 0xd);
    if (bVar1 < *(byte *)(DAT_08011094 + 0x28)) {
      *(byte *)(DAT_08011094 + 0x28) = bVar1;
    }
    if (*(byte *)(iVar2 + 0x29) < bVar1) {
      *(byte *)(iVar2 + 0x29) = bVar1;
    }
    uVar13 = DAT_0801109c;
    cVar16 = 7 < bVar1;
    if (((bVar1 == 8) || (cVar16 = 10 < bVar1, bVar1 == 0xb)) ||
       (cVar16 = 0xd < bVar1, bVar1 == 0xe)) {
      uVar6 = DAT_080110a0;
LAB_08010dd0:
      uVar10 = FUN_080158c4(uVar10,uVar6);
    }
    else {
      cVar16 = 8 < bVar1;
      if (((bVar1 == 9) || (cVar16 = 0xb < bVar1, bVar1 == 0xc)) ||
         (cVar16 = 0xe < bVar1, bVar1 == 0xf)) {
        uVar6 = DAT_080110a4;
        goto LAB_08010dd0;
      }
    }
    uVar17 = FUN_08015548(uVar10);
    uVar10 = (undefined4)((ulonglong)uVar17 >> 0x20);
    FUN_0801507c((int)uVar17,uVar10,uVar14,uVar9);
    if (cVar16 == '\0') {
      *(undefined8 *)(iVar2 + 0x20) = uVar17;
    }
    FUN_080152f0((int)uVar17,uVar10,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c));
    if (cVar16 == '\0') {
      *(undefined8 *)(iVar2 + 0x18) = uVar17;
    }
    bVar15 = true;
    FUN_080152f0(*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24),0,uVar13);
    uVar10 = DAT_080110a8;
    if ((bool)cVar16 && !bVar15) {
      FUN_080152f0(*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24),0,DAT_080110a8);
      if (!(bool)cVar16 || bVar15) goto LAB_08010dea;
      uVar17 = *(undefined8 *)(iVar2 + 0x20);
    }
    else {
      uVar10 = uVar13;
LAB_08010dea:
      uVar17 = FUN_08014d1c(*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24),0,uVar10);
    }
    bVar15 = true;
    FUN_080152f0(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),0,uVar13);
    uVar10 = DAT_080110a8;
    if ((bool)cVar16 && !bVar15) {
      bVar15 = true;
      FUN_080152f0(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),0,DAT_080110a8);
      uVar13 = uVar10;
      if ((bool)cVar16 && !bVar15) {
        uVar18 = *(undefined8 *)(iVar2 + 0x18);
        break;
      }
    }
    uVar18 = FUN_08014d1c(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),0,uVar13);
    break;
  case 3:
    *(undefined1 *)(DAT_08011094 + 0x28) = 7;
    *(undefined1 *)(iVar2 + 0x29) = 7;
    uVar17 = FUN_08015548(uVar10);
    FUN_0801507c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar14,uVar9);
    if (cVar16 == '\0') {
      uVar17 = FUN_08015548(*(undefined4 *)(iVar2 + 8));
      *(undefined8 *)(iVar2 + 0x20) = uVar17;
    }
    uVar17 = FUN_08015548(*(undefined4 *)(iVar2 + 8));
    FUN_080152f0((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),*(undefined4 *)(iVar2 + 0x18),
                 *(undefined4 *)(iVar2 + 0x1c));
    uVar18 = 0;
    if (cVar16 == '\0') {
      uVar17 = FUN_08015548(*(undefined4 *)(iVar2 + 8));
      *(undefined8 *)(iVar2 + 0x18) = uVar17;
      uVar18 = 0;
    }
    goto LAB_08010e82;
  case 7:
    *(undefined1 *)(DAT_08011094 + 0x28) = 0x10;
    *(undefined1 *)(iVar2 + 0x29) = 0x10;
    cVar16 = '\x01';
    if (*(char *)(iVar3 + 0x21) != '\0') {
      FUN_08009534(uVar10);
    }
    uVar17 = FUN_08015548();
    uVar10 = (undefined4)((ulonglong)uVar17 >> 0x20);
    FUN_0801507c((int)uVar17,uVar10,*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24));
    if (cVar16 == '\0') {
      *(undefined8 *)(iVar2 + 0x20) = uVar17;
    }
    FUN_080152f0((int)uVar17,uVar10,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c));
    uVar18 = 0;
    if (cVar16 == '\0') {
      *(undefined8 *)(iVar2 + 0x18) = uVar17;
      uVar18 = 0;
    }
    goto LAB_08010e82;
  }
  cVar16 = 1 < param_1;
  if (param_1 != 2) {
    cVar16 = 9 < param_1;
    if (param_1 == 10) {
      uVar17 = FUN_08015548(*(undefined4 *)(iVar3 + 0x14));
      uVar17 = FUN_08014ba4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),
                            *(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24));
    }
    else {
LAB_08010e82:
      uVar17 = *(undefined8 *)(iVar2 + 0x20);
    }
  }
  uVar12 = (uint)((ulonglong)uVar17 >> 0x20);
  uVar10 = (undefined4)uVar17;
  FUN_0801507c(uVar10,uVar12,0,0);
  if (cVar16 == '\0') {
    uVar12 = uVar12 ^ 0x80000000;
  }
  cVar16 = 6 < param_1;
  if (param_1 == 7) {
    FUN_0801507c(uVar10,uVar12,0,DAT_080110ac);
    if ((cVar16 != '\0') && (FUN_0801507c(uVar10,uVar12,0,DAT_080110b8), cVar16 != '\0')) {
      FUN_0801507c(uVar10,uVar12,0,DAT_080110a8);
    }
    FUN_08014af4(auStack_54,s__04_0f_080110bc,uVar10,uVar12);
LAB_08010f44:
    uVar18 = *(undefined8 *)(iVar2 + 0x18);
  }
  else {
    FUN_0801507c(uVar10,uVar12,0,DAT_080110ac);
    if (cVar16 == '\0') {
      pcVar7 = s__0_3f_080110b0;
    }
    else {
      FUN_0801507c(uVar10,uVar12,0,DAT_080110b8);
      if (cVar16 == '\0') {
        pcVar7 = s__0_2f_080110c4;
      }
      else {
        FUN_0801507c(uVar10,uVar12,0,DAT_080110a8);
        if (cVar16 == '\0') {
          pcVar7 = s__0_1f_080110cc;
        }
        else {
          pcVar7 = s__0_0f_080110d4;
        }
      }
    }
    FUN_08014af4(auStack_54,pcVar7,uVar10,uVar12);
    cVar16 = 1 < param_1;
    if (((param_1 != 2) && (cVar16 = 4 < param_1, param_1 != 5)) &&
       (cVar16 = 5 < param_1, param_1 != 6)) {
      cVar16 = 9 < param_1;
      if (param_1 != 10) goto LAB_08010f44;
      uVar17 = FUN_08015548(*(undefined4 *)(iVar3 + 0x14));
      uVar18 = FUN_08014ba4((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),
                            *(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c));
    }
  }
  uVar12 = (uint)((ulonglong)uVar18 >> 0x20);
  uVar10 = (undefined4)uVar18;
  FUN_0801507c(uVar10,uVar12,0,0);
  iVar4 = DAT_080110dc;
  if (cVar16 == '\0') {
    uVar12 = uVar12 ^ 0x80000000;
  }
  cVar16 = 6 < param_1;
  if (param_1 == 7) {
    FUN_0801507c(uVar10,uVar12,0,DAT_080110ac);
    if ((cVar16 != '\0') && (FUN_0801507c(uVar10,uVar12,0,DAT_080110b8), cVar16 != '\0')) {
      FUN_0801507c(uVar10,uVar12,0,DAT_080110a8);
    }
    FUN_08014af4(auStack_48,s__04_0f_080110bc,uVar10,uVar12);
LAB_080114ca:
    FUN_0801507c(*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24),0,0);
    if (cVar16 == '\0') {
      puVar8 = &DAT_080110e0;
    }
    else {
      puVar8 = &DAT_080110e4;
    }
    FUN_08014af4(auStack_3c,puVar8,auStack_54);
    if (*(char *)(iVar4 + 2) == '\0') {
      FUN_0800dbe4(0x14,0xe8,auStack_3c,*(undefined2 *)(iVar3 + 0x1c),*(undefined2 *)(iVar3 + 0x1e))
      ;
    }
    else {
      FUN_0800da1c(4,0xed,auStack_3c);
    }
    FUN_0801507c(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),0,0);
    if (cVar16 == '\0') {
      puVar8 = &DAT_080110e0;
    }
    else {
      puVar8 = &DAT_080110e4;
    }
    FUN_08014af4(auStack_30,puVar8,auStack_48);
    if (*(char *)(iVar4 + 2) == '\0') {
      FUN_0800dbe4(0x8b,0xe8,auStack_30,*(undefined2 *)(iVar3 + 0x1c),*(undefined2 *)(iVar3 + 0x1e))
      ;
    }
    else {
      FUN_0800da1c(0x51,0xed,auStack_30);
    }
    if (*(char *)(iVar4 + 2) == '\0') {
      if (*(char *)(iVar3 + 0x21) == '\0') {
        FUN_080082f2(0x53,0xea,&DAT_08011614,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e),0xc,0);
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_08011614;
      }
      else {
        FUN_080082f2(0x53,0xea,&DAT_08011610,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e),0xc,0);
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_08011610;
      }
      goto LAB_080115da;
    }
    if (*(char *)(iVar3 + 0x21) == '\0') {
      FUN_080082f2(0x38,0xef,&DAT_08011614,*(undefined2 *)(iVar3 + 0x1c),
                   *(undefined2 *)(iVar3 + 0x1a),0xc,0);
      uVar19 = *(undefined2 *)(iVar3 + 0x1a);
      uVar11 = *(undefined2 *)(iVar3 + 0x1c);
      puVar8 = &DAT_08011614;
    }
    else {
      FUN_080082f2(0x38,0xef,&DAT_08011610,*(undefined2 *)(iVar3 + 0x1c),
                   *(undefined2 *)(iVar3 + 0x1a),0xc,0);
      uVar19 = *(undefined2 *)(iVar3 + 0x1a);
      uVar11 = *(undefined2 *)(iVar3 + 0x1c);
      puVar8 = &DAT_08011610;
    }
LAB_0801159e:
    uVar9 = 0xef;
    uVar10 = 0x85;
  }
  else {
    FUN_0801507c(uVar10,uVar12,0,DAT_080110ac);
    if (cVar16 == '\0') {
      pcVar7 = s__0_3f_080110b0;
    }
    else {
      FUN_0801507c(uVar10,uVar12,0,DAT_080110b8);
      if (cVar16 == '\0') {
        pcVar7 = s__0_2f_080110c4;
      }
      else {
        FUN_0801507c(uVar10,uVar12,0,DAT_080110a8);
        if (cVar16 == '\0') {
          pcVar7 = s__0_1f_080110cc;
        }
        else {
          pcVar7 = s__0_0f_080110d4;
        }
      }
    }
    FUN_08014af4(auStack_48,pcVar7,uVar10,uVar12);
    cVar16 = 0xb < param_1;
    switch(param_1) {
    case 0:
    case 1:
    case 4:
    case 10:
    case 0xb:
      FUN_0801507c(*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24),0,0);
      if (cVar16 == '\0') {
        puVar8 = &DAT_080110e0;
      }
      else {
        puVar8 = &DAT_080110e4;
      }
      FUN_08014af4(auStack_3c,puVar8,auStack_54);
      if (*(char *)(iVar4 + 2) == '\0') {
        FUN_0800dbe4(0x14,0xe8,auStack_3c,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e));
      }
      else {
        FUN_0800da1c(4,0xed,auStack_3c);
      }
      FUN_0801507c(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),0,0);
      if (cVar16 == '\0') {
        puVar8 = &DAT_080110e0;
      }
      else {
        puVar8 = &DAT_080110e4;
      }
      FUN_08014af4(auStack_30,puVar8,auStack_48);
      if (*(char *)(iVar4 + 2) == '\0') {
        FUN_0800dbe4(0x8b,0xe8,auStack_30,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e));
      }
      else {
        FUN_0800da1c(0x51,0xed,auStack_30);
      }
      if ((param_1 == 10) || (param_1 == 0xb)) {
        if (*(char *)(iVar4 + 2) != '\0') {
          FUN_080082f2(0x38,0xef,&DAT_080114e4,*(undefined2 *)(iVar3 + 0x1c),
                       *(undefined2 *)(iVar3 + 0x1a),0xc,0);
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114e4;
          goto LAB_0801159e;
        }
        FUN_080082f2(0x53,0xea,&DAT_080114e4,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e),0xc,0);
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_080114e4;
      }
      else {
        if (*(char *)(iVar4 + 2) != '\0') {
          FUN_080082f2(0x38,0xef,&DAT_080114e0,*(undefined2 *)(iVar3 + 0x1c),
                       *(undefined2 *)(iVar3 + 0x1a),0xc,0);
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114e0;
          goto LAB_0801159e;
        }
        FUN_080082f2(0x53,0xea,&DAT_080114e0,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e),0xc,0);
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_080114e0;
      }
      break;
    case 2:
    case 3:
    case 5:
    case 6:
      FUN_08014af4(auStack_3c,&DAT_080110e4,auStack_54);
      FUN_08014af4(auStack_30,&DAT_080110e4,auStack_48);
      if (*(char *)(iVar4 + 2) == '\0') {
        FUN_0800dbe4(0x14,0xe8,auStack_3c,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e));
        FUN_0800dbe4(0x8b,0xe8,auStack_30,*(undefined2 *)(iVar3 + 0x1c),
                     *(undefined2 *)(iVar3 + 0x1e));
      }
      else {
        FUN_0800da1c(4,0xed,auStack_3c);
        FUN_0800da1c(0x51,0xed,auStack_30);
      }
      cVar16 = *(char *)(iVar2 + 0x28);
      if (cVar16 == '\a') {
        if (*(char *)(iVar4 + 2) != '\0') {
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114e8;
          goto LAB_0801122a;
        }
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_080114e8;
LAB_0801123c:
        uVar9 = 0xea;
        uVar10 = 0x53;
LAB_08011240:
        FUN_080082f2(uVar10,uVar9,puVar8,uVar11,uVar19,0xc,0);
      }
      else {
        if (cVar16 == '\b') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114ec;
            goto LAB_0801123c;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114ec;
LAB_0801122a:
          uVar9 = 0xef;
          uVar10 = 0x38;
          goto LAB_08011240;
        }
        if (cVar16 == '\t') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114f0;
            goto LAB_0801123c;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114f0;
          goto LAB_0801122a;
        }
      }
      cVar16 = *(char *)(iVar2 + 0x29);
      if (cVar16 == '\a') {
        if (*(char *)(iVar4 + 2) != '\0') {
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114e8;
          goto LAB_080112a6;
        }
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_080114e8;
LAB_080112b8:
        uVar9 = 0xea;
        uVar10 = 0xca;
LAB_080112bc:
        FUN_080082f2(uVar10,uVar9,puVar8,uVar11,uVar19,0xc,0);
      }
      else {
        if (cVar16 == '\b') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114ec;
            goto LAB_080112b8;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114ec;
LAB_080112a6:
          uVar9 = 0xef;
          uVar10 = 0x85;
          goto LAB_080112bc;
        }
        if (cVar16 == '\t') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114f0;
            goto LAB_080112b8;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114f0;
          goto LAB_080112a6;
        }
      }
      cVar16 = *(char *)(iVar2 + 0x28);
      if (cVar16 == '\n') {
        if (*(char *)(iVar4 + 2) != '\0') {
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114f4;
          goto LAB_08011322;
        }
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_080114f4;
LAB_08011334:
        uVar9 = 0xea;
        uVar10 = 0x53;
LAB_08011338:
        FUN_080082f2(uVar10,uVar9,puVar8,uVar11,uVar19,0xc,0);
      }
      else {
        if (cVar16 == '\v') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114f8;
            goto LAB_08011334;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114f8;
LAB_08011322:
          uVar9 = 0xef;
          uVar10 = 0x38;
          goto LAB_08011338;
        }
        if (cVar16 == '\f') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114fc;
            goto LAB_08011334;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114fc;
          goto LAB_08011322;
        }
      }
      cVar16 = *(char *)(iVar2 + 0x29);
      if (cVar16 == '\n') {
        if (*(char *)(iVar4 + 2) != '\0') {
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114f4;
          goto LAB_080113a0;
        }
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_080114f4;
LAB_080113b2:
        uVar9 = 0xea;
        uVar10 = 0xca;
LAB_080113b6:
        FUN_080082f2(uVar10,uVar9,puVar8,uVar11,uVar19,0xc,0);
      }
      else {
        if (cVar16 == '\v') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114f8;
            goto LAB_080113b2;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114f8;
LAB_080113a0:
          uVar9 = 0xef;
          uVar10 = 0x85;
          goto LAB_080113b6;
        }
        if (cVar16 == '\f') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_080114fc;
            goto LAB_080113b2;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_080114fc;
          goto LAB_080113a0;
        }
      }
      cVar16 = *(char *)(iVar2 + 0x28);
      if (cVar16 == '\r') {
        if (*(char *)(iVar4 + 2) != '\0') {
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_08011500;
          goto LAB_0801141c;
        }
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_08011500;
LAB_0801142e:
        uVar9 = 0xea;
        uVar10 = 0x53;
LAB_08011432:
        FUN_080082f2(uVar10,uVar9,puVar8,uVar11,uVar19,0xc,0);
      }
      else {
        if (cVar16 == '\x0e') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_08011504;
            goto LAB_0801142e;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_08011504;
LAB_0801141c:
          uVar9 = 0xef;
          uVar10 = 0x38;
          goto LAB_08011432;
        }
        if (cVar16 == '\x0f') {
          if (*(char *)(iVar4 + 2) == '\0') {
            uVar19 = *(undefined2 *)(iVar3 + 0x1e);
            uVar11 = *(undefined2 *)(iVar3 + 0x1c);
            puVar8 = &DAT_08011508;
            goto LAB_0801142e;
          }
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = &DAT_08011508;
          goto LAB_0801141c;
        }
      }
      cVar16 = *(char *)(iVar2 + 0x29);
      if (cVar16 == '\r') {
        if (*(char *)(iVar4 + 2) != '\0') {
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = (undefined *)0x801150c;
          goto LAB_0801159e;
        }
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = (undefined *)0x801150c;
        break;
      }
      if (cVar16 == '\x0e') {
        if (*(char *)(iVar4 + 2) != '\0') {
          uVar19 = *(undefined2 *)(iVar3 + 0x1a);
          uVar11 = *(undefined2 *)(iVar3 + 0x1c);
          puVar8 = (undefined *)0x8011510;
          goto LAB_0801159e;
        }
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = (undefined *)0x8011510;
        break;
      }
      if (cVar16 != '\x0f') {
        return;
      }
      if (*(char *)(iVar4 + 2) == '\0') {
        uVar19 = *(undefined2 *)(iVar3 + 0x1e);
        uVar11 = *(undefined2 *)(iVar3 + 0x1c);
        puVar8 = &DAT_08011508;
        break;
      }
      uVar19 = *(undefined2 *)(iVar3 + 0x1a);
      uVar11 = *(undefined2 *)(iVar3 + 0x1c);
      puVar8 = &DAT_08011508;
      goto LAB_0801159e;
    case 7:
      cVar16 = '\0';
      goto LAB_080114ca;
    default:
      goto switchD_08011000_caseD_8;
    }
LAB_080115da:
    uVar9 = 0xea;
    uVar10 = 0xca;
  }
  FUN_080082f2(uVar10,uVar9,puVar8,uVar11,uVar19,0xc,0);
switchD_08011000_caseD_8:
  return;
}


// ===== FUN_08011618 @ 08011618

void FUN_08011618(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined1 auStack_1c [8];
  
  iVar1 = DAT_08011694;
  switch(param_1) {
  case 3:
    puVar2 = &DAT_08011698;
    break;
  default:
    goto switchD_0801162a_caseD_4;
  case 6:
    puVar2 = &DAT_0801169c;
    break;
  case 7:
    puVar2 = &DAT_080116a8;
    break;
  case 8:
    puVar2 = &DAT_080116a4;
    break;
  case 9:
    puVar2 = &DAT_080116a0;
    break;
  case 10:
    puVar2 = &DAT_080116b0;
    break;
  case 0xb:
    puVar2 = &DAT_080116ac;
    break;
  case 0xc:
    puVar2 = &DAT_080116b4;
    break;
  case 0xd:
    puVar2 = &DAT_080116c0;
    break;
  case 0xe:
    puVar2 = &DAT_080116bc;
    break;
  case 0xf:
    puVar2 = &DAT_080116b8;
    break;
  case 0x10:
    if (*(char *)(DAT_08011694 + 0x21) == '\0') {
      puVar2 = &DAT_080116c8;
    }
    else {
      puVar2 = &DAT_080116c4;
    }
  }
  FUN_08014af4(auStack_1c,puVar2);
switchD_0801162a_caseD_4:
  FUN_080082f2(param_3,param_4,auStack_1c,param_2,*(undefined2 *)(iVar1 + 0x1a),0xc,0);
  return;
}


// ===== FUN_080116cc @ 080116cc

undefined4 FUN_080116cc(int param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  short *psVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  char cVar11;
  uint uVar12;
  int iVar13;
  int local_28;
  undefined4 *puStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  
  *param_2 = 0;
  local_28 = param_1;
  puStack_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  iVar5 = FUN_0800fc58();
  if (iVar5 < 0) {
    return 0xb;
  }
  pcVar10 = *(char **)(DAT_08011908 + iVar5 * 4);
  if (pcVar10 == (char *)0x0) {
    return 0xc;
  }
  *param_2 = pcVar10;
  if ((*pcVar10 == '\0') || (uVar6 = FUN_0800a088(pcVar10[1]), (uVar6 & 1) != 0)) {
    *pcVar10 = '\0';
    pcVar10[1] = (char)iVar5;
    uVar6 = FUN_08009ff2();
    if ((uVar6 & 1) != 0) {
      return 3;
    }
    if (((param_3 & 0xfe) != 0) && ((int)(uVar6 << 0x1d) < 0)) {
      return 10;
    }
    uVar6 = FUN_08009560(pcVar10,0);
    if (uVar6 == 2) {
      uVar6 = 0;
      do {
        iVar5 = FUN_080105ee(pcVar10 + uVar6 * 0x10 + 0x1f6);
        (&local_28)[uVar6] = iVar5;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      uVar12 = 0;
      do {
        if ((&local_28)[uVar12] == 0) {
          uVar6 = 3;
        }
        else {
          uVar6 = FUN_08009560(pcVar10);
          if (uVar6 < 2) break;
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < 4);
    }
    if (uVar6 == 4) {
      return 1;
    }
    if (uVar6 < 2) {
      iVar13 = *(int *)(pcVar10 + 0x2c);
      iVar5 = FUN_08010604(pcVar10 + 0x3b);
      if (iVar5 == 0x1000) {
        iVar5 = FUN_08010604(pcVar10 + 0x46);
        if (iVar5 == 0) {
          iVar5 = FUN_080105ee(pcVar10 + 0x54);
        }
        *(int *)(pcVar10 + 0x18) = iVar5;
        uVar6 = (uint)(byte)pcVar10[0x40];
        pcVar10[2] = pcVar10[0x40];
        if ((uVar6 == 1) || (uVar6 == 2)) {
          bVar1 = pcVar10[0x3d];
          *(ushort *)(pcVar10 + 10) = (ushort)bVar1;
          if ((bVar1 != 0) && ((bVar1 & bVar1 - 1) == 0)) {
            uVar3 = FUN_08010604(pcVar10 + 0x41);
            *(ushort *)(pcVar10 + 8) = uVar3;
            if ((uVar3 & 0x7f) == 0) {
              uVar12 = FUN_08010604(pcVar10 + 0x43);
              if (uVar12 == 0) {
                uVar12 = FUN_080105ee(pcVar10 + 0x50);
              }
              iVar7 = FUN_08010604(pcVar10 + 0x3e);
              if (iVar7 != 0) {
                uVar9 = iVar7 + iVar5 * uVar6 + (uint)(*(ushort *)(pcVar10 + 8) >> 7);
                if ((uVar9 <= uVar12) &&
                   (uVar12 = (uVar12 - uVar9) / (uint)*(ushort *)(pcVar10 + 10), uVar12 != 0)) {
                  cVar11 = '\0';
                  if (uVar12 <= DAT_0801190c) {
                    cVar11 = '\x03';
                  }
                  if (uVar12 < 0xfff6) {
                    cVar11 = '\x02';
                  }
                  if (uVar12 < 0xff6) {
                    cVar11 = '\x01';
                  }
                  else if (cVar11 == '\0') goto LAB_08011864;
                  uVar12 = uVar12 + 2;
                  *(uint *)(pcVar10 + 0x28) = uVar9 + iVar13;
                  *(uint *)(pcVar10 + 0x14) = uVar12;
                  *(int *)(pcVar10 + 0x1c) = iVar13;
                  *(int *)(pcVar10 + 0x20) = iVar7 + iVar13;
                  if (cVar11 == '\x03') {
                    iVar5 = FUN_08010604(pcVar10 + 0x5a);
                    if ((iVar5 == 0) && (*(short *)(pcVar10 + 8) == 0)) {
                      uVar8 = FUN_080105ee(pcVar10 + 0x5c);
                      *(undefined4 *)(pcVar10 + 0x24) = uVar8;
                      iVar5 = *(int *)(pcVar10 + 0x14) << 2;
                      goto LAB_08011858;
                    }
                  }
                  else if (*(ushort *)(pcVar10 + 8) != 0) {
                    *(uint *)(pcVar10 + 0x24) = iVar7 + iVar13 + iVar5 * uVar6;
                    if (cVar11 == '\x02') {
                      iVar5 = uVar12 * 2;
                    }
                    else {
                      iVar5 = (uVar12 & 1) + (uVar12 * 3 >> 1);
                    }
LAB_08011858:
                    if (iVar5 + 0xfffU >> 0xc <= *(uint *)(pcVar10 + 0x18)) {
                      pcVar10[0x10] = -1;
                      pcVar10[0x11] = -1;
                      pcVar10[0x12] = -1;
                      pcVar10[0x13] = -1;
                      pcVar10[0xc] = -1;
                      pcVar10[0xd] = -1;
                      pcVar10[0xe] = -1;
                      pcVar10[0xf] = -1;
                      pcVar10[4] = -0x80;
                      if (((cVar11 == '\x03') && (iVar5 = FUN_08010604(pcVar10 + 0x60), iVar5 == 1))
                         && (iVar5 = FUN_0801191c(pcVar10,iVar13 + 1), iVar5 == 0)) {
                        pcVar10[4] = '\0';
                        iVar5 = FUN_08010604(pcVar10 + 0x22e);
                        if (((iVar5 == 0xaa55) &&
                            (iVar5 = FUN_080105ee(pcVar10 + 0x30), iVar5 == DAT_08011910)) &&
                           (iVar5 = FUN_080105ee(pcVar10 + 0x214), iVar5 == DAT_08011914)) {
                          uVar8 = FUN_080105ee(pcVar10 + 0x218);
                          *(undefined4 *)(pcVar10 + 0x10) = uVar8;
                          uVar8 = FUN_080105ee(pcVar10 + 0x21c);
                          *(undefined4 *)(pcVar10 + 0xc) = uVar8;
                        }
                      }
                      psVar2 = DAT_08011918;
                      *pcVar10 = cVar11;
                      sVar4 = *psVar2 + 1;
                      *psVar2 = sVar4;
                      *(short *)(pcVar10 + 6) = sVar4;
                      goto LAB_08011722;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_08011864:
    uVar8 = 0xd;
  }
  else {
    if (((param_3 & 0xfe) != 0) && ((int)(uVar6 << 0x1d) < 0)) {
      return 10;
    }
LAB_08011722:
    uVar8 = 0;
  }
  return uVar8;
}


// ===== FUN_0801191c @ 0801191c

int FUN_0801191c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((*(int *)(param_1 + 0x2c) != param_2) && (iVar2 = FUN_08012da8(param_1), iVar2 == 0)) {
    iVar1 = FUN_0800a048(*(undefined1 *)(param_1 + 1),param_1 + 0x30,param_2,1);
    if (iVar1 != 0) {
      param_2 = -1;
      iVar2 = 1;
    }
    *(int *)(param_1 + 0x2c) = param_2;
  }
  return iVar2;
}


// ===== FUN_0801194e @ 0801194e

undefined4 FUN_0801194e(uint param_1)

{
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
  if (param_1 == 0xe5) {
    return 0x45;
  }
  if (param_1 == 4) {
    return 0x2d;
  }
  if (param_1 == 0) {
    return 0x20;
  }
  if (param_1 == 0xe1) {
    return 0x43;
  }
  if (param_1 == 0xec) {
    return 0x50;
  }
  if (param_1 == 0x24) {
    return 0x52;
  }
  return 0xff;
}


// ===== FUN_080119fc @ 080119fc

void FUN_080119fc(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*DAT_08011a74 & 0x7ff) >> 8;
  uVar2 = 7 - uVar1;
  if (4 < uVar2) {
    uVar2 = 4;
  }
  if (uVar1 + 4 < 7) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 - 3;
  }
  uVar1 = ((1 << (uVar2 & 0xff)) - 1U & param_2) << (uVar1 & 0xff) |
          (1 << (uVar1 & 0xff)) - 1U & param_3;
  if ((int)param_1 < 0) {
    (&DAT_e000ed14)[param_1 & 0xf] = (char)(uVar1 << 4);
  }
  else {
    (&DAT_e000e400)[param_1] = (char)(uVar1 << 4);
    *(int *)(&DAT_e000e100 + (param_1 >> 5) * 4) = 1 << (param_1 & 0x1f);
  }
  return;
}


// ===== FUN_08011a78 @ 08011a78

void FUN_08011a78(uint param_1)

{
  *DAT_08011a94 = *DAT_08011a94 & 0xf8ff | (param_1 & 7) << 8 | DAT_08011a98;
  return;
}


// ===== FUN_08011ac0 @ 08011ac0

void FUN_08011ac0(uint param_1,uint param_2)

{
  *DAT_08011ad0 = param_2 & DAT_08011acc | param_1;
  return;
}


// ===== FUN_08011ad4 @ 08011ad4

void FUN_08011ad4(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  
  iVar1 = DAT_08011da4;
  uVar7 = 0;
  if (param_1 == 1) {
    do {
      FUN_08007e88(uVar7 * 0x3d + 8,8,uVar7 * 0x3d + 0x33,0x33,5,*(undefined2 *)(iVar1 + 0x1c));
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 4);
    FUN_08007c6c(DAT_08011da8,0xe,0xe,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
    FUN_08007c6c(DAT_08011dac,0x4a,0xc,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
    FUN_08007c6c(DAT_08011db0,0x87,0xd,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
    FUN_08007c6c(DAT_08011db4,0xc5,0xe,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0);
  }
  if (param_2 != 0) {
    if (*(char *)(iVar1 + 0x26) == '\0') {
      pcVar2 = s_2__UI_decorate_menu_jpg_08011dd0;
    }
    else {
      pcVar2 = s_2__UI_decorat_menu_jpg_08011db8;
    }
    FUN_08010274(pcVar2,5,0x41);
    if (param_2 == 1) {
      FUN_08007e88(8,8,0x33,0x33,5,0xfc60);
      FUN_08007f24(0xf,0x68,0xe6,0x8c,*(undefined2 *)(iVar1 + 0x1a));
      if (*(char *)(iVar1 + 0x20) == '\0') {
        FUN_080082f2(0x12,0x45,&DAT_08011e0c,0xf79e,0xf79e,0x18,1);
        FUN_080082f2(0x30,0x69,&DAT_08011e18,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x18,1);
        uVar4 = 0x18;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        pcVar2 = &DAT_08011e20;
        uVar3 = 0x8e;
      }
      else {
        FUN_080082f2(0xc,0x48,s_History_record_08011de8,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1)
        ;
        FUN_080082f2(0x34,0x69,&DAT_08011df8,*(undefined2 *)(iVar1 + 0x1c),0xf79e,0x10,1);
        uVar4 = 0x10;
        uVar6 = *(undefined2 *)(iVar1 + 0x1c);
        pcVar2 = s_Measurement_08011e00;
        uVar3 = 0x8c;
      }
      FUN_080082f2(uVar3,0x69,pcVar2,uVar6,0xf79e,uVar4,1);
      FUN_0800b1d4(1);
    }
    else {
      if (param_2 == 2) {
        FUN_08007e88(0x45,8,0x70,0x33,5,0xfc60);
        if (*(char *)(iVar1 + 0x20) == '\0') {
          pcVar2 = (char *)0x8011e38;
LAB_08011c76:
          uVar5 = 0x18;
          uVar4 = 0x45;
          uVar3 = 0x12;
        }
        else {
          uVar5 = 0x10;
          uVar4 = 0x48;
          pcVar2 = s_System_settings_08011e28;
          uVar3 = 10;
        }
      }
      else {
        if (param_2 == 3) {
          FUN_08007e88(0x82,8,0xad,0x33,5,0xfc60);
          if (*(char *)(iVar1 + 0x20) == '\0') {
            pcVar2 = (char *)0x8011e4c;
            goto LAB_08011c76;
          }
          pcVar2 = s_Reset_08011e44;
        }
        else {
          if (param_2 != 4) goto LAB_08011cae;
          FUN_08007e88(0xbf,8,0xea,0x33,5,0xfc60);
          if (*(char *)(iVar1 + 0x20) == '\0') {
            pcVar2 = &DAT_08011e60;
            goto LAB_08011c76;
          }
          pcVar2 = s_About_08011e58;
        }
        uVar5 = 0x18;
        uVar4 = 0x45;
        uVar3 = 0x2a;
      }
      FUN_080082f2(uVar3,uVar4,pcVar2,0xf79e,0xf79e,uVar5,1);
    }
  }
LAB_08011cae:
  if (param_3 == 1) {
    uVar6 = *(undefined2 *)(iVar1 + 0x1c);
    uVar4 = 0x33;
    uVar3 = 8;
LAB_08011d04:
    FUN_08007e88(uVar3,8,uVar4,0x33,5,uVar6);
  }
  else {
    if (param_3 == 2) {
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar4 = 0x70;
      uVar3 = 0x45;
      goto LAB_08011d04;
    }
    if (param_3 == 3) {
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar4 = 0xad;
      uVar3 = 0x82;
      goto LAB_08011d04;
    }
    if (param_3 == 4) {
      uVar6 = *(undefined2 *)(iVar1 + 0x1c);
      uVar4 = 0xea;
      uVar3 = 0xbf;
      goto LAB_08011d04;
    }
  }
  if (param_4 == 1) {
    uVar5 = 0xe;
    uVar4 = 0xe;
    uVar3 = DAT_08011da8;
  }
  else if (param_4 == 2) {
    uVar5 = 0xc;
    uVar4 = 0x4a;
    uVar3 = DAT_08011dac;
  }
  else if (param_4 == 3) {
    uVar5 = 0xd;
    uVar4 = 0x87;
    uVar3 = DAT_08011db0;
  }
  else {
    if (param_4 != 4) goto LAB_08011d4a;
    uVar5 = 0xe;
    uVar4 = 0xc5;
    uVar3 = DAT_08011db4;
  }
  FUN_08007c6c(uVar3,uVar4,uVar5,0xfc60,0xfc60,0);
LAB_08011d4a:
  if (param_5 == 1) {
    uVar5 = 0xe;
    uVar6 = *(undefined2 *)(iVar1 + 0x1c);
    uVar4 = 0xe;
    uVar3 = DAT_08011da8;
  }
  else if (param_5 == 2) {
    uVar6 = *(undefined2 *)(iVar1 + 0x1c);
    uVar5 = 0xc;
    uVar4 = 0x4a;
    uVar3 = DAT_08011dac;
  }
  else if (param_5 == 3) {
    uVar5 = 0xd;
    uVar6 = *(undefined2 *)(iVar1 + 0x1c);
    uVar4 = 0x87;
    uVar3 = DAT_08011db0;
  }
  else {
    if (param_5 != 4) {
      return;
    }
    uVar5 = 0xe;
    uVar6 = *(undefined2 *)(iVar1 + 0x1c);
    uVar4 = 0xc5;
    uVar3 = DAT_08011db4;
  }
  FUN_08007c6c(uVar3,uVar4,uVar5,uVar6,0xf79e,0);
  return;
}


// ===== FUN_08011f08 @ 08011f08

void FUN_08011f08(int param_1)

{
  uint uVar1;
  undefined2 local_18 [8];
  
  uVar1 = 0;
  if (param_1 == 5) {
    do {
      local_18[uVar1] = 0x400;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 5);
  }
  else if (param_1 == 4) {
    do {
      local_18[uVar1] = 0x400;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
    local_18[4] = 0x3186;
  }
  else if (param_1 == 3) {
    do {
      local_18[uVar1] = 0x400;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 3);
    local_18[4] = 0x3186;
    local_18[3] = 0x3186;
  }
  else {
    local_18[3] = 0x3186;
    local_18[4] = 0x3186;
    local_18[2] = 0x3186;
    if (param_1 == 2) {
      local_18[1] = 0x400;
    }
    else {
      local_18[1] = 0x3186;
    }
    local_18[0] = 0x400;
  }
  FUN_08007f24(0x6d,0x6a,0x84,0x6e,0x3186);
  FUN_08007fc8(0x5c,0x71,0x95,0x83,4,local_18[4]);
  FUN_08007f24(0x5c,0x7d,0x95,0x83,local_18[4]);
  FUN_08007f24(0x5c,0x85,0x95,0x96,local_18[3]);
  FUN_08007f24(0x5c,0x98,0x95,0xa9,local_18[2]);
  FUN_08007f24(0x5c,0xab,0x95,0xbc,local_18[1]);
  FUN_08007fc8(0x5c,0xbe,0x95,0xd2,4,local_18[0]);
  FUN_08007f24(0x5c,0xbe,0x95,0xcb,local_18[0]);
  return;
}


// ===== FUN_08012078 @ 08012078

int FUN_08012078(char *param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  if (param_2 < 2) {
    return 2;
  }
  if (*(uint *)(param_1 + 0x14) <= param_2) {
    return 2;
  }
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    uVar3 = param_2 + (param_2 >> 1);
    iVar2 = FUN_0801191c(param_1,*(int *)(param_1 + 0x20) + (uVar3 >> 0xc));
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((param_2 & 1) == 0) {
      uVar5 = param_3;
    }
    else {
      uVar5 = (byte)param_1[(uVar3 & 0xfff) + 0x30] & 0xf | (param_3 & 0xff) << 4;
    }
    param_1[(uVar3 & 0xfff) + 0x30] = (byte)uVar5;
    param_1[3] = '\x01';
    iVar2 = FUN_0801191c(param_1,*(int *)(param_1 + 0x20) + (uVar3 + 1 >> 0xc));
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((param_2 & 1) == 0) {
      bVar4 = param_1[(uVar3 + 1 & 0xfff) + 0x30] & 0xf0U | (byte)(param_3 >> 8) & 0xf;
    }
    else {
      bVar4 = (byte)((param_3 & 0xfff) >> 4);
    }
    param_1[(uVar3 + 1 & 0xfff) + 0x30] = bVar4;
  }
  else if (cVar1 == '\x02') {
    iVar2 = FUN_0801191c(param_1,*(int *)(param_1 + 0x20) + (param_2 >> 0xb));
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_08012c68(param_1 + (param_2 & 0x7ff) * 2 + 0x30,param_3 & 0xffff);
  }
  else {
    if (cVar1 != '\x03') {
      return 2;
    }
    iVar2 = FUN_0801191c(param_1,*(int *)(param_1 + 0x20) + (param_2 >> 10));
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar3 = FUN_080105ee();
    FUN_08012c58(param_1 + (param_2 & 0x3ff) * 4 + 0x30,uVar3 & 0xf0000000 | param_3 & 0xfffffff);
  }
  param_1[3] = '\x01';
  return 0;
}


// ===== FUN_08012164 @ 08012164

void FUN_08012164(void)

{
  FUN_0800f2fc(DAT_08012174,DAT_08012170,0x46);
  return;
}


// ===== FUN_08012178 @ 08012178

undefined4 FUN_08012178(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = DAT_080121b4;
  iVar2 = FUN_0800fd5e(DAT_080121b4,1);
  if ((iVar2 == 0) || (iVar2 = FUN_0800fd5e(uVar1,2), iVar2 == 0)) {
    FUN_08009d18(10);
    iVar2 = FUN_0800fd5e(uVar1,1);
    if ((iVar2 == 0) || (iVar2 = FUN_0800fd5e(uVar1,2), iVar2 == 0)) {
      return 1;
    }
  }
  return 0;
}


// ===== FUN_080121b8 @ 080121b8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_080121b8(uint param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  byte bVar10;
  
  bVar4 = false;
  bVar10 = 0;
  sVar3 = 0;
  iVar7 = FUN_08012178();
  iVar5 = _DAT_0801228c;
  if (iVar7 == 1) {
    FUN_08007f24(0,0,0xf0,0x140,*(undefined2 *)(_DAT_0801228c + 0x1a),param_2,param_3);
    if (*(char *)(iVar5 + 0x20) == '\0') {
      uVar1 = *(ushort *)(iVar5 + 0x1a);
      param_2 = 0x18;
      uVar2 = *(undefined2 *)(iVar5 + 0x1c);
      pcVar9 = &DAT_080122b4;
      uVar8 = 0x1e;
    }
    else {
      uVar1 = *(ushort *)(iVar5 + 0x1a);
      param_2 = 0x10;
      uVar2 = *(undefined2 *)(iVar5 + 0x1c);
      pcVar9 = s_Do_not_use_while_charging_0801228f + 1;
      uVar8 = 0x14;
    }
    param_1 = (uint)uVar1;
    FUN_080082f2(uVar8,0xfa,pcVar9,uVar2,param_1,param_2,0);
    uVar6 = DAT_080122b0;
    uVar8 = DAT_080122ac;
    while( true ) {
      iVar7 = FUN_0800fd5e(uVar8,2);
      if (iVar7 == 0) {
        if (!bVar4) {
          FUN_08011f08(5);
          bVar4 = true;
        }
      }
      else {
        if (sVar3 == 0) {
          if (bVar10 < 5) {
            bVar10 = bVar10 + 1;
          }
          else {
            bVar10 = 1;
          }
          FUN_08011f08(bVar10);
          sVar3 = 0x4f;
        }
        sVar3 = sVar3 + -1;
        bVar4 = false;
      }
      iVar7 = FUN_08012178();
      if (iVar7 == 0) break;
      iVar7 = FUN_0800fd5e(uVar6,0x80);
      if (iVar7 == 0) {
        FUN_08009d18(10);
        iVar7 = FUN_0800fd5e(uVar6,0x80);
        if (iVar7 == 0) {
          FUN_08012aa0();
        }
      }
    }
    *(undefined1 *)(iVar5 + 5) = 1;
  }
  return CONCAT44(param_2,param_1);
}


// ===== FUN_080122c4 @ 080122c4

int FUN_080122c4(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if ((param_2 < 2) || (*(uint *)(iVar3 + 0x14) <= param_2)) {
LAB_08012330:
    iVar1 = 2;
  }
  else if ((param_3 == 0) || (iVar1 = FUN_08012078(iVar3,param_3,0xffffffff), iVar1 == 0)) {
    do {
      uVar2 = FUN_0800fae4(param_1,param_2);
      if (uVar2 == 0) break;
      if (uVar2 == 1) goto LAB_08012330;
      if (uVar2 == 0xffffffff) {
        return 1;
      }
      iVar1 = FUN_08012078(iVar3,param_2,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (*(uint *)(iVar3 + 0x10) < *(uint *)(iVar3 + 0x14) - 2) {
        *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) + 1;
        *(byte *)(iVar3 + 4) = *(byte *)(iVar3 + 4) | 1;
      }
      param_2 = uVar2;
    } while (uVar2 < *(uint *)(iVar3 + 0x14));
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_08012338 @ 08012338

void FUN_08012338(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  
  iVar3 = DAT_08012420;
  iVar2 = DAT_0801241c;
  iVar1 = DAT_08012418;
  uVar12 = (uint)(byte)(*(char *)(DAT_08012418 + 0x12) * '\x02' + 10);
  *(ushort *)(DAT_08012418 + uVar12 * 2) =
       (ushort)*(byte *)(DAT_0801241c + 3) | (ushort)*(byte *)(DAT_08012420 + 0xd) << 6;
  iVar8 = FUN_08012a2c();
  iVar4 = DAT_08012424;
  if (iVar8 == 1) {
    uVar10 = DAT_08012430;
  }
  else {
    iVar8 = FUN_08012a2c();
    if (iVar8 == 2) {
      uVar10 = DAT_08012434;
    }
    else {
      iVar9 = FUN_08012a2c();
      iVar5 = DAT_0801242c;
      iVar8 = DAT_08012428;
      if (iVar9 == 3) {
        uVar10 = DAT_08012438;
      }
      else {
        if (*(char *)(iVar2 + 3) == '\n') {
          uVar10 = FUN_080155a0(*(undefined4 *)(iVar3 + 8),*(undefined4 *)(DAT_0801243c + 0x14));
        }
        else {
          uVar10 = *(uint *)(iVar3 + 8);
        }
        if (0x807fffff < uVar10) {
          uVar10 = uVar10 ^ 0x80000000;
          *(ushort *)(iVar1 + uVar12 * 2) = *(ushort *)(iVar1 + uVar12 * 2) | 0x1000;
        }
        if ((int)uVar10 < iVar4) {
          uVar10 = FUN_080158c4(uVar10,iVar8);
          uVar11 = *(ushort *)(iVar1 + uVar12 * 2) | 0x6000;
        }
        else if ((int)uVar10 < iVar5) {
          uVar10 = FUN_080158c4(uVar10,iVar5);
          uVar11 = *(ushort *)(iVar1 + uVar12 * 2) | 0x4000;
        }
        else {
          if (iVar8 <= (int)uVar10) goto LAB_080123f0;
          uVar10 = FUN_080158c4();
          uVar11 = *(ushort *)(iVar1 + uVar12 * 2) | 0x2000;
        }
        *(ushort *)(iVar1 + uVar12 * 2) = uVar11;
      }
    }
  }
LAB_080123f0:
  uVar6 = FUN_0801582c(uVar10);
  *(undefined2 *)(iVar1 + uVar12 * 2 + 2) = uVar6;
  if (*(ushort *)(iVar1 + 0x10) < 0x1e) {
    *(ushort *)(iVar1 + 0x10) = *(ushort *)(iVar1 + 0x10) + 1;
  }
  if (*(ushort *)(iVar1 + 0x12) < 0x1e) {
    sVar7 = *(ushort *)(iVar1 + 0x12) + 1;
  }
  else {
    sVar7 = 1;
  }
  *(short *)(iVar1 + 0x12) = sVar7;
  return;
}


// ===== FUN_08012440 @ 08012440

void FUN_08012440(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = DAT_080124b8;
  cVar1 = *(char *)(DAT_080124b8 + 3);
  cVar2 = *(char *)(DAT_080124b8 + 2);
  if ((cVar1 == '\0') || (cVar1 == '\x01')) {
    if (cVar2 == '\x02') goto LAB_0801246a;
    uVar5 = 8000;
  }
  else {
    if (cVar2 != '\x02') goto LAB_080124b4;
LAB_0801246a:
    uVar5 = 60000;
  }
  if (*(char *)(DAT_080124bc + 0xd) == '\x06') {
    *(int *)(DAT_080124b8 + 0x10) = *(int *)(DAT_080124b8 + 0x10) + 1;
    if (*(uint *)(iVar3 + 0x10) <= uVar5) {
      return;
    }
    if (cVar2 == '\x02') {
      iVar4 = FUN_08012868(0x15);
      if (iVar4 == 1) {
        *(undefined1 *)(iVar3 + 2) = 2;
      }
    }
    else if (cVar1 == '\x01') {
      iVar4 = FUN_08012868(0xd);
      if (iVar4 == 1) {
        **(undefined1 **)(iVar3 + 0x14) = 1;
      }
    }
    else {
      iVar4 = FUN_08012868(0xc);
      if (iVar4 == 1) {
        **(undefined1 **)(iVar3 + 0x14) = 0;
      }
    }
  }
LAB_080124b4:
  *(undefined4 *)(iVar3 + 0x10) = 0;
  return;
}


// ===== FUN_080124c0 @ 080124c0

void FUN_080124c0(void)

{
  FUN_08012868(0xb);
  FUN_08012868(0xa0);
  return;
}


// ===== FUN_080124d4 @ 080124d4

void FUN_080124d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  pbVar3 = DAT_0801259c;
  bVar1 = *DAT_0801259c;
  if ((DAT_08012598 < *(int *)(DAT_08012594 + 8)) && (bVar1 == 0)) {
    *DAT_0801259c = 1;
LAB_0801253e:
    pcVar6 = s_100mV_080125b0;
  }
  else {
    if (bVar1 == 1) goto LAB_0801253e;
    if (bVar1 == 2) {
      pcVar6 = &DAT_080125b8;
    }
    else if (bVar1 == 3) {
      FUN_0800fc94(DAT_080125a0,4);
      pcVar6 = &DAT_080125c0;
    }
    else if (bVar1 == 4) {
      FUN_0800fc94(DAT_080125a0,4);
      pcVar6 = s_DC_10A_080125cc;
    }
    else {
      local_20 = param_2;
      uStack_1c = param_3;
      local_18 = param_4;
      if (bVar1 < 5) goto LAB_0801251c;
      FUN_0800fc94(DAT_080125a0,4);
      pcVar6 = s_DC_100A_080125a4;
    }
  }
  local_18 = 0;
  uStack_1c = 0x20;
  local_20 = 0;
  FUN_080082f2(0x46,0x4b,pcVar6,0xf79e);
LAB_0801251c:
  cVar2 = *(char *)(DAT_080125ac + 2);
  if (cVar2 == '\r') {
    iVar5 = FUN_08012868(1);
    if (iVar5 == 1) {
      *pbVar3 = *pbVar3 + 1;
    }
    return;
  }
  if (cVar2 == '\x05') {
    uVar4 = 3;
  }
  else if (cVar2 == '\x01') {
    uVar4 = 9;
  }
  else {
    if (cVar2 != '\t') {
      return;
    }
    uVar4 = 8;
  }
  FUN_08012868(uVar4,local_20,uStack_1c,local_18);
  return;
}


// ===== FUN_080125d4 @ 080125d4

undefined4 FUN_080125d4(void)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  char cVar9;
  char local_28 [12];
  
  pcVar1 = DAT_08012838;
  iVar7 = DAT_08012834;
  uVar6 = 0;
  bVar8 = *(char *)(DAT_08012834 + 9) == '\x01';
  do {
    if (!bVar8) {
      return 0;
    }
    bVar8 = *DAT_08012838 == 'Z';
  } while ((!bVar8) || (bVar8 = DAT_08012838[1] == -0x5b, !bVar8));
  *(undefined1 *)(DAT_08012834 + 9) = 0;
  *(undefined1 *)(iVar7 + 10) = 1;
  if ((int)((uint)(byte)pcVar1[2] << 0x1b) < 0) {
    uVar4 = 0x2d;
  }
  else {
    uVar4 = 0x20;
  }
  FUN_080129d0(local_28);
  pcVar2 = DAT_0801283c;
  do {
    cVar3 = local_28[uVar6];
    if ((((((cVar3 != ' ') && (cVar3 != '0')) && (cVar3 != '1')) &&
         (((cVar3 != '2' && (cVar3 != '3')) &&
          ((cVar3 != '4' && ((cVar3 != '5' && (cVar3 != '6')))))))) && (cVar3 != '7')) &&
       ((cVar3 != '8' && (cVar3 != '9')))) {
      *pcVar2 = '\0';
      break;
    }
    uVar6 = uVar6 + 1 & 0xff;
    *pcVar2 = '\x01';
  } while (uVar6 < 4);
  if ((int)((uint)(byte)pcVar1[3] << 0x1b) < 0) {
    cVar3 = local_28[1];
    local_28[1] = 0x2e;
LAB_08012686:
    cVar9 = local_28[2];
LAB_080126a6:
    FUN_08014af4(DAT_0801283c + 0x30,s__c_c_c_c_c_c_08012840,uVar4,local_28[0],local_28[1],cVar3,
                 cVar9,local_28[3]);
  }
  else {
    if ((int)((uint)(byte)pcVar1[4] << 0x1b) < 0) {
      cVar3 = 0x2e;
      goto LAB_08012686;
    }
    if ((int)((uint)(byte)pcVar1[5] << 0x1b) < 0) {
      cVar9 = 0x2e;
      cVar3 = local_28[2];
      goto LAB_080126a6;
    }
    FUN_08014af4(DAT_0801283c + 0x30,s__c_c_c_c_c_08012850,uVar4,local_28[0],local_28[1],local_28[2]
                 ,local_28[3]);
  }
  *(char **)(pcVar2 + 4) = DAT_0801283c + 0x30;
  if ((*pcVar2 == '\x01') &&
     (((((pcVar1[2] & 0xe0U) != 0 || (pcVar1[3] & 0xfU) != 0 ||
        ((pcVar1[3] & 0xe0U) != 0 || (pcVar1[4] & 0xfU) != 0)) ||
       ((pcVar1[4] & 0xe0U) != 0 || (pcVar1[5] & 0xfU) != 0)) ||
      ((pcVar1[5] & 0xe0U) != 0 || (pcVar1[6] & 0xfU) != 0)))) {
    uVar4 = FUN_0800966c(DAT_0801283c + 0x30);
    *(undefined4 *)(pcVar2 + 8) = uVar4;
  }
  if ((int)((uint)(byte)pcVar1[2] << 0x1e) < 0) {
    pcVar2[0xc] = '\x02';
  }
  else if ((pcVar1[2] & 1U) == 0) {
    pcVar2[0xc] = -1;
  }
  else {
    pcVar2[0xc] = '\x01';
  }
  uVar6 = (uint)(byte)pcVar1[8];
  if ((int)(uVar6 << 0x1e) < 0) {
    if ((pcVar1[7] & 1U) != 0) {
      pcVar2[0xd] = '\x02';
      goto LAB_080127d0;
    }
    cVar3 = '\x03';
  }
  else {
    uVar5 = (uint)(byte)pcVar1[7];
    if ((int)(uVar5 << 0x1a) < 0) {
      if ((int)((uint)(byte)pcVar1[6] << 0x19) < 0) {
        cVar3 = '\b';
      }
      else if ((int)(uVar5 << 0x1d) < 0) {
        cVar3 = '\t';
      }
      else {
        cVar3 = '\a';
      }
    }
    else if ((pcVar1[8] & 1U) == 0) {
      if ((int)(uVar5 << 0x1b) < 0) {
        if ((int)((uint)(byte)pcVar1[6] << 0x1a) < 0) {
          cVar3 = '\n';
        }
        else if ((int)((uint)(byte)pcVar1[6] << 0x1b) < 0) {
          cVar3 = '\v';
        }
        else {
          cVar3 = '\f';
        }
      }
      else if ((int)(uVar6 << 0x1a) < 0) {
        cVar3 = '\x10';
      }
      else {
        if (-1 < (int)(uVar6 << 0x1d)) {
          pcVar2[0xd] = '\x01';
          goto LAB_080127d0;
        }
        if ((int)((uint)(byte)pcVar1[6] << 0x19) < 0) {
          cVar3 = '\x0e';
        }
        else if ((int)(uVar5 << 0x1d) < 0) {
          cVar3 = '\x0f';
        }
        else {
          cVar3 = '\r';
        }
      }
    }
    else if ((int)((uint)(byte)pcVar1[6] << 0x1b) < 0) {
      cVar3 = '\x04';
    }
    else if ((pcVar1[7] & 1U) == 0) {
      cVar3 = '\x06';
    }
    else {
      cVar3 = '\x05';
    }
  }
  pcVar2[0xd] = cVar3;
LAB_080127d0:
  uVar6 = (uint)(byte)pcVar1[10];
  if ((int)(uVar6 << 0x18) < 0) {
    pcVar2[0x14] = '\x01';
  }
  else {
    pcVar2[0x14] = '\0';
  }
  if ((int)(uVar6 << 0x19) < 0) {
    iVar7 = -1;
  }
  else {
    iVar7 = 1;
  }
  pcVar1[10] = (char)(uVar6 & 0x3f);
  uVar4 = FUN_0801589c((uVar6 & 0x3f) * 0x10000 + (uint)(byte)pcVar1[0xb] * 0x100 +
                       (uint)(byte)pcVar1[0xc]);
  uVar6 = FUN_08015670(uVar4,DAT_0801285c);
  *(uint *)(pcVar2 + 0x10) = uVar6;
  if (iVar7 != 1) {
    *(uint *)(pcVar2 + 0x10) = uVar6 ^ 0x80000000;
  }
  if ((*DAT_08012860 != '\x02') && (*pcVar2 != '\0')) {
    FUN_080145fc(*(undefined1 *)*DAT_08012864);
    FUN_08009088();
  }
  return 0;
}


// ===== FUN_08012868 @ 08012868

undefined4 FUN_08012868(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  char local_1b;
  undefined2 uStack_1a;
  
  local_24 = DAT_08012998;
  uStack_20 = DAT_0801299c;
  uVar9 = 0;
  if (param_1 == 0xa0) {
    local_24._0_3_ = CONCAT12(2,(short)DAT_08012998);
    local_24 = (uint)(uint3)local_24;
  }
  uVar4 = local_24;
  local_24 = CONCAT13((char)param_1,(uint3)local_24);
  uVar5 = local_24;
  local_24._2_1_ = SUB41(uVar4,2);
  uStack_1a = (undefined2)((uint)DAT_080129a0 >> 0x10);
  _uStack_1c = CONCAT11(local_24._2_1_ + (char)param_1,(char)DAT_080129a0);
  local_24 = uVar5;
  FUN_08012a74(&local_24);
  iVar2 = DAT_080129a4;
  while (*(char *)(iVar2 + 8) != '\x01') {
    FUN_08009d18(1);
    uVar9 = uVar9 + 1 & 0xffff;
    if (999 < uVar9) {
      return 0;
    }
    if (uVar9 % 200 == 0) {
      FUN_08012a74(&local_24);
    }
  }
  if (*DAT_080129a8 == '\0') {
    if (((param_1 == 0x10) || (param_1 == 0x11)) || (param_1 == 0x15)) {
      FUN_0800fc94(DAT_080129ac,4);
    }
    else {
      FUN_0800fc90(DAT_080129ac,4);
    }
  }
  iVar3 = DAT_080129b8;
  uVar5 = DAT_080129b4;
  if (*DAT_080129b0 != '\0') {
    return 1;
  }
  *(undefined4 *)(DAT_080129b8 + 0x18) = 0;
  *(undefined4 *)(iVar3 + 0x1c) = uVar5;
  uVar5 = DAT_080129bc;
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0x20) = 0;
  *(undefined4 *)(iVar3 + 0x24) = uVar5;
  *(undefined1 *)(iVar3 + 0x28) = 0x10;
  *(undefined1 *)(iVar3 + 0x29) = 1;
  if ((*(char *)*DAT_080129c0 != '\t') && (*(char *)*DAT_080129c0 != '\b')) {
    if (*DAT_080129c4 == '\0') {
      FUN_08007f24(0x14,0xdf,0x66,0xf7,*(undefined2 *)(iVar2 + 0x1e));
      uVar1 = *(undefined2 *)(iVar2 + 0x1e);
      uVar8 = 0xf7;
      uVar7 = 0xdb;
      uVar6 = 0xdf;
      uVar5 = 0x88;
    }
    else {
      if (*DAT_080129c4 != '\x01') goto LAB_08012962;
      FUN_08007f24(7,0xec,0x4a,0xfa,*(undefined2 *)(iVar2 + 0x1a));
      uVar1 = *(undefined2 *)(iVar2 + 0x1a);
      uVar8 = 0xf9;
      uVar7 = 0x96;
      uVar6 = 0xec;
      uVar5 = 0x51;
    }
    FUN_08007f24(uVar5,uVar6,uVar7,uVar8,uVar1);
  }
LAB_08012962:
  *(undefined1 *)(iVar3 + 0x2a) = 0;
  FUN_080145dc();
  if (*(char *)(iVar3 + 0xe) == '\x01') {
    *(undefined1 *)(iVar3 + 0xe) = 0;
    FUN_0800a124(0);
  }
  FUN_08014af4(*(undefined4 *)(iVar3 + 4),s__080129c8);
  return 1;
}


// ===== FUN_080129d0 @ 080129d0

void FUN_080129d0(undefined4 param_1)

{
  undefined1 uVar1;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  undefined1 *extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  
  uVar1 = FUN_0801194e(*(byte *)(DAT_08012a28 + 2) & 0xf0 | *(byte *)(DAT_08012a28 + 3) & 0xf,
                       DAT_08012a28,param_1);
  *extraout_r2 = uVar1;
  uVar1 = FUN_0801194e(*(byte *)(extraout_r1 + 3) & 0xf0 | *(byte *)(extraout_r1 + 4) & 0xf);
  *(undefined1 *)(extraout_r2_00 + 1) = uVar1;
  uVar1 = FUN_0801194e(*(byte *)(extraout_r1_00 + 4) & 0xf0 | *(byte *)(extraout_r1_00 + 5) & 0xf);
  *(undefined1 *)(extraout_r2_01 + 2) = uVar1;
  uVar1 = FUN_0801194e(*(byte *)(extraout_r1_01 + 5) & 0xf0 | *(byte *)(extraout_r1_01 + 6) & 0xf);
  *(undefined1 *)(extraout_r2_02 + 3) = uVar1;
  return;
}


// ===== FUN_08012a2c @ 08012a2c

undefined4 FUN_08012a2c(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_08012a70 + 4);
  if (*(char *)(iVar1 + 2) == '.') {
    if ((*(char *)(iVar1 + 3) == '0') && (*(char *)(iVar1 + 4) == 'L')) {
      return 1;
    }
  }
  else if (*(char *)(iVar1 + 2) == '0') {
    if (*(char *)(iVar1 + 3) == '.') {
      if (*(char *)(iVar1 + 4) == 'L') {
        return 2;
      }
    }
    else if ((*(char *)(iVar1 + 3) == 'L') && (*(char *)(iVar1 + 4) == '.')) {
      return 3;
    }
  }
  return 0;
}


// ===== FUN_08012a74 @ 08012a74

void FUN_08012a74(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = DAT_08012a9c;
  uVar3 = 0;
  do {
    do {
      iVar2 = FUN_080134c4(uVar1,0x80);
    } while (iVar2 == 0);
    FUN_08013498(uVar1,*(undefined1 *)(param_1 + uVar3));
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 10);
  return;
}


// ===== FUN_08012aa0 @ 08012aa0

void FUN_08012aa0(void)

{
  int iVar1;
  int iVar2;
  
  FUN_080104f4(9999,0x8f,0);
  iVar2 = DAT_08012af8;
  iVar1 = DAT_08012af4;
  *(ushort *)(DAT_08012af8 + 2) = (ushort)*(byte *)(DAT_08012af4 + 0x20);
  *(ushort *)(iVar2 + 8) = (ushort)*(byte *)(iVar1 + 0x21);
  *(ushort *)(iVar2 + 4) = (ushort)*(byte *)(iVar1 + 0x22);
  *(ushort *)(iVar2 + 6) = (ushort)*(byte *)(iVar1 + 0x23);
  *(ushort *)(iVar2 + 10) = (ushort)*DAT_08012afc;
  *(ushort *)(iVar2 + 0xc) = (ushort)*DAT_08012b00;
  *(ushort *)(iVar2 + 0xe) = (ushort)*(byte *)(iVar1 + 0x26);
  FUN_08014678();
  FUN_08009450();
  FUN_08009d18(0xfa);
  FUN_0800fc90(DAT_08012b04,0x40);
  DataSynchronizationBarrier(0xf);
  *DAT_08011ab8 = *DAT_08011ab8 & 0x700 | DAT_08011abc;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_08012b08 @ 08012b08

void FUN_08012b08(undefined1 *param_1)

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


// ===== FUN_08012b1e @ 08012b1e

void FUN_08012b1e(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xffffffbf | (param_2 & 1) << 6;
  return;
}


// ===== FUN_08012b28 @ 08012b28

void FUN_08012b28(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xfffff7ff | (param_2 & 1) << 0xb;
  return;
}


// ===== FUN_08012b32 @ 08012b32

uint FUN_08012b32(int param_1)

{
  return *(uint *)(param_1 + 0xc) & 0xffff;
}


// ===== FUN_08012b38 @ 08012b38

void FUN_08012b38(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}


// ===== FUN_08012b3c @ 08012b3c

bool FUN_08012b3c(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 8) & param_2) != 0;
}


// ===== FUN_08012b4a @ 08012b4a

void FUN_08012b4a(uint *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  
  param_1[7] = param_1[7] & 0xfffff7ff;
  cVar1 = *param_2;
  if (cVar1 == '\0') {
    uVar2 = *param_1 & 0xffff7fff;
LAB_08012b8a:
    *param_1 = uVar2;
    uVar2 = *param_1 & 0xffffbfff;
LAB_08012ba2:
    *param_1 = uVar2;
    uVar2 = *param_1 & 0xfffffbff;
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        uVar2 = *param_1 | 0x8000;
        goto LAB_08012b8a;
      }
      if (cVar1 != '\x03') goto LAB_08012bac;
      *param_1 = *param_1 | 0x8000;
      uVar2 = *param_1 | 0x4000;
      goto LAB_08012ba2;
    }
    *param_1 = *param_1 & 0xffff7fff;
    *param_1 = *param_1 & 0xffffbfff;
    uVar2 = *param_1 | 0x400;
  }
  *param_1 = uVar2;
LAB_08012bac:
  *param_1 = *param_1 & 0xfffffdff | ((byte)param_2[7] & 1) << 9;
  if ((param_2[1] == '\x01') && (param_2[7] == '\x01')) {
    uVar2 = *param_1 | 0x100;
  }
  else {
    uVar2 = *param_1 & 0xfffffeff;
  }
  *param_1 = uVar2;
  *param_1 = *param_1 & 0xfffffffb | ((byte)param_2[1] & 1) << 2;
  if ((byte)param_2[2] < 8) {
    param_1[1] = param_1[1] & 0xfffffeff;
    *param_1 = *param_1 & 0xffffffc7 | ((byte)param_2[2] & 7) << 3;
  }
  else {
    param_1[1] = param_1[1] | 0x100;
    *param_1 = *param_1 & 0xffffffc7 | ((byte)param_2[2] & 7) << 3;
  }
  *param_1 = *param_1 & 0xffffff7f | ((byte)param_2[3] & 1) << 7;
  *param_1 = *param_1 & 0xfffff7ff | ((byte)param_2[4] & 1) << 0xb;
  *param_1 = *param_1 & 0xfffffffd | ((byte)param_2[5] & 1) << 1;
  *param_1 = *param_1 & 0xfffffffe | (byte)param_2[6] & 1;
  return;
}


// ===== FUN_08012c30 @ 08012c30

void FUN_08012c30(char *param_1,int param_2,uint param_3)

{
  FUN_08012c68(param_2 + 0x1a,param_3 & 0xffff);
  if (*param_1 == '\x03') {
    FUN_08012c68(param_2 + 0x14,param_3 >> 0x10);
    return;
  }
  return;
}


// ===== FUN_08012c58 @ 08012c58

void FUN_08012c58(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  param_1[2] = (char)((uint)param_2 >> 0x10);
  param_1[3] = (char)((uint)param_2 >> 0x18);
  return;
}


// ===== FUN_08012c68 @ 08012c68

void FUN_08012c68(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)param_2;
  param_1[1] = (char)((uint)param_2 >> 8);
  return;
}


// ===== FUN_08012c70 @ 08012c70

void FUN_08012c70(void)

{
  short sVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  undefined1 auStack_94 [128];
  
  uVar3 = DAT_08012d18;
  bVar2 = false;
  bVar5 = 0xff;
  sVar1 = 0;
  do {
    while (iVar4 = FUN_0800fd5e(uVar3,0x80), iVar4 != 0) {
      iVar4 = FUN_08012178();
      if (iVar4 == 1) {
        if (bVar5 == 0xff) {
          FUN_080104f4(9999,0x8f,
                       (uint)((short)(*(byte *)(DAT_08012d1c + 0x23) + 1) * 9999) / 10 & 0xffff);
        }
        iVar4 = FUN_0800fd5e(DAT_08012d20,2);
        if (iVar4 == 0) {
          if (!bVar2) {
            FUN_08011f08(5);
            bVar2 = true;
          }
        }
        else {
          if (sVar1 == 0) {
            if (bVar5 < 5) {
              bVar5 = bVar5 + 1;
            }
            else {
              bVar5 = 1;
            }
            FUN_08011f08(bVar5);
            sVar1 = 0x4f;
          }
          sVar1 = sVar1 + -1;
          bVar2 = false;
        }
      }
    }
    FUN_08009d18(10);
    iVar4 = FUN_0800fd5e(uVar3,0x80);
  } while (iVar4 != 0);
  FUN_08009ba4(DAT_0801206c,1);
  FUN_08009ba4(DAT_0801206c + -5,1);
  uVar3 = DAT_08012070;
  FUN_0800fcb0(DAT_08012070,auStack_94 + 0x84);
  FUN_0800fc94(uVar3,0x40);
  uVar3 = DAT_08012074;
  FUN_0800fcb0(DAT_08012074,auStack_94 + 0x84);
  FUN_0800fc90(uVar3,4);
  return;
}


// ===== FUN_08012d24 @ 08012d24

int FUN_08012d24(char *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = FUN_08012da8();
  if (iVar1 == 0) {
    if ((*param_1 == '\x03') && (param_1[4] == '\x01')) {
      pcVar2 = param_1 + 0x30;
      FUN_080076e8(pcVar2,0x1000);
      FUN_08012c68(param_1 + 0x22e,0xaa55);
      FUN_08012c58(pcVar2,DAT_08012da0);
      FUN_08012c58(param_1 + 0x214,DAT_08012da4);
      FUN_08012c58(param_1 + 0x218,*(undefined4 *)(param_1 + 0x10));
      FUN_08012c58(param_1 + 0x21c,*(undefined4 *)(param_1 + 0xc));
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x1c) + 1;
      FUN_0800a09c(param_1[1],pcVar2,*(int *)(param_1 + 0x1c) + 1,1);
      param_1[4] = '\0';
    }
    iVar3 = FUN_0800a004(param_1[1],0);
    if (iVar3 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}


// ===== FUN_08012da8 @ 08012da8

undefined4 FUN_08012da8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 3) != '\0') {
    iVar1 = FUN_0800a09c(*(undefined1 *)(param_1 + 1),param_1 + 0x30,*(undefined4 *)(param_1 + 0x2c)
                         ,1);
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 3) = 0;
      if (((uint)(*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x20)) < *(uint *)(param_1 + 0x18))
         && (*(char *)(param_1 + 2) == '\x02')) {
        FUN_0800a09c(*(undefined1 *)(param_1 + 1),param_1 + 0x30,
                     *(int *)(param_1 + 0x2c) + *(uint *)(param_1 + 0x18),1);
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}


// ===== FUN_08012df0 @ 08012df0

void FUN_08012df0(void)

{
  longlong lVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 unaff_r4;
  
  *DAT_08012e5c = 0x14;
  FUN_08009c20();
  FUN_08009a20(1);
  do {
    iVar3 = FUN_08009b7c();
  } while (iVar3 == 0);
  FUN_08009bc8(2,0x23);
  FUN_08009a20(2,1);
  do {
    iVar3 = FUN_08009b5c(0x19);
  } while (iVar3 != 1);
  FUN_080099d4(0);
  FUN_080099f4(0);
  FUN_080099e4(0);
  FUN_08009a04(1);
  FUN_08009c68(2);
  do {
    iVar3 = FUN_08009ca0();
  } while (iVar3 != 2);
  FUN_08009a04(0);
  iVar4 = FUN_08009ca0();
  puVar2 = DAT_08012f10;
  iVar3 = DAT_08012f0c;
  if (iVar4 == 0) {
    if ((-1 < *(int *)(DAT_08012f0c + 0x54) << 0x16) || (-1 < *(int *)(DAT_08012f0c + 0x30) << 6))
    goto LAB_08012e8a;
    uVar5 = DAT_08012f14;
  }
  else {
    if ((iVar4 == 1) || (iVar4 != 2)) {
LAB_08012e8a:
      *DAT_08012f10 = DAT_08012f08;
      goto LAB_08012ef4;
    }
    iVar4 = *(int *)(DAT_08012f0c + 4) << 0xf;
    if (*(int *)(DAT_08012f0c + 0x2c) < 0) {
      if ((-1 < iVar4) || (uVar5 = DAT_08012f08, *(int *)(DAT_08012f0c + 4) << 0xe < 0)) {
        uVar5 = DAT_08012f18;
      }
      lVar1 = (ulonglong)uVar5 * (ulonglong)((*(uint *)(DAT_08012f0c + 0x2c) & 0x1ffff) >> 8);
      uVar5 = FUN_0800730a((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),
                           ((*(uint *)(DAT_08012f0c + 0x2c) & 0xff) >> 4) <<
                           (*(uint *)(DAT_08012f0c + 0x2c) & 7),0,unaff_r4);
    }
    else {
      uVar5 = (*(uint *)(DAT_08012f0c + 4) & 0x3fffff) >> 0x12;
      uVar7 = (*(uint *)(DAT_08012f0c + 4) & 0x7fffffff) >> 0x1d;
      if ((uVar7 == 0) && (uVar5 != 0xf)) {
        iVar6 = uVar5 + 2;
      }
      else {
        iVar6 = uVar5 + uVar7 * 0x10 + 1;
      }
      if ((iVar4 < 0) && (-1 < *(int *)(DAT_08012f0c + 4) << 0xe)) {
        uVar5 = DAT_08012f08;
      }
      else {
        uVar5 = DAT_08012f18;
      }
      uVar5 = uVar5 * iVar6;
    }
  }
  *puVar2 = uVar5;
LAB_08012ef4:
  *puVar2 = *puVar2 >> *(sbyte *)(DAT_08012f1c + ((*(uint *)(iVar3 + 4) & 0xff) >> 4));
  return;
}


// ===== FUN_08012f20 @ 08012f20

void FUN_08012f20(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_08012f5c;
  uVar3 = DAT_08012f58;
  *(undefined4 *)(DAT_08012f5c + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = uVar3;
  uVar3 = DAT_08012f60;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  *(undefined4 *)(iVar2 + 0x24) = uVar3;
  *(undefined1 *)(iVar2 + 0x2a) = 0;
  cVar1 = *(char *)(DAT_08012f64 + 0x22);
  if (cVar1 == '\x01') {
    uVar3 = 30000;
  }
  else if (cVar1 == '\x02') {
    uVar3 = DAT_08012f6c;
  }
  else {
    if (cVar1 != '\x03') {
      return;
    }
    uVar3 = DAT_08012f68;
  }
  *(undefined4 *)(DAT_08012f64 + 0x10) = uVar3;
  return;
}


// ===== FUN_08012f70 @ 08012f70

void FUN_08012f70(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  
  iVar1 = DAT_08013100;
  if (*(char *)(DAT_08013100 + 2) == '\0') {
    *(undefined1 *)(DAT_08013100 + 5) = 1;
    *(undefined1 *)(iVar1 + 2) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
  }
  if (*(char *)(iVar1 + 1) == '\0') {
    FUN_0800cc34(*(undefined1 *)(iVar1 + 5),0,0);
    *(undefined1 *)(iVar1 + 1) = 1;
  }
  iVar2 = DAT_08013104;
  cVar3 = *(char *)(DAT_08013104 + 2);
  if (cVar3 == '\t') {
    if (*(char *)(iVar1 + 6) != '\0') {
      if (8 < *(byte *)(DAT_08013104 + 0x23)) goto LAB_080130b6;
      bVar6 = *(byte *)(DAT_08013104 + 0x23) + 1;
      goto LAB_08012ff4;
    }
    bVar6 = *(byte *)(iVar1 + 5);
    if (8 < bVar6) goto LAB_080130b6;
    *(byte *)(iVar1 + 5) = bVar6 + 1;
    if (bVar6 == 2) {
LAB_0801304a:
      FUN_0800ca6c(0);
    }
    else if (bVar6 == 5) {
      FUN_0800c7b0();
    }
    else {
LAB_08013036:
      FUN_0800cc34(0,bVar6,0);
    }
LAB_08012fde:
    cVar3 = '\0';
    uVar7 = 0;
    uVar5 = 0;
    uVar4 = *(undefined1 *)(iVar1 + 5);
  }
  else {
    if (cVar3 == '\x01') {
      if (*(char *)(iVar1 + 6) == '\0') {
        bVar6 = *(byte *)(iVar1 + 5);
        if (bVar6 < 2) goto LAB_080130b6;
        *(byte *)(iVar1 + 5) = bVar6 - 1;
        if (bVar6 != 3) {
          if (bVar6 != 6) goto LAB_08013036;
          goto LAB_0801304a;
        }
        FUN_0800c938();
        goto LAB_08012fde;
      }
      if (*(char *)(DAT_08013104 + 0x23) == '\0') goto LAB_080130b6;
      bVar6 = *(char *)(DAT_08013104 + 0x23) - 1;
LAB_08012ff4:
      *(byte *)(DAT_08013104 + 0x23) = bVar6;
      FUN_080104f4(9999,0x8f,(uint)((short)(bVar6 + 1) * 9999) / 10 & 0xffff);
      FUN_0800c58c(*(char *)(iVar2 + 0x23) + '\x01',1);
      goto LAB_080130b6;
    }
    if (cVar3 == '\x05') {
      uVar7 = (uint)*(byte *)(iVar1 + 5);
      if (uVar7 < 3) {
        if ((uint)*(byte *)(DAT_08013104 + 0x20) == uVar7 - 1) goto LAB_080130b6;
        cVar3 = *(byte *)(DAT_08013104 + 0x20) + 1;
      }
      else {
        if (uVar7 == 3) {
          FUN_0800cc34(0,0);
          *(undefined1 *)(iVar1 + 6) = 1;
          goto LAB_080130b6;
        }
        if (uVar7 < 6) {
          if ((uint)*(byte *)(DAT_08013104 + 0x21) == uVar7 - 4) goto LAB_080130b6;
          cVar3 = *(byte *)(DAT_08013104 + 0x21) + 4;
        }
        else {
          if ((uint)*(byte *)(DAT_08013104 + 0x22) == uVar7 - 6) goto LAB_080130b6;
          cVar3 = *(byte *)(DAT_08013104 + 0x22) + 6;
        }
      }
      uVar5 = 0;
    }
    else {
      if (cVar3 != '\r') goto LAB_080130b6;
      if (*(char *)(iVar1 + 6) != '\0') {
        FUN_0800c58c(*(char *)(DAT_08013104 + 0x23) + '\x01',0);
        *(undefined1 *)(iVar1 + 6) = 0;
        *(undefined1 *)(iVar2 + 2) = 0;
        goto LAB_080130b6;
      }
      cVar3 = '\0';
      uVar5 = *(undefined1 *)(iVar1 + 5);
      uVar7 = 0;
    }
    uVar4 = 0;
  }
  FUN_0800cc34(uVar4,uVar5,uVar7,cVar3);
LAB_080130b6:
  if (*(char *)(iVar2 + 5) == '\x01') {
    if (*(byte *)(iVar1 + 5) < 3) {
      FUN_0800c938();
    }
    else if (*(byte *)(iVar1 + 5) < 6) {
      FUN_0800ca6c(*(undefined1 *)(iVar1 + 6));
    }
    else {
      FUN_0800c7b0();
    }
    if (*(char *)(iVar1 + 3) == '\x01') {
      FUN_0800cc34(*(undefined1 *)(iVar1 + 5),0,0);
    }
    *(undefined1 *)(iVar2 + 5) = 0;
  }
  return;
}


// ===== FUN_08013108 @ 08013108

void FUN_08013108(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_e000e010;
  if (param_1 == 4) {
    uVar1 = uVar1 | 4;
  }
  else {
    uVar1 = uVar1 & 0xfffffffb;
  }
  DAT_e000e010 = uVar1;
  return;
}


// ===== FUN_08013120 @ 08013120

void FUN_08013120(void)

{
  undefined4 uVar1;
  undefined1 auStack_20 [4];
  uint local_1c;
  
  FUN_080076e8(auStack_20,0x14);
  FUN_08009a64(auStack_20);
  FUN_08009ba4(DAT_08013180,1);
  uVar1 = DAT_08013188;
  FUN_0801318c(DAT_08013188,9999,local_1c / DAT_08013184 - 1);
  FUN_080131b8(uVar1,0);
  FUN_080131d2(uVar1,1);
  FUN_08011a78(3);
  FUN_080119fc(0x19,0);
  FUN_080131c2(uVar1,1);
  return;
}


// ===== FUN_0801318c @ 0801318c

void FUN_0801318c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 1;
  return;
}


// ===== FUN_0801319a @ 0801319a

void FUN_0801319a(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x34) = param_3;
    return;
  }
  if (param_2 == 2) {
    *(undefined4 *)(param_1 + 0x38) = param_3;
    return;
  }
  if (param_2 == 4) {
    *(undefined4 *)(param_1 + 0x3c) = param_3;
    return;
  }
  if (param_2 == 6) {
    *(undefined4 *)(param_1 + 0x40) = param_3;
  }
  return;
}


// ===== FUN_080131b8 @ 080131b8

void FUN_080131b8(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xffffff8f | (param_2 & 7) << 4;
  return;
}


// ===== FUN_080131c2 @ 080131c2

void FUN_080131c2(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xfffffffe | param_2 & 1;
  return;
}


// ===== FUN_080131cc @ 080131cc

void FUN_080131cc(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x10) = ~param_2;
  return;
}


// ===== FUN_080131d2 @ 080131d2

void FUN_080131d2(int param_1,uint param_2,int param_3)

{
  if (param_3 == 1) {
    param_2 = *(uint *)(param_1 + 0xc) | param_2;
  }
  else {
    if (param_3 != 0) {
      return;
    }
    param_2 = *(uint *)(param_1 + 0xc) & ~param_2;
  }
  *(uint *)(param_1 + 0xc) = param_2;
  return;
}


// ===== FUN_080131e8 @ 080131e8

undefined4 FUN_080131e8(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(uint *)(param_1 + 0x10) & param_2) != 0) && ((*(uint *)(param_1 + 0xc) & param_2) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== FUN_080131fc @ 080131fc

void FUN_080131fc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 0x18) & 0xfffffff7 | (param_3 & 1) << 3;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 4) {
        uVar1 = *(uint *)(param_1 + 0x1c) & 0xfffffff7 | (param_3 & 1) << 3;
      }
      else {
        if (param_2 != 6) {
          return;
        }
        uVar1 = *(uint *)(param_1 + 0x1c) & 0xfffff7ff | (param_3 & 1) << 0xb;
      }
      *(uint *)(param_1 + 0x1c) = uVar1;
      return;
    }
    uVar1 = *(uint *)(param_1 + 0x18) & 0xfffff7ff | (param_3 & 1) << 0xb;
  }
  *(uint *)(param_1 + 0x18) = uVar1;
  return;
}


// ===== FUN_0801322e @ 0801322e

void FUN_0801322e(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = param_3[1];
  bVar2 = param_3[2];
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & ~(1 << (param_2 + 9U & 0xff));
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | (uint)bVar2 << (param_2 + 9U & 0xff) & 0xffff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & ~(1 << (param_2 + 8U & 0xff));
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | (uint)bVar1 << (param_2 + 8U & 0xff) & 0xffff;
  if (param_2 == 0) {
    uVar3 = *(uint *)(param_1 + 0x18) & 0xffffff8f | (*param_3 & 7) << 4;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 4) {
        uVar3 = *(uint *)(param_1 + 0x1c) & 0xffffff8f | (*param_3 & 7) << 4;
      }
      else {
        if (param_2 != 6) goto LAB_080132a4;
        uVar3 = *(uint *)(param_1 + 0x1c) & 0xffff8fff | (*param_3 & 7) << 0xc;
      }
      *(uint *)(param_1 + 0x1c) = uVar3;
      goto LAB_080132a4;
    }
    uVar3 = *(uint *)(param_1 + 0x18) & 0xffff8fff | (*param_3 & 7) << 0xc;
  }
  *(uint *)(param_1 + 0x18) = uVar3;
LAB_080132a4:
  uVar3 = param_2 * 2 + 3;
  uVar4 = param_2 * 2 + 1;
  uVar4 = (*(uint *)(param_1 + 0x20) & ~(1 << (uVar3 & 0xff)) |
          (uint)param_3[4] << (uVar3 & 0xff) & 0xffff) & ~(1 << (uVar4 & 0xff)) |
          (uint)param_3[3] << (uVar4 & 0xff) & 0xffff;
  uVar3 = param_2 * 2 + 2;
  *(uint *)(param_1 + 0x20) = uVar4;
  *(uint *)(param_1 + 0x20) =
       (uVar4 & ~(1 << (uVar3 & 0xff)) | (uint)param_3[6] << (uVar3 & 0xff) & 0xffff) &
       ~(1 << (param_2 << 1 & 0xffU)) | (uint)param_3[5] << (param_2 << 1 & 0xffU) & 0xffff;
  return;
}


// ===== FUN_080132f8 @ 080132f8

void FUN_080132f8(undefined1 *param_1)

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


// ===== FUN_0801330a @ 0801330a

void FUN_0801330a(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xffff7fff | (param_2 & 1) << 0xf;
  return;
}


// ===== FUN_08013314 @ 08013314

void FUN_08013314(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xffffff7f | (param_2 & 1) << 7;
  return;
}


// ===== FUN_08013370 @ 08013370

void FUN_08013370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_08009ba4(DAT_080133d0,1);
  FUN_08009ba4(DAT_080133d4,1);
  FUN_0800fc98(&local_10);
  local_10 = 0x400;
  local_c = 0x1080400;
  FUN_0800fcb0(DAT_080133d8,&local_10);
  uVar1 = DAT_080133dc;
  FUN_080134d0(DAT_080133dc,param_1,0);
  FUN_080135e0(uVar1,1);
  FUN_080134aa(uVar1,1);
  return;
}


// ===== FUN_080133e0 @ 080133e0

void FUN_080133e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08009ba4(DAT_08013488,1);
  FUN_08009ba4(DAT_08013488 + -0xc,1);
  FUN_0800fc98(&local_18);
  uVar1 = DAT_0801348c;
  local_18 = 0x200;
  local_14 = 0x1080400;
  FUN_0800fcb0(DAT_0801348c,&local_18);
  local_18 = 0x400;
  local_14 = 0x1001800;
  FUN_0800fcb0(uVar1,&local_18);
  FUN_08011a78(3);
  FUN_080119fc(0x25,0);
  uVar1 = DAT_08013490;
  FUN_080134d0(DAT_08013490,0x2580,0);
  FUN_080135e0(uVar1,1);
  FUN_080135d6(uVar1,1);
  FUN_0801352c(uVar1,DAT_08013494,1);
  FUN_080134aa(uVar1,1);
  FUN_0800e648();
  return;
}


// ===== FUN_08013498 @ 08013498

void FUN_08013498(int param_1,uint param_2)

{
  *(uint *)(param_1 + 4) = param_2 & 0x1ff;
  return;
}


// ===== FUN_080134a0 @ 080134a0

void FUN_080134a0(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xffffffbf | (param_2 & 1) << 6;
  return;
}


// ===== FUN_080134aa @ 080134aa

void FUN_080134aa(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffdfff | (param_2 & 1) << 0xd;
  return;
}


// ===== FUN_080134b4 @ 080134b4

undefined8 FUN_080134b4(uint *param_1,uint param_2)

{
  if ((param_2 & 0x1f) == 0) {
    *param_1 = ~param_2;
    return CONCAT44(~param_2,param_1);
  }
  return CONCAT44(*param_1,param_1[1]);
}


// ===== FUN_080134c4 @ 080134c4

bool FUN_080134c4(uint *param_1,uint param_2)

{
  return (*param_1 & param_2) != 0;
}


// ===== FUN_080134d0 @ 080134d0

void FUN_080134d0(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined1 auStack_28 [8];
  int local_20;
  int local_1c;
  
  FUN_08009a64(auStack_28);
  if (param_1 != DAT_08013528) {
    local_20 = local_1c;
  }
  param_2 = (uint)(local_20 * 10) / param_2;
  uVar1 = param_2 / 10;
  if (4 < param_2 % 10) {
    uVar1 = uVar1 + 1;
  }
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffff0000 | uVar1 & 0xffff;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffefff | (param_3 & 1) << 0xc;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffcfff | (param_4 & 3) << 0xc;
  return;
}


// ===== FUN_0801352c @ 0801352c

void FUN_0801352c(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (uint *)(param_1 + (param_2 >> 0x10));
  uVar3 = 1 << (param_2 & 0x1f);
  uVar2 = *puVar1;
  if (param_3 == 1) {
    uVar2 = uVar2 | uVar3;
  }
  else {
    uVar2 = uVar2 & ~uVar3;
  }
  *puVar1 = uVar2;
  return;
}


// ===== FUN_0801354a @ 0801354a

bool FUN_0801354a(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0x20) {
    uVar1 = (param_1[3] & 0x3f) >> 5;
    goto joined_r0x080135ac;
  }
  if ((int)param_2 < 0x21) {
    if (param_2 == 4) {
LAB_080135b8:
      uVar1 = param_1[5] & 1;
    }
    else if ((int)param_2 < 5) {
      if (param_2 != 1) {
        if (param_2 != 2) {
          return false;
        }
        goto LAB_080135b8;
      }
      uVar1 = (param_1[3] & 0x1ff) >> 8;
    }
    else if (param_2 == 8) {
      if ((int)(param_1[3] << 0x1a) < 0) goto LAB_080135c8;
      uVar1 = param_1[5] & 1;
    }
    else {
      if (param_2 != 0x10) {
        return false;
      }
      uVar1 = (param_1[3] & 0x1f) >> 4;
    }
  }
  else if (param_2 == 0x40) {
    uVar1 = param_1[3];
LAB_08013594:
    uVar1 = (uVar1 & 0x7f) >> 6;
  }
  else if (param_2 == 0x80) {
    uVar1 = (param_1[3] & 0xff) >> 7;
  }
  else {
    if (param_2 == 0x100) {
      uVar1 = param_1[4];
      goto LAB_08013594;
    }
    if (param_2 != 0x200) {
      return false;
    }
    uVar1 = (param_1[5] & 0x7ff) >> 10;
  }
joined_r0x080135ac:
  if (uVar1 == 0) {
    return false;
  }
LAB_080135c8:
  return (*param_1 & param_2) != 0;
}


// ===== FUN_080135d6 @ 080135d6

void FUN_080135d6(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffb | (param_2 & 1) << 2;
  return;
}


// ===== FUN_080135e0 @ 080135e0

void FUN_080135e0(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffff7 | (param_2 & 1) << 3;
  return;
}


// ===== FUN_080135ea @ 080135ea

void FUN_080135ea(int param_1)

{
  *(uint *)(param_1 + 0x900) = *(uint *)(param_1 + 0x900) & 0xfffff800;
  *(uint *)(param_1 + 0x804) = *(uint *)(param_1 + 0x804) & 0xfffffeff;
  return;
}


// ===== FUN_08013604 @ 08013604

void FUN_08013604(int param_1)

{
  *(undefined4 *)(param_1 + 0xb10) = 0;
  *(uint *)(param_1 + 0xb10) = *(uint *)(param_1 + 0xb10) & 0xe007ffff | 0x80000;
  *(uint *)(param_1 + 0xb10) = (*(uint *)(param_1 + 0xb10) & 0xfff80000) + 0x18;
  *(uint *)(param_1 + 0xb10) = *(uint *)(param_1 + 0xb10) | 0x60000000;
  return;
}


// ===== FUN_08013634 @ 08013634

void FUN_08013634(int param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = param_1 + (uint)*param_2 * 0x20;
  if (param_2[2] == 0) {
    *(uint *)(iVar1 + 0x900) = *(uint *)(iVar1 + 0x900) & 0xffdfffff;
    if ((param_2[3] == 3) || (param_2[3] == 2)) {
      param_1 = param_1 + (uint)*param_2 * 0x20;
      *(uint *)(param_1 + 0x900) = *(uint *)(param_1 + 0x900) | 0x10000000;
      return;
    }
  }
  else {
    *(uint *)(iVar1 + 0xb00) = *(uint *)(iVar1 + 0xb00) & 0xffdfffff;
    if ((param_2[3] == 3) || (param_2[3] == 2)) {
      param_1 = param_1 + (uint)*param_2 * 0x20;
      *(uint *)(param_1 + 0xb00) = *(uint *)(param_1 + 0xb00) | 0x10000000;
    }
  }
  return;
}


// ===== FUN_08013692 @ 08013692

void FUN_08013692(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 0x20 + 0x908) = param_3;
  return;
}


// ===== FUN_0801369c @ 0801369c

uint FUN_0801369c(int param_1,uint param_2)

{
  return *(uint *)(param_1 + param_2 * 0x20 + 0x908) &
         (*(uint *)(param_1 + 0x810) | (*(uint *)(param_1 + 0x834) >> (param_2 & 0xff) & 1) << 7);
}


// ===== FUN_080137d2 @ 080137d2

void FUN_080137d2(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 0x20 + 0xb08) = param_3;
  return;
}


// ===== FUN_080137dc @ 080137dc

uint FUN_080137dc(int param_1,int param_2)

{
  return *(uint *)(param_1 + 0x814) & *(uint *)(param_1 + param_2 * 0x20 + 0xb08);
}


// ===== FUN_080137ec @ 080137ec

void FUN_080137ec(int param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = param_1 + (uint)*param_2 * 0x20;
  if (param_2[2] == 0) {
    if (-1 < *(int *)(iVar1 + 0x900)) {
      *(uint *)(iVar1 + 0x900) = *(uint *)(iVar1 + 0x900) & 0xbfffffff;
    }
    param_1 = param_1 + (uint)*param_2 * 0x20;
    *(uint *)(param_1 + 0x900) = *(uint *)(param_1 + 0x900) | 0x200000;
    return;
  }
  if (-1 < *(int *)(iVar1 + 0xb00)) {
    *(uint *)(iVar1 + 0xb00) = *(uint *)(iVar1 + 0xb00) & 0xbfffffff;
  }
  param_1 = param_1 + (uint)*param_2 * 0x20;
  *(uint *)(param_1 + 0xb00) = *(uint *)(param_1 + 0xb00) | 0x200000;
  return;
}


// ===== FUN_08013848 @ 08013848

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013848(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  FUN_0800f350();
  *DAT_0801385c = param_1;
  iVar1 = FUN_0800ec28(_DAT_0800f23c,&DAT_0800f238,1,extraout_r3,unaff_r4,unaff_lr);
  if (iVar1 == 0) {
    pcVar2 = s_2_APPusbflash_init_ok_0800f258;
  }
  else {
    pcVar2 = s_2_APPusbflash_init_err_0800f23f + 1;
  }
  FUN_08007420(pcVar2);
  return;
}


// ===== FUN_08013860 @ 08013860

void FUN_08013860(int param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffff83f | (param_2 & 0x1f) << 6;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
  uVar2 = 0;
  do {
    if (-1 < *(int *)(param_1 + 0x10) << 0x1a) {
      return;
    }
    bVar1 = uVar2 <= DAT_08013888;
    uVar2 = uVar2 + 1;
  } while (bVar1);
  return;
}


// ===== FUN_0801388c @ 0801388c

uint FUN_0801388c(int param_1)

{
  return *(uint *)(param_1 + 0x81c) & *(uint *)(param_1 + 0x818) & 0xffff;
}


// ===== FUN_0801389a @ 0801389a

uint FUN_0801389a(int param_1)

{
  return (*(uint *)(param_1 + 0x81c) & *(uint *)(param_1 + 0x818)) >> 0x10;
}


// ===== FUN_080138a8 @ 080138a8

void FUN_080138a8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


// ===== FUN_080138ac @ 080138ac

uint FUN_080138ac(int param_1)

{
  return *(uint *)(param_1 + 0x18) & *(uint *)(param_1 + 0x14);
}


// ===== FUN_080138b4 @ 080138b4

void FUN_080138b4(int param_1,uint param_2,int param_3)

{
  if (param_3 == 1) {
    param_2 = *(uint *)(param_1 + 0x18) | param_2;
  }
  else {
    param_2 = *(uint *)(param_1 + 0x18) & ~param_2;
  }
  *(uint *)(param_1 + 0x18) = param_2;
  return;
}


// ===== FUN_080138c4 @ 080138c4

void FUN_080138c4(int param_1)

{
  *(uint *)(param_1 + 0xe00) = *(uint *)(param_1 + 0xe00) & 0xfffffffe;
  return;
}


// ===== FUN_080138d2 @ 080138d2

void FUN_080138d2(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_4 + 3U >> 2; uVar1 = uVar1 + 1) {
    *param_2 = *(undefined4 *)(param_1 + 0x1000);
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_080138ec @ 080138ec

void FUN_080138ec(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x800) = *(uint *)(param_1 + 0x800) & 0xfffff80f | (param_2 & 0x7f) << 4;
  return;
}


// ===== FUN_080138fa @ 080138fa

void FUN_080138fa(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}


// ===== FUN_08013900 @ 08013900

void FUN_08013900(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x24) | param_3 << 0x10;
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x24) + (*(uint *)(param_1 + 0x28) >> 0x10);
  for (; (int)uVar1 < param_2 + -1; uVar1 = uVar1 + 1 & 0xff) {
    uVar2 = uVar2 + (*(uint *)(param_1 + uVar1 * 4 + 0x104) >> 0x10);
  }
  *(uint *)(param_1 + param_2 * 4 + 0x100) = uVar2 | param_3 << 0x10;
  return;
}


// ===== FUN_0801394c @ 0801394c

uint FUN_0801394c(int param_1)

{
  return *(uint *)(param_1 + 0x808) & 1;
}


// ===== FUN_08013956 @ 08013956

void FUN_08013956(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  uVar2 = param_1[param_2 * 0xb + 9] - param_1[param_2 * 0xb + 10];
  if ((uint)param_1[param_2 * 0xb + 5] <
      (uint)(param_1[param_2 * 0xb + 9] - param_1[param_2 * 0xb + 10])) {
    uVar2 = param_1[param_2 * 0xb + 5];
  }
  while (uVar2 + 3 >> 2 < (*(uint *)(iVar3 + param_2 * 0x20 + 0x918) & 0xffff)) {
    uVar1 = param_1[param_2 * 0xb + 9];
    if ((uVar1 <= (uint)param_1[param_2 * 0xb + 10]) || (uVar1 == 0)) break;
    uVar2 = uVar1 - param_1[param_2 * 0xb + 10];
    if ((uint)param_1[param_2 * 0xb + 5] < uVar2) {
      uVar2 = param_1[param_2 * 0xb + 5];
    }
    FUN_080139da(iVar3,param_1[param_2 * 0xb + 8],param_2 & 0xffff,uVar2 & 0xffff);
    param_1[param_2 * 0xb + 8] = param_1[param_2 * 0xb + 8] + uVar2;
    param_1[param_2 * 0xb + 10] = param_1[param_2 * 0xb + 10] + uVar2;
  }
  if (uVar2 == 0) {
    *(uint *)(iVar3 + 0x834) = *(uint *)(iVar3 + 0x834) & ~(1 << (param_2 & 0xff));
  }
  return;
}


// ===== FUN_080139da @ 080139da

void FUN_080139da(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < param_4 + 3U >> 2; uVar2 = uVar2 + 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *(undefined4 *)(param_1 + param_3 * 0x1000 + 0x1000) = uVar1;
  }
  return;
}


// ===== FUN_080139f8 @ 080139f8

void FUN_080139f8(undefined4 *param_1,uint param_2)

{
  int iVar1;
  
  if ((int)(param_2 << 0x18) < 0) {
    iVar1 = (param_2 & 0x7f) * 0xb + 3;
  }
  else {
    iVar1 = (param_2 & 0x7f) * 0xb + 0x2f;
  }
  FUN_08013634(*param_1,param_1 + iVar1);
  *(undefined1 *)((int)(param_1 + iVar1) + 0xd) = 0;
  return;
}


// ===== FUN_08013a24 @ 08013a24

/* WARNING: Removing unreachable block (ram,0x08013e9c) */
/* WARNING: Removing unreachable block (ram,0x08013eaa) */

void FUN_08013a24(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  if (param_2 == 0) {
    if ((char)param_1[0x60] == '\x02') {
      uVar1 = param_1[5];
      if (uVar1 < (uint)param_1[0xc]) {
        uVar1 = param_1[0xc] - uVar1;
        param_1[0xc] = uVar1;
        if ((uint)param_1[5] <= uVar1) {
          uVar1 = param_1[5];
        }
        FUN_08013f04(param_1,0,param_1[8],uVar1 & 0xffff);
        return;
      }
      if (((param_1[0xb] == uVar1) && (uVar1 <= (uint)param_1[0xd])) &&
         ((uint)param_1[0xd] < (uint)*(ushort *)((int)param_1 + 0x182))) {
        param_1[0xb] = 0;
        FUN_08013f04(param_1,0,0,0);
      }
      else {
        if ((*(code **)(param_1[1] + 0xc) != (code *)0x0) && ((char)param_1[0x61] == '\x03')) {
          (**(code **)(param_1[1] + 0xc))(param_1);
        }
        *(undefined1 *)(param_1 + 0x60) = 5;
      }
      iVar4 = *param_1;
      param_1[0x34] = 0;
      param_1[0x35] = 0;
      iVar2 = iVar4 + (uint)*(byte *)(param_1 + 0x2f) * 0x20;
      param_1[0x36] = 0;
      puVar3 = (uint *)(iVar2 + 0xb00);
      param_1[0x35] = param_1[0x31];
      *(uint *)(iVar2 + 0xb10) = *(uint *)(iVar2 + 0xb10) & 0xfff80000 | param_1[0x31] & 0x7ffffU;
      *(uint *)(iVar2 + 0xb10) = *(uint *)(iVar2 + 0xb10) & 0xe007ffff | 0x80000;
      if (*(char *)((int)param_1 + 0xbf) == '\x01') {
        if ((*(uint *)(iVar4 + 0x808) >> 8 & 1) == 0) {
          uVar1 = *puVar3 | 0x20000000;
        }
        else {
          uVar1 = *puVar3 | 0x10000000;
        }
        *puVar3 = uVar1;
      }
      *puVar3 = *puVar3 | 0x4000000;
      *puVar3 = *puVar3 | 0x80000000;
      return;
    }
  }
  else if ((*(code **)(param_1[1] + 0x14) != (code *)0x0) && ((char)param_1[0x61] == '\x03')) {
                    /* WARNING: Could not recover jumptable at 0x08013a52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1[1] + 0x14))(param_1);
    return;
  }
  return;
}


// ===== FUN_08013ad2 @ 08013ad2

/* WARNING: Removing unreachable block (ram,0x08013e9c) */
/* WARNING: Removing unreachable block (ram,0x08013eaa) */

void FUN_08013ad2(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  if (param_2 == 0) {
    if ((char)param_1[0x60] == '\x03') {
      if ((uint)param_1[0x38] <= (uint)param_1[0x31]) {
        if (*(code **)(param_1[1] + 0x10) != (code *)0x0) {
          (**(code **)(param_1[1] + 0x10))(param_1);
        }
        FUN_08013bba(param_1);
        return;
      }
      uVar1 = param_1[0x38] - param_1[0x31];
      param_1[0x38] = uVar1;
      if ((uint)param_1[0x31] <= uVar1) {
        uVar1 = param_1[0x31];
      }
      iVar4 = *param_1;
      param_1[0x34] = param_1[0x34];
      param_1[0x35] = uVar1 & 0xffff;
      iVar2 = iVar4 + (uint)*(byte *)(param_1 + 0x2f) * 0x20;
      param_1[0x36] = 0;
      puVar3 = (uint *)(iVar2 + 0xb00);
      param_1[0x35] = param_1[0x31];
      *(uint *)(iVar2 + 0xb10) = *(uint *)(iVar2 + 0xb10) & 0xfff80000 | param_1[0x31] & 0x7ffffU;
      *(uint *)(iVar2 + 0xb10) = *(uint *)(iVar2 + 0xb10) & 0xe007ffff | 0x80000;
      if (*(char *)((int)param_1 + 0xbf) == '\x01') {
        if ((*(uint *)(iVar4 + 0x808) >> 8 & 1) == 0) {
          uVar1 = *puVar3 | 0x20000000;
        }
        else {
          uVar1 = *puVar3 | 0x10000000;
        }
        *puVar3 = uVar1;
      }
      *puVar3 = *puVar3 | 0x4000000;
      *puVar3 = *puVar3 | 0x80000000;
      return;
    }
  }
  else if ((*(code **)(param_1[1] + 0x18) != (code *)0x0) && ((char)param_1[0x61] == '\x03')) {
                    /* WARNING: Could not recover jumptable at 0x08013b00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1[1] + 0x18))(param_1);
    return;
  }
  return;
}


// ===== FUN_08013b42 @ 08013b42

uint FUN_08013b42(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_r4;
  
  FUN_080144cc(param_1 + 0x16c,param_1 + 0x174);
  *(undefined1 *)(param_1 + 0x180) = 1;
  *(undefined2 *)(param_1 + 0x182) = *(undefined2 *)(param_1 + 0x172);
  uVar1 = *(byte *)(param_1 + 0x16c) & 0x1f;
  if ((*(byte *)(param_1 + 0x16c) & 0x1f) != 0) {
    if (uVar1 == 1) {
      uVar1 = FUN_08014170(param_1);
      return uVar1;
    }
    if (uVar1 == 2) {
      uVar1 = FUN_08013cf4(param_1);
      return uVar1;
    }
    return uVar1;
  }
  if ((*(byte *)(param_1 + 0x16c) & 0x60) != 0) {
    (**(code **)(*(int *)(param_1 + 4) + 8))();
    return 0;
  }
  switch(*(undefined1 *)(param_1 + 0x16d)) {
  case 0:
    if ((*(char *)(param_1 + 0x184) == '\x02') || (*(char *)(param_1 + 0x184) == '\x03')) {
      if (*(char *)(param_1 + 0x187) != '\0') {
        *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) | 2;
      }
      uVar3 = 2;
      iVar2 = param_1 + 0x18c;
      goto LAB_08013ccc;
    }
    break;
  case 1:
    if ((*(char *)(param_1 + 0x184) != '\x02') && (*(char *)(param_1 + 0x184) != '\x03')) break;
    if (*(short *)(param_1 + 0x16e) != 1) {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x187) = 0;
    *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) & 0xfffffffd;
    goto LAB_08013c6e;
  case 3:
    if (*(short *)(param_1 + 0x16e) != 1) {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x187) = 1;
LAB_08013c6e:
    (**(code **)(*(int *)(param_1 + 4) + 8))(param_1);
LAB_08013ca2:
    FUN_08013bba(param_1);
    return 0;
  case 5:
    if ((*(short *)(param_1 + 0x170) != 0) || (*(short *)(param_1 + 0x172) != 0)) break;
    if (*(char *)(param_1 + 0x184) == '\x03') break;
    *(byte *)(param_1 + 0x186) = *(byte *)(param_1 + 0x16e) & 0x7f;
    if ((*(byte *)(param_1 + 0x16e) & 0x7f) == 0) {
      *(undefined1 *)(param_1 + 0x184) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x184) = 2;
    }
    goto LAB_08013ca2;
  case 6:
    FUN_08014032();
    return 0;
  case 8:
    if (*(short *)(param_1 + 0x172) == 1) {
      if (*(char *)(param_1 + 0x184) == '\x02') {
        *(undefined1 *)(param_1 + 0x188) = 0;
        uVar3 = 1;
        iVar2 = param_1 + 0x188;
      }
      else {
        if (*(char *)(param_1 + 0x184) != '\x03') break;
        uVar3 = 1;
        iVar2 = param_1 + 0x189;
      }
LAB_08013ccc:
      FUN_08013ba2(param_1,iVar2,uVar3,0,unaff_r4);
      return 0;
    }
    break;
  case 9:
    FUN_08014428();
    return 0;
  }
  FUN_08013bca(param_1);
  return 0;
}


// ===== FUN_08013ba2 @ 08013ba2

void FUN_08013ba2(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x34) = param_3;
  *(undefined4 *)(param_1 + 0x30) = param_3;
  *(undefined1 *)(param_1 + 0x180) = 2;
  FUN_08013f04(param_1,0,param_2,param_3);
  return;
}


// ===== FUN_08013bba @ 08013bba

void FUN_08013bba(int param_1)

{
  *(undefined1 *)(param_1 + 0x180) = 4;
  FUN_08013f04(param_1,0,0);
  return;
}


// ===== FUN_08013bca @ 08013bca

void FUN_08013bca(undefined4 param_1)

{
  FUN_080144a0(param_1,0);
  FUN_080144a0(param_1,0x80);
  return;
}


// ===== FUN_08013ce6 @ 08013ce6

void FUN_08013ce6(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x20);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08013cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,4);
  return;
}


// ===== FUN_08013cf4 @ 08013cf4

undefined4 FUN_08013cf4(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = (byte *)(param_1 + 0x16c);
  bVar1 = *(byte *)(param_1 + 0x170);
  uVar4 = (uint)bVar1;
  if ((*pbVar5 & 0x7f) >> 5 == 1) {
    (**(code **)(*(int *)(param_1 + 4) + 8))(param_1,pbVar5);
  }
  cVar2 = *(char *)(param_1 + 0x16d);
  if (cVar2 == '\0') {
    if (*(char *)(param_1 + 0x184) != '\x02') {
      if (*(char *)(param_1 + 0x184) == '\x03') {
        iVar3 = param_1 + (uVar4 & 0x7f) * 0x2c;
        if ((int)(uVar4 << 0x18) < 0) {
          iVar3 = iVar3 + 0xc;
        }
        else {
          iVar3 = iVar3 + 0xbc;
        }
        *(uint *)(iVar3 + 0x10) = (uint)(*(char *)(iVar3 + 0xd) == '\x01');
        FUN_08013ba2(param_1,(uint *)(iVar3 + 0x10),2);
        return 0;
      }
      goto LAB_08013d9a;
    }
    if ((bVar1 & 0x7f) == 0) {
      return 0;
    }
    goto LAB_08013dae;
  }
  if (cVar2 == '\x01') {
    if (*(char *)(param_1 + 0x184) == '\x02') {
LAB_08013da6:
      if (uVar4 == 0) {
        return 0;
      }
      if (uVar4 == 0x80) {
        return 0;
      }
LAB_08013dae:
      FUN_080144a0(param_1,uVar4);
      return 0;
    }
    if (*(char *)(param_1 + 0x184) != '\x03') goto LAB_08013d9a;
    if (*(short *)(param_1 + 0x16e) != 0) {
      return 0;
    }
    if ((bVar1 & 0x7f) == 0) goto LAB_08013d86;
    FUN_080139f8(param_1,uVar4);
  }
  else {
    if (cVar2 != '\x03') {
LAB_08013d9a:
      FUN_08013bca(param_1);
      return 0;
    }
    if (*(char *)(param_1 + 0x184) == '\x02') goto LAB_08013da6;
    if (*(char *)(param_1 + 0x184) != '\x03') goto LAB_08013d9a;
    if (((*(short *)(param_1 + 0x16e) == 0) && (uVar4 != 0)) && (uVar4 != 0x80)) {
      FUN_080144a0(param_1,uVar4);
    }
  }
  (**(code **)(*(int *)(param_1 + 4) + 8))(param_1,pbVar5);
LAB_08013d86:
  FUN_08013bba(param_1);
  return 0;
}


// ===== FUN_08013dd6 @ 08013dd6

void FUN_08013dd6(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0801394c(*param_1);
  if (iVar1 == 1) {
    *(uint *)(*param_1 + 0xe00) = *(uint *)(*param_1 + 0xe00) | 1;
    return;
  }
  return;
}


// ===== FUN_08013df0 @ 08013df0

void FUN_08013df0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_080135ea(iVar1);
  *(uint *)(iVar1 + 0xc) = (*(uint *)(iVar1 + 0xc) & 0xffffc3ff) + 0x1400;
  FUN_08013e38(param_1,0,0,0x40);
  FUN_08013e38(param_1,0x80,0,0x40);
  *(undefined1 *)(param_1 + 0x61) = 1;
  if (*(code **)(param_1[1] + 4) == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08013e34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1[1] + 4))(param_1);
  return;
}


// ===== FUN_08013e38 @ 08013e38

void FUN_08013e38(int *param_1,uint param_2,byte param_3,undefined4 param_4)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = param_2 & 0x7f;
  iVar4 = *param_1;
  if ((int)(param_2 << 0x18) < 0) {
    *(undefined1 *)((int)param_1 + uVar1 * 0x2c + 0xe) = 0;
    iVar3 = uVar1 * 0xb + 3;
  }
  else {
    *(undefined1 *)((int)param_1 + uVar1 * 0x2c + 0xbe) = 1;
    iVar3 = uVar1 * 0xb + 0x2f;
  }
  pbVar2 = (byte *)(param_1 + iVar3);
  *(undefined4 *)(pbVar2 + 8) = param_4;
  pbVar2[3] = param_3;
  uVar1 = 0;
  if ((*pbVar2 == 0) && (iVar3 = *(int *)(pbVar2 + 8), iVar3 != 0x40)) {
    if (iVar3 == 0x20) {
      uVar1 = 1;
    }
    else if (iVar3 == 0x10) {
      uVar1 = 2;
    }
    else if (iVar3 == 8) {
      uVar1 = 3;
    }
  }
  if (pbVar2[2] == 0) {
    *(uint *)(iVar4 + 0x81c) = *(uint *)(iVar4 + 0x81c) | 1 << *pbVar2;
    if (*pbVar2 == 0) {
      *(uint *)(iVar4 + 0x900) = *(uint *)(iVar4 + 0x900) & 0xfffff800 | uVar1;
    }
    else {
      iVar3 = iVar4 + (uint)*pbVar2 * 0x20;
      *(uint *)(iVar3 + 0x900) =
           *(uint *)(iVar3 + 0x900) & 0xfffff800 | *(ushort *)(pbVar2 + 8) & 0x7ff;
    }
    iVar3 = iVar4 + (uint)*pbVar2 * 0x20;
    *(uint *)(iVar3 + 0x900) = *(uint *)(iVar3 + 0x900) & 0xfff3ffff | (pbVar2[3] & 3) << 0x12;
    iVar3 = iVar4 + (uint)*pbVar2 * 0x20;
    *(uint *)(iVar3 + 0x900) = *(uint *)(iVar3 + 0x900) & 0xfc3fffff | (*pbVar2 & 0xf) << 0x16;
    iVar3 = iVar4 + (uint)*pbVar2 * 0x20;
    *(uint *)(iVar3 + 0x900) = *(uint *)(iVar3 + 0x900) | 0x10000000;
    iVar4 = iVar4 + (uint)*pbVar2 * 0x20;
    *(uint *)(iVar4 + 0x900) = *(uint *)(iVar4 + 0x900) | 0x8000;
    return;
  }
  *(uint *)(iVar4 + 0x81c) = *(uint *)(iVar4 + 0x81c) | (1 << *pbVar2) << 0x10;
  if (*pbVar2 == 0) {
    *(uint *)(iVar4 + 0xb00) = *(uint *)(iVar4 + 0xb00) & 0xfffff800 | uVar1;
  }
  else {
    iVar3 = iVar4 + (uint)*pbVar2 * 0x20;
    *(uint *)(iVar3 + 0xb00) =
         *(uint *)(iVar3 + 0xb00) & 0xfffff800 | *(ushort *)(pbVar2 + 8) & 0x7ff;
  }
  iVar3 = iVar4 + (uint)*pbVar2 * 0x20;
  *(uint *)(iVar3 + 0xb00) = *(uint *)(iVar3 + 0xb00) & 0xfff3ffff | (pbVar2[3] & 3) << 0x12;
  iVar3 = iVar4 + (uint)*pbVar2 * 0x20;
  *(uint *)(iVar3 + 0xb00) = *(uint *)(iVar3 + 0xb00) | 0x10000000;
  iVar4 = iVar4 + (uint)*pbVar2 * 0x20;
  *(uint *)(iVar4 + 0xb00) = *(uint *)(iVar4 + 0xb00) | 0x8000;
  return;
}


// ===== FUN_08013f04 @ 08013f04

void FUN_08013f04(int *param_1,uint param_2,int param_3,uint param_4)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = param_2 & 0x7f;
  iVar2 = *param_1;
  pbVar1 = (byte *)(param_1 + uVar6 * 0xb + 3);
  param_1[uVar6 * 0xb + 8] = param_3;
  param_1[uVar6 * 0xb + 9] = param_4;
  param_1[uVar6 * 0xb + 10] = 0;
  iVar4 = iVar2 + (uint)*pbVar1 * 0x20;
  puVar5 = (uint *)(iVar4 + 0x900);
  if (param_4 == 0) {
    *(uint *)(iVar4 + 0x910) = *(uint *)(iVar4 + 0x910) & 0xe007ffff | 0x80000;
    uVar3 = *(uint *)(iVar4 + 0x910) & 0xfff80000;
LAB_08013f98:
    *(uint *)(iVar4 + 0x910) = uVar3;
LAB_08013f9a:
    if (*(char *)((int)param_1 + uVar6 * 0x2c + 0xf) != '\x01') goto LAB_08013fa0;
  }
  else {
    uVar3 = param_1[uVar6 * 0xb + 5];
    if ((param_2 & 0x7f) == 0) {
      if (uVar3 < param_4) {
        param_1[uVar6 * 0xb + 9] = uVar3;
      }
      *(uint *)(iVar4 + 0x910) =
           *(uint *)(iVar4 + 0x910) & 0xfff80000 | param_1[uVar6 * 0xb + 9] & 0x7ffffU;
      *(uint *)(iVar4 + 0x910) = *(uint *)(iVar4 + 0x910) & 0xe007ffff | 0x80000;
      param_1[uVar6 * 0xb + 0xb] = param_1[uVar6 * 0xb + 9];
      goto LAB_08013f9a;
    }
    *(uint *)(iVar4 + 0x910) = *(uint *)(iVar4 + 0x910) & 0xfff80000 | param_4 & 0x7ffff;
    *(uint *)(iVar4 + 0x910) =
         *(uint *)(iVar4 + 0x910) & 0xe007ffff | (((param_4 + uVar3) - 1) / uVar3 & 0x3ff) << 0x13;
    if (*(char *)((int)param_1 + uVar6 * 0x2c + 0xf) == '\x01') {
      uVar3 = (*(uint *)(iVar4 + 0x910) & 0x9fffffff) + 0x20000000;
      goto LAB_08013f98;
    }
LAB_08013fa0:
    if ((param_1[uVar6 * 0xb + 9] == 0) ||
       (*(uint *)(iVar2 + 0x834) = *(uint *)(iVar2 + 0x834) | 1 << *pbVar1,
       *(char *)((int)param_1 + uVar6 * 0x2c + 0xf) != '\x01')) goto LAB_08013fc4;
  }
  if ((*(uint *)(iVar2 + 0x808) >> 8 & 1) == 0) {
    uVar3 = *puVar5 | 0x20000000;
  }
  else {
    uVar3 = *puVar5 | 0x10000000;
  }
  *puVar5 = uVar3;
LAB_08013fc4:
  *puVar5 = *puVar5 | 0x4000000;
  *puVar5 = *puVar5 | 0x80000000;
  if (*(char *)((int)param_1 + uVar6 * 0x2c + 0xf) == '\x01') {
    FUN_080139da(iVar2,param_1[uVar6 * 0xb + 8],*pbVar1,(short)param_1[uVar6 * 0xb + 9]);
    return;
  }
  return;
}


// ===== FUN_08013ff2 @ 08013ff2

void FUN_08013ff2(undefined4 *param_1)

{
  if ((undefined *)*param_1 == &UNK_50000000) {
    FUN_080138fa(&UNK_50000000,0x80);
    FUN_08013900(&UNK_50000000,0,0x18);
    FUN_08013900(&UNK_50000000,1,0x14);
    FUN_08013900(&UNK_50000000,2,0x14);
    FUN_08013900(&UNK_50000000,3,0x14);
    return;
  }
  return;
}


// ===== FUN_08014032 @ 08014032

undefined4 FUN_08014032(int param_1)

{
  ushort uVar1;
  code *pcVar2;
  ushort *puVar3;
  ushort uVar4;
  
  switch(*(ushort *)(param_1 + 0x16e) >> 8) {
  default:
    FUN_08013bca(param_1);
    return 0;
  case 1:
    pcVar2 = (code *)**(undefined4 **)(param_1 + 8);
    break;
  case 2:
    pcVar2 = *(code **)(*(int *)(param_1 + 8) + 8);
    break;
  case 3:
    switch((char)*(ushort *)(param_1 + 0x16e)) {
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
      (**(code **)(*(int *)(param_1 + 4) + 8))(param_1,param_1 + 0x16c);
      return 0;
    }
  }
  puVar3 = (ushort *)(*pcVar2)();
  if (((puVar3 != (ushort *)0x0) && (uVar1 = *puVar3, uVar1 != 0)) &&
     (uVar4 = *(ushort *)(param_1 + 0x172), uVar4 != 0)) {
    if (uVar1 < uVar4) {
      uVar4 = uVar1;
    }
    FUN_08013ba2(param_1,*(undefined4 *)(puVar3 + 2),uVar4);
  }
  return 0;
}


// ===== FUN_080140be @ 080140be

void FUN_080140be(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x20);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x080140c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,5);
  return;
}


// ===== FUN_080140cc @ 080140cc

void FUN_080140cc(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x20);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x080140d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,6);
  return;
}


// ===== FUN_080140da @ 080140da

void FUN_080140da(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  uVar3 = 0;
  for (uVar1 = FUN_0801388c(iVar4); uVar1 != 0; uVar1 = uVar1 >> 1) {
    if ((uVar1 & 1) != 0) {
      uVar2 = FUN_0801369c(iVar4,uVar3);
      if ((uVar2 & 1) != 0) {
        *(uint *)(iVar4 + 0x834) = *(uint *)(iVar4 + 0x834) & ~(1 << (uVar3 & 0xff));
        FUN_08013692(iVar4,uVar3,1);
        FUN_08013a24(param_1,uVar3 & 0xff);
      }
      if ((int)(uVar2 << 0x1c) < 0) {
        FUN_08013692(iVar4,uVar3,8);
      }
      if ((int)(uVar2 << 0x1b) < 0) {
        FUN_08013692(iVar4,uVar3,0x10);
      }
      if ((int)(uVar2 << 0x19) < 0) {
        FUN_08013692(iVar4,uVar3,0x40);
      }
      if ((int)(uVar2 << 0x1e) < 0) {
        FUN_08013692(iVar4,uVar3,2);
      }
      if ((int)(uVar2 << 0x18) < 0) {
        FUN_08013956(param_1,uVar3);
      }
    }
    uVar3 = uVar3 + 1;
  }
  return;
}


// ===== FUN_08014170 @ 08014170

undefined4 FUN_08014170(int param_1)

{
  if (*(char *)(param_1 + 0x184) == '\x03') {
    (**(code **)(*(int *)(param_1 + 4) + 8))(param_1);
    if (*(short *)(param_1 + 0x172) == 0) {
      FUN_08013bba(param_1);
    }
  }
  else {
    FUN_08013bca(param_1);
  }
  return 0;
}


// ===== FUN_080141a4 @ 080141a4

void FUN_080141a4(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_1;
  param_1 = param_1 + 1;
  iVar1 = FUN_080138ac(iVar2);
  if ((*(uint *)(iVar2 + 0x14) & 1) == 0) {
    if (iVar1 << 0x1e < 0) {
      FUN_080138a8(iVar2,2);
    }
    if (iVar1 << 0xd < 0) {
      FUN_080140da(param_1);
    }
    if (iVar1 << 0xc < 0) {
      FUN_08014296(param_1);
    }
    if (iVar1 << 0x13 < 0) {
      FUN_08014318(param_1);
      FUN_080138a8(iVar2,0x1000);
    }
    if (iVar1 << 0x1c < 0) {
      FUN_080144f4(param_1);
      FUN_080138a8(iVar2,8);
    }
    if (iVar1 << 0x12 < 0) {
      FUN_08013df0(param_1);
      FUN_080138a8(iVar2,0x2000);
    }
    if (iVar1 << 0x1b < 0) {
      FUN_080143bc(param_1);
    }
    if (iVar1 << 0xb < 0) {
      FUN_080140be(param_1);
      FUN_080138a8(iVar2,0x100000);
    }
    if (iVar1 << 0x1d < 0) {
      uVar3 = *(undefined4 *)(*param_1 + 4);
      if (*(int *)(*param_1 + 4) << 0x1d < 0) {
        FUN_08013ce6(param_1);
      }
      *(undefined4 *)(*param_1 + 4) = uVar3;
      FUN_080138a8(iVar2,4);
    }
    if (iVar1 << 10 < 0) {
      FUN_080140cc(param_1);
      FUN_080138a8(iVar2,0x200000);
    }
    if (iVar1 < 0) {
      FUN_08014536(param_1);
      FUN_080138a8(iVar2,0x80000000);
    }
    if (iVar1 << 0x14 < 0) {
      FUN_08014500(param_1);
      FUN_080138a8(iVar2,0x800);
      return;
    }
  }
  return;
}


// ===== FUN_08014296 @ 08014296

void FUN_08014296(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  uVar4 = 0;
  for (uVar2 = FUN_0801389a(); uVar2 != 0; uVar2 = uVar2 >> 1) {
    if ((uVar2 & 1) != 0) {
      uVar3 = FUN_080137dc(iVar1,uVar4);
      if ((uVar3 & 1) != 0) {
        FUN_080137d2(iVar1,uVar4,1);
        FUN_08013ad2(param_1,uVar4 & 0xff);
      }
      if ((int)(uVar3 << 0x1c) < 0) {
        FUN_080137d2(iVar1,uVar4,8);
        FUN_08013b42(param_1,uVar4 & 0xff);
        if (*(byte *)((int)param_1 + 0x186) != 0) {
          *(uint *)(*param_1 + 0x800) =
               *(uint *)(*param_1 + 0x800) & 0xfffff80f |
               (*(byte *)((int)param_1 + 0x186) & 0x7f) << 4;
          *(undefined1 *)((int)param_1 + 0x186) = 0;
        }
      }
      if ((int)(uVar3 << 0x1b) < 0) {
        FUN_080137d2(iVar1,uVar4,0x10);
      }
    }
    uVar4 = uVar4 + 1;
  }
  return;
}


// ===== FUN_08014318 @ 08014318

void FUN_08014318(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  uVar3 = 0;
  *(uint *)(iVar2 + 0x804) = *(uint *)(iVar2 + 0x804) & 0xfffffffe;
  FUN_08013ff2(param_1);
  FUN_08013860(iVar2,0x10);
  do {
    iVar1 = iVar2 + uVar3 * 0x20;
    *(undefined4 *)(iVar1 + 0x908) = 0xff;
    *(undefined4 *)(iVar1 + 0xb08) = 0xff;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  *(undefined4 *)(iVar2 + 0x818) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x81c) = 0x10001;
  *(uint *)(iVar2 + 0x814) = *(uint *)(iVar2 + 0x814) | 1;
  *(uint *)(iVar2 + 0x814) = *(uint *)(iVar2 + 0x814) | 2;
  *(uint *)(iVar2 + 0x814) = *(uint *)(iVar2 + 0x814) | 8;
  *(uint *)(iVar2 + 0x810) = *(uint *)(iVar2 + 0x810) | 1;
  *(uint *)(iVar2 + 0x810) = *(uint *)(iVar2 + 0x810) | 2;
  *(uint *)(iVar2 + 0x810) = *(uint *)(iVar2 + 0x810) | 8;
  FUN_080138ec(iVar2,0);
  FUN_08013604(iVar2);
  *(undefined1 *)(param_1 + 0x61) = 1;
  if (*(code **)(param_1[1] + 0x20) == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x080143b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1[1] + 0x20))(param_1,1);
  return;
}


// ===== FUN_080143bc @ 080143bc

void FUN_080143bc(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  FUN_080138b4(iVar4,0x10,0);
  uVar1 = *(uint *)(iVar4 + 0x20);
  uVar3 = (uVar1 & 0x7fff) >> 4;
  uVar2 = (uVar1 & 0x1fffff) >> 0x11;
  uVar1 = uVar1 & 0xf;
  if (uVar2 == 2) {
    if (uVar3 == 0) goto LAB_0801441a;
    FUN_080138d2(iVar4,param_1[uVar1 * 0xb + 0x34],uVar1,uVar3);
    param_1[uVar1 * 0xb + 0x34] = param_1[uVar1 * 0xb + 0x34] + uVar3;
  }
  else {
    if (uVar2 != 6) goto LAB_0801441a;
    FUN_080138d2(iVar4,param_1 + 0x5d,uVar1,uVar3);
  }
  param_1[uVar1 * 0xb + 0x36] = param_1[uVar1 * 0xb + 0x36] + uVar3;
LAB_0801441a:
  FUN_080138b4(iVar4,0x10,1);
  return;
}


// ===== FUN_08014428 @ 08014428

undefined4 FUN_08014428(int param_1)

{
  char cVar1;
  char *pcVar2;
  code *pcVar3;
  
  pcVar2 = DAT_0801449c;
  cVar1 = *(char *)(param_1 + 0x16e);
  *DAT_0801449c = cVar1;
  if ((*(short *)(param_1 + 0x170) == 0) && (*(short *)(param_1 + 0x172) == 0)) {
    if (*(char *)(param_1 + 0x184) == '\x02') {
      if (cVar1 != '\0') {
        *(char *)(param_1 + 0x189) = cVar1;
        *(undefined1 *)(param_1 + 0x184) = 3;
LAB_0801447c:
        pcVar3 = (code *)**(undefined4 **)(param_1 + 4);
LAB_08014490:
        (*pcVar3)(param_1);
      }
    }
    else {
      if (*(char *)(param_1 + 0x184) != '\x03') goto LAB_0801444c;
      if (cVar1 == '\0') {
        *(undefined1 *)(param_1 + 0x184) = 2;
        *(undefined1 *)(param_1 + 0x189) = 0;
        pcVar3 = *(code **)(*(int *)(param_1 + 4) + 4);
        goto LAB_08014490;
      }
      if (*(char *)(param_1 + 0x189) == cVar1) {
        (**(code **)(*(int *)(param_1 + 4) + 4))(param_1);
        *(char *)(param_1 + 0x189) = *pcVar2;
        goto LAB_0801447c;
      }
    }
    FUN_08013bba(param_1);
  }
  else {
LAB_0801444c:
    FUN_08013bca(param_1);
  }
  return 0;
}


// ===== FUN_080144a0 @ 080144a0

void FUN_080144a0(undefined4 *param_1,uint param_2)

{
  int iVar1;
  
  if ((int)(param_2 << 0x18) < 0) {
    iVar1 = (param_2 & 0x7f) * 0xb + 3;
  }
  else {
    iVar1 = (param_2 & 0x7f) * 0xb + 0x2f;
  }
  FUN_080137ec(*param_1,param_1 + iVar1);
  *(undefined1 *)((int)(param_1 + iVar1) + 0xd) = 1;
  return;
}


// ===== FUN_080144cc @ 080144cc

void FUN_080144cc(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 6);
  return;
}


// ===== FUN_080144f4 @ 080144f4

void FUN_080144f4(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 4) + 0x1c);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x080144fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ===== FUN_08014500 @ 08014500

void FUN_08014500(int *param_1)

{
  if ((*(uint *)(*param_1 + 0x808) & 1) != 0) {
    *(char *)((int)param_1 + 0x185) = (char)param_1[0x61];
    *(undefined1 *)(param_1 + 0x61) = 4;
    FUN_08013dd6(param_1);
    if (*(code **)(param_1[1] + 0x20) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08014532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(param_1[1] + 0x20))(param_1,2);
      return;
    }
  }
  return;
}


// ===== FUN_08014536 @ 08014536

void FUN_08014536(int *param_1)

{
  *(uint *)(*param_1 + 0x804) = *(uint *)(*param_1 + 0x804) & 0xfffffffe;
  FUN_080138c4(*param_1);
  *(undefined1 *)(param_1 + 0x61) = *(undefined1 *)((int)param_1 + 0x185);
  if (*(code **)(param_1[1] + 0x20) == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08014566. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1[1] + 0x20))(param_1,3);
  return;
}


// ===== FUN_0801456c @ 0801456c

void FUN_0801456c(void)

{
  short *psVar1;
  int iVar2;
  
  FUN_08012164();
  psVar1 = DAT_080145a0;
  if (*DAT_080145a0 != 0) {
    FUN_0800f100();
  }
  iVar2 = DAT_080145a4;
  *(char *)(DAT_080145a4 + 0x20) = (char)psVar1[1];
  *(char *)(iVar2 + 0x21) = (char)psVar1[4];
  *(char *)(iVar2 + 0x22) = (char)psVar1[2];
  *(char *)(iVar2 + 0x23) = (char)psVar1[3];
  *(char *)(iVar2 + 0x24) = (char)psVar1[5];
  *(char *)(iVar2 + 0x25) = (char)psVar1[6];
  *(char *)(iVar2 + 0x26) = (char)psVar1[7];
  return;
}


// ===== FUN_080145a8 @ 080145a8

undefined4 FUN_080145a8(undefined4 *param_1,undefined4 *param_2)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 9;
  if (((param_1 != (undefined4 *)0x0) && (pcVar1 = (char *)*param_1, pcVar1 != (char *)0x0)) &&
     (*pcVar1 != '\0')) {
    if ((*(short *)(param_1 + 1) == *(short *)(pcVar1 + 6)) &&
       (uVar2 = FUN_0800a088(pcVar1[1]), (uVar2 & 1) == 0)) {
      uVar4 = 0;
      uVar3 = *param_1;
      goto LAB_080145d0;
    }
  }
  uVar3 = 0;
LAB_080145d0:
  *param_2 = uVar3;
  return uVar4;
}


// ===== FUN_080145dc @ 080145dc

void FUN_080145dc(void)

{
  *(undefined2 *)(DAT_080145f0 + 0xc) = 0;
  *(undefined2 *)(DAT_080145f4 + 2) = 0;
  FUN_080076e8(DAT_080145f8,0x4f0);
  return;
}


// ===== FUN_080145fc @ 080145fc

void FUN_080145fc(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  uVar5 = CONCAT44(param_2,param_1);
  uVar4 = *(undefined4 *)(DAT_08014664 + 8);
  switch(param_1) {
  case 0:
  case 1:
  case 3:
  case 4:
  case 7:
  case 10:
  case 0xb:
switchD_08014606_caseD_0:
    break;
  case 2:
  case 5:
  case 6:
    cVar1 = *(char *)(DAT_08014664 + 0xd);
    if (((cVar1 == '\b') || (cVar1 == '\v')) || (cVar1 == '\x0e')) {
      uVar3 = DAT_08014674;
    }
    else {
      if (((cVar1 != '\t') && (cVar1 != '\f')) && (cVar1 != '\x0f')) goto switchD_08014606_caseD_0;
      uVar3 = DAT_08014668;
    }
    uVar4 = FUN_080158c4(uVar4,uVar3);
    break;
  default:
    goto switchD_08014606_caseD_8;
  }
  uVar5 = FUN_08015548(uVar4);
switchD_08014606_caseD_8:
  iVar2 = DAT_08014670;
  *(undefined8 *)(DAT_0801466c + (uint)*(ushort *)(DAT_08014670 + 2) * 8) = uVar5;
  *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + 1;
  if (0x9d < *(ushort *)(iVar2 + 2)) {
    *(undefined2 *)(iVar2 + 2) = 0;
  }
  return;
}


// ===== FUN_08014678 @ 08014678

void FUN_08014678(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  uVar1 = DAT_080146bc;
  iVar2 = FUN_0800f6e0(DAT_080146bc,DAT_080146b8,0x46);
  FUN_0800f2fc(uVar1,DAT_080146b8 + 0x8c,0x46);
  iVar3 = FUN_08009400(DAT_080146b8,DAT_080146b8 + 0x8c,0x46);
  if ((iVar3 == 1) && (iVar2 == 1)) {
    pcVar4 = s_write_flash_ok_080146d4;
  }
  else {
    pcVar4 = s_write_flash_err_080146c0;
  }
  FUN_08007420(pcVar4);
  return;
}


// ===== FUN_080146e8 @ 080146e8

int FUN_080146e8(byte *param_1,int param_2,byte *param_3,uint *param_4)

{
  byte bVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char cVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  bool bVar17;
  char cVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  uint local_70;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  uint *local_28;
  
  local_70 = 0;
  uVar19 = 0;
  pbVar13 = (byte *)0x0;
  bVar1 = 0;
  *DAT_08014abc = (int)param_1;
  local_28 = param_4;
LAB_08014704:
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
      goto LAB_08014aa2;
    }
    if (bVar3 == 0x25) {
      param_3 = param_3 + 2;
      bVar3 = *pbVar10;
      uVar11 = (uint)bVar3;
      if (uVar11 != 0x25) {
        if (uVar11 == 0x30) {
          uVar15 = 1;
          goto LAB_08014744;
        }
        pbVar10 = param_3;
        if (uVar11 == 0x2d) {
          uVar15 = 2;
          goto LAB_08014744;
        }
        while (uVar11 - 0x30 < 10) {
          uVar14 = (uVar11 + uVar14 * 10) - 0x30 & 0xff;
          param_3 = pbVar10;
LAB_08014744:
          pbVar10 = param_3 + 1;
          uVar11 = (uint)*param_3;
        }
        if (uVar11 == 0x2e) {
          uVar12 = 0;
          pbVar9 = pbVar10;
          while( true ) {
            pbVar10 = pbVar9 + 1;
            uVar11 = (uint)*pbVar9;
            if (9 < uVar11 - 0x30) break;
            uVar12 = (uVar11 + uVar12 * 10) - 0x30 & 0xff;
            pbVar9 = pbVar10;
          }
        }
        param_3 = pbVar10;
        if (uVar11 == 0x6c) {
          param_3 = pbVar10 + 1;
          uVar11 = (uint)*pbVar10;
          uVar15 = uVar15 | 4;
        }
        bVar3 = (byte)uVar11;
        pbVar10 = param_1;
        if (uVar11 == 0) goto LAB_08014aa2;
        if (uVar11 == 0x66) {
          cVar18 = (uint *)0xfffffff8 < local_28;
          puVar6 = (undefined4 *)((uint)((int)local_28 + 7) & 0xfffffff8);
          local_28 = puVar6 + 2;
          uVar16 = *puVar6;
          local_5c = puVar6[1];
          FUN_0801507c(uVar16,local_5c,0,0);
          if (cVar18 == '\0') {
            local_5c = local_5c ^ 0x80000000;
            uVar15 = uVar15 | 0x80;
          }
          uVar19 = CONCAT44(local_5c,uVar16);
          local_58 = (uint)(cVar18 == '\0');
          if (uVar12 != 0) {
            local_58 = local_58 + 1;
          }
          local_70 = FUN_08014fcc(uVar16,local_5c);
          cVar18 = FUN_08014b28();
          bVar3 = cVar18 + (char)uVar12;
LAB_08014838:
          uVar5 = (uint)bVar3;
        }
        else {
          if (0x66 < uVar11) {
            if (uVar11 != 0x73) {
              if ((uVar11 != 0x75) && (uVar11 != 0x78)) goto LAB_080147b2;
              goto LAB_08014826;
            }
            pbVar13 = (byte *)*local_28;
            bVar3 = FUN_08014ae2(pbVar13);
            local_28 = local_28 + 1;
            goto LAB_08014838;
          }
          if (uVar11 == 0x58) {
LAB_08014826:
            local_70 = *local_28;
            if (uVar11 == 0x75) goto LAB_08014820;
            bVar3 = FUN_08014ac4(local_70);
            local_28 = local_28 + 1;
            goto LAB_08014838;
          }
          if (uVar11 != 99) {
            if (uVar11 != 100) goto LAB_080147b2;
            local_70 = *local_28;
            bVar17 = (int)local_70 < 0;
            if (bVar17) {
              local_70 = -local_70;
              uVar15 = uVar15 | 0x80;
            }
            local_58 = (uint)bVar17;
LAB_08014820:
            local_28 = local_28 + 1;
            bVar3 = FUN_08014b28(local_70);
            goto LAB_08014838;
          }
          bVar1 = (byte)*local_28;
          uVar5 = 1;
          local_28 = local_28 + 1;
        }
        local_5c = (uint)((ulonglong)uVar19 >> 0x20);
        local_60 = (undefined4)uVar19;
        if ((-1 < (int)(uVar15 << 0x1e)) && (uVar5 + local_58 < uVar14)) {
          iVar8 = *DAT_08014abc;
          for (uVar4 = 0; (int)uVar4 < (int)(uVar14 - (uVar5 + local_58));
              uVar4 = uVar4 + 1 & 0xffff) {
            if ((uVar15 & 1) == 0) {
              bVar3 = 0x20;
            }
            else {
              bVar3 = 0x30;
            }
            pbVar10 = param_1 + 1;
            *param_1 = bVar3;
            if (((byte *)(iVar8 + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
            param_1 = pbVar10;
          }
        }
        pbVar10 = param_1;
        if (uVar11 == 0x66) {
          if ((int)(uVar15 << 0x18) < 0) {
            pbVar10 = param_1 + 1;
            *param_1 = 0x2d;
            if (((byte *)(*DAT_08014abc + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
          }
          local_70 = FUN_08014fcc(local_60,local_5c);
          uVar11 = uVar5 - uVar12;
          param_1 = pbVar10;
          while ((uVar11 & 0xffff) != 0) {
            uVar11 = (uVar11 & 0xffff) - 1;
            bVar3 = FUN_08014b08(local_70,uVar11 & 0xff);
            pbVar10 = param_1 + 1;
            *param_1 = bVar3;
            param_1 = pbVar10;
            if (((byte *)(*DAT_08014abc + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
          }
          if (uVar12 != 0) {
            *param_1 = 0x2e;
            uVar19 = FUN_08015054(local_70);
            uVar19 = FUN_0801535c((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),local_60,local_5c);
            FUN_08014ad4(10,uVar12);
            uVar20 = FUN_08015026();
            uVar19 = FUN_080150f4((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,
                                  (int)((ulonglong)uVar19 >> 0x20));
            uVar19 = FUN_08014ba4((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,DAT_08014ac0);
            local_70 = FUN_08014fcc();
            piVar2 = DAT_08014abc;
            pbVar9 = param_1 + 1;
            do {
              bVar3 = FUN_08014b08(local_70,uVar12 - 1 & 0xff);
              pbVar10 = pbVar9 + 1;
              *pbVar9 = bVar3;
              if (((byte *)(*piVar2 + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
              uVar12 = uVar12 - 1 & 0xffff;
              param_1 = pbVar10;
              pbVar9 = pbVar10;
            } while (uVar12 != 0);
          }
        }
        else if (uVar11 < 0x67) {
          if (uVar11 == 0x58) {
LAB_0801494a:
            for (uVar12 = uVar5; uVar12 != 0; uVar12 = uVar12 - 1 & 0xffff) {
              uVar4 = uVar12 - 1 & 0xff;
              if (uVar11 == 0x78) {
                uVar4 = FUN_08014ad4(0x10,uVar4);
                uVar4 = local_70 / uVar4 & 0xf;
                cVar18 = (char)uVar4;
                if (uVar4 < 10) goto LAB_08014992;
                cVar7 = 'W';
              }
              else {
                uVar4 = FUN_08014ad4(0x10,uVar4);
                uVar4 = local_70 / uVar4 & 0xf;
                cVar18 = (char)uVar4;
                if (uVar4 < 10) {
LAB_08014992:
                  cVar7 = '0';
                }
                else {
                  cVar7 = '7';
                }
              }
              pbVar10 = param_1 + 1;
              *param_1 = cVar18 + cVar7;
              if (((byte *)(*DAT_08014abc + param_2) <= pbVar10) && (param_2 != 0))
              goto LAB_08014aa2;
              param_1 = pbVar10;
            }
          }
          else if (uVar11 == 99) {
            pbVar10 = param_1 + 1;
            *param_1 = bVar1;
            param_1 = pbVar10;
            if (((byte *)(*DAT_08014abc + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
          }
          else if (uVar11 == 100) goto LAB_08014906;
        }
        else if (uVar11 == 0x73) {
          iVar8 = *DAT_08014abc;
          while( true ) {
            param_1 = pbVar10;
            if (*pbVar13 == 0) break;
            if (((byte *)(iVar8 + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
            *pbVar10 = *pbVar13;
            pbVar13 = pbVar13 + 1;
            pbVar10 = pbVar10 + 1;
          }
        }
        else if (uVar11 == 0x75) {
LAB_08014906:
          if ((int)(uVar15 << 0x18) < 0) {
            pbVar10 = param_1 + 1;
            *param_1 = 0x2d;
            if (((byte *)(*DAT_08014abc + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
          }
          piVar2 = DAT_08014abc;
          param_1 = pbVar10;
          for (uVar12 = uVar5; uVar12 != 0; uVar12 = uVar12 - 1 & 0xffff) {
            bVar3 = FUN_08014b08(local_70,uVar12 - 1 & 0xff);
            pbVar10 = param_1 + 1;
            *param_1 = bVar3;
            if (((byte *)(*piVar2 + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
            param_1 = pbVar10;
          }
        }
        else if (uVar11 == 0x78) goto LAB_0801494a;
        if (((int)(uVar15 << 0x1e) < 0) && (local_58 + uVar5 < uVar14)) {
          iVar8 = *DAT_08014abc;
          for (uVar15 = 0; (int)uVar15 < (int)(uVar14 - (local_58 + uVar5));
              uVar15 = uVar15 + 1 & 0xffff) {
            pbVar10 = param_1 + 1;
            *param_1 = 0x20;
            if (((byte *)(iVar8 + param_2) <= pbVar10) && (param_2 != 0)) goto LAB_08014aa2;
            param_1 = pbVar10;
          }
        }
        goto LAB_08014704;
      }
LAB_080147b2:
      *param_1 = bVar3;
    }
    else {
      *param_1 = bVar3;
      param_3 = pbVar10;
    }
    pbVar10 = param_1 + 1;
    param_1 = pbVar10;
    if (((byte *)(*DAT_08014abc + param_2) <= pbVar10) && (param_2 != 0)) {
LAB_08014aa2:
      return (int)pbVar10 - *DAT_08014abc;
    }
  } while( true );
}


// ===== FUN_08014ac4 @ 08014ac4

int FUN_08014ac4(uint param_1)

{
  int iVar1;
  
  iVar1 = 1;
  for (; 0xf < param_1; param_1 = param_1 >> 4) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// ===== FUN_08014ad4 @ 08014ad4

int FUN_08014ad4(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 1;
  while (bVar2 = param_2 != 0, param_2 = param_2 + -1, bVar2) {
    iVar1 = param_1 * iVar1;
  }
  return iVar1;
}


// ===== FUN_08014ae2 @ 08014ae2

int FUN_08014ae2(char *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while (*param_1 != '\0') {
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  }
  return iVar1;
}


// ===== FUN_08014af4 @ 08014af4

void FUN_08014af4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_080146e8(param_1,0,param_2,&uStack_8);
  return;
}


// ===== FUN_08014b08 @ 08014b08

int FUN_08014b08(uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_08014ad4(10);
  return (param_1 / uVar1) % 10 + 0x30;
}


// ===== FUN_08014b28 @ 08014b28

int FUN_08014b28(uint param_1)

{
  int iVar1;
  
  iVar1 = 1;
  for (; 9 < param_1; param_1 = param_1 / 10) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// ===== FUN_08014b40 @ 08014b40

uint FUN_08014b40(uint param_1,uint param_2)

{
  uint extraout_r1;
  uint uVar1;
  bool bVar2;
  
  uVar1 = (param_2 & 0x7fffffff) + 0xc8000000;
  bVar2 = uVar1 == 0x100000;
  if (0xfffff < uVar1) {
    bVar2 = uVar1 == 0xff00000;
  }
  if ((0xfffff >= uVar1 || 0xff00000 < uVar1) || bVar2) {
    if ((int)uVar1 < 0x100000) {
      return param_2 & 0x80000000;
    }
    if (0xffdfffff < param_2 << 1) {
      FUN_08015248(param_1);
      param_2 = extraout_r1;
    }
    return (param_2 >> 0x17 | 0xff) << 0x17;
  }
  bVar2 = (param_1 & 0x10000000) != 0;
  uVar1 = (param_2 & 0x80000000 | uVar1 * 8) + (param_1 >> 0x1d) + (uint)bVar2;
  if ((param_1 & 0xfffffff) != 0) {
    return uVar1;
  }
  if (bVar2) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  return uVar1;
}


// ===== FUN_08014ba4 @ 08014ba4

/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_08014ba4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    bVar11 = param_3 <= param_1;
    uVar6 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar6);
      param_3 = param_3 + uVar6;
      uVar7 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar7 + bVar12;
      bVar11 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = (param_2 - uVar7) - (uint)bVar11;
    }
    uVar7 = param_2 >> 0x14;
    uVar6 = uVar7 - (param_4 >> 0x14);
    if ((DAT_08015544 & param_4 << 1) == 0 || DAT_08015544 == uVar7 << 0x15) {
      if (DAT_08015544 == uVar7 << 0x15) {
        FUN_08015248();
        do {
          software_interrupt(0x40);
        } while( true );
      }
      if ((param_2 & DAT_08015544 >> 1) == 0) {
        param_2 = 0;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    uVar5 = -param_3;
    uVar1 = param_2 & ~(uVar7 << 0x14);
    iVar8 = ((int)DAT_08015544 >> 1) - (param_4 & ~((int)DAT_08015544 >> 1));
    if (param_3 != 0) {
      iVar8 = iVar8 + -1;
    }
    if (uVar6 < 0x21) {
      uVar2 = uVar5 >> (uVar6 & 0xff);
      uVar9 = param_1 + uVar2;
      uVar1 = uVar1 + (iVar8 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar2);
      uVar10 = iVar8 << (0x20 - uVar6 & 0xff);
      uVar2 = uVar9 + uVar10;
      bVar11 = CARRY4(uVar1,(uint)CARRY4(uVar9,uVar10));
      iVar8 = uVar1 + CARRY4(uVar9,uVar10);
      uVar6 = 0x20 - uVar6;
    }
    else {
      uVar5 = (uint)(param_3 * -2 != 0) | (iVar8 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar6 = uVar6 - 0x20;
      if (0x1d < uVar6) {
        return CONCAT44(uVar1 + uVar7 * 0x100000,param_1);
      }
      uVar9 = iVar8 >> (uVar6 & 0xff);
      uVar2 = param_1 + uVar9;
      bVar11 = uVar1 != 0 || CARRY4(uVar1 - 1,(uint)CARRY4(param_1,uVar9));
      iVar8 = (uVar1 - 1) + (uint)CARRY4(param_1,uVar9);
      uVar6 = 0x1e - uVar6;
    }
    if (-1 < iVar8) {
      iVar4 = uVar5 << (uVar6 & 0xff);
      iVar8 = iVar8 + uVar7 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar8,uVar2);
      }
      uVar2 = uVar2 + 1;
      if (uVar2 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar8,uVar2);
      }
      if (uVar2 == 0) {
        iVar8 = iVar8 + 1;
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar2);
    }
    uVar1 = uVar6 + 1 & 0xff;
    bVar11 = uVar1 == 0 && bVar11 || uVar1 != 0 && (uVar5 << uVar1 - 1 & 0x80000000) != 0;
    uVar9 = uVar2 * 2 + (uint)bVar11;
    uVar6 = iVar8 * 2 + (uint)(CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar11));
    uVar2 = uVar6 + uVar7 * 0x200000;
    bVar11 = (uVar2 >> 0x14 & 1) != 0;
    if (bVar11 && uVar2 >> 0x15 != 0) {
      uVar2 = -((int)(uVar5 << uVar1) >> 0x1f);
      uVar10 = uVar9 + uVar2;
      bVar11 = uVar10 == 0;
      iVar8 = uVar6 + uVar7 * 0x100000;
      if (!CARRY4(uVar9,uVar2)) {
        bVar11 = uVar5 << uVar1 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar8,uVar10);
      }
      if (uVar10 == 0) {
        iVar8 = iVar8 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar10);
    }
    if (bVar11) {
      uVar7 = ((int)uVar6 >> 1) + uVar7 * 0x100000;
      uVar6 = (uint)((uVar6 & 1) != 0) << 0x1f | uVar9 >> 1;
      if (uVar7 * 2 == 0 && uVar6 == 0) {
        return (ulonglong)uVar6;
      }
      if (uVar7 * 2 < 0x200000) {
        return (ulonglong)(uVar7 & 0x80000000) << 0x20;
      }
      return CONCAT44(uVar7,uVar6);
    }
    iVar8 = uVar6 + 0x200000;
    if (iVar8 == 0) {
      uVar6 = uVar9 << LZCOUNT(uVar9);
      if (uVar6 == 0) {
        return (ulonglong)uVar9;
      }
      iVar4 = ((uVar7 & 0xfffff7ff) - LZCOUNT(uVar9)) + -0x17;
      iVar8 = uVar6 << 0x15;
      uVar6 = uVar6 >> 0xb;
    }
    else {
      uVar5 = LZCOUNT(iVar8) - 0xb;
      iVar4 = ((uVar7 & 0xfffff7ff) - uVar5) + -2;
      uVar6 = iVar8 << (uVar5 & 0xff) | uVar9 >> (0x20 - uVar5 & 0xff);
      iVar8 = uVar9 << (uVar5 & 0xff);
    }
    iVar3 = uVar6 + (param_2 & 0x80000000) + iVar4 * 0x100000;
    if (iVar4 < 0) {
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    return CONCAT44(iVar3,iVar8);
  }
  uVar6 = param_1 - param_3;
  iVar8 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + iVar8 + (uint)bVar11;
    bVar11 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = (param_2 - iVar8) - (uint)bVar11;
  }
  uVar7 = param_2 >> 0x14;
  uVar6 = uVar7 - (param_4 >> 0x14);
  if ((DAT_08014cf0 & param_4 << 1) == 0 || DAT_08014cf0 == uVar7 << 0x15) {
    if (DAT_08014cf0 == uVar7 << 0x15) {
      FUN_08015248();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((param_2 & DAT_08014cf0 >> 1) == 0) {
      param_2 = param_2 & 0x80000000;
      param_1 = 0;
    }
    return CONCAT44(param_2,param_1);
  }
  param_2 = param_2 & ~(uVar7 << 0x14);
  uVar5 = param_4 & ~DAT_08014cf0 | 0x100000;
  if (uVar6 < 0x21) {
    uVar9 = param_3 >> (uVar6 & 0xff);
    uVar1 = param_1 + uVar9;
    uVar10 = uVar5 << (0x20 - uVar6 & 0xff);
    uVar2 = uVar1 + uVar10;
    param_2 = param_2 + (uVar5 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar9) +
              (uint)CARRY4(uVar1,uVar10);
    uVar6 = 0x20 - uVar6;
    if (param_2 < 0x100000) {
      param_2 = param_2 + uVar7 * 0x100000;
      goto LAB_08014c20;
    }
LAB_08014c82:
    bVar13 = (byte)uVar2 & 1;
    uVar5 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar2 >> 1;
    param_2 = (param_2 + 0x100000 >> 1) + uVar7 * 0x100000;
    if ((uVar2 & 1) == 0) {
LAB_08014cb0:
      if (param_2 * 2 < 0xffe00000) {
        return CONCAT44(param_2,uVar5);
      }
      goto LAB_080152e4;
    }
    bVar11 = CARRY4(uVar5,(uint)bVar13);
    uVar5 = uVar5 + bVar13;
    uVar7 = uVar5;
    if (!bVar11) {
      uVar7 = param_3 << (uVar6 & 0xff);
    }
    if (uVar7 != 0) goto LAB_08014cb0;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar1 = uVar6 - 0x20;
    uVar6 = 0x1f - uVar1;
    if (uVar1 < 0x20) {
      uVar5 = uVar5 >> (uVar1 & 0xff);
      uVar2 = param_1 + uVar5;
    }
    else {
      uVar6 = 0;
      uVar2 = param_1;
    }
    param_2 = param_2 + uVar7 * 0x100000 + (uint)(uVar1 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar7 != param_2 >> 0x14) {
      param_2 = param_2 + uVar7 * -0x100000;
      goto LAB_08014c82;
    }
LAB_08014c20:
    param_3 = param_3 << (uVar6 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(param_2,uVar2);
    }
    uVar5 = uVar2 + 1;
    uVar6 = uVar5;
    if (uVar2 != 0xffffffff) {
      uVar6 = param_3 & 0x7fffffff;
    }
    if (uVar6 != 0) {
      return CONCAT44(param_2,uVar5);
    }
  }
  if (uVar5 == 0) {
    param_2 = param_2 + 1;
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar5);
  }
LAB_080152e4:
  return (ulonglong)((uint)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_08014d1c @ 08014d1c

longlong FUN_08014d1c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint unaff_lr;
  uint uVar12;
  bool bVar13;
  
  if ((DAT_08014fc4 & ~(param_2 >> 4)) == 0 || (DAT_08014fc4 & ~(param_4 >> 4)) == 0) {
    FUN_08015248();
    param_2 = extraout_r3;
  }
  else {
    uVar7 = param_2 ^ param_4;
    uVar4 = DAT_08014fc4 & param_2 >> 4;
    bVar13 = uVar4 == 0;
    uVar6 = uVar7 >> 0x1f;
    if (!bVar13) {
      uVar7 = DAT_08014fc4 & param_4 >> 4;
      bVar13 = uVar7 == 0;
    }
    if (bVar13) {
      if ((param_2 & DAT_08014fc4 << 4) == 0) {
        if ((param_4 & DAT_08014fc4 << 4) == 0) {
          return (ulonglong)DAT_08014fc8 << 0x20;
        }
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
      param_2 = param_2 ^ param_4;
    }
    else {
      iVar5 = (uVar4 | uVar6) - uVar7;
      uVar7 = param_4 << 0xb | 0x80000000;
      uVar4 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
      uVar3 = uVar7 | param_3 >> 0x15;
      uVar6 = iVar5 + 0x3fe0000;
      if (uVar4 == uVar3 && param_1 * 0x800 == param_3 * 0x800) {
        uVar4 = 0x100000;
        uVar3 = 0;
      }
      else {
        uVar9 = (uint)*(byte *)((uVar7 >> 0x18) + 0x8014ec4);
        uVar9 = uVar9 * (0x1000000 - uVar9 * (uVar7 >> 0x10)) >> 0xf;
        iVar10 = (int)((ulonglong)uVar9 * (ulonglong)uVar3);
        iVar8 = -(int)((ulonglong)uVar9 * (ulonglong)uVar3 >> 0x20);
        iVar11 = iVar8 + 0x10000;
        if (iVar10 != 0) {
          iVar11 = iVar8 + 0xffff;
        }
        uVar9 = uVar9 * iVar11 + (int)((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        lVar1 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(param_3 * 0x800) >> 0x20);
        iVar10 = (int)lVar1;
        iVar8 = -(int)((ulonglong)lVar1 >> 0x20);
        uVar3 = iVar8 + 0x80000000;
        if (iVar10 != 0) {
          uVar3 = iVar8 + 0x7fffffff;
        }
        uVar2 = (ulonglong)uVar9 * (ulonglong)uVar3 +
                ((ulonglong)uVar9 * (ulonglong)(uint)-iVar10 >> 0x20);
        uVar9 = (uint)(uVar2 >> 0x20);
        uVar3 = (uint)((ulonglong)uVar4 * (uVar2 & 0xffffffff) >> 0x20);
        uVar12 = (uint)((ulonglong)(param_1 * 0x800) * (ulonglong)uVar9 >> 0x20);
        uVar2 = (ulonglong)uVar4 * (ulonglong)uVar9 +
                (ulonglong)CONCAT14(CARRY4(uVar3,uVar12),uVar3 + uVar12);
        iVar8 = (int)(uVar2 >> 0x20);
        unaff_lr = iVar8 + 0x70000000;
        if (!SCARRY4(iVar8,0x70000000)) {
          uVar6 = iVar5 + 0x3fd0000;
          uVar2 = CONCAT44(iVar8 * 2 + (uint)((uVar2 & 0x80000000) != 0),(int)uVar2 << 1);
        }
        uVar4 = (uint)(uVar2 + 0x80 >> 0x20);
        uVar3 = (uint)(uVar2 + 0x80) >> 8 | uVar4 * 0x1000000;
        uVar4 = uVar4 >> 8;
        if ((int)uVar2 * 0x1000000 + 0x91000000U < 0x10000001) {
          uVar9 = param_3 & 0x1fffff | (param_3 >> 0x15) << 0x15;
          iVar5 = uVar4 * uVar9 +
                  uVar3 * (uVar7 >> 0xb) + (int)((ulonglong)uVar3 * (ulonglong)uVar9 >> 0x20);
          if (-1 < (int)unaff_lr) {
            iVar5 = iVar5 + param_1 * -0x100000;
          }
          unaff_lr = iVar5 + param_1 * -0x100000 +
                     (uVar7 >> 0xc) +
                     (uint)CARRY4((uint)((ulonglong)uVar3 * (ulonglong)uVar9),
                                  uVar9 >> 1 | (uVar7 >> 0xb) << 0x1f);
          if ((int)unaff_lr < 0) {
            bVar13 = 0xfffffffe < uVar3;
            uVar3 = uVar3 + 1;
            uVar4 = uVar4 + bVar13;
          }
        }
      }
      iVar5 = uVar4 + uVar6 * -0x80000000 + (uVar6 & 0xfffffffe) * 0x10;
      if ((uVar6 & 0xfffffffe) < 0x7f00001) {
        return CONCAT44(iVar5,uVar3);
      }
      if (-1 < (int)uVar6) {
        unaff_lr = iVar5 + 0x100000;
      }
      if (-1 < (int)uVar6 && -1 < (int)(unaff_lr ^ uVar6 << 0x1f)) {
        return CONCAT44(iVar5,uVar3);
      }
      if ((int)uVar6 < 0) {
        return (ulonglong)(iVar5 + 0x60000000U & 0x80000000) << 0x20;
      }
      param_2 = iVar5 + 0xa0000000;
    }
  }
  return (ulonglong)((uint)((int)param_2 < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_08014fcc @ 08014fcc

uint FUN_08014fcc(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  uint uVar3;
  bool bVar4;
  
  iVar1 = (param_2 >> 0x14) - 0x400;
  bVar4 = SBORROW4(0x1e,iVar1);
  uVar2 = -iVar1 + 0x1e;
  uVar3 = uVar2;
  if (iVar1 < 0x1f) {
    bVar4 = SBORROW4(0x20,uVar2);
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
  FUN_08015248(param_1);
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== FUN_08015026 @ 08015026

undefined8 FUN_08015026(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  return CONCAT44(uVar2 + (0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
}


// ===== FUN_08015054 @ 08015054

undefined8 FUN_08015054(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  return CONCAT44((0x41d - LZCOUNT(param_1)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
}


// ===== FUN_0801507c @ 0801507c

void FUN_0801507c(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
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
  }
  else {
    bVar3 = SCARRY4(uVar1,0x100000);
    bVar2 = -1 < (int)(uVar1 + 0x100000);
    if (bVar2) {
      bVar3 = SBORROW4(uVar1,0x100000);
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
  FUN_08015248();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_080150f4 @ 080150f4

longlong FUN_080150f4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  int extraout_r1;
  int iVar7;
  uint uVar8;
  uint extraout_r3;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  
  uVar13 = DAT_08015240 & param_2 >> 4;
  bVar16 = uVar13 == 0;
  if (!bVar16) {
    unaff_r5 = DAT_08015240 & param_4 >> 4;
    bVar16 = unaff_r5 == 0;
  }
  if (!bVar16) {
    bVar16 = uVar13 == DAT_08015240;
  }
  if (!bVar16) {
    bVar16 = unaff_r5 == DAT_08015240;
  }
  if (bVar16) {
    if (uVar13 != DAT_08015240 && (DAT_08015240 & param_4 >> 4) != DAT_08015240) {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    FUN_08015248();
    uVar13 = extraout_r1 << 2 ^ extraout_r3;
  }
  else {
    uVar6 = param_2 & ~(DAT_08015240 << 5) | 0x100000;
    uVar8 = param_4 & ~(DAT_08015240 << 5) | 0x100000;
    iVar14 = (uVar13 | (param_2 ^ param_4) >> 0x1f) + unaff_r5;
    lVar1 = (ulonglong)uVar6 * (ulonglong)param_3;
    uVar11 = (uint)((ulonglong)lVar1 >> 0x20);
    lVar2 = (ulonglong)param_1 * (ulonglong)uVar8;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    iVar15 = iVar14 + -0x3fc0000;
    lVar4 = lVar1 + lVar2;
    uVar10 = (uint)((ulonglong)lVar4 >> 0x20);
    lVar3 = (ulonglong)uVar6 * (ulonglong)uVar8;
    uVar13 = (uint)lVar3;
    uVar12 = (uint)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
    lVar5 = lVar4 + CONCAT44(uVar13,uVar12);
    uVar8 = (uint)lVar5;
    uVar6 = (uint)((ulonglong)lVar5 >> 0x20);
    uVar13 = (int)((ulonglong)lVar3 >> 0x20) +
             (uint)(CARRY4(uVar9,uVar11) ||
                   CARRY4(uVar9 + uVar11,(uint)CARRY4((uint)lVar2,(uint)lVar1))) +
             (uint)(CARRY4(uVar10,uVar13) ||
                   CARRY4(uVar10 + uVar13,(uint)CARRY4((uint)lVar4,uVar12)));
    if ((int)((ulonglong)param_1 * (ulonglong)param_3) != 0) {
      uVar8 = uVar8 | 1;
    }
    if ((uVar13 & 0x200) == 0) {
      uVar9 = uVar8 << 0xc;
      uVar13 = uVar13 * 0x1000 | uVar6 >> 0x14;
      uVar6 = uVar6 * 0x1000 | uVar8 >> 0x14;
      iVar7 = -4;
    }
    else {
      uVar9 = uVar8 << 0xb;
      uVar13 = uVar13 * 0x800 | uVar6 >> 0x15;
      uVar6 = uVar6 * 0x800 | uVar8 >> 0x15;
      iVar7 = -3;
    }
    uVar8 = iVar7 + (iVar15 >> 0x10);
    uVar13 = uVar13 + uVar8 * 0x100000 ^ iVar14 * -0x80000000;
    if (uVar9 != 0) {
      bVar16 = (uVar9 & 0x80000000) != 0;
      if ((uVar9 & 0x7fffffff) != 0) {
        uVar9 = 0;
      }
      uVar13 = uVar13 + CARRY4(uVar6,(uint)bVar16);
      uVar6 = uVar6 + bVar16 & ~(uVar9 >> 0x1f);
    }
    if (uVar8 < 0x7fe) {
      return CONCAT44(uVar13,uVar6);
    }
    if (iVar15 < 0x4000000) {
      return (ulonglong)(uVar13 + 0x60000000 & 0x80000000) << 0x20;
    }
    uVar13 = uVar13 + 0xa0000000;
  }
  return (ulonglong)((uint)((int)uVar13 < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_08015248 @ 08015248

int FUN_08015248(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r5;
  uint uVar2;
  uint uVar3;
  int unaff_lr;
  uint *puVar4;
  bool bVar5;
  
  puVar4 = (uint *)(unaff_lr + 2U & 0xfffffffc);
  uVar2 = *puVar4;
  if ((((int)uVar2 < 0) || (unaff_r5 = param_4 * 2 + (uint)(param_3 != 0), unaff_r5 < 0xffe00001))
     && (uVar3 = param_2 * 2 + (uint)(param_1 != 0), uVar3 < 0xffe00001)) {
    if (uVar3 == 0xffe00000) {
      uVar3 = ((int)param_2 >> 0x1f) * -3 + 2;
      if (unaff_r5 == 0xffe00000) {
        uVar3 = uVar3 + (1 - ((int)param_4 >> 0x1f));
      }
    }
    else {
      uVar3 = param_4 >> 0x1f;
    }
  }
  else {
    uVar3 = 8;
  }
  uVar2 = uVar2 >> (uVar3 * 3 & 0xff) & 7;
  switch(uVar2) {
  case 4:
    param_1 = param_3;
    param_2 = param_4;
switchD_080152b4_caseD_5:
    bVar5 = CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)(param_1 != 0));
    uVar2 = param_2 * 2 + (uint)(param_1 != 0);
    if (uVar2 != 0) {
      bVar5 = uVar2 < 0x200001;
    }
    if (bVar5 && (uVar2 != 0 && uVar2 != 0x200000)) {
      param_1 = 0;
    }
    return param_1;
  case 5:
    goto switchD_080152b4_caseD_5;
  case 6:
  case 7:
    return 0;
  default:
                    /* WARNING: Could not recover jumptable at 0x080152b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(puVar4 + uVar2 + 1))();
    return iVar1;
  }
}


// ===== FUN_080152f0 @ 080152f0

void FUN_080152f0(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
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
  }
  else {
    bVar3 = SCARRY4(uVar1,0x100000);
    bVar2 = -1 < (int)(uVar1 + 0x100000);
    if (bVar2) {
      bVar3 = SBORROW4(uVar1,0x100000);
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
  FUN_08015248(param_3,param_4,param_1,param_2);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0801535c @ 0801535c

/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_0801535c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  byte bVar14;
  
  uVar2 = param_2 ^ 0x80000000;
  if (-1 < (int)(param_2 ^ param_4)) {
    param_4 = param_4 ^ 0x80000000;
    bVar12 = param_3 <= param_1;
    uVar8 = param_1 - param_3;
    if (uVar2 <= param_4 && (uint)bVar12 <= uVar2 - param_4) {
      bVar13 = CARRY4(param_3,uVar8);
      param_3 = param_3 + uVar8;
      uVar9 = (uVar2 - param_4) - (uint)!bVar12 ^ 0x80000000;
      param_4 = param_4 + uVar9 + bVar13;
      bVar12 = param_1 < uVar8;
      param_1 = param_1 - uVar8;
      uVar2 = (uVar2 - uVar9) - (uint)bVar12;
    }
    uVar9 = uVar2 >> 0x14;
    uVar8 = uVar9 - (param_4 >> 0x14);
    if ((DAT_08015544 & param_4 << 1) == 0 || DAT_08015544 == uVar9 << 0x15) {
      if (DAT_08015544 == uVar9 << 0x15) {
        FUN_08015248();
        do {
          software_interrupt(0x40);
        } while( true );
      }
      if ((uVar2 & DAT_08015544 >> 1) == 0) {
        uVar2 = 0;
        param_1 = 0;
      }
      return CONCAT44(uVar2,param_1);
    }
    uVar6 = -param_3;
    uVar3 = uVar2 & ~(uVar9 << 0x14);
    iVar7 = ((int)DAT_08015544 >> 1) - (param_4 & ~((int)DAT_08015544 >> 1));
    if (param_3 != 0) {
      iVar7 = iVar7 + -1;
    }
    if (uVar8 < 0x21) {
      uVar10 = uVar6 >> (uVar8 & 0xff);
      uVar1 = param_1 + uVar10;
      uVar3 = uVar3 + (iVar7 >> (uVar8 & 0xff)) + (uint)CARRY4(param_1,uVar10);
      uVar11 = iVar7 << (0x20 - uVar8 & 0xff);
      uVar10 = uVar1 + uVar11;
      bVar12 = CARRY4(uVar3,(uint)CARRY4(uVar1,uVar11));
      iVar7 = uVar3 + CARRY4(uVar1,uVar11);
      uVar8 = 0x20 - uVar8;
    }
    else {
      uVar6 = (uint)(param_3 * -2 != 0) | (iVar7 * 2 + (uint)CARRY4(uVar6,uVar6)) * 2;
      uVar8 = uVar8 - 0x20;
      if (0x1d < uVar8) {
        return CONCAT44(uVar3 + uVar9 * 0x100000,param_1);
      }
      uVar1 = iVar7 >> (uVar8 & 0xff);
      uVar10 = param_1 + uVar1;
      bVar12 = uVar3 != 0 || CARRY4(uVar3 - 1,(uint)CARRY4(param_1,uVar1));
      iVar7 = (uVar3 - 1) + (uint)CARRY4(param_1,uVar1);
      uVar8 = 0x1e - uVar8;
    }
    if (-1 < iVar7) {
      iVar5 = uVar6 << (uVar8 & 0xff);
      iVar7 = iVar7 + uVar9 * 0x100000;
      if (-1 < iVar5) {
        return CONCAT44(iVar7,uVar10);
      }
      uVar10 = uVar10 + 1;
      if (uVar10 != 0 && iVar5 != -0x80000000) {
        return CONCAT44(iVar7,uVar10);
      }
      if (uVar10 == 0) {
        iVar7 = iVar7 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar7,uVar10);
    }
    uVar3 = uVar8 + 1 & 0xff;
    bVar12 = uVar3 == 0 && bVar12 || uVar3 != 0 && (uVar6 << uVar3 - 1 & 0x80000000) != 0;
    uVar1 = uVar10 * 2 + (uint)bVar12;
    uVar8 = iVar7 * 2 + (uint)(CARRY4(uVar10,uVar10) || CARRY4(uVar10 * 2,(uint)bVar12));
    uVar10 = uVar8 + uVar9 * 0x200000;
    bVar12 = (uVar10 >> 0x14 & 1) != 0;
    if (bVar12 && uVar10 >> 0x15 != 0) {
      uVar2 = -((int)(uVar6 << uVar3) >> 0x1f);
      uVar10 = uVar1 + uVar2;
      bVar12 = uVar10 == 0;
      iVar7 = uVar8 + uVar9 * 0x100000;
      if (!CARRY4(uVar1,uVar2)) {
        bVar12 = uVar6 << uVar3 == -0x80000000;
      }
      if (!bVar12) {
        return CONCAT44(iVar7,uVar10);
      }
      if (uVar10 == 0) {
        iVar7 = iVar7 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar7,uVar10);
    }
    if (bVar12) {
      uVar9 = ((int)uVar8 >> 1) + uVar9 * 0x100000;
      uVar2 = (uint)((uVar8 & 1) != 0) << 0x1f | uVar1 >> 1;
      if (uVar9 * 2 == 0 && uVar2 == 0) {
        return (ulonglong)uVar2;
      }
      if (uVar9 * 2 < 0x200000) {
        return (ulonglong)(uVar9 & 0x80000000) << 0x20;
      }
      return CONCAT44(uVar9,uVar2);
    }
    iVar7 = uVar8 + 0x200000;
    if (iVar7 == 0) {
      uVar8 = uVar1 << LZCOUNT(uVar1);
      if (uVar8 == 0) {
        return (ulonglong)uVar1;
      }
      iVar5 = ((uVar9 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
      iVar7 = uVar8 << 0x15;
      uVar8 = uVar8 >> 0xb;
    }
    else {
      uVar6 = LZCOUNT(iVar7) - 0xb;
      iVar5 = ((uVar9 & 0xfffff7ff) - uVar6) + -2;
      uVar8 = iVar7 << (uVar6 & 0xff) | uVar1 >> (0x20 - uVar6 & 0xff);
      iVar7 = uVar1 << (uVar6 & 0xff);
    }
    iVar4 = uVar8 + (uVar2 & 0x80000000) + iVar5 * 0x100000;
    if (iVar5 < 0) {
      return (ulonglong)(iVar4 + 0x60000000U & 0x80000000) << 0x20;
    }
    return CONCAT44(iVar4,iVar7);
  }
  uVar8 = param_1 - param_3;
  iVar7 = (uVar2 - param_4) - (uint)(param_3 > param_1);
  if (uVar2 <= param_4 && (uint)(param_3 <= param_1) <= uVar2 - param_4) {
    bVar12 = CARRY4(param_3,uVar8);
    param_3 = param_3 + uVar8;
    param_4 = param_4 + iVar7 + (uint)bVar12;
    bVar12 = param_1 < uVar8;
    param_1 = param_1 - uVar8;
    uVar2 = (uVar2 - iVar7) - (uint)bVar12;
  }
  uVar9 = uVar2 >> 0x14;
  uVar8 = uVar9 - (param_4 >> 0x14);
  if ((DAT_08014cf0 & param_4 << 1) == 0 || DAT_08014cf0 == uVar9 << 0x15) {
    if (DAT_08014cf0 == uVar9 << 0x15) {
      FUN_08015248();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((uVar2 & DAT_08014cf0 >> 1) == 0) {
      uVar2 = uVar2 & 0x80000000;
      param_1 = 0;
    }
    return CONCAT44(uVar2,param_1);
  }
  uVar2 = uVar2 & ~(uVar9 << 0x14);
  uVar6 = param_4 & ~DAT_08014cf0 | 0x100000;
  if (uVar8 < 0x21) {
    uVar1 = param_3 >> (uVar8 & 0xff);
    uVar3 = param_1 + uVar1;
    uVar11 = uVar6 << (0x20 - uVar8 & 0xff);
    uVar10 = uVar3 + uVar11;
    uVar2 = uVar2 + (uVar6 >> (uVar8 & 0xff)) + (uint)CARRY4(param_1,uVar1) +
            (uint)CARRY4(uVar3,uVar11);
    uVar8 = 0x20 - uVar8;
    if (uVar2 < 0x100000) {
      uVar2 = uVar2 + uVar9 * 0x100000;
      goto LAB_08014c20;
    }
LAB_08014c82:
    bVar14 = (byte)uVar10 & 1;
    uVar6 = (uint)((uVar2 + 0x100000 & 1) != 0) << 0x1f | uVar10 >> 1;
    uVar2 = (uVar2 + 0x100000 >> 1) + uVar9 * 0x100000;
    if ((uVar10 & 1) == 0) {
LAB_08014cb0:
      if (uVar2 * 2 < 0xffe00000) {
        return CONCAT44(uVar2,uVar6);
      }
      goto LAB_080152e4;
    }
    bVar12 = CARRY4(uVar6,(uint)bVar14);
    uVar6 = uVar6 + bVar14;
    uVar9 = uVar6;
    if (!bVar12) {
      uVar9 = param_3 << (uVar8 & 0xff);
    }
    if (uVar9 != 0) goto LAB_08014cb0;
  }
  else {
    param_3 = uVar6 * 2 + (uint)(param_3 != 0);
    uVar3 = uVar8 - 0x20;
    uVar8 = 0x1f - uVar3;
    if (uVar3 < 0x20) {
      uVar6 = uVar6 >> (uVar3 & 0xff);
      uVar10 = param_1 + uVar6;
    }
    else {
      uVar8 = 0;
      uVar10 = param_1;
    }
    uVar2 = uVar2 + uVar9 * 0x100000 + (uint)(uVar3 < 0x20 && CARRY4(param_1,uVar6));
    if (uVar9 != uVar2 >> 0x14) {
      uVar2 = uVar2 + uVar9 * -0x100000;
      goto LAB_08014c82;
    }
LAB_08014c20:
    param_3 = param_3 << (uVar8 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(uVar2,uVar10);
    }
    uVar6 = uVar10 + 1;
    uVar8 = uVar6;
    if (uVar10 != 0xffffffff) {
      uVar8 = param_3 & 0x7fffffff;
    }
    if (uVar8 != 0) {
      return CONCAT44(uVar2,uVar6);
    }
  }
  if (uVar6 == 0) {
    uVar2 = uVar2 + 1;
    uVar6 = 0;
  }
  else {
    uVar6 = uVar6 & 0xfffffffe;
  }
  if (uVar2 << 1 < 0xffe00000) {
    return CONCAT44(uVar2,uVar6);
  }
LAB_080152e4:
  return (ulonglong)((uint)((int)(uVar2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_08015374 @ 08015374

/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_08015374(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  
  if (-1 < (int)(param_2 ^ param_4)) {
    bVar11 = param_3 <= param_1;
    uVar7 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar7);
      param_3 = param_3 + uVar7;
      uVar8 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar8 + bVar12;
      bVar11 = param_1 < uVar7;
      param_1 = param_1 - uVar7;
      param_2 = (param_2 - uVar8) - (uint)bVar11;
    }
    uVar8 = param_2 >> 0x14;
    uVar7 = uVar8 - (param_4 >> 0x14);
    if ((DAT_08015544 & param_4 << 1) == 0 || DAT_08015544 == uVar8 << 0x15) {
      if (DAT_08015544 == uVar8 << 0x15) {
        FUN_08015248();
        do {
          software_interrupt(0x40);
        } while( true );
      }
      if ((param_2 & DAT_08015544 >> 1) == 0) {
        param_2 = 0;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    uVar5 = -param_3;
    uVar2 = param_2 & ~(uVar8 << 0x14);
    iVar6 = ((int)DAT_08015544 >> 1) - (param_4 & ~((int)DAT_08015544 >> 1));
    if (param_3 != 0) {
      iVar6 = iVar6 + -1;
    }
    if (uVar7 < 0x21) {
      uVar9 = uVar5 >> (uVar7 & 0xff);
      uVar1 = param_1 + uVar9;
      uVar2 = uVar2 + (iVar6 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar9);
      uVar10 = iVar6 << (0x20 - uVar7 & 0xff);
      uVar9 = uVar1 + uVar10;
      bVar11 = CARRY4(uVar2,(uint)CARRY4(uVar1,uVar10));
      iVar6 = uVar2 + CARRY4(uVar1,uVar10);
      uVar7 = 0x20 - uVar7;
    }
    else {
      uVar5 = (uint)(param_3 * -2 != 0) | (iVar6 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar7 = uVar7 - 0x20;
      if (0x1d < uVar7) {
        return CONCAT44(uVar2 + uVar8 * 0x100000,param_1);
      }
      uVar1 = iVar6 >> (uVar7 & 0xff);
      uVar9 = param_1 + uVar1;
      bVar11 = uVar2 != 0 || CARRY4(uVar2 - 1,(uint)CARRY4(param_1,uVar1));
      iVar6 = (uVar2 - 1) + (uint)CARRY4(param_1,uVar1);
      uVar7 = 0x1e - uVar7;
    }
    if (-1 < iVar6) {
      iVar4 = uVar5 << (uVar7 & 0xff);
      iVar6 = iVar6 + uVar8 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar6,uVar9);
      }
      uVar9 = uVar9 + 1;
      if (uVar9 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar6,uVar9);
      }
      if (uVar9 == 0) {
        iVar6 = iVar6 + 1;
        uVar9 = 0;
      }
      else {
        uVar9 = uVar9 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar9);
    }
    uVar2 = uVar7 + 1 & 0xff;
    bVar11 = uVar2 == 0 && bVar11 || uVar2 != 0 && (uVar5 << uVar2 - 1 & 0x80000000) != 0;
    uVar1 = uVar9 * 2 + (uint)bVar11;
    uVar7 = iVar6 * 2 + (uint)(CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)bVar11));
    uVar9 = uVar7 + uVar8 * 0x200000;
    bVar11 = (uVar9 >> 0x14 & 1) != 0;
    if (bVar11 && uVar9 >> 0x15 != 0) {
      uVar9 = -((int)(uVar5 << uVar2) >> 0x1f);
      uVar10 = uVar1 + uVar9;
      bVar11 = uVar10 == 0;
      iVar6 = uVar7 + uVar8 * 0x100000;
      if (!CARRY4(uVar1,uVar9)) {
        bVar11 = uVar5 << uVar2 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar6,uVar10);
      }
      if (uVar10 == 0) {
        iVar6 = iVar6 + 1;
        uVar10 = 0;
      }
      else {
        uVar10 = uVar10 & 0xfffffffe;
      }
      return CONCAT44(iVar6,uVar10);
    }
    if (bVar11) {
      uVar8 = ((int)uVar7 >> 1) + uVar8 * 0x100000;
      uVar7 = (uint)((uVar7 & 1) != 0) << 0x1f | uVar1 >> 1;
      if (uVar8 * 2 == 0 && uVar7 == 0) {
        return (ulonglong)uVar7;
      }
      if (uVar8 * 2 < 0x200000) {
        return (ulonglong)(uVar8 & 0x80000000) << 0x20;
      }
      return CONCAT44(uVar8,uVar7);
    }
    iVar6 = uVar7 + 0x200000;
    if (iVar6 == 0) {
      uVar7 = uVar1 << LZCOUNT(uVar1);
      if (uVar7 == 0) {
        return (ulonglong)uVar1;
      }
      iVar4 = ((uVar8 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
      iVar6 = uVar7 << 0x15;
      uVar7 = uVar7 >> 0xb;
    }
    else {
      uVar5 = LZCOUNT(iVar6) - 0xb;
      iVar4 = ((uVar8 & 0xfffff7ff) - uVar5) + -2;
      uVar7 = iVar6 << (uVar5 & 0xff) | uVar1 >> (0x20 - uVar5 & 0xff);
      iVar6 = uVar1 << (uVar5 & 0xff);
    }
    iVar3 = uVar7 + (param_2 & 0x80000000) + iVar4 * 0x100000;
    if (iVar4 < 0) {
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    return CONCAT44(iVar3,iVar6);
  }
  param_4 = param_4 ^ 0x80000000;
  uVar7 = param_1 - param_3;
  iVar6 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar7);
    param_3 = param_3 + uVar7;
    param_4 = param_4 + iVar6 + (uint)bVar11;
    bVar11 = param_1 < uVar7;
    param_1 = param_1 - uVar7;
    param_2 = (param_2 - iVar6) - (uint)bVar11;
  }
  uVar8 = param_2 >> 0x14;
  uVar7 = uVar8 - (param_4 >> 0x14);
  if ((DAT_08014cf0 & param_4 << 1) == 0 || DAT_08014cf0 == uVar8 << 0x15) {
    if (DAT_08014cf0 == uVar8 << 0x15) {
      FUN_08015248();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((param_2 & DAT_08014cf0 >> 1) == 0) {
      param_2 = param_2 & 0x80000000;
      param_1 = 0;
    }
    return CONCAT44(param_2,param_1);
  }
  param_2 = param_2 & ~(uVar8 << 0x14);
  uVar5 = param_4 & ~DAT_08014cf0 | 0x100000;
  if (uVar7 < 0x21) {
    uVar1 = param_3 >> (uVar7 & 0xff);
    uVar2 = param_1 + uVar1;
    uVar10 = uVar5 << (0x20 - uVar7 & 0xff);
    uVar9 = uVar2 + uVar10;
    param_2 = param_2 + (uVar5 >> (uVar7 & 0xff)) + (uint)CARRY4(param_1,uVar1) +
              (uint)CARRY4(uVar2,uVar10);
    uVar7 = 0x20 - uVar7;
    if (param_2 < 0x100000) {
      param_2 = param_2 + uVar8 * 0x100000;
      goto LAB_08014c20;
    }
LAB_08014c82:
    bVar13 = (byte)uVar9 & 1;
    uVar5 = (uint)((param_2 + 0x100000 & 1) != 0) << 0x1f | uVar9 >> 1;
    param_2 = (param_2 + 0x100000 >> 1) + uVar8 * 0x100000;
    if ((uVar9 & 1) == 0) {
LAB_08014cb0:
      if (param_2 * 2 < 0xffe00000) {
        return CONCAT44(param_2,uVar5);
      }
      goto LAB_080152e4;
    }
    bVar11 = CARRY4(uVar5,(uint)bVar13);
    uVar5 = uVar5 + bVar13;
    uVar8 = uVar5;
    if (!bVar11) {
      uVar8 = param_3 << (uVar7 & 0xff);
    }
    if (uVar8 != 0) goto LAB_08014cb0;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar2 = uVar7 - 0x20;
    uVar7 = 0x1f - uVar2;
    if (uVar2 < 0x20) {
      uVar5 = uVar5 >> (uVar2 & 0xff);
      uVar9 = param_1 + uVar5;
    }
    else {
      uVar7 = 0;
      uVar9 = param_1;
    }
    param_2 = param_2 + uVar8 * 0x100000 + (uint)(uVar2 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar8 != param_2 >> 0x14) {
      param_2 = param_2 + uVar8 * -0x100000;
      goto LAB_08014c82;
    }
LAB_08014c20:
    param_3 = param_3 << (uVar7 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(param_2,uVar9);
    }
    uVar5 = uVar9 + 1;
    uVar7 = uVar5;
    if (uVar9 != 0xffffffff) {
      uVar7 = param_3 & 0x7fffffff;
    }
    if (uVar7 != 0) {
      return CONCAT44(param_2,uVar5);
    }
  }
  if (uVar5 == 0) {
    param_2 = param_2 + 1;
    uVar5 = 0;
  }
  else {
    uVar5 = uVar5 & 0xfffffffe;
  }
  if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2,uVar5);
  }
LAB_080152e4:
  return (ulonglong)((uint)((int)(param_2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_08015548 @ 08015548

longlong FUN_08015548(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f;
  uVar2 = (param_1 & 0x7fffffff) >> 3;
  uVar4 = param_1 << 1 ^ param_1;
  if (uVar4 != 0) {
    param_1 = param_1 << 0x1d;
    param_2 = (uVar1 | uVar2) + 0x38000000;
  }
  if (uVar4 != 0 && (uVar4 & 0x7f000000) != 0) {
    return CONCAT44(param_2,param_1);
  }
  if ((uVar2 & 0x8000000) == 0) {
    return (ulonglong)uVar1 << 0x20;
  }
  iVar3 = FUN_080159c6(uVar1 | param_1 >> 0x1d | uVar2 << 3,param_2);
  return (ulonglong)((uint)(iVar3 < 0) << 0x1f | 0x7ff00000) << 0x20;
}


// ===== FUN_080155a0 @ 080155a0

/* WARNING: Control flow encountered bad instruction data */

uint FUN_080155a0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
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
      if ((uVar4 & 0xff) == 0xff) {
        FUN_080159c6();
        do {
          software_interrupt(0x40);
        } while( true );
      }
      if ((param_1 & 0x7f800000) == 0) {
        param_1 = 0;
      }
      return param_1;
    }
    uVar1 = param_2 << 8 | 0x80000000;
    uVar2 = (param_1 << 8 | 0x80000000) - (uVar1 >> (uVar5 & 0xff));
    if ((int)uVar2 < 0) {
      bVar8 = (uVar2 >> 7 & 1) != 0;
      uVar4 = (uVar2 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
      if (!bVar8) {
        return uVar4;
      }
      if ((uVar2 & 0x7f) != 0) {
        return uVar4;
      }
LAB_08015ade:
      if (uVar1 << (0x20 - uVar5 & 0xff) == 0) {
        uVar4 = uVar4 & 0xfffffffe;
      }
      else {
        uVar4 = uVar4 - 1;
      }
      return uVar4;
    }
    if ((uVar4 & 0xfe) == 0) {
      if (uVar2 >> 7 == 0) {
        return 0;
      }
    }
    else {
      iVar3 = uVar2 * 2;
      if (iVar3 < 0) {
        bVar8 = (iVar3 >> 7 & 1U) != 0;
        uVar4 = (iVar3 >> 8) + uVar4 * 0x800000 + (uint)bVar8;
        if (!bVar8) {
          return uVar4;
        }
        if ((uVar2 & 0x3f) != 0) {
          return uVar4;
        }
        goto LAB_08015ade;
      }
      uVar5 = (uVar2 & 0x7fffffff) >> 1;
      if (uVar5 == 0) {
        return 0;
      }
      uVar4 = uVar4 - LZCOUNT(uVar5);
      uVar1 = 0x28U - LZCOUNT(uVar5) & 0x1f;
      if (param_1 >> 0x1f == uVar4 >> 8) {
        return (uVar5 >> uVar1 | uVar5 << 0x20 - uVar1) + uVar4 * 0x800000;
      }
    }
    return param_1 & 0x80000000;
  }
  iVar3 = param_1 - param_2;
  if (param_1 < param_2) {
    param_1 = param_1 - iVar3;
    param_2 = param_2 + iVar3;
  }
  uVar4 = param_1 >> 0x17;
  uVar5 = uVar4 - (param_2 >> 0x17);
  if ((param_2 & 0x7f800000) == 0 || (uVar4 & 0xff) == 0xff) {
    if ((uVar4 & 0xff) == 0xff) {
      FUN_080159c6();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if ((param_1 & 0x7f800000) == 0) {
      param_1 = param_1 & 0x80000000;
    }
    return param_1;
  }
  uVar1 = param_1 << 8 | 0x80000000;
  uVar2 = param_2 << 8 | 0x80000000;
  uVar6 = uVar2 >> (uVar5 & 0xff);
  uVar7 = uVar1 + uVar6;
  if (CARRY4(uVar1,uVar6)) {
    bVar8 = (uVar7 >> 1 & 0x80) != 0;
    uVar1 = (uVar7 >> 1 | 0x80000000) >> 8;
    uVar4 = uVar1 + uVar4 * 0x800000 + (uint)bVar8;
    if (bVar8) {
      uVar1 = uVar7 & 0xff;
    }
    uVar6 = uVar4 * 2;
    if (uVar1 != 0) {
      if (uVar6 < 0xff000000) {
        return uVar4;
      }
      goto LAB_0801561c;
    }
  }
  else {
    bVar8 = (uVar7 >> 7 & 1) != 0;
    uVar4 = (uVar7 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
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
LAB_0801561c:
  return (uVar4 + 0xa0000000 >> 0x17 | 0xff) << 0x17;
}


// ===== FUN_08015670 @ 08015670

ulonglong FUN_08015670(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
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
        return CONCAT44(param_2,param_1 ^ param_2) & 0xffffffff80000000;
      }
      if ((uVar3 & 0xff0000) == 0) {
        return CONCAT44(param_2,DAT_080157f0);
      }
      param_1 = param_1 ^ param_2;
    }
    else {
      param_1 = FUN_080159c6();
      param_1 = param_1 & 0x80000000;
    }
  }
  else {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar3 = uVar3 | 0x100;
    }
    uVar2 = param_1 & 0xffffff | 0x800000;
    uVar1 = param_2 & 0xffffff | 0x800000;
    bVar8 = uVar1 <= uVar2;
    uVar6 = -uVar1;
    uVar1 = (uint)*(byte *)(0x80157b8 - (uVar1 >> 0x11));
    iVar7 = uVar1 * 2;
    if (!bVar8) {
      uVar2 = uVar2 << 1;
    }
    iVar4 = (uVar3 - param_4) + 0x7d0000;
    iVar7 = uVar1 * 0x100 + (((int)(uVar6 * iVar7) >> 4) * iVar7 >> 0x15);
    uVar1 = iVar4 + (iVar4 >> 0x10) + (uint)bVar8;
    uVar5 = iVar7 * (uVar2 >> 8) >> 0x14;
    uVar3 = uVar6 * uVar5 + uVar2 * 0x800;
    uVar2 = iVar7 * (uVar3 >> 8) >> 0x13;
    uVar3 = uVar6 * uVar2 + uVar3 * 0x1000;
    bVar8 = CARRY4(uVar3,uVar6);
    if (bVar8) {
      uVar3 = uVar3 + uVar6;
    }
    iVar7 = uVar6 + uVar3 * 2;
    param_1 = uVar2 + uVar5 * 0x1000 + (uint)bVar8 +
              uVar1 * 0x800000 + (uint)CARRY4(uVar6,uVar3 * 2);
    if (uVar1 < 0xfc0000) {
      return CONCAT44(iVar7,param_1);
    }
    if ((int)(uVar1 - 0xfc0000) < 0) {
      if ((uVar1 & 0xf0) != 0) {
        param_1 = param_1 + 0x60000000 & 0x80000000;
      }
      return CONCAT44(iVar7,param_1);
    }
    if (0xfdffffff < param_1 * 2 + 0x1000000) {
      return CONCAT44(iVar7,param_1);
    }
    param_1 = param_1 + 0xa0000000;
  }
  return CONCAT44(0xff,(param_1 >> 0x17 | 0xff) << 0x17);
}


// ===== FUN_080157f4 @ 080157f4

uint FUN_080157f4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar1 = 0x9e - uVar2;
  if (0x9e < uVar2 || uVar1 == 0) {
    FUN_080159c6();
    do {
      *unaff_r4 = (short)unaff_r4;
    } while( true );
  }
  uVar1 = ((param_1 | 0x800000) << 8) >> (uVar1 & 0xff);
  if ((int)(param_1 | 0x800000) < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}


// ===== FUN_0801582c @ 0801582c

uint FUN_0801582c(uint param_1)

{
  undefined2 *unaff_r4;
  
  if (param_1 >> 0x17 < 0x9f) {
    return (param_1 << 8 | 0x80000000) >> (0x9e - (param_1 >> 0x17) & 0xff);
  }
  if (((int)param_1 < 0) && (param_1 << 1 < 0x7f000000)) {
    return 0;
  }
  FUN_080159c6();
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== FUN_0801586c @ 0801586c

uint FUN_0801586c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
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


// ===== FUN_0801589c @ 0801589c

uint FUN_0801589c(uint param_1)

{
  uint uVar1;
  
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


// ===== FUN_080158c4 @ 080158c4

uint FUN_080158c4(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined8 uVar10;
  
  uVar2 = param_1 >> 7 & 0xff0000;
  bVar7 = uVar2 == 0;
  if (!bVar7) {
    param_4 = param_2 >> 7 & 0xff0000;
    bVar7 = param_4 == 0;
  }
  if (!bVar7) {
    bVar7 = uVar2 == 0xff0000;
  }
  if (!bVar7) {
    bVar7 = param_4 == 0xff0000;
  }
  if (bVar7) {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar2 = uVar2 | 0x100;
    }
    if (uVar2 < 0xff0000 && (param_2 >> 7 & 0xff0000) < 0xff0000) {
      return (param_1 ^ param_2) & 0x80000000;
    }
    uVar10 = FUN_080159c6();
    uVar2 = (uint)uVar10 ^ (int)((ulonglong)uVar10 >> 0x20) << 2;
  }
  else {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar2 = uVar2 | 0x100;
    }
    lVar1 = (ulonglong)(param_1 << 8 | 0x80000000) * (ulonglong)(param_2 << 8 | 0x80000000);
    uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
    iVar3 = uVar2 + param_4 + -0x800000;
    if ((int)lVar1 != 0) {
      uVar4 = uVar4 | 1;
    }
    bVar7 = (uVar4 & 0x80000000) != 0;
    uVar5 = uVar4 << 1;
    if (bVar7) {
      uVar5 = uVar4 & 0x7fffffff | 0x80000000;
    }
    uVar4 = iVar3 + (iVar3 >> 0x10) + (uint)bVar7;
    bVar7 = (uVar5 >> 7 & 1) != 0;
    uVar6 = uVar5 >> 8;
    uVar2 = uVar6 + uVar4 * 0x800000 + (uint)bVar7;
    bVar8 = uVar5 << 0x19 <= uVar6;
    bVar9 = bVar7 && bVar8;
    if (!bVar7 || !bVar8) {
      bVar9 = 0xfbffff < uVar4;
    }
    if (!bVar9) {
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


// ===== FUN_080159c6 @ 080159c6

uint FUN_080159c6(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int unaff_lr;
  uint *puVar3;
  bool bVar4;
  
  puVar3 = (uint *)(unaff_lr + 2U & 0xfffffffc);
  uVar1 = *puVar3;
  if ((((int)uVar1 < 0) || (param_3 = param_2 * 2, param_3 < 0xff000001)) &&
     (param_1 * 2 < 0xff000001)) {
    if (param_1 * 2 == 0xff000000) {
      uVar2 = ((int)param_1 >> 0x1f) * -3 + 2;
      if (param_3 == 0xff000000) {
        uVar2 = uVar2 + (1 - ((int)param_2 >> 0x1f));
      }
    }
    else {
      uVar2 = param_2 >> 0x1f;
    }
  }
  else {
    uVar2 = 8;
  }
  uVar1 = uVar1 >> (uVar2 * 3 & 0xff) & 7;
  switch(uVar1) {
  case 4:
    param_1 = param_2;
switchD_08015a2e_caseD_5:
    bVar4 = (param_1 & 0x80000000) != 0;
    uVar1 = param_1 * 2;
    if (uVar1 != 0) {
      bVar4 = uVar1 < 0x1000001;
    }
    if (bVar4 && (uVar1 != 0 && param_1 * -2 != -0x1000000)) {
      param_1 = param_1 & 0x80000000;
    }
    return param_1;
  case 5:
    goto switchD_08015a2e_caseD_5;
  case 6:
  case 7:
    return 0x7fc00000;
  default:
                    /* WARNING: Could not recover jumptable at 0x08015a2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(puVar3 + uVar1 + 1))();
    return uVar1;
  }
}


// ===== FUN_08015baa @ 08015baa

/* WARNING: Removing unreachable block (ram,0x08015c58) */
/* WARNING: Removing unreachable block (ram,0x08015c66) */
/* WARNING: Removing unreachable block (ram,0x08015b76) */
/* WARNING: Removing unreachable block (ram,0x08015c5e) */
/* WARNING: Removing unreachable block (ram,0x08015b94) */
/* WARNING: Removing unreachable block (ram,0x08015b5e) */
/* WARNING: Removing unreachable block (ram,0x08015b60) */
/* WARNING: Removing unreachable block (ram,0x08015b64) */
/* WARNING: Removing unreachable block (ram,0x08015b7c) */
/* WARNING: Removing unreachable block (ram,0x08015b82) */
/* WARNING: Removing unreachable block (ram,0x08015b66) */
/* WARNING: Removing unreachable block (ram,0x08015b70) */
/* WARNING: Removing unreachable block (ram,0x08015b4e) */

longlong FUN_08015baa(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  char in_OV;
  bool bVar3;
  bool bVar4;
  
  uVar2 = 0x7ff;
  uVar1 = param_2 >> 0x14 & 0x7ff;
  bVar3 = uVar1 == 0;
  if (!bVar3) {
    uVar2 = uVar1 ^ 0x7ff;
    bVar3 = uVar2 == 0;
  }
  bVar4 = bVar3;
  if (!bVar3) {
    in_OV = SBORROW4(uVar2,param_3);
    bVar4 = uVar2 == param_3;
  }
  bVar3 = !bVar3 && (int)(uVar2 - param_3) < 0;
  if (!bVar4 && bVar3 == (bool)in_OV) {
    in_OV = SCARRY4(param_3,uVar1);
    bVar3 = (int)(param_3 + uVar1) < 0;
    bVar4 = param_3 + uVar1 == 0;
  }
  if (!bVar4 && bVar3 == (bool)in_OV) {
    return CONCAT44(param_2 + param_3 * 0x100000,param_1);
  }
  if (uVar1 == 0) {
    return (ulonglong)(param_2 & 0x80000000) << 0x20;
  }
  if (uVar2 == 0) {
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return CONCAT44(param_2,param_1);
    }
    return (ulonglong)DAT_08014d00 << 0x20;
  }
  param_2 = param_2 & 0x80000000;
  if (-1 < (int)param_3) {
    param_2 = param_2 | 0x7ff00000;
  }
  return (ulonglong)param_2 << 0x20;
}


// ===== FUN_08015c06 @ 08015c06

/* WARNING: Removing unreachable block (ram,0x08015c58) */
/* WARNING: Removing unreachable block (ram,0x08015c66) */
/* WARNING: Removing unreachable block (ram,0x08015b82) */
/* WARNING: Removing unreachable block (ram,0x08015b76) */
/* WARNING: Removing unreachable block (ram,0x08015c5e) */
/* WARNING: Removing unreachable block (ram,0x08015b70) */
/* WARNING: Removing unreachable block (ram,0x08015b66) */
/* WARNING: Removing unreachable block (ram,0x08015b5e) */
/* WARNING: Removing unreachable block (ram,0x08015b60) */
/* WARNING: Removing unreachable block (ram,0x08015b64) */
/* WARNING: Removing unreachable block (ram,0x08015b7c) */
/* WARNING: Removing unreachable block (ram,0x08015b4e) */

ulonglong FUN_08015c06(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  char in_OV;
  bool bVar2;
  bool bVar3;
  
  uVar1 = param_1 >> 0x17 & 0xff;
  bVar2 = uVar1 == 0;
  if (!bVar2) {
    param_4 = uVar1 ^ 0xff;
    bVar2 = param_4 == 0;
  }
  bVar3 = bVar2;
  if (!bVar2) {
    in_OV = SBORROW4(param_4,param_2);
    bVar3 = param_4 == param_2;
  }
  bVar2 = !bVar2 && (int)(param_4 - param_2) < 0;
  if (!bVar3 && bVar2 == (bool)in_OV) {
    in_OV = SCARRY4(param_2,uVar1);
    bVar2 = (int)(param_2 + uVar1) < 0;
    bVar3 = param_2 + uVar1 == 0;
  }
  if (!bVar3 && bVar2 == (bool)in_OV) {
    return CONCAT44(param_2,param_1 + param_2 * 0x800000);
  }
  if (uVar1 == 0) {
    return CONCAT44(param_2,param_1) & 0xffffffff80000000;
  }
  if (param_4 == 0) {
    if ((param_1 & 0x7fffff) == 0) {
      return CONCAT44(param_2,param_1);
    }
    return CONCAT44(param_2,DAT_0801566c);
  }
  param_1 = param_1 & 0x80000000;
  if (-1 < (int)param_2) {
    param_1 = param_1 | 0x7f800000;
  }
  return CONCAT44(param_2,param_1);
}


