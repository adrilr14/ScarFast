rm -rf /src/pro/ScarFast/resources
#wget --max-redirect=20 -O download.zip https://www.dropbox.com/sh/3uqns6p87umsmyf/AAAoESdVifX25IKDqxY1S0Xza
wget -O FV.zip https://www.dropbox.com/sh/3uqns6p87umsmyf/AAAoESdVifX25IKDqxY1S0Xza
unzip -q FV
cp -r resources/ src/pro/ScarFast
rm -rf resources
rm -rf FV.zip