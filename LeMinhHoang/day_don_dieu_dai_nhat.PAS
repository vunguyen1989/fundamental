program Finding_The_Longest_Sub_Sequence;
const
InputFile = 'INCSEQ.INP'; OutputFile = 'INCSEQ.OUT'; max = 1000000;
var
a, L, T: array[0..max + 1] of Integer; n: Integer;

procedure Enter; 
var
i: Integer; f: Text;
begin
    Assign(f, InputFile); Reset(f);
    ReadLn(f, n);
    for i := 1 to n do Read(f, a[i]); Close(f);
end;

procedure Optimize; {Quy hoạch động}
var
i, j, jmax: Integer; 
begin
    a[0] := Low(Integer); a[n + 1] := High(Integer); {Thêm hai phần tử canh hai đầu dãy a}
    L[n + 1] := 1; {Điền cơ sở quy hoach động vào bảng phương án}
    for i := n downto 0 do {Tính bảng phương án}
        begin
            {Chọn trong các chỉ số j đứng sau i thoả mãn a[j] > a[i] ra chỉ số jmax có L[jmax] lớn nhất}
            jmax := n + 1;
            for j := i + 1 to n + 1 do
                if (a[j] > a[i]) and (L[j] > L[jmax]) then jmax := j;
            L[i] := L[jmax] + 1; {Lưu độ dài dãy con tăng dài nhất bắt đầu tại a[i]}
            T[i] := jmax; {Lưu vết: phần tử đứng liền sau a[i] trong dãy con tăng dài nhất đó là a[jmax]}
        end;
end;

procedure Result;
var
    f: Text;
    i: Integer; 
begin
    Assign(f, OutputFile); Rewrite(f);
    WriteLn(f, L[0] - 2); {Chiều dài dãy con tăng dài nhất}
    i := T[0]; {Bắt đầu truy vết tìm nghiệm}
    while i <> n + 1 do 
        begin
            WriteLn(f, 'a[', i, '] = ', a[i]);
            i := T[i];
        end;
    Close(f);
    end;

begin
    Enter;
    Optimize;
    Result;
end.
