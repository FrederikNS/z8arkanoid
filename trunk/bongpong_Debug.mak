#
# ZDS II Make File - bongpong, Debug
#

CC = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~1\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\z8project\bongpong_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\z8project\bongpong_Debug.asmsw

OUTDIR = C:\z8project\

Debug: bongpong

deltarget: 
	@if exist C:\z8project\bongpong.lod  \
            del C:\z8project\bongpong.lod

clean: 
	@if exist C:\z8project\bongpong.lod  \
            del C:\z8project\bongpong.lod
	@if exist C:\z8project\zsldevinit.obj  \
            del C:\z8project\zsldevinit.obj
	@if exist C:\z8project\main.obj  \
            del C:\z8project\main.obj
	@if exist C:\z8project\ledframebuffer.obj  \
            del C:\z8project\ledframebuffer.obj
	@if exist C:\z8project\ledstring.obj  \
            del C:\z8project\ledstring.obj
	@if exist C:\z8project\ball.obj  \
            del C:\z8project\ball.obj
	@if exist C:\z8project\game.obj  \
            del C:\z8project\game.obj
	@if exist C:\z8project\paddle.obj  \
            del C:\z8project\paddle.obj
	@if exist C:\z8project\sincoslut.obj  \
            del C:\z8project\sincoslut.obj
	@if exist C:\z8project\vector.obj  \
            del C:\z8project\vector.obj
	@if exist C:\z8project\timer.obj  \
            del C:\z8project\timer.obj
	@if exist C:\z8project\button.obj  \
            del C:\z8project\button.obj
	@if exist C:\z8project\led.obj  \
            del C:\z8project\led.obj
	@if exist C:\z8project\lamemath.obj  \
            del C:\z8project\lamemath.obj
	@if exist C:\z8project\blocks.obj  \
            del C:\z8project\blocks.obj
	@if exist C:\z8project\collision.obj  \
            del C:\z8project\collision.obj
	@if exist C:\z8project\hyperterm.obj  \
            del C:\z8project\hyperterm.obj
	@if exist C:\z8project\gameboard.obj  \
            del C:\z8project\gameboard.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\z8project\zsldevinit.obj  \
            C:\z8project\main.obj  \
            C:\z8project\ledframebuffer.obj  \
            C:\z8project\ledstring.obj  \
            C:\z8project\ball.obj  \
            C:\z8project\game.obj  \
            C:\z8project\paddle.obj  \
            C:\z8project\sincoslut.obj  \
            C:\z8project\vector.obj  \
            C:\z8project\timer.obj  \
            C:\z8project\button.obj  \
            C:\z8project\led.obj  \
            C:\z8project\lamemath.obj  \
            C:\z8project\blocks.obj  \
            C:\z8project\collision.obj  \
            C:\z8project\hyperterm.obj  \
            C:\z8project\gameboard.obj

bongpong: $(OBJS)
	 $(LINK)  @C:\z8project\bongpong_Debug.linkcmd

C:\z8project\zsldevinit.obj :  \
            C:\z8project\zsldevinit.asm  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\z8project\zsldevinit.asm

C:\z8project\main.obj :  \
            C:\z8project\main.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Z8PROJ~1\API\API.H  \
            C:\Z8PROJ~1\API\HYPERT~1.H  \
            C:\Z8PROJ~1\API\LEDFRA~1.H  \
            C:\Z8PROJ~1\API\LEDSTR~1.H  \
            C:\Z8PROJ~1\HLI\HLI.h  \
            C:\Z8PROJ~1\HLI\button.h  \
            C:\Z8PROJ~1\HLI\led.h  \
            C:\Z8PROJ~1\HLI\timer.h  \
            C:\Z8PROJ~1\game\ball.h  \
            C:\Z8PROJ~1\game\blocks.h  \
            C:\Z8PROJ~1\game\COLLIS~1.H  \
            C:\Z8PROJ~1\game\game.h  \
            C:\Z8PROJ~1\game\GAMEBO~1.H  \
            C:\Z8PROJ~1\game\paddle.h
	 $(CC)  $(CFLAGS) C:\z8project\main.c

C:\z8project\ledframebuffer.obj :  \
            C:\z8project\API\ledframebuffer.c  \
            C:\Z8PROJ~1\API\LEDFRA~1.H  \
            C:\Z8PROJ~1\HLI\led.h
	 $(CC)  $(CFLAGS) C:\z8project\API\ledframebuffer.c

C:\z8project\ledstring.obj :  \
            C:\z8project\API\ledstring.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Z8PROJ~1\API\API.H  \
            C:\Z8PROJ~1\API\HYPERT~1.H  \
            C:\Z8PROJ~1\API\LEDFRA~1.H  \
            C:\Z8PROJ~1\API\LEDSTR~1.H  \
            C:\Z8PROJ~1\HLI\HLI.h  \
            C:\Z8PROJ~1\HLI\button.h  \
            C:\Z8PROJ~1\HLI\led.h  \
            C:\Z8PROJ~1\HLI\timer.h  \
            C:\Z8PROJ~1\math\lamemath.h  \
            C:\Z8PROJ~1\math\math.h  \
            C:\Z8PROJ~1\math\SINCOS~1.H  \
            C:\Z8PROJ~1\math\vector.h
	 $(CC)  $(CFLAGS) C:\z8project\API\ledstring.c

C:\z8project\ball.obj :  \
            C:\z8project\game\ball.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\Z8PROJ~1\API\HYPERT~1.H  \
            C:\Z8PROJ~1\game\ball.h  \
            C:\Z8PROJ~1\game\blocks.h  \
            C:\Z8PROJ~1\game\paddle.h  \
            C:\Z8PROJ~1\math\lamemath.h  \
            C:\Z8PROJ~1\math\math.h  \
            C:\Z8PROJ~1\math\SINCOS~1.H  \
            C:\Z8PROJ~1\math\vector.h
	 $(CC)  $(CFLAGS) C:\z8project\game\ball.c

C:\z8project\game.obj :  \
            C:\z8project\game\game.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDLIB.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Z8PROJ~1\API\API.H  \
            C:\Z8PROJ~1\API\HYPERT~1.H  \
            C:\Z8PROJ~1\API\LEDFRA~1.H  \
            C:\Z8PROJ~1\API\LEDSTR~1.H  \
            C:\Z8PROJ~1\HLI\HLI.h  \
            C:\Z8PROJ~1\HLI\button.h  \
            C:\Z8PROJ~1\HLI\led.h  \
            C:\Z8PROJ~1\HLI\timer.h  \
            C:\Z8PROJ~1\game\ball.h  \
            C:\Z8PROJ~1\game\blocks.h  \
            C:\Z8PROJ~1\game\COLLIS~1.H  \
            C:\Z8PROJ~1\game\game.h  \
            C:\Z8PROJ~1\game\GAMEBO~1.H  \
            C:\Z8PROJ~1\game\paddle.h
	 $(CC)  $(CFLAGS) C:\z8project\game\game.c

C:\z8project\paddle.obj :  \
            C:\z8project\game\paddle.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Z8PROJ~1\API\API.H  \
            C:\Z8PROJ~1\API\HYPERT~1.H  \
            C:\Z8PROJ~1\API\LEDFRA~1.H  \
            C:\Z8PROJ~1\API\LEDSTR~1.H  \
            C:\Z8PROJ~1\HLI\HLI.h  \
            C:\Z8PROJ~1\HLI\button.h  \
            C:\Z8PROJ~1\HLI\led.h  \
            C:\Z8PROJ~1\HLI\timer.h  \
            C:\Z8PROJ~1\game\paddle.h
	 $(CC)  $(CFLAGS) C:\z8project\game\paddle.c

C:\z8project\sincoslut.obj :  \
            C:\z8project\math\sincoslut.c  \
            C:\Z8PROJ~1\math\SINCOS~1.H
	 $(CC)  $(CFLAGS) C:\z8project\math\sincoslut.c

C:\z8project\vector.obj :  \
            C:\z8project\math\vector.c
	 $(CC)  $(CFLAGS) C:\z8project\math\vector.c

C:\z8project\timer.obj :  \
            C:\z8project\HLI\timer.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Z8PROJ~1\HLI\timer.h
	 $(CC)  $(CFLAGS) C:\z8project\HLI\timer.c

C:\z8project\button.obj :  \
            C:\z8project\HLI\button.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\z8project\HLI\button.c

C:\z8project\led.obj :  \
            C:\z8project\HLI\led.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Z8PROJ~1\HLI\led.h  \
            C:\Z8PROJ~1\math\lamemath.h
	 $(CC)  $(CFLAGS) C:\z8project\HLI\led.c

C:\z8project\lamemath.obj :  \
            C:\z8project\math\lamemath.c  \
            C:\Z8PROJ~1\math\lamemath.h
	 $(CC)  $(CFLAGS) C:\z8project\math\lamemath.c

C:\z8project\blocks.obj :  \
            C:\z8project\game\blocks.c  \
            C:\Z8PROJ~1\API\API.H  \
            C:\Z8PROJ~1\API\HYPERT~1.H  \
            C:\Z8PROJ~1\API\LEDFRA~1.H  \
            C:\Z8PROJ~1\API\LEDSTR~1.H  \
            C:\Z8PROJ~1\game\blocks.h
	 $(CC)  $(CFLAGS) C:\z8project\game\blocks.c

C:\z8project\collision.obj :  \
            C:\z8project\game\collision.c  \
            C:\Z8PROJ~1\game\ball.h  \
            C:\Z8PROJ~1\game\blocks.h  \
            C:\Z8PROJ~1\game\COLLIS~1.H  \
            C:\Z8PROJ~1\game\game.h  \
            C:\Z8PROJ~1\game\GAMEBO~1.H  \
            C:\Z8PROJ~1\game\paddle.h
	 $(CC)  $(CFLAGS) C:\z8project\game\collision.c

C:\z8project\hyperterm.obj :  \
            C:\z8project\API\hyperterm.c  \
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
            C:\Z8PROJ~1\API\HYPERT~1.H
	 $(CC)  $(CFLAGS) C:\z8project\API\hyperterm.c

C:\z8project\gameboard.obj :  \
            C:\z8project\game\gameboard.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Z8PROJ~1\API\API.H  \
            C:\Z8PROJ~1\API\HYPERT~1.H  \
            C:\Z8PROJ~1\API\LEDFRA~1.H  \
            C:\Z8PROJ~1\API\LEDSTR~1.H  \
            C:\Z8PROJ~1\game\GAMEBO~1.H
	 $(CC)  $(CFLAGS) C:\z8project\game\gameboard.c

