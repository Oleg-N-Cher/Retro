MODULE ASCII; (** portable *)
IMPORT Console, Basic;
VAR
  n: BYTE;
BEGIN (*$MAIN*)
  FOR n := 32-1 TO 127-1 DO Console.WriteCh(CHR(n+1)) END;
  Basic.Quit
END ASCII.
