program ExampleSimple;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletDualRelay;

type
  TExample = class
  private
    ipcon: TIPConnection;
    dr: TBrickletDualRelay;
  public
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '928'; { Change to your UID }

var
  e: TExample;

procedure TExample.Execute;
begin
  { Create IP connection to brickd }
  ipcon := TIPConnection.Create(HOST, PORT);

  { Create device object }
  dr := TBrickletDualRelay.Create(UID);

  { Add device to IP connection }
  ipcon.AddDevice(dr);
  { Don't use device before it is added to a connection }

  { Turn relay 1 on and relay 2 off. }
  dr.SetState(true, false);

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
