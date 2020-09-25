# ArduinoButton

Helper class for handling Buttons in Arduino projects.

```
# initialize with pin:
Button button1 (8);

void setup() {
  # How long do you need to press before it's detected (default 0ms):
  button1.threshold = 1000;
  
  # After first detection, continue detecting? i.e. hold the button and trigger every [threshold]ms
  # Warning - set a sensible threshold above
  button1.repeats = true;
}

void loop() {
  if (button1.isDown()) {
    # press detected
  }
}
