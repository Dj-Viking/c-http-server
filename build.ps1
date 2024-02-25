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

    Write-Host "last exit code $LASTEXITCODE";

    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE;
    }

    ./dist/main.exe;
}
else {
    # build somehow in another OS here assuming someone else has powershell installed
}


