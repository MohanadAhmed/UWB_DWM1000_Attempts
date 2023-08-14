<style>
img { width: 45%;}
</style>

# Ultrawideband Experiments (UWB) for the Time Difference of Arrival (TDoA)

We want to get a system where we can obtain Time Difference of Arrival measurements from Decawave's (DWM1000) devices. Decawave is now acquired by Qorva. 
Mohammed Hussaini replicated a PCB that works with Feather M0 and works with the [`thotro`](https://github.com/thotro/arduino-dw1000) library.

We start by asking the following questions:

1. What does the hardware connection look like (Know your Hardware)?
2. A basic test of the MCU / DWM1000 hardware connectivity.


# Know Your Hardware
<div style="text-align:center">

![](.\ZDocStuff\M0_Back_DW_Top.jpg) ![](.\ZDocStuff\M0_Top_DW_Back.jpg)

</div>

Which pin in the module is connected to which pin in the Feather M0? What pin in the Feather M0 is connected to which SAMD21 pin? Which IDEs are more convenient for deveopment? We will attempt to answer these questions here!

The Feather M0 pinout [can be found here](https://learn.adafruit.com/assets/110924):

<div style="text-align:center">
<img src=".\ZDocStuff\FeatherM0_pinout.png" style="width: 90%" />
</div>




