; Generated by holtek-gcc v3.19, Tue Apr 05 13:18:20 2022
; 
; Configuration:
;       with long instruction
;       Single ROM, Multi-RAM
;       bits_per_rom_unit:16
;       with mp1
;       with tbhp, address(0x9)
;          Use tabrd-const
;       
; SFR address of long-instruction arch:
;    mp0 = -1,1,0
;    mp1 = 4,3,2
;    mp2 = 14,13,12
;    tbp = 9,7,8
;    acc = 5
;    pcl = 6
;    status = 10
;    bp = 11
;    intc = 17
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.19" "build 20130711"
; Rebuild 718

ir equ [2]
mp equ [3]
sbp equ [4]
acc equ [5]
bp equ [11]
tblp equ [7]
tbhp equ [9]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
cz equ [10].6
sc equ [10].7
intc equ [17]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @BITDATASEC, @BITDATASEC1
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'
@BITDATASEC	 .section 'data'
@BITDATASEC1	 .section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
___intc0 equ [17]
___ptmc0 equ [55]
___pa equ [20]
___pc equ [65]
public _INT0_ISR
#pragma debug scope 2 1
#line 346 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
@INT0_ISR_code .section at 4 'code'
ifdef INTERRUPT_DELAY
	nop
endif
	mov r1,a
	mov a,status
ifndef INTERRUPT_DELAY
	mov r2,a
endif
	jmp _INT0_ISR
#pragma debug scope 1 1
@dummy4 proc
	call _INT0_ISR
@dummy4 endp
#pragma debug scope 3 1
_INT0_ISR .section 'code'
_INT0_ISR proc
ifdef INTERRUPT_DELAY
	mov r2,a
endif
#line 348 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [17].4
#line 349 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [55].3
#line 355 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,_TRIAC_INT[0]
	sub a,7
	sz z
	jmp _L3
	sub a,(8)-(7)
	sz z
	jmp _L4
#line 355 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,_TRIAC_INT[0]
	sub a,9
	sz z
	jmp _L5
	sub a,(10)-(9)
	sz z
	jmp _L6
	mov a,_TRIAC_INT[0]
	sub a,11
	sz z
	jmp _L7
	sub a,(12)-(11)
	sz z
	jmp _L8
	mov a,_TRIAC_INT[0]
	sub a,13
	sz z
	jmp _L9
	sub a,(14)-(13)
	sz z
	jmp _L10
	mov a,_TRIAC_INT[0]
	sub a,15
	snz z
	jmp _L2
#line 406 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
	jmp _L19
_L3:
#line 358 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [20].1
	jmp _L19
_L4:
#line 364 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
#line 365 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [65].4
	jmp _L24
_L5:
#line 370 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
#line 371 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [65].4
	jmp _L25
_L6:
#line 376 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
#line 377 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [65].4
	jmp _L23
_L7:
#line 382 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
#line 383 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [65].4
	jmp _L22
_L8:
#line 388 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
#line 389 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [65].4
_L24:
#line 390 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [65].1
	jmp _L20
_L9:
#line 394 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
#line 395 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [65].4
_L25:
#line 396 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [65].1
	jmp _L21
_L10:
#line 400 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [20].1
#line 401 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [65].4
_L23:
#line 402 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [65].1
_L20:
#line 403 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [65].5
#line 404 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	jmp _L2
_L19:
#line 407 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [65].4
_L22:
#line 408 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [65].1
_L21:
#line 409 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [65].5
_L2:
#line 415 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	snz _TriacTimeoutFlag[0].4
	jmp _L12
#line 417 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,_gDownCounterValue[0]
	mov ra,a
	snz ra
	jmp _L12
#line 418 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	deca ra
	mov _gDownCounterValue[0],a
_L12:
#line 421 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr _No_zero_cross_counter[0]
	mov a,r2
	mov status,a
	mov a,r1
	reti
_INT0_ISR endp

#line 421 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
#pragma debug scope 1 1
___mfi1 equ [77]
public _timer_i0
#pragma debug scope 4 1
#line 426 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
@timer_i0_code .section at 16 'code'
ifdef INTERRUPT_DELAY
	nop
endif
	mov r1,a
	mov a,status
ifndef INTERRUPT_DELAY
	mov r2,a
endif
	jmp _timer_i0
#pragma debug scope 1 1
@dummy16 proc
	call _timer_i0
@dummy16 endp
#pragma debug scope 5 1
_timer_i0 .section 'code'
_timer_i0 proc
ifdef INTERRUPT_DELAY
	mov r2,a
endif
#line 428 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [77].5
#line 486 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [55].3
	mov a,r2
	mov status,a
	mov a,r1
	reti
_timer_i0 endp

#line 486 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
#pragma debug scope 1 1
___wdtc equ [26]
___lvrc equ [29]
___lvdc equ [24]
___sledc0 equ [79]
___sledc1 equ [80]
___pac equ [21]
___pcc equ [66]
___pbc equ [38]
___pbs0 equ [93]
___integ equ [16]
___ifs equ [81]
___pas0 equ [91]
___intc2 equ [19]
___stmc1 equ [48]
___stmc0 equ [47]
___stmal equ [51]
___stmah equ [52]
___pcs0 equ [95]
___ucr3 equ [118]
___ucr1 equ [86]
___ucr2 equ [87]
___brg equ [88]
___ptmc1 equ [56]
___ptmal equ [59]
___ptmah equ [60]
___intc1 equ [18]
___ctmc1 equ [41]
___ctmc0 equ [40]
___ctmal equ [44]
___ctmah equ [45]
___pb equ [37]
___tb0c equ [27]
public _sysInit
#pragma debug scope 6 1
#line 536 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
_sysInit .section 'code'
_sysInit proc
#line 541 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,171
	mov [26],a
#line 549 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,102
	mov [29],a
#line 550 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,20
	mov [24],a
#line 558 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [79].3
	set [79].2
	set [79].1
	set [79].0
#line 559 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [80].3
	set [80].2
	set [80].1
	set [80].0
#line 562 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [21].1
	clr [66].5
	clr [66].4
	clr [66].1
#line 565 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [21].0
#line 566 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [21].7
#line 568 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [38].0
#line 569 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [93]
#line 570 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [17].4
#line 571 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,3
	mov [16],a
#line 572 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [17].1
#line 583 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [81].5
	clr [91].5
	clr [91].4
	set [21].2
#line 584 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [16].3
	set [16].2
#line 585 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [19].5
#line 586 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [19].1
#line 589 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [48].7
	set [48].6
#line 590 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [47].6
	set [47].5
	clr [47].4
#line 591 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [48].0
#line 592 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,124
	mov [51],a
#line 593 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,146
	mov [52],a
#line 594 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [47].3
#line 598 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [66].0
#line 599 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [95].1
	set [95].0
#line 601 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [118].0
#line 602 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [86].5
#line 603 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [86].6
#line 604 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [87].5
#line 605 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [86].3
#line 606 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,12
	mov [88],a
#line 607 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [86].7
#line 608 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [87].7
#line 616 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,80
	mov [55],a
#line 617 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,193
	mov [56],a
#line 618 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,240
	mov [59],a
#line 619 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,3
	mov [60],a
#line 622 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [18].0
#line 623 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [18].4
#line 624 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [77].5
#line 625 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [77].1
#line 626 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [17].0
#line 632 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [41].7
	set [41].6
#line 633 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [40].6
	clr [40].5
	set [40].4
#line 634 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [41].0
#line 635 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [44]
#line 636 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,5
	mov [45],a
#line 637 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [40].3
#line 639 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [21].7
#line 640 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [20].7
#line 641 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [38].6
#line 642 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [37].6
#line 664 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	clr [18].7
#line 665 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	mov a,135
	mov [27],a
#line 666 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	set [18].3
	ret
_sysInit endp
#line 666 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
#pragma debug scope 1 1
public _main
#pragma debug scope 7 1
#line 51 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
IFDEF WITH_DEFAULT_STARTUP
extern _main_initial0:near
extern _main_startup:near
ENDIF

ROMBANK 0 @start
@start .section com_l 'code'
_main_startup1:
@start .section com_e 'code'
	jmp _main

_main .section 'code'
_main proc
#line 60 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	call _sysInit
#line 67 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
	call _app
	jmp $
_main endp

@dummy proc
	call _main
@dummy endp

#line 67 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
#pragma debug scope 1 1
public _TRIAC_INT
@HCCINIT	.section 'data'
#line 48 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
@HCCINIT_TRIAC_INT .section 'data'
_TRIAC_INT label byte
#pragma debug variable 8 1 _TRIAC_INT "TRIAC_INT"
	db 0
@ROMDATA_BASE .section inpage 'code'
	db 0
@HCCINIT_TRIAC_INT .section 'data'
#line 26 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
public _keyPressIndiVal
@HCCINIT0_keyPressIndiVal .section 'data'
_keyPressIndiVal	db 4 dup(0)
#pragma debug variable 14 1 _keyPressIndiVal "keyPressIndiVal"

@HCCINIT .section 'data'
#pragma debug struct_begin 42 "__integ_bits"
#pragma debug field 21 8 0 1 "__int0s0" ;0,1
#pragma debug field 21 8 0 1 "__int0s1" ;1,1
#pragma debug field 21 8 0 1 "__int1s0" ;2,1
#pragma debug field 21 8 0 1 "__int1s1" ;3,1
#pragma debug field 21 8 0 4 ;4,4
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 ___integ "__integ" 1
#pragma debug struct_begin 44 "__intc0_bits"
#pragma debug field 21 8 0 1 "__emi" ;0,1
#pragma debug field 21 8 0 1 "__int0e" ;1,1
#pragma debug field 21 8 0 1 "__cpe" ;2,1
#pragma debug field 21 8 0 1 "__mf0e" ;3,1
#pragma debug field 21 8 0 1 "__int0f" ;4,1
#pragma debug field 21 8 0 1 "__cpf" ;5,1
#pragma debug field 21 8 0 1 "__mf0f" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 45 ""
#pragma debug field 2 44 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 45 1 ___intc0 "__intc0" 1
#pragma debug struct_begin 46 "__intc1_bits"
#pragma debug field 21 8 0 1 "__mf1e" ;0,1
#pragma debug field 21 8 0 1 "__mf2e" ;1,1
#pragma debug field 21 8 0 1 "__ade" ;2,1
#pragma debug field 21 8 0 1 "__tb0e" ;3,1
#pragma debug field 21 8 0 1 "__mf1f" ;4,1
#pragma debug field 21 8 0 1 "__mf2f" ;5,1
#pragma debug field 21 8 0 1 "__adf" ;6,1
#pragma debug field 21 8 0 1 "__tb0f" ;7,1
#pragma debug struct_end
#pragma debug union_begin 47 ""
#pragma debug field 2 46 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 47 1 ___intc1 "__intc1" 1
#pragma debug struct_begin 48 "__intc2_bits"
#pragma debug field 21 8 0 1 "__tb1e" ;0,1
#pragma debug field 21 8 0 1 "__int1e" ;1,1
#pragma debug field 21 8 0 1 "__sime" ;2,1
#pragma debug field 21 8 0 1 "__ure" ;3,1
#pragma debug field 21 8 0 1 "__tb1f" ;4,1
#pragma debug field 21 8 0 1 "__int1f" ;5,1
#pragma debug field 21 8 0 1 "__simf" ;6,1
#pragma debug field 21 8 0 1 "__urf" ;7,1
#pragma debug struct_end
#pragma debug union_begin 49 ""
#pragma debug field 2 48 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 49 1 ___intc2 "__intc2" 1
#pragma debug struct_begin 50 "__pa_bits"
#pragma debug field 21 8 0 1 "__pa0" ;0,1
#pragma debug field 21 8 0 1 "__pa1" ;1,1
#pragma debug field 21 8 0 1 "__pa2" ;2,1
#pragma debug field 21 8 0 1 "__pa3" ;3,1
#pragma debug field 21 8 0 1 "__pa4" ;4,1
#pragma debug field 21 8 0 1 "__pa5" ;5,1
#pragma debug field 21 8 0 1 "__pa6" ;6,1
#pragma debug field 21 8 0 1 "__pa7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 51 ""
#pragma debug field 2 50 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 51 1 ___pa "__pa" 1
#pragma debug struct_begin 52 "__pac_bits"
#pragma debug field 21 8 0 1 "__pac0" ;0,1
#pragma debug field 21 8 0 1 "__pac1" ;1,1
#pragma debug field 21 8 0 1 "__pac2" ;2,1
#pragma debug field 21 8 0 1 "__pac3" ;3,1
#pragma debug field 21 8 0 1 "__pac4" ;4,1
#pragma debug field 21 8 0 1 "__pac5" ;5,1
#pragma debug field 21 8 0 1 "__pac6" ;6,1
#pragma debug field 21 8 0 1 "__pac7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 53 ""
#pragma debug field 2 52 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 53 1 ___pac "__pac" 1
#pragma debug struct_begin 54 "__lvdc_bits"
#pragma debug field 21 8 0 1 "__vlvd0" ;0,1
#pragma debug field 21 8 0 1 "__vlvd1" ;1,1
#pragma debug field 21 8 0 1 "__vlvd2" ;2,1
#pragma debug field 21 8 0 1 ;3,1
#pragma debug field 21 8 0 1 "__lvden" ;4,1
#pragma debug field 21 8 0 1 "__lvdo" ;5,1
#pragma debug field 21 8 0 2 ;6,2
#pragma debug struct_end
#pragma debug union_begin 55 ""
#pragma debug field 2 54 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 55 1 ___lvdc "__lvdc" 1
#pragma debug struct_begin 56 "__wdtc_bits"
#pragma debug field 21 8 0 1 "__ws0" ;0,1
#pragma debug field 21 8 0 1 "__ws1" ;1,1
#pragma debug field 21 8 0 1 "__ws2" ;2,1
#pragma debug field 21 8 0 1 "__we0" ;3,1
#pragma debug field 21 8 0 1 "__we1" ;4,1
#pragma debug field 21 8 0 1 "__we2" ;5,1
#pragma debug field 21 8 0 1 "__we3" ;6,1
#pragma debug field 21 8 0 1 "__we4" ;7,1
#pragma debug struct_end
#pragma debug union_begin 57 ""
#pragma debug field 2 56 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 57 1 ___wdtc "__wdtc" 1
#pragma debug struct_begin 58 "__tb0c_bits"
#pragma debug field 21 8 0 1 "__tb00" ;0,1
#pragma debug field 21 8 0 1 "__tb01" ;1,1
#pragma debug field 21 8 0 1 "__tb02" ;2,1
#pragma debug field 21 8 0 4 ;3,4
#pragma debug field 21 8 0 1 "__tb0on" ;7,1
#pragma debug struct_end
#pragma debug union_begin 59 ""
#pragma debug field 2 58 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 59 1 ___tb0c "__tb0c" 1
#pragma debug struct_begin 60 "__lvrc_bits"
#pragma debug field 21 8 0 1 "__lvs0" ;0,1
#pragma debug field 21 8 0 1 "__lvs1" ;1,1
#pragma debug field 21 8 0 1 "__lvs2" ;2,1
#pragma debug field 21 8 0 1 "__lvs3" ;3,1
#pragma debug field 21 8 0 1 "__lvs4" ;4,1
#pragma debug field 21 8 0 1 "__lvs5" ;5,1
#pragma debug field 21 8 0 1 "__lvs6" ;6,1
#pragma debug field 21 8 0 1 "__lvs7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 61 ""
#pragma debug field 2 60 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 61 1 ___lvrc "__lvrc" 1
#pragma debug struct_begin 62 "__pb_bits"
#pragma debug field 21 8 0 1 "__pb0" ;0,1
#pragma debug field 21 8 0 1 "__pb1" ;1,1
#pragma debug field 21 8 0 1 "__pb2" ;2,1
#pragma debug field 21 8 0 1 "__pb3" ;3,1
#pragma debug field 21 8 0 1 "__pb4" ;4,1
#pragma debug field 21 8 0 1 "__pb5" ;5,1
#pragma debug field 21 8 0 1 "__pb6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 63 ""
#pragma debug field 2 62 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 63 1 ___pb "__pb" 1
#pragma debug struct_begin 64 "__pbc_bits"
#pragma debug field 21 8 0 1 "__pbc0" ;0,1
#pragma debug field 21 8 0 1 "__pbc1" ;1,1
#pragma debug field 21 8 0 1 "__pbc2" ;2,1
#pragma debug field 21 8 0 1 "__pbc3" ;3,1
#pragma debug field 21 8 0 1 "__pbc4" ;4,1
#pragma debug field 21 8 0 1 "__pbc5" ;5,1
#pragma debug field 21 8 0 1 "__pbc6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 65 ""
#pragma debug field 2 64 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 65 1 ___pbc "__pbc" 1
#pragma debug struct_begin 66 "__ctmc0_bits"
#pragma debug field 21 8 0 3 ;0,3
#pragma debug field 21 8 0 1 "__cton" ;3,1
#pragma debug field 21 8 0 1 "__ctck0" ;4,1
#pragma debug field 21 8 0 1 "__ctck1" ;5,1
#pragma debug field 21 8 0 1 "__ctck2" ;6,1
#pragma debug field 21 8 0 1 "__ctpau" ;7,1
#pragma debug struct_end
#pragma debug union_begin 67 ""
#pragma debug field 2 66 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 67 1 ___ctmc0 "__ctmc0" 1
#pragma debug struct_begin 68 "__ctmc1_bits"
#pragma debug field 21 8 0 1 "__ctcclr" ;0,1
#pragma debug field 21 8 0 1 "__ctdpx" ;1,1
#pragma debug field 21 8 0 1 "__ctpol" ;2,1
#pragma debug field 21 8 0 1 "__ctoc" ;3,1
#pragma debug field 21 8 0 1 "__ctio0" ;4,1
#pragma debug field 21 8 0 1 "__ctio1" ;5,1
#pragma debug field 21 8 0 1 "__ctm0" ;6,1
#pragma debug field 21 8 0 1 "__ctm1" ;7,1
#pragma debug struct_end
#pragma debug union_begin 69 ""
#pragma debug field 2 68 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 69 1 ___ctmc1 "__ctmc1" 1
#pragma debug variable 8 1 ___ctmal "__ctmal" 1
#pragma debug variable 8 1 ___ctmah "__ctmah" 1
#pragma debug struct_begin 70 "__stmc0_bits"
#pragma debug field 21 8 0 3 ;0,3
#pragma debug field 21 8 0 1 "__ston" ;3,1
#pragma debug field 21 8 0 1 "__stck0" ;4,1
#pragma debug field 21 8 0 1 "__stck1" ;5,1
#pragma debug field 21 8 0 1 "__stck2" ;6,1
#pragma debug field 21 8 0 1 "__stpau" ;7,1
#pragma debug struct_end
#pragma debug union_begin 71 ""
#pragma debug field 2 70 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 71 1 ___stmc0 "__stmc0" 1
#pragma debug struct_begin 72 "__stmc1_bits"
#pragma debug field 21 8 0 1 "__stcclr" ;0,1
#pragma debug field 21 8 0 1 "__stdpx" ;1,1
#pragma debug field 21 8 0 1 "__stpol" ;2,1
#pragma debug field 21 8 0 1 "__stoc" ;3,1
#pragma debug field 21 8 0 1 "__stio0" ;4,1
#pragma debug field 21 8 0 1 "__stio1" ;5,1
#pragma debug field 21 8 0 1 "__stm0" ;6,1
#pragma debug field 21 8 0 1 "__stm1" ;7,1
#pragma debug struct_end
#pragma debug union_begin 73 ""
#pragma debug field 2 72 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 73 1 ___stmc1 "__stmc1" 1
#pragma debug variable 8 1 ___stmal "__stmal" 1
#pragma debug variable 8 1 ___stmah "__stmah" 1
#pragma debug struct_begin 74 "__ptmc0_bits"
#pragma debug field 21 8 0 3 ;0,3
#pragma debug field 21 8 0 1 "__pton" ;3,1
#pragma debug field 21 8 0 1 "__ptck0" ;4,1
#pragma debug field 21 8 0 1 "__ptck1" ;5,1
#pragma debug field 21 8 0 1 "__ptck2" ;6,1
#pragma debug field 21 8 0 1 "__ptpau" ;7,1
#pragma debug struct_end
#pragma debug union_begin 75 ""
#pragma debug field 2 74 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 75 1 ___ptmc0 "__ptmc0" 1
#pragma debug struct_begin 76 "__ptmc1_bits"
#pragma debug field 21 8 0 1 "__ptcclr" ;0,1
#pragma debug field 21 8 0 1 ;1,1
#pragma debug field 21 8 0 1 "__ptpol" ;2,1
#pragma debug field 21 8 0 1 "__ptoc" ;3,1
#pragma debug field 21 8 0 1 "__ptio0" ;4,1
#pragma debug field 21 8 0 1 "__ptio1" ;5,1
#pragma debug field 21 8 0 1 "__ptm0" ;6,1
#pragma debug field 21 8 0 1 "__ptm1" ;7,1
#pragma debug struct_end
#pragma debug union_begin 77 ""
#pragma debug field 2 76 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 77 1 ___ptmc1 "__ptmc1" 1
#pragma debug variable 8 1 ___ptmal "__ptmal" 1
#pragma debug variable 8 1 ___ptmah "__ptmah" 1
#pragma debug struct_begin 78 "__pc_bits"
#pragma debug field 21 8 0 1 "__pc0" ;0,1
#pragma debug field 21 8 0 1 "__pc1" ;1,1
#pragma debug field 21 8 0 1 "__pc2" ;2,1
#pragma debug field 21 8 0 1 "__pc3" ;3,1
#pragma debug field 21 8 0 1 "__pc4" ;4,1
#pragma debug field 21 8 0 1 "__pc5" ;5,1
#pragma debug field 21 8 0 1 "__pc6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 79 ""
#pragma debug field 2 78 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 79 1 ___pc "__pc" 1
#pragma debug struct_begin 80 "__pcc_bits"
#pragma debug field 21 8 0 1 "__pcc0" ;0,1
#pragma debug field 21 8 0 1 "__pcc1" ;1,1
#pragma debug field 21 8 0 1 "__pcc2" ;2,1
#pragma debug field 21 8 0 1 "__pcc3" ;3,1
#pragma debug field 21 8 0 1 "__pcc4" ;4,1
#pragma debug field 21 8 0 1 "__pcc5" ;5,1
#pragma debug field 21 8 0 1 "__pcc6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 81 ""
#pragma debug field 2 80 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 81 1 ___pcc "__pcc" 1
#pragma debug struct_begin 82 "__mfi1_bits"
#pragma debug field 21 8 0 1 "__ptmpe" ;0,1
#pragma debug field 21 8 0 1 "__ptmae" ;1,1
#pragma debug field 21 8 0 1 "__ctmpe" ;2,1
#pragma debug field 21 8 0 1 "__ctmae" ;3,1
#pragma debug field 21 8 0 1 "__ptmpf" ;4,1
#pragma debug field 21 8 0 1 "__ptmaf" ;5,1
#pragma debug field 21 8 0 1 "__ctmpf" ;6,1
#pragma debug field 21 8 0 1 "__ctmaf" ;7,1
#pragma debug struct_end
#pragma debug union_begin 83 ""
#pragma debug field 2 82 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 83 1 ___mfi1 "__mfi1" 1
#pragma debug struct_begin 84 "__sledc0_bits"
#pragma debug field 21 8 0 1 "__sledc00" ;0,1
#pragma debug field 21 8 0 1 "__sledc01" ;1,1
#pragma debug field 21 8 0 1 "__sledc02" ;2,1
#pragma debug field 21 8 0 1 "__sledc03" ;3,1
#pragma debug field 21 8 0 1 "__sledc04" ;4,1
#pragma debug field 21 8 0 1 "__sledc05" ;5,1
#pragma debug field 21 8 0 1 "__sledc06" ;6,1
#pragma debug field 21 8 0 1 "__sledc07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 85 ""
#pragma debug field 2 84 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 85 1 ___sledc0 "__sledc0" 1
#pragma debug struct_begin 86 "__sledc1_bits"
#pragma debug field 21 8 0 1 "__sledc10" ;0,1
#pragma debug field 21 8 0 1 "__sledc11" ;1,1
#pragma debug field 21 8 0 1 "__sledc12" ;2,1
#pragma debug field 21 8 0 1 "__sledc13" ;3,1
#pragma debug field 21 8 0 1 "__sledc14" ;4,1
#pragma debug field 21 8 0 1 "__sledc15" ;5,1
#pragma debug field 21 8 0 2 ;6,2
#pragma debug struct_end
#pragma debug union_begin 87 ""
#pragma debug field 2 86 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 87 1 ___sledc1 "__sledc1" 1
#pragma debug struct_begin 88 "__ifs_bits"
#pragma debug field 21 8 0 1 "__rxps" ;0,1
#pragma debug field 21 8 0 1 "__scsbps" ;1,1
#pragma debug field 21 8 0 1 "__sck_sclps" ;2,1
#pragma debug field 21 8 0 1 "__sdi_sdaps" ;3,1
#pragma debug field 21 8 0 1 "__int0ps" ;4,1
#pragma debug field 21 8 0 1 "__int1ps" ;5,1
#pragma debug field 21 8 0 2 ;6,2
#pragma debug struct_end
#pragma debug union_begin 89 ""
#pragma debug field 2 88 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 89 1 ___ifs "__ifs" 1
#pragma debug struct_begin 90 "__ucr1_bits"
#pragma debug field 21 8 0 1 "__tx8" ;0,1
#pragma debug field 21 8 0 1 "__rx8" ;1,1
#pragma debug field 21 8 0 1 "__txbrk" ;2,1
#pragma debug field 21 8 0 1 "__stops" ;3,1
#pragma debug field 21 8 0 1 "__prt" ;4,1
#pragma debug field 21 8 0 1 "__pren" ;5,1
#pragma debug field 21 8 0 1 "__bno" ;6,1
#pragma debug field 21 8 0 1 "__uren" ;7,1
#pragma debug struct_end
#pragma debug union_begin 91 ""
#pragma debug field 2 90 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 91 1 ___ucr1 "__ucr1" 1
#pragma debug struct_begin 92 "__ucr2_bits"
#pragma debug field 21 8 0 1 "__teie" ;0,1
#pragma debug field 21 8 0 1 "__tiie" ;1,1
#pragma debug field 21 8 0 1 "__rie" ;2,1
#pragma debug field 21 8 0 1 "__wake" ;3,1
#pragma debug field 21 8 0 1 "__adden" ;4,1
#pragma debug field 21 8 0 1 "__brgh" ;5,1
#pragma debug field 21 8 0 1 "__rxen" ;6,1
#pragma debug field 21 8 0 1 "__txen" ;7,1
#pragma debug struct_end
#pragma debug union_begin 93 ""
#pragma debug field 2 92 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 93 1 ___ucr2 "__ucr2" 1
#pragma debug struct_begin 94 "__brg_bits"
#pragma debug field 21 8 0 1 "__brg0" ;0,1
#pragma debug field 21 8 0 1 "__brg1" ;1,1
#pragma debug field 21 8 0 1 "__brg2" ;2,1
#pragma debug field 21 8 0 1 "__brg3" ;3,1
#pragma debug field 21 8 0 1 "__brg4" ;4,1
#pragma debug field 21 8 0 1 "__brg5" ;5,1
#pragma debug field 21 8 0 1 "__brg6" ;6,1
#pragma debug field 21 8 0 1 "__brg7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 95 ""
#pragma debug field 2 94 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 95 1 ___brg "__brg" 1
#pragma debug struct_begin 96 "__pas0_bits"
#pragma debug field 21 8 0 1 "__pas00" ;0,1
#pragma debug field 21 8 0 1 "__pas01" ;1,1
#pragma debug field 21 8 0 1 "__pas02" ;2,1
#pragma debug field 21 8 0 1 "__pas03" ;3,1
#pragma debug field 21 8 0 1 "__pas04" ;4,1
#pragma debug field 21 8 0 1 "__pas05" ;5,1
#pragma debug field 21 8 0 1 "__pas06" ;6,1
#pragma debug field 21 8 0 1 "__pas07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 97 ""
#pragma debug field 2 96 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 97 1 ___pas0 "__pas0" 1
#pragma debug struct_begin 98 "__pbs0_bits"
#pragma debug field 21 8 0 1 "__pbs00" ;0,1
#pragma debug field 21 8 0 1 "__pbs01" ;1,1
#pragma debug field 21 8 0 1 "__pbs02" ;2,1
#pragma debug field 21 8 0 1 "__pbs03" ;3,1
#pragma debug field 21 8 0 1 "__pbs04" ;4,1
#pragma debug field 21 8 0 1 "__pbs05" ;5,1
#pragma debug field 21 8 0 1 "__pbs06" ;6,1
#pragma debug field 21 8 0 1 "__pbs07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 99 ""
#pragma debug field 2 98 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 99 1 ___pbs0 "__pbs0" 1
#pragma debug struct_begin 100 "__pcs0_bits"
#pragma debug field 21 8 0 1 "__pcs00" ;0,1
#pragma debug field 21 8 0 1 "__pcs01" ;1,1
#pragma debug field 21 8 0 1 "__pcs02" ;2,1
#pragma debug field 21 8 0 1 "__pcs03" ;3,1
#pragma debug field 21 8 0 1 "__pcs04" ;4,1
#pragma debug field 21 8 0 1 "__pcs05" ;5,1
#pragma debug field 21 8 0 1 "__pcs06" ;6,1
#pragma debug field 21 8 0 1 "__pcs07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 101 ""
#pragma debug field 2 100 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 101 1 ___pcs0 "__pcs0" 1
#pragma debug struct_begin 102 "__ucr3_bits"
#pragma debug field 21 8 0 1 "__swm" ;0,1
#pragma debug field 21 8 0 7 ;1,7
#pragma debug struct_end
#pragma debug union_begin 103 ""
#pragma debug field 2 102 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 103 1 ___ucr3 "__ucr3" 1

; output external variables
extern _No_zero_cross_counter:byte
extern _gDownCounterValue:byte
extern _TriacTimeoutFlag:byte
extern r1:byte
extern r2:byte
#line 51 "d:\projects\bldc fan\remote fan final to production\global(longway)1\Remote Fan.c"
@code .section at 0 'code'
	jmp _main_startup1

extern _app:near

; 
; Generated by holtek-gcc v3.19, Tue Apr 05 13:18:20 2022
; Rebuild 718
; end of file
