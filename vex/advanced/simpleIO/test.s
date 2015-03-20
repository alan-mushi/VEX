 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /opt/vex-3.43 -ms -mas_g -mas_t -fmm=./vex_MachineModel.mm -o test"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
.equ _?1TEMPLATEPACKET.17, 0x0
.equ _?1TEMPLATEPACKET.1, 0x0
.equ _?1TEMPLATEPACKET.18, 0x0
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-192, arg($r0.3:s32,$r0.4:u32)
main::
.trace 4
	c0    add $r0.1 = $r0.1, (-0xc0)
	c0    cmplt $b0.0 = $r0.3, 3   ## bblock 0, line 15,  t66(I1),  t1,  3(SI32)
	c0    ldw.d $r0.2 = 4[$r0.4]   ## [spec] bblock 1, line 20, t13, t63
;;								## 0
	c0    stw 0x90[$r0.1] = $l0.0  ## spill ## t49
;;								## 1
	c0    stw 0xa0[$r0.1] = $r0.4  ## spill ## t63
;;								## 2
	c0    mov $r0.4 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
	c0    stw 0x94[$r0.1] = $r0.59  ## spill ## t55
	c0    mov $r0.3 = $r0.2   ## [spec] t13
;;								## 3
	c0    stw 0x98[$r0.1] = $r0.58  ## spill ## t54
;;								## 4
	c0    stw 0x9c[$r0.1] = $r0.57  ## spill ## t53
;;								## 5
	c0    add $r0.57 = $r0.1, 0x10   ## bblock 0, line 13,  t0,  t50,  offset(buffer?1.2)=0x10(P32)
	c0    br $b0.0, L0?3   ## bblock 0, line 15,  t66(I1)
;;								## 6
L1?3:
.call fopen, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = fopen   ## bblock 1, line 20,  raddr(fopen)(P32),  t13,  addr(_?1STRINGVAR.2)(P32)
;;								## 7
	c0    mov $r0.4 = (_?1STRINGPACKET.3 + 0)   ## addr(_?1STRINGVAR.3)(P32)
	c0    stw 0xa4[$r0.1] = $r0.3  ## spill ## t10
;;								## 8
	c0    ldw $r0.2 = 0xa0[$r0.1]  ## restore ## t63
	      xnop 2
;;								## 11
	c0    ldw $r0.3 = 8[$r0.2]   ## bblock 2, line 21, t19, t63
	      xnop 1
;;								## 13
.call fopen, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:u32)
	c0    call $l0.0 = fopen   ## bblock 2, line 21,  raddr(fopen)(P32),  t19,  addr(_?1STRINGVAR.3)(P32)
;;								## 14
	c0    ldw $r0.58 = 0xa4[$r0.1]  ## restore ## t10
	c0    mov $r0.59 = $r0.3   ## t16
	      xnop 2
;;								## 17
	c0    nandl $b0.0 = $r0.58, $r0.3   ## bblock 3, line 22,  t67(I1),  t10,  t16
	      xnop 1
;;								## 19
	c0    br $b0.0, L2?3   ## bblock 3, line 22,  t67(I1)
;;								## 20
.trace 1
L3?3:
.call fgets, caller, arg($r0.3:u32,$r0.4:s32,$r0.5:u32), ret($r0.3:u32)
	c0    call $l0.0 = fgets   ## bblock 4, line 28,  raddr(fgets)(P32),  t0,  128(SI32),  t10
	c0    mov $r0.4 = 128   ## 128(SI32)
	c0    mov $r0.3 = $r0.57   ## t0
	c0    mov $r0.5 = $r0.58   ## t10
;;								## 0
	c0    ldh $r0.2 = 12[$r0.58]   ## bblock 5, line 29, t35(SI16), t10
	c0    mov $r0.4 = (_?1STRINGPACKET.5 + 0)   ## addr(_?1STRINGVAR.5)(P32)
	c0    mov $r0.5 = $r0.57   ## t0
;;								## 1
	c0    mov $r0.3 = $r0.59   ## t16
	      xnop 1
;;								## 3
	c0    and $r0.2 = $r0.2, 32   ## bblock 5, line 29,  t36,  t35(SI16),  32(I32)
;;								## 4
	c0    cmpeq $b0.0 = $r0.2, $r0.0   ## bblock 5, line 29,  t68(I1),  t36,  0(SI32)
	      xnop 1
;;								## 6
	c0    brf $b0.0, L4?3   ## bblock 5, line 29,  t68(I1)
;;								## 7
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 10, line 30,  raddr(fprintf)(P32),  t16,  addr(_?1STRINGVAR.5)(P32),  t0
;;								## 8
L4?3:
	c0    ldh $r0.2 = 12[$r0.58]   ## bblock 6, line 32, t43(SI16), t10
	      xnop 2
;;								## 11
	c0    and $r0.2 = $r0.2, 32   ## bblock 6, line 32,  t44,  t43(SI16),  32(I32)
;;								## 12
	c0    cmpne $b0.0 = $r0.2, $r0.0   ## bblock 6, line 32,  t69(I1),  t44,  0(SI32)
	      xnop 1
;;								## 14
	c0    br $b0.0, L5?3   ## bblock 6, line 32,  t69(I1)
	      ## goto
;;
	c0    goto L3?3 ## goto
;;								## 15
.trace 5
L5?3:
.call fclose, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = fclose   ## bblock 7, line 34,  raddr(fclose)(P32),  t10
	c0    mov $r0.3 = $r0.58   ## t10
;;								## 0
.call fclose, caller, arg($r0.3:u32), ret($r0.3:s32)
	c0    call $l0.0 = fclose   ## bblock 8, line 35,  raddr(fclose)(P32),  t16
	c0    mov $r0.3 = $r0.59   ## t16
;;								## 1
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x90[$r0.1]  ## restore ## t49
;;								## 2
	c0    ldw $r0.59 = 0x94[$r0.1]  ## restore ## t55
;;								## 3
	c0    ldw $r0.58 = 0x98[$r0.1]  ## restore ## t54
;;								## 4
	c0    ldw $r0.57 = 0x9c[$r0.1]  ## restore ## t53
	      xnop 1
;;								## 6
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0xc0), $l0.0   ## bblock 9, line 37,  t50,  ?2.1?2auto_size(I32),  t49
;;								## 7
.trace 7
L2?3:
	c0    ldw $r0.2 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 11, line 23, t27, 0(I32)
	c0    mov $r0.4 = (_?1STRINGPACKET.4 + 0)   ## addr(_?1STRINGVAR.4)(P32)
	      xnop 2
;;								## 2
	c0    ldw $r0.3 = 12[$r0.2]   ## bblock 11, line 23, t28, t27
	      xnop 1
;;								## 4
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 11, line 23,  raddr(fprintf)(P32),  t28,  addr(_?1STRINGVAR.4)(P32)
;;								## 5
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 12, line 24,  raddr(exit)(P32),  -2(SI32)
	c0    mov $r0.3 = -2   ## -2(SI32)
	      ## goto
;;
	c0    goto L3?3 ## goto
;;								## 6
.trace 6
L0?3:
	c0    ldw $r0.2 = ((_impure_ptr + 0) + 0)[$r0.0]   ## bblock 13, line 16, t3, 0(I32)
	c0    mov $r0.4 = (_?1STRINGPACKET.1 + 0)   ## addr(_?1STRINGVAR.1)(P32)
;;								## 0
	c0    ldw $r0.6 = 0xa0[$r0.1]  ## restore ## t63
	      xnop 1
;;								## 2
	c0    ldw $r0.3 = 12[$r0.2]   ## bblock 13, line 16, t4, t3
;;								## 3
	c0    ldw $r0.5 = 0[$r0.6]   ## bblock 13, line 16, t9, t63
	      xnop 1
;;								## 5
.call fprintf, caller, arg($r0.3:u32,$r0.4:u32,$r0.5:u32), ret($r0.3:s32)
	c0    call $l0.0 = fprintf   ## bblock 13, line 16,  raddr(fprintf)(P32),  t4,  addr(_?1STRINGVAR.1)(P32),  t9
;;								## 6
.call exit, caller, arg($r0.3:s32), ret()
	c0    call $l0.0 = exit   ## bblock 14, line 17,  raddr(exit)(P32),  -1(SI32)
	c0    mov $r0.3 = -1   ## -1(SI32)
;;								## 7
	c0    mov $r0.4 = (_?1STRINGPACKET.2 + 0)   ## addr(_?1STRINGVAR.2)(P32)
	c0    ldw $r0.2 = 0xa0[$r0.1]  ## restore ## t63
	      xnop 2
;;								## 10
	c0    ldw $r0.3 = 4[$r0.2]   ## bblock 1, line 20, t13, t63
	      xnop 1
;;								## 12
	c0    goto L1?3 ## goto
;;								## 13
.endp
.section .bss
.section .data
_?1STRINGPACKET.1:
    .data1 85
    .data1 115
    .data1 97
    .data1 103
    .data1 101
    .data1 58
    .data1 32
    .data1 37
    .data1 115
    .data1 32
    .data1 105
    .data1 110
    .data1 112
    .data1 117
    .data1 116
    .data1 32
    .data1 111
    .data1 117
    .data1 116
    .data1 112
    .data1 117
    .data1 116
    .data1 10
    .data1 0
_?1STRINGPACKET.2:
    .data1 114
    .data1 0
.skip 2
_?1STRINGPACKET.3:
    .data1 119
    .data1 0
.skip 2
_?1STRINGPACKET.4:
    .data1 67
    .data1 97
    .data1 110
    .data1 110
    .data1 111
    .data1 116
    .data1 32
    .data1 111
    .data1 112
    .data1 101
    .data1 110
    .data1 32
    .data1 102
    .data1 105
    .data1 108
    .data1 101
    .data1 33
    .data1 10
    .data1 0
.skip 1
_?1STRINGPACKET.5:
    .data1 37
    .data1 115
    .data1 0
.equ ?2.1?2scratch.0, 0x0
.equ _?1PACKET.3, 0x10
.equ ?2.1?2ras_p, 0x90
.equ ?2.1?2spill_p, 0x94
.section .data
.section .text
.equ ?2.1?2auto_size, 0xc0
 ## End main
.section .bss
.section .data
.section .data
.import _impure_ptr
.type _impure_ptr,@object
.section .text
.import exit
.type exit,@function
.import fopen
.type fopen,@function
.import fgets
.type fgets,@function
.import fprintf
.type fprintf,@function
.import fclose
.type fclose,@function
