Forked Bitcoin Core, removed everything EXCEPT the files necessary to perform Base58 Check Encoding/Decoding.
Organized it into a lib (.pri) and created 2x UIs for it (GUI and CLI).

To use the GUI:
#clone this repo
#cd into it
cd src
mkdir buildgui
cd buildgui
qmake ../Base58CheckTranscoderGui.pro
make
./Base58CheckTranscoderGui

To use the CLI:
#clone this repo
#cd into it
cd src
mkdir buildcli
cd buildcli
qmake ../Base58CheckTranscoderCli.pro
make
echo -n "test" | ./Base58CheckTranscoderCli | ./Base58CheckTranscoderCli -d

To use the lib:
Examine either the GUI or the CLI .pro files/projects

Long live Satoshi Nakamoto! Also death to Base64!!!
-d3fault
