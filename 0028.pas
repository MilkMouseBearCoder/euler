procedure TForm1.btnGoClick(Sender: TObject);
var
    level, size, step, stepSize, total, previousStep, increment: Integer;
    temp: String;
begin
    temp := InputBox('Matrix size', 'Enter a matrix size', '1001');
    size := StrToInt(temp);

    total := 1;
    stepSize := 0;
    previousStep := 1;
    size := floor((size - 1) / 2) + 1;
    for level := 2 to size do
    begin
        stepSize := (level - 1) * 2;
        for step := 1 to 4 do
        begin
            increment := previousStep + stepSize;
            total := total + increment;
            previousStep := increment;
        end;
    end;

    MessageDlg(Format('The totals is: %d', [total]), mtInformation, [mbOK], -1);

end;
