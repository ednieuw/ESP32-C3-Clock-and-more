# ESP32-C3-Clock-and-more

<h2> The project is still in progress but almost finished with V008 </h2>

https://ednieuw.home.xs4all.nl/Woordklok/ESP32C3AndMore/ESP32C3ClockAndMoreV.html

<body>
<h1 class="auto-style10">ESP32-C3 Clock, HTML page, NTP, BLE to phone and more </h1>

<p class="auto-style10"><strong><a href="../index.html">Home</a></strong></p>
<p><span class="auto-style10">A small clock that displays the time in words in Dutch, English, French and 
German.<br />The clock is able to receive time 
via NTP from the internet. <br />
Settings can be controlled via a webpage, PC and Bluetooth LE.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">
<a href="https://github.com/ednieuw/ESP32-C3-Clock-and-more">Latest versions and 
updates on Github</a> </span> </p>
<p><span class="auto-style10">The clock is built with a ESP32-C3-12F kit.</span><br class="auto-style10" />
<span class="auto-style10">The software is written with the Arduino IDE 1.8.19 
and IDE 2.0.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">The software contains coding to use the:</span><br class="auto-style10" />
<span class="auto-style10">1 ILI9314 colour display (in progress)<br />
2 BLE nRF UART connection with an option to send strings longer than 20 bytes</span><br class="auto-style10" />
<span class="auto-style10">3 Time zone corrected time with daylight savings from a NTP server via WIFI</span><br class="auto-style10" />
<span class="auto-style10">4 RGB LED control on the MVU</span><br class="auto-style10" />
<span class="auto-style10">5 RTC for time keeping when off line</span><br class="auto-style10" />
<span class="auto-style10">6 LDR analogue readings&nbsp; (in progress)</span><br class="auto-style10" />
<span class="auto-style10">7 Storage of the settings in the ESP32-C3 SPIFSS Flash memory</span><br class="auto-style10" />
<span class="auto-style10">8 Menu driven control of preferences with serial monitor, BLE and WIFI-html page</span><br class="auto-style10" />
<span class="auto-style10">9&nbsp;Four languages to display time<br />
10 SK6812 RGBW /WS2812 RGB LED strip support to make a word clock&nbsp; (in progress)</span></p>
<p style="width: 840px"><br class="auto-style10" />
<table class="auto-style12">
<tr>
<td style="width: 248px" valign="bottom"><span class="auto-style3">Het was tien over tien 10:13:00</span><br class="auto-style3" />
<span class="auto-style3">Il est dix heures et quart 10:14:00</span><br class="auto-style3" />
<span class="auto-style3">Il est dix heures et quart 10:15:00</span><br class="auto-style3" />
<span class="auto-style3">Het is kwart over tien 10:16:00</span><br class="auto-style3" />
<span class="auto-style3">Es war viertel nach zehn 10:17:00</span><br class="auto-style3" />
<span class="auto-style3">It was quarter past ten 10:18:00</span><br class="auto-style3" />
<span class="auto-style3">Il est dix heures vingt 10:19:00</span><br class="auto-style3" />
<span class="auto-style3">Es ist zehn vor halb elf 10:20:00</span><br class="auto-style3" />
<span class="auto-style3">Het is tien voor half elf 10:21:00</span><br class="auto-style3" />
<span class="auto-style3">It was twenty past ten 10:22:00</span><br class="auto-style3" />
<span class="auto-style3">It was twenty past ten 10:23:00</span><br class="auto-style3" />
<span class="auto-style3">Het is vijf voor half elf 10:24:00</span><br class="auto-style3" />
<span class="auto-style3">Es ist funf vor halb elf 10:25:00</span><br class="auto-style3" />
<span class="auto-style3">It is twenty five past ten 10:26:00</span><br class="auto-style3" />
<span class="auto-style3">Es war funf vor halb elf 10:27:00</span></td>
<td>
<img alt="MS phone and iPhone8" src="Pics/MS_IP8.jpg" width="450" class="auto-style10" /></td>
</tr>
<tr>
<td style="width: 248px" class="auto-style10">Display of the time in the serial output</td>
<td class="auto-style10">HTML page in iPhone 8 and Microsoft Phone</td>
</tr>
</table>
<br class="auto-style10" />
<strong><span class="auto-style10">First Use</span><br class="auto-style10" />
</strong><span class="auto-style10">When the MCU is started and running properly the LED on the 
board will pulse red every second. 
</span> 
<br class="auto-style10" />
<span class="auto-style10">When connected to WIFI&nbsp; the same led will also pulse green.&nbsp; 
</span> <br class="auto-style10" />
<span class="auto-style10">Press the
the top right button to see the ip-address, time and date of the clock .
</span>
<br class="auto-style10" />
<span class="auto-style10">Date and ip-address will disappear as a new minute starts.</span><br class="auto-style10" />
<span class="auto-style10">Enter the ip-address in a browser or connect 
via Bluetooth and send the character 'I' to see for the menu.</span><br class="auto-style10" />
<span class="auto-style10">In the menu the name of the router to connect to, the SSID, and its password can 
be entered. </span> <br class="auto-style10" />
<br class="auto-style10" />
<img alt="IP-address" src="Pics/img9.gif" class="auto-style10" /><br class="auto-style10" />
</p>
<p><span class="auto-style10"><strong>Installations</strong>&nbsp;
</span>
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">If the clock is connected to the internet it will seek contact with a time 
server. </span> <br class="auto-style10" />
<span class="auto-style10">The time zone is set to UTC+1 Amsterdam but can be changed in the menu.</span><br class="auto-style10" />
<span class="auto-style10">To connect to a WIFI network a SSID and password must be entered.</span><br class="auto-style10" />
<span class="auto-style10">There are a few methods:</span><br class="auto-style10" />
<span class="auto-style10">- Connect the MCU with a serial cable to a PC and use a serial terminal. I 
use the Arduino IDE or <a href="https://www.compuphase.com/software_termite.htm">
Termite</a> as serial terminal.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">Sending the I for information will display the menu followed with the actual 
settings of several preferences</span></p>
<p>
<table style="width: 51%" class="auto-style12">
<tr>
<td style="width: 342px">
<img alt="Menu on iPhone" src="Pics/phonemenu.jpg" width="350" class="auto-style10" /></td>
<td style="width: 415px">
<img alt="Termite terminal" src="Pics/Termite.jpg" width="400" class="auto-style10" /></td>
</tr>
<tr>
<td style="width: 342px" class="auto-style10">HTML page on iPhone </td>
<td style="width: 415px"><br class="auto-style10" />
<span class="auto-style10">Termite Terminal from a PC</span></td>
</tr>
</table>
<br class="auto-style10" />
</p>
<table style="width: 919px">
<tr>
<td style="width: 550px">
<p><span class="auto-style10">- USE the BLE nRF connection with an UART serial terminal app 
to control it with your mobile phone or tablet.</span><br class="auto-style10" />
<span class="auto-style10">Use the IOS app:&nbsp;
<a href="https://apps.apple.com/nl/app/ble-serial-pro/id1632245655?l=en">BLE 
Serial Pro</a>. <br />
Turn on Fast BLE with option Z.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">For Android use:
<a href="https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal">
Serial Bluetooth terminal</a>. <br />
Turn off (default) Fast BLE.</span>
</p>
<p>
<br class="auto-style10" /><span class="auto-style10">Start the 
app and find the MCU in the list of devices and connect to it. You 
can change it's beacon name in the menu with option C.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">In both cases 
<strong>send the letter I 
of Information and the menu shows up</strong></span>.<br class="auto-style10" />
<span class="auto-style10">Enter the first letter of the setting you want to changes followed with a code.</span><br class="auto-style10" />
<span class="auto-style10">Some entries just toggle On and Off. Like the W to set WIFI Off or On. 
</span> 
</p>
<p style="width: 600px"><span class="auto-style10">To change the SSID and password:</span><br class="auto-style10" />
<span class="auto-style10"><strong>A</strong></span><span class="auto-style7"><strong>my-ssid</strong></span><span class="auto-style10"> 
and send this command. Eg AFRITZ!Box01 or aFRITZ!Box01. Starting with an upper 
or lower case character is an identical instruction in the command string</span><br class="auto-style10" />
<span class="auto-style10">Then&nbsp; <strong>B</strong></span><span class="auto-style1"><span class="auto-style10"><strong>my password</strong> and send that password.</span><br class="auto-style10" />
<span class="auto-style10">
<strong>Cbroadcastname</strong>&nbsp; will change to name displayed in the Bluetooth 
connection list.&nbsp; </span> <br class="auto-style10" />
<span class="auto-style10">If the length of the SSID and/or password is less then 5 characters the WIFI 
will be turned off automatically. This will speed up startup time if no internet connection is available</span><br class="auto-style10" />
<span class="auto-style10">Use a length of minimal 8 characters for SSID and password.</span><br class="auto-style10" />
<span class="auto-style10">Check in the menu (third row from the bottom) if WIFI and NTP are on.</span><br class="auto-style10" />
<span class="auto-style10">If WIFI is connected the LED on the MCU will pulse green.</span><br class="auto-style10" />
</span><br class="auto-style10" /><span class="auto-style10">Enter @ to reset the 
MCU. It will restart and connections will be made.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">To set a time zone. Send the the time zone string between the quotes prefixed with 
the character E or e.</span><br class="auto-style10" />
<span class="auto-style10">See the time zones at the bottom of this page.</span><br class="auto-style10" />
<span class="auto-style10">For example; if you live in Australia/Sydney send the string, eAEST-10AEDT,M10.1.0,M4.1.0/3</span></p>
</td>
<td valign="bottom">
<p class="auto-style10">&nbsp;</p>
<pre><span class="auto-style10">A SSID B Password C BLE beacon name</span>
<span class="auto-style10">D Set Date (D15012021)</span>
<span class="auto-style10">E Set Timezone E&lt;-02&gt;2 or E&lt;+01&gt;-1</span>
<span class="auto-style10">Make own colour of: (Hex RRGGBB)</span>
<span class="auto-style10">F Font G Dimmed font H Bkgnd</span>
<span class="auto-style10">I To print this Info menu</span>
<span class="auto-style10">L L0 = NL, L1 = UK, L2 = DE</span>
<span class="auto-style10">L3 = FR, L4 = Wheel</span>
<span class="auto-style10">N Display off between Nhhhh (N2208)</span>
<span class="auto-style10">O Display toggle On/Off</span>
<span class="auto-style10">Q Display colour choice (Q0-6)</span>
<span class="auto-style10">Q0 Yellow Q1 hourly</span>
<span class="auto-style10">Q2 White Q3 All Own</span>
<span class="auto-style10">Q4 Own Q5 Wheel</span>
<span class="auto-style10">Q6 Digital display</span>
<span class="auto-style10">R Reset settings @ = Reset MCU</span>
<span class="auto-style10">T Set Time (T132145)</span>
<span class="auto-style10">W=WIFI, X=NTP, Y=BLE, Z=Fast BLE</span>
<span class="auto-style10">Ed Nieuwenhuys Okt 2022</span>
<span class="auto-style10">___________________________________</span>
<span class="auto-style10">Display off: 00h - 00h</span>
<span class="auto-style10">Display choice: Wheel</span>
<span class="auto-style10">SSID: FRITZ!BoxEd</span>
<span class="auto-style10">BLE name: PocClockBlack</span>
<span class="auto-style10">IP-address: 192.168.178.77</span>
<span class="auto-style10">Timezone:CET-1CEST,M3.5.0,M10.5.0/3</span>
<span class="auto-style10">WIFI=On NTP=On BLE=On Fast BLE=Off</span>
<span class="auto-style10">Language choice: Rotate language</span>
<span class="auto-style10">Software: ESP32C3WordClockV010.ino</span>
<span class="auto-style10">___________________________________</span></pre>
</td>
</tr>
<tr>
<td style="width: 550px" class="auto-style10">&nbsp;</td>
<td class="auto-style10">Menu shown in serial output.</td>
</tr>
</table>
<p class="auto-style10"><strong>Control and settings of the clock</strong></p>
<p><span class="auto-style10">If there is no WIFI connection time and digital or word clock mode can be set with 
the three buttons. </span> <br class="auto-style10" />
<span class="auto-style10">Check at the bottom of the menu if WIFI is OFF. </span> 
<br class="auto-style10" />
<span class="auto-style10">The clock will start much quicker because it 
will not try to connect.</span><br class="auto-style10" />
<img alt="Pocuter menu bottom" class="auto-style4" src="Pics/MenuBottom.gif" /></p>
<p>
<span class="auto-style10">Top 
Left: + 1 hour</span>
<span class="auto-style10">Right bottom: + 1 minute</span>
<span class="auto-style10">Top Right: Toggle between word or digital display</span></p>
<p><span class="auto-style10">As mentioned before the clock can be controlled with the WIFI webpage or BLE 
UART terminal app.</span><br class="auto-style10" />
<span class="auto-style10">When the clock is connected to WIFI the ip-address is displayed in the Digital display (Press 
Top right button to select it).</span><br class="auto-style10" />
<span class="auto-style10">Enter this ip-address numbers and dots (for example: 192.168.178.77) in the browser of your mobile or PC where you type 
your internet addresses (URL).</span><br class="auto-style10" />
<span class="auto-style10">or search items.</span><br class="auto-style10" />
<span class="auto-style10">Or</span><br class="auto-style10" />
<span class="auto-style10">Open the BLE terminal app. Look for the WordClock to connect to and connect.</span><br class="auto-style10" />
<span class="auto-style10">BLE connection can be made with my app
<a href="https://ednieuw.home.xs4all.nl/BLESerial/BLESerialPRO.html">BLE Serial 
pro</a> on the
<a href="https://apps.apple.com/nl/app/ble-serial-pro/id1632245655?l=en">app 
store</a> for Apple IOS devices. </span> <br class="auto-style10" />
<span class="auto-style10">For Android
<a href="https://play.google.com/store/apps/details?id=com.nordicsemi.nrfUARTv2&amp;hl=en&amp;gl=US"> 
&nbsp;nRF UART terminal program </a>and
<a href="https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal">
Serial Bluetooth terminal from Kai Morich</a></span>
<span class="auto-style10">Unfortunately this Android apps 
can not read strings longer than 20 characters.</span><br class="auto-style10" />
<span class="auto-style10">If you see a garbled menu enter and send the character 'Z' to select the slower 
transmission mode</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">
<strong>Settings are set by entering the first character of a command following by 
parameters if necessary.</strong></span>
<span class="auto-style10">For example: To set the colours of the fonts in the display 
to white enter: Q2</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">To shown random all four languages every minute send L4.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">Set the time by entering T130245. (130245 will also work)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">Turn off WIFI by sending a W.</span></p>
<p class="auto-style10">Reset the MCU with the letter @.</p>
<p><span class="auto-style10">Reset to default setting by send R.<br />
</span><br class="auto-style10" />
<span class="auto-style10">In the BLE connection the SSID and password will be shown. 
</span> <br class="auto-style10" />
<table cellspacing="6" class="auto-style2" style="width: auto">
<tr>
<td style="width: 318px">
<img alt="Phone" src="Pics/IMG_9449.jpg" width="350" class="auto-style4" /></td>
<td>
<img alt="WIFI-BLE" src="Pics/IMG_9448.jpg" width="350" class="auto-style4" /></td>
</tr>
<tr>
<td style="width: 318px" class="auto-style10">HTML page</td>
<td class="auto-style10">BLE menu</td>
</tr>
</table>
</p>
<p><span class="auto-style10"><strong>Detailed description</strong></span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">With the menu many preferences can be set. These preferences are stored on a 
SD-card or in the ESP32-C3 storage space.</span><br class="auto-style10" />
&nbsp;<br class="auto-style10" />
<span class="auto-style10">Enter the first character in the menu of the item to be changed followed with the parameter.</span><br class="auto-style10" />
<span class="auto-style10">There is no difference between upper or lower case. Both are OK.</span><br class="auto-style10" />
<span class="auto-style10">Between the ( )</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">
<strong>A SSID B Password C BLE beacon name</strong></span><br class="auto-style10" />
<span class="auto-style10">Change the name of the SSID of the router to be connected to. 
</span> <br class="auto-style10" />
<span class="auto-style10">aFRITZ!BoxEd or AFRITZ!BoxEd</span><br class="auto-style10" />
<span class="auto-style10">Then enter the password. For example: BSecret_pass</span><br class="auto-style10" />
<span class="auto-style10">Restart the MCU by sending @ </span> 
<br class="auto-style10" />
<span class="auto-style10">Entering a single 'b' will show the used password. This Easter egg can can used 
to check if a valid password was entered</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">
<strong>D Set Date</strong>&nbsp; and <strong>T Set Time</strong></span> 
<br class="auto-style10" />
<span class="auto-style10">If you are not connected to WIFI you have to set the time and date by hand</span><br class="auto-style10" />
<span class="auto-style10">For example enter: D06112022 to set the date to 6 November 2022.</span></p>
<p class="auto-style10">Enter for example T132145 (or 132145 , or t132145)&nbsp; to set the time to 45 seconds and 21 minute past 
one o'clock.</p>
<p><span class="auto-style10"><strong>E Set Timezone E&lt;-02&gt;2 or E&lt;+01&gt;-1</strong></span><br class="auto-style10" />
<span class="auto-style10">At the bottom of this page you can find the time zones used in 2022. 
</span> <br class="auto-style10" />
<span class="auto-style10">It is a rather complicated string and it is therefore wise to copy it.</span><br class="auto-style10" />
<span class="auto-style10">Let's pick one if you happen to live here: Antarctica/Troll,"&lt;+00&gt;0&lt;+02&gt;-2,M3.5.0/1,M10.5.0/3"</span><br class="auto-style10" />
<span class="auto-style10">Copy the string between the " "'s and send it with starting with an 'E' or 'e' in front.</span><br class="auto-style10" />
<span class="auto-style10">E&lt;+00&gt;0&lt;+02&gt;-2,M3.5.0/1,M10.5.0/3</span></p>
<p><em><span class="auto-style10">Time zones and daylight savings should be ended and replaced by one universal 
date and time for the while planet cq universe. </span> 
<br class="auto-style10" />
<span class="auto-style10">But that is my opinion.</span></em></p>
<p><strong><span class="auto-style10">Make own colour of: (Hex RRGGBB)</span><br class="auto-style10" />
<span class="auto-style10">F Font G Dimmed font H Bkgnd</span></strong><br class="auto-style10" />
<span class="auto-style10">You can set the colours of the highlighted and dimmed characters and&nbsp; the back ground</span><br class="auto-style10" />
<span class="auto-style10">The time is shown with the colour defined with Font when Display choice Q3 or Q4 
is chosen and the rest of the not highlighted characters are coloured with the setting in Dimmed 
font.</span><br class="auto-style10" />
<span class="auto-style10">The format to be entered is hexadecimal. 0123456789ABCDEF are the character that 
can be used.</span><br class="auto-style10" />
<span class="auto-style10">The command is 2 digits for Red followed with&nbsp; two for Green and ending 
with two digits for Blue. </span> <br class="auto-style10" />
<span class="auto-style10">To colour the characters intense red enter FF0000 prefixed with the letter F, G 
or H.</span><br class="auto-style10" />
<span class="auto-style10">To set the background to intense blue enter: H0000FF</span><br class="auto-style10" />
<span class="auto-style10">To set the dimmed character to dark gray enter for example: G191919. You get 
gray if red, green and blue has the same intensity.</span></p>
<p><span class="auto-style10"><strong>I To print this Info menu</strong></span><br class="auto-style10" />
<span class="auto-style10">Print the menu to Bluetooth and the serial monitor connected with an USB-cable</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">
<strong>L L0 = NL, L1 = UK, L2 = DE, L3 = FR, L4 = Wheel</strong></span><br class="auto-style10" />
<span class="auto-style10">You can choose between four languages to display or show them randomly every 
minute.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">
<strong>N Display off between Nhhhh (N2208)</strong></span><br class="auto-style10" />
<span class="auto-style10">With N2208 the display will be turned off between 22:00 and 8:00.</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">
<strong>O Display toggle On/Off</strong></span><br class="auto-style10" />
<span class="auto-style10">O toggle the display off and on.</span></p>
<p><br class="auto-style10" />
<strong><span class="auto-style10">Q Display colour choice (Q0-6)</span><br class="auto-style10" />
<span class="auto-style10">Q0 Yellow Q1 hourly
Q2 White Q3 All Own
Q4 Own Q5 Wheel
Q6 Digital display</span></strong><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">Q0 will show the time with yellow words.</span><br class="auto-style10" />
<span class="auto-style10">Q1 will show every hour another colour.</span><br class="auto-style10" />
<span class="auto-style10">Q2 shows all the texts white.</span><br class="auto-style10" />
<span class="auto-style10">Q3 and Q4 uses you own defined colours.</span><br class="auto-style10" />
<span class="auto-style10">Q5 will follow rainbow colours every minute.</span><br class="auto-style10" />
<span class="auto-style10">Q6 is the digital display with the IP-address and date until seconds are 00.</span><br class="auto-style10" />
<span class="auto-style10">You can also press the top right button.</span><br class="auto-style10" />
<span class="auto-style10">The selected choice is displayed at the bottom of the menu.</span><br class="auto-style10" />
<span class="auto-style10">Send an 'I' to display the latest's settings</span></p>
<p><span class="auto-style10"><strong>R Reset settings </strong></span>
<br class="auto-style10" />
<span class="auto-style10">R will set all preferences to default settings, it also clears the SSID and password.</span><br class="auto-style10" />
</p>
<p>
<strong><span class="auto-style10">@ = Restart MCU</span><br class="auto-style10" />
</strong><span class="auto-style10">@ will restart the MCU. This is handy when the SSID, et cetera are 
changed and the program must be restarted.</span></p>
<p>
<span class="auto-style10">
<strong>W=WIFI, X=NTP, Y=BLE, Z=Use SD</strong></span><br class="auto-style10" />
<span class="auto-style10">Toggle WIFI, NTP on and off.</span><br class="auto-style10" />
<span class="auto-style10">Enter the character will toggle it on or off. A the bottom of the menu the 
stated is printed.</span><br class="auto-style10" />
<img alt="Bottom menu" class="auto-style4" src="Pics/BottomMenu.gif" /><br class="auto-style10" />
</p>
<p><span class="auto-style10"><strong>Z Fast BLE</strong></span><br class="auto-style10" />
<span class="auto-style10">The
BLE UART protocol sends default packets of 20 bytes. Between every packet there is a delay of 50 
msec</span><br class="auto-style10" />
<span class="auto-style10">The IOS BLEserial app, and maybe others too, is able to receive packets of 80 
bytes or more before characters are missed and </span> 
<br class="auto-style10" />
<span class="auto-style10">Option Z toggles between the long and short packages.&nbsp; 
</span> </p>
<p class="auto-style10">
Settings are stored in the SPIFFS space from the ESP32-C3</p>
<p class="auto-style10">
<strong>Compilation and uploading</strong></p>
<p class="auto-style10">
The following libraries are 
used.<br />
<span class="auto-style10">#include &lt;NimBLEDevice.h&gt;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; // For BLE communication&nbsp; https://github.com/h2zero/NimBLE-Arduino</span><br />
<span class="auto-style10">#include &lt;ESPNtpClient.h&gt;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; // https://github.com/gmag11/ESPNtpClient</span><br />
<span class="auto-style10">#include &lt;WiFi.h&gt;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; // Used for NTP tme and web page</span><br />
<span class="auto-style10">#include &lt;AsyncTCP.h&gt;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; // Used for webpage&nbsp;&nbsp; https://github.com/me-no-dev/ESPAsyncWebServer</span><br />
<span class="auto-style10">#include &lt;ESPAsyncWebServer.h&gt; // Used for webpage&nbsp;&nbsp;   <a href="https://github.com/me-no-dev/ESPAsyncWebServer">https://github.com/me-no-dev/ESPAsyncWebServer</a></span><br />
<span class="auto-style10">#include &lt;Preferences.h&gt;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; // Used for SPIFFS file system</span></p>
<p class="auto-style10">&nbsp;</p>
<p><img alt="ESP32-c3 DEV board" src="Pics/img6.gif" class="auto-style10"></p>
<p class="auto-style10">&nbsp;</p>
<p class="auto-style10"><strong>Program explanation</strong></p>
<p><span class="auto-style10">The program uses a few standard libraries. </span> 
<br class="auto-style10" />
</p>
<pre><span class="auto-style10">// ESP32-C3 Includes defines and initialisations</span>

<span class="auto-style10">#include &lt;NimBLEDevice.h&gt;      // For BLE communication https://github.com/h2zero/NimBLE-Arduino</span>
<span class="auto-style10">#include &lt;ESPNtpClient.h&gt;      // https://github.com/gmag11/ESPNtpClient</span>
<span class="auto-style10">#include &lt;WiFi.h&gt;              // Used for NTP time and web page</span>
<span class="auto-style10">#include &lt;AsyncTCP.h&gt;          // Used for webpage https://github.com/me-no-dev/ESPAsyncWebServer</span>
<span class="auto-style10">#include &lt;ESPAsyncWebServer.h&gt; // Used for webpage https://github.com/me-no-dev/ESPAsyncWebServer</span>
<span class="auto-style10">#include &lt;Preferences.h&gt;       // for storage in SPIFFS</span>
<span class="auto-style10">#include "Colors.h"            // Definition of the colour list</span></pre>
<p><span class="auto-style10">Colors.h is included in the program as a TAB</span><br class="auto-style10" />
<span class="auto-style10">The same as the #include "Webpage.h" </span> 
<br class="auto-style10" />
<span class="auto-style10">I made the web page in the free 'Microsoft Expression Web 4'. It is not 
maintained anymore but has more than enough functionalities for our purposes</span><br class="auto-style10" />
<span class="auto-style10">Click&nbsp; Spit, below in the window of MS-Expression, and copy all the HTML 
code between:</span><br class="auto-style10" />
<span class="auto-style11">R"rawliteral( </span><span class="auto-style10">&nbsp;... and ...&nbsp;
</span><span class="auto-style11">)rawliteral"; </span> 
<br class="auto-style10" />
</p>
<p><br class="auto-style10" />
<img alt="MS expression" class="auto-style4" src="Pics/MSExpression.jpg" /><br class="auto-style10" />
<span class="auto-style10">&nbsp;</span></p>
<p><span class="auto-style10">A long list if definitions and initialisations follows.</span><br class="auto-style10" />
<span class="auto-style10">I am not a fan of passing all the variables to and from functions and like to 
keep them global in one program list.</span><br class="auto-style10" />
<span class="auto-style10">If you write a program with other people it is good practice not to use globals 
but this program is in one large listing, for the same reason to keep it simple.</span><br class="auto-style10" />
<span class="auto-style10">I grouped all the variables per application to keep track where they are used.</span><br class="auto-style10" />
<span class="auto-style10">With a simple find it is easy in this one great listing to find the back.</span><br class="auto-style10" />
</p>
<p><span class="auto-style10">To print the time as text and colour the proper 
LEDs all the words and its position in a string leds or text are defined.</span><br class="auto-style10" />
<span class="auto-style10">...&nbsp;&nbsp; </span><span class="auto-style11">#define PRECIES ColorLeds("precies", 16, 22, LetterColor);</span><br class="auto-style10" />
</p>
<p><br class="auto-style10" />
<span class="auto-style11">Preferences FLASHSTOR;</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">struct EEPROMstorage { // Data storage in EEPROM to maintain them after power 
loss</span><br class="auto-style10" />
<span class="auto-style10">byte DisplayChoice = 0;</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<span class="auto-style10">char BLEbroadcastName[30]; // Name of the BLE beacon</span><br class="auto-style10" />
<span class="auto-style10">char Timezone[50];</span><br class="auto-style10" />
<span class="auto-style10">int Checksum = 0;</span><br class="auto-style10" />
<span class="auto-style10">} Mem;</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">// Menu</span><br class="auto-style10" />
<span class="auto-style10">//0 1 2 3 4</span><br class="auto-style10" />
<span class="auto-style10">//1234567890123456789012345678901234567890---- </span> 
<br class="auto-style10" />
<span class="auto-style10">char menu[][40] = {</span><br class="auto-style10" />
<span class="auto-style10">"A SSID B Password C BLE beacon name",</span><br class="auto-style10" />
<span class="auto-style10">"D Date (D15012021) T Time (T132145)",</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<span class="auto-style10">"W=WIFI, X=NTP, Y=BLE, Z=Fast BLE", </span> 
<br class="auto-style10" />
<span class="auto-style10">"Nov 2022" };</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// ESP32-C3 Setup</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void setup() </span> <br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">Serial.begin(115200); Tekstprintln("Serial started"); // Setup the serial port 
to 115200 baud //</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<span class="auto-style10">msTick = LastButtonTime = millis(); </span> 
<br class="auto-style10" />
}<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// ESP32-C3 Loop</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void loop() </span> <br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">EverySecondCheck(); </span> 
<br class="auto-style10" />
<span class="auto-style10">CheckDevices();</span><br class="auto-style10" />
}<br class="auto-style10" />
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Update routine done every second</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void EverySecondCheck(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">static int lumi=0;</span><br class="auto-style10" />
<span class="auto-style10">... </span> <br class="auto-style10" />
<span class="auto-style10">if (timeinfo.tm_min != lastminute) EveryMinuteUpdate(); // Enter the every 
minute routine after one minute</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Update routine done every minute</span><br class="auto-style10" />
<span class="auto-style10">//-------------------------------------------- </span> 
<br class="auto-style10" />
<span class="auto-style10">void EveryMinuteUpdate(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<span class="auto-style10">if(timeinfo.tm_hour != lasthour) EveryHourUpdate();</span><br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Update routine done every hour</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void EveryHourUpdate(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<span class="auto-style10">if (timeinfo.tm_mday != lastday) EveryDayUpdate();
</span> <br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">// //</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Update routine done every day</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void EveryDayUpdate(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
}<br class="auto-style10" />
<br class="auto-style10" />
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common check for serial input</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void SerialCheck(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<span class="auto-style10">ReworkInputString(SerialString+"\n"); // Rework ReworkInputString();</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
}<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common Reset to default settings</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void Reset(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">Mem.Checksum = 25065; //</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
}<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common common print routines</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void Tekstprint(char const tekst[]) { if(Serial) Serial.print(tekst); 
SendMessageBLE(tekst);sptext[0]=0; } </span> <br class="auto-style10" />
<span class="auto-style10">void Tekstprintln(char const tekst[]) { sprintf(sptext,"%s\n",tekst); Tekstprint(sptext); 
}</span><br class="auto-style10" />
<span class="auto-style10">void TekstSprint(char const tekst[]) { printf(tekst); sptext[0]=0;} // printing 
for Debugging purposes in serial monitor </span> <br class="auto-style10" />
<span class="auto-style10">void TekstSprintln(char const tekst[]){ sprintf(sptext,"%s\n",tekst); 
TekstSprint(sptext); }</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common Constrain a string with integers</span><br class="auto-style10" />
<span class="auto-style10">// The value between the first and last character in a string is returned 
between the low and up bounderies</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">int SConstrainInt(String s,byte first,byte last,int low,int up){return 
constrain(s.substring(first, last).toInt(), low, up);}</span><br class="auto-style10" />
<span class="auto-style10">int SConstrainInt(String s,byte first, int low,int up){return constrain(s.substring(first).toInt(), 
low, up);}</span><br class="auto-style10" />
<span class="auto-style10">// //</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common Init and check contents of EEPROM</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void InitStorage(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common common print routines</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void Tekstprint(char const tekst[]) { if(Serial) Serial.print(tekst); 
SendMessageBLE(tekst);sptext[0]=0; } </span> <br class="auto-style10" />
<span class="auto-style10">void Tekstprintln(char const tekst[]) { sprintf(sptext,"%s\n",tekst); Tekstprint(sptext); 
}</span><br class="auto-style10" />
<span class="auto-style10">void TekstSprint(char const tekst[]) { printf(tekst); sptext[0]=0;} // printing 
for Debugging purposes in serial monitor </span> <br class="auto-style10" />
<span class="auto-style10">void TekstSprintln(char const tekst[]){ sprintf(sptext,"%s\n",tekst); 
TekstSprint(sptext); }</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common Constrain a string with integers</span><br class="auto-style10" />
<span class="auto-style10">// The value between the first and last character in a string is returned 
between the low and up bounderies</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------------------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">int SConstrainInt(String s,byte first,byte last,int low,int up){return 
constrain(s.substring(first, last).toInt(), low, up);}</span><br class="auto-style10" />
<span class="auto-style10">int SConstrainInt(String s,byte first, int low,int up){return constrain(s.substring(first).toInt(), 
low, up);}</span><br class="auto-style10" />
<span class="auto-style10">// //</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// Common Init and check contents of EEPROM</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void InitStorage(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// COMMON Store mem.struct in FlashStorage or SD</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void StoreStructInFlashMemory(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// COMMON Get data from FlashStorage</span><br class="auto-style10" />
<span class="auto-style10">// Preferences.h</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void GetStructFromFlashMemory(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Input from Bluetooth or Serial</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void ReworkInputString(String InputString)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">.... </span> <br class="auto-style10" />
<span class="auto-style10">switch (InputString[0])</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">case 'A':</span><br class="auto-style10" />
<span class="auto-style10">case 'a': </span> <br class="auto-style10" />
<span class="auto-style10">if (InputString.length() &gt;5 )</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
}<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// LED Set color for LED. </span> 
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void ColorLeds(char const *Texkst, int FirstLed, int LastLed, uint32_t RGBColor)</span><br class="auto-style10" />
<span class="auto-style10">{ </span> <br class="auto-style10" />
<br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">// //</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// COMMON String upper</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void to_upper(char* string)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// LED Clear the character string</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void LedsOff(void) </span> 
<br class="auto-style10" />
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// LED Set second color</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void SetSecondColour(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">// //</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Version and preferences info</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void SWversion(void) </span> 
<br class="auto-style10" />
<span class="auto-style10">{ </span> <br class="auto-style10" />
<span class="auto-style10">#define FILENAAM (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : 
__FILE__)</span><br class="auto-style10" />
<span class="auto-style10">PrintLine(35);</span><br class="auto-style10" />
<span class="auto-style10">for (uint8_t i = 0; i &lt; sizeof(menu) / sizeof(menu[0]); Tekstprintln(menu[i++]));</span><br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<span class="auto-style10">PrintLine(35);</span><br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">void PrintLine(byte Lengte)</span><br class="auto-style10" />
{<br class="auto-style10" />
<br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">// //</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Say the time and load the LEDs </span> 
<br class="auto-style10" />
<span class="auto-style10">// with the proper colour and intensity</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void Displaytime(void)</span><br class="auto-style10" />
<span class="auto-style10">{ </span> <br class="auto-style10" />
<span class="auto-style10">..</span><br class="auto-style10" />
<span class="auto-style10">switch(Language) // Print all the character in the backgound color, a sort of 
ClearScreen</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">case 0: </span> <br class="auto-style10" />
<span class="auto-style10">strncpy(Template,"HETVISOWASOVIJFQPRECIESZSTIENKPFKWARTSVOORSOVERAHALFSMIDDERTVIJFATWEESOEENOXVIERELFQTIENKTWAALFBHDRIECNEGENACHTFZESVZEVENOENVUUR",129);
</span>
<br class="auto-style10" />
<span class="auto-style10">ColorLeds(Template,0,127, Mem.DimmedLetter);</span><br class="auto-style10" />
<span class="auto-style10">Dutch(); Print_tijd(); break;</span><br class="auto-style10" />
<span class="auto-style10">case 1: </span> <br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
}<br class="auto-style10" />
<span class="auto-style10">//--------------------------- Time functions --------------------------</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">void GetTijd(byte printit)</span><br class="auto-style10" />
<span class="auto-style10">void Print_RTC_tijd(void)</span><br class="auto-style10" />
<span class="auto-style10">void PrintNTP_tijd(void)</span><br class="auto-style10" />
<span class="auto-style10">void PrintUTCtijd(void)</span><br class="auto-style10" />
<span class="auto-style10">void Print_tijd(void)</span><br class="auto-style10" />
<span class="auto-style10">void SetRTCTime(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Convert Hex to uint32</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">uint32_t HexToDec(String hexString) </span> 
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// CLOCK Dutch clock display</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void Dutch(void)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">HET; // HET is always on</span><br class="auto-style10" />
<span class="auto-style10">switch (timeinfo.tm_min)</span><br class="auto-style10" />
{<br class="auto-style10" />
<span class="auto-style10">case 0: IS; PRECIES; break;</span><br class="auto-style10" />
<span class="auto-style10">case 1: IS; break;</span><br class="auto-style10" />
<span class="auto-style10">case 2: </span> <br class="auto-style10" />
<span class="auto-style10">case 3: WAS; break;</span><br class="auto-style10" />
<span class="auto-style10">case 4: </span> <br class="auto-style10" />
<span class="auto-style10">case 5: </span> <br class="auto-style10" />
<span class="auto-style10">...</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">void English(void)</span><br class="auto-style10" />
<span class="auto-style10">void German(void)</span><br class="auto-style10" />
<span class="auto-style10">void French(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//-----------------------------</span><br class="auto-style10" />
<span class="auto-style10">// BLE SendMessage by BLE Slow in packets of 20 chars</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void SendMessageBLE(std::string Message)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//-----------------------------</span><br class="auto-style10" />
<span class="auto-style10">// BLE Start BLE Classes</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------</span><br class="auto-style10" />
<span class="auto-style10">class MyServerCallbacks: public BLEServerCallbacks
</span> <br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//-----------------------------</span><br class="auto-style10" />
<span class="auto-style10">// BLE Start BLE Service</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void StartBLEService(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//-----------------------------</span><br class="auto-style10" />
<span class="auto-style10">// BLE CheckBLE</span><br class="auto-style10" />
<span class="auto-style10">//------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void CheckBLE(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// WIFI WEBPAGE </span> <br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void StartWIFI_NTP(void)</span><br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// WIFI WEBPAGE </span> <br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void WebPage(void) </span> 
<br class="auto-style10" />
<br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">// WIFI WEBPAGE Not found message</span><br class="auto-style10" />
<span class="auto-style10">//--------------------------------------------</span><br class="auto-style10" />
<span class="auto-style10">void notFound(AsyncWebServerRequest *request) </span> 
<br class="auto-style10"></p>
<p class="auto-style10"><strong>Some lessons learned:</strong></p>
<p class="auto-style10"><a href="../../email.html">@Ed Nieuwenhuys</a>, November 2022&nbsp;</p>
<p class="auto-style10">&nbsp;</p>
<p><span class="auto-style10"><strong>Time zones</strong>. </span> 
<br class="auto-style10" />
<span class="auto-style10">Copy the text between the quotes and paste them after the character E 
</span> </p>

<pre><span class="auto-style10">Africa/Abidjan,"GMT0"</span>
<span class="auto-style10">Africa/Accra,"GMT0"</span>
<span class="auto-style10">Africa/Addis_Ababa,"EAT-3"</span>
<span class="auto-style10">Africa/Algiers,"CET-1"</span>
<span class="auto-style10">Africa/Asmara,"EAT-3"</span>
<span class="auto-style10">Africa/Bamako,"GMT0"</span>
<span class="auto-style10">Africa/Bangui,"WAT-1"</span>
<span class="auto-style10">Africa/Banjul,"GMT0"</span>
<span class="auto-style10">Africa/Bissau,"GMT0"</span>
<span class="auto-style10">Africa/Blantyre,"CAT-2"</span>
<span class="auto-style10">Africa/Brazzaville,"WAT-1"</span>
<span class="auto-style10">Africa/Bujumbura,"CAT-2"</span>
<span class="auto-style10">Africa/Cairo,"EET-2"</span>
<span class="auto-style10">Africa/Casablanca,"&lt;+01&gt;-1"</span>
<span class="auto-style10">Africa/Ceuta,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Africa/Conakry,"GMT0"</span>
<span class="auto-style10">Africa/Dakar,"GMT0"</span>
<span class="auto-style10">Africa/Dar_es_Salaam,"EAT-3"</span>
<span class="auto-style10">Africa/Djibouti,"EAT-3"</span>
<span class="auto-style10">Africa/Douala,"WAT-1"</span>
<span class="auto-style10">Africa/El_Aaiun,"&lt;+01&gt;-1"</span>
<span class="auto-style10">Africa/Freetown,"GMT0"</span>
<span class="auto-style10">Africa/Gaborone,"CAT-2"</span>
<span class="auto-style10">Africa/Harare,"CAT-2"</span>
<span class="auto-style10">Africa/Johannesburg,"SAST-2"</span>
<span class="auto-style10">Africa/Juba,"CAT-2"</span>
<span class="auto-style10">Africa/Kampala,"EAT-3"</span>
<span class="auto-style10">Africa/Khartoum,"CAT-2"</span>
<span class="auto-style10">Africa/Kigali,"CAT-2"</span>
<span class="auto-style10">Africa/Kinshasa,"WAT-1"</span>
<span class="auto-style10">Africa/Lagos,"WAT-1"</span>
<span class="auto-style10">Africa/Libreville,"WAT-1"</span>
<span class="auto-style10">Africa/Lome,"GMT0"</span>
<span class="auto-style10">Africa/Luanda,"WAT-1"</span>
<span class="auto-style10">Africa/Lubumbashi,"CAT-2"</span>
<span class="auto-style10">Africa/Lusaka,"CAT-2"</span>
<span class="auto-style10">Africa/Malabo,"WAT-1"</span>
<span class="auto-style10">Africa/Maputo,"CAT-2"</span>
<span class="auto-style10">Africa/Maseru,"SAST-2"</span>
<span class="auto-style10">Africa/Mbabane,"SAST-2"</span>
<span class="auto-style10">Africa/Mogadishu,"EAT-3"</span>
<span class="auto-style10">Africa/Monrovia,"GMT0"</span>
<span class="auto-style10">Africa/Nairobi,"EAT-3"</span>
<span class="auto-style10">Africa/Ndjamena,"WAT-1"</span>
<span class="auto-style10">Africa/Niamey,"WAT-1"</span>
<span class="auto-style10">Africa/Nouakchott,"GMT0"</span>
<span class="auto-style10">Africa/Ouagadougou,"GMT0"</span>
<span class="auto-style10">Africa/Porto-Novo,"WAT-1"</span>
<span class="auto-style10">Africa/Sao_Tome,"GMT0"</span>
<span class="auto-style10">Africa/Tripoli,"EET-2"</span>
<span class="auto-style10">Africa/Tunis,"CET-1"</span>
<span class="auto-style10">Africa/Windhoek,"CAT-2"</span>
<span class="auto-style10">America/Adak,"HST10HDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Anchorage,"AKST9AKDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Anguilla,"AST4"</span>
<span class="auto-style10">America/Antigua,"AST4"</span>
<span class="auto-style10">America/Araguaina,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Buenos_Aires,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Catamarca,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Cordoba,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Jujuy,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/La_Rioja,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Mendoza,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Rio_Gallegos,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Salta,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/San_Juan,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/San_Luis,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Tucuman,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Argentina/Ushuaia,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Aruba,"AST4"</span>
<span class="auto-style10">America/Asuncion,"&lt;-04&gt;4&lt;-03&gt;,M10.1.0/0,M3.4.0/0"</span>
<span class="auto-style10">America/Atikokan,"EST5"</span>
<span class="auto-style10">America/Bahia,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Bahia_Banderas,"CST6CDT,M4.1.0,M10.5.0"</span>
<span class="auto-style10">America/Barbados,"AST4"</span>
<span class="auto-style10">America/Belem,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Belize,"CST6"</span>
<span class="auto-style10">America/Blanc-Sablon,"AST4"</span>
<span class="auto-style10">America/Boa_Vista,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Bogota,"&lt;-05&gt;5"</span>
<span class="auto-style10">America/Boise,"MST7MDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Cambridge_Bay,"MST7MDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Campo_Grande,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Cancun,"EST5"</span>
<span class="auto-style10">America/Caracas,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Cayenne,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Cayman,"EST5"</span>
<span class="auto-style10">America/Chicago,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Chihuahua,"MST7MDT,M4.1.0,M10.5.0"</span>
<span class="auto-style10">America/Costa_Rica,"CST6"</span>
<span class="auto-style10">America/Creston,"MST7"</span>
<span class="auto-style10">America/Cuiaba,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Curacao,"AST4"</span>
<span class="auto-style10">America/Danmarkshavn,"GMT0"</span>
<span class="auto-style10">America/Dawson,"MST7"</span>
<span class="auto-style10">America/Dawson_Creek,"MST7"</span>
<span class="auto-style10">America/Denver,"MST7MDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Detroit,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Dominica,"AST4"</span>
<span class="auto-style10">America/Edmonton,"MST7MDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Eirunepe,"&lt;-05&gt;5"</span>
<span class="auto-style10">America/El_Salvador,"CST6"</span>
<span class="auto-style10">America/Fortaleza,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Fort_Nelson,"MST7"</span>
<span class="auto-style10">America/Glace_Bay,"AST4ADT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Godthab,"&lt;-03&gt;3&lt;-02&gt;,M3.5.0/-2,M10.5.0/-1"</span>
<span class="auto-style10">America/Goose_Bay,"AST4ADT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Grand_Turk,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Grenada,"AST4"</span>
<span class="auto-style10">America/Guadeloupe,"AST4"</span>
<span class="auto-style10">America/Guatemala,"CST6"</span>
<span class="auto-style10">America/Guayaquil,"&lt;-05&gt;5"</span>
<span class="auto-style10">America/Guyana,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Halifax,"AST4ADT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Havana,"CST5CDT,M3.2.0/0,M11.1.0/1"</span>
<span class="auto-style10">America/Hermosillo,"MST7"</span>
<span class="auto-style10">America/Indiana/Indianapolis,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Indiana/Knox,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Indiana/Marengo,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Indiana/Petersburg,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Indiana/Tell_City,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Indiana/Vevay,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Indiana/Vincennes,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Indiana/Winamac,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Inuvik,"MST7MDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Iqaluit,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Jamaica,"EST5"</span>
<span class="auto-style10">America/Juneau,"AKST9AKDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Kentucky/Louisville,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Kentucky/Monticello,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Kralendijk,"AST4"</span>
<span class="auto-style10">America/La_Paz,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Lima,"&lt;-05&gt;5"</span>
<span class="auto-style10">America/Los_Angeles,"PST8PDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Lower_Princes,"AST4"</span>
<span class="auto-style10">America/Maceio,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Managua,"CST6"</span>
<span class="auto-style10">America/Manaus,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Marigot,"AST4"</span>
<span class="auto-style10">America/Martinique,"AST4"</span>
<span class="auto-style10">America/Matamoros,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Mazatlan,"MST7MDT,M4.1.0,M10.5.0"</span>
<span class="auto-style10">America/Menominee,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Merida,"CST6CDT,M4.1.0,M10.5.0"</span>
<span class="auto-style10">America/Metlakatla,"AKST9AKDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Mexico_City,"CST6CDT,M4.1.0,M10.5.0"</span>
<span class="auto-style10">America/Miquelon,"&lt;-03&gt;3&lt;-02&gt;,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Moncton,"AST4ADT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Monterrey,"CST6CDT,M4.1.0,M10.5.0"</span>
<span class="auto-style10">America/Montevideo,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Montreal,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Montserrat,"AST4"</span>
<span class="auto-style10">America/Nassau,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/New_York,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Nipigon,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Nome,"AKST9AKDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Noronha,"&lt;-02&gt;2"</span>
<span class="auto-style10">America/North_Dakota/Beulah,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/North_Dakota/Center,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/North_Dakota/New_Salem,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Nuuk,"&lt;-03&gt;3&lt;-02&gt;,M3.5.0/-2,M10.5.0/-1"</span>
<span class="auto-style10">America/Ojinaga,"MST7MDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Panama,"EST5"</span>
<span class="auto-style10">America/Pangnirtung,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Paramaribo,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Phoenix,"MST7"</span>
<span class="auto-style10">America/Port-au-Prince,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Port_of_Spain,"AST4"</span>
<span class="auto-style10">America/Porto_Velho,"&lt;-04&gt;4"</span>
<span class="auto-style10">America/Puerto_Rico,"AST4"</span>
<span class="auto-style10">America/Punta_Arenas,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Rainy_River,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Rankin_Inlet,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Recife,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Regina,"CST6"</span>
<span class="auto-style10">America/Resolute,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Rio_Branco,"&lt;-05&gt;5"</span>
<span class="auto-style10">America/Santarem,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Santiago,"&lt;-04&gt;4&lt;-03&gt;,M9.1.6/24,M4.1.6/24"</span>
<span class="auto-style10">America/Santo_Domingo,"AST4"</span>
<span class="auto-style10">America/Sao_Paulo,"&lt;-03&gt;3"</span>
<span class="auto-style10">America/Scoresbysund,"&lt;-01&gt;1&lt;+00&gt;,M3.5.0/0,M10.5.0/1"</span>
<span class="auto-style10">America/Sitka,"AKST9AKDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/St_Barthelemy,"AST4"</span>
<span class="auto-style10">America/St_Johns,"NST3:30NDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/St_Kitts,"AST4"</span>
<span class="auto-style10">America/St_Lucia,"AST4"</span>
<span class="auto-style10">America/St_Thomas,"AST4"</span>
<span class="auto-style10">America/St_Vincent,"AST4"</span>
<span class="auto-style10">America/Swift_Current,"CST6"</span>
<span class="auto-style10">America/Tegucigalpa,"CST6"</span>
<span class="auto-style10">America/Thule,"AST4ADT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Thunder_Bay,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Tijuana,"PST8PDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Toronto,"EST5EDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Tortola,"AST4"</span>
<span class="auto-style10">America/Vancouver,"PST8PDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Whitehorse,"MST7"</span>
<span class="auto-style10">America/Winnipeg,"CST6CDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Yakutat,"AKST9AKDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">America/Yellowknife,"MST7MDT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">Antarctica/Casey,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Antarctica/Davis,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Antarctica/DumontDUrville,"&lt;+10&gt;-10"</span>
<span class="auto-style10">Antarctica/Macquarie,"AEST-10AEDT,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Antarctica/Mawson,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Antarctica/McMurdo,"NZST-12NZDT,M9.5.0,M4.1.0/3"</span>
<span class="auto-style10">Antarctica/Palmer,"&lt;-03&gt;3"</span>
<span class="auto-style10">Antarctica/Rothera,"&lt;-03&gt;3"</span>
<span class="auto-style10">Antarctica/Syowa,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Antarctica/Troll,"&lt;+00&gt;0&lt;+02&gt;-2,M3.5.0/1,M10.5.0/3"</span>
<span class="auto-style10">Antarctica/Vostok,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Arctic/Longyearbyen,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Asia/Aden,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Asia/Almaty,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Asia/Amman,"EET-2EEST,M2.5.4/24,M10.5.5/1"</span>
<span class="auto-style10">Asia/Anadyr,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Asia/Aqtau,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Aqtobe,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Ashgabat,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Atyrau,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Baghdad,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Asia/Bahrain,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Asia/Baku,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Asia/Bangkok,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Barnaul,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Beirut,"EET-2EEST,M3.5.0/0,M10.5.0/0"</span>
<span class="auto-style10">Asia/Bishkek,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Asia/Brunei,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Asia/Chita,"&lt;+09&gt;-9"</span>
<span class="auto-style10">Asia/Choibalsan,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Asia/Colombo,"&lt;+0530&gt;-5:30"</span>
<span class="auto-style10">Asia/Damascus,"EET-2EEST,M3.5.5/0,M10.5.5/0"</span>
<span class="auto-style10">Asia/Dhaka,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Asia/Dili,"&lt;+09&gt;-9"</span>
<span class="auto-style10">Asia/Dubai,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Asia/Dushanbe,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Famagusta,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Asia/Gaza,"EET-2EEST,M3.4.4/48,M10.5.5/1"</span>
<span class="auto-style10">Asia/Hebron,"EET-2EEST,M3.4.4/48,M10.5.5/1"</span>
<span class="auto-style10">Asia/Ho_Chi_Minh,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Hong_Kong,"HKT-8"</span>
<span class="auto-style10">Asia/Hovd,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Irkutsk,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Asia/Jakarta,"WIB-7"</span>
<span class="auto-style10">Asia/Jayapura,"WIT-9"</span>
<span class="auto-style10">Asia/Jerusalem,"IST-2IDT,M3.4.4/26,M10.5.0"</span>
<span class="auto-style10">Asia/Kabul,"&lt;+0430&gt;-4:30"</span>
<span class="auto-style10">Asia/Kamchatka,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Asia/Karachi,"PKT-5"</span>
<span class="auto-style10">Asia/Kathmandu,"&lt;+0545&gt;-5:45"</span>
<span class="auto-style10">Asia/Khandyga,"&lt;+09&gt;-9"</span>
<span class="auto-style10">Asia/Kolkata,"IST-5:30"</span>
<span class="auto-style10">Asia/Krasnoyarsk,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Kuala_Lumpur,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Asia/Kuching,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Asia/Kuwait,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Asia/Macau,"CST-8"</span>
<span class="auto-style10">Asia/Magadan,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Asia/Makassar,"WITA-8"</span>
<span class="auto-style10">Asia/Manila,"PST-8"</span>
<span class="auto-style10">Asia/Muscat,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Asia/Nicosia,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Asia/Novokuznetsk,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Novosibirsk,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Omsk,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Asia/Oral,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Phnom_Penh,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Pontianak,"WIB-7"</span>
<span class="auto-style10">Asia/Pyongyang,"KST-9"</span>
<span class="auto-style10">Asia/Qatar,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Asia/Qyzylorda,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Riyadh,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Asia/Sakhalin,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Asia/Samarkand,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Seoul,"KST-9"</span>
<span class="auto-style10">Asia/Shanghai,"CST-8"</span>
<span class="auto-style10">Asia/Singapore,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Asia/Srednekolymsk,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Asia/Taipei,"CST-8"</span>
<span class="auto-style10">Asia/Tashkent,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Tbilisi,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Asia/Tehran,"&lt;+0330&gt;-3:30&lt;+0430&gt;,J79/24,J263/24"</span>
<span class="auto-style10">Asia/Thimphu,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Asia/Tokyo,"JST-9"</span>
<span class="auto-style10">Asia/Tomsk,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Ulaanbaatar,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Asia/Urumqi,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Asia/Ust-Nera,"&lt;+10&gt;-10"</span>
<span class="auto-style10">Asia/Vientiane,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Asia/Vladivostok,"&lt;+10&gt;-10"</span>
<span class="auto-style10">Asia/Yakutsk,"&lt;+09&gt;-9"</span>
<span class="auto-style10">Asia/Yangon,"&lt;+0630&gt;-6:30"</span>
<span class="auto-style10">Asia/Yekaterinburg,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Asia/Yerevan,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Atlantic/Azores,"&lt;-01&gt;1&lt;+00&gt;,M3.5.0/0,M10.5.0/1"</span>
<span class="auto-style10">Atlantic/Bermuda,"AST4ADT,M3.2.0,M11.1.0"</span>
<span class="auto-style10">Atlantic/Canary,"WET0WEST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Atlantic/Cape_Verde,"&lt;-01&gt;1"</span>
<span class="auto-style10">Atlantic/Faroe,"WET0WEST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Atlantic/Madeira,"WET0WEST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Atlantic/Reykjavik,"GMT0"</span>
<span class="auto-style10">Atlantic/South_Georgia,"&lt;-02&gt;2"</span>
<span class="auto-style10">Atlantic/Stanley,"&lt;-03&gt;3"</span>
<span class="auto-style10">Atlantic/St_Helena,"GMT0"</span>
<span class="auto-style10">Australia/Adelaide,"ACST-9:30ACDT,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Australia/Brisbane,"AEST-10"</span>
<span class="auto-style10">Australia/Broken_Hill,"ACST-9:30ACDT,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Australia/Currie,"AEST-10AEDT,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Australia/Darwin,"ACST-9:30"</span>
<span class="auto-style10">Australia/Eucla,"&lt;+0845&gt;-8:45"</span>
<span class="auto-style10">Australia/Hobart,"AEST-10AEDT,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Australia/Lindeman,"AEST-10"</span>
<span class="auto-style10">Australia/Lord_Howe,"&lt;+1030&gt;-10:30&lt;+11&gt;-11,M10.1.0,M4.1.0"</span>
<span class="auto-style10">Australia/Melbourne,"AEST-10AEDT,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Australia/Perth,"AWST-8"</span>
<span class="auto-style10">Australia/Sydney,"AEST-10AEDT,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Europe/Amsterdam,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Andorra,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Astrakhan,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Europe/Athens,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Belgrade,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Berlin,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Bratislava,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Brussels,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Bucharest,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Budapest,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Busingen,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Chisinau,"EET-2EEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Copenhagen,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Dublin,"IST-1GMT0,M10.5.0,M3.5.0/1"</span>
<span class="auto-style10">Europe/Gibraltar,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Guernsey,"GMT0BST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Europe/Helsinki,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Isle_of_Man,"GMT0BST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Europe/Istanbul,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Europe/Jersey,"GMT0BST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Europe/Kaliningrad,"EET-2"</span>
<span class="auto-style10">Europe/Kiev,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Kirov,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Europe/Lisbon,"WET0WEST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Europe/Ljubljana,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/London,"GMT0BST,M3.5.0/1,M10.5.0"</span>
<span class="auto-style10">Europe/Luxembourg,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Madrid,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Malta,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Mariehamn,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Minsk,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Europe/Monaco,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Moscow,"MSK-3"</span>
<span class="auto-style10">Europe/Oslo,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Paris,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Podgorica,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Prague,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Riga,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Rome,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Samara,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Europe/San_Marino,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Sarajevo,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Saratov,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Europe/Simferopol,"MSK-3"</span>
<span class="auto-style10">Europe/Skopje,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Sofia,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Stockholm,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Tallinn,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Tirane,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Ulyanovsk,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Europe/Uzhgorod,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Vaduz,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Vatican,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Vienna,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Vilnius,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Volgograd,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Europe/Warsaw,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Zagreb,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Europe/Zaporozhye,"EET-2EEST,M3.5.0/3,M10.5.0/4"</span>
<span class="auto-style10">Europe/Zurich,"CET-1CEST,M3.5.0,M10.5.0/3"</span>
<span class="auto-style10">Indian/Antananarivo,"EAT-3"</span>
<span class="auto-style10">Indian/Chagos,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Indian/Christmas,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Indian/Cocos,"&lt;+0630&gt;-6:30"</span>
<span class="auto-style10">Indian/Comoro,"EAT-3"</span>
<span class="auto-style10">Indian/Kerguelen,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Indian/Mahe,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Indian/Maldives,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Indian/Mauritius,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Indian/Mayotte,"EAT-3"</span>
<span class="auto-style10">Indian/Reunion,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Pacific/Apia,"&lt;+13&gt;-13"</span>
<span class="auto-style10">Pacific/Auckland,"NZST-12NZDT,M9.5.0,M4.1.0/3"</span>
<span class="auto-style10">Pacific/Bougainville,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Pacific/Chatham,"&lt;+1245&gt;-12:45&lt;+1345&gt;,M9.5.0/2:45,M4.1.0/3:45"</span>
<span class="auto-style10">Pacific/Chuuk,"&lt;+10&gt;-10"</span>
<span class="auto-style10">Pacific/Easter,"&lt;-06&gt;6&lt;-05&gt;,M9.1.6/22,M4.1.6/22"</span>
<span class="auto-style10">Pacific/Efate,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Pacific/Enderbury,"&lt;+13&gt;-13"</span>
<span class="auto-style10">Pacific/Fakaofo,"&lt;+13&gt;-13"</span>
<span class="auto-style10">Pacific/Fiji,"&lt;+12&gt;-12&lt;+13&gt;,M11.2.0,M1.2.3/99"</span>
<span class="auto-style10">Pacific/Funafuti,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Pacific/Galapagos,"&lt;-06&gt;6"</span>
<span class="auto-style10">Pacific/Gambier,"&lt;-09&gt;9"</span>
<span class="auto-style10">Pacific/Guadalcanal,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Pacific/Guam,"ChST-10"</span>
<span class="auto-style10">Pacific/Honolulu,"HST10"</span>
<span class="auto-style10">Pacific/Kiritimati,"&lt;+14&gt;-14"</span>
<span class="auto-style10">Pacific/Kosrae,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Pacific/Kwajalein,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Pacific/Majuro,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Pacific/Marquesas,"&lt;-0930&gt;9:30"</span>
<span class="auto-style10">Pacific/Midway,"SST11"</span>
<span class="auto-style10">Pacific/Nauru,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Pacific/Niue,"&lt;-11&gt;11"</span>
<span class="auto-style10">Pacific/Norfolk,"&lt;+11&gt;-11&lt;+12&gt;,M10.1.0,M4.1.0/3"</span>
<span class="auto-style10">Pacific/Noumea,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Pacific/Pago_Pago,"SST11"</span>
<span class="auto-style10">Pacific/Palau,"&lt;+09&gt;-9"</span>
<span class="auto-style10">Pacific/Pitcairn,"&lt;-08&gt;8"</span>
<span class="auto-style10">Pacific/Pohnpei,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Pacific/Port_Moresby,"&lt;+10&gt;-10"</span>
<span class="auto-style10">Pacific/Rarotonga,"&lt;-10&gt;10"</span>
<span class="auto-style10">Pacific/Saipan,"ChST-10"</span>
<span class="auto-style10">Pacific/Tahiti,"&lt;-10&gt;10"</span>
<span class="auto-style10">Pacific/Tarawa,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Pacific/Tongatapu,"&lt;+13&gt;-13"</span>
<span class="auto-style10">Pacific/Wake,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Pacific/Wallis,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Etc/GMT,"GMT0"</span>
<span class="auto-style10">Etc/GMT-0,"GMT0"</span>
<span class="auto-style10">Etc/GMT-1,"&lt;+01&gt;-1"</span>
<span class="auto-style10">Etc/GMT-2,"&lt;+02&gt;-2"</span>
<span class="auto-style10">Etc/GMT-3,"&lt;+03&gt;-3"</span>
<span class="auto-style10">Etc/GMT-4,"&lt;+04&gt;-4"</span>
<span class="auto-style10">Etc/GMT-5,"&lt;+05&gt;-5"</span>
<span class="auto-style10">Etc/GMT-6,"&lt;+06&gt;-6"</span>
<span class="auto-style10">Etc/GMT-7,"&lt;+07&gt;-7"</span>
<span class="auto-style10">Etc/GMT-8,"&lt;+08&gt;-8"</span>
<span class="auto-style10">Etc/GMT-9,"&lt;+09&gt;-9"</span>
<span class="auto-style10">Etc/GMT-10,"&lt;+10&gt;-10"</span>
<span class="auto-style10">Etc/GMT-11,"&lt;+11&gt;-11"</span>
<span class="auto-style10">Etc/GMT-12,"&lt;+12&gt;-12"</span>
<span class="auto-style10">Etc/GMT-13,"&lt;+13&gt;-13"</span>
<span class="auto-style10">Etc/GMT-14,"&lt;+14&gt;-14"</span>
<span class="auto-style10">Etc/GMT0,"GMT0"</span>
<span class="auto-style10">Etc/GMT+0,"GMT0"</span>
<span class="auto-style10">Etc/GMT+1,"&lt;-01&gt;1"</span>
<span class="auto-style10">Etc/GMT+2,"&lt;-02&gt;2"</span>
<span class="auto-style10">Etc/GMT+3,"&lt;-03&gt;3"</span>
<span class="auto-style10">Etc/GMT+4,"&lt;-04&gt;4"</span>
<span class="auto-style10">Etc/GMT+5,"&lt;-05&gt;5"</span>
<span class="auto-style10">Etc/GMT+6,"&lt;-06&gt;6"</span>
<span class="auto-style10">Etc/GMT+7,"&lt;-07&gt;7"</span>
<span class="auto-style10">Etc/GMT+8,"&lt;-08&gt;8"</span>
<span class="auto-style10">Etc/GMT+9,"&lt;-09&gt;9"</span>
<span class="auto-style10">Etc/GMT+10,"&lt;-10&gt;10"</span>
<span class="auto-style10">Etc/GMT+11,"&lt;-11&gt;11"</span>
<span class="auto-style10">Etc/GMT+12,"&lt;-12&gt;12"</span>
<span class="auto-style10">Etc/UCT,"UTC0"</span>
<span class="auto-style10">Etc/UTC,"UTC0"</span>
<span class="auto-style10">Etc/Greenwich,"GMT0"</span>
<span class="auto-style10">Etc/Universal,"UTC0"</span>
<span class="auto-style10">Etc/Zulu,"UTC0"</span></pre>

</body>
