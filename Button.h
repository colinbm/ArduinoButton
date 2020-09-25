class Button {
  private:
    int pin;
    bool down = false;
    unsigned long downAt;
    bool reported = false;

  public:
    Button(int pin);
    unsigned long threshold = 0;
    bool repeats = false;
    bool isDown();
};