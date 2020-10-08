(*$MAIN*) MODULE DemoTiles;
IMPORT T := GrTiles, B := Basic, SYSTEM;

CONST
  square = T.MonoTile8x8(
    (*Pixels:*) 0FFX, 81X, 81X, 81X, 81X, 81X, 81X, 0FFX
    (*Attrib:*)
  );

VAR i: BYTE;

BEGIN
  B.BORDER(3);
  FOR i :=  8 TO 23 DO T.DrawMonoTile8x8(i, 1, square, 4) END;
  FOR i := 10 TO 21 DO T.DrawMonoTile8x8(i, 3, square, 5) END;
  FOR i := 12 TO 19 DO T.DrawMonoTile8x8(i, 5, square, 6) END;
  FOR i := 14 TO 17 DO T.DrawMonoTile8x8(i, 7, square, 7) END;
  B.Quit;
END DemoTiles.
