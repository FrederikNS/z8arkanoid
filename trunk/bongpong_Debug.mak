#
# ZDS II Make File - bongpong, Debug
#

CC = @C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\bin\eZ8cc
ASM = @C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\bin\eZ8asm
LINK = @C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\bin\eZ8link
LIB = @C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\bin\eZ8lib

CFLAGS =  \
 -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug  \
 -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY  \
 -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32  \
 -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy  \
 -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc  \
 -NOjmpopt -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy  \
 -localcse -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L  \
 -NOoptlink -optsize -peephole -NOpromote -quiet -regvar -revaa  \
 -NOsdiopt -shortsize:16  \
 -stdinc:"C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\std;C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog;C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\Z8Encore_F640X"  \
 -strict -NOwatch -cpu:Z8F6403  \
 -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\std;C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog;C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\Z8Encore_F640X -revaa"

AFLAGS =  \
 -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1  \
 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj  \
 -NOigcase  \
 -include:"C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\std;C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog;C:\Programmer\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\Z8Encore_F640X"  \
 -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt  \
 -warn -NOzmasm -revaa -cpu:Z8F6403

OUTDIR = C:\Projects\zilog\z8proj\

Debug: bongpong

deltarget: 
	@if exist C:\Projects\zilog\z8proj\bongpong.lod  \
            del C:\Projects\zilog\z8proj\bongpong.lod

clean: 
	@if exist C:\Projects\zilog\z8proj\bongpong.lod  \
            del C:\Projects\zilog\z8proj\bongpong.lod
	@if exist C:\Projects\zilog\z8proj\zsldevinit.obj  \
            del C:\Projects\zilog\z8proj\zsldevinit.obj
	@if exist C:\Projects\zilog\z8proj\main.obj  \
            del C:\Projects\zilog\z8proj\main.obj
	@if exist C:\Projects\zilog\z8proj\ledframebuffer.obj  \
            del C:\Projects\zilog\z8proj\ledframebuffer.obj
	@if exist C:\Projects\zilog\z8proj\ledstring.obj  \
            del C:\Projects\zilog\z8proj\ledstring.obj
	@if exist C:\Projects\zilog\z8proj\ball.obj  \
            del C:\Projects\zilog\z8proj\ball.obj
	@if exist C:\Projects\zilog\z8proj\board.obj  \
            del C:\Projects\zilog\z8proj\board.obj
	@if exist C:\Projects\zilog\z8proj\game.obj  \
            del C:\Projects\zilog\z8proj\game.obj
	@if exist C:\Projects\zilog\z8proj\paddle.obj  \
            del C:\Projects\zilog\z8proj\paddle.obj
	@if exist C:\Projects\zilog\z8proj\sincoslut.obj  \
            del C:\Projects\zilog\z8proj\sincoslut.obj
	@if exist C:\Projects\zilog\z8proj\vector.obj  \
            del C:\Projects\zilog\z8proj\vector.obj
	@if exist C:\Projects\zilog\z8proj\timer.obj  \
            del C:\Projects\zilog\z8proj\timer.obj
	@if exist C:\Projects\zilog\z8proj\button.obj  \
            del C:\Projects\zilog\z8proj\button.obj
	@if exist C:\Projects\zilog\z8proj\hyperterm.obj  \
            del C:\Projects\zilog\z8proj\hyperterm.obj
	@if exist C:\Projects\zilog\z8proj\led.obj  \
            del C:\Projects\zilog\z8proj\led.obj
	@if exist C:\Projects\zilog\z8proj\lamemath.obj  \
            del C:\Projects\zilog\z8proj\lamemath.obj
	@if exist C:\Projects\zilog\z8proj\cracktro.obj  \
            del C:\Projects\zilog\z8proj\cracktro.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Projects\zilog\z8proj\zsldevinit.obj  \
            C:\Projects\zilog\z8proj\main.obj  \
            C:\Projects\zilog\z8proj\ledframebuffer.obj  \
            C:\Projects\zilog\z8proj\ledstring.obj  \
            C:\Projects\zilog\z8proj\ball.obj  \
            C:\Projects\zilog\z8proj\board.obj  \
            C:\Projects\zilog\z8proj\game.obj  \
            C:\Projects\zilog\z8proj\paddle.obj  \
            C:\Projects\zilog\z8proj\sincoslut.obj  \
            C:\Projects\zilog\z8proj\vector.obj  \
            C:\Projects\zilog\z8proj\timer.obj  \
            C:\Projects\zilog\z8proj\button.obj  \
            C:\Projects\zilog\z8proj\hyperterm.obj  \
            C:\Projects\zilog\z8proj\led.obj  \
            C:\Projects\zilog\z8proj\lamemath.obj  \
            C:\Projects\zilog\z8proj\cracktro.obj

bongpong: $(OBJS)
	 $(LINK)  @C:\Projects\zilog\z8proj\bongpong_Debug.linkcmd

C:\Projects\zilog\z8proj\zsldevinit.obj :  \
            C:\Projects\zilog\z8proj\zsldevinit.asm  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Projects\zilog\z8proj\zsldevinit.asm

C:\Projects\zilog\z8proj\main.obj :  \
            C:\Projects\zilog\z8proj\main.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\API\API.H  \
            C:\Projects\zilog\z8proj\API\ledframebuffer.h  \
            C:\Projects\zilog\z8proj\API\ledstring.h  \
            C:\Projects\zilog\z8proj\HLI\HLI.h  \
            C:\Projects\zilog\z8proj\HLI\button.h  \
            C:\Projects\zilog\z8proj\HLI\hyperterm.h  \
            C:\Projects\zilog\z8proj\HLI\led.h  \
            C:\Projects\zilog\z8proj\HLI\timer.h  \
            C:\Projects\zilog\z8proj\cracktro\cracktro.h  \
            C:\Projects\zilog\z8proj\game\ball.h  \
            C:\Projects\zilog\z8proj\game\board.h  \
            C:\Projects\zilog\z8proj\game\game.h  \
            C:\Projects\zilog\z8proj\game\paddle.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\main.c

C:\Projects\zilog\z8proj\ledframebuffer.obj :  \
            C:\Projects\zilog\z8proj\API\ledframebuffer.c  \
            C:\Projects\zilog\z8proj\API\ledframebuffer.h  \
            C:\Projects\zilog\z8proj\HLI\led.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\API\ledframebuffer.c

C:\Projects\zilog\z8proj\ledstring.obj :  \
            C:\Projects\zilog\z8proj\API\ledstring.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\API\API.H  \
            C:\Projects\zilog\z8proj\API\ledframebuffer.h  \
            C:\Projects\zilog\z8proj\API\ledstring.h  \
            C:\Projects\zilog\z8proj\HLI\HLI.h  \
            C:\Projects\zilog\z8proj\HLI\button.h  \
            C:\Projects\zilog\z8proj\HLI\hyperterm.h  \
            C:\Projects\zilog\z8proj\HLI\led.h  \
            C:\Projects\zilog\z8proj\HLI\timer.h  \
            C:\Projects\zilog\z8proj\math\lamemath.h  \
            C:\Projects\zilog\z8proj\math\math.h  \
            C:\Projects\zilog\z8proj\math\sincoslut.h  \
            C:\Projects\zilog\z8proj\math\vector.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\API\ledstring.c

C:\Projects\zilog\z8proj\ball.obj :  \
            C:\Projects\zilog\z8proj\game\ball.c  \
            C:\Projects\zilog\z8proj\game\ball.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\game\ball.c

C:\Projects\zilog\z8proj\board.obj :  \
            C:\Projects\zilog\z8proj\game\board.c  \
            C:\Projects\zilog\z8proj\game\board.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\game\board.c

C:\Projects\zilog\z8proj\game.obj :  \
            C:\Projects\zilog\z8proj\game\game.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\API\API.H  \
            C:\Projects\zilog\z8proj\API\ledframebuffer.h  \
            C:\Projects\zilog\z8proj\API\ledstring.h  \
            C:\Projects\zilog\z8proj\HLI\HLI.h  \
            C:\Projects\zilog\z8proj\HLI\button.h  \
            C:\Projects\zilog\z8proj\HLI\hyperterm.h  \
            C:\Projects\zilog\z8proj\HLI\led.h  \
            C:\Projects\zilog\z8proj\HLI\timer.h  \
            C:\Projects\zilog\z8proj\game\ball.h  \
            C:\Projects\zilog\z8proj\game\board.h  \
            C:\Projects\zilog\z8proj\game\game.h  \
            C:\Projects\zilog\z8proj\game\paddle.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\game\game.c

C:\Projects\zilog\z8proj\paddle.obj :  \
            C:\Projects\zilog\z8proj\game\paddle.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\API\API.H  \
            C:\Projects\zilog\z8proj\API\ledframebuffer.h  \
            C:\Projects\zilog\z8proj\API\ledstring.h  \
            C:\Projects\zilog\z8proj\HLI\HLI.h  \
            C:\Projects\zilog\z8proj\HLI\button.h  \
            C:\Projects\zilog\z8proj\HLI\hyperterm.h  \
            C:\Projects\zilog\z8proj\HLI\led.h  \
            C:\Projects\zilog\z8proj\HLI\timer.h  \
            C:\Projects\zilog\z8proj\game\paddle.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\game\paddle.c

C:\Projects\zilog\z8proj\sincoslut.obj :  \
            C:\Projects\zilog\z8proj\math\sincoslut.c  \
            C:\Projects\zilog\z8proj\math\sincoslut.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\math\sincoslut.c

C:\Projects\zilog\z8proj\vector.obj :  \
            C:\Projects\zilog\z8proj\math\vector.c
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\math\vector.c

C:\Projects\zilog\z8proj\timer.obj :  \
            C:\Projects\zilog\z8proj\HLI\timer.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\HLI\timer.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\HLI\timer.c

C:\Projects\zilog\z8proj\button.obj :  \
            C:\Projects\zilog\z8proj\HLI\button.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\HLI\button.c

C:\Projects\zilog\z8proj\hyperterm.obj :  \
            C:\Projects\zilog\z8proj\HLI\hyperterm.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\std\format.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\std\stdarg.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\std\stdio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\sio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\HLI\hyperterm.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\HLI\hyperterm.c

C:\Projects\zilog\z8proj\led.obj :  \
            C:\Projects\zilog\z8proj\HLI\led.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\HLI\led.h  \
            C:\Projects\zilog\z8proj\math\lamemath.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\HLI\led.c

C:\Projects\zilog\z8proj\lamemath.obj :  \
            C:\Projects\zilog\z8proj\math\lamemath.c  \
            C:\Projects\zilog\z8proj\math\lamemath.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\math\lamemath.c

C:\Projects\zilog\z8proj\cracktro.obj :  \
            C:\Projects\zilog\z8proj\cracktro\cracktro.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\std\stdlib.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\eZ8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\z8proj\API\API.H  \
            C:\Projects\zilog\z8proj\API\ledframebuffer.h  \
            C:\Projects\zilog\z8proj\API\ledstring.h  \
            C:\Projects\zilog\z8proj\HLI\HLI.h  \
            C:\Projects\zilog\z8proj\HLI\button.h  \
            C:\Projects\zilog\z8proj\HLI\hyperterm.h  \
            C:\Projects\zilog\z8proj\HLI\led.h  \
            C:\Projects\zilog\z8proj\HLI\timer.h  \
            C:\Projects\zilog\z8proj\math\lamemath.h  \
            C:\Projects\zilog\z8proj\math\math.h  \
            C:\Projects\zilog\z8proj\math\sincoslut.h  \
            C:\Projects\zilog\z8proj\math\vector.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\z8proj\cracktro\cracktro.c

