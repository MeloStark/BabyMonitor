# Baby Monitor

# Devices
## 1. Raspberry Pi zero 2
OS: bullseye 64-bit  
kernel : 6.1.21-v8+  
architechture : aarch64  

## 2. IR Camera
Maker : [OSOYOO IR-CUT camera](https://www.amazon.co.jp/dp/B0CD7KPH3K?psc=1&ref=ppx_pop_dt_b_product_details)  
Module : OV5647

## 3. Microphone
Maker : [Fermion: I2S MEMS Microphone](https://www.dfrobot.com/product-2637.html)  
Buy from : [switch science](https://www.switch-science.com/products/8792?srsltid=AfmBOoqcv8FdD5tEHdltkeBC67CmGvsm0YxuSpLwuCHaZVdnrEOpOwnC)
Reference : [ref1](https://tomosoft.jp/design/?p=11471)
            [ref2](https://raspberry-pi.ksyic.com/bypass/files/GPIO.svgz#Alt0)

| Fermion I2S MEMS Mic | RPi GPIO |
| :------------------: | :------: |
|         GND          |   GND    |
|         3V3          |   3.3V   |
|          WS          | 19(ALT0) |
|         SEL          | 21(ALT0) |
|         SCK          | 18(ALT0) |
|          DO          | 19(ALT0) |

i2s microphone setting
```bash
$ sudo nano /boot/config.txt
dtparam=i2s=on
~~~
dtoverlay=googlevoicehat-soundcard

$ raspi-gpio set 'PIN num' ALT0

$ arecord -l
**** List of CAPTURE Hardware Devices ****
card 0: sndrpigooglevoi [snd_rpi_googlevoicehat_soundcar], device 0: Google voiceHAT SoundCard HiFi voicehat-hifi-0 [Google voiceHAT SoundCard HiFi voicehat-hifi-0]
  Subdevices: 1/1
  Subdevice #0: subdevice #0

$ arecord -D plughw:0,0 -c1 -r 48000 -f S32_LE -t wav -V mono -v file.wav
```

# Record sound by python
```bash
$ sudo apt-get install -y python3-pyaudio
```
