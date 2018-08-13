$SourceFile = Get-Content C:\git\RunProject\RunProject\Source.cpp
$FirstLine = $SourceFile[0]

$RootPath = "C:\git\hf-ict\AAD\"


if($FirstLine.Substring(0,2) -eq "//") {
    $DestinationPath = $RootPath + $FirstLine.Substring(2).Trim() + "\"
}
else {
    $Date = (Get-Date).ToString("yyyy-MM-dd")
    $DestinationPath +=  $Date + "\"
}

if((Test-Path $DestinationPath) -eq $false)
{
    mkdir $DestinationPath
}

[void](Get-Item -Path C:\git\RunProject\RunProject\* -Include "*.h", "*.cpp"| select -ExpandProperty FullName | % {cp $_ $DestinationPath})

cd C:\git\hf-ict\AAD
git add .
git commit -m "Auto Post-Build push" | % { $_.ToString() }
git push | % { $_.ToString() }

exit 0


# powershell.exe -ExecutionPolicy ByPass -F "C:\git\hf-ict\AAD\Push-Code.ps1"