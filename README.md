# churchStageLightController
Light controller for 12v stage LED lighting.

### Purpose:
Our church's youth group is spectacular. They are highly involved and tremendously dedicated. Each month they decorate the main stage to Hollywood and/or Broadway standards. While the actual stage lights are managed by a professional DMX controller, we had no way of adding lights to props, structures, or other on-stage items. The goal of this project is to create a self-contained controller with a simple UI that can manage low voltage RGB LED lighting. A standardized output plug would allow the ability to adapt LED strings, strips, or bulbs for use with various on-stage lighting needs.


### Parts List:
  * [Arduino Nano Clone](https://www.amazon.com/dp/B0739V3MR7
    * Or Arduino Uno Clone (the shield fits directly on the Uno)
  * [1602 LCD Keypad Shield](https://www.amazon.com/gp/product/B0744JLGWF)
    * The model I used is a parallel model, not I2C.
  * [(3) TIP120 Darlington NPN Transistors](https://www.amazon.com/gp/product/B00B888622/)
  * [12v RGB LED Ligting (any type, non-addressable)](https://www.amazon.com/econoLED-Flexible-Multi-colors-Non-waterproof-Changing/dp/B006LW2NJM)
  * [12v 3 Amp or greater power supply](https://www.amazon.com/110V-220V-Converter-Lighting-Transformer-Flexible/dp/B073QTNF9F)
    * Match the amperage here to the amount of lights you want to control.


  ** Note: Links above are non-affiliate links to products that I have used either for this project or in the past. They are suggestions only and may not be appropriate for your project. They should, at a minimum, give you an idea of what you're looking for.

### Other References
  * [http://www.thomasclausen.net/en/walking-through-the-1602-lcd-keypad-shield-for-arduino/]
  * [http://www.hobbyist.co.nz/?q=diy-tutorials]