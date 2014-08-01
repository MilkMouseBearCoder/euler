procedure TForm1.btnGoClick(Sender: TObject);
var
    nums: TList;
    a, b: integer;
    r: double;
begin
    nums := TList.Create;
    for a := 2 to 100 do
    begin
        for b := 2 to 100 do
        begin
            r := power(a, b);
            if nums.IndexOf(Pointer(r)) = -1 then
                nums.Add(Pointer(r));
        end;
    end;
    MessageDlg('Length', Format('%d', [nums.Count]), mtInformation, [mbOK], -1);
end;    
