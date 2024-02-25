Function MyClean {
    [OutputType([System.Void])]
    param()

    Get-ChildItem -Path "." | Where-Object { $_ -match ".obj" } | ForEach-Object {
        Remove-Item $_.FullName;
    }

}

if ($env:OS -match "Windows") {

    MyClean;

    cmd /s /v /c "main.bat";

    ./dist/main.exe;
}
else {
    # build somehow in another OS here assuming someone else has powershell installed
}


