program Combination; const
    InputFile = 'SUBSET.INP'; 
    OutputFile = 'SUBSET.OUT'; 
    max = 30;
var
    x: array[1..max] of Integer; 
    n, k, i, j: Integer;
    f: Text; 
begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n, k);
    Close(f);
    Assign(f, OutputFile); Rewrite(f);
        for i := 1 to k do x[i] := i; {x1 := 1; x2 := 2; … ; x3 := k	(Cấu hình khởi tạo)}
        repeat
            {In ra cấu hình hiện tại}
            Write(f, '{');
            for i := 1 to k - 1 do Write(f, x[i], ', ');
            WriteLn(f, x[k], '}');
            {Sinh tiếp}
            i := k; {xi là phần tử cuối dãy, lùi dần i cho tới khi gặp một xi chưa đạt giới hạn trên n - k + i}
            while (i > 0) and (x[i] = n - k + i) do Dec(i);
            if i > 0 then {Nếu chưa lùi đến 0 có nghĩa là chưa phải cấu hình kết thúc}
                begin
                    Inc(x[i]); {Tăng xi lên 1, Đặt các phần tử đứng sau xi bằng giới hạn dưới của nó}
                    for j := i + 1 to k do x[j] := x[j - 1] + 1; 
                end;
        until i = 0; {Lùi đến tận 0 có nghĩa là tất cả các phần tử đã đạt giới hạn trên - hết cấu hình}
    Close(f); 
end.
