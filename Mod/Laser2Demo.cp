MODULE Laser2Demo; (*$MAIN*)

(*   LASER BASIC 2 Demo for Sinclair ZX Spectrum 48 Kb   *)
(* Copyright (C) 2016 Oleg N. Cher, VEDAsoft Oberon Club *)

IMPORT gr := Laser2, b := Basic, Retro;

(* ������ ���� �� ����� "��� �������� ���� ��� ZX Spectrum" *)

(*
10 BORDER 0: PAPER 0:INK 5
20 CLS: LET S=-2
30 FOR N=7 TO 10
40 .R0W=5:.C0L=S:.SPN=N
50 .PTBL
60 PAUSE 5
70 NEXT N
80 LET S=S+2
90 IF S<32 THEN GO TO 30
*)

CONST
  FrameSizeBytes = 5(*hdr*) + 8*20(*data*) ;

TYPE
  Sprites = ARRAY FrameSizeBytes * 4 (*frames*) + 1 OF CHAR;

CONST
  Chudik = Sprites (

    (* Phase 1: *)

    1X, CHR( FrameSizeBytes-2 ), 0X, 5X, 4X, (* SPN, offset, LEN, HGT *)
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    030X,048X,048X,030X,010X,010X,010X,009X,
    030X,048X,048X,030X,020X,040X,080X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    007X,00CX,019X,01CX,01FX,01FX,00FX,002X,
    080X,07CX,07EX,0FEX,0F0X,080X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    01FX,03FX,07FX,07FX,07EX,060X,0F0X,07FX,
    080X,0C0X,0C0X,000X,000X,000X,0E0X,080X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,

    (* Phase 2: *)

    2X, CHR( FrameSizeBytes-2 ), 0X, 5X, 4X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,018X,024X,024X,018X,004X,
    000X,000X,000X,000X,006X,009X,009X,006X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    002X,003X,007X,00EX,00FX,00FX,00FX,007X,
    008X,0E0X,018X,05EX,03FX,0FFX,0E7X,0C3X,
    000X,000X,000X,000X,000X,080X,080X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    001X,00FX,01FX,01FX,007X,007X,01EX,018X,
    080X,0F0X,0FCX,0FEX,0FCX,038X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    03FX,000X,000X,000X,000X,000X,000X,000X,
    080X,060X,030X,018X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,

    (* Phase 3: *)

    3X, CHR( FrameSizeBytes-2 ), 0X, 5X, 4X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    003X,004X,004X,003X,000X,000X,000X,000X,
    000X,0E1X,092X,00AX,03EX,071X,0E5X,0F3X,
    030X,0C8X,048X,030X,000X,0F0X,0F8X,0F8X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,001X,001X,000X,
    0FFX,0FEX,07CX,018X,0FFX,0FFX,0FFX,07FX,
    0E0X,000X,000X,000X,000X,0C0X,0E0X,0C0X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,001X,001X,003X,000X,000X,000X,000X,
    061X,0C0X,080X,0FFX,000X,000X,000X,000X,
    080X,000X,000X,080X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,

    (* Phase 4: *)

    4X, CHR( FrameSizeBytes-2 ), 0X, 5X, 4X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,006X,009X,009X,006X,
    000X,000X,000X,000X,080X,040X,040X,080X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    002X,002X,002X,001X,007X,00EX,01CX,01EX,
    000X,000X,006X,01FX,0FFX,03EX,0BCX,070X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    01FX,01FX,00FX,003X,00FX,01FX,01FX,007X,
    0C0X,0C0X,080X,000X,0C0X,0E0X,0E0X,0E0X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,
    00EX,01CX,01CX,00FX,000X,000X,000X,000X,
    0C4X,018X,060X,080X,000X,000X,000X,000X,
    000X,000X,000X,000X,000X,000X,000X,000X,

    0X
  );

VAR
  x, phase: BYTE;

BEGIN
  b.Init;
  b.COLOR(b.Bright + b.Black*b.Paper + b.Yellow); b.BORDER(b.Black);
  b.CLS;
  gr.SPRT(Chudik); gr.ATOF;
  FOR x := 0 TO 30 BY 2 DO
    FOR phase := 1 TO 4 DO
      gr.PTBL(x, 0, phase); gr.PTBL(x, 5, phase); gr.PTBL(x, 10, phase);
      gr.PTBL(x, 15, phase); gr.PTBL(x, 20, phase);
      b.PAUSE(5);
    END;
  END;
  b.Quit

END Laser2Demo.
