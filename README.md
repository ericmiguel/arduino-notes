# Arduino Notes

## WSL notes

```bash
# install USBIPD-WIN
# https://learn.microsoft.com/pt-br/windows/wsl/connect-usb#attach-a-usb-device

# at WSL
sudo apt install linux-tools-generic hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip /usr/lib/linux-tools/*-generic/usbip 20

# at windows
usbipd list
usbipd bind -b {BUSID}
usbipd attach --busid {BUSID} --wsl

# at wsl
lsusb
```

## Fresh install

```bash
arduino config init
# The first thing to do upon a fresh install is to update the local cache of available platforms and libraries by running:
arduino core update-index
arduino lib update-index
```

## CLI workflow

```bash

# https://arduino.github.io/arduino-cli/0.35/getting-started/

arduino sketch new {name}

# After connecting the board to your PC by using the USB cable, you should be able to check whether it's been recognized by running:
arduino board list

# installing an Arduino UNO R3 compatible board
arduino core search uno
arduino core install arduino:avr
arduino compile --fqbn arduino:avr:uno {sketch name here}

# get USB port from "arduino-cli board list"
arduino upload --port /dev/ttyUSB0 --fqbn arduino:avr:uno {sketch name here}

# search for libs
arduino lib search {lib name}
arduino lib install {lib name}
```