$IsAdmin =  ([Security.Principal.WindowsPrincipal] `
                [Security.Principal.WindowsIdentity]::GetCurrent() `
            ).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)

if (!($IsAdmin)) {
    Write-Output "Please run this script as an administrator"
    Read-Host -Prompt "Press any key to continue" | Out-Null
    exit 1
}

$ProgramFiles = "C:\Program Files"
$MooncatLibrarySubdir = "Mooncat\include\mooncat"
$LibPath = "$ProgramFiles\$MooncatLibrarySubdir"
$LibName = "units"

if (!(Test-Path "$LibPath\$LibName")) {
    Write-Output "Creating: $LibPath"
    mkdir "$LibPath\$LibName"
} else {
    Write-Output "Skipping: Creation of $LibPath"
}

Write-Output "Clearing: Contents of $LibPath\$LibName"
Get-ChildItem -Path "$LibPath\$LibName" -Include * -Recurse | ForEach-Object { $_.Delete() }

$IncludeDir = "include"
Copy-item -Force -Recurse "$IncludeDir" -Destination "$LibPath\$LibName"

