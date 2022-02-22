.nolist
.include "/home/krunal/Projects/avr_assembly/m328pdef.inc" 
.list

ldi r16,low(RAMEND) ; RAMEND address 0x08ff
out SPL,r16 ; Stack Pointer Low SPL at i/o address 0x3d
ldi r16,high(RAMEND)
out SPH,r16
             

ldi r16,0b00100000
out DDRB,r16

ldi r16,0b00000000
out DDRD,r16
ldi r16, 0b00000101 ; the last 3 bits define the prescaler, 101 => division by 1024
out TCCR0B, r16

ldi r25,0x0f

loop:


    rcall BITSEP

    com r13 ;u'
    or r13,r12 ; u'+v
    mov r14,r12 ;v
    com r14 ;v'
    com r11 ;w'
    or r14,r11 ;v'+w'
    and r14,r13 ;ans
lsl r14
lsl r14
lsl r14
lsl r14
lsl r14
    out PortB,r14

    ldi r19, $32
    rcall DELAY

    rjmp loop

DELAY: ;this is delay (function)
               ;times to run the loop = 64 for 1 second delay
    lp2:
        IN r16, TIFR0 ;tifr is timer interupt flag (8 bit timer runs 256 times)
        ldi r17, 0b00000010
        AND r16, r17 ;need second bit
        BREQ DELAY
        OUT TIFR0, r17 ;set tifr flag high
        dec r19
        brne lp2
    ret




BITSEP:

    in r25, PinD
lsr r25
lsr r25
lsr r25
lsr r25
lsr r25
    mov r21, r25 ;w LSB
    sub r21,r20
    andi r21,0x01
    mov r11,r21

    mov r22, r25 ;v
    sub r22,r20
    andi r22,0x02
    lsr r22
    mov r12,r22

    mov r23, r25 ;u MSB
    sub r23,r20
    andi r23,0x04
    lsr r23
    lsr r23
    mov r13,r23


    ret


