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

OUTDIR = C:\Projects\zilog\project\

Debug: bongpong

deltarget: 
	@if exist C:\Projects\zilog\project\bongpong.lod  \
            del C:\Projects\zilog\project\bongpong.lod

clean: 
	@if exist C:\Projects\zilog\project\bongpong.lod  \
            del C:\Projects\zilog\project\bongpong.lod
	@if exist C:\Projects\zilog\project\zsldevinit.obj  \
            del C:\Projects\zilog\project\zsldevinit.obj
	@if exist C:\Projects\zilog\project\main.obj  \
            del C:\Projects\zilog\project\main.obj
	@if exist C:\Projects\zilog\project\ledframebuffer.obj  \
            del C:\Projects\zilog\project\ledframebuffer.obj
	@if exist C:\Projects\zilog\project\ledstring.obj  \
            del C:\Projects\zilog\project\ledstring.obj
	@if exist C:\Projects\zilog\project\ball.obj  \
            del C:\Projects\zilog\project\ball.obj
	@if exist C:\Projects\zilog\project\board.obj  \
            del C:\Projects\zilog\project\board.obj
	@if exist C:\Projects\zilog\project\game.obj  \
            del C:\Projects\zilog\project\game.obj
	@if exist C:\Projects\zilog\project\paddle.obj  \
            del C:\Projects\zilog\project\paddle.obj
	@if exist C:\Projects\zilog\project\sincoslut.obj  \
            del C:\Projects\zilog\project\sincoslut.obj
	@if exist C:\Projects\zilog\project\vector.obj  \
            del C:\Projects\zilog\project\vector.obj
	@if exist C:\Projects\zilog\project\timer.obj  \
            del C:\Projects\zilog\project\timer.obj
	@if exist C:\Projects\zilog\project\button.obj  \
            del C:\Projects\zilog\project\button.obj
	@if exist C:\Projects\zilog\project\hyperterm.obj  \
            del C:\Projects\zilog\project\hyperterm.obj
	@if exist C:\Projects\zilog\project\led.obj  \
            del C:\Projects\zilog\project\led.obj
	@if exist C:\Projects\zilog\project\lamemath.obj  \
            del C:\Projects\zilog\project\lamemath.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Projects\zilog\project\zsldevinit.obj  \
            C:\Projects\zilog\project\main.obj  \
            C:\Projects\zilog\project\ledframebuffer.obj  \
            C:\Projects\zilog\project\ledstring.obj  \
            C:\Projects\zilog\project\ball.obj  \
            C:\Projects\zilog\project\board.obj  \
            C:\Projects\zilog\project\game.obj  \
            C:\Projects\zilog\project\paddle.obj  \
            C:\Projects\zilog\project\sincoslut.obj  \
            C:\Projects\zilog\project\vector.obj  \
            C:\Projects\zilog\project\timer.obj  \
            C:\Projects\zilog\project\button.obj  \
            C:\Projects\zilog\project\hyperterm.obj  \
            C:\Projects\zilog\project\led.obj  \
            C:\Projects\zilog\project\lamemath.obj

bongpong: $(OBJS)
	 $(LINK)  @C:\Projects\zilog\project\bongpong_Debug.linkcmd

C:\Projects\zilog\project\zsldevinit.obj :  \
            C:\Projects\zilog\project\zsldevinit.asm  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Projects\zilog\project\zsldevinit.asm

C:\Projects\zilog\project\main.obj :  \
            C:\Projects\zilog\project\main.c  \
            C:\Projects\zilog\project\API\API.h  \
            C:\Projects\zilog\project\API\ledframebuffer.h  \
            C:\Projects\zilog\project\API\ledstring.h  \
            C:\Projects\zilog\project\HLI\HLI.h  \
            C:\Projects\zilog\project\HLI\button.h  \
            C:\Projects\zilog\project\HLI\hyperterm.h  \
            C:\Projects\zilog\project\HLI\led.h  \
            C:\Projects\zilog\project\HLI\timer.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\main.c

C:\Projects\zilog\project\ledframebuffer.obj :  \
            C:\Projects\zilog\project\API\ledframebuffer.c  \
            C:\Projects\zilog\project\API\ledframebuffer.h  \
            C:\Projects\zilog\project\HLI\led.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\API\ledframebuffer.c

C:\Projects\zilog\project\ledstring.obj :  \
            C:\Projects\zilog\project\API\ledstring.c  \
            C:\Projects\zilog\project\API\API.h  \
            C:\Projects\zilog\project\API\ledframebuffer.h  \
            C:\Projects\zilog\project\API\ledstring.h  \
            C:\Projects\zilog\project\HLI\HLI.h  \
            C:\Projects\zilog\project\HLI\button.h  \
            C:\Projects\zilog\project\HLI\hyperterm.h  \
            C:\Projects\zilog\project\HLI\led.h  \
            C:\Projects\zilog\project\HLI\timer.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\API\ledstring.c

C:\Projects\zilog\project\ball.obj :  \
            C:\Projects\zilog\project\game\ball.c
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\game\ball.c

C:\Projects\zilog\project\board.obj :  \
            C:\Projects\zilog\project\game\board.c  \
            C:\Projects\zilog\project\game\board.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\game\board.c

C:\Projects\zilog\project\game.obj :  \
            C:\Projects\zilog\project\game\game.c
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\game\game.c

C:\Projects\zilog\project\paddle.obj :  \
            C:\Projects\zilog\project\game\paddle.c
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\game\paddle.c

C:\Projects\zilog\project\sincoslut.obj :  \
            C:\Projects\zilog\project\math\sincoslut.c
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\math\sincoslut.c

C:\Projects\zilog\project\vector.obj :  \
            C:\Projects\zilog\project\math\vector.c
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\math\vector.c

C:\Projects\zilog\project\timer.obj :  \
            C:\Projects\zilog\project\HLI\timer.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\project\HLI\timer.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\HLI\timer.c

C:\Projects\zilog\project\button.obj :  \
            C:\Projects\zilog\project\HLI\button.c
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\HLI\button.c

C:\Projects\zilog\project\hyperterm.obj :  \
            C:\Projects\zilog\project\HLI\hyperterm.c  \
            C:\Projects\zilog\project\HLI\hyperterm.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\HLI\hyperterm.c

C:\Projects\zilog\project\led.obj :  \
            C:\Projects\zilog\project\HLI\led.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_Z8Encore!_4.9.3\include\zilog\uartdefs.h  \
            C:\Projects\zilog\project\HLI\led.h  \
            C:\Projects\zilog\project\math\lamemath.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\HLI\led.c

C:\Projects\zilog\project\lamemath.obj :  \
            C:\Projects\zilog\project\math\lamemath.c  \
            C:\Projects\zilog\project\math\lamemath.h
	 $(CC)  $(CFLAGS) C:\Projects\zilog\project\math\lamemath.c

