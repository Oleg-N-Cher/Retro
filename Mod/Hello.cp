(*$MAIN*) MODULE Hello; IMPORT b := Basic;
BEGIN
  b.Init; b.CLS;
  b.PRSTR("Hello, World!"); b.PAUSE(0);
  b.Quit
END Hello.
