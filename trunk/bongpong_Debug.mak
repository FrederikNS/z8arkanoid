#
# ZDS II Make File - bongpong, Debug
#

CC = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8lib

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
 -stdinc:"C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"  \
 -strict -NOwatch -cpu:Z8F6403  \
 -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"

AFLAGS =  \
 -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1  \
 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj  \
 -NOigcase  \
 -include:"C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"  \
 -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt  \
 -warn -NOzmasm -revaa -cpu:Z8F6403

OUTDIR = U:\z8proj\

Debug: bongpong

deltarget: 
	@if exist U:\z8proj\bongpong.lod  \
            del U:\z8proj\bongpong.lod

clean: 
	@if exist U:\z8proj\bongpong.lod  \
            del U:\z8proj\bongpong.lod
	@if exist U:\z8proj\zsldevinit.obj  \
            del U:\z8proj\zsldevinit.obj
	@if exist U:\z8proj\main.obj  \
            del U:\z8proj\main.obj
	@if exist U:\z8proj\ledframebuffer.obj  \
            del U:\z8proj\ledframebuffer.obj
	@if exist U:\z8proj\ledstring.obj  \
            del U:\z8proj\ledstring.obj
	@if exist U:\z8proj\ball.obj  \
            del U:\z8proj\ball.obj
	@if exist U:\z8proj\board.obj  \
            del U:\z8proj\board.obj
	@if exist U:\z8proj\game.obj  \
            del U:\z8proj\game.obj
	@if exist U:\z8proj\paddle.obj  \
            del U:\z8proj\paddle.obj
	@if exist U:\z8proj\sincoslut.obj  \
            del U:\z8proj\sincoslut.obj
	@if exist U:\z8proj\vector.obj  \
            del U:\z8proj\vector.obj
	@if exist U:\z8proj\timer.obj  \
            del U:\z8proj\timer.obj
	@if exist U:\z8proj\button.obj  \
            del U:\z8proj\button.obj
	@if exist U:\z8proj\hyperterm.obj  \
            del U:\z8proj\hyperterm.obj
	@if exist U:\z8proj\led.obj  \
            del U:\z8proj\led.obj
	@if exist U:\z8proj\lamemath.obj  \
            del U:\z8proj\lamemath.obj
	@if exist U:\z8proj\cracktro.obj  \
            del U:\z8proj\cracktro.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            U:\z8proj\zsldevinit.obj  \
            U:\z8proj\main.obj  \
            U:\z8proj\ledframebuffer.obj  \
            U:\z8proj\ledstring.obj  \
            U:\z8proj\ball.obj  \
            U:\z8proj\board.obj  \
            U:\z8proj\game.obj  \
            U:\z8proj\paddle.obj  \
            U:\z8proj\sincoslut.obj  \
            U:\z8proj\vector.obj  \
            U:\z8proj\timer.obj  \
            U:\z8proj\button.obj  \
            U:\z8proj\hyperterm.obj  \
            U:\z8proj\led.obj  \
            U:\z8proj\lamemath.obj  \
            U:\z8proj\cracktro.obj

bongpong: $(OBJS)
	 $(LINK)  @U:\z8proj\bongpong_Debug.linkcmd

U:\z8proj\zsldevinit.obj :  \
            U:\z8proj\zsldevinit.asm  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) U:\z8proj\zsldevinit.asm

U:\z8proj\main.obj :  \
            U:\z8proj\main.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            U:\z8proj\API\API.H  \
            U:\z8proj\API\LP8QOW~X.H  \
            U:\z8proj\API\L4T02W~Z.H  \
            U:\z8proj\HLI\HLI.h  \
            U:\z8proj\HLI\button.h  \
            U:\z8proj\HLI\HTA25T~V.H  \
            U:\z8proj\HLI\led.h  \
            U:\z8proj\HLI\timer.h  \
            U:\z8proj\cracktro\cracktro.h
	 $(CC)  $(CFLAGS) U:\z8proj\main.c

U:\z8proj\ledframebuffer.obj :  \
            U:\z8proj\API\ledframebuffer.c  \
            U:\z8proj\API\LP8QOW~X.H  \
            U:\z8proj\HLI\led.h
	 $(CC)  $(CFLAGS) U:\z8proj\API\ledframebuffer.c

U:\z8proj\ledstring.obj :  \
            U:\z8proj\API\ledstring.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            U:\z8proj\API\API.H  \
            U:\z8proj\API\LP8QOW~X.H  \
            U:\z8proj\API\L4T02W~Z.H  \
            U:\z8proj\HLI\HLI.h  \
            U:\z8proj\HLI\button.h  \
            U:\z8proj\HLI\HTA25T~V.H  \
            U:\z8proj\HLI\led.h  \
            U:\z8proj\HLI\timer.h  \
            U:\z8proj\math\lamemath.h  \
            U:\z8proj\math\math.h  \
            U:\z8proj\math\SGJV1T~5.H  \
            U:\z8proj\math\vector.h
	 $(CC)  $(CFLAGS) U:\z8proj\API\ledstring.c

U:\z8proj\ball.obj :  \
            U:\z8proj\game\ball.c
	 $(CC)  $(CFLAGS) U:\z8proj\game\ball.c

U:\z8proj\board.obj :  \
            U:\z8proj\game\board.c  \
            U:\z8proj\game\board.h
	 $(CC)  $(CFLAGS) U:\z8proj\game\board.c

U:\z8proj\game.obj :  \
            U:\z8proj\game\game.c
	 $(CC)  $(CFLAGS) U:\z8proj\game\game.c

U:\z8proj\paddle.obj :  \
            U:\z8proj\game\paddle.c  \
            U:\z8proj\game\paddle.h
	 $(CC)  $(CFLAGS) U:\z8proj\game\paddle.c

U:\z8proj\sincoslut.obj :  \
            U:\z8proj\math\sincoslut.c
	 $(CC)  $(CFLAGS) U:\z8proj\math\sincoslut.c

U:\z8proj\vector.obj :  \
            U:\z8proj\math\vector.c
	 $(CC)  $(CFLAGS) U:\z8proj\math\vector.c

U:\z8proj\timer.obj :  \
            U:\z8proj\HLI\timer.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            U:\z8proj\HLI\timer.h
	 $(CC)  $(CFLAGS) U:\z8proj\HLI\timer.c

U:\z8proj\button.obj :  \
            U:\z8proj\HLI\button.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) U:\z8proj\HLI\button.c

U:\z8proj\hyperterm.obj :  \
            U:\z8proj\HLI\hyperterm.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            U:\z8proj\HLI\HTA25T~V.H
	 $(CC)  $(CFLAGS) U:\z8proj\HLI\hyperterm.c

U:\z8proj\led.obj :  \
            U:\z8proj\HLI\led.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            U:\z8proj\HLI\led.h  \
            U:\z8proj\math\lamemath.h
	 $(CC)  $(CFLAGS) U:\z8proj\HLI\led.c

U:\z8proj\lamemath.obj :  \
            U:\z8proj\math\lamemath.c  \
            U:\z8proj\math\lamemath.h
	 $(CC)  $(CFLAGS) U:\z8proj\math\lamemath.c

U:\z8proj\cracktro.obj :  \
            U:\z8proj\cracktro\cracktro.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            U:\z8proj\API\API.H  \
            U:\z8proj\API\LP8QOW~X.H  \
            U:\z8proj\API\L4T02W~Z.H  \
            U:\z8proj\HLI\HLI.h  \
            U:\z8proj\HLI\button.h  \
            U:\z8proj\HLI\HTA25T~V.H  \
            U:\z8proj\HLI\led.h  \
            U:\z8proj\HLI\timer.h  \
            U:\z8proj\math\lamemath.h  \
            U:\z8proj\math\math.h  \
            U:\z8proj\math\SGJV1T~5.H  \
            U:\z8proj\math\vector.h
	 $(CC)  $(CFLAGS) U:\z8proj\cracktro\cracktro.c

