@echo off

rem normally, only 127 patches can be applied to an msi

set /A ii=0

rem msiexec /i GoogleUpdateHelper.msi /qn
rem echo original product installed

:repeat

msiexec /update GoogleUpdateHelperPatch.msp REINSTALL=ALL /qn /L*v patchapply%ii%.log
echo patch %ii% applied
if %ii% GEQ 127 pause
msiexec /uninstall {C7DBD047-AE4B-483F-B51E-95605BB1A32C} /package {B29A414C-43FE-40EF-8FC1-141C70C1503B} /qn /L*v patchremove%ii%.log
echo patch %ii% removed

set /A ii=%ii%+1

if %ii% NEQ 300 goto repeat
rem if %ii% NEQ 127 goto repeat

set ii=
